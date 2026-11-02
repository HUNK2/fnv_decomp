
// src/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern const char* const g_011c7d74_arg1;

// @fnv 0x00a31730
const char* const* __cdecl FUN_00a31730()
{
    return &g_011c7d74_arg1;
}

struct BaseH
{
    virtual ~BaseH();
};

struct NiControllerSequence : BaseH
{
    void* FUN_00a35820(unsigned int);
};

extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);

// @fnv 0x00a35820
void* NiControllerSequence::FUN_00a35820(unsigned int flags)
{
    BaseH::~BaseH();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x74);
    return this;
}

struct FUN_00a30580_shell
{
    bool __thiscall IsNotInChain(void* arg);
};

// Walks the linked list at offset 0x58 from arg and returns false if this is found in it, true otherwise.
// @fnv 0x00a30580
bool __thiscall FUN_00a30580_shell::IsNotInChain(void* pStart)
{
    void* next = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(pStart) + 0x58);
    if (next == 0)
        return true;
    do
    {
        if (next == this)
            return false;
        next = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(next) + 0x58);
    } while (next != 0);
    return true;
}

void __cdecl ReleaseObjectArray(void*);
struct MM_00a34450
{
    void __thiscall _DeallocateAlias(void*);
};
extern MM_00a34450 g_memoryManager;
extern int DAT_01096620;
struct FUN_00a34450_shell
{
    void* __thiscall FUN_00a34450(unsigned int);
};
// @fnv 0x00a34450
void* __thiscall FUN_00a34450_shell::FUN_00a34450(unsigned int auiFlags)
{
    void* p = *(void**)((char*)this + 4);
    *(void**)this = (void*)&DAT_01096620;
    ReleaseObjectArray(p);
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

struct NiBinaryStream
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pv, unsigned int uiBytes)
    {
        unsigned int uiComponentSize = uiBytes;
        m_uiStreamFlags += m_pfnWrite(this, pv, uiBytes, &uiComponentSize, 1);
    }
};
struct NiStream
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void SaveLinkID(const void* pkObject);
    void SerializeString(char const*);
    unsigned char m_auiShapeKeys[0x24c];
    NiBinaryStream* m_pBackingStream;
};
struct NiObject
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    void LinkObject(NiStream&);
};
struct SeqInterpArrayItem
{
    void* m_spControllerInterpolator;
    void* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned char m_auiShapeKeys[2];
};
struct SeqIDTag
{
    char* m_kAVObjectName;
    char* m_kPropertyType;
    char* m_kCtlrType;
    char* m_kCtlrID;
    char* m_kInterpolatorID;
};
struct FUN_00a33bf0_s : NiObject
{
    char* m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    SeqInterpArrayItem* m_pInterpArray;
    SeqIDTag* m_pkIDTags;
    float m_fWeight;
    void* m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    unsigned char m_pad34[0xc];
    void* m_pkOwnerManager;
    unsigned char m_pad44[0x18];
    char* m_kAccumulationRootName;
    unsigned char m_pad60[0xc];
    void** m_pkAnimNotes;
    unsigned short m_usNumAnimNotes;
    void SaveToStream(NiStream& kStream);
};
// Links the object to the stream, then writes the name, interpolation array items with their ID tags, scalar fields and the linked object list.
// @fnv 0x00a33bf0
void FUN_00a33bf0_s::SaveToStream(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    kStream.SerializeString((const char*)&m_kName);
    kStream.m_pBackingStream->Write(&m_uiNumControlledBlocks, 4);
    kStream.m_pBackingStream->Write(&m_uiNumIDTags, 4);
    unsigned int ui;
    for (ui = 0; ui < m_uiNumControlledBlocks; ui++)
    {
        SeqInterpArrayItem& kItem = m_pInterpArray[ui];
        kStream.SaveLinkID(kItem.m_spControllerInterpolator);
        kStream.SaveLinkID(kItem.m_pkController);
        kStream.m_pBackingStream->Write(&kItem.m_ucArrayItemID, 1);
        SeqIDTag& kTag = m_pkIDTags[ui];
        kStream.SerializeString((const char*)&kTag.m_kAVObjectName);
        kStream.SerializeString((const char*)&kTag.m_kPropertyType);
        kStream.SerializeString((const char*)&kTag.m_kCtlrType);
        kStream.SerializeString((const char*)&kTag.m_kCtlrID);
        kStream.SerializeString((const char*)&kTag.m_kInterpolatorID);
    }
    kStream.m_pBackingStream->Write(&m_fWeight, 4);
    kStream.SaveLinkID(m_spTextKeyData);
    kStream.m_pBackingStream->Write(&m_eAnimationCycleType, 4);
    kStream.m_pBackingStream->Write(&m_fFrequency, 4);
    kStream.m_pBackingStream->Write(&m_fFirstKeyTime, 4);
    kStream.m_pBackingStream->Write(&m_fLastKeyTime, 4);
    kStream.SaveLinkID(m_pkOwnerManager);
    kStream.SerializeString((const char*)&m_kAccumulationRootName);
    kStream.m_pBackingStream->Write(&m_usNumAnimNotes, 2);
    for (unsigned short usIndex = 0; usIndex < m_usNumAnimNotes; usIndex++)
        kStream.SaveLinkID(m_pkAnimNotes[usIndex]);
}

struct FUN_00a2e420_shell
{
    unsigned char FUN_00a2e420(float);
};
struct FUN_00a30540_shell
{
    void FUN_00a30540();
};
extern float DAT_01015f5c;
extern double DAT_010241b0;
struct FUN_00a35030_shell : NiControllerSequence
{
    unsigned char SetEaseOut(float fEaseOutTime, bool bTransition);
};
// Starts an ease-out with the given time and transition flag, or finishes it by updating the accumulated time and resetting state.
// @fnv 0x00a35030
unsigned char FUN_00a35030_shell::SetEaseOut(float fEaseOutTime, bool bTransition)
{
    if (!*(void**)((char*)this + 0x44))
        return 0;
    if (fEaseOutTime > 0.0f)
    {
        *(float*)((char*)this + 0x4c) = DAT_01015f5c;
        *(float*)((char*)this + 0x50) = fEaseOutTime;
        *(unsigned int*)((char*)this + 0x44) = bTransition ? 4 : 3;
        return 1;
    }
    if (*(float*)((char*)this + 0x34) != DAT_010241b0)
        *(float*)((char*)this + 0x48) = *(float*)((char*)this + 0x38) / *(float*)((char*)this + 0x28) -
                                        *(float*)((char*)this + 0x34) + *(float*)((char*)this + 0x48);
    if (*(unsigned int*)((char*)this + 0x44) == 5 && *(void**)((char*)this + 0x40))
        ((FUN_00a2e420_shell*)*(void**)((char*)this + 0x40))->FUN_00a2e420(0.0f);
    *(float*)((char*)this + 0x54) = DAT_01015f5c;
    *(unsigned int*)((char*)this + 0x44) = 0;
    *(void**)((char*)this + 0x58) = 0;
    ((FUN_00a30540_shell*)this)->FUN_00a30540();
    return 1;
}

struct FUN_00a30900_shell
{
    void FUN_00a30900(char m_ucRegionPriority);
};

// @fnv 0x00a30900
void FUN_00a30900_shell::FUN_00a30900(char cDefaultPriority)
{
    unsigned int ui;
    SeqInterpArrayItem* kItem;

    for (ui = 0; ui < *(unsigned int*)((char*)this + 0xc); ++ui)
    {
        kItem = (SeqInterpArrayItem*)(*(unsigned int*)((char*)this + 0x14) + ui * 0x10);
        if (kItem->m_spControllerInterpolator && kItem->m_pkBlendInterpolator)
        {
            unsigned int ucPriority;
            if (kItem->m_ucArrayItemID == 0xff)
                ucPriority = (unsigned int)cDefaultPriority;
            else
                ucPriority = kItem->m_ucArrayItemID;
            kItem->m_ucBlendIndex = ((unsigned char(__thiscall*)(void*, void*, float, unsigned int, float)) *
                                     (void**)(*(unsigned int*)kItem->m_pkBlendInterpolator + 0xdc))(
                kItem->m_pkBlendInterpolator, kItem->m_spControllerInterpolator, *(float*)((char*)this + 0x1c),
                ucPriority, 1.0f);
        }
    }
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00a316a0_shell
{
    void* __thiscall FUN_00a316a0();
};

// @fnv 0x00a326c0
void* __cdecl FUN_00a326c0()
{
    void* p = A51BF0Base::operator new(0x74);
    if (p)
        return reinterpret_cast<FUN_00a316a0_shell*>(p)->FUN_00a316a0();
    return 0;
}

extern char DAT_01096584;
extern void* _EmptyFS;
extern int(__stdcall* DAT_00fdf1c4)(void*);

struct NiRefObject
{
    ~NiRefObject();
};

struct FUN_00a31500_shell
{
    void __thiscall FUN_00a31500(int);
};

struct FUN_00a315b0_shell
{
    void __thiscall FUN_00a315b0(int);
};

struct FUN_00a31740_shell
{
    void __thiscall FUN_00a31740(int);
};

struct FUN_00a35640_shell
{
    void __thiscall FUN_00a35640();
};

struct RefBase
{
    virtual void First()
    {}
    virtual void Release()
    {}
};

// @fnv 0x00a35640
void FUN_00a35640_shell::FUN_00a35640()
{
    *reinterpret_cast<void**>(this) = &DAT_01096584;

    if (*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x44) != 0)
    {
        reinterpret_cast<FUN_00a35030_shell*>(this)->SetEaseOut(0.0f, false);
    }

    if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x14) != 0)
    {
        reinterpret_cast<FUN_00a31500_shell*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x14))
            ->FUN_00a31500(3);
    }

    if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x18) != 0)
    {
        reinterpret_cast<FUN_00a315b0_shell*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x18))
            ->FUN_00a315b0(3);
    }

    if (*reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(this) + 0x70) > 0 &&
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x6c) != 0)
    {
        reinterpret_cast<FUN_00a31740_shell*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x6c))
            ->FUN_00a31740(3);
    }

    int(__stdcall * pDecrementRef)(void*) = DAT_00fdf1c4;

    void* p = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x64);
    if (p != 0)
    {
        if (pDecrementRef(reinterpret_cast<char*>(p) + 4) == 0)
        {
            reinterpret_cast<RefBase*>(p)->Release();
        }
    }

    void* pString = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x5c);
    if (pString != _EmptyFS)
    {
        pDecrementRef(reinterpret_cast<char*>(pString) - 8);
    }

    p = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x20);
    if (p != 0)
    {
        if (pDecrementRef(reinterpret_cast<char*>(p) + 4) == 0)
        {
            reinterpret_cast<RefBase*>(p)->Release();
        }
    }

    pString = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x8);
    if (pString != _EmptyFS)
    {
        pDecrementRef(reinterpret_cast<char*>(pString) - 8);
    }

    reinterpret_cast<NiRefObject*>(this)->~NiRefObject();
}

extern "C" unsigned int __cdecl strlen(const char* s);
void __cdecl FUN_00a305b0(char* out, unsigned int size, const char* fmt, const char* a, const char* b, const char* c);
void __cdecl FUN_00ec65a6(char* c, unsigned int b, const char* a);

struct FUN_00a307c0_entry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct FUN_00a307c0_item
{
    const char* name;
    const char* ctrl;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
};

struct FUN_00a307c0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_00a307c0_entry* m_14;
    FUN_00a307c0_item* m_18;
    void GetEntryText(unsigned int idx, char* out);
};

// @fnv 0x00a307c0
void FUN_00a307c0_cls::GetEntryText(unsigned int uiIndex, char* out)
{
    if (out == 0)
    {
        return;
    }
    if (m_14[uiIndex].unk00 == 0)
    {
        *out = 0;
    }
    else
    {
        FUN_00a307c0_item* item = &m_18[uiIndex];
        const char* name = item->name;
        unsigned int nameLen = strlen(name) + 1;
        const char* ctrl = item->ctrl;
        if (ctrl != 0)
        {
            const char* propStr = ctrl ? "PROP\n" : 0;
            unsigned int propLen = strlen(propStr);
            unsigned int ctrlLen = strlen(ctrl);
            unsigned int total = ctrlLen + propLen + nameLen + 1;
            FUN_00a305b0(out, total, "%s\n%s%s", name, "PROP\n", ctrl);
        }
        else
        {
            FUN_00ec65a6(out, nameLen, name);
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* Addend);

struct S_00a30880_RefObject
{
    virtual ~S_00a30880_RefObject()
    {}
    virtual void V01()
    {}

    long m_lRefCount;
};

struct S_00a30880_Base
{
    virtual void V00()
    {}
    virtual void V01()
    {}
    virtual void V02()
    {}
    virtual void V03()
    {}
    virtual void V04()
    {}
    virtual void V05()
    {}
    virtual void V06()
    {}
    virtual void V07()
    {}
    virtual void V08()
    {}
    virtual void V09()
    {}
    virtual void V10()
    {}
    virtual void V11()
    {}
    virtual void V12()
    {}
    virtual void V13()
    {}
    virtual void V14()
    {}
    virtual void V15()
    {}
    virtual void V16()
    {}
    virtual void V17()
    {}
    virtual void V18()
    {}
    virtual void V19()
    {}
    virtual void V20()
    {}
    virtual void V21()
    {}
    virtual void V22()
    {}
    virtual void V23()
    {}
    virtual void V24()
    {}
    virtual void V25()
    {}
    virtual void V26()
    {}
    virtual void V27()
    {}
    virtual void V28()
    {}
    virtual void V29()
    {}
    virtual void V30()
    {}
    virtual void V31()
    {}
    virtual void V32()
    {}
    virtual void V33()
    {}
    virtual void V34()
    {}

    virtual void Target(float fValue, unsigned int uiFlags)
    {}
};

struct S_00a30880_Item
{
    void* m_spControllerInterpolator;
    S_00a30880_RefObject* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned char m_auiShapeKeys[2];
};

struct S_00a30880_Foo : S_00a30880_Base
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    S_00a30880_Item* m_pInterpArray;
    void* unk18;
    float unk1c;
    void* unk20;
    unsigned int unk24;
    float unk28;
    float unk2c;
    float unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;

    void ReleaseItems();
};

// Calls Target(0,0) when unk44 is set, then releases each item's reference-counted object and clears its pointer.
// @fnv 0x00a30880
void S_00a30880_Foo::ReleaseItems()
{
    if (unk44 != 0)
    {
        S_00a30880_Base* pBase = this;
        pBase->Target(0.0f, 0u);
    }

    unsigned int uiIndex = 0;

    if (m_uiNumControlledBlocks > uiIndex)
    {
        do
        {
            S_00a30880_RefObject** ppRefObject = &m_pInterpArray[uiIndex].m_pkController;
            S_00a30880_RefObject* pRefObject = *ppRefObject;

            if (pRefObject != 0)
            {
                if (InterlockedDecrement(&pRefObject->m_lRefCount) == 0)
                    pRefObject->V01();

                *ppRefObject = 0;
            }

            m_pInterpArray[uiIndex].m_pkBlendInterpolator = 0;
        } while (++uiIndex < m_uiNumControlledBlocks);
    }
}

extern "C" double __cdecl fmod(double, double);
struct SequenceA30970 : NiObject
{
    char* name08;
    unsigned int arraySize0c;
    unsigned int arrayGrow10;
    SeqInterpArrayItem* interpolators14;
    SeqIDTag* tags18;
    float weight1c;
    void* textKeys20;
    int cycleType24;
    float frequency28;
    float begin2c;
    float end30;
    float lastTime34;
    float accumulated38;
    float scaled3c;
    float __thiscall FUN_00a30970(float time, bool update);
};
// Advances the sequence's accumulated time by frequency times the delta, wraps it into [begin,end] when cycleType is 0, and optionally stores the new state.
// @fnv 0x00a30970
float SequenceA30970::FUN_00a30970(float time, bool update)
{
    float accumulated = accumulated38;
    float delta;
    if (lastTime34 == DAT_010241b0)
    {
        accumulated = 0.0f;
        delta = time;
    }
    else
    {
        delta = time - lastTime34;
    }
    accumulated += frequency28 * delta;
    float scaled = accumulated;
    if (cycleType24 == 0)
    {
        float duration = end30 - begin2c;
        if (duration != 0.0f)
        {
            scaled -= begin2c;
            if (scaled == duration)
                scaled = end30;
            else
                scaled = (float)fmod(scaled, duration) + begin2c;
            if (scaled < begin2c)
                scaled += duration;
        }
        else
        {
            scaled = begin2c;
        }
    }
    if (scaled > end30)
        scaled = end30;
    else if (scaled < begin2c)
        scaled = begin2c;
    if (update)
    {
        accumulated38 = accumulated;
        lastTime34 = time;
        scaled3c = scaled;
    }
    return scaled;
}

struct FUN_00a30c80_shell
{
    unsigned __int64 __thiscall IsNotInChain(void* arg);
    bool __thiscall FUN_00a30c80(void* arg);
};
bool __stdcall MatchesTextKeys(void* arg);
// @fnv 0x00a30c80
bool FUN_00a30c80_shell::FUN_00a30c80(void* arg)
{
    if (arg)
    {
        void* linked = *reinterpret_cast<void**>(static_cast<char*>(arg) + 0x58);
        if (linked)
        {
            if (linked == this)
                goto failure;
            unsigned __int64 result = IsNotInChain(linked);
            if (!static_cast<unsigned char>(result))
                goto failure;
            arg = reinterpret_cast<void*>(static_cast<unsigned int>(result >> 32));
        }
        if (MatchesTextKeys(arg))
            return true;
    }
failure:
    return false;
}

struct FUN_00a30cc0_target
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual bool V23(void* pOther);
};

