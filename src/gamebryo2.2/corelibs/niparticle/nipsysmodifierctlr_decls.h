// gamebryo2.2/corelibs/niparticle/nipsysmodifierctlr_decls.h: declares CloningProcess, NiSingleInterpController, NiPSysModifierCtlr
#ifndef NIPSYSMODIFIERCTLR_DECLS_H
#define NIPSYSMODIFIERCTLR_DECLS_H

class ShaderBufferRecord;
template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char*, T&);
};
class CloningProcess
{
  public:
    NiTStringPointerMap<ShaderBufferRecord*>* m_pCloneMap;
};
class NiSingleInterpController
{
  public:
    virtual void ProcessClone(CloningProcess&);
    unsigned char padding[40];
    void* m_pkTarget;
    unsigned char rest[8];
};
class NiPSysModifierCtlr : public NiSingleInterpController
{
  public:
    void* m_kTargetModifierName;
    void* m_pkTargetModifier;
    virtual void ProcessClone(CloningProcess&);
};
#endif
