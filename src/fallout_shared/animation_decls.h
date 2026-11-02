// fallout_shared/animation_decls.h: declares NiUpdateData, NiNode, NiMemObject, NiControllerManager, NiControllerSequence and more
#ifndef ANIMATION_DECLS_H
#define ANIMATION_DECLS_H

// Shared classes come from the canonical include/ headers: TESForm/TESObjectREFR/MobileObject/Actor/Character/
// PlayerCharacter (PC virtual slots), BaseProcess (all 493 PC virtuals), AutoMemContext/MEM_CONTEXT, BSSimpleList,
// NiTPointerMap.
// Explicit ../../include/ paths: src/fallout_shared has case-insensitive shadows (layout_support.h, TESForm.h, ...).
// Unit-local supersets of canonical leaf types (same layout), because matched functions use members the canonical
// headers do not declare yet:
//   NiPointer: ctors, operator T*, operator->, copy assignment (out-of-line calls in matched code).
//   NiPoint3: default ctor (called by Animation::Animation) and static ZERO (?ZERO@NiPoint3@@2V1@B, 0x011f426c).
//   NiFixedString: operator const char* (0x0043b1b0).
// Still unit-local because no canonical header exists: NiNode, NiAVObject, NiControllerManager, NiControllerSequence,
// NiUpdateData, AnimSequenceBase, AnimIdle, KFModel, TESBoundObject.
// first-definition-wins type index shows them (not the renamed canonical text).
#include "animation_local_types.h"
#define NiPointer FNV_NiPointer_Canonical
#define NiPoint3 FNV_NiPoint3_Canonical
#include "../../include/layout_support.h"
#include "../../include/NiPoint3.h"
#undef NiPoint3
#undef NiPointer
FNV_STATIC_ASSERT(sizeof(NiPoint3) == sizeof(FNV_NiPoint3_Canonical));
#include "../../include/TESObjectREFR.h"
#include "../../include/Actor.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/BaseProcess.h"
#include "../../include/AutoMemContext.h"
class NiNode;
class NiAVObject;
class NiControllerManager;
class AnimIdle;
class KFModel;
class AnimSequenceBase;
class BSAnimGroupSequence;
class IdleReplayDelayEntry;
class NiUpdateData
{
  public:
    float time;
    unsigned int flags;
    bool multithread;
    NiUpdateData(float, bool, bool);
};
class NiNode
{
  public:
    const NiFixedString& GetName() const;
    void FUN_004902f0(bool);
    void FUN_0043fa80(void*);
    void Update(const NiUpdateData&);
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class NiControllerManager : public NiMemObject
{
  public:
    char data[124];
    NiControllerManager(NiNode*, bool);
};
class NiControllerSequence
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();

    virtual bool Deactivate(float, bool);
    bool Activate(char, bool, float, float, NiControllerSequence*, bool);
    int GetState();
    const NiFixedString& GetName() const;
};
class BSAnimGroupSequence : public NiControllerSequence
{
};
class AnimSequenceBase
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual BSAnimGroupSequence* GetSequenceAtIndex(int);
};
class AnimIdle
{
  public:
    int GetSection();
    BSAnimGroupSequence* GetControllerSequence();
};
class TESBoundObject
{
  public:
    int GetFormType() const;
};
// TESObjectREFR non-virtual (0x00490310) the canonical header does not declare yet.
class TESObjectREFR_AnimationExt : public TESObjectREFR
{
  public:
    NiAVObject* FUN_00490310(NiNode*, const char*);
};
class KFModel
{
  public:
    void* GetControllerSequence();
};
class ModelLoader
{
  public:
    KFModel* LoadKF(const char*);
};
extern ModelLoader* g_modelLoader;
extern const char* DAT_01199bcc[];
extern char DAT_011a9448;
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern "C" void* memset(void*, int, unsigned int);
int Warning(const char*, ...);
enum ANIM_GROUP_ACTION
{
    AGA_NONE = -1,
    AGA_START = 0
};
class Animation
{
  public:
    unsigned char m_uiObjectFlags;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    TESObjectREFR* m_pAttachedReference;           // +0x4, 4 bytes
    NiPointer<NiNode> m_acHeaderData;        // +0x8, 4 bytes
    NiNode* m_pObjectNode;                 // +0xC, 4 bytes
    NiPoint3 m_kNodeTranslation;             // +0x10, 12 bytes
    NiPoint3 m_kRootTranslation;        // +0x1C, 12 bytes
    NiAVObject* m_acNodeName[8];  // +0x28, 32 bytes
    float m_fAnimationAmount;                   // +0x48, 4 bytes
    unsigned short group[8];            // +0x4C, 16 bytes
    ANIM_GROUP_ACTION action[8];        // +0x5C, 32 bytes
    int m_acTargetName[8];                   // +0x7C, 32 bytes
    unsigned short usReloadGroup[8];        // +0x9C, 16 bytes
    int m_acAnimationName[8];                   // +0xAC, 32 bytes
    char m_cState;                   // +0xCC, 1 bytes
    bool m_bIsPlaying;                     // +0xCD, 1 bytes
    unsigned char layoutPaddingCE[2];
    float time;                                                          // +0xD0, 4 bytes
    float m_fTimeOffset;                                                      // +0xD4, 4 bytes
    NiPointer<NiControllerManager> m_acReservedBytes;                            // +0xD8, 4 bytes
    NiTPointerMap<unsigned short, AnimSequenceBase*>* m_pOwnerReference;  // +0xDC, 4 bytes
    BSAnimGroupSequence* m_pChildTile[8];                            // +0xE0, 32 bytes
    BSAnimGroupSequence* m_pCurrentSequence;                          // +0x100, 4 bytes
    BSSimpleList<KFModel*> kfModelList;                                  // +0x104, 8 bytes
    float m_fMovementRate;                                                  // +0x10C, 4 bytes
    float m_fCombatAnimationRate;                                                // +0x110, 4 bytes
    float m_fEquipAnimationRate;                                       // +0x114, 4 bytes
    float m_fReloadAnimationRate;                                             // +0x118, 4 bytes
    float m_fAnimationTimeScale;                                              // +0x11C, 4 bytes
    char m_cSkipNextBlend;                                                 // +0x120, 1 bytes
    unsigned char layoutPadding121[1];
    unsigned short m_usQueuedGroup;                    // +0x122, 2 bytes
    NiPointer<AnimIdle> LocalInput;                       // +0x124, 4 bytes
    NiPointer<AnimIdle> LocalStateValue;                 // +0x128, 4 bytes
    NiPointer<AnimIdle> LocalOutput[2];   // +0x12C, 8 bytes
    BSSimpleList<IdleReplayDelayEntry*> m_acTrailingData;  // +0x134, 8 bytes

    Animation();
    bool Init(BSSimpleList<const char*>*, NiNode*, TESObjectREFR*, bool);
    void SpecialIdleFree(bool, bool);
    void AssignControllerManager(NiPointer<AnimIdle>&);
    void BlendOut(int, bool);
    bool IsAnimationLoaded();
    bool AddAnimation(KFModel*, bool);
    void UpdateFlags(unsigned char, unsigned char, unsigned char);
};
#endif
