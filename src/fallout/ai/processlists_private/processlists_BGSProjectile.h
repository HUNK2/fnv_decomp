// fallout/ai/processlists_private/processlists_BGSProjectile.h: declares ProjectileProperties, BGSProjectile
#ifndef PROCESSLISTS_PRIVATE_BGSPROJECTILE_H
#define PROCESSLISTS_PRIVATE_BGSPROJECTILE_H

#include "processlists_TESBoundObject.h"
#include "processlists_TESFullName.h"
#include "processlists_TESModel.h"
#include "processlists_BGSPreloadable.h"
#include "processlists_types_BGSDestructibleObjectForm.h"
class TESObjectLIGH;
class TESObjectWEAP;
class BGSExplosion;
#include "processlists_actor_enums.h"
class ProjectileProperties
{
  public:
    unsigned int iFlags;                      // +0x0, 4 bytes
    float afGravity;                          // +0x4, 4 bytes
    float fSpeed;                             // +0x8, 4 bytes
    float fImpulseRadiusSquared;                             // +0xC, 4 bytes
    TESObjectLIGH* apTargetLight;                    // +0x10, 4 bytes
    TESObjectLIGH* m_pSecondLight;            // +0x14, 4 bytes
    float ExplosionLightingData;              // +0x18, 4 bytes
    float LightExplosionSoundData;            // +0x1C, 4 bytes
    float AlphaFloatParameters;               // +0x20, 4 bytes
    BGSExplosion* ExplosionFadeData;          // +0x24, 4 bytes
    TESSound* m_pExplosionSound;              // +0x28, 4 bytes
    float ExplosionEffectRecord;              // +0x2C, 4 bytes
    float fFadeOutTime;                       // +0x30, 4 bytes
    float fForce;                             // +0x34, 4 bytes
    TESSound* m_pFirstSound;                  // +0x38, 4 bytes
    TESSound* m_pSecondSound;                 // +0x3C, 4 bytes
    TESObjectWEAP* m_pProjectileWeapon;       // +0x40, 4 bytes
    float ProjectileWeaponDataWithTwoSounds;  // +0x44, 4 bytes
    float ProjectileWeaponDataWithOneSound;   // +0x48, 4 bytes
    float ProjectileWeaponData;               // +0x4C, 4 bytes
    float m_fFourthProjectileValue;           // +0x50, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(ProjectileProperties) == 84);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, iFlags) == 0);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, afGravity) == 4);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, fSpeed) == 8);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, fImpulseRadiusSquared) == 12);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, apTargetLight) == 16);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, m_pSecondLight) == 20);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, ExplosionLightingData) == 24);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, LightExplosionSoundData) == 28);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, AlphaFloatParameters) == 32);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, ExplosionFadeData) == 36);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, m_pExplosionSound) == 40);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, ExplosionEffectRecord) == 44);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, fFadeOutTime) == 48);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, fForce) == 52);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, m_pFirstSound) == 56);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, m_pSecondSound) == 60);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, m_pProjectileWeapon) == 64);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, ProjectileWeaponDataWithTwoSounds) == 68);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, ProjectileWeaponDataWithOneSound) == 72);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, ProjectileWeaponData) == 76);
FNV_STATIC_ASSERT(offsetof(ProjectileProperties, m_fFourthProjectileValue) == 80);
class BGSProjectile : public TESBoundObject,
                      public TESFullName,
                      public TESModel,
                      public BGSPreloadable,
                      public BGSDestructibleObjectForm
{
  public:
    BGSProjectile();
    virtual ~BGSProjectile();
    ProjectileProperties Data;
    TESModel m_kProjectileModel;
    SOUND_LEVEL m_eSoundLevel;
    bool GetFlag(unsigned int flag) const;
    bool GetHasExplosionAltTrigger() const;
};
FNV_STATIC_ASSERT(sizeof(BGSProjectile) == 0xd0);
FNV_STATIC_ASSERT(offsetof(BGSProjectile, Data) == 0x60);
FNV_STATIC_ASSERT(offsetof(BGSProjectile, m_kProjectileModel) == 0xb4);
FNV_STATIC_ASSERT(offsetof(BGSProjectile, m_eSoundLevel) == 0xcc);
#endif