struct FUN_00a30cc0_cls
{
    FUN_00a30cc0_target* m_pKey0;
    FUN_00a30cc0_target* m_pKey4;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char unk0C;
    unsigned char m_bFlag0D;

    unsigned char Equals(FUN_00a30cc0_cls* other);
};

// Compares two objects' key pointers via V23 and returns whether both keys match and m_bFlag0D is equal.
// @fnv 0x00a30cc0
unsigned char FUN_00a30cc0_cls::Equals(FUN_00a30cc0_cls* other)
{
    if ((m_pKey0 != 0 && other->m_pKey0 == 0) || (m_pKey0 == 0 && other->m_pKey0 != 0) ||
        (m_pKey0 != 0 && other->m_pKey0 != 0 && !m_pKey0->V23(other->m_pKey0)))
        return false;
    FUN_00a30cc0_target* a = m_pKey4;
    if ((a != 0 && other->m_pKey4 == 0) || (m_pKey4 == 0 && other->m_pKey4 != 0) ||
        (a != 0 && other->m_pKey4 != 0 && !a->V23(other->m_pKey4)))
        return false;
    return m_bFlag0D == other->m_bFlag0D;
}

struct StreamView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(char*&);
};
struct RefView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual bool v21(StreamView&);
};
struct ObjectView
{
    int vtable;
    int refs;
    bool FUN_00a5d2f0(StreamView&);
};
struct ItemView
{
    RefView* interpolator;
    RefView* controller;
    void* blend;
    unsigned int settings;
};
struct TagView
{
    char* object;
    char* property;
    char* type;
    char* controller;
    char* interpolator;
};
struct SequenceView : ObjectView
{
    char* name;
    unsigned int count;
    unsigned int grow;
    ItemView* items;
    TagView* tags;
    float weight;
    RefView* text;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    char* root;
    int unk60;
    int unk64;
    int unk68;
    RefView** notes;
    unsigned short noteCount;
    bool FUN_00a30ea0(StreamView&);
};
// @fnv 0x00a30ea0
bool SequenceView::FUN_00a30ea0(StreamView& stream)
{
    if (!FUN_00a5d2f0(stream))
        return false;
    for (unsigned int i = 0; i < count; i++)
    {
        ItemView& item = items[i];
        if (item.interpolator)
            item.interpolator->v21(stream);
        RefView* controller = item.controller;
        if (controller)
            controller->v21(stream);
        TagView& tag = tags[i];
        stream.v8(tag.object);
        stream.v8(tag.property);
        stream.v8(tag.type);
        stream.v8(tag.controller);
        stream.v8(tag.interpolator);
    }
    RefView* textKeys = text;
    if (textKeys)
        textKeys->v21(stream);
    stream.v8(name);
    stream.v8(root);
    for (unsigned short j = 0; j < noteCount; j++)
        notes[j]->v21(stream);
    return true;
}

__declspec(dllimport) long __stdcall InterlockedIncrement(long* p);
__declspec(dllimport) long __stdcall InterlockedDecrement(long* p);

extern void* _EmptyFS;

struct FixedStr
{
    char* m_handle;
    FixedStr() : m_handle((char*)_EmptyFS)
    {}
    static void AcquireReference(char* h)
    {
        if (h != _EmptyFS)
            InterlockedIncrement((long*)(h - 8));
    }
    static void DecRef(char* h)
    {
        if (h != _EmptyFS)
            InterlockedDecrement((long*)(h - 8));
    }
    FixedStr& operator=(const FixedStr& o)
    {
        char* h = o.m_handle;
        if (m_handle != h)
        {
            AcquireReference(h);
            DecRef(m_handle);
            m_handle = h;
        }
        return *this;
    }
};

struct FUN_00a312d0
{
    FixedStr m_kAVObjectName;
    FixedStr m_kPropertyType;
    FixedStr m_kCtlrType;
    FixedStr m_kCtlrID;
    FixedStr m_kInterpolatorID;
    void ClearIdentifiers();
    FUN_00a312d0(const FixedStr& a, const FixedStr& b, const FixedStr& c, const FixedStr& d, const FixedStr& e);
};

// @fnv 0x00a312d0
FUN_00a312d0::FUN_00a312d0(const FixedStr& akAVObjectName, const FixedStr& akPropertyType, const FixedStr& akCtlrType,
                           const FixedStr& akCtlrID, const FixedStr& akInterpolatorID)
{
    ClearIdentifiers();
    m_kAVObjectName = akAVObjectName;
    m_kPropertyType = akPropertyType;
    m_kCtlrType = akCtlrType;
    m_kCtlrID = akCtlrID;
    m_kInterpolatorID = akInterpolatorID;
}

extern int DAT_0109b220;
extern int(__stdcall* DAT_00fdf1c4)(void*);

struct S_00aa4060_Class
{
    void FUN_00aa4060(void* apMemory);
};
extern S_00aa4060_Class DAT_011f6238;

struct FUN_00a315b0_Elem
{
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    char* m_10;
};

class FUN_00a315b0_Base
{
  public:
    void FUN_00a30750();
};

class FUN_00a315b0_cls
{
  public:
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    char* m_10;

    FUN_00a315b0_cls* FUN_00a315b0(unsigned char acFlags);
};

// @fnv 0x00a315b0
FUN_00a315b0_cls* FUN_00a315b0_cls::FUN_00a315b0(unsigned char acFlags)
{
    if (acFlags & 2)
    {
        int i = ((int*)this)[-1];
        FUN_00a315b0_Elem* e = (FUN_00a315b0_Elem*)((char*)this + i * 20);
        i = i - 1;
        char* base = (char*)this - 4;
        if (i >= 0)
        {
            int(__stdcall * pRelease)(void*) = DAT_00fdf1c4;
            do
            {
                e = (FUN_00a315b0_Elem*)((char*)e - 20);
                if ((int)e->m_10 != DAT_0109b220)
                {
                    pRelease(e->m_10 - 8);
                }
                if ((int)e->m_0c != DAT_0109b220)
                {
                    pRelease(e->m_0c - 8);
                }
                if ((int)e->m_08 != DAT_0109b220)
                {
                    pRelease(e->m_08 - 8);
                }
                if ((int)e->m_04 != DAT_0109b220)
                {
                    pRelease(e->m_04 - 8);
                }
                if ((int)e->m_00 != DAT_0109b220)
                {
                    pRelease(e->m_00 - 8);
                }
            } while (--i >= 0);
        }
        if (acFlags & 1)
        {
            DAT_011f6238.FUN_00aa4060(base);
        }
        return (FUN_00a315b0_cls*)base;
    }

    ((FUN_00a315b0_Base*)this)->FUN_00a30750();
    if (acFlags & 1)
    {
        DAT_011f6238.FUN_00aa4060(this);
    }
    return this;
}

struct a31740_Ref
{
    virtual void v00();
    virtual void Release();
    int refCount;
};

struct a31740_Mem
{
    void __thiscall _DeallocateAlias(void*);
};

extern a31740_Mem g_memMgr31740;

struct FUN_00a31740_cls
{
    a31740_Ref* m_pReference;

    void* FUN_00a31740(unsigned char acFlags);
};

// Releases the referenced objects (decrementing refcounts and calling Release at zero) and optionally deallocates this or the array block based on acFlags.
// @fnv 0x00a31740
void* FUN_00a31740_cls::FUN_00a31740(unsigned char acFlags)
{
    if (acFlags & 2)
    {
        char* base = (char*)this - 4;
        int i = *(int*)base;
        a31740_Ref** p = (a31740_Ref**)this + i;
        i = i - 1;
        if (i >= 0)
        {
            do
            {
                p = p - 1;
                a31740_Ref* e = *p;
                if (e != 0 && InterlockedDecrement((long volatile*)&e->refCount) == 0)
                {
                    e->Release();
                }
            } while (--i >= 0);
        }
        if (acFlags & 1)
        {
            g_memMgr31740._DeallocateAlias(base);
        }
        return base;
    }

    a31740_Ref* e = m_pReference;
    if (e != 0 && InterlockedDecrement((long volatile*)&e->refCount) == 0)
    {
        e->Release();
    }
    if (acFlags & 1)
    {
        g_memMgr31740._DeallocateAlias(this);
    }
    return this;
}

extern int(__stdcall* DAT_00fdf1c0)(void*);
extern int(__stdcall* DAT_00fdf1c4)(void*);

struct FUN_00a317e0_ref
{
    virtual ~FUN_00a317e0_ref();
    virtual void DeleteThis();
    int m_uiRefCount;
};

struct FUN_00a317e0_interp
{
    void* m_spControllerInterpolator;
    void* unk04;
    void* unk08;
    void* unk0C;
    void __thiscall FUN_00a31260();
};

struct FUN_00a317e0_tag
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void __thiscall ResetStrings();
};

struct FUN_00a317e0_t
{
    void* unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    FUN_00a317e0_interp* m_pInterpArray;
    FUN_00a317e0_tag* m_pkIDTags;

    void __thiscall AssignInterpolatorRef(int index, FUN_00a317e0_ref** output);
};

// @fnv 0x00a317e0
void __thiscall FUN_00a317e0_t::AssignInterpolatorRef(int index, FUN_00a317e0_ref** output)
{
    FUN_00a317e0_ref* pNewRef = reinterpret_cast<FUN_00a317e0_ref*>(
        reinterpret_cast<FUN_00a317e0_interp*>(m_pInterpArray + index)->m_spControllerInterpolator);

    if (pNewRef)
        DAT_00fdf1c0(&pNewRef->m_uiRefCount);

    reinterpret_cast<FUN_00a317e0_interp*>(m_pInterpArray + index)->FUN_00a31260();

    reinterpret_cast<FUN_00a317e0_tag*>(m_pkIDTags + index)->ResetStrings();

    FUN_00a317e0_ref* old = *output;
    int(__stdcall * pfnDecrementRef)(void*) = DAT_00fdf1c4;

    if (old != pNewRef)
    {
        if (old)
        {
            if (pfnDecrementRef(&old->m_uiRefCount) == 0)
                old->DeleteThis();
        }

        *output = pNewRef;

        if (pNewRef)
            DAT_00fdf1c0(&pNewRef->m_uiRefCount);
    }

    if (pNewRef)
    {
        if (pfnDecrementRef(&pNewRef->m_uiRefCount) == 0)
            pNewRef->DeleteThis();
    }
}

namespace fnv_00a328b0 {
extern char* DAT_0109b220;

struct SeqExt : FUN_00a33bf0_s
{
    void FUN_00a328b0(float time, bool setControllerTimes);
};

// Computes time plus an offset, optionally writes time to each controller's time field, and stores the result in m_pad44[4].
// @fnv 0x00a328b0
void SeqExt::FUN_00a328b0(float time, bool setControllerTimes)
{
    float currentTime = time + m_fFirstKeyTime;
    if (setControllerTimes)
    {
        unsigned int index = 0;
        if (index < m_uiNumControlledBlocks)
        {
            do
            {
                SeqIDTag& tag = m_pkIDTags[index];
                void* controller = m_pInterpArray[index].m_pkController;
                if (controller && tag.m_kCtlrType != DAT_0109b220 &&
                    (!tag.m_kCtlrType || tag.m_kCtlrType[2] != 'T' || tag.m_kCtlrType[7] != 'f'))
                {
                    *reinterpret_cast<float*>(static_cast<char*>(controller) + 0x10) = time;
                }
                ++index;
            } while (index < m_uiNumControlledBlocks);
        }
    }
    *reinterpret_cast<float*>(&m_pad44[4]) = currentTime;
}
}  // namespace fnv_00a328b0

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);

