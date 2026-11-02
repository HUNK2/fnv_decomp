
// src/gamebryo2.2/corelibs/nianimation/niviscontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niviscontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiBoolInterpController
{
    unsigned char m_bValue;  // placeholder
};

struct NiVisController
{
    NiBoolInterpController* m_pkBoolInterpController;  // +0x2c
    void GetVisibility(bool& bValue);
};

// @fnv 0x00a44d00
void NiVisController::GetVisibility(bool& abVisible)
{
    NiBoolInterpController* p = *(NiBoolInterpController**)((char*)this + 0x2c);
    abVisible = !(*(unsigned char*)((char*)p + 0x30) & 1);
}

extern void* g_011f3f08;

// @fnv 0x00a44eb0
void* __cdecl FUN_00a44eb0()
{
    return &g_011f3f08;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00a57790_shell
{
    void __thiscall FUN_00a57790();
};

extern void* DAT_01097e8c;

// Allocates a 0x38-byte BSFadeNode, runs its constructor, sets its vtable to DAT_01097e8c, and returns the pointer or 0 on allocation failure.
// @fnv 0x00a44f10
void* __cdecl FUN_00a44f10()
{
    void* mem = BSFadeNode::operator new(0x38);
    if (mem)
    {
        reinterpret_cast<FUN_00a57790_shell*>(mem)->FUN_00a57790();
        *reinterpret_cast<void**>(mem) = &DAT_01097e8c;
        return mem;
    }
    return 0;
}

extern const char* const g_011f3ec8_arg1;

// @fnv 0x00a57660
const char* __cdecl FUN_00a57660()
{
    return (const char*)&g_011f3ec8_arg1;
}

extern const char* const g_011f3f08_arg1;

// @fnv 0x00a577b0
const char* const* __cdecl FUN_00a577b0()
{
    return &g_011f3f08_arg1;
}

struct NiStream
{
    unsigned int m_uiNifVersion;  // +0xd8
    void __thiscall ResetStreamState();
};
void __stdcall FUN_00a57c70(NiStream*);
void __stdcall FUN_00a44d20(NiStream* pStream);
// @fnv 0x00a44d20
void __stdcall FUN_00a44d20(NiStream* pStream)
{
    FUN_00a57c70(pStream);
    if (*(unsigned int*)((char*)pStream + 0xd8) < 0xa010068)
        pStream->ResetStreamState();
}

struct NiRTTI
{
    const char* m_pcName;
    NiRTTI* m_pkBase;
};
extern NiRTTI g_011f4428_arg1;
struct NiObjectNET
{
    virtual void Unk0();
    virtual void Unk1();
    virtual NiRTTI* GetRTTI();
};
struct NiTransformController
{
    bool IsTargetOfType(NiObjectNET* pkTarget) const;
};
// Walks the target's RTTI base chain and returns true if it reaches g_011f4428_arg1, otherwise false.
// @fnv 0x00a44de0
bool NiTransformController::IsTargetOfType(NiObjectNET* pkTarget) const
{
    if (pkTarget)
    {
        NiRTTI* pkRTTI = pkTarget->GetRTTI();
        if (pkRTTI)
        {
            do
            {
                if (pkRTTI == &g_011f4428_arg1)
                    return true;
                pkRTTI = pkRTTI->m_pkBase;
            } while (pkRTTI);
        }
    }
    return false;
}

extern void* DAT_0109ab44;
struct NiTimeController
{
    void __thiscall SetControllerActive();
};
struct FUN_00a57640_shell : NiTimeController
{
    FUN_00a57640_shell* __thiscall FUN_00a57640();
};
// @fnv 0x00a57640
FUN_00a57640_shell* __thiscall FUN_00a57640_shell::FUN_00a57640()
{
    SetControllerActive();
    *(void**)(char*)this = &DAT_0109ab44;
    return this;
}

extern int DAT_0109ac54;

struct FUN_00a57790 : NiTimeController
{
    FUN_00a57790();
};

// @fnv 0x00a57790
FUN_00a57790::FUN_00a57790()
{
    SetControllerActive();
    *(int**)this = (int*)&DAT_0109ac54;
}

struct StrArr
{
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};

void __stdcall FUN_00a57800(StrArr*);
char* __cdecl _FUN_00a7d330(void*);

// @fnv 0x00a44f40
void __stdcall FUN_00a44f40(StrArr* pkStrings)
{
    FUN_00a57800(pkStrings);
    char* pcStr = _FUN_00a7d330(g_011f3f08);
    unsigned int uiElementCount = *(unsigned short*)((char*)pkStrings + 0xa);
    unsigned int uiSize = *(unsigned short*)((char*)pkStrings + 8);
    if (uiElementCount >= uiSize)
    {
        unsigned int uiGrow = *(unsigned short*)((char*)pkStrings + 0xe);
        pkStrings->SetSize(uiGrow + uiElementCount);
    }
    pkStrings->SetAt(uiElementCount, pcStr);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plValue);

class BA44D50Object;

class BA44D50Stream
{
  public:
    BA44D50Object* GetLoadedObject();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    unsigned int m_uiFileVersion;
};

class BA44D50RefObject
{
  public:
    virtual ~BA44D50RefObject();
    virtual void DeleteThis();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void VFuncA0();
    virtual void VFuncA4();
    virtual void VFuncA8();
    virtual void VFuncAC();
    virtual void VFuncB0();
    virtual void VFuncB4();
    virtual void VFuncB8();
    virtual void Collapse();

    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};

template <class T> class BA44D50Pointer
{
  public:
    BA44D50Pointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* operator->() const
    {
        return m_pObject;
    }

    T* m_pObject;
};

class BA44D50BoolInterpolator : public BA44D50RefObject
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    BA44D50BoolInterpolator(BA44D50Object* pkData) throw();

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class BA44D50Controller
{
  public:
    void BaseLinkObject(BA44D50Stream& kStream);
    void LinkBoolInterpolator(BA44D50Stream& kStream);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    BA44D50Pointer<BA44D50BoolInterpolator> m_spControllerInterpolator;
};

// @fnv 0x00a44d50
void BA44D50Controller::LinkBoolInterpolator(BA44D50Stream& kStream)
{
    BaseLinkObject(kStream);
    if (kStream.m_uiFileVersion < 0x0A010068)
    {
        BA44D50Object* pkData = kStream.GetLoadedObject();
        m_spControllerInterpolator = new BA44D50BoolInterpolator(pkData);
        m_spControllerInterpolator->Collapse();
    }
}

class BSFaceGenMorphData
{
  public:
    static void* operator new(unsigned int uiSize);
};
struct CtlA44 : FUN_00a57790_shell
{
    char m_auiShapeKeys[0x38];
    __forceinline CtlA44()
    {
        FUN_00a57790();
        *(void***)this = &DAT_01097e8c;
    }
};
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
struct OwnerA44
{
    void FUN_00a57620(CtlA44* pkCtl, unsigned int uiArg);
    CtlA44* CreateCtlA44(unsigned int uiArg);
};
// Allocates a 0x38-byte CtlA44, constructs it in place, passes it with uiArg to FUN_00a57620, and returns it.
// @fnv 0x00a44ec0
CtlA44* OwnerA44::CreateCtlA44(unsigned int uiArg)
{
    void* pMem = BSFaceGenMorphData::operator new(0x38);
    CtlA44* pkCtl = pMem ? new (pMem) CtlA44 : 0;
    FUN_00a57620(pkCtl, uiArg);
    return pkCtl;
}

extern const float DAT_01096324;

struct NiUpdateDataA44E
{
    float m_fTime;
    int unk04;
    bool m_bUnk08;
};

class NiAVObjectA44E
{
  public:
    virtual void vfn_00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    unsigned int m_uiObjectFlags;

    bool GetAppCulled() const
    {
        return (m_uiObjectFlags & 1) != 0;
    }
    void SetAppCulled(bool bAppCulled)
    {
        if (bAppCulled)
            m_uiObjectFlags |= 1;
        else
            m_uiObjectFlags &= ~1;
    }
};

class NiBoolInterpolatorA44E
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual bool Update(float fTime, NiAVObjectA44E* pkInterpTarget, bool& bValue);
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual bool AlwaysUpdate() const;
};

