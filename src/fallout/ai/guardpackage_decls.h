// fallout/ai/guardpackage_decls.h: declares TESForm, Actor, TESObjectREFRHelper, GuardActorPackageData, BGSLoadFormBuffer
#ifndef GUARDPACKAGE_DECLS_H
#define GUARDPACKAGE_DECLS_H

double FUN_00408860(float);
namespace std {
double abs(float);
}
class TESForm
{
  public:
    virtual ~TESForm();
    static TESForm* GetFormByID(unsigned int);
};
class Actor : public TESForm
{
};
class TESObjectREFRHelper
{
  public:
    void SetTargetingState(bool);
};
class BGSLoadFormBuffer;
class GuardActorPackageData
{
  public:
    void* vtable;
    unsigned int eState;
    Actor* pWarningTarget;
    int iWarningCount;
    float m_fWarningTimer;
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
};
class BGSLoadFormBuffer
{
  public:
    void ReadTypedData(void*, unsigned int);
    bool ReadFormIdentifier(void*);
};
#endif