struct RefObj
{
    virtual void V00();
    virtual void Release();
    long m_iObjectReferenceCount;
};

struct SlotEntry
{
    RefObj* m_pEntryObject;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned char m_unk0c;
    unsigned char m_flag0d;
    unsigned char m_unk0e;
    unsigned char m_unk0f;
};

struct SlotInfo
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
    void FUN_00a31400(unsigned int value);
};

struct FUN_00a32bc0_cls
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_uiItemCount;
    unsigned int m_unk10;
    SlotEntry* m_pSlots;
    SlotInfo* m_pInfos;

    bool FUN_00a32330();
    int AssignSlot(RefObj* p1, unsigned int p2, unsigned char p3);
};

// @fnv 0x00a32bc0
int FUN_00a32bc0_cls::AssignSlot(RefObj* apRef, unsigned int auiValue, unsigned char aucFlag)
{
    unsigned int count = m_uiItemCount;
    unsigned int idx = 0;
    for (; idx < count; ++idx)
    {
        if (m_pSlots[idx].m_pEntryObject == 0)
        {
            break;
        }
    }
    if (idx == count)
    {
        if (!FUN_00a32330())
        {
            return -1;
        }
    }
    SlotEntry* slot = &m_pSlots[idx];
    if (slot->m_pEntryObject != apRef)
    {
        RefObj* old = slot->m_pEntryObject;
        if (old != 0)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
            {
                old->Release();
            }
        }
        slot->m_pEntryObject = apRef;
        if (apRef != 0)
        {
            InterlockedIncrement(&apRef->m_iObjectReferenceCount);
        }
    }
    m_pInfos[idx].FUN_00a31400(auiValue);
    m_pSlots[idx].m_flag0d = aucFlag;
    return idx;
}

struct FUN_00a34480_obj
{
    virtual void V00();
    virtual void V01();
    virtual FUN_00a34480_obj* V02();
    FUN_00a34480_obj* m_pNext;
    unsigned short m_word08;
    unsigned short unk0a;
    float m_f0c;
};

extern int DAT_011f36b4;

struct FUN_00a34480_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned short m_word24;
    unsigned short unk26;
    float m_f28;

    bool AssignControllers(void* a1, FUN_00a34480_obj* a2);
    bool FUN_00a34480(void* a1, FUN_00a34480_obj* a2);
};

// Walks the linked list from a2's V02() looking for DAT_011f36b4; if found, merges m_word24 into a2->m_word08, copies m_f28 to a2->m_f0c and calls AssignControllers.
// @fnv 0x00a34480
bool FUN_00a34480_cls::FUN_00a34480(void* a1, FUN_00a34480_obj* pNode)
{
    FUN_00a34480_obj* cur = 0;
    if (a1 != 0)
    {
        if (pNode != 0)
        {
            cur = pNode->V02();
            if (cur != 0)
            {
                do
                {
                    if (cur == (FUN_00a34480_obj*)&DAT_011f36b4)
                    {
                        goto found;
                    }
                    cur = cur->m_pNext;
                } while (cur != 0);
            }
        }
    }
    return false;

found:
    unsigned short flags = (unsigned short)(m_word24 + m_word24);
    flags = (unsigned short)(flags | (pNode->m_word08 & 0xfff9));
    pNode->m_word08 = flags;
    pNode->m_f0c = m_f28;
    pNode->m_word08 = (unsigned short)(pNode->m_word08 & 0xffef);
    return AssignControllers(a1, pNode);
}

extern void* DAT_011f36dc;
extern char DAT_01044a7c, DAT_01096678, DAT_0105ac84, DAT_0109666c;
extern char DAT_01096664, DAT_01044c94, DAT_01044c90, DAT_0109665c;
extern char DAT_01096654, DAT_010477f4, DAT_01096648, DAT_0109663c;
extern char DAT_01096630, DAT_01096624;

struct OutputArray
{
    void* unk00;
    void** data;
    unsigned short capacity;
    unsigned short length;
    unsigned short populated;
    unsigned short growth;
    void FUN_0096ad30(unsigned int capacity);
    void FUN_0096ae90(unsigned int index, void** value);
    void Append(void* value)
    {
        unsigned int index = length;
        if (index >= capacity)
            FUN_0096ad30(index + growth);
        FUN_0096ae90(index, &value);
    }
};

struct ControlItem
{
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned char unk0c;
    unsigned char priority;
    unsigned short unk0e;
};
struct TagItem
{
    const char* first;
    const char* second;
    const char* third;
    const char* fourth;
    const char* fifth;
};

void* __cdecl FUN_00a7d330(void*);
void* __cdecl FormatStringWithType(const char*, void*);
void* __cdecl FUN_00a7d510(const char*, unsigned int);
void* __cdecl FUN_00a7d550(const char*, float);
void* __cdecl FUN_00a6d190(const char*, void*);
int __cdecl FUN_00a305b0(char*, unsigned int, const char*, ...);
void* __cdecl FUN_00a7d5e0(const char*, const char*);

struct Position
{
    unsigned int i;
    unsigned int tagOffset;
};
struct Sequence
{
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned int itemCount;
    void* unk10;
    ControlItem* controls;
    TagItem* tags;
    float mainWeight;
    void* unk20;
    void* interp;
    float fadeIn;
    float fadeOut;
    float duration;
    float offset;
    float rate;
    float extra3c;
    void* unk40;
    void* name;
    float start;
    float end;
    float total;
    void AppendCameraPathEntries(OutputArray*);
    void FUN_00a34540(OutputArray* output);
};

// Appends the sequence's base data and per-item key/value entries built from each tag and control priority to the output array.
// @fnv 0x00a34540
void Sequence::FUN_00a34540(OutputArray* output)
{
    AppendCameraPathEntries(output);
    output->Append(FUN_00a7d330(DAT_011f36dc));
    output->Append(FormatStringWithType(&DAT_01044a7c, name));
    output->Append(FUN_00a7d510(&DAT_01096678, itemCount));
    output->Append(FUN_00a7d550(&DAT_0105ac84, mainWeight));
    output->Append(FUN_00a6d190(&DAT_0109666c, interp));
    output->Append(FUN_00a7d550(&DAT_01096664, fadeIn));
    output->Append(FUN_00a7d550(&DAT_01044c94, fadeOut));
    output->Append(FUN_00a7d550(&DAT_01044c90, duration));
    output->Append(FUN_00a7d550(&DAT_0109665c, offset));
    output->Append(FUN_00a7d550(&DAT_01096654, start));
    output->Append(FUN_00a7d550(&DAT_010477f4, end));
    output->Append(FUN_00a7d550(&DAT_01044c90, total));
    output->Append(FUN_00a7d550(&DAT_01096648, rate));
    output->Append(FUN_00a7d550(&DAT_0109663c, extra3c));
    Position pos;
    pos.i = 0;
    if (pos.i < itemCount)
    {
        char key[128];
        char val[256];
        unsigned int controlOffset = 0;
        pos.tagOffset = 0;
        do
        {
            TagItem* tag = (TagItem*)((char*)tags + pos.tagOffset);
            ControlItem* ctrl = (ControlItem*)((char*)controls + controlOffset);
            FUN_00a305b0(key, sizeof(key), &DAT_01096630, pos.i);
            FUN_00a305b0(val, sizeof(val), &DAT_01096624, tag->first, tag->third, ctrl->priority);
            void* entry = FUN_00a7d5e0(key, val);
            unsigned int index = output->length;
            if (index >= output->capacity)
                output->FUN_0096ad30(index + output->growth);
            if (index >= output->length)
            {
                output->length = index + 1;
                if (entry)
                    output->populated++;
            }
            else if (entry)
            {
                if (!output->data[index])
                    output->populated++;
            }
            else if (output->data[index])
            {
                output->populated--;
            }
            output->data[index] = entry;
            pos.tagOffset += sizeof(TagItem);
            controlOffset += sizeof(ControlItem);
            ++pos.i;
        } while (pos.i < itemCount);
    }
}

static const float g_fSeqNegInfinity = -3.402823466e+38f;

struct SeqA34f20;

struct SeqPtrArray
{
    unsigned int AddSeq(SeqA34f20* const& pkSeq);
};

struct SeqOwner
{
    int unk00;
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
    int unk3c;
    int unk40;
    SeqPtrArray m_kPlayingSequences;
};

struct SeqA34f20
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    char* m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    void* m_pInterpArray;
    void* m_pkIDTags;
    float m_fWeight;
    void* m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fScaledLastTime;
    SeqOwner* m_pkOwnerManager;
    int m_eAnimationState;
    float m_fSequenceOffset;
    float m_fStartTime;
    float m_fEndTime;
    float m_fDestinationFrame;
    SeqA34f20* m_pkTimeSyncSequence;

    bool CanSyncWithSequence(SeqA34f20* pkSequence);
    bool SetTimeSyncSequence(SeqA34f20* pkTimeSyncSeq);
    void SetAnimationCycleType(char m_ucRegionPriority);

    __forceinline bool SetState(int eState)
    {
        bool bWasInactive = m_eAnimationState == 0;
        m_eAnimationState = eState;
        if (bWasInactive)
        {
            m_pkOwnerManager->m_kPlayingSequences.AddSeq(this);
        }
        return bWasInactive;
    }

    bool StartSequence(char m_ucRegionPriority, bool bStartOver, float fWeight, float fEaseInTime,
                       SeqA34f20* pkTimeSyncSeq, bool bTransition);
};

// @fnv 0x00a34f20
bool SeqA34f20::StartSequence(char m_ucRegionPriority, bool bStartOver, float fWeight, float fEaseInTime,
                              SeqA34f20* pkTimeSyncSeq, bool bTransition)
{
    if (m_eAnimationState != 0)
        return false;

    m_pkTimeSyncSequence = 0;
    if (pkTimeSyncSeq)
    {
        SeqA34f20* pkPartner = pkTimeSyncSeq->m_pkTimeSyncSequence;
        if (pkPartner)
        {
            if (pkPartner == this || !CanSyncWithSequence(pkPartner))
                return false;
        }
        if (SetTimeSyncSequence(pkTimeSyncSeq))
            m_pkTimeSyncSequence = pkTimeSyncSeq;
        else
            return false;
    }

    m_fWeight = fWeight;
    SetAnimationCycleType(m_ucRegionPriority);

    if (fEaseInTime > 0.0f)
    {
        if (bTransition)
            SetState(5);
        else
            SetState(2);
        m_fStartTime = g_fSeqNegInfinity;
        m_fEndTime = fEaseInTime;
    }
    else
    {
        SetState(1);
        m_fStartTime = 0.0f;
    }

    if (bStartOver)
        m_fSequenceOffset = g_fSeqNegInfinity;
    m_fLastTime = g_fSeqNegInfinity;
    return true;
}

namespace fnv_00a351d0 {
static float NEG_FLT_MAX = -3.402823466e+38f;

struct SeqSet
{
    void Add(void* const& item);
};
struct SeqOwner
{
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
    SeqSet m_kActive;
};
struct CtlrSeq : BaseH
{
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual bool Deactivate(float fEaseOutTime, bool bTransition);
    unsigned int m_uiRefCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    float m_fDestWeight;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    float m_fWeightAdjustedLastTime;
    int unk38;
    int unk3C;
    SeqOwner* m_pkOwnerManager;
    int m_eAnimationState;
    float m_fSequenceOffset;
    float m_fStartTime;
    float m_fEndTime;
    int unk54;
    int m_pkTimeSyncSequence;

    bool Activate(char m_ucRegionPriority, bool bStartOver, float fWeight, float fEaseInTime, CtlrSeq* pkTimeSyncSeq,
                  bool bTransition);
    void SetPriorityStub(char m_ucRegionPriority);
    void SetState(int eState)
    {
        bool bWasInactive = (m_eAnimationState == 0);
        m_eAnimationState = eState;
        if (bWasInactive)
        {
            m_pkOwnerManager->m_kActive.Add((void* const&)(void*)this);
        }
    }
    bool CrossFadeTo(CtlrSeq* pkDestSequence, float fDuration, int iPriority, float fSourceWeight, float fDestWeight);
};

// @fnv 0x00a351d0
bool CtlrSeq::CrossFadeTo(CtlrSeq* pkDestSequence, float fDuration, int iPriority, float fSourceWeight,
                          float fDestWeight)
{
    Deactivate(0.0f, true);
    if (Activate((char)iPriority, false, fSourceWeight, fDuration, pkDestSequence, true) &&
        pkDestSequence->m_eAnimationState == 0)
    {
        pkDestSequence->m_fDestWeight = fDestWeight;
        pkDestSequence->m_pkTimeSyncSequence = 0;
        pkDestSequence->SetPriorityStub((char)iPriority);
        if (fDuration > 0.0f)
        {
            pkDestSequence->SetState(5);
            pkDestSequence->m_fStartTime = NEG_FLT_MAX;
            pkDestSequence->m_fEndTime = fDuration;
        }
        else
        {
            pkDestSequence->SetState(1);
            pkDestSequence->m_fStartTime = 0.0f;
        }
        pkDestSequence->m_fSequenceOffset = NEG_FLT_MAX;
        pkDestSequence->m_fWeightAdjustedLastTime = NEG_FLT_MAX;
        SetState(6);
        return true;
    }
    return false;
}
}  // namespace fnv_00a351d0

struct SomeObjectB3718
{
    virtual void V00();
    virtual void V01();
    virtual void V02(void* pv, unsigned int ItemUpdateArray, int iFlag);
};

struct HolderB3718
{
    SomeObjectB3718* m_pEntryObject;
};

extern HolderB3718* DAT_011f6080;

// @fnv 0x00aa10f0
void __cdecl FUN_00aa10f0(void* pv)
{
    if (pv != 0)
    {
        DAT_011f6080->m_pEntryObject->V02(pv, 9, -1);
    }
}

struct FUN_00a30750_shell
{
    char* m_kPointA[5];
    void FUN_00a30750();
};

extern int EmptyFS;

// @fnv 0x00a30750
void FUN_00a30750_shell::FUN_00a30750()
{
    char* p;
    p = m_kPointA[4];
    if (p != (char*)EmptyFS)
        InterlockedDecrement((long*)(p - 8));
    p = m_kPointA[3];
    if (p != (char*)EmptyFS)
        InterlockedDecrement((long*)(p - 8));
    p = m_kPointA[2];
    if (p != (char*)EmptyFS)
        InterlockedDecrement((long*)(p - 8));
    p = m_kPointA[1];
    if (p != (char*)EmptyFS)
        InterlockedDecrement((long*)(p - 8));
    p = m_kPointA[0];
    if (p != (char*)EmptyFS)
        InterlockedDecrement((long*)(p - 8));
}