class NiVisControllerA44E
{
  public:
    virtual void vfn_00();
    bool FUN_00a36250(float fTime);
    void FUN_00a44e10(NiUpdateDataA44E& kUpdateData);

    bool GetManagerControlled() const
    {
        return (bool)((m_uiObjectFlags >> 5) & 1);
    }

    unsigned int m_uiRefCount;
    unsigned short m_uiObjectFlags;
    unsigned short unk0A;
    float m_fFrequency;
    float m_fPhase;
    float m_fLoKeyTime;
    float m_fHiKeyTime;
    float m_fStartTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fControllerTime;
    NiAVObjectA44E* m_pkTarget;
    void* m_spNextController;
    NiBoolInterpolatorA44E* m_spControllerInterpolator;
};

// @fnv 0x00a44e10
void NiVisControllerA44E::FUN_00a44e10(NiUpdateDataA44E& kUpdateData)
{
    if (GetManagerControlled())
    {
        m_fControllerTime = DAT_01096324;
    }
    else if (FUN_00a36250(kUpdateData.m_fTime) &&
             (!m_spControllerInterpolator || !m_spControllerInterpolator->AlwaysUpdate()))
    {
        return;
    }

    if (m_spControllerInterpolator)
    {
        bool bValue;
        if (m_spControllerInterpolator->Update(m_fControllerTime, m_pkTarget, bValue))
        {
            bool bOld = m_pkTarget->GetAppCulled();
            m_pkTarget->SetAppCulled(!bValue);
            if (bOld && bValue)
                kUpdateData.m_bUnk08 = true;
        }
    }
}
