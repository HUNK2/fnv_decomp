#ifndef FNV_NITFIXEDSTRINGMAP_DECLS_H
#define FNV_NITFIXEDSTRINGMAP_DECLS_H

#include "NiFixedString.h"

class NiAVObject;
extern NiFixedString EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

template <class T> class DFALL
{
};
template <class Allocator, class Value> class NiTFixedStringMapBase
{
  public:
    typedef NiTMapItem<NiFixedString, Value> Item;
    virtual ~NiTFixedStringMapBase();
    virtual Item* NewItem();
    virtual void DeleteItem(Item* item);
    unsigned int m_uiHashSize;
    Item** m_ppkHashTable;
    struct MapEntryCount : public Allocator
    {
        unsigned int m_uiCount;
    } m_kItemCount;
    void GetNext(void*& pos, NiFixedString& key, Value& value) const;
    void SetAt(NiFixedString& key, Value value);
    void RemoveAll();
    void AssignSharedPtr(Item* item, NiFixedString& key, Value value);
};
typedef NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString, NiAVObject*> >, NiAVObject*> NiAVObjectFixedStringMap;
typedef NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString, const char*> >, const char*> NiCharFixedStringMap;
FNV_STATIC_ASSERT(sizeof(NiAVObjectFixedStringMap) == 16);
FNV_STATIC_ASSERT(offsetof(NiAVObjectFixedStringMap, m_uiHashSize) == 4);
FNV_STATIC_ASSERT(offsetof(NiAVObjectFixedStringMap, m_ppkHashTable) == 8);
FNV_STATIC_ASSERT(offsetof(NiAVObjectFixedStringMap, m_kItemCount) == 12);
#endif