struct EqObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual bool equal(EqObj* other);
};
struct TCEq
{
    bool IsSameAs(NiObject* other);
};
struct SeqTagCmp
{
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    bool equal(const SeqTagCmp& x) const
    {
        return a == x.a && b == x.b && c == x.c && d == x.d && e == x.e;
    }
};
extern "C" int __cdecl FUN_00aa1360(const char* a, const char* b);
struct SeqTK
{
    EqObj* p;
    operator EqObj*() const
    {
        return p;
    }
    EqObj* operator->() const
    {
        return p;
    }
};
struct SeqEqStand : SequenceA30970
{
    SeqTK& textKeys()
    {
        return *(SeqTK*)&textKeys20;
    }
    EqObj* owner40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    void* root5c;
    unsigned char FUN_00a30fb0(SeqEqStand* other);
};
// Compares this sequence with another field by field, including interpolators, tags, text keys and owner, returning true only if all match.
// @fnv 0x00a30fb0
unsigned char SeqEqStand::FUN_00a30fb0(SeqEqStand* other)
{
    if (!((TCEq*)this)->IsSameAs((NiObject*)other))
        return false;
    if (name08 != other->name08 && FUN_00aa1360(name08, other->name08))
        return false;
    if (arraySize0c != other->arraySize0c || arrayGrow10 != other->arrayGrow10)
        return false;
    for (unsigned int i = 0; i < arraySize0c; ++i)
    {
        if (!((FUN_00a30cc0_cls*)&interpolators14[i])->Equals((FUN_00a30cc0_cls*)&other->interpolators14[i]))
            return false;
        if (!((SeqTagCmp*)tags18)[i].equal(((SeqTagCmp*)other->tags18)[i]))
            return false;
    }
    if (weight1c != other->weight1c)
        return false;
    if ((textKeys() && !other->textKeys()) || (!textKeys() && other->textKeys()))
        return false;
    if (textKeys() && other->textKeys() && !textKeys()->equal(other->textKeys()))
        return false;
    if (cycleType24 != other->cycleType24)
        return false;
    if (frequency28 != other->frequency28 || begin2c != other->begin2c || end30 != other->end30)
        return false;
    if ((owner40 && !other->owner40) || (!owner40 && other->owner40))
        return false;
    if (owner40 && other->owner40 && !owner40->equal(other->owner40))
        return false;
    return root5c == other->root5c;
}

extern const char str_01020fd4[];
extern const char str_01020fc8[];
extern const char str_01020fc0[];
extern const char str_01020fb8[];
extern const char str_01020fac[];
extern const char str_01020fa0[];
extern const char str_01020f94[];
extern const char str_0109655c[];
struct S_00a31140_Allocator
{
    void* __thiscall FUN_00aa3e40(unsigned int);
};
extern "C" void __cdecl FUN_00ec623a(void*, const char*, const char*, const char*);
// @fnv 0x00a31140
void* __cdecl FormatStringWithType(const char* pcText, void* arg2)
{
    void* esi = ((S_00a31140_Allocator&)DAT_011f6238).FUN_00aa3e40((unsigned int)strlen(pcText) + 0x20);
    const char* eax = 0;
    switch ((unsigned int)arg2)
    {
    case 0:
        eax = str_01020fd4;
        break;
    case 1:
        eax = str_01020fc8;
        break;
    case 2:
        eax = str_01020fc0;
        break;
    case 3:
        eax = str_01020fb8;
        break;
    case 4:
        eax = str_01020fac;
        break;
    case 5:
        eax = str_01020fa0;
        break;
    case 6:
        eax = str_01020f94;
        break;
    default:
        break;
    }
    FUN_00ec623a(esi, str_0109655c, pcText, eax);
    return esi;
}

// Copy a group of five ref-counted fixed strings (the ref count sits 8 bytes before the text).

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

extern char* g_pcA1400NullString;

class A1400FixedString
{
  public:
    A1400FixedString& operator=(const A1400FixedString& kOther)
    {
        if (m_pcHandle != kOther.m_pcHandle)
        {
            char* pcNew = kOther.m_pcHandle;
            if (pcNew != g_pcA1400NullString)
                InterlockedIncrement((long volatile*)(pcNew - 8));
            if (m_pcHandle != g_pcA1400NullString)
                InterlockedDecrement((long volatile*)(m_pcHandle - 8));
            m_pcHandle = pcNew;
        }
        return *this;
    }

    char* m_pcHandle;
};

class A1400StringGroup
{
  public:
    A1400FixedString m_kName0;
    A1400FixedString m_kName1;
    A1400FixedString m_kName2;
    A1400FixedString m_kName3;
    A1400FixedString m_kName4;

    A1400StringGroup& FUN_00a31400(const A1400StringGroup& kOther);
};

// Assigns each of the five fixed-string members from kOther and returns *this.
// @fnv 0x00a31400
A1400StringGroup& A1400StringGroup::FUN_00a31400(const A1400StringGroup& kOther)
{
    m_kName0 = kOther.m_kName0;
    m_kName1 = kOther.m_kName1;
    m_kName2 = kOther.m_kName2;
    m_kName3 = kOther.m_kName3;
    m_kName4 = kOther.m_kName4;
    return *this;
}

struct IStreamA33a50
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(IStreamA33a50*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* pv, unsigned int uiBytes)
    {
        unsigned int uiComponentSize = uiBytes;
        m_uiStreamFlags += m_pfnRead(this, pv, uiBytes, &uiComponentSize, 1);
    }
};
struct StreamA33a50
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    unsigned int m_uiNifVersion;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    IStreamA33a50* m_pUnderlyingStream;
    void ReadFixedString(char*& kString);
    unsigned int ReadLinkIDA33a50();
    void ReadStringTableEntry(char*& kString);
};
struct IDTagA33a50
{
    char* m_kAVObjectName;
    char* m_kPropertyType;
    char* m_kCtlrType;
    char* m_kCtlrID;
    char* m_kInterpolatorID;
    void ReadFromStream(StreamA33a50& kStream, unsigned int& uiPaletteLink);
};

// @fnv 0x00a33a50
void IDTagA33a50::ReadFromStream(StreamA33a50& kStream, unsigned int& uiPaletteLink)
{
    if (kStream.m_uiNifVersion < 0x0A010071)
    {
        kStream.ReadFixedString(m_kAVObjectName);
        kStream.ReadFixedString(m_kPropertyType);
        kStream.ReadFixedString(m_kCtlrType);
        kStream.ReadFixedString(m_kCtlrID);
        kStream.ReadFixedString(m_kInterpolatorID);
    }
    else if (kStream.m_uiNifVersion < 0x14010001)
    {
        uiPaletteLink = kStream.ReadLinkIDA33a50();
        unsigned int uiAVObjectNameOffset = 0;
        unsigned int uiPropertyTypeOffset = 0;
        unsigned int uiCtlrTypeOffset = 0;
        unsigned int uiCtlrIDOffset = 0;
        unsigned int uiInterpolatorIDOffset = 0;
        kStream.m_pUnderlyingStream->Read(&uiAVObjectNameOffset, 4);
        kStream.m_pUnderlyingStream->Read(&uiPropertyTypeOffset, 4);
        kStream.m_pUnderlyingStream->Read(&uiCtlrTypeOffset, 4);
        kStream.m_pUnderlyingStream->Read(&uiCtlrIDOffset, 4);
        kStream.m_pUnderlyingStream->Read(&uiInterpolatorIDOffset, 4);
        m_kAVObjectName = (char*)uiAVObjectNameOffset;
        m_kPropertyType = (char*)uiPropertyTypeOffset;
        m_kCtlrType = (char*)uiCtlrTypeOffset;
        m_kCtlrID = (char*)uiCtlrIDOffset;
        m_kInterpolatorID = (char*)uiInterpolatorIDOffset;
    }
    else
    {
        kStream.ReadStringTableEntry(m_kAVObjectName);
        kStream.ReadStringTableEntry(m_kPropertyType);
        kStream.ReadStringTableEntry(m_kCtlrType);
        kStream.ReadStringTableEntry(m_kCtlrID);
        kStream.ReadStringTableEntry(m_kInterpolatorID);
    }
}

struct AnimationSequence;
struct UpdateActiveArray
{
    void FindOrAdd(AnimationSequence* const& sequence);
};
struct UpdateNote
{
    int unk00;
    int unk04;
    int unk08;
    float time;
};
struct UpdateNoteManager
{
    void DispatchByKey(UpdateNote* note);
};
struct UpdateOwner
{
    int unk00;
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
    int unk3c;
    int unk40;
    UpdateActiveArray active;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    UpdateNoteManager* noteManager;
};
struct AnimationSequence : S_00a30880_Base
{
    unsigned int refs;
    char* name;
    unsigned int count;
    unsigned int grow;
    void* interpolators;
    void* tags;
    float weight;
    void* keys;
    int cycle;
    float frequency;
    float begin;
    float end;
    float lastTime;
    float weightedTime;
    float scaledTime;
    UpdateOwner* owner;
    int state;
    float offset;
    float startTime;
    float endTime;
    float destFrame;
    AnimationSequence* partner;
    char* root;
    int unk60;
    int unk64;
    short noteIndex;
    unsigned short unk6a;
    UpdateNote** notes;
    unsigned short noteCount;
    float GetMorphedTime(AnimationSequence*, float);
    float FUN_00a30970(float, bool);
    void FUN_00a32290(float, float, float);
    void FUN_00a34ba0(float time, bool update);
    __forceinline bool SetState(int value)
    {
        bool inactive = state == 0;
        state = value;
        if (inactive)
        {
            AnimationSequence* self = this;
            owner->active.FindOrAdd(self);
        }
        return inactive;
    }
};
// @fnv 0x00a34ba0
void AnimationSequence::FUN_00a34ba0(float time, bool update)
{
    if (state == 0)
    {
        noteIndex = -1;
        return;
    }
    if (offset == g_fSeqNegInfinity)
        offset = -time;
    if (startTime == g_fSeqNegInfinity)
    {
        startTime = time;
        endTime += time;
    }
    float ease = 1.0f;
    float transition = 1.0f;
    switch (state)
    {
    case 2:
        if (endTime > time)
        {
            if (startTime > time)
                time = startTime;
            ease = (time - startTime) / (endTime - startTime);
        }
        else
        {
            state = 1;
            startTime = 0.0f;
        }
        break;
    case 5:
        if (endTime > time)
        {
            if (startTime > time)
                time = startTime;
            transition = (time - startTime) / (endTime - startTime);
        }
        else
        {
            if (destFrame != g_fSeqNegInfinity)
            {
                offset = destFrame - time;
                destFrame = DAT_01015f5c;
            }
            state = 1;
            startTime = 0.0f;
        }
        break;
    case 3:
        if (endTime > time)
        {
            if (startTime > time)
                time = startTime;
            ease = (endTime - time) / (endTime - startTime);
        }
        else
        {
            Target(0.0f, false);
            return;
        }
        break;
    case 6: {
        float partnerTime = partner->GetMorphedTime(this, time + offset);
        partnerTime /= partner->frequency;
        partner->offset = partnerTime - time;
        SetState(4);
    }
    case 4:
        if (endTime > time)
        {
            if (startTime > time)
                time = startTime;
            transition = (endTime - time) / (endTime - startTime);
        }
        else
        {
            Target(0.0f, true);
            return;
        }
        break;
    case 1:
        startTime = scaledTime;
        break;
    }
    float fOldScaledTime = scaledTime;
    if (update)
    {
        float localTime;
        if (destFrame != g_fSeqNegInfinity)
            localTime = destFrame;
        else if (partner)
        {
            if (partner->lastTime != time + partner->offset)
                partner->FUN_00a34ba0(time, false);
            localTime = GetMorphedTime(partner, time + partner->offset);
            localTime /= frequency;
        }
        else
            localTime = time + offset;
        FUN_00a32290(weight * transition, ease, FUN_00a30970(localTime, true));
        if (notes)
        {
            if (fOldScaledTime > scaledTime)
                noteIndex = -1;
            for (short i = noteIndex + 1; i < noteCount; ++i)
            {
                if (!(notes[i]->time < localTime))
                    break;
                noteIndex = i;
                owner->noteManager->DispatchByKey(notes[i]);
            }
        }
    }
}

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct RefObject
{
    virtual void Virtual0();
    virtual void Release();
    volatile long referenceCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            Release();
    }
    void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }
};

struct NiPointerRef
{
    RefObject* m_pObject;
    void operator=(RefObject* p)
    {
        RefObject* pOld = m_pObject;
        RefObject* pNew = p;
        if (pOld != pNew)
        {
            if (pOld)
                pOld->DecRefCount();
            m_pObject = pNew;
            if (pNew)
                pNew->IncRefCount();
        }
    }
};

struct NiItem
{
    unsigned int m0;
    NiPointerRef object4;
    unsigned int m8;
    unsigned int mc;
};

struct NiSequenceSource
{
    unsigned int unk00;
    unsigned int type04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int versionD8;
    RefObject* __thiscall FUN_00a63430();
};

struct SequenceLink : NiObject
{
    unsigned int unk08;
    unsigned int count0c;
    unsigned int unk10;
    NiItem* items14;
    unsigned int unk18;
    unsigned int unk1c;
    NiPointerRef object20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    RefObject* object40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    NiPointerRef* objects6c;
    unsigned short count70;
    void __thiscall LinkSequenceSource(NiSequenceSource*);
};

// @fnv 0x00a326e0
void SequenceLink::LinkSequenceSource(NiSequenceSource* source)
{
    NiObject::LinkObject(*(NiStream*)source);
    if (source->versionD8 < 0x0a010068)
    {
        object20 = source->FUN_00a63430();
        unsigned int i = 0;
        if (i < count0c)
        {
            do
            {
                items14[i].object4 = source->FUN_00a63430();
                ++i;
            } while (i < count0c);
        }
    }
    else
    {
        object20 = source->FUN_00a63430();
        object40 = source->FUN_00a63430();
        if (source->type04 > 0x15 && source->type04 < 0x1d)
        {
            source->FUN_00a63430();
            objects6c = 0;
            count70 = 0;
        }
        if (source->type04 > 0x1c)
        {
            unsigned short i = 0;
            if (i < count70)
            {
                do
                {
                    objects6c[i] = source->FUN_00a63430();
                    ++i;
                } while (i < count70);
            }
        }
    }
}

extern int(__stdcall* DAT_00fdf1c0)(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct A33950RefObject
{
    virtual void Unused();
    virtual void Release();
    volatile long refCount;
};

struct A33950BinaryInput
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* readFn)(A33950BinaryInput*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* destination, unsigned int bytes)
    {
        unsigned int componentSize = bytes;
        position += readFn(this, destination, bytes, &componentSize, 1);
    }
};

