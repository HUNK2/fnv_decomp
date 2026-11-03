// gamebryo2.2/corelibs/niparticle/nipsysmodifierctlr.cpp: NiPSysModifierCtlr, NiPSysModifierCtlrRuntime, ModifierControllerStandin (9 functions)

#include "nipsysmodifierctlr_decls.h"

// @fnv 0x00c31340
void NiPSysModifierCtlr::ProcessClone(CloningProcess& aCloneProcess)
{
    NiSingleInterpController::ProcessClone(aCloneProcess);
    NiPSysModifierCtlr* clone = 0;
    aCloneProcess.m_pCloneMap->GetAt((const char*)this, (ShaderBufferRecord*&)clone);
    NiPSysModifierCtlr* destination = clone;
    if (m_pkTarget && destination->m_pkTarget)
    {
        aCloneProcess.m_pCloneMap->GetAt((const char*)m_pkTargetModifier, (ShaderBufferRecord*&)clone);
        destination->m_pkTargetModifier = clone;
    }
}

struct NiObjectNET
{
    virtual ~NiObjectNET();
};
struct NiTimeController
{
    virtual void SetTarget(NiObjectNET*);
};
struct NiParticleSystem
{
    void FindModifier();
};
struct NiPSysModifierCtlr_shell : public NiTimeController, public NiParticleSystem
{
    void NiPSysModifierCtlr_SetTarget(NiObjectNET* pkTarget);
};
// Clears the pointer at offset 0x3c, calls NiTimeController::SetTarget, and if the pointer at 0x2c is set, invokes the particle system method.
// @fnv 0x00c31500
void NiPSysModifierCtlr_shell::NiPSysModifierCtlr_SetTarget(NiObjectNET* pkTarget)
{
    *(void**)((char*)this + 0x3c) = 0;
    NiTimeController::SetTarget(pkTarget);
    if (*(void**)((char*)this + 0x2c))
        ((NiParticleSystem*)((char*)this + 0))->FindModifier();
}

struct NiStream
{
    void SerializeString(char const*);
};

struct FUN_00a39010_shell
{
    void NiSingleInterpController_SaveBinary(NiStream&);
};

struct FUN_00a57130_shell
{
    void FUN_00a57130(NiStream&);
};

// @fnv 0x00a57130
void FUN_00a57130_shell::FUN_00a57130(NiStream& kStream)
{
    FUN_00a39010_shell* pBase = (FUN_00a39010_shell*)this;
    pBase->NiSingleInterpController_SaveBinary(kStream);
    kStream.SerializeString((char const*)((char*)this + 0x38));
}

struct S_00c313a0_Field
{
    virtual int v00() = 0;
    virtual int v01() = 0;
    virtual int v02() = 0;
    virtual int v03() = 0;
    virtual int v04() = 0;
    virtual int v05() = 0;
    virtual int v06() = 0;
    virtual int v07() = 0;
    virtual int v08() = 0;
    virtual int v09() = 0;
    virtual int v10() = 0;
    virtual int v11() = 0;
    virtual int v12() = 0;
    virtual int v13() = 0;
    virtual int v14() = 0;
    virtual int v15() = 0;
    virtual int v16() = 0;
    virtual int v17() = 0;
    virtual int v18() = 0;
    virtual int v19() = 0;
    virtual int v20() = 0;
    virtual int v21() = 0;
    virtual int v22() = 0;

    virtual bool FUN_00c313a0_Field_005c(S_00c313a0_Field*) = 0;
};

struct S_00c313a0
{
    virtual ~S_00c313a0()
    {}

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    S_00c313a0_Field* unk3c;

    unsigned char IsEquivalentTo(S_00c313a0* other);
};

struct S_00a39030_Callee
{
    bool IsCompatibleWith(S_00c313a0* other);
};

// Compares this object with other via IsCompatibleWith, matching unk3c presence and contents, and returns whether unk38 is equal.
// @fnv 0x00c313a0
unsigned char S_00c313a0::IsEquivalentTo(S_00c313a0* other)
{
    if (!reinterpret_cast<S_00a39030_Callee*>(this)->IsCompatibleWith(other))
        return 0;

    if (unk3c && !other->unk3c)
        return 0;

    if (!unk3c && other->unk3c)
        return 0;

    if (unk3c && other->unk3c)
    {
        if (!unk3c->FUN_00c313a0_Field_005c(other->unk3c))
            return 0;
    }

    return unk38 == other->unk38;
}

extern int DAT_010c08ac;
extern int DAT_0109b220;
extern int(__stdcall* DAT_00fdf1c4)(void* apMemory);
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct NiPSysModifierRef
{
    virtual void v00();
    virtual void Release();
    int m_iRefCount;
};

struct FUN_00c314a0_cls
{
    int m_vptr;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    NiPSysModifierRef* m_pModifier;
    char* m_kTargetModifierName;

