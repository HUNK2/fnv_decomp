// fallout/ai/baseprocess_worker.h: declares BaseProcess, ActorPackageCall, TESPackage, CachedValuesCall, GuardActorPackageDataCall and more
#ifndef FNV_BASEPROCESS_WORKER_H
#define FNV_BASEPROCESS_WORKER_H

#include "layout_support.h"
#include "ActorPackageContext.h"
class BGSLoadFormBuffer;
class TESPackage;
class MobileObject;
class TESObjectREFR;
class BaseProcess
{
  public:
    void** m_ppVirtualMethodTable;
    ActorPackageContext m_kProcessData;
    float m_fValue2;
    float m_fValue1;
    unsigned int m_uiStateFlags;
    PROCESS_TYPE m_eProcessType;
    CachedValues* m_pCachedValues;
    int GetAttackChance(Actor*, float, float, float, bool, bool);
    void Copy(BaseProcess*);
    void SetCurrentPackageAndTarget(TESPackage*, MobileObject*);
    void SetReferenceTarget(TESObjectREFR*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    void ApplyLoadBuffer(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
};
FNV_STATIC_ASSERT(sizeof(BaseProcess) == 0x30);
class ActorPackageCall
{
  public:
    void SetPackageAndTarget(TESPackage*, TESObjectREFR*);
    void LoadGame(BGSLoadFormBuffer*);
    void ApplyLoadBuffer(BGSLoadFormBuffer*);
    void FUN_008c6970(BGSLoadFormBuffer*);
    void FUN_008c6c80(BGSLoadFormBuffer*);
};
class TESPackage
{
  public:
    TESObjectREFR* GetResolvedTargetReference(MobileObject*);
};
class CachedValuesCall
{
  public:
    void ClearField44();
};
class GuardActorPackageDataCall
{
  public:
    void SetReferenceTarget(TESObjectREFR*);
};
class PatrolActorPackageData;
class LowProcess
{
  public:
    PatrolActorPackageData* GetCurrentPackageData();
};
class ActorPackageDataVirtualCall
{
  public:
    virtual void Slot0() = 0;
    virtual void SetReferenceTarget(TESObjectREFR*) = 0;
};
class BGSLoadFormBuffer
{
  public:
    void ReadTypedData(void*, unsigned int);
};
class BGSLoadFormBufferVirtual
{
  public:
    virtual unsigned char GetVersion() = 0;
};

class MiddleHighProcessCall
{
  public:
    void CopyProcessDataFrom(MiddleHighProcessCall*);
};
class CopyCall00914c60
{
  public:
    void FUN_00914c60(CopyCall00914c60*);
};
class CachedValuesCopyCall
{
  public:
    void Copy(CachedValuesCopyCall*);
};
class LowProcessCopyCall
{
  public:
    void HandlePackageChange(LowProcessCopyCall*);
};
class LowProcessCachedCopyCall
{
  public:
    void HandlePackageChange(LowProcessCachedCopyCall*);
};
extern char DAT_0118a6b8;
extern char DAT_0118a6d4;
extern char DAT_0118c64c;
extern char DAT_011a3668;
extern char DAT_011a364c;
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
class BaseProcessCopyVirtual
{
  public:
    virtual void vfn_000();
    virtual void vfn_001();
    virtual void vfn_002();
    virtual void vfn_003();
    virtual void vfn_004();
    virtual void vfn_005();
    virtual void vfn_006();
    virtual void vfn_007();
    virtual void vfn_008();
    virtual void vfn_009();
    virtual void vfn_010();
    virtual void vfn_011();
    virtual void vfn_012();
    virtual void vfn_013();
    virtual void vfn_014();
    virtual void vfn_015();
    virtual void vfn_016();
    virtual void vfn_017();
    virtual void vfn_018();
    virtual void vfn_019();
    virtual void vfn_020();
    virtual void vfn_021();
    virtual void vfn_022();
    virtual void vfn_023();
    virtual void vfn_024();
    virtual void vfn_025();
    virtual void vfn_026();
    virtual void vfn_027();
    virtual void vfn_028();
    virtual void vfn_029();
    virtual void vfn_030();
    virtual void vfn_031();
    virtual void vfn_032();
    virtual void vfn_033();
    virtual void vfn_034();
    virtual void vfn_035();
    virtual void vfn_036();
    virtual void vfn_037();
    virtual void vfn_038();
    virtual void vfn_039();
    virtual void vfn_040();
    virtual void vfn_041();
    virtual void vfn_042();
    virtual void vfn_043();
    virtual void vfn_044();
    virtual void vfn_045();
    virtual void vfn_046();
    virtual void vfn_047();
    virtual void vfn_048();
    virtual void vfn_049();
    virtual void vfn_050();
    virtual void vfn_051();
    virtual void vfn_052();
    virtual void vfn_053();
    virtual void vfn_054();
    virtual void vfn_055();
    virtual void vfn_056();
    virtual void vfn_057();
    virtual void vfn_058();
    virtual void vfn_059();
    virtual void vfn_060();
    virtual void vfn_061();
    virtual void vfn_062();
    virtual void vfn_063();
    virtual void vfn_064();
    virtual void vfn_065();
    virtual void vfn_066();
    virtual void vfn_067();
    virtual void vfn_068();
    virtual void vfn_069();
    virtual void vfn_070();
    virtual void vfn_071();
    virtual void vfn_072();
    virtual void vfn_073();
    virtual void vfn_074();
    virtual void vfn_12c(int);
    virtual void vfn_076();
    virtual void vfn_077();
    virtual void vfn_078();
    virtual void vfn_079();
    virtual void vfn_080();
    virtual void vfn_081();
    virtual void vfn_082();
    virtual void vfn_083();
    virtual void vfn_084();
    virtual void vfn_085();
    virtual void vfn_086();
    virtual void vfn_087();
    virtual void vfn_088();
    virtual void vfn_089();
    virtual void vfn_090();
    virtual void vfn_091();
    virtual void vfn_092();
    virtual void vfn_093();
    virtual void vfn_094();
    virtual void vfn_095();
    virtual void vfn_096();
    virtual void vfn_097();
    virtual void vfn_098();
    virtual void vfn_099();
    virtual void vfn_100();
    virtual void vfn_101();
    virtual void vfn_102();
    virtual void vfn_103();
    virtual void vfn_104();
    virtual void vfn_105();
    virtual void vfn_106();
    virtual void vfn_107();
    virtual void vfn_108();
    virtual void vfn_109();
    virtual void vfn_110();
    virtual void vfn_111();
    virtual void vfn_112();
    virtual void vfn_113();
    virtual void vfn_114();
    virtual void vfn_115();
    virtual void vfn_116();
    virtual void vfn_117();
    virtual void vfn_118();
    virtual void vfn_119();
    virtual double vfn_1e0();
    virtual void vfn_121();
    virtual void vfn_122();
    virtual void vfn_123();
    virtual void vfn_124();
    virtual void vfn_125();
    virtual void vfn_126();
    virtual void vfn_127();
    virtual void vfn_128();
    virtual void vfn_129();
    virtual void vfn_130();
    virtual void vfn_131();
    virtual void vfn_132();
    virtual void vfn_214();
};
#endif
