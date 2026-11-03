// fallout_shared/bgsopencloseform_packet_decls.h: declares TESForm, TESBoundObject, NiFixedString, NiObjectNET, NiUpdateData and more
#ifndef BGSOPENCLOSEFORM_PACKET_DECLS_H
#define BGSOPENCLOSEFORM_PACKET_DECLS_H

#include "layout_support.h"
// Private PC declaration subset. Folded accessor identities retain canonical
class TESForm
{
  public:
    ENUM_FORM_ID GetFormType() const;
};
class TESBoundObject : public TESForm
{
};
class NiFixedString
{
  public:
    operator const char*() const;
};
class NiTimeController;
class NiObjectNET
{
  public:
    NiTimeController* GetControllers() const;
};
class NiUpdateData
{
  public:
    float time;
    bool updateControllers;
    bool isMultiThreaded;
    bool flag6;
    bool flag7;
    bool flag8;
    NiUpdateData(float, bool, bool);
};
class NiNode : public NiObjectNET
{
  public:
    void Update(const NiUpdateData&);
};
struct NiRTTI
{
};
class NiProperty;
class SkyShaderProperty;
SkyShaderProperty* FUN_00653270(const NiRTTI*, NiProperty*);
extern NiRTTI DAT_011f36ac;
enum OBJECT_ACTION
{
    ACTION_OPEN = 4
};
class ExtraRadioData;
class ExtraDataList
{
  public:
    void CallExtraDataListMethod36(TESObjectREFR*);
};
class TESObjectREFR
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiNode* GetNiNode_v();
    TESBoundObject* GetObjectReference();
    bool GetAction(OBJECT_ACTION);
    void PerformAction(OBJECT_ACTION);
    void CloseReference(OBJECT_ACTION);
    ExtraDataList* GetExtraData();
    ExtraRadioData* GetExtraRadioData();
    void TESObjectREFR_SetLastFinishedSequence(const char*);
};
class NiControllerSequence
{
  public:
    const NiFixedString& GetName() const;
    void FUN_0098adb0(float);
    float FUN_00759450();
};
class LowProcess
{
  public:
    TESObjectREFR* GetActiveCombatTarget();
};
class NiControllerManager
{
  public:
    NiControllerSequence* FindSequenceByName(const NiFixedString&);
    static NiFixedString* FindSequenceByName();
    void FUN_0047aa40(bool);
    bool ActivateControllerSequence(NiControllerSequence*, int, bool, float, float, NiControllerSequence*);
    bool StopSequence(NiControllerSequence*, float);
};
class TESObjectDOOR
{
  public:
    virtual ~TESObjectDOOR();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    static NiFixedString* GetOpenSequenceName();
};
class BGSOpenCloseForm
{
  public:
    virtual ~BGSOpenCloseForm();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    enum OPEN_STATE
    {
        CLOSED_UNKNOWN,
        OPEN,
        OPENING,
        CLOSED,
        CLOSING
    };
    static bool HasOpenCloseComponent(TESForm*);
    static OPEN_STATE GetOpenState(TESObjectREFR*);
    static bool SetOpenState(TESObjectREFR*, bool, bool);
};
class AIThreadManager
{
  public:
    static TESObjectREFR* IsConditionMet();
};
bool IsConditionMet();
class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
    void FUN_0087b600(TESObjectREFR*, bool, bool);
};
class NavMeshObstacleManager
{
  public:
    static NavMeshObstacleManager* GetSingleton();
    void RemoveObstacleReference(TESObjectREFR*);
    void AddObstacleReference(TESObjectREFR*);
};
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};
class GlobalObject_0045cf30
{
};
extern GlobalObject_0045cf30 g_011d7188;
extern const char DAT_01011f30[];
extern const char g_011d22b0_arg1[];
extern float DAT_0101ab70;
void FUN_00c6bd00(NiNode*, bool);
#endif