    void FUN_00a6d290();
    FUN_00c314a0_cls* Destroy(unsigned char acFlags);
};

// Frees the name buffer and modifier reference, calls FUN_00a6d290, and optionally deallocates the object when acFlags bit 0 is set.
// @fnv 0x00c314a0
FUN_00c314a0_cls* FUN_00c314a0_cls::Destroy(unsigned char acFlags)
{
    int(__stdcall * pfnFree)(void*) = DAT_00fdf1c4;
    *(volatile int*)&m_vptr = (int)&DAT_010c08ac;
    char* pName = *(char* volatile*)&m_kTargetModifierName;
    if (pName != (char*)DAT_0109b220)
    {
        pfnFree(pName - 8);
    }
    NiPSysModifierRef* pModifier = m_pModifier;
    if (pModifier != 0)
    {
        if (pfnFree(&pModifier->m_iRefCount) == 0)
        {
            pModifier->Release();
        }
    }
    FUN_00a6d290();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x40);
    }
    return this;
}

namespace fnv_00c31530 {
struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};
extern NiRTTI DAT_012024e0;
extern void* DAT_0109b220;

struct NiParticleSystemRuntime
{
    virtual void DeleteThis();
    virtual void LoadBinary();
    virtual const NiRTTI* GetRTTI();
    void* FUN_00c1b0f0(const void* pkName);
};

struct NiPSysModifierCtlrRuntime : NiPSysModifierCtlr
{
    bool IsTargetParticleSystem(NiParticleSystemRuntime* pkTarget);
};

// @fnv 0x00c31530
bool NiPSysModifierCtlrRuntime::IsTargetParticleSystem(NiParticleSystemRuntime* pkTarget)
{
    if (pkTarget != 0)
    {
        const NiRTTI* pkRTTI = pkTarget->GetRTTI();
        while (pkRTTI != 0)
        {
            if (pkRTTI == &DAT_012024e0)
            {
                if (m_kTargetModifierName != DAT_0109b220 && m_pkTarget != 0)
                {
                    if (pkTarget->FUN_00c1b0f0(&m_kTargetModifierName))
                    {
                        return true;
                    }
                }
                return false;
            }
            pkRTTI = pkRTTI->m_pBaseRTTI;
        }
    }
    return false;
}
}  // namespace fnv_00c31530

struct NiStream;
struct ControllerStandin
{
    void __thiscall FUN_00a89af0(NiStream& stream);
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    void* target_2c;
};
struct ModifierControllerStandin : ControllerStandin
{
    void __thiscall FUN_00c31400();
    void __thiscall FUN_00c31590(NiStream& stream);
};
// @fnv 0x00c31590
void ModifierControllerStandin::FUN_00c31590(NiStream& stream)
{
    ControllerStandin::FUN_00a89af0(stream);
    if (target_2c)
        FUN_00c31400();
}

struct FUN_00c315b0_arr
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_iCap;
    unsigned short m_iArrayLength;
    unsigned short unk0C;
    unsigned short m_iGrowBy;
    void FUN_0096ad30(unsigned int newSize);
    void FUN_0096ae90(unsigned int index, void*& item);
};

struct FUN_00c315b0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    void* m_pModifierName;
    void AppendModifierInfo(void* arg);
};

extern void __stdcall NiSingleInterpController_GetViewerStrings(FUN_00c315b0_arr* arr);
extern void* __cdecl FUN_00a7d330(void* p);
extern void* __cdecl FUN_00a7d5e0(const char* fmt, void* p);
extern void* DAT_012027c8;

// @fnv 0x00c315b0
void FUN_00c315b0_cls::AppendModifierInfo(void* arg)
{
    FUN_00c315b0_arr* arr = (FUN_00c315b0_arr*)arg;
    NiSingleInterpController_GetViewerStrings(arr);
    void* v1 = FUN_00a7d330(DAT_012027c8);
    unsigned int count = arr->m_iArrayLength;
    if (count >= arr->m_iCap)
    {
        arg = v1;
        arr->FUN_0096ad30(count + arr->m_iGrowBy);
    }
    else
    {
        arg = v1;
    }
    arr->FUN_0096ae90(count, arg);
    void* pModifierName = m_pModifierName;
    void* pNameString = FUN_00a7d5e0("Modifier Name", pModifierName);
    count = arr->m_iArrayLength;
    if (count >= arr->m_iCap)
    {
        arg = pNameString;
        arr->FUN_0096ad30(count + arr->m_iGrowBy);
    }
    else
    {
        arg = pNameString;
    }
    arr->FUN_0096ae90(count, arg);
}

struct BaseFake
{
    bool RegisterInterpolatorStreamables(NiStream&);
};
struct FUN_00a57780_shell : BaseFake
{
    bool FUN_00a57780(NiStream&);
};
// @fnv 0x00a57780
bool FUN_00a57780_shell::FUN_00a57780(NiStream& stream)
{
    return RegisterInterpolatorStreamables(stream);
}
