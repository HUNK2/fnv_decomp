// gamebryo2.2/corelibs/niparticle/nipsyspositionmodifier_decls.h: declares NiObject, NiFixedString, NiPSysPositionModifier
#ifndef NIPSYSPOSITIONMODIFIER_DECLS_H
#define NIPSYSPOSITIONMODIFIER_DECLS_H

class NiObject
{
  public:
    NiObject();
    virtual ~NiObject();
    unsigned int m_uiRefCount;
};
class NiFixedString
{
  public:
    char* m_kHandle;
};
extern NiFixedString EmptyFS;
class NiParticleSystem;
class NiPSysPositionModifier : public NiObject
{
  public:
    NiPSysPositionModifier();
    virtual ~NiPSysPositionModifier();
    NiFixedString m_kName;
    unsigned int m_uiUpdateOrder;
    NiParticleSystem* m_pkTarget;
    bool m_bModifierActive;
};
#endif
