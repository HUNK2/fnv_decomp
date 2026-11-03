
// src/gamebryo2.2/corelibs/nianimation/nimorphdata_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/nianimation/nimorphdata.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/nimorphdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nimorphdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void* g_011f3e74;
void* __cdecl NiMorphData_GetRTTI();
extern int DAT_010976fc;
struct NiRefObject
{
    ~NiRefObject();
};
struct S41660
{
    void __thiscall FUN_00a41660(int);
};
void __cdecl _delete(void*, unsigned int);
struct NiMorphData
{
    char _pad[16];
    void* m_pMorphTargets;
    void* FUN_00a41a00(unsigned int);
};
struct NiStream
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void RegisterStreamable(void* pkObject);
};
struct FUN_00a57850_shell
{
    void FUN_00a57850(NiStream& kStream);
};
extern int DAT_0109b220;
struct Object
{
    int field_00;
    int field_04;
    volatile float field_08;
    int field_0c;
    Object* __thiscall FUN_00a415f0();
};
extern int DAT_011f6238;
extern int DAT_0109b220;
extern void* DAT_00fdf1c4;
struct GlobalMgr_b9415
{
    void FUN_00aa4060(int key);
};
struct RefItem_b9415
{
    virtual void V0();
    virtual void Delete();
    int m_refs;
};
typedef int(__stdcall* ReleaseFn_b9415)(int p);
class FUN_00a41610_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    RefItem_b9415* m_0c;
    void ReleaseResources();
};
struct MorphBuffer
{
    void* unk00;
    unsigned int used;
    void* unk08;
    int(__cdecl* append)(MorphBuffer*, void*, unsigned int, const unsigned int*, int);
};
static __forceinline unsigned int countBytes(const volatile unsigned int& count)
{
    return count * 4;
}
void __cdecl FUN_00a417b0(void* owner, void* source, unsigned int elementCount);
struct FUN_00a417f0_vec3
{
    float x;
    float y;
    float z;
};
struct FUN_00a417f0_cls
{
    FUN_00a417f0_vec3* m_pData;
    unsigned int m_iArrayLength;

    bool Equals(FUN_00a417f0_cls* other, unsigned int n);
};
// NiMorphData::SaveBinary: base data, target/vertex counts, relative flag, then each morph
// target's name and vertex array. WriteBinaryArray multiplies by the uiSize variable (Gamebryo form).
struct NiBinaryStream;
typedef unsigned int(__cdecl* NiBinWriteFn)(NiBinaryStream* pkStream, const void* pvBuffer, unsigned int uiBytes,
                                            unsigned int* puiComponentSizes, unsigned int uiNumComponents);
struct NiBinaryStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    NiBinWriteFn m_pfnWrite;

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
        return uiBytes;
    }
};
template <class T> inline unsigned int WriteBinaryArray(NiBinaryStream& kStream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
struct NiFixedStr
{
    const char* m_handle;
};
struct NiStreamM
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    NiBinaryStream* m_pBackingStream;

    void SerializeString(const NiFixedStr& kString);
};
inline void SerializeValue(NiStreamM& kStream, const unsigned int& uiValue)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &uiValue, 1);
}
inline void SerializeValue(NiStreamM& kStream, const char& cValue)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &cValue, 1);
}
inline void SerializeValue(NiStreamM& kStream, const float* pfValues, unsigned int uiNumEls)
{
    WriteBinaryArray(*kStream.m_pBackingStream, pfValues, uiNumEls);
}
struct NiPt3
{
    float x, y, z;
};
inline void SerializeValue(NiStreamM& kStream, const NiPt3* pkValues, unsigned int uiNumEls)
{
    SerializeValue(kStream, (const float*)pkValues, uiNumEls * 3);
}
struct NiObjBase
{
    void* m_ppVirtualMethodTable;
    int m_uiRefCount;
    void SaveBinaryBase(NiStreamM& kStream);
};
struct MorphTgt
{
    NiPt3* m_aVerts;
    NiFixedStr m_kName;
    int unk08;
    int unk0C;

    void SaveBinary(NiStreamM& kStream, unsigned int m_uiScaleCount)
    {
        kStream.SerializeString(m_kName);
        if (m_uiScaleCount)
            SerializeValue(kStream, m_aVerts, m_uiScaleCount);
    }
};
struct NiMorphDataX : NiObjBase
{
    unsigned int m_uiNumTargets;
    unsigned int m_uiNumVertsPerTarget;
    MorphTgt* m_pMorphTargets;
    bool m_bTargetsAreRelative;

