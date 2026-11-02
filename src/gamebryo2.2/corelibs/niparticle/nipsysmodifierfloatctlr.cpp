// gamebryo2.2/corelibs/niparticle/nipsysmodifierfloatctlr.cpp: NiPSysModifierFloatCtlr, ThisCtlr (7 functions)

#include "nipsysmodifierfloatctlr_decls.h"
// @fnv 0x00c32e10
void NiPSysModifierFloatCtlr::LinkObject(NiStream& stream)
{
    NiPSysModifierCtlr::LinkObject(stream);
    if (stream.version < 0x0a010068)
    {
        NiFloatData* pFloatData = (NiFloatData*)stream.GetLoadedObject();
        NiObject* pNewInterpolator = new NiFloatInterpolator(pFloatData);
        NiObject* pOldInterpolator = interpolator;
        if (pOldInterpolator != pNewInterpolator)
        {
            if (pOldInterpolator && !InterlockedDecrement(&pOldInterpolator->refs))
                pOldInterpolator->DeleteThis();
            interpolator = pNewInterpolator;
            if (pNewInterpolator)
                InterlockedIncrement(&pNewInterpolator->refs);
        }
    }
}

extern const char* const g_012026d8_arg1;

// @fnv 0x00c32e00
const char* const* __cdecl FUN_00c32e00()
{
    return &g_012026d8_arg1;
}

struct FUN_00a3a710_shell
{
    void __thiscall CallVirtualMethodAtOffsetA8(void* arg, void* dummy);
};

// @fnv 0x00a3a710
void __thiscall FUN_00a3a710_shell::CallVirtualMethodAtOffsetA8(void* pObject, void* pUnused)
{
    typedef void(__thiscall * fp)(void*);
    fp f = *(fp*)((char*)(*(void**)pObject) + 0xa8);
    f(pObject);
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
char* __cdecl _FUN_00a7d330(const char*);
void __stdcall AppendModifierInfo(StrArr*);
// Appends the string returned by _FUN_00a7d330(g_012026d8_arg1) to pkStrings, growing the array if its count reaches capacity.
// @fnv 0x00c32f60
void __stdcall FUN_00c32f60(StrArr* pkStrings)
{
    AppendModifierInfo(pkStrings);
    char* pString = _FUN_00a7d330(g_012026d8_arg1);
    unsigned int n = *(unsigned short*)((char*)pkStrings + 0xa);
    if (n >= *(unsigned short*)((char*)pkStrings + 8))
    {
        pkStrings->SetSize(*(unsigned short*)((char*)pkStrings + 0xe) + n);
    }
    pkStrings->SetAt(n, pString);
}

struct DynCastHelper
{
    NiObject* __thiscall DynamicCast(const void*);
};
struct PoseInterpStub
{
    void __thiscall SetFloatValue(float);
};
extern int g_011f3738;
struct ThisCtlr
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void GetValue(float*);
    void __thiscall FUN_00c32e90(NiObject*, unsigned short);
};
// @fnv 0x00c32e90
void __thiscall ThisCtlr::FUN_00c32e90(NiObject* pkInterp, unsigned short usIndex)
{
    NiObject* pkFloatInterp;
    float fValue;
    if (pkInterp == 0)
        pkFloatInterp = 0;
    else
        pkFloatInterp = ((DynCastHelper*)pkInterp)->DynamicCast(&g_011f3738);
    GetValue(&fValue);
    ((PoseInterpStub*)pkFloatInterp)->SetFloatValue(fValue);
}

extern const float DAT_01096324;

struct Interp_c32ee0
{
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual void i5();
    virtual void i6();
    virtual void i7();
    virtual void i8();
    virtual void i9();
    virtual void i10();
    virtual void i11();
    virtual void i12();
    virtual void i13();
    virtual void i14();
    virtual void i15();
    virtual void i16();
    virtual void i17();
    virtual void i18();
    virtual void i19();
    virtual void i20();
    virtual void i21();
    virtual void i22();
    virtual void i23();
    virtual void i24();
    virtual void i25();
    virtual void i26();
    virtual void i27();
    virtual void i28();
    virtual void i29();
    virtual void i30();
    virtual void i31();
    virtual void i32();
    virtual void i33();
    virtual void i34();
    virtual void i35();
    virtual void i36();
    virtual void i37();
    virtual void i38();
    virtual bool Update39(float fTime, void* pkTarget, float& fVal);
    virtual void i40();
    virtual void i41();
    virtual void i42();
    virtual void i43();
    virtual void i44();
    virtual void i45();
    virtual void i46();
    virtual void i47();
    virtual void i48();
    virtual void i49();
    virtual void i50();
    virtual void i51();
    virtual void i52();
    virtual bool GetAlwaysUpdate53();
};

struct Ctlr_c32ee0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void SetTargetVal61(float fVal);
    int unk04;
    unsigned short m_uiObjectFlags;
    unsigned short unk0a;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    float m_fControllerTime;
    void* m_pkTarget;
    int unk30;
    Interp_c32ee0* m_spControllerInterpolator;
    bool AdvanceController(float fTime);
    void UpdateController(float& fTime);
};

// @fnv 0x00c32ee0
void Ctlr_c32ee0::UpdateController(float& fTime)
{
    bool b = (m_uiObjectFlags & 0x20) != 0;
    if ((unsigned char)b & 1)
    {
        m_fControllerTime = DAT_01096324;
    }
    else if (AdvanceController(fTime))
    {
        if (!m_spControllerInterpolator || !m_spControllerInterpolator->GetAlwaysUpdate53())
            return;
    }
    if (m_spControllerInterpolator)
    {
        float fVal;
        if (m_spControllerInterpolator->Update39(m_fControllerTime, m_pkTarget, fVal))
        {
            SetTargetVal61(fVal);
        }
    }
}

void __cdecl FUN_00a57780();
// @fnv 0x00a44cd0
void __cdecl FUN_00a44cd0()
{
    FUN_00a57780();
}
