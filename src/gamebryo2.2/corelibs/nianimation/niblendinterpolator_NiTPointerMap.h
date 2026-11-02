#ifndef FNV_NIBLENDINTERPOLATOR_PRIVATE_NITPOINTERMAP_H
#define FNV_NIBLENDINTERPOLATOR_PRIVATE_NITPOINTERMAP_H

#include "niblendinterpolator_layout_support.h"
#include "niblendinterpolator_NiMemObject.h"

// Declaration-only public NiTMapBase/NiTPointerMap hierarchy. No template implementation copied.
template <class Allocator, class Key, class Value> class NiTMapBase : public NiMemObject
{
  public:
    struct MapEntryCount : public Allocator
    {
        unsigned int m_uiCount;
    };
    NiTMapBase(unsigned int hashSize);
    virtual ~NiTMapBase();
    virtual unsigned int KeyToHashIndex(const Key key) const;
    virtual bool IsKeysEqual(const Key first, const Key second) const;
    virtual void SetValue(NiTMapItem<Key, Value>* item, Key key, Value value);
    virtual void ClearValue(NiTMapItem<Key, Value>* item);
    virtual NiTMapItem<Key, Value>* NewItem() = 0;
    virtual void DeleteItem(NiTMapItem<Key, Value>* item) = 0;
    unsigned int m_uiHashSize;
    NiTMapItem<Key, Value>** m_ppkHashTable;
    MapEntryCount m_kItemCount;
    unsigned int GetCount() const;
    bool IsEmpty() const;
    bool GetAt(const Key key, Value& value) const;
    void SetAt(Key key, Value value);
    bool RemoveAt(const Key key);
    void RemoveAll();
    void* GetFirstPos() const;
    void GetNext(void*& position, Key& key, Value& value) const;

  private:
    NiTMapBase(const NiTMapBase&);
    NiTMapBase& operator=(const NiTMapBase&);
};

template <>
class NiTPointerMap<NiObject*, NiObject*> : public NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, NiObject*>
{
  public:
    NiTPointerMap(unsigned int hashSize);
    ~NiTPointerMap();
    virtual NiTMapItem<NiObject*, NiObject*>* NewItem();
    virtual void DeleteItem(NiTMapItem<NiObject*, NiObject*>* item);
};
typedef NiTPointerMap<NiObject*, NiObject*> NiClonePointerMap;
typedef NiTMapItem<NiObject*, NiObject*> NiClonePointerMapItem;
FNV_STATIC_ASSERT(sizeof(NiClonePointerMap) == 16);
FNV_STATIC_ASSERT(offsetof(NiClonePointerMap, m_uiHashSize) == 4);
FNV_STATIC_ASSERT(offsetof(NiClonePointerMap, m_ppkHashTable) == 8);
FNV_STATIC_ASSERT(offsetof(NiClonePointerMap, m_kItemCount) == 12);
FNV_STATIC_ASSERT(sizeof(NiClonePointerMapItem) == 12);
FNV_STATIC_ASSERT(offsetof(NiClonePointerMapItem, m_pkNext) == 0);
FNV_STATIC_ASSERT(offsetof(NiClonePointerMapItem, m_key) == 4);
FNV_STATIC_ASSERT(offsetof(NiClonePointerMapItem, m_val) == 8);
#endif