struct A33950Stream
{
    A33950RefObject* FUN_00a64620();
    unsigned int& Version()
    {
        return *(unsigned int*)((char*)this + 0xd8);
    }
    unsigned int& Count()
    {
        return *(unsigned int*)((char*)this + 4);
    }
    A33950BinaryInput* Input()
    {
        return *(A33950BinaryInput**)((char*)this + 0x24c);
    }
};

struct A33950Object
{
    A33950RefObject* first;
    A33950RefObject* second;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char flag0d;
    void LoadFromStream(A33950Stream* stream);
};

// @fnv 0x00a33950
void A33950Object::LoadFromStream(A33950Stream* stream)
{
    A33950RefObject* next = stream->FUN_00a64620();
    A33950RefObject* previous = first;
    if (previous != next)
    {
        if (previous && InterlockedDecrement(&previous->refCount) == 0)
            previous->Release();
        first = next;
        if (next)
            DAT_00fdf1c0((void*)&next->refCount);
    }

    next = stream->FUN_00a64620();
    previous = second;
    if (previous != next)
    {
        if (previous && InterlockedDecrement(&previous->refCount) == 0)
            previous->Release();
        second = next;
        if (next)
            DAT_00fdf1c0((void*)&next->refCount);
    }

    if (stream->Version() < 0x0a01006f)
    {
        unsigned short oldValue;
        stream->FUN_00a64620();
        stream->Input()->Read(&oldValue, 2);
    }
    if (stream->Count() > 0)
        stream->Input()->Read(&flag0d, 1);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);

struct FUN_00a344f0_cls
{
    void __thiscall FUN_00a33570(void* obj, unsigned int param);
    void* FUN_00a344f0(unsigned int param);
};

// @fnv 0x00a344f0
void* FUN_00a344f0_cls::FUN_00a344f0(unsigned int param)
{
    void* p = FUN_00aa13e0(0x74);
    void* result = p ? ((FUN_00a316a0_shell*)p)->FUN_00a316a0() : 0;
    this->FUN_00a33570(result, param);
    return result;
}

extern const float DAT_010141cc;

struct FUN_00a350d0_seq : SeqA34f20
{
    bool FUN_00a350d0(SeqA34f20* pkTarget, float fTime, float m_fTimeout, int iPriority, float fSeqWeight,
                      float fTargetWeight, SeqA34f20* pkPartner);
};

// @fnv 0x00a350d0
bool FUN_00a350d0_seq::FUN_00a350d0(SeqA34f20* pkTarget, float fTime, float m_fTimeout, int iPriority, float fSeqWeight,
                                    float fTargetWeight, SeqA34f20* pkPartner)
{
    ((S_00a30880_Base*)this)->Target(0.0f, 1);

    if (fTime <= 0.0f)
        fTime = DAT_010141cc;

    if (pkTarget->m_eAnimationState != 0 || m_eAnimationState != 0)
        return false;

    m_fWeight = fSeqWeight;
    m_pkTimeSyncSequence = 0;

    SetAnimationCycleType((char)iPriority);
    SetState(1);

    m_fStartTime = 0.0f;
    m_fLastTime = DAT_01015f5c;

    if (!pkTarget->StartSequence((char)iPriority, false, fTargetWeight, fTime, pkPartner, true))
        return false;

    ((S_00a30880_Base*)this)->Target(fTime, 1);

    m_fDestinationFrame = m_fScaledLastTime / m_fFrequency;
    pkTarget->m_fDestinationFrame = m_fTimeout / pkTarget->m_fFrequency;
    return true;
}

struct NiGlobalStringTable
{
    static char* AddString(const char* pcString);
};
extern char* g_kNullStringHandle;

struct NiStringPalette
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    char* m_pString;
};

struct OffsetString
{
    char* m_kHandle;
    static void DecRefHandle(char* h)
    {
        if (h != g_kNullStringHandle)
            InterlockedDecrement((long volatile*)(h - 8));
    }
    OffsetString& operator=(const char* pcString)
    {
        if (m_kHandle != pcString)
        {
            char* pcOld = m_kHandle;
            m_kHandle = NiGlobalStringTable::AddString(pcString);
            DecRefHandle(pcOld);
        }
        return *this;
    }
};

struct SeqIDTagOffsets
{
    OffsetString m_kAVObjectName;
    OffsetString m_kPropertyType;
    OffsetString m_kCtlrType;
    OffsetString m_kCtlrID;
    OffsetString m_kInterpolatorID;
    void LoadFromPalette(NiStringPalette* pkPalette, int iUnused);
};

// Resolves five string offsets against pkPalette->m_pString, assigning each to the matching OffsetString field when the offset is not -1.
// @fnv 0x00a30d40
void SeqIDTagOffsets::LoadFromPalette(NiStringPalette* pkPalette, int iUnused)
{
    int iAVObjectNameOffset = (int)m_kAVObjectName.m_kHandle;
    int iPropertyTypeOffset = (int)m_kPropertyType.m_kHandle;
    int iCtlrTypeOffset = (int)m_kCtlrType.m_kHandle;
    int iCtlrIDOffset = (int)m_kCtlrID.m_kHandle;
    int iInterpolatorIDOffset = (int)m_kInterpolatorID.m_kHandle;
    char* pcNullHandle = g_kNullStringHandle;
    OffsetString* apkOffsets[5] = {&m_kAVObjectName, &m_kPropertyType, &m_kCtlrType, &m_kCtlrID, &m_kInterpolatorID};
    for (int i = 0; i < 5; i++)
        apkOffsets[i]->m_kHandle = pcNullHandle;

    if (iAVObjectNameOffset != -1)
        m_kAVObjectName = pkPalette->m_pString + iAVObjectNameOffset;
    if (iPropertyTypeOffset != -1)
        m_kPropertyType = pkPalette->m_pString + iPropertyTypeOffset;
    if (iCtlrTypeOffset != -1)
        m_kCtlrType = pkPalette->m_pString + iCtlrTypeOffset;
    if (iCtlrIDOffset != -1)
        m_kCtlrID = pkPalette->m_pString + iCtlrIDOffset;
    if (iInterpolatorIDOffset != -1)
        m_kInterpolatorID = pkPalette->m_pString + iInterpolatorIDOffset;

    OffsetString::DecRefHandle(pcNullHandle);
}

__declspec(dllimport) long __stdcall InterlockedDecrement(long* plAddend);

struct A31500Ref
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
};

struct A31500Item
{
    A31500Ref* m_spControllerInterpolator;
    A31500Ref* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned int m_uiValue1;

    static void Release(A31500Ref* pkObject)
    {
        if (pkObject && InterlockedDecrement(&pkObject->m_uiRefCount) == 0)
            pkObject->DeleteThis();
    }

    void ReleaseRefs();
    A31500Item* FUN_00a31500(unsigned char m_ucEntryType);
};

// Releases references for this item or preceding items, conditionally calls another function, and returns this or the count address.
// @fnv 0x00a31500
A31500Item* A31500Item::FUN_00a31500(unsigned char m_ucEntryType)
{
    if (m_ucEntryType & 2)
    {
        int* piItemCount = reinterpret_cast<int*>(this) - 1;
        int iItemCount = *piItemCount;
        A31500Item* pkItem = this + iItemCount;
        while (--iItemCount >= 0)
        {
            --pkItem;
            Release(pkItem->m_pkController);
            Release(pkItem->m_spControllerInterpolator);
        }
        if (m_ucEntryType & 1)
            DAT_011f6238.FUN_00aa4060(piItemCount);
        return reinterpret_cast<A31500Item*>(piItemCount);
    }
    ReleaseRefs();
    if (m_ucEntryType & 1)
        DAT_011f6238.FUN_00aa4060(this);
    return this;
}

struct Rtti31910
{
    const char* name;
    Rtti31910* parent;
};
struct Node31910;
struct Blend31910
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char flags;
};
struct BlendTransform31910
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char flags;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct MorphItem31910
{
    int unk00;
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
    int unk3c;
    const char* name;
};
struct Morph31910
{
    int unk00;
    int unk04;
    int unk08;
    MorphItem31910* items;
    unsigned int count;
};
struct Node31910
{
    virtual void V00();
    virtual void V01();
    virtual Rtti31910* GetRTTI();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual Node31910* FindObject(const void*);
    virtual void V36();
    virtual void V37();
    virtual void SetTarget(Node31910*);
    long refCount;
    union
    {
        const char* name;
        unsigned short flags08;
    };
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned int flags30;

    Node31910* FUN_00a5c570(const void*);
    void FUN_00a5c480(Node31910*);
    unsigned int FUN_00dbbc10();
};
struct NiSingleInterpControllerBase : Node31910
{
    NiSingleInterpControllerBase();
};
struct Controller31910 : NiSingleInterpControllerBase
{
    BlendTransform31910* blends;
    Node31910** targets;
    unsigned short count;
    unsigned short unk3e;
    void FUN_00a2feb0(unsigned short);
    unsigned short FindIndexByValue(Node31910*);
    unsigned short FUN_00a35fe0(Node31910*, unsigned short, MorphItem31910*);
    void SetSlotEntry(unsigned short, Node31910*, unsigned short, MorphItem31910*);
    Blend31910* FUN_00a358a0(unsigned short);
    Controller31910* FUN_00a36070(unsigned short, unsigned short);
};
struct Owner31910
{
    int unk00;
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
    Node31910* root;
    Node31910* controller;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    unsigned char skipAccum;
};
struct Entry31910
{
    Morph31910* interpolator;
    Node31910* controller;
    Blend31910* blend;
    unsigned char index;
    unsigned char priority;
    unsigned short unk0e;
};
struct Sequence31910
{
    void* vtable;
    int refs;
    const char* name;
    unsigned int count;
    unsigned int grow;
    Entry31910* entries;
    TagItem* tags;
    float weight;
    void* keys;
    int cycle;
    float frequency;
    float begin;
    float end;
    float last;
    float weighted;
    float scaled;
    Owner31910* owner;
    int state;
    float offset;
    float start;
    float stop;
    float dest;
    void* partner;
    const char* rootName;
    Node31910* accum;
    bool FUN_00a31910(Node31910*, Node31910*, int);
};
extern Rtti31910 DAT_011f36bc, DAT_011f36e4, DAT_011f4a04, g_011f36ec;
extern unsigned int DAT_011f36c8, DAT_011f36d0;
extern const char* DAT_011f36c4;
extern const char* DAT_011f36cc;
extern const char DAT_01096564, DAT_0101e460;
extern unsigned short DAT_01096320;
extern void* DAT_01096444;
char* __cdecl FUN_00a5b690(const char*);
void __cdecl FUN_00fdad60();
void __cdecl FUN_00fdad80();
extern "C" int __cdecl atexit(void(__cdecl*)());
void* __cdecl FUN_00aa13e0(unsigned int);
struct NiMultiTargetTransformController : Controller31910
{
    virtual void V00();
    NiMultiTargetTransformController(unsigned short n)
    {
        count = 0;
        blends = 0;
        targets = 0;
        FUN_00a2feb0(n);
    }
};
void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
static bool IsKind31910(Node31910* node, Rtti31910* type)
{
    Rtti31910* rtti = node->GetRTTI();
    while (rtti)
    {
        if (rtti == type)
            return true;
        rtti = rtti->parent;
    }
    return false;
}
static void Retain31910(Node31910* p)
{
    if (p)
        InterlockedIncrement(&p->refCount);
}
static void Release31910(Node31910* p)
{
    if (p && !InterlockedDecrement(&p->refCount))
        p->V01();
}
struct ControllerPtr31910
{
    Controller31910* p;
    ControllerPtr31910(Controller31910* v) : p(v)
    {
        Retain31910(p);
    }
    operator Controller31910*() const
    {
        return p;
    }
    Controller31910* operator->() const
    {
        return p;
    }
    ControllerPtr31910& operator=(Controller31910* v)
    {
        if (p != v)
        {
            Release31910(p);
            p = v;
            Retain31910(p);
        }
        return *this;
    }
};
static void Assign31910(Node31910*& dst, Node31910* src)
{
    if (dst != src)
    {
        Release31910(dst);
        dst = src;
        Retain31910(src);
    }
}
static const char* MorphType31910()
{
    if (!(DAT_011f36c8 & 1))
    {
        DAT_011f36c8 |= 1;
        DAT_011f36c4 = FUN_00a5b690(&DAT_01096564);
        atexit(FUN_00fdad60);
    }
    return DAT_011f36c4;
}
static __forceinline unsigned short FindTarget31910(Controller31910* c, Node31910* node)
{
    for (unsigned short i = 0; i < c->count; ++i)
        if (c->targets[i] == node)
            return i;
    return DAT_01096320;
}
static __forceinline unsigned short AddTarget31910(Controller31910* c, Node31910* node)
{
    for (unsigned short i = 0; i < c->count; ++i)
        if (!c->targets[i])
        {
            c->targets[i] = node;
            node->flags30 |= 0x80;
            return i;
        }
    return DAT_01096320;
}
// @fnv 0x00a31910
bool Sequence31910::FUN_00a31910(Node31910* target, Node31910* root, int unused)
{
    bool spMorphController;
    spMorphController = false;
    Controller31910* ctrl = (Controller31910*)target->FUN_00a5c570(&DAT_011f36bc);
    Retain31910(ctrl);
    Controller31910* pMorphCtrl = (Controller31910*)target->FUN_00a5c570(&DAT_011f36e4);
    Retain31910(pMorphCtrl);
    unsigned short uiMorphEntries = 0, usMorphTargetCount = 0;
    for (unsigned int i = 0; i < count; i++)
    {
        TagItem& v = tags[i];
        if (v.third != (const char*)DAT_0109b220 && MorphType31910() == v.third)
        {
            usMorphTargetCount += (unsigned short)entries[i].interpolator->count;
            ++uiMorphEntries;
        }
    }
    if (!ctrl || (!pMorphCtrl && uiMorphEntries))
    {
        unsigned short usExistingTargets = 0;
        Node31910* morphIndex = 0;
        if (root)
        {
            morphIndex = IsKind31910(root, &DAT_011f4a04) ? root : 0;
        }
        if (morphIndex)
            usExistingTargets = (unsigned short)(morphIndex->FUN_00dbbc10() - usMorphTargetCount);
        else
            for (unsigned int i = 0; count > i; i++)
            {
                const char* cnt;
                cnt = tags[i].third;
                if (cnt != (const char*)DAT_0109b220 && cnt && cnt[2] == 'T' && cnt[7] == 'f')
                    usExistingTargets++;
            }
        if (!usExistingTargets && !uiMorphEntries)
        {
            Release31910(pMorphCtrl);
            Release31910(ctrl);
            return false;
        }
        if (usExistingTargets && !ctrl)
        {
            Controller31910* tag;
            tag = (Controller31910*)FUN_00aa13e0(0x40);
            if (tag)
            {
                ctrl = new (tag) NiMultiTargetTransformController(usExistingTargets);
                Retain31910(ctrl);
            }
            ctrl->SetTarget(target);
            ctrl->flags08 |= 0x20;
            spMorphController = true;
            if (target == owner->root)
            {
                target->FUN_00a5c480(ctrl);
                Assign31910((Node31910*&)ctrl->flags30, owner->controller);
                Assign31910(owner->controller, ctrl);
            }
        }
        if (uiMorphEntries && !pMorphCtrl)
        {
            Controller31910* tag = (Controller31910*)FUN_00aa13e0(0x44);
            if (tag)
            {
                tag = tag->FUN_00a36070(uiMorphEntries, usMorphTargetCount);
                if (tag)
                {
                    pMorphCtrl = tag;
                    Retain31910(pMorphCtrl);
                }
            }
            pMorphCtrl->SetTarget(target);
            pMorphCtrl->flags08 |= 0x20;
            spMorphController = true;
            if (target == owner->root)
            {
                target->FUN_00a5c480(pMorphCtrl);
                Assign31910((Node31910*&)pMorphCtrl->flags30, owner->controller);
                Assign31910(owner->controller, pMorphCtrl);
            }
        }
    }
    int idx = 0;
    if (!(DAT_011f36d0 & 1))
    {
        DAT_011f36d0 |= 1;
        DAT_011f36cc = FUN_00a5b690(&DAT_0101e460);
        atexit(FUN_00fdad80);
    }
    for (unsigned int i = 0; i < count; i++)
    {
        Entry31910& entry = entries[i];
        TagItem& v = tags[i];
        if (v.third != (const char*)DAT_0109b220 && v.third && v.third[2] == 'T' && v.third[7] == 'f')
        {
            Node31910* spTransformController = root->FindObject(&v);
            if (!spTransformController || (accum == spTransformController && owner->skipAccum))
                continue;
            Node31910* z = spTransformController->FUN_00a5c570(&g_011f36ec);
            unsigned short s = FindTarget31910(ctrl, spTransformController);
            if (s == DAT_01096320)
            {
                s = AddTarget31910(ctrl, spTransformController);
                if (s == DAT_01096320)
                    continue;
            }
            else
            {
                ctrl->targets[s] = spTransformController;
                spTransformController->flags30 |= 0x80;
            }
            if (spTransformController->name != DAT_011f36cc)
                spTransformController->FUN_00a5c480(z);
            Assign31910(entry.controller, ctrl);
            entry.blend = (Blend31910*)&ctrl->blends[s];
            entry.blend->flags |= 1;
        }
        else if (v.third != (const char*)DAT_0109b220 && MorphType31910() == v.third)
        {
            Morph31910* interp = entry.interpolator;
            volatile unsigned int s;
            for (unsigned int j = 0; j < interp->count; j++)
            {
                MorphItem31910* item = &interp->items[j];
                Node31910* spTransformController = root->FindObject(&item->name);
                unsigned short usMorphSlot = pMorphCtrl->FindIndexByValue(spTransformController);
                if (usMorphSlot == DAT_01096320)
                    s = pMorphCtrl->FUN_00a35fe0(spTransformController, idx, item);
                else
                    pMorphCtrl->SetSlotEntry(usMorphSlot, spTransformController, idx, item);
            }
            Assign31910(entry.controller, pMorphCtrl);
            entry.blend = pMorphCtrl->FUN_00a358a0(idx);
            entry.blend->flags |= 1;
            idx += 1;
        }
    }
    Release31910(pMorphCtrl);
    Release31910(ctrl);
    return spMorphController;
}

