// fallout_shared/tesobjectcell_packet.h: declares TESFile, PlayerMover, SettingT_GameSettingCollection_, NiNode, TESDataHandler and more
#ifndef TESOBJECTCELL_PACKET_H
#define TESOBJECTCELL_PACKET_H

struct TESRecordHeader;
class TESFile
{
  public:
    char pad[0x240];
    TESRecordHeader* GetRecordHeader();
};
class PlayerMover
{
  public:
    char pad[0x94];
    unsigned int moveMode;
    unsigned int GetActorStateFlags();
};
union SETTING_VALUE
{
    int i;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Int();
};
class NiAVObject;
class NiNode
{
  public:
    NiAVObject* FUN_0043b4a0(int index);
};
class TESImageSpaceModifier;
template <class T> class BSSimpleList;
class TESDataHandler
{
  public:
    BSSimpleList<TESImageSpaceModifier*>* GetTESImageSpaceModifierList();
};
class BGSEncounterZone;
class TESWorldSpace
{
  public:
    BGSEncounterZone* FindEncounterZone() const;
};
class TESForm;
class NiNode;
class NiAVObject
{
  public:
    NiNode* GetParent();
};
class TESObjectREFR
{
  public:
    static BGSEncounterZone* FindEncounterZone();
};
class DoorCell
{
  public:
    TESForm* GetOwner();
};
class TESSound
{
  public:
    char pad[0x45];
    unsigned char field45;
    unsigned char GetField45();
};
extern unsigned int DAT_011ca438;
class GarbageCollectorObjectPtr
{
  public:
    NiAVObject* operator->() const;
};
class GlobalObject_00633c90 : public GarbageCollectorObjectPtr
{
};
extern GlobalObject_00633c90 g_011deda4;
struct InteriorCellData
{
    char pad[0x20];
    float clipDist;
};
class CellLightingTemplate
{
  public:
    float FUN_009a9350();
};
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    T& GetItem();
    BSSimpleList* GetNext();
    void RemoveAll();
};
class BGSPerkEntry;
class BGSLoadedReferenceCollection
{
  public:
    void FUN_00526f20(BGSPerkEntry* reference);
};
extern BGSLoadedReferenceCollection* DAT_011c95c8;
class ActorCause;
class BSExtraData;
class BaseExtraList
{
  public:
    char data[0x20];
    BSExtraData* GetExtraData(unsigned char type);
};
class ExtraDataList : public BaseExtraList
{
  public:
    void RemoveNonPersistentCellData();
    BGSEncounterZone* FindEncounterZone() const;
    TESForm* GetOwner();
};
class RecursiveSpinLock
{
  public:
    void Lock(const char* name);
};
class ExteriorCellData
{
  public:
    int x;
    int y;
};
class TESWorldSpace;
class TESObjectCELL
{
  public:
    char padToExtraData[0x24];
    unsigned char field24;
    char padToExtraData2[3];
    ExtraDataList extraDataList;
    void* cellData;
    char padToRefListLock[0x34];
    RecursiveSpinLock refListLock;
    char padToWorldSpace[0x3f];
    TESWorldSpace* worldSpace;
    char padToUnknownDC[0x18];
    unsigned int unknownDC;
    char padToField210[0x130];
    unsigned char field210;
    char padToField619[0x408];
    unsigned char field619;
    char padToField760[0x146];
    void* field760;
    char padToAudioMarkers[0x70];
    BSSimpleList<ActorCause*> audioMarkers;
    unsigned int audioMarkerCount;
    unsigned char GetField24();
    unsigned char FUN_00552bb0();
    unsigned char FUN_00542d20();
    void* FUN_005454d0();
    void ClearAudioMarkers();
    ExteriorCellData* GetExteriorData();
    int GetCellGridX();
    int GetCellGridY();
    bool HasCellExtraData();
    bool IsCellInterior() const;
    TESWorldSpace* GetParentWorldSpace();
    void CellRefLockEnter();
    void ClearData();
    void SetLightingTemplate(void* value);
    int GetCellStandValue();
    InteriorCellData* GetInteriorData();
    bool FUN_00558b80(int mask);
    CellLightingTemplate* GetLightingTemplate();
    float GetInteriorLightValue();
    BSSimpleList<BGSPerkEntry*>* FUN_009604f0();
    void CellRefLockLeave();
    void ClearCellReferenceList();
    NiAVObject* GetCellChildAt(int index);
    NiAVObject* GetDynamicNode();
    NiNode* FUN_00545cb0();
    BGSEncounterZone* FindEncounterZone() const;
};

#endif
