// gamebryo2.2/corelibs/niparticle/nipsysmodifieractivectlr_decls.h: declares NiPSysModifierCtlr, NiPSysAirFieldAirFrictionCtlr

class CloningProcess;
class NiPSysModifierCtlr
{
  public:
    void CopyMemberData(NiPSysModifierCtlr*, CloningProcess&);
};
class NiPSysAirFieldAirFrictionCtlr : public NiPSysModifierCtlr
{
  public:
    void CopyMemberData(NiPSysAirFieldAirFrictionCtlr*, CloningProcess&);
};
