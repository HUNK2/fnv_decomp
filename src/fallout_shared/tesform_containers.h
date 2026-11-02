// Unit-private declaration closure. No external function bodies are defined here.
// Provenance and qualified constructor/fold bindings: PROVENANCE.md.
#ifndef FNV_UNIT_TESFORM_CONTAINERS_H
#define FNV_UNIT_TESFORM_CONTAINERS_H

#include "tesform_layout_support.h"

class TESForm;

// The supplied canonical NiMemObject.h records an empty, one-byte base.
#ifndef FNV_UNIT_TESFORM_CONTAINER_NIMEMOBJECT_H
#define FNV_UNIT_TESFORM_CONTAINER_NIMEMOBJECT_H
class NiMemObject
{
  public:
};
FNV_STATIC_ASSERT(sizeof(NiMemObject) == 1);
#endif

template <class T> class DFALL
{
  public:
    void* Allocate();
    void Deallocate(void* memory);
};

template <class T> class PoolAllocatorBase
{
  public:
};

template <class T> class NiTPointerAllocator : public PoolAllocatorBase<T>
{
  public:
    void* Allocate();
    void Deallocate(void* memory);
};

template <class T> class NiTMallocInterface
{
  public:
};

template <class K, class V> class NiTMapItem : public NiMemObject
{
  public:
    NiTMapItem<K, V>* m_pkNext;
    K m_key;
    V m_val;
};

template <class Allocator, class K, class V> class NiTMapBase : public NiMemObject
{
  public:
    struct MapEntryCount : public Allocator
    {
        unsigned int m_uiCount;
    };

    NiTMapBase(unsigned int hashSize);
    virtual ~NiTMapBase();
    virtual unsigned int KeyToHashIndex(K key) const;
    virtual bool IsKeysEqual(K first, K second) const;
    virtual void SetValue(NiTMapItem<K, V>* item, K key, V value);
    virtual void ClearValue(NiTMapItem<K, V>* item);
    virtual NiTMapItem<K, V>* NewItem() = 0;
    virtual void DeleteItem(NiTMapItem<K, V>* item) = 0;

    unsigned int m_uiHashSize;
    NiTMapItem<K, V>** m_ppkHashTable;
    MapEntryCount m_kItemCount;

    bool GetAt(K key, V& result) const;
    void SetAt(K key, V value);
    bool RemoveAt(K key);
};

template <class K, class V> class NiTPointerMap : public NiTMapBase<NiTPointerAllocator<unsigned int>, K, V>
{
  public:
    NiTPointerMap(unsigned int hashSize);
    ~NiTPointerMap();
    virtual NiTMapItem<K, V>* NewItem();
    virtual void DeleteItem(NiTMapItem<K, V>* item);
};

// specialization. It is not a new allocator name or a borrowed function body.
template <class K, class V> class NiTMap : public NiTMapBase<DFALL<NiTMapItem<K, V> >, K, V>
{
  public:
    NiTMap(unsigned int hashSize);
    ~NiTMap();
    virtual NiTMapItem<K, V>* NewItem();
    virtual void DeleteItem(NiTMapItem<K, V>* item);
};

template <class Parent, class V> class NiTStringTemplateMap : public Parent
{
  public:
    NiTStringTemplateMap(unsigned int hashSize, bool copyStrings);
    virtual ~NiTStringTemplateMap();
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* first, const char* second) const;
    virtual void SetValue(NiTMapItem<const char*, V>* item, const char* key, V value);
    virtual void ClearValue(NiTMapItem<const char*, V>* item);
    bool m_bCopy;
    void SetAt(const char* key, V value);
};

template <class V> class NiTStringMap : public NiTStringTemplateMap<NiTMap<const char*, V>, V>
{
  public:
    NiTStringMap(unsigned int hashSize, bool copyStrings);
};

template <class V> class BSTCaseInsensitiveStringMap : public NiTStringMap<V>
{
  public:
    BSTCaseInsensitiveStringMap(unsigned int hashSize, bool copyStrings);
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* first, const char* second) const;
};

template <class T, class Allocator> class NiTLargeArray : public NiMemObject
{
  public:
    NiTLargeArray(unsigned int maxSize, unsigned int growBy);
    virtual ~NiTLargeArray();
    T* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    unsigned int GetSize() const;
    T& GetAt(unsigned int index) const;
    unsigned int Add(const T& item);
    unsigned int AddFirstEmpty(const T& item);
    T RemoveAt(unsigned int index);
};

template <class T> class NiTLargePrimitiveArray : public NiTLargeArray<T, NiTMallocInterface<T> >
{
  public:
    NiTLargePrimitiveArray(unsigned int maxSize, unsigned int growBy);
};

// These typedefs are layout-assertion conveniences, not new class owners.
typedef NiTPointerMap<unsigned int, TESForm*> TESFormNumericMap;
typedef BSTCaseInsensitiveStringMap<TESForm*> TESFormEditorIDMap;
typedef NiTLargePrimitiveArray<TESForm*> TESFormAlteredArray;
typedef NiTMapItem<const char*, TESForm*> TESFormEditorIDMapItem;
FNV_STATIC_ASSERT(sizeof(TESFormNumericMap) == 0x10);
FNV_STATIC_ASSERT(offsetof(TESFormNumericMap, m_uiHashSize) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESFormNumericMap, m_ppkHashTable) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESFormNumericMap, m_kItemCount) == 0xC);
FNV_STATIC_ASSERT(sizeof(TESFormEditorIDMap) == 0x14);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMap, m_uiHashSize) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMap, m_ppkHashTable) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMap, m_kItemCount) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMap, m_bCopy) == 0x10);
FNV_STATIC_ASSERT(sizeof(TESFormEditorIDMapItem) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMapItem, m_pkNext) == 0x0);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMapItem, m_key) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMapItem, m_val) == 0x8);
FNV_STATIC_ASSERT(sizeof(TESFormAlteredArray) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESFormAlteredArray, m_pBase) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESFormAlteredArray, m_uiMaxSize) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESFormAlteredArray, m_uiSize) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFormAlteredArray, m_uiESize) == 0x10);
FNV_STATIC_ASSERT(offsetof(TESFormAlteredArray, m_uiGrowBy) == 0x14);

// Global allocation/deallocation are declarations only. The covered new
// expressions emit the allocation and exception cleanup naturally.
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* memory);
#endif
