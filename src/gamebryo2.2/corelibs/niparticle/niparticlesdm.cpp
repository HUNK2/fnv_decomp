
// src/gamebryo2.2/corelibs/niparticle/niparticlesdm.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/niparticlesdm.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl FUN_00a63520(const char* pName);
void __cdecl DestroyManager();
extern bool g_bInitialized_012024d0;

static const char s_sz00[] = "NiMeshParticleSystem";
static const char s_sz01[] = "NiMeshPSysData";
static const char s_sz02[] = "NiParticleSystem";
static const char s_sz03[] = "NiPSysAirFieldAirFrictionCtlr";
static const char s_sz04[] = "NiPSysAirFieldInheritVelocityCtlr";
static const char s_sz05[] = "NiPSysAirFieldModifier";
static const char s_sz06[] = "NiPSysAirFieldSpreadCtlr";
static const char s_sz07[] = "NiPSysAgeDeathModifier";
static const char s_sz08[] = "NiPSysBombModifier";
static const char s_sz09[] = "NiPSysBoundUpdateModifier";
static const char s_sz10[] = "NiPSysBoxEmitter";
static const char s_sz11[] = "NiPSysColliderManager";
static const char s_sz12[] = "NiPSysColorModifier";
static const char s_sz13[] = "NiPSysCylinderEmitter";
static const char s_sz14[] = "NiPSysData";
static const char s_sz15[] = "NiPSysDragFieldModifier";
static const char s_sz16[] = "NiPSysDragModifier";
static const char s_sz17[] = "NiPSysEmitterCtlr";
static const char s_sz18[] = "NiPSysEmitterCtlrData";
static const char s_sz19[] = "NiPSysEmitterDeclinationCtlr";
static const char s_sz20[] = "NiPSysEmitterDeclinationVarCtlr";
static const char s_sz21[] = "NiPSysEmitterInitialRadiusCtlr";
static const char s_sz22[] = "NiPSysEmitterLifeSpanCtlr";
static const char s_sz23[] = "NiPSysEmitterPlanarAngleCtlr";
static const char s_sz24[] = "NiPSysEmitterPlanarAngleVarCtlr";
static const char s_sz25[] = "NiPSysEmitterSpeedCtlr";
static const char s_sz26[] = "NiPSysFieldAttenuationCtlr";
static const char s_sz27[] = "NiPSysFieldMagnitudeCtlr";
static const char s_sz28[] = "NiPSysFieldMaxDistanceCtlr";
static const char s_sz29[] = "NiPSysGravityModifier";
static const char s_sz30[] = "NiPSysGravityFieldModifier";
static const char s_sz31[] = "NiPSysGravityStrengthCtlr";
static const char s_sz32[] = "NiPSysGrowFadeModifier";
static const char s_sz33[] = "NiPSysInitialRotAngleCtlr";
static const char s_sz34[] = "NiPSysInitialRotAngleVarCtlr";
static const char s_sz35[] = "NiPSysInitialRotSpeedCtlr";
static const char s_sz36[] = "NiPSysInitialRotSpeedVarCtlr";
static const char s_sz37[] = "NiPSysMeshEmitter";
static const char s_sz38[] = "NiPSysMeshUpdateModifier";
static const char s_sz39[] = "NiPSysModifierActiveCtlr";
static const char s_sz40[] = "NiPSysPlanarCollider";
static const char s_sz41[] = "NiPSysPositionModifier";
static const char s_sz42[] = "NiPSysRadialFieldModifier";
static const char s_sz43[] = "NiPSysResetOnLoopCtlr";
static const char s_sz44[] = "NiPSysRotationModifier";
static const char s_sz45[] = "NiPSysSpawnModifier";
static const char s_sz46[] = "NiPSysSphereEmitter";
static const char s_sz47[] = "NiPSysSphericalCollider";
static const char s_sz48[] = "NiPSysTurbulenceFieldModifier";
static const char s_sz49[] = "NiPSysUpdateCtlr";
static const char s_sz50[] = "NiPSysVortexFieldModifier";
extern const char g_szShutdownEnd[] = "";

