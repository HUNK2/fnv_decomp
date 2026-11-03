// gamebryo2.2/corelibs/nianimation/nialphacontroller.cpp: NiAlphaController, Holder, FloatCtlr (9 functions)

#include "nialphacontroller_decls.h"

// @fnv 0x00a57620
void NiAlphaController::CopyMemberData(NiAlphaController* clone, CloningProcess& process)
{
    reinterpret_cast<NiTransformController*>(this)->CopyMemberData(reinterpret_cast<NiTransformController*>(clone),
                                                                   process);
}

struct FUN_00a569f0_shell
{
    void __thiscall FUN_00a569f0(float& fValue);
};

// @fnv 0x00a569f0
void __thiscall FUN_00a569f0_shell::FUN_00a569f0(float& fValue)
{
    float* p = *reinterpret_cast<float**>(reinterpret_cast<char*>(this) + 0x2c);
    fValue = p[0x3c / 4];
}

extern int g_011f4084;

// @fnv 0x00a56a80
int* __cdecl NiAlphaController_GetRTTI()
{
    return &g_011f4084;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct NiFloatInterpController
{
    NiFloatInterpController();
};
extern int DAT_0109a76c;
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// Allocates a 0x38-byte NiFloatInterpController, constructs it in place, sets its vtable to DAT_0109a76c, and returns it (or null on allocation failure).
// @fnv 0x00a56b30
NiFloatInterpController* __cdecl CreateFloatInterpController()
{
    NiFloatInterpController* p = (NiFloatInterpController*)BSFadeNode::operator new(0x38);
    if (p)
    {
        new (p) NiFloatInterpController;
        *(int**)p = &DAT_0109a76c;
        return p;
    }
    return 0;
}

struct FUN_00bc3050_RTTI
{
    const char* m_pcName;
    FUN_00bc3050_RTTI* m_pParentNode;
};
extern FUN_00bc3050_RTTI g_011f4a5c;
struct FUN_00bc3050_Obj
{
    virtual void f0();
    virtual void f1();
    virtual FUN_00bc3050_RTTI* GetRTTI();
};
// Checks whether pkTarget's RTTI chain contains g_011f4a5c, returning false for a null target or null RTTI.
// @fnv 0x00bc3050
bool __stdcall FUN_00bc3050(FUN_00bc3050_Obj* pkTarget)
{
    if (!pkTarget)
        return false;
    FUN_00bc3050_RTTI* pkRTTI = pkTarget->GetRTTI();
    if (!pkRTTI)
        return false;
    do
    {
        if (pkRTTI == &g_011f4a5c)
            return true;
        pkRTTI = pkRTTI->m_pParentNode;
    } while (pkRTTI);
    return false;
}

template <class T> struct NiTMallocInterface
{
};
template <class T, class Alloc> struct NiTPrimitiveArray
{
    char _pad[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    char _pad2[2];
    unsigned short m_usGrowBy;
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, T&);
};
void __stdcall NiFloatInterpController_GetViewerStrings(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >*);
char* __cdecl _FUN_00a7d330(const char*);
// Grows pkStrings if full, then appends the string returned by _FUN_00a7d330(g_011f4084) at the current size index.
// @fnv 0x00a56b60
void __stdcall NiAlphaController_GetViewerStrings(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >* pkStrings)
{
    NiFloatInterpController_GetViewerStrings(pkStrings);
    char* pszStr = _FUN_00a7d330((const char*)g_011f4084);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pszStr);
}

extern int DAT_0109a76c;
struct NiNew
{
    int* vt;
    int f[13];
    void __thiscall Init();
    static void* __cdecl operator new(unsigned int) throw();
};
struct Holder
{
    void __thiscall Copy(NiNew* n, CloningProcess* p);
    NiNew* __thiscall CreateAndCopy(CloningProcess* p);
};
// Allocates and initialises a NiNew, then copies p into it via Copy and returns the new object, or null if allocation fails.
// @fnv 0x00a56ae0
NiNew* Holder::CreateAndCopy(CloningProcess* apSource)
{
    NiNew* n = (NiNew*)NiNew::operator new(0x38);
    NiNew* r;
    if (n)
    {
        n->Init();
        n->vt = &DAT_0109a76c;
        r = n;
    }
    else
    {
        r = 0;
    }
    Copy(r, apSource);
    return r;
}

static const float kInvalidTime = -3.402823466e+38f;
struct FloatTarget
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    float m_fValue;
    int unk40;
    unsigned int m_uiRevID;
    void SetValue(float f)
    {
        m_fValue = f;
        m_uiRevID++;
    }
};
struct FloatInterpolator
{
    virtual void s00(), s01(), s02(), s03(), s04(), s05(), s06(), s07();
    virtual void s08(), s09(), s10(), s11(), s12(), s13(), s14(), s15();
    virtual void s16(), s17(), s18(), s19(), s20(), s21(), s22(), s23();
    virtual void s24(), s25(), s26(), s27(), s28(), s29(), s30(), s31();
    virtual void s32(), s33(), s34(), s35(), s36(), s37(), s38();
    virtual bool Update(float fTime, FloatTarget* pkTarget, float& fValue);
    virtual void s40(), s41(), s42(), s43(), s44(), s45(), s46(), s47();
    virtual void s48(), s49(), s50(), s51(), s52();
    virtual bool AlwaysUpdate();
};
struct UpdateData
{
    float m_fTime;
};
struct FloatCtlr
{
    int unk00, unk04;
    unsigned short m_uiObjectFlags;
    unsigned short unk0a;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    float m_fControllerTime;
    FloatTarget* m_pkTarget;
    int unk30;
    FloatInterpolator* m_spControllerInterpolator;
    bool GetManagerControlled() const
    {
        return ((m_uiObjectFlags >> 5) & 1) ? true : false;
    }
    bool FUN_00a36250(float fTime);
    void NiAlphaController_Update(UpdateData& kData);
};
// @fnv 0x00a56a00
void FloatCtlr::NiAlphaController_Update(UpdateData& kData)
{
    if (GetManagerControlled())
    {
        m_fControllerTime = kInvalidTime;
    }
    else if (FUN_00a36250(kData.m_fTime) &&
             (!m_spControllerInterpolator || !m_spControllerInterpolator->AlwaysUpdate()))
    {
        return;
    }
    if (m_spControllerInterpolator)
    {
        float fValue;
        if (m_spControllerInterpolator->Update(m_fControllerTime, m_pkTarget, fValue))
        {
            m_pkTarget->SetValue(fValue);
        }
    }
}

#include <windows.h>
struct Obj_00a56a90
{
    virtual void F0();
    virtual void F1();
    LONG m_lRef;
};
struct Base_00a56a90
{
    void __thiscall FUN_00a6d290();
};
void __cdecl _delete(void*, unsigned int);
struct FUN_00a56a90_shell
{
    char _pad[0x34];
    Obj_00a56a90* m_pEntryObject;
    void* __thiscall FUN_00a56a90(unsigned int);
};
// Decrements m_pEntryObject's count, calls F1 at zero, invokes FUN_00a6d290, optionally deletes this, and returns this.
// @fnv 0x00a56a90
void* __thiscall FUN_00a56a90_shell::FUN_00a56a90(unsigned int uiFlags)
{
    Obj_00a56a90* p = m_pEntryObject;
    if (p)
    {
        if (InterlockedDecrement(&p->m_lRef) == 0)
            p->F1();
    }
    ((Base_00a56a90*)this)->FUN_00a6d290();
    if (uiFlags & 1)
        _delete(this, 0x38);
    return this;
}