struct TimedTextEntry
{
    float m_fTime;
    char* m_kText;

    float GetTime() const
    {
        return m_fTime;
    }
    const char* GetText() const
    {
        return m_kText;
    }
};

struct NiTextKeyExtraData
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    char* m_kName;
    unsigned int m_uiNumKeys;
    TimedTextEntry* m_pKeys;

    TimedTextEntry* GetKeys(unsigned int& uiNumKeys) const
    {
        uiNumKeys = m_uiNumKeys;
        return m_pKeys;
    }
};

extern const char* ms_kMorphTextKey;
extern int ms_iMorphTextKeyLength;
int __cdecl FUN_00aa1370(const char*, const char*, unsigned int);
int __cdecl FUN_00aa1360(const char*, const char*);

// Interpolates between matching key times in this sequence using surrounding morph-key times from the partner sequence.
// @fnv 0x00a32010
float AnimationSequence::GetMorphedTime(AnimationSequence* pkPartnerSequence, float fFrameTime)
{
    TimedTextEntry* pkNextKey = 0;
    float fPartnerTime = pkPartnerSequence->FUN_00a30970(fFrameTime, false);

    unsigned int uiNumPartnerKeys;
    TimedTextEntry* pkPartnerKeys = ((NiTextKeyExtraData*)pkPartnerSequence->keys)->GetKeys(uiNumPartnerKeys);

    TimedTextEntry* pkFirstKey = 0;
    TimedTextEntry* pkPrevKey = 0;
    TimedTextEntry* pkLastKey = 0;
    unsigned int ui;
    for (ui = 0; ui < uiNumPartnerKeys; ui++)
    {
        const char* pcText = pkPartnerKeys[ui].GetText();
        if (pcText && FUN_00aa1370(pcText, ms_kMorphTextKey, ms_iMorphTextKeyLength) == 0)
        {
            pkLastKey = &pkPartnerKeys[ui];
            if (!pkFirstKey)
                pkFirstKey = &pkPartnerKeys[ui];

            if (pkPartnerKeys[ui].GetTime() < fPartnerTime)
                pkPrevKey = &pkPartnerKeys[ui];
            else if (!pkNextKey)
                pkNextKey = &pkPartnerKeys[ui];
        }
    }

    bool bHasKeyPair = false;
    float fRatio;
    if (pkNextKey && pkPrevKey)
    {
        float fPriorKeyTime = pkPrevKey->GetTime();
        fRatio = (fPartnerTime - fPriorKeyTime) / (pkNextKey->GetTime() - fPriorKeyTime);
    }
    else if (!pkNextKey)
    {
        float fPriorKeyTime = pkPrevKey->GetTime();
        float fNextTime = pkPartnerSequence->end - pkPartnerSequence->begin + pkFirstKey->GetTime();
        fRatio = (fPartnerTime - fPriorKeyTime) / (fNextTime - fPriorKeyTime);
        pkNextKey = pkFirstKey;
        bHasKeyPair = true;
    }
    else
    {
        float fPriorKeyTime = pkPartnerSequence->begin - pkPartnerSequence->end + pkLastKey->GetTime();
        fRatio = (fPartnerTime - fPriorKeyTime) / (pkNextKey->GetTime() - fPriorKeyTime);
        pkPrevKey = pkLastKey;
    }

    unsigned int uiNumKeys;
    TimedTextEntry* pkKeys = ((NiTextKeyExtraData*)keys)->GetKeys(uiNumKeys);

    bool bFoundPrev = (pkPrevKey == 0);
    bool bFoundNext = (pkNextKey == 0);
    TimedTextEntry* pkMatchPrev = 0;
    TimedTextEntry* pkMatchNext = 0;
    for (ui = 0; ui < uiNumKeys; ui++)
    {
        if (bFoundPrev && bFoundNext)
            break;

        if (!bFoundPrev && FUN_00aa1360(pkKeys[ui].GetText(), pkPrevKey->GetText()) == 0)
        {
            pkMatchPrev = &pkKeys[ui];
            bFoundPrev = true;
        }
        if (!bFoundNext && FUN_00aa1360(pkKeys[ui].GetText(), pkNextKey->GetText()) == 0)
        {
            pkMatchNext = &pkKeys[ui];
            bFoundNext = true;
        }
    }

    float fNextTime = 0.0f;
    float fPriorKeyTime = 0.0f;
    if (pkMatchPrev == pkMatchNext)
    {
        fPriorKeyTime = pkMatchPrev->GetTime();
        fNextTime = pkMatchNext->GetTime();
        if (bHasKeyPair)
            fNextTime += end - begin;
        else
            fPriorKeyTime -= end - begin;
    }
    else
    {
        if (pkMatchNext)
            fNextTime = pkMatchNext->GetTime();
        if (pkMatchPrev)
            fPriorKeyTime = pkMatchPrev->GetTime();
        if (fPriorKeyTime > fNextTime)
            fNextTime += end - begin;
    }

    float fTime = fPriorKeyTime + (fNextTime - fPriorKeyTime) * fRatio;
    if (fTime < begin)
        fTime += end - begin;
    else if (fTime > end)
        fTime -= end - begin;
    return fTime;
}

struct CloneObject;
struct CloneMap
{
    bool FUN_00a53c30(CloneObject* const key, CloneObject*& val) const;
};
struct CloneContext
{
    CloneMap* map;
};
struct CloneObject
{
    virtual void v00();
    virtual void Release();
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
    virtual void ProcessClone(CloneContext&);
    long refs;
};
struct ClonePointer
{
    CloneObject* object;
    operator CloneObject*() const
    {
        return object;
    }
    bool operator==(const CloneObject* other) const
    {
        return object == other;
    }
    CloneObject* operator->() const
    {
        return object;
    }
    void Assign(CloneObject* other)
    {
        CloneObject* old = object;
        if (old != other)
        {
            if (old && !InterlockedDecrement(&old->refs))
                old->Release();
            object = other;
            if (other)
                InterlockedIncrement(&other->refs);
        }
    }
    void Assign(const ClonePointer& ptr)
    {
        CloneObject* old = object;
        if (old != ptr.object)
        {
            if (old && !InterlockedDecrement(&old->refs))
                old->Release();
            CloneObject* next = ptr.object;
            object = next;
            if (next)
                InterlockedIncrement(&next->refs);
        }
    }
    void AssignRef(CloneObject* const& other)
    {
        CloneObject* old = object;
        if (old != other)
        {
            if (old && !InterlockedDecrement(&old->refs))
                old->Release();
            CloneObject* next = other;
            object = next;
            if (next)
                InterlockedIncrement(&next->refs);
        }
    }
};
struct CloneItem
{
    ClonePointer interpolator;
    ClonePointer controller;
    void* blend;
    unsigned char index, priority, unk0e, unk0f;
    void FUN_00a5f860(void*);
    void FUN_00c663d0(const CloneItem&);
};
struct CloneSequence
{
    void* vtable;
    unsigned int refs;
    void* name;
    unsigned int count, grow;
    CloneItem* items;
    void* tags;
    float weight;
    void* text;
    int cycle;
    float frequency, begin, end, last, accumulated, scaled;
    void* owner;
    int state;
    float offset, startTime, endTime, destFrame;
    void* partner;
    void* root;
    void* object60;
    void FUN_00a5d430(CloneContext&);
    void FUN_00a32470(CloneContext&);
};
// Calls FUN_00a5d430, processes or looks up item objects, then assigns mapped or original pointers to the copy's fields.
// @fnv 0x00a32470
void CloneSequence::FUN_00a32470(CloneContext& context)
{
    FUN_00a5d430(context);
    CloneObject* clone = 0;
    context.map->FUN_00a53c30((CloneObject*)this, clone);
    CloneSequence* copy = (CloneSequence*)clone;
    for (unsigned int i = 0; i < count; ++i)
    {
        if (items[i].interpolator == 0)
            continue;
        CloneItem& item = items[i];
        if (!owner)
        {
            items[i].interpolator->ProcessClone(context);
            CloneObject* controller = items[i].controller;
            if (controller)
                controller->ProcessClone(context);
        }
        else
        {
            CloneObject* interp = item.interpolator;
            if (!state)
                interp->ProcessClone(context);
            else
            {
                bool found = context.map->FUN_00a53c30(interp, clone);
                CloneItem& dest = copy->items[i];
                if (found)
                    dest.FUN_00a5f860(clone);
                else
                    dest.FUN_00c663d0(items[i]);
            }
            if (context.map->FUN_00a53c30(items[i].controller, clone))
            {
                CloneObject* old = copy->items[i].controller;
                ClonePointer* volatile dest = &copy->items[i].controller;
                CloneObject* next = *(CloneObject* volatile*)&clone;
                if (old != next)
                {
                    if (old)
                    {
                        if (!InterlockedDecrement(&old->refs))
                            old->Release();
                        next = *(CloneObject* volatile*)&clone;
                    }
                    dest->object = next;
                    if (next)
                        InterlockedIncrement(&next->refs);
                }
            }
            else
                copy->items[i].controller.Assign(items[i].controller);
            if (context.map->FUN_00a53c30((CloneObject*)items[i].blend, clone))
                copy->items[i].blend = clone;
            else
                copy->items[i].blend = items[i].blend;
        }
    }
    if (context.map->FUN_00a53c30((CloneObject*)owner, clone))
        copy->owner = clone;
    else
        copy->owner = owner;
    if (context.map->FUN_00a53c30((CloneObject*)partner, clone))
        copy->partner = clone;
    else
        copy->partner = partner;
    if (context.map->FUN_00a53c30((CloneObject*)object60, clone))
        copy->object60 = clone;
    else
        copy->object60 = object60;
}

struct Ref43c
{
    virtual void v00();
    virtual void DeleteThis();
    unsigned int m_lRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_lRefCount) == 0)
            DeleteThis();
    }
};
struct Ctl43c
{
    void FUN_00a31500(int iFlags);
    void FUN_00a315b0(int iFlags);
};
struct Src43c
{
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned int m_uiCount;
    void* unk10;
    Ctl43c* m_pA;
    Ctl43c* m_pB;
    __declspec(noalias) void AssignInterpolatorRef(unsigned int i, Ref43c*& pOut);
};
struct Base43c
{
    void FUN_00a33570(Src43c* pkSrc, int iArg);
};
struct Obj43c : Base43c
{
    void ClearInterpolatorRefs(Src43c* pkSrc, int iArg);
};

// Releases each ref returned by pkSrc->AssignInterpolatorRef, calls both controller methods, then invokes the base handler.
// @fnv 0x00a343c0
void Obj43c::ClearInterpolatorRefs(Src43c* pkSrc, int iArg)
{
    for (unsigned int i = 0; i < pkSrc->m_uiCount; i++)
    {
        Ref43c* pObj = 0;
        pkSrc->AssignInterpolatorRef(i, pObj);
        if (pObj)
            pObj->DecRefCount();
    }
    if (pkSrc->m_pA)
        pkSrc->m_pA->FUN_00a31500(3);
    if (pkSrc->m_pB)
        pkSrc->m_pB->FUN_00a315b0(3);
    Base43c::FUN_00a33570(pkSrc, iArg);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_011f36dc;

struct DynCastHelper : RefBase
{
    long count;
    DynCastHelper* DynamicCast(const GlobalObjectO2_00a7b610*) throw();
    void IncRefCount() throw()
    {
        InterlockedIncrement(&count);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&count))
            Release();
    }
};