// @fnv 0x00c1a7d0
void __cdecl FUN_00c1a7d0()
{
    if (!g_bInitialized_012024d0)
        return;
    g_bInitialized_012024d0 = false;
    FUN_00a63520(s_sz00);
    FUN_00a63520(s_sz01);
    FUN_00a63520(s_sz02);
    FUN_00a63520(s_sz03);
    FUN_00a63520(s_sz04);
    FUN_00a63520(s_sz05);
    FUN_00a63520(s_sz06);
    FUN_00a63520(s_sz07);
    FUN_00a63520(s_sz08);
    FUN_00a63520(s_sz09);
    FUN_00a63520(s_sz10);
    FUN_00a63520(s_sz11);
    FUN_00a63520(s_sz12);
    FUN_00a63520(s_sz13);
    FUN_00a63520(s_sz14);
    FUN_00a63520(s_sz15);
    FUN_00a63520(s_sz16);
    FUN_00a63520(s_sz17);
    FUN_00a63520(s_sz18);
    FUN_00a63520(s_sz19);
    FUN_00a63520(s_sz20);
    FUN_00a63520(s_sz21);
    FUN_00a63520(s_sz22);
    FUN_00a63520(s_sz23);
    FUN_00a63520(s_sz24);
    FUN_00a63520(s_sz25);
    FUN_00a63520(s_sz26);
    FUN_00a63520(s_sz27);
    FUN_00a63520(s_sz28);
    FUN_00a63520(s_sz29);
    FUN_00a63520(s_sz30);
    FUN_00a63520(s_sz31);
    FUN_00a63520(s_sz32);
    FUN_00a63520(s_sz33);
    FUN_00a63520(s_sz34);
    FUN_00a63520(s_sz35);
    FUN_00a63520(s_sz36);
    FUN_00a63520(s_sz37);
    FUN_00a63520(s_sz38);
    FUN_00a63520(s_sz39);
    FUN_00a63520(s_sz40);
    FUN_00a63520(s_sz41);
    FUN_00a63520(s_sz42);
    FUN_00a63520(s_sz43);
    FUN_00a63520(s_sz44);
    FUN_00a63520(s_sz45);
    FUN_00a63520(s_sz46);
    FUN_00a63520(s_sz47);
    FUN_00a63520(s_sz48);
    FUN_00a63520(s_sz49);
    FUN_00a63520(s_sz50);
    DestroyManager();
}

#include <windows.h>
typedef void* (*S_00c1aa00_CreateFunc)();
void FUN_00a64900(const char* pcName, S_00c1aa00_CreateFunc pfnCreate);

