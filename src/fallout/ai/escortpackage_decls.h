// fallout/ai/escortpackage_decls.h: declares EscortActorPackageData
#ifndef ESCORTPACKAGE_DECLS_H
#define ESCORTPACKAGE_DECLS_H

extern void* kVtbl_UseWeaponActorPackageData[];
class Actor;
class EscortActorPackageData
{
  public:
    EscortActorPackageData();
    void FUN_0067d920();
    void** m_ppVirtualMethodTable;
    Actor* pActor;
};
#endif
