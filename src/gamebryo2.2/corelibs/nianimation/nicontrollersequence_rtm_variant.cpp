// src/gamebryo2.2/corelibs/nianimation/nicontrollersequence_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern const char* const g_011c7d74_arg1;
const char* const* __cdecl FUN_00a31730();
struct BaseH
{
    virtual ~BaseH();
};
struct NiControllerSequence : BaseH
{
    void* FUN_00a35820(unsigned int);
};
extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);
struct FUN_00a30580_shell
{
    bool __thiscall IsNotInChain(void* arg);
};
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
struct FUN_00a30900_shell
{
    void FUN_00a30900(char m_ucRegionPriority);
};
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};
struct FUN_00a316a0_shell
{
    void* __thiscall FUN_00a316a0();
};
void* __cdecl FUN_00a326c0();
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
struct FUN_00a30c80_shell
{
    unsigned __int64 __thiscall IsNotInChain(void* arg);
    bool __thiscall FUN_00a30c80(void* arg);
};
bool __stdcall MatchesTextKeys(void* arg);
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
void __cdecl FUN_00aa10f0(void* pv);
struct FUN_00a30750_shell
{
    char* m_kPointA[5];
    void FUN_00a30750();
};
extern int EmptyFS;
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
void* __cdecl FormatStringWithType(const char* pcText, void* arg2);
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
extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
struct FUN_00a344f0_cls
{
    void __thiscall FUN_00a33570(void* obj, unsigned int param);
    void* FUN_00a344f0(unsigned int param);
};
extern const float DAT_010141cc;
struct FUN_00a350d0_seq : SeqA34f20
{
    bool FUN_00a350d0(SeqA34f20* pkTarget, float fTime, float m_fTimeout, int iPriority, float fSeqWeight,
                      float fTargetWeight, SeqA34f20* pkPartner);
};
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
void __cdecl FUN_00a35700(BinaryDataRecord* stream, unsigned int index, NiPtrNode& out);
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
#include <windows.h>
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
void __cdecl ConvertOldSequence(OldSequence* pkOld, SeqPtr<NewSequence>& spOut) throw();
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

