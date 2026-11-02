// fallout_shared/tempeffects/bstempeffect_decls.h: declares SandBoxActorPackageData, NiObject, BSTempEffect

enum PTYPE
{
    PTYPE_SANDBOX = 12
};
class SandBoxActorPackageData
{
  public:
    PTYPE GetPackageType();
};
class TESObjectCELL;
class NiObject
{
  public:
    NiObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};
class BSTempEffect : public NiObject
{
  public:
    BSTempEffect(TESObjectCELL*, float);
    virtual void DeleteThis();
    float m_fParticleParameter5;
    TESObjectCELL* pCell;
    float m_fFirstFloatValue;
    bool bInitialized;
};
