
// src/gamebryo2.2/corelibs/nianimation/nifloatinterpcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nifloatinterpcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};

extern "C" void __stdcall NiSingleInterpController_GetViewerStrings(StrArr*);
extern "C" char* __cdecl FUN_00a7d330(const char*);
extern "C" const char* const g_011f3ec8_arg1;

template <class T> class NiTMallocInterface
{
};

template <class T, class M> class NiTPrimitiveArray : public StrArr
{
  public:
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};

typedef NiTPrimitiveArray<char*, NiTMallocInterface<char*> > NiTPrimitiveArray_char;

// @fnv 0x00a576c0
void __stdcall NiFloatInterpController_GetViewerStrings(NiTPrimitiveArray_char* pkStrings)
{
    NiSingleInterpController_GetViewerStrings(pkStrings);
    char* pStr = FUN_00a7d330(g_011f3ec8_arg1);
    unsigned int idx = *(reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pkStrings) + 0x0a));
    unsigned int cnt = *(reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pkStrings) + 0x08));
    if (idx >= cnt)
    {
        unsigned int extra = *(reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pkStrings) + 0x0e));
        pkStrings->SetSize(idx + extra);
    }
    pkStrings->SetAt(idx, pStr);
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct FUN_00a3c390 : BSFadeNode
{
    char _pad[0x18];
    FUN_00a3c390(float) throw();
};
struct NiFloatInterpController
{
    FUN_00a3c390* CreateFadeNodeFromValue(unsigned short usIndex);
};
// Reads a float via the controller's vtable slot 59 and returns a newly allocated FUN_00a3c390 constructed from it.
// @fnv 0x00a575e0
FUN_00a3c390* NiFloatInterpController::CreateFadeNodeFromValue(unsigned short usIndex)
{
    float fValue;
    ((void(__thiscall*)(NiFloatInterpController*, float*))(*(void***)this)[59])(this, &fValue);
    return new FUN_00a3c390(fValue);
}

namespace fnv_00a57670 {
struct NiRTTI;
struct NiObject
{
    NiObject* DynamicCast(const NiRTTI*);
};
struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_011f3738;
struct NiInterpolator : NiObject
{
};
struct PoseInterpStub
{
    void SetFloatValue(float);
};
struct NiFloatInterpolator : PoseInterpStub
{
};
struct NiSingleInterpController : NiObject
{
    virtual void D00() = 0;
    virtual void D01() = 0;
    virtual void D02() = 0;
    virtual void D03() = 0;
    virtual void D04() = 0;
    virtual void D05() = 0;
    virtual void D06() = 0;
    virtual void D07() = 0;
    virtual void D08() = 0;
    virtual void D09() = 0;
    virtual void D10() = 0;
    virtual void D11() = 0;
    virtual void D12() = 0;
    virtual void D13() = 0;
    virtual void D14() = 0;
    virtual void D15() = 0;
    virtual void D16() = 0;
    virtual void D17() = 0;
    virtual void D18() = 0;
    virtual void D19() = 0;
    virtual void D20() = 0;
    virtual void D21() = 0;
    virtual void D22() = 0;
    virtual void D23() = 0;
    virtual void D24() = 0;
    virtual void D25() = 0;
    virtual void D26() = 0;
    virtual void D27() = 0;
    virtual void D28() = 0;
    virtual void D29() = 0;
    virtual void D30() = 0;
    virtual void D31() = 0;
    virtual void D32() = 0;
    virtual void D33() = 0;
    virtual void D34() = 0;
    virtual void D35() = 0;
    virtual void D36() = 0;
    virtual void D37() = 0;
    virtual void D38() = 0;
    virtual void D39() = 0;
    virtual void D40() = 0;
    virtual void D41() = 0;
    virtual void D42() = 0;
    virtual void D43() = 0;
    virtual void D44() = 0;
    virtual void D45() = 0;
    virtual void D46() = 0;
    virtual void D47() = 0;
    virtual void D48() = 0;
    virtual void D49() = 0;
    virtual void D50() = 0;
    virtual void D51() = 0;
    virtual void D52() = 0;
    virtual void D53() = 0;
    virtual void D54() = 0;
    virtual void D55() = 0;
    virtual void D56() = 0;
    virtual void D57() = 0;
    virtual void D58() = 0;
    virtual void GetValue(float*) = 0;
};
struct NiFloatInterpController : NiSingleInterpController
{
    void SetInterpolatorValue(NiInterpolator*, unsigned short);
};
// Casts pkInterp to a NiFloatInterpolator, reads the controller value via GetValue and passes it to the interpolator's SetFloatValue.
// @fnv 0x00a57670
void NiFloatInterpController::SetInterpolatorValue(NiInterpolator* pkInterp, unsigned short usIndex)
{
    NiFloatInterpolator* pkFloatInterp;
    float fValue;
    if (!pkInterp)
        pkFloatInterp = 0;
    else
        pkFloatInterp =
            reinterpret_cast<NiFloatInterpolator*>(pkInterp->DynamicCast(reinterpret_cast<const NiRTTI*>(&g_011f3738)));
    GetValue(&fValue);
    pkFloatInterp->SetFloatValue(fValue);
}
}  // namespace fnv_00a57670

struct NiStream;
struct NiSingleInterpController
{
    void LinkObject(NiStream&);
};
struct FUN_00a57630 : NiSingleInterpController
{
    void LinkObject(NiStream&);
};
// @fnv 0x00a57630
void FUN_00a57630::LinkObject(NiStream& kStream)
{
    NiSingleInterpController::LinkObject(kStream);
}

namespace fnv_00a57c70 {
struct NiStream
{
};
struct NiSingleInterpController
{
    void LoadBinary(NiStream&);
};
struct FUN_00a57c70 : NiSingleInterpController
{
    void LoadBinary(NiStream&);
};
// @fnv 0x00a57c70
void FUN_00a57c70::LoadBinary(NiStream& kStream)
{
    NiSingleInterpController::LoadBinary(kStream);
}
}  // namespace fnv_00a57c70
