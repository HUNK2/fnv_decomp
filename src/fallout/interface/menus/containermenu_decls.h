// fallout/interface/menus/containermenu_decls.h: declares TESObjectREFR, Actor, PlayerCharacter, BSAudio, TESCreature and more
#ifndef CONTAINERMENU_DECLS_H
#define CONTAINERMENU_DECLS_H

class TESForm;
class TESBoundObject;
class ActorCause;
class TESObjectREFR
{
  public:
    virtual ~TESObjectREFR();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    TESForm* GetOwner();
    TESBoundObject* GetObjectReference();
};
class BaseProcess;
class Actor
{
  public:
    virtual ~Actor();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    BaseProcess* GetProcess();
    void StealAlarm(TESObjectREFR*, int, int, int, TESForm*);
    bool IsFirstActorFlagSet();
    void SetIsSwimming(bool);
};
class PlayerCharacter
{
  public:
    void UpdatePlayerControls();
};
class SoundPlaybackHandle
{
  public:
    unsigned m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char pad[3];
    unsigned eState;
    bool Play(bool);
    bool StopWithFade(unsigned);
    ~SoundPlaybackHandle();
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    SoundPlaybackHandle GetSoundHandleByEditorID(const char*, unsigned);
};
class TESCreature
{
  public:
    void UpdateModel3D(TESObjectREFR*, bool, bool, bool);
};
class TESNPC
{
  public:
    void RebuildHeadModel(TESObjectREFR*, void*);
};
class HUDMainMenu
{
  public:
    bool RefreshTargetDisplay();
};
template <class T> class BSSimpleList
{
  public:
    void* head;
    void* next;
    void RemoveAll();
};
class Tile
{
  public:
    void Set(int, int);
};
class Menu
{
  public:
    char menuData[40];
    void LoadMenuData();
};
class ContainerMenu : public Menu
{
  public:
    Tile* m_pTiles[19];
    TESObjectREFR* m_pContainer;
    BSSimpleList<TESBoundObject*> m_kContainerItems;
    int m_eContainerMenuMode;
    int m_iStolenItemCount;
    char otherData[120];
    SoundPlaybackHandle m_kFadeSequence;
    static void Close();
    void UpdateContainer(TESObjectREFR*, bool);
};
extern ContainerMenu* DAT_011d93f8;
extern PlayerCharacter* g_thePlayer;
extern int DAT_011f2250;
extern const char DAT_01072278[];
extern void __cdecl StartDialogueForTopic(int);
extern void __cdecl FUN_00778b10();
class CloseVirtualSlots
{
  public:
    virtual void vfn_0000() = 0;
    virtual void vfn_0004() = 0;
    virtual void vfn_0008() = 0;
    virtual void vfn_000c() = 0;
    virtual void vfn_0010() = 0;
    virtual void vfn_0014() = 0;
    virtual void vfn_0018() = 0;
    virtual void vfn_001c() = 0;
    virtual void vfn_0020() = 0;
    virtual void vfn_0024() = 0;
    virtual void vfn_0028() = 0;
    virtual void vfn_002c() = 0;
    virtual void vfn_0030() = 0;
    virtual void vfn_0034() = 0;
    virtual void vfn_0038() = 0;
    virtual void vfn_003c() = 0;
    virtual void vfn_0040() = 0;
    virtual void vfn_0044() = 0;
    virtual void vfn_0048() = 0;
    virtual void vfn_004c() = 0;
    virtual void vfn_0050() = 0;
    virtual void vfn_0054() = 0;
    virtual void vfn_0058() = 0;
    virtual void vfn_005c() = 0;
    virtual void vfn_0060() = 0;
    virtual void vfn_0064() = 0;
    virtual void vfn_0068() = 0;
    virtual void vfn_006c() = 0;
    virtual void vfn_0070() = 0;
    virtual void vfn_0074() = 0;
    virtual void vfn_0078() = 0;
    virtual void vfn_007c() = 0;
    virtual void vfn_0080() = 0;
    virtual void vfn_0084() = 0;
    virtual void vfn_0088() = 0;
    virtual void vfn_008c() = 0;
    virtual void vfn_0090() = 0;
    virtual void vfn_0094() = 0;
    virtual void vfn_0098() = 0;
    virtual void vfn_009c() = 0;
    virtual void vfn_00a0() = 0;
    virtual void vfn_00a4() = 0;
    virtual void vfn_00a8() = 0;
    virtual void vfn_00ac() = 0;
    virtual void vfn_00b0() = 0;
    virtual void vfn_00b4() = 0;
    virtual void vfn_00b8() = 0;
    virtual void vfn_00bc() = 0;
    virtual void vfn_00c0() = 0;
    virtual void vfn_00c4() = 0;
    virtual void vfn_00c8() = 0;
    virtual void vfn_00cc() = 0;
    virtual void vfn_00d0() = 0;
    virtual void vfn_00d4() = 0;
    virtual void vfn_00d8() = 0;
    virtual void vfn_00dc() = 0;
    virtual void vfn_00e0() = 0;
    virtual void vfn_00e4() = 0;
    virtual void vfn_00e8() = 0;
    virtual void vfn_00ec() = 0;
    virtual void vfn_00f0() = 0;
    virtual void vfn_00f4() = 0;
    virtual void vfn_00f8() = 0;
    virtual void vfn_00fc() = 0;
    virtual bool IsActor() = 0;
    virtual void vfn_0104() = 0;
    virtual void vfn_0108() = 0;
    virtual void vfn_010c() = 0;
    virtual void vfn_0110() = 0;
    virtual void vfn_0114() = 0;
    virtual void vfn_0118() = 0;
    virtual void vfn_011c() = 0;
    virtual void vfn_0120() = 0;
    virtual void vfn_0124() = 0;
    virtual void vfn_0128() = 0;
    virtual void vfn_012c() = 0;
    virtual void vfn_0130() = 0;
    virtual void vfn_0134() = 0;
    virtual void vfn_0138() = 0;
    virtual void vfn_013c() = 0;
    virtual void vfn_0140() = 0;
    virtual void vfn_0144() = 0;
    virtual int GetCastsShadows() = 0;
    virtual void vfn_014c() = 0;
    virtual void vfn_0150() = 0;
    virtual void vfn_0154() = 0;
    virtual void vfn_0158() = 0;
    virtual void vfn_015c() = 0;
    virtual void vfn_0160() = 0;
    virtual void vfn_0164() = 0;
    virtual void vfn_0168() = 0;
    virtual void vfn_016c() = 0;
    virtual void vfn_0170() = 0;
    virtual void vfn_0174() = 0;
    virtual void vfn_0178() = 0;
    virtual void vfn_017c() = 0;
    virtual void vfn_0180() = 0;
    virtual void vfn_0184() = 0;
    virtual void vfn_0188() = 0;
    virtual void vfn_018c() = 0;
    virtual void vfn_0190() = 0;
    virtual void vfn_0194() = 0;
    virtual void vfn_0198() = 0;
    virtual void vfn_019c() = 0;
    virtual void vfn_01a0() = 0;
    virtual void vfn_01a4() = 0;
    virtual void vfn_01a8() = 0;
    virtual void vfn_01ac() = 0;
    virtual void vfn_01b0() = 0;
    virtual void vfn_01b4() = 0;
    virtual void vfn_01b8() = 0;
    virtual void vfn_01bc() = 0;
    virtual void vfn_01c0() = 0;
    virtual void vfn_01c4() = 0;
    virtual void vfn_01c8() = 0;
    virtual void vfn_01cc() = 0;
    virtual void vfn_01d0() = 0;
    virtual void vfn_01d4() = 0;
    virtual void vfn_01d8() = 0;
    virtual void vfn_01dc() = 0;
    virtual void vfn_01e0() = 0;
    virtual void* vfn_1e4() = 0;
    virtual void* vfn_1e8(bool) = 0;
    virtual void vfn_01ec() = 0;
    virtual void vfn_01f0() = 0;
    virtual void vfn_01f4() = 0;
    virtual void vfn_01f8() = 0;
    virtual void vfn_01fc() = 0;
    virtual void vfn_0200() = 0;
    virtual void vfn_0204() = 0;
    virtual void vfn_0208() = 0;
    virtual void vfn_020c() = 0;
    virtual void vfn_0210() = 0;
    virtual void vfn_0214() = 0;
    virtual void vfn_0218() = 0;
    virtual bool IsCreature() = 0;
    virtual void vfn_0220() = 0;
    virtual void vfn_0224() = 0;
    virtual void vfn_0228() = 0;
    virtual void vfn_022c() = 0;
    virtual void vfn_0230() = 0;
    virtual void vfn_0234() = 0;
    virtual void vfn_0238() = 0;
    virtual void vfn_023c() = 0;
    virtual void vfn_0240() = 0;
    virtual void vfn_0244() = 0;
    virtual void vfn_0248() = 0;
    virtual void vfn_024c() = 0;
    virtual void vfn_0250() = 0;
    virtual void vfn_0254() = 0;
    virtual void vfn_0258() = 0;
    virtual void vfn_025c() = 0;
    virtual void vfn_0260() = 0;
    virtual void vfn_0264() = 0;
    virtual void vfn_0268() = 0;
    virtual void vfn_026c() = 0;
    virtual void vfn_0270() = 0;
    virtual void vfn_0274() = 0;
    virtual void vfn_0278() = 0;
    virtual void vfn_027c() = 0;
    virtual void vfn_0280() = 0;
    virtual void vfn_0284() = 0;
    virtual void vfn_0288() = 0;
    virtual void vfn_028c() = 0;
    virtual void vfn_0290() = 0;
    virtual void vfn_0294() = 0;
    virtual void vfn_0298() = 0;
    virtual void vfn_029c() = 0;
    virtual void vfn_02a0() = 0;
    virtual void vfn_02a4() = 0;
    virtual void vfn_02a8() = 0;
    virtual void vfn_02ac() = 0;
    virtual void vfn_02b0() = 0;
    virtual void vfn_02b4() = 0;
    virtual void vfn_02b8() = 0;
    virtual void vfn_02bc() = 0;
    virtual void vfn_02c0() = 0;
    virtual void vfn_02c4() = 0;
    virtual void vfn_02c8() = 0;
    virtual void vfn_02cc() = 0;
    virtual void vfn_02d0() = 0;
    virtual void vfn_02d4() = 0;
    virtual void vfn_02d8() = 0;
    virtual void vfn_02dc() = 0;
    virtual void vfn_02e0() = 0;
    virtual void vfn_02e4() = 0;
    virtual void vfn_02e8() = 0;
    virtual void vfn_02ec() = 0;
    virtual void vfn_02f0() = 0;
    virtual void vfn_02f4() = 0;
    virtual void vfn_02f8() = 0;
    virtual void vfn_02fc() = 0;
    virtual void vfn_0300() = 0;
    virtual void vfn_0304() = 0;
    virtual void vfn_0308() = 0;
    virtual void vfn_030c() = 0;
    virtual void vfn_0310() = 0;
    virtual void vfn_0314() = 0;
    virtual void vfn_0318() = 0;
    virtual void vfn_031c() = 0;
    virtual void vfn_0320() = 0;
    virtual void vfn_0324() = 0;
    virtual void vfn_0328() = 0;
    virtual void vfn_032c() = 0;
    virtual void vfn_0330() = 0;
    virtual void vfn_0334() = 0;
    virtual void vfn_0338() = 0;
    virtual void vfn_033c() = 0;
    virtual bool vfn_340(int) = 0;
    virtual void vfn_0344() = 0;
    virtual void vfn_0348() = 0;
    virtual void vfn_034c() = 0;
    virtual void vfn_0350() = 0;
    virtual void vfn_0354() = 0;
    virtual void vfn_0358() = 0;
    virtual void vfn_035c() = 0;
    virtual void vfn_0360() = 0;
    virtual void vfn_0364() = 0;
    virtual void vfn_0368() = 0;
    virtual void vfn_036c() = 0;
    virtual void vfn_0370() = 0;
    virtual void vfn_0374() = 0;
    virtual void vfn_0378() = 0;
    virtual void vfn_037c() = 0;
    virtual void vfn_0380() = 0;
    virtual void vfn_0384() = 0;
    virtual void vfn_0388() = 0;
    virtual void vfn_038c() = 0;
    virtual void vfn_0390() = 0;
    virtual void vfn_0394() = 0;
    virtual void vfn_0398() = 0;
    virtual void vfn_039c() = 0;
    virtual void vfn_03a0() = 0;
    virtual void vfn_03a4() = 0;
    virtual void vfn_03a8() = 0;
    virtual void vfn_03ac() = 0;
    virtual void vfn_03b0() = 0;
    virtual void vfn_03b4() = 0;
    virtual void vfn_03b8() = 0;
    virtual void vfn_03bc() = 0;
    virtual void vfn_03c0() = 0;
    virtual void vfn_03c4() = 0;
    virtual void vfn_03c8() = 0;
    virtual void vfn_03cc() = 0;
    virtual void vfn_03d0() = 0;
    virtual void vfn_03d4() = 0;
    virtual void vfn_03d8() = 0;
    virtual void vfn_03dc() = 0;
    virtual void vfn_03e0() = 0;
    virtual void vfn_03e4() = 0;
    virtual void vfn_03e8() = 0;
    virtual void vfn_03ec() = 0;
    virtual void vfn_03f0() = 0;
    virtual void vfn_03f4() = 0;
    virtual void vfn_03f8() = 0;
    virtual void vfn_03fc() = 0;
    virtual void vfn_0400() = 0;
    virtual void vfn_0404() = 0;
    virtual void vfn_0408() = 0;
    virtual void vfn_040c() = 0;
    virtual void vfn_0410() = 0;
    virtual void vfn_0414() = 0;
    virtual void vfn_0418() = 0;
    virtual void vfn_041c() = 0;
    virtual void vfn_0420() = 0;
    virtual void vfn_0424() = 0;
    virtual void vfn_0428() = 0;
    virtual void vfn_042c() = 0;
    virtual void vfn_0430() = 0;
    virtual void vfn_0434() = 0;
    virtual void vfn_0438() = 0;
    virtual void vfn_043c() = 0;
    virtual void vfn_0440() = 0;
    virtual void vfn_0444() = 0;
    virtual void vfn_0448() = 0;
    virtual void vfn_044c() = 0;
    virtual void vfn_0450() = 0;
    virtual void vfn_0454() = 0;
    virtual void vfn_0458() = 0;
    virtual void vfn_045c() = 0;
    virtual void vfn_0460() = 0;
    virtual void vfn_0464() = 0;
    virtual void vfn_0468() = 0;
    virtual void vfn_046c() = 0;
    virtual void vfn_0470() = 0;
    virtual bool vfn_474(bool) = 0;
};
#endif