class NiNode : public DynCastHelper
{
};

template <class T> struct NiPointer
{
    T* p;
    NiPointer(T* object = 0) throw()
    {
        p = object;
        if (p)
            p->IncRefCount();
    }
    ~NiPointer() throw()
    {
        if (p)
            p->DecRefCount();
    }
    NiPointer& operator=(T* object) throw()
    {
        if (p != object)
        {
            if (p)
                p->DecRefCount();
            p = object;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
    NiPointer& operator=(const NiPointer& other) throw()
    {
        if (p != other.p)
        {
            if (p)
                p->DecRefCount();
            p = other.p;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
};

typedef NiPointer<NiNode> NiPtrNode;
typedef NiPointer<DynCastHelper> LegacyPtr;

struct BinaryDataRecord
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int version;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    DynCastHelper** objects;
    unsigned int unk224;
    unsigned int count;
};

struct S00a35700_NodeRef
{
    NiNode* p;
    S00a35700_NodeRef& operator=(NiNode* object);
};

extern "C" void __cdecl GetGPUProgram(BinaryDataRecord*, unsigned int, LegacyPtr*, unsigned int) throw();
extern "C" void __cdecl ConvertOldSequence(DynCastHelper*, S00a35700_NodeRef*) throw();

// Retrieves a NiNode by index from a BinaryDataRecord, using version-specific lookup, and assigns it to the output pointer with a reference count adjustment.
// @fnv 0x00a35700
void __cdecl FUN_00a35700(BinaryDataRecord* stream, unsigned int index, NiPtrNode& out)
{
    if (index >= stream->count)
    {
        out = 0;
        return;
    }
    NiNode* const null = 0;
    S00a35700_NodeRef a;
    a.p = null;
    if (stream->version < 0x5000000)
    {
        LegacyPtr b = null;
        GetGPUProgram(stream, index, &b, 0);
        ConvertOldSequence(b.p, &a);
    }
    else
    {
        DynCastHelper* value = stream->objects[index];
        a = value == null ? null : (NiNode*)value->DynamicCast(&g_011f36dc);
    }
    NiNode* p = a.p;
    out = p;
    if (p)
        p->DecRefCount();
}

struct ActiveArray
{
    void** items;
    unsigned int capacity;
    unsigned int size;
    void FUN_00a311e0(unsigned int);
    unsigned int Find(void* const& key) const
    {
        for (unsigned int i = 0; i < size; ++i)
            if (items[i] == key)
                return i;
        return (unsigned int)-1;
    }
    unsigned int FindOrAdd(void* const& key);
};
// Returns the index of key in items, or appends it (growing the array if full) and returns the new index.
// @fnv 0x00e7ec00
unsigned int ActiveArray::FindOrAdd(void* const& key)
{
    unsigned int i = Find(key);
    if (i != (unsigned int)-1)
        return i;
    if (size == capacity)
        FUN_00a311e0(capacity > 0 ? capacity * 2 : 1);
    unsigned int index = size;
    items[index] = key;
    ++size;
    return index;
}

#include <windows.h>
namespace fnv_00a30640 {
struct NiGlobalStringTable
{
    static char* __cdecl AddString(const char*);
};

extern char* EmptyFS;

struct NiStringPtr
{
    char* m_kHandle;
};

struct NiControllerSequence
{
    NiStringPtr m_kName;
    NiStringPtr m_kParentName;
    NiStringPtr m_kSourceName;
    NiStringPtr m_kTargetName;
    NiStringPtr m_kControllerName;
    void ResetStrings();
};

// For each non-null handle, assigns AddString(0)'s result and decrements the old handle's count when it differs from a global handle.
// @fnv 0x00a30640
void NiControllerSequence::ResetStrings()
{
    char* old = m_kName.m_kHandle;
    if (old != 0)
    {
        m_kName.m_kHandle = NiGlobalStringTable::AddString(0);
        if (old != EmptyFS)
            InterlockedDecrement((LONG*)(old - 8));
    }

    old = m_kParentName.m_kHandle;
    if (old != 0)
    {
        m_kParentName.m_kHandle = NiGlobalStringTable::AddString(0);
        if (old != EmptyFS)
            InterlockedDecrement((LONG*)(old - 8));
    }

    old = m_kSourceName.m_kHandle;
    if (old != 0)
    {
        m_kSourceName.m_kHandle = NiGlobalStringTable::AddString(0);
        if (old != EmptyFS)
            InterlockedDecrement((LONG*)(old - 8));
    }

    old = m_kTargetName.m_kHandle;
    if (old != 0)
    {
        m_kTargetName.m_kHandle = NiGlobalStringTable::AddString(0);
        if (old != EmptyFS)
            InterlockedDecrement((LONG*)(old - 8));
    }

    old = m_kControllerName.m_kHandle;
    if (old != 0)
    {
        m_kControllerName.m_kHandle = NiGlobalStringTable::AddString(0);
        if (old != EmptyFS)
            InterlockedDecrement((LONG*)(old - 8));
    }
}
}  // namespace fnv_00a30640

int __cdecl FUN_00aa1370(const char*, const char*, const char*);
extern const char* g_kTextKeyA;
extern const char* g_kTextKeyB;

struct NiControllerSequenceT
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    char* m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    void* m_pInterpArray;
    void* m_pkIDTags;
    float m_fWeight;
    NiTextKeyExtraData* m_spTextKeyData;
    bool MatchesTextKeys(NiControllerSequenceT* pkOther);
};

// Returns true when both sequences have eligible text keys and each eligible key occurs in the other sequence.
// @fnv 0x00a30ab0
bool NiControllerSequenceT::MatchesTextKeys(NiControllerSequenceT* pkOther)
{
    NiTextKeyExtraData* pkKeys = m_spTextKeyData;
    NiTextKeyExtraData* pkOtherKeys;
    if (!pkKeys || !(pkOtherKeys = pkOther->m_spTextKeyData))
        return false;

    unsigned int uiNumOther = pkOtherKeys->m_uiNumKeys;
    TimedTextEntry* pOther = pkOtherKeys->m_pKeys;
    unsigned int uiNumKeys = pkKeys->m_uiNumKeys;
    TimedTextEntry* pKeys = pkKeys->m_pKeys;

    bool bFound = false;
    unsigned int i;
    for (i = 0; i < uiNumOther; i++)
    {
        const char* pcText = pOther[i].m_kText;
        if (!FUN_00aa1370(pcText, g_kTextKeyA, g_kTextKeyB))
        {
            bFound = true;
            bool bMatch = false;
            for (unsigned int j = 0; j < uiNumKeys; j++)
            {
                if (strcmp(pcText, pKeys[j].m_kText) == 0)
                {
                    bMatch = true;
                    break;
                }
            }
            if (!bMatch)
                goto fail;
        }
    }
    if (!bFound)
        goto fail;
    bFound = false;
    for (i = 0; i < uiNumKeys; i++)
    {
        const char* pcText = pKeys[i].m_kText;
        if (!FUN_00aa1370(pcText, g_kTextKeyA, g_kTextKeyB))
        {
            bFound = true;
            bool bMatch = false;
            for (unsigned int j = 0; j < uiNumOther; j++)
            {
                if (strcmp(pcText, pOther[j].m_kText) == 0)
                {
                    bMatch = true;
                    break;
                }
            }
            if (!bMatch)
                goto fail;
        }
    }
    if (!bFound)
        goto fail;
    return true;
fail:
    return false;
}

struct StaticKeyB5652
{
    StaticKeyB5652(int v) throw()
    {
        m_00 = v;
    }
    ~StaticKeyB5652() throw()
    {}
    unsigned int m_00;
};

class NiRefStubB5652
{
  public:
    virtual void Slot0();
    virtual void Destroy();
    long m_iObjectReferenceCount;
};

class FUN_00a32940_cls
{
  public:
    unsigned int unk00;
    NiRefStubB5652** m_04;
    unsigned short unk08;
    unsigned short m_0a;
    unsigned short m_0c;
    void SetEntry(unsigned int idx, NiRefStubB5652** a2);
};

// Stores a NiRefStubB5652 pointer at index idx in m_04, updating m_0a, m_0c and reference counts as needed.
// @fnv 0x00a32940
void FUN_00a32940_cls::SetEntry(unsigned int uiIndex, NiRefStubB5652** apNewStub)
{
    static StaticKeyB5652 key(0);
    if (uiIndex >= m_0a)
    {
        m_0a = (unsigned short)(uiIndex + 1);
        if ((unsigned int)*apNewStub == key.m_00)
        {
        }
        else
        {
            m_0c++;
        }
    }
    else
    {
        if ((unsigned int)*apNewStub != key.m_00)
        {
            if ((unsigned int)m_04[uiIndex] == key.m_00)
            {
                m_0c++;
            }
        }
        else
        {
            if ((unsigned int)m_04[uiIndex] != key.m_00)
            {
                m_0c--;
            }
        }
    }
    NiRefStubB5652** slot = &m_04[uiIndex];
    NiRefStubB5652* old = *slot;
    if (old != *apNewStub)
    {
        if (old != 0)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
            {
                old->Destroy();
            }
        }
        NiRefStubB5652* pNewStub = *apNewStub;
        *slot = pNewStub;
        if (pNewStub != 0)
        {
            InterlockedIncrement(&pNewStub->m_iObjectReferenceCount);
        }
    }
}

struct BindObj;
struct BindCtrl;
struct Blend;
struct ObjPtr
{
    BindObj* ptr;
    operator BindObj*() const
    {
        return ptr;
    }
    BindObj* operator->() const
    {
        return ptr;
    }
};
struct PropLink
{
    PropLink* next;
    int unk04;
    ObjPtr object;
};
inline ObjPtr& NextProperty(PropLink*& pos)
{
    ObjPtr& value = pos->object;
    pos = pos->next;
    return value;
}
struct BindObj
{
    virtual void V0();
    virtual void V1();
    virtual const char** GetType();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual BindObj* Find(const char** name);
    virtual void V36();
    virtual void V37();
    virtual void SetTarget(BindObj* obj);
    virtual void V39();
    virtual void Update(bool*, int, bool*);
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual unsigned short FindIndex(const char*);
    virtual void V48();
    virtual Blend* GetBlend(unsigned short);
    virtual void SetBlend(Blend*, unsigned short);
    virtual bool Supports(BindObj*);
    virtual const char* GetID();
    virtual void V53();
    virtual void V54();
    virtual Blend* MakeBlend(unsigned short, bool, bool, float, int);
    void FUN_00a5c480(BindCtrl*);
    int refs;
    unsigned short flags;
    unsigned short unk0a;
    BindCtrl* controllers;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    PropLink* properties;
    int unk28;
    int unk2c;
    BindCtrl* next;
};
struct BindCtrl : BindObj
{
    void FUN_00a67260(BindCtrl*);
};
struct Blend
{
    Blend* FUN_00653290(const void*);
};
extern const int DAT_011f36fc;
extern int DAT_0109b220;

struct BindOwner
{
    int unk00;
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
    BindObj* target;
    BindCtrl* program;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    bool managerFlag;
    int unk6c;
    int unk70;
    int unk74;
    BindObj* root;
};
struct CtrlPtr
{
    BindCtrl* ptr;
    void FUN_0066b0d0(BindCtrl*);
};
struct BindItem
{
    BindObj* interpolator;
    CtrlPtr controller;
    Blend* blend;
    unsigned int settings;
};
struct BindTag
{
    const char* object;
    const char* property;
    const char* type;
    const char* id;
    const char* interpolator;
};
struct BindSequence
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int count;
    int unk10;
    BindItem* items;
    BindTag* tags;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    BindOwner* owner;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    const char* rootName;
    BindObj* accumRoot;
    int unk64;
    int unk68;
    int unk6c;
    unsigned short unk70;
    bool missing;
    bool Attach(bool, BindObj*, bool);
    bool FUN_00a32c70(bool arg);
};
// Resolves interpolators, objects, and controllers for each BindItem, creating blends and updating the owner's target.
// @fnv 0x00a32c70
bool BindSequence::FUN_00a32c70(bool abUpdate)
{
    BindObj* root = owner->root;
    if (rootName != (const char*)DAT_0109b220)
        accumRoot = root->Find(&rootName);
    abUpdate = Attach(abUpdate, root, false);
    for (unsigned int index = 0; index < count; ++index)
    {
        BindObj* interpolator = items[index].interpolator;
        if (!interpolator)
            continue;
        BindTag& tag = tags[index];
        if (!interpolator->Supports(root) || items[index].blend)
            continue;
        BindObj* object = root->Find(&tag.object);
        if (object && tag.property)
        {
            PropLink* link = object->properties;
            while (link)
            {
                BindObj* property = NextProperty(link);
                const char* propertyType = tag.property;
                if (!strcmp(*property->GetType(), propertyType))
                {
                    object = property;
                    break;
                }
            }
        }
        if (!object)
        {
            if (*(const unsigned short*)tag.object == 0x2323)
                missing = true;
            continue;
        }
        BindCtrl* controller = object->controllers;
        while (controller)
        {
            const char* controllerType = tag.type;
            if (!strcmp(*controller->GetType(), controllerType))
            {
                const char* id = controller->GetID();
                if ((!id && !tag.id) || (id && tag.id && !strcmp(id, tag.id)))
                    break;
            }
            controller = controller->next;
        }
        if (!controller)
        {
            controller = items[index].controller.ptr;
            if (!controller)
                continue;
            controller->SetTarget(object);
            abUpdate = true;
            if (object == owner->target)
            {
                object->FUN_00a5c480(controller);
                controller->FUN_00a67260(owner->program);
                ((BindCtrl*)owner)->FUN_00a67260(controller);
            }
        }
        const char* interpolatorName = tag.interpolator;
        unsigned short interpIndex = controller->FindIndex(interpolatorName);
        if (interpIndex == DAT_01096320)
            continue;
        {
            Blend* blend = controller->GetBlend(interpIndex);
            if (!blend)
                blend = 0;
            else
                blend = blend->FUN_00653290(&DAT_011f36fc);
            bool special = false;
            if (accumRoot == object && owner->managerFlag)
                special = true;
            if (!blend)
            {
                blend = controller->MakeBlend(interpIndex, true, special, 0.0f, 2);
                controller->SetBlend(blend, interpIndex);
                if (!blend)
                    continue;
            }
            controller->flags |= 0x20;
            items[index].controller.FUN_0066b0d0(controller);
            items[index].blend = blend;
        }
    }
    if (abUpdate)
    {
        bool result;
        owner->target->Update(&result, 1, &abUpdate);
    }
    return true;
}