void* FUN_00c21e90();
void* CreateNiMeshPSysData();
void* NiParticleSystem_CreateObject();
void* NiPSysAirFieldAirFrictionCtlr_CreateObject();
void* NiPSysAirFieldInheritVelocityCtlr_CreateObject();
void* CreateAirTmp();
void* NiPSysAirFieldSpreadCtlr_CreateObject();
void* NiPSysAgeDeathModifier_CreateObject();
void* NiPSysBombModifier_CreateObject();
void* CreateNiPSysModC2D();
void* NiPSysBoxEmitter_CreateObject();
void* NiPSysColliderManager_CreateObject();
void* CreateColorModifier();
void* NiPSysCylinderEmitter_CreateObject();
void* NiPSysData_CreateObject();
void* NiPSysDragFieldModifier_CreateObject();
void* NiPSysDragModifier_CreateObject();
void* CreateNiPSysEmitterCtlrC1C5();
void* NiPSysEmitterCtlrData_CreateObject();
void* NiPSysEmitterDeclinationCtlr_CreateObject();
void* NiPSysEmitterDeclinationVarCtlr_CreateObject();
void* NiPSysEmitterInitialRadiusCtlr_CreateObject();
void* NiPSysEmitterLifeSpanCtlr_CreateObject();
void* CreatePSysFactoryObjectB52();
void* CreatePSysFactoryObject();
void* CreateParticleEmitterAllocation();
void* NiPSysFieldAttenuationCtlr_CreateObject();
void* NiPSysFieldMagnitudeCtlr_CreateObject();
void* NiPSysFieldMaxDistanceCtlr_CreateObject();
void* NiPSysGravityModifier_CreateObject();
void* CreateGravityFieldModifier();
void* NiPSysGravityStrengthCtlr_CreateObject();
void* NiPSysGrowFadeModifier_CreateObject();
void* CreateParticleObjectFactory();
void* NiPSysInitialRotAngleVarCtlr_CreateObject();
void* CreateParticleFactoryObject();
void* CreateC29E50Object();
void* CreateNiPSysMeshEmitterObject();
void* CreateModifier();
void* NiPSysModifierActiveCtlr_CreateObject();
void* FUN_00c29af0();
void* NiPSysPositionModifier_CreateObject();
void* NiPSysRadialFieldModifier_CreateObject();
void* NiPSysResetOnLoopCtlr_CreateObject();
void* NiPSysRotationModifier_CreateObject();
void* NiPSysSpawnModifier_CreateObject();
void* NiPSysSphereEmitter_CreateObject();
void* CreateCollider();
void* NiPSysTurbulenceFieldModifier_CreateObject();
void* NiPSysUpdateCtlr_CreateObject();
void* NiPSysVortexFieldModifier_CreateObject();
void* BSStripParticleSystem_CreateObject();
void* CreateFUN_00c24c90();

bool DAT_012024d0;
DWORD DAT_012024dc;

