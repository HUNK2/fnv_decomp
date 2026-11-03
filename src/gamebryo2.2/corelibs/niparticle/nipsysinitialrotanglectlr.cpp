
// src/gamebryo2.2/corelibs/niparticle/nipsysinitialrotanglectlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysinitialrotanglectlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiRTTI;
extern NiRTTI g_012026f0;

// @fnv 0x00c2a1a0
const NiRTTI* __cdecl NiPSysInitialRotAngleCtlr_GetRTTI()
{
    return &g_012026f0;
}

struct NiRTTI
{
    const char* m_pcName;
    NiRTTI* m_pBaseRTTI;
};
extern NiRTTI _g_01202528;
struct NiObject
{
    virtual ~NiObject();
    virtual void _U4();
    virtual const NiRTTI* GetRTTI() const;
    bool IsKindOfType(const NiRTTI* pkRTTI) const
    {
        const NiRTTI* pkMy = GetRTTI();
        while (pkMy)
        {
            if (pkMy == pkRTTI)
                return true;
            pkMy = pkMy->m_pBaseRTTI;
        }
        return false;
    }
};
struct NiPSysModifier : NiObject
{
};
struct B00c1bff0
{
    void* FUN_00c1b0f0(void*);
};
struct NiObjectNET : B00c1bff0
{
};
struct BaseStandIn
{
    bool IsTargetParticleSystem(NiObjectNET*);
};
struct NiPSysInitialRotAngleCtlr : BaseStandIn
{
    bool IsModifierOfType(NiObjectNET*);
};
// @fnv 0x00c2a210
bool NiPSysInitialRotAngleCtlr::IsModifierOfType(NiObjectNET* pkTarget)
{
    if (!BaseStandIn::IsTargetParticleSystem(pkTarget))
        return false;
    NiPSysModifier* pkModifier = (NiPSysModifier*)pkTarget->FUN_00c1b0f0((void*)((char*)this + 0x38));
    if (!pkModifier)
        return false;
    return pkModifier->IsKindOfType(&_g_01202528);
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
char* __cdecl FUN_00a7d330(const char*);
void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr*);
// @fnv 0x00c2a260
void __stdcall NiPSysInitialRotAngleCtlr_GetViewerStrings(StrArr* pkStrings)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(pkStrings);
    char* pStr = FUN_00a7d330(g_012026f0.m_pcName);
    unsigned int iCount = *(unsigned short*)((char*)pkStrings + 10);
    unsigned int iSize = *(unsigned short*)((char*)pkStrings + 8);
    if (iCount >= iSize)
        pkStrings->SetSize(iCount + *(unsigned short*)((char*)pkStrings + 14));
    pkStrings->SetAt(iCount, pStr);
}

extern char DAT_010befbc;
void* __cdecl FUN_00aa13e0(unsigned int);

struct SpawnedObject
{
    void FUN_00c32d80();
};

struct SpawnedCtlr
{
    void FUN_00c32de0(SpawnedObject* pkObj, void* pArg);
    SpawnedObject* CreateSpawnedObject(void* pArg);
};

// Allocates a 0x40-byte SpawnedObject, initialises it, passes it to FUN_00c32de0 with pArg, and returns it (or null on allocation failure).
// @fnv 0x00c2a1c0
SpawnedObject* SpawnedCtlr::CreateSpawnedObject(void* pArg)
{
    SpawnedObject* pkObj = (SpawnedObject*)FUN_00aa13e0(0x40);
    if (pkObj != 0)
    {
        pkObj->FUN_00c32d80();
        *(char**)pkObj = &DAT_010befbc;
    }
    else
    {
        pkObj = 0;
    }
    FUN_00c32de0(pkObj, pArg);
    return pkObj;
}