void __cdecl ReleaseObjectArray(void*);
extern float DAT_01096548;
extern double DAT_010231b0;
extern unsigned char DAT_01096968;
extern unsigned int DAT_01096688;
void* __cdecl FUN_00aa1070(unsigned int);
struct LegacyStream
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
    unsigned int version;
};
struct LegacyTag
{
    char* name;
    char* property;
    char* type;
    char* controller;
    char* interpolator;
    void LoadFromPalette(RefObj*, NiStream&);
    void ResetStrings();
};
struct LegacyController : RefObj
{
    unsigned short flags;
    unsigned short unk0a;
    float frequency;
    float phase;
    volatile float begin;
    volatile float end;
};
struct LegacyItem
{
    RefObj* interpolator;
    LegacyController* controller;
    void* blend;
    unsigned char index;
    unsigned char priority;
    unsigned short unk0e;
    void Clear()
    {
        if (interpolator)
        {
            RefObj* saved = interpolator;
            if (!InterlockedDecrement(&saved->m_iObjectReferenceCount))
                saved->Release();
            interpolator = 0;
        }
        if (controller)
        {
            LegacyController* saved = controller;
            if (!InterlockedDecrement(&saved->m_iObjectReferenceCount))
                saved->Release();
            controller = 0;
        }
        blend = 0;
        index = DAT_01096968;
        priority = 255;
    }
};
struct MemoryManager
{
    void* Allocate(unsigned int);
};
extern MemoryManager _g_memoryManager;
struct ReferenceAllocation;
struct LegacyRef
{
    LegacyController* pointer;
    ~LegacyRef() throw()
    {}
    static void* operator new[](unsigned int bytes, ReferenceAllocation*& allocation) throw();
};
struct ReferenceAllocation
{
    unsigned int count;
    LegacyRef elements[1];
};
__forceinline void* LegacyRef::operator new[](unsigned int bytes, ReferenceAllocation*& allocation) throw()
{
    allocation = (ReferenceAllocation*)_g_memoryManager.Allocate(bytes);
    return allocation;
}
static __forceinline void MakeRefs(unsigned int n, LegacyRef*& result)
{
    ReferenceAllocation* allocation;
    new (allocation) LegacyRef[n];
    if (allocation)
    {
        LegacyRef* data = allocation->elements;
        LegacyRef* current = data;
        for (int remaining = (int)n - 1; remaining >= 0; --remaining, ++current)
            current->pointer = 0;
        result = data;
    }
    else
        result = 0;
}
struct S00a352f0_Hold
{
    LegacyController* p;
    S00a352f0_Hold(LegacyController* c) : p(c)
    {
        if (p)
            InterlockedIncrement(&p->m_iObjectReferenceCount);
    }
};
struct LegacyArray
{
    unsigned int* vtable;
    LegacyRef* data;
    unsigned short capacity;
    unsigned short length;
    unsigned short populated;
    unsigned short grow;
    void SetEntry(unsigned int, const S00a352f0_Hold&);
};
struct NamesArray
{
    unsigned int* vtable;
    char** data;
    unsigned short capacity, length, populated, grow;
};
struct LegacySequence : ::NiObject
{
    char* name;
    unsigned int count;
    unsigned int grow;
    LegacyItem* items;
    LegacyTag* tags;
    float weight;
    RefObj* textKeys;
    int cycle;
    float frequency;
    float begin;
    float end;
    float last;
    float weightedLast;
    float scaledLast;
    void* owner;
    int state;
    float offset;
    float start;
    float finish;
    float dest;
    void* partner;
    char* rootName;
    unsigned int unk60;
    RefObj* stringPalette;
    void FUN_00a352f0(NiStream& stream);
    bool FUN_00a34480(char*, LegacyController*);
};
// @fnv 0x00a352f0
void LegacySequence::FUN_00a352f0(NiStream& stream)
{
    ::NiObject::LinkObject(stream);
    if (stringPalette)
    {
        for (unsigned int i = 0; i < count; ++i)
            tags[i].LoadFromPalette(stringPalette, stream);
        if (stringPalette)
        {
            RefObj* palette = stringPalette;
            if (!InterlockedDecrement(&palette->m_iObjectReferenceCount))
                palette->Release();
            stringPalette = 0;
        }
    }
    if (((LegacyStream*)&stream)->version < 0x0a010068)
    {
        begin = DAT_01096548;
        unsigned int n = count;
        end = DAT_01015f5c;
        unsigned int rangeIndex = 0;
        if (rangeIndex < n)
        {
            LegacyController** sourceControllers = &items[0].controller;
            do
            {
                LegacyController* controller = *sourceControllers;
                if (controller->begin < begin)
                    begin = controller->begin;
                if (controller->end > end)
                    end = controller->end;
                sourceControllers += sizeof(LegacyItem) / sizeof(*sourceControllers);
                ++rangeIndex;
            } while (rangeIndex < n);
        }
        if (begin == DAT_010231b0 && end == DAT_010241b0)
            begin = end = 0.0f;
        NamesArray names;
        names.capacity = (unsigned short)n;
        names.length = 0;
        if (names.capacity > 0)
            names.data = (char**)FUN_00aa1070(names.capacity * 4);
        else
            names.data = 0;
        LegacyArray controllers;
        controllers.capacity = (unsigned short)count;
        controllers.grow = 1;
        controllers.length = 0;
        controllers.populated = 0;
        if (controllers.capacity > 0)
            MakeRefs(controllers.capacity, controllers.data);
        else
            controllers.data = 0;
        controllers.vtable = &DAT_01096688;
        for (unsigned int i = 0; i < count; ++i)
        {
            {
                const char* name = tags[i].name;
                unsigned int bytes = strlen(name) + 1;
                char* copy = (char*)FUN_00aa1070(bytes);
                FUN_00ec65a6(copy, bytes, name);
                if (i >= names.length)
                    names.length = (unsigned short)(i + 1);
                names.data[i] = copy;
            }
            tags[i].ResetStrings();
            LegacyController* retained = items[i].controller;
            controllers.SetEntry(i, S00a352f0_Hold(retained));
            if (retained && !InterlockedDecrement(&retained->m_iObjectReferenceCount))
                retained->Release();
            items[i].Clear();
        }
        unsigned int controllerCount = controllers.length;
        for (unsigned int i = 0; i < controllerCount; ++i)
        {
            LegacyController* controller = controllers.data[i].pointer;
            if (i == 0)
            {
                cycle = (controller->flags >> 1) & 3;
                if (cycle != 2 && cycle != 0)
                    cycle = 0;
                frequency = controller->frequency;
            }
            FUN_00a34480(names.data[i], controller);
        }
        for (unsigned int i = 0; i < names.length; ++i)
            FUN_00aa10f0(names.data[i]);
        ReleaseObjectArray(controllers.data);
        FUN_00aa10f0(names.data);
    }
}