// Registers particle system class factories with FUN_00a64900 and stores the calling thread ID in DAT_012024dc.
// @fnv 0x00c1aa00
void RegisterParticleSystems()
{
    if (DAT_012024d0)
        return;
    DAT_012024d0 = true;

    FUN_00a64900("NiMeshParticleSystem", FUN_00c21e90);
    FUN_00a64900("NiMeshPSysData", CreateNiMeshPSysData);
    FUN_00a64900("NiParticleSystem", NiParticleSystem_CreateObject);
    FUN_00a64900("NiPSysAirFieldAirFrictionCtlr", NiPSysAirFieldAirFrictionCtlr_CreateObject);
    FUN_00a64900("NiPSysAirFieldInheritVelocityCtlr", NiPSysAirFieldInheritVelocityCtlr_CreateObject);
    FUN_00a64900("NiPSysAirFieldModifier", CreateAirTmp);
    FUN_00a64900("NiPSysAirFieldSpreadCtlr", NiPSysAirFieldSpreadCtlr_CreateObject);
    FUN_00a64900("NiPSysAgeDeathModifier", NiPSysAgeDeathModifier_CreateObject);
    FUN_00a64900("NiPSysBombModifier", NiPSysBombModifier_CreateObject);
    FUN_00a64900("NiPSysBoundUpdateModifier", CreateNiPSysModC2D);
    FUN_00a64900("NiPSysBoxEmitter", NiPSysBoxEmitter_CreateObject);
    FUN_00a64900("NiPSysColliderManager", NiPSysColliderManager_CreateObject);
    FUN_00a64900("NiPSysColorModifier", CreateColorModifier);
    FUN_00a64900("NiPSysCylinderEmitter", NiPSysCylinderEmitter_CreateObject);
    FUN_00a64900("NiPSysData", NiPSysData_CreateObject);
    FUN_00a64900("NiPSysDragFieldModifier", NiPSysDragFieldModifier_CreateObject);
    FUN_00a64900("NiPSysDragModifier", NiPSysDragModifier_CreateObject);
    FUN_00a64900("NiPSysEmitterCtlr", CreateNiPSysEmitterCtlrC1C5);
    FUN_00a64900("NiPSysEmitterCtlrData", NiPSysEmitterCtlrData_CreateObject);
    FUN_00a64900("NiPSysEmitterDeclinationCtlr", NiPSysEmitterDeclinationCtlr_CreateObject);
    FUN_00a64900("NiPSysEmitterDeclinationVarCtlr", NiPSysEmitterDeclinationVarCtlr_CreateObject);
    FUN_00a64900("NiPSysEmitterInitialRadiusCtlr", NiPSysEmitterInitialRadiusCtlr_CreateObject);
    FUN_00a64900("NiPSysEmitterLifeSpanCtlr", NiPSysEmitterLifeSpanCtlr_CreateObject);
    FUN_00a64900("NiPSysEmitterPlanarAngleCtlr", CreatePSysFactoryObjectB52);
    FUN_00a64900("NiPSysEmitterPlanarAngleVarCtlr", CreatePSysFactoryObject);
    FUN_00a64900("NiPSysEmitterSpeedCtlr", CreateParticleEmitterAllocation);
    FUN_00a64900("NiPSysFieldAttenuationCtlr", NiPSysFieldAttenuationCtlr_CreateObject);
    FUN_00a64900("NiPSysFieldMagnitudeCtlr", NiPSysFieldMagnitudeCtlr_CreateObject);
    FUN_00a64900("NiPSysFieldMaxDistanceCtlr", NiPSysFieldMaxDistanceCtlr_CreateObject);
    FUN_00a64900("NiPSysGravityModifier", NiPSysGravityModifier_CreateObject);
    FUN_00a64900("NiPSysGravityFieldModifier", CreateGravityFieldModifier);
    FUN_00a64900("NiPSysGravityStrengthCtlr", NiPSysGravityStrengthCtlr_CreateObject);
    FUN_00a64900("NiPSysGrowFadeModifier", NiPSysGrowFadeModifier_CreateObject);
    FUN_00a64900("NiPSysInitialRotAngleCtlr", CreateParticleObjectFactory);
    FUN_00a64900("NiPSysInitialRotAngleVarCtlr", NiPSysInitialRotAngleVarCtlr_CreateObject);
    FUN_00a64900("NiPSysInitialRotSpeedCtlr", CreateParticleFactoryObject);
    FUN_00a64900("NiPSysInitialRotSpeedVarCtlr", CreateC29E50Object);
    FUN_00a64900("NiPSysMeshEmitter", CreateNiPSysMeshEmitterObject);
    FUN_00a64900("NiPSysMeshUpdateModifier", CreateModifier);
    FUN_00a64900("NiPSysModifierActiveCtlr", NiPSysModifierActiveCtlr_CreateObject);
    FUN_00a64900("NiPSysPlanarCollider", FUN_00c29af0);
    FUN_00a64900("NiPSysPositionModifier", NiPSysPositionModifier_CreateObject);
    FUN_00a64900("NiPSysRadialFieldModifier", NiPSysRadialFieldModifier_CreateObject);
    FUN_00a64900("NiPSysResetOnLoopCtlr", NiPSysResetOnLoopCtlr_CreateObject);
    FUN_00a64900("NiPSysRotationModifier", NiPSysRotationModifier_CreateObject);
    FUN_00a64900("NiPSysSpawnModifier", NiPSysSpawnModifier_CreateObject);
    FUN_00a64900("NiPSysSphereEmitter", NiPSysSphereEmitter_CreateObject);
    FUN_00a64900("NiPSysSphericalCollider", CreateCollider);
    FUN_00a64900("NiPSysTurbulenceFieldModifier", NiPSysTurbulenceFieldModifier_CreateObject);
    FUN_00a64900("NiPSysUpdateCtlr", NiPSysUpdateCtlr_CreateObject);
    FUN_00a64900("NiPSysVortexFieldModifier", NiPSysVortexFieldModifier_CreateObject);
    FUN_00a64900("BSStripParticleSystem", BSStripParticleSystem_CreateObject);
    FUN_00a64900("BSStripPSysData", CreateFUN_00c24c90);

    DAT_012024dc = GetCurrentThreadId();
}
