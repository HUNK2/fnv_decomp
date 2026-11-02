// fallout/ai/combat/combatthreatmap_ctor_decls.h: declares CombatThreatRecord, ReadWriteLock, CombatThreatMap
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
    unsigned int vtable;
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
extern float DAT_0108d9b0;
class CombatTargetTimestamp
{
  public:
    float value;
    CombatTargetTimestamp(float);
};
class FUN_00906f60
{
  public:
    unsigned int data[2];
    FUN_00906f60();
};
class NiAVObject;
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    NiPointer(NiAVObject*);
    ~NiPointer();
};
class FUN_00993960 : public NiTMap<unsigned int, CombatThreatRecord*>
{
  public:
    ReadWriteLock Lock;
    unsigned int padding[2];
    FUN_00993960(int, int);
    ~FUN_00993960();
};
class CombatThreatMap : public FUN_00993960
{
  public:
    CombatTargetTimestamp stamp;
    FUN_00906f60 pair1, pair2;
    unsigned int mode;
    NiPointer<NiAVObject> object;
    CombatThreatMap();
    void InitThreatObjects();
    void ApplyLoadBuffer(BGSLoadGameBuffer*);
};
#endif
