// Declaration-only interface; no BGSProjectile object is created or laid out here.
// Public PC signatures and address annotations: JohnnyGuitarNVSE
// JG/internal/Game/Bethesda/BGSProjectile.hpp and BGSProjectile.cpp.
#ifndef FNV_GRENADEPROJECTILE_BGSPROJECTILE_H
#define FNV_GRENADEPROJECTILE_BGSPROJECTILE_H

class BGSProjectile
{
  public:
    float GetFloatAtOffset68();
    float GetFloatAtOffsetB0();  // declared for the original code (decl_variants.py)

  public:
    bool GetHasExplosionDetonates() const;
    bool GetHasExplosionAltTrigger() const;
    float GetExplosionProximity() const;
};
#endif