    void NiMorphData_SaveBinary(NiStreamM& kStream);
};
struct ViewerStrings
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& element);
    inline unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    __forceinline unsigned int AddInl(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAtInl(uiIndex, element);
        return uiIndex;
    }
    __forceinline void SetAtInl(unsigned int uiIndex, char* const& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else if (element != 0)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != 0)
                m_usESize--;
        }
        m_pBase[uiIndex] = element;
    }
};
struct MorphTarget
{
    void* vtbl;
    char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
    int unk08;
    int unk0c;
};
extern "C" void* g_011f3e74;
char* FUN_00a7d330(const char* pcName);
char* FUN_00a7d510(const char* pcPrefix, unsigned int uiValue);
char* FUN_00a7d5e0(const char* pcPrefix, const char* pcValue);
struct NiObjectBase
{
    void AppendCameraPathEntries(ViewerStrings* pkStrings);
};
struct NiMorphDataV : NiObjectBase
{
    int unk00;
    int unk04;
    unsigned int m_uiNumTargets;
    unsigned int m_uiNumVertsPerTarget;
    MorphTarget* m_pMorphTargets;
    MorphTarget* GetTarget(unsigned int i)
    {
        return i < m_uiNumTargets ? &m_pMorphTargets[i] : 0;
    }
    void AppendToStrings(ViewerStrings* pkStrings);
};
struct FNVBinaryInput
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(FNVBinaryInput*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(const void* data, unsigned int bytes, unsigned int* elementSize, unsigned int elementCount)
    {
        unsigned int bytesRead = m_pfnRead(this, data, bytes, elementSize, elementCount);
        m_uiStreamFlags += bytesRead;
        return bytesRead;
    }
};
template <class T> inline unsigned int FNVReadElements(FNVBinaryInput& stream, const T* data, unsigned int count)
{
    unsigned int elementSize = sizeof(T);
    return stream.Read(data, count * elementSize, &elementSize, 1);
}
void __cdecl ReadElements(NiStreamM* context, const unsigned int* data, unsigned int count);

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct NiInStream;
typedef unsigned int(__cdecl* NiBinReadFn)(NiInStream* pkStream, void* pvBuffer, unsigned int uiBytes,
                                           unsigned int* puiComponentSizes, unsigned int uiNumComponents);
struct NiInStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    NiBinReadFn m_pfnRead;
    void* m_pfnWrite;
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline unsigned int NiBinaryStreamLoad(NiInStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
struct NiStreamL
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    unsigned int m_uiNifVersion;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    NiInStream* m_pUnderlyingStream;
};
template <class T> inline void ReadBinaryValue(NiStreamL& kStream, T& kValue)
{
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &kValue, 1);
}
inline void ReadBinaryValue(NiStreamL& kStream, bool& bValue)
{
    unsigned char ucValue;
    ReadBinaryValue(kStream, ucValue);
    bValue = (ucValue == 1);
}
template <class T> inline T ReadValue(NiStreamL& kStream)
{
    T value;
    ReadBinaryValue(kStream, value);
    return value;
}
struct MorphMemory
{
    void* Allocate(unsigned int);
    void Deallocate(void*);
};
extern MorphMemory _g_memoryManager;
struct MorphPoint3
{
    float x, y, z;
    MorphPoint3()
    {}
    static void* operator new[](unsigned int n)
    {
        return _g_memoryManager.Allocate(n);
    }
    void LoadBinary(NiStreamL&);
};
struct NiFloatData;
struct NiFloatInterpolator
{
    virtual void V00();
    virtual void DeleteThis();
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
    virtual void Collapse();
    long m_uiRefCount;
    unsigned int unk08, unk0c, unk10, unk14;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    static void* operator new(unsigned int);
    NiFloatInterpolator(NiFloatData*) throw();
    void SetKeyData(void* pkKeys, unsigned int uiNumKeys, unsigned int eType);
};
template <class T> struct NiPtr
{
    T* m_pObject;
    ~NiPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPtr& operator=(T* pObject)
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
};
struct NiGlobalStringTable
{
    static char* AddString(const char*);
};
struct NiFixedStrL
{
    char* m_kHandle;
    static void IncRefCount(char* kHandle)
    {
        if (kHandle != (char*)DAT_0109b220)
            InterlockedIncrement((long*)(kHandle - 8));
    }
    static void DecRefCount(char* kHandle)
    {
        if (kHandle != (char*)DAT_0109b220)
            InterlockedDecrement((long*)(kHandle - 8));
    }
    NiFixedStrL(const char* pcString)
    {
        if (pcString == 0)
            m_kHandle = (char*)DAT_0109b220;
        else
            m_kHandle = NiGlobalStringTable::AddString(pcString);
    }
    __forceinline ~NiFixedStrL()
    {
        DecRefCount(m_kHandle);
    }
    NiFixedStrL& operator=(const NiFixedStrL& kString)
    {
        if (m_kHandle != kString.m_kHandle)
        {
            char* kHandle = kString.m_kHandle;
            IncRefCount(kHandle);
            DecRefCount(m_kHandle);
            m_kHandle = kHandle;
        }
        return *this;
    }
};
struct NiFixedName
{
    char* m_kHandle;
    NiFixedName& operator=(const NiFixedStrL& kString)
    {
        if (m_kHandle != kString.m_kHandle)
        {
            char* kHandle = kString.m_kHandle;
            NiFixedStrL::IncRefCount(kHandle);
            NiFixedStrL::DecRefCount(m_kHandle);
            m_kHandle = kHandle;
        }
        return *this;
    }
};
struct FUN_00a415f0
{
    MorphPoint3* m_pkVertexPositions;
    NiFixedStrL m_kName;
    float m_fWeight;
    NiPtr<NiFloatInterpolator> m_spLegacyInterp;
    FUN_00a415f0() throw();
    ~FUN_00a415f0()
    {
        _g_memoryManager.Deallocate(m_pkVertexPositions);
    }
    static void* operator new[](unsigned int n)
    {
        return _g_memoryManager.Allocate(n);
    }
    void SetName(const NiFixedStrL& kName)
    {
        m_kName = kName;
    }
    void ReplaceTargetVerts(MorphPoint3* pkVerts)
    {
        _g_memoryManager.Deallocate(m_pkVertexPositions);
        m_pkVertexPositions = pkVerts;
    }
    void SetTargetInterpolator(NiFloatInterpolator* pkInterp)
    {
        m_spLegacyInterp = pkInterp;
    }
    __forceinline void LoadTargetVerts(NiStreamL& kStream, const unsigned int& count)
    {
        MorphPoint3* pkVerts = new MorphPoint3[count];
        for (unsigned int j = 0; j < count; ++j)
            pkVerts[j].LoadBinary(kStream);
        ReplaceTargetVerts(pkVerts);
    }
    void LoadBinary(NiStreamL& kStream, unsigned int m_uiScaleCount);
};
typedef void*(__cdecl* KeyCreateFn)(NiStreamL& kStream, unsigned int uiNumKeys);
typedef void(__cdecl* KeyFillFn)(void* pkKeys, unsigned int uiNumKeys, unsigned char ucSize);
extern unsigned char DAT_011f3758[];
extern KeyCreateFn DAT_011f3db0[];
extern KeyFillFn DAT_011f3780[];
int __cdecl FUN_00a305b0(char*, unsigned int, const char*, ...);

