// fallout_shared/bgsloadedreferencecollection.h: declares TESObjectREFR, TimeGlobal, LoadedReferenceMap
#ifndef FNV_BGSLOADEDREFERENCECOLLECTION_H
#define FNV_BGSLOADEDREFERENCECOLLECTION_H


#include "layout_support.h"
#include "TESForm.h"

template <class K, class V> class NiTMapItem
{
  public:
    NiTMapItem<K, V>* m_pkNext;
    K m_key;
    V m_val;
};
template <class K, class V> class NiTPointerMap
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    NiTMapItem<K, V>** m_ppkHashTable;
    struct MapEntryCount
    {
        unsigned int m_uiCount;
    } m_kItemCount;
    NiTPointerMap(unsigned int hashSize);
    bool GetAt(K key, V& result) const;
    void SetAt(K key, V value);
};

class TESObjectREFR : public TESForm
{
};

class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};
extern TimeGlobal g_timeGlobal;

#pragma pack(push, 4)
class LoadedReferenceMap : public NiTPointerMap<unsigned int, TESObjectREFR*>
{
  public:
    unsigned int iCount;              // +0x10
    unsigned int m_uiLastUpdateTime;  // +0x14

    bool AddReference(TESObjectREFR* pRef);
};
#pragma pack(pop)

FNV_STATIC_ASSERT(sizeof(LoadedReferenceMap) == 24);
FNV_STATIC_ASSERT(offsetof(LoadedReferenceMap, iCount) == 16);
FNV_STATIC_ASSERT(offsetof(LoadedReferenceMap, m_uiLastUpdateTime) == 20);

#endif
