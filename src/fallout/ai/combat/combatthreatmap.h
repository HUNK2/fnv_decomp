// fallout/ai/combat/combatthreatmap.h: declares CombatThreatRecord, ReadWriteLock, CombatThreatMap
#ifndef FNV_ASTRA_COMBATTHREATMAP_H
#define FNV_ASTRA_COMBATTHREATMAP_H

#include <stddef.h>
class TESForm;
class BGSLoadGameBuffer;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    operator T*() const;
};
// Prefix-only PC view, inferred from the folded NiPointer conversion called on
// the threat address itself. No sizeof/new/member-destruction operation on a
// CombatThreatRecord is emitted here; its real destructor remains external.
class CombatThreatRecord : public NiPointer<TESForm>
{
  public:
    ~CombatThreatRecord();
    void LoadGame(BGSLoadGameBuffer*);
};
template <class K, class V> class NiTMapItem;
template <class T> class DFALL;
template <class Allocator, class K, class V> class NiTMapBase
{
  public:
    virtual ~NiTMapBase();
    unsigned int m_uiHashSize;
    NiTMapItem<K, V>** m_ppkHashTable;
    struct MapEntryCount
    {
        unsigned int m_uiCount;
    } m_kItemCount;
    void* GetFirstPos();
    void GetNext(void*&, K&, V&);
    bool RemoveAt(K);
};
template <class K, class V> class NiTMap : public NiTMapBase<DFALL<NiTMapItem<K, V> >, K, V>
{
};
class ReadWriteLock
{
  public:
    volatile unsigned int m_uiLockState;
    unsigned int m_uiWriterThreadId;
};
class CombatThreatMap : public NiTMap<unsigned int, CombatThreatRecord*>
{
  public:
    ReadWriteLock Lock;
    void ApplyLoadBuffer(BGSLoadGameBuffer*);
};
typedef char check_CombatThreatMap[sizeof(CombatThreatMap) == 0x18 ? 1 : -1];
typedef char check_CombatThreatMap_Lock[offsetof(CombatThreatMap, Lock) == 0x10 ? 1 : -1];
#endif