struct MorphKeyHelpers
{
    static unsigned char GetKeySize(unsigned int type)
    {
        return DAT_011f3758[type];
    }
    static KeyCreateFn GetCreate(unsigned int type)
    {
        return DAT_011f3db0[type];
    }
    static KeyFillFn GetFill(unsigned int type)
    {
        return DAT_011f3780[type];
    }
};
struct MorphData
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    unsigned int m_uiNumTargets;
    unsigned int m_uiNumVertsPerTarget;
    FUN_00a415f0* m_pMorphTargets;
    bool m_bTargetsAreRelative;
    void NiMorphData_LoadBinary(NiStreamL& kStream);
    void LoadBinaryBase(NiStreamL&);
};
// @fnv 0x00a41a40
void MorphData::NiMorphData_LoadBinary(NiStreamL& kStream)
{
    LoadBinaryBase(kStream);
    ReadBinaryValue(kStream, m_uiNumTargets);
    ReadBinaryValue(kStream, m_uiNumVertsPerTarget);
    ReadBinaryValue(kStream, m_bTargetsAreRelative);
    m_pMorphTargets = new FUN_00a415f0[m_uiNumTargets];
    for (unsigned int i = 0; i < m_uiNumTargets; i++)
    {
        if (kStream.m_uiNifVersion < 0x0a010068)
        {
            unsigned int uiNumKeys;
            ReadBinaryValue(kStream, uiNumKeys);
            const unsigned int eType = ReadValue<unsigned int>(kStream);
            if (uiNumKeys > 0)
            {
                unsigned char ucSize = MorphKeyHelpers::GetKeySize(eType);
                void* pkKeys = MorphKeyHelpers::GetCreate(eType)(kStream, uiNumKeys);
                MorphKeyHelpers::GetFill(eType)(pkKeys, uiNumKeys, ucSize);
                NiFloatInterpolator* pkInterp = new NiFloatInterpolator(0);
                pkInterp->SetKeyData(pkKeys, uiNumKeys, eType);
                m_pMorphTargets[i].SetTargetInterpolator(pkInterp);
                pkInterp->Collapse();
            }
            char acName[256];
            FUN_00a305b0(acName, 256, "MT %d", i);
            m_pMorphTargets[i].SetName(acName);
            MorphPoint3* pkVerts = new MorphPoint3[m_uiNumVertsPerTarget];
            for (unsigned int j = 0; j < m_uiNumVertsPerTarget; ++j)
                pkVerts[j].LoadBinary(kStream);
            m_pMorphTargets[i].ReplaceTargetVerts(pkVerts);
        }
        else
        {
            m_pMorphTargets[i].LoadBinary(kStream, m_uiNumVertsPerTarget);
        }
    }
}