extern int DAT_011f49e0;
extern char DAT_01096614;

struct Controller33130
{
    virtual void V00();
    virtual void V01();
    virtual const char** V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual unsigned short V45();
    virtual const char* V46(unsigned int);
    virtual void V47();
    virtual void V48();
    virtual RefObj* V49(unsigned int);
    virtual void V50();
    virtual void V51();
    virtual const char* V52();
    int refs;
};
static void Release33130(char* h)
{
    if (h != (char*)DAT_0109b220)
        InterlockedDecrement((long*)(h - 8));
}
static void Assign33130(FixedStr& dst, const char* value)
{
    char* h = !value ? (char*)DAT_0109b220 : NiGlobalStringTable::AddString(value);
    if (dst.m_handle != h)
    {
        char* old = dst.m_handle;
        if (h != (char*)DAT_0109b220)
            InterlockedIncrement((long*)(h - 8));
        Release33130(old);
        dst.m_handle = h;
    }
    Release33130(h);
}
static void Clear33130(FUN_00a312d0& tag)
{
    Release33130(tag.m_kInterpolatorID.m_handle);
    Release33130(tag.m_kCtlrID.m_handle);
    Release33130(tag.m_kCtlrType.m_handle);
    Release33130(tag.m_kPropertyType.m_handle);
    Release33130(tag.m_kAVObjectName.m_handle);
}
// Parses objectName into property and controller IDs, then for each controller slot assigns an interpolator and stores a reference to the controller.
// @fnv 0x00a33130
bool FUN_00a34480_cls::AssignControllers(void* apObjectName, FUN_00a34480_obj* apController)
{
    char objectName[260];
    char propertyName[260];
    char controllerID[260];
    FUN_00ec65a6(objectName, 260, (const char*)apObjectName);
    propertyName[0] = 0;
    controllerID[0] = 0;
    char* split = strchr(objectName, '\n');
    if (split)
    {
        FUN_00ec65a6(propertyName, 260, split + 1);
        *split = 0;
        split = strchr(propertyName, '\n');
        FUN_00ec65a6(controllerID, 260, split + 1);
        *split = 0;
    }
    Controller33130* controller = (Controller33130*)apController;
    for (unsigned int i = 0; (unsigned short)i < controller->V45(); ++i)
    {
        const FixedStr& empty = *(const FixedStr*)&DAT_011f49e0;
        FUN_00a312d0 tag(empty, empty, empty, empty, empty);
        Assign33130(tag.m_kAVObjectName, objectName);
        if (strcmp(propertyName, "PROP") == 0)
            Assign33130(tag.m_kPropertyType, controllerID);
        Assign33130(tag.m_kCtlrType, *controller->V02());
        Assign33130(tag.m_kCtlrID, controller->V52());
        Assign33130(tag.m_kInterpolatorID, controller->V46(i));
        RefObj* interpolator = controller->V49(i);
        int index = ((FUN_00a32bc0_cls*)this)->AssignSlot(interpolator, (unsigned int)&tag, 255);
        if (index == -1)
        {
            Clear33130(tag);
            return false;
        }
        RefObj*& slot = *(RefObj**)&((FUN_00a32bc0_cls*)this)->m_pSlots[index].m_unk04;
        if (slot != (RefObj*)controller)
        {
            RefObj* old = slot;
            if (old && !InterlockedDecrement(&old->m_iObjectReferenceCount))
                old->Release();
            slot = (RefObj*)controller;
            InterlockedIncrement(&slot->m_iObjectReferenceCount);
        }
        Clear33130(tag);
    }
    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

extern "C" void* __cdecl FUN_00aa13e0(unsigned int);

extern char* g_pcEmptyFixedString;

struct SeqFixedString
{

    char* m_kHandle;

    SeqFixedString(const char* pcString)

    {

        if (pcString == 0)

            m_kHandle = g_pcEmptyFixedString;

        else

            m_kHandle = NiGlobalStringTable::AddString(pcString);
    }

    operator const char*() const
    {
        return m_kHandle;
    }

    ~SeqFixedString()

    {

        if (m_kHandle != g_pcEmptyFixedString)

            InterlockedDecrement((long*)(m_kHandle - 8));
    }

    SeqFixedString& operator=(const SeqFixedString& kString)

    {

        if (m_kHandle != kString.m_kHandle)
        {

            char* kHandle = kString.m_kHandle;

            if (kHandle != g_pcEmptyFixedString)

                InterlockedIncrement((long*)(kHandle - 8));

            if (m_kHandle != g_pcEmptyFixedString)

                InterlockedDecrement((long*)(m_kHandle - 8));

            m_kHandle = kHandle;
        }

        return *this;
    }
};

namespace a3 {
extern SeqFixedString DAT_011f49e0;
}

struct SeqRefObject
{

    virtual ~SeqRefObject();

    virtual __declspec(nothrow) void DeleteThis() throw();

    long m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }

    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct SeqPtr
{

    T* m_pObject;

    SeqPtr(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }

    ~SeqPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    SeqPtr& operator=(T* p)

    {

        if (m_pObject != p)
        {

            if (m_pObject)
                m_pObject->DecRefCount();

            m_pObject = p;

            if (m_pObject)
                m_pObject->IncRefCount();
        }

        return *this;
    }

    SeqPtr& operator=(const SeqPtr& p)
    {
        return operator=(p.m_pObject);
    }

    T* operator->() const
    {
        return m_pObject;
    }

    operator T*() const
    {
        return m_pObject;
    }
};

struct SeqTextKeys : SeqRefObject
{
};

struct SeqController
{

    void* vtbl;

    int unk04;

    unsigned short m_uiObjectFlags;

    unsigned short unk0A;

    float m_fFrequency;

    float m_fPhase;

    float m_fLoKeyTime;

    float m_fHiKeyTime;
};

struct OldSequence
{

    void* vtbl;

    int unk04;

    const char* m_pcName;

    int unk0C;

    void** m_ppObjects;

    unsigned short unk14;

    unsigned short m_usElementCount;

    int unk18;

    int unk1C;

    SeqController** m_ppControllers;

    int unk24;

    int unk28;

    SeqPtr<SeqTextKeys> m_spTextKeyData;
};

struct NewSequence : SeqRefObject
{

    static void* __cdecl operator new(unsigned int);

    static void* __cdecl operator new(unsigned int, void* p)
    {
        return p;
    }

    __declspec(noalias)
        NewSequence(const char* const& kName, unsigned int uiArraySize, unsigned int uiArrayGrowBy) throw();

    __declspec(nothrow) void AddFromOld(void* pkObject, SeqController* pkCtlr) throw();

    int unk08;

    int unk0C;

    int unk10;

    int unk14;

    int unk18;

    int unk1C;

    SeqPtr<SeqTextKeys> m_spTextKeyData;

    int m_eAnimationCycleType;

    float m_fFrequency;

    float m_fFirstKeyTime;

    float m_fLastKeyTime;

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

    SeqFixedString m_kAccumulationRootName;

    int unk60;

    int unk64;

    int unk68;

    int unk6C;

    int unk70;
};

// Allocates a NewSequence, copies name and controller data from pkOld, and assigns the result to spOut.
// @fnv 0x00a349e0
void __cdecl ConvertOldSequence(OldSequence* pkOld, SeqPtr<NewSequence>& spOut) throw()

{

    void* pvRaw = FUN_00aa13e0(0x74);

    unsigned int ItemUpdateArray = pvRaw != 0 ? pkOld->m_usElementCount : 0;

    SeqPtr<NewSequence> spSeq = new (pvRaw) NewSequence(SeqFixedString(pkOld->m_pcName), ItemUpdateArray, ItemUpdateArray);

    bool bFirst = true;

    for (unsigned int i = 0; i < pkOld->m_usElementCount; i++)
    {

        void* pkObject = pkOld->m_ppObjects[i];

        SeqController* pkCtlr = pkOld->m_ppControllers[i];

        if (pkObject && pkCtlr)
        {

            if (bFirst)
            {

                int eType = (pkCtlr->m_uiObjectFlags >> 1) & 3;

                if (eType != 2 && eType != 0)

                    eType = 0;

                spSeq->m_eAnimationCycleType = eType;

                spSeq->m_fFrequency = pkCtlr->m_fFrequency;

                bFirst = false;

                spSeq->m_fFirstKeyTime = pkCtlr->m_fLoKeyTime;

                spSeq->m_fLastKeyTime = pkCtlr->m_fHiKeyTime;
            }

            spSeq->AddFromOld(pkObject, pkCtlr);
        }
    }

    spSeq->m_spTextKeyData = pkOld->m_spTextKeyData;

    spSeq->m_kAccumulationRootName = a3::DAT_011f49e0;

    spOut = spSeq;
}

extern "C" void _ReadWriteBarrier(void);
struct S00a32fa0_Ctl
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual unsigned short GetTargetIndex(const FUN_00a312d0& tag);
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual RefObj* GetInterpolator(unsigned short index);
};
struct S00a32fa0_RO : RefObj
{
    void DecRef()
    {
        if (!InterlockedDecrement(&m_iObjectReferenceCount))
            Release();
    }
};
struct S00a32fa0_SP
{
    RefObj* m_p;
    S00a32fa0_SP& operator=(const S00a32fa0_SP& o)
    {
        if (m_p != o.m_p)
        {
            RefObj* old = m_p;
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->Release();
            m_p = o.m_p;
            if (m_p)
                InterlockedIncrement(&m_p->m_iObjectReferenceCount);
        }
        return *this;
    }
    S00a32fa0_SP& operator=(RefObj* p)
    {
        if (m_p != p)
        {
            if (m_p)
                ((S00a32fa0_RO*)m_p)->DecRef();
            m_p = p;
            if (m_p)
                InterlockedIncrement(&m_p->m_iObjectReferenceCount);
        }
        return *this;
    }
    void Drop()
    {
        RefObj* old = m_p;
        _ReadWriteBarrier();
        if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
            old->Release();
    }
};
struct S00a32fa0_Item
{
    RefObj* interpolator;
    S00a32fa0_SP controller;
    void* blend;
    unsigned char blendIndex;
    unsigned char priority;
    unsigned char pad0e;
    unsigned char pad0f;
};
struct S00a32fa0_Tag
{
    char* m_kPointA[5];
};
struct S00a32fa0_Arr
{
    __declspec(noalias) bool AssignInterpolatorRef(int index, RefObj** output);
};
struct S00a32fa0_Seq : FUN_00a32bc0_cls
{
    float weight;
    void* textKeys;
    int cycleType;
    float frequency;
    float beginTime;
    float endTime;
    void FUN_00a32fa0(S00a32fa0_Seq* destination, int, int, bool remove);
};
extern int DAT_011f49e0;
extern unsigned short DAT_01096320;

// Copies cycleType, frequency, beginTime, endTime and interpolator slots from this sequence into destination, optionally clearing destination slots first.
// @fnv 0x00a32fa0
void S00a32fa0_Seq::FUN_00a32fa0(S00a32fa0_Seq* destination, int, int, bool remove)
{
    if (remove)
    {
        for (unsigned int i = 0; i < destination->m_uiItemCount; ++i)
        {
            S00a32fa0_SP object = {0};
            ((S00a32fa0_Arr*)destination)->AssignInterpolatorRef(i, &object.m_p);
            object.Drop();
            _ReadWriteBarrier();
        }
    }
    if (cycleType == 2 || cycleType == 0)
        destination->cycleType = cycleType;
    destination->frequency = frequency;
    destination->beginTime = beginTime;
    destination->endTime = endTime;
    for (unsigned int i = 0; i < m_uiItemCount; ++i)
    {
        S00a32fa0_Item& item = ((S00a32fa0_Item*)m_pSlots)[i];
        S00a32fa0_Ctl* controller = (S00a32fa0_Ctl*)item.controller.m_p;
        if (item.interpolator && controller)
        {
            const FUN_00a312d0* info = (FUN_00a312d0*)&m_pInfos[i];
            unsigned short index = controller->GetTargetIndex(*info);
            if (index != DAT_01096320)
            {
                RefObj* interpolator = controller->GetInterpolator(index);
                S00a32fa0_Tag tag;
                unsigned int newIndex = destination->AssignSlot(
                    interpolator,
                    (unsigned int)new (&tag)
                        FUN_00a312d0((FixedStr&)DAT_011f49e0, (FixedStr&)DAT_011f49e0, (FixedStr&)DAT_011f49e0,
                                     (FixedStr&)DAT_011f49e0, (FixedStr&)DAT_011f49e0),
                    0xff);
                ((FUN_00a30750_shell*)&tag)->FUN_00a30750();
                S00a32fa0_Item& newItem = ((S00a32fa0_Item*)destination->m_pSlots)[newIndex];
                newItem.blend = item.blend;
                newItem.controller = item.controller;
                newItem.priority = item.priority;
            }
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class S00a31880_RefObj
{
  public:
    virtual ~S00a31880_RefObj();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class S00a31880_FUN_00a31880_cls
{
  public:
    S00a31880_RefObj* m_00;
    S00a31880_RefObj* m_04;
    unsigned int m_08;
    unsigned char m_0c;
    unsigned char m_0d;

    S00a31880_FUN_00a31880_cls* FUN_00a31880(S00a31880_FUN_00a31880_cls* src);
};

// Copies reference-counted pointers and plain fields from src, managing ref counts for the two RefObj pointers.
// @fnv 0x00a31880
S00a31880_FUN_00a31880_cls* S00a31880_FUN_00a31880_cls::FUN_00a31880(S00a31880_FUN_00a31880_cls* src)
{
    S00a31880_RefObj* pOldRef0 = m_00;
    if (pOldRef0 != src->m_00)
    {
        if (pOldRef0 != 0)
        {
            pOldRef0->DecRefCount();
        }
        m_00 = src->m_00;
        if (m_00 != 0)
        {
            m_00->IncRefCount();
        }
    }
    S00a31880_RefObj* pOldRef1 = m_04;
    if (pOldRef1 != src->m_04)
    {
        if (pOldRef1 != 0)
        {
            pOldRef1->DecRefCount();
        }
        m_04 = src->m_04;
        if (m_04 != 0)
        {
            m_04->IncRefCount();
        }
    }
    m_08 = src->m_08;
    m_0c = src->m_0c;
    m_0d = src->m_0d;
    return this;
}
