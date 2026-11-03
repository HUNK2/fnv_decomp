
#include "nitransformdata_accepted_decls.h"

// The PC member offsets and the Euler-key cleanup identify this as rotation
// replacement in the opposite order.
// Releases the previous rotation keys via the per-type deleter, then stores the new keys, count and interpolation type, or clears them.
// @fnv 0x00a4e2e0
void NiTransformData::SetRotationKeys(TimedRotationKey* keys, unsigned int count, AnimationKey::KeyType type)
{
    TimedRotationKey* oldKeys = m_pkRotationKeys;
    if (oldKeys)
    {
        if (m_eRotationKeyType == AnimationKey::EULERKEY)
            oldKeys->ClearFloatKeys();
        DAT_011f38d0[m_eRotationKeyType](oldKeys);
    }
    if (keys && count)
    {
        m_usNumRotKeys = (unsigned short)count;
        m_pkRotationKeys = keys;
        m_eRotationKeyType = type;
        m_ucRotationKeySize = DAT_011f3764[type];
    }
    else
    {
        m_usNumRotKeys = 0;
        m_pkRotationKeys = 0;
        m_eRotationKeyType = AnimationKey::NOINTERP;
        m_ucRotationKeySize = 0;
    }
}

// @fnv 0x00a4e350
void NiTransformData::SetPositionKeys(PositionKeyInterpolator* keys, unsigned int count, AnimationKey::KeyType eKeyType)
{
    if (m_pkPositionKeys)
        DAT_011f38b8[m_ePositionKeyType](m_pkPositionKeys);
    if (keys && count)
    {
        m_usNumPosKeys = (unsigned short)count;
        m_pkPositionKeys = keys;
        m_ePositionKeyType = eKeyType;
        m_ucPositionKeySize = DAT_011f375e[eKeyType];
    }
    else
    {
        m_usNumPosKeys = 0;
        m_pkPositionKeys = 0;
        m_ePositionKeyType = AnimationKey::NOINTERP;
        m_ucPositionKeySize = 0;
    }
}

// Releases the previous scale keys and stores the new key array, count and interpolation type, or clears them when keys or count is zero.
// @fnv 0x00a4e3b0
void NiTransformData::SetScaleKeys(TimedAnimationKey* keys, unsigned int count, AnimationKey::KeyType type)
{
    if (m_pkScaleKeyArray)
        DAT_011f38a0[m_eScaleKeyType](m_pkScaleKeyArray);
    if (keys && count)
    {
        m_usNumScaleKeys = (unsigned short)count;
        m_pkScaleKeyArray = keys;
        m_eScaleKeyType = type;
        m_ucScaleKeySize = DAT_011f3758[type];
    }
    else
    {
        m_usNumScaleKeys = 0;
        m_pkScaleKeyArray = 0;
        m_ucScaleKeySize = 0;
        m_eScaleKeyType = AnimationKey::NOINTERP;
    }
}

#include "nitransformdata_types_NiInterpolator.h"
#include "nitransformdata_types_NiFloatsExtraDataController.h"
#include "nitransformdata_types_NiRTTI.h"

// @fnv 0x00a4ead0
bool NiFloatsExtraDataPoint3Controller::ControlsTransform(NiInterpolator* interpolator, unsigned short index) const
{
    return interpolator->IsPoint3ValueSupported();
}

// Returns true if the base controller and the floats extra data index both match the given object's.
// @fnv 0x00a4eb10
bool NiFloatsExtraDataController::IsEqual(NiObject* object) const
{
    if (!NiExtraDataController::IsEqual(object))
        return false;
    if (m_iFloatsExtraDataIndex != static_cast<NiFloatsExtraDataController*>(object)->m_iFloatsExtraDataIndex)
        return false;
    return true;
}

// @fnv 0x00a4eb40
const NiRTTI* NiFloatsExtraDataPoint3Controller::GetRTTI() const
{
    return &ms_kRTTI;
}

struct FUN_00a4e270_shell : public NiTransformData
{
    void DestroyTransformData();
};

extern int DAT_01099004;

struct NiObject_Helper : public NiObject
{
    void FUN_00a5d3d0();
};

// @fnv 0x00a4e270
void FUN_00a4e270_shell::DestroyTransformData()
{
    *reinterpret_cast<int**>(this) = &DAT_01099004;
    TimedRotationKey* pkRotKeys = *reinterpret_cast<TimedRotationKey**>(reinterpret_cast<char*>(this) + 0x20);
    if (pkRotKeys)
    {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) == 4)
        {
            pkRotKeys->ClearFloatKeys();
        }
        DAT_011f38d0[*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10)](pkRotKeys);
    }
    PositionKeyInterpolator* pkPosKeys =
        *reinterpret_cast<PositionKeyInterpolator**>(reinterpret_cast<char*>(this) + 0x24);
    if (pkPosKeys)
    {
        void(__cdecl * pfnPosDeleteFunc)(PositionKeyInterpolator*) =
            DAT_011f38b8[*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x14)];
        pfnPosDeleteFunc(pkPosKeys);
    }
    TimedAnimationKey* pkScaleKeys = *reinterpret_cast<TimedAnimationKey**>(reinterpret_cast<char*>(this) + 0x28);
    if (pkScaleKeys)
    {
        void(__cdecl * pfnScaleDeleteFunc)(TimedAnimationKey*) =
            DAT_011f38a0[*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18)];
        pfnScaleDeleteFunc(pkScaleKeys);
    }
    reinterpret_cast<NiObject_Helper*>(this)->FUN_00a5d3d0();
}

void __fastcall DestroyTransformData(void*);
void __cdecl FUN_00aa1460(void*, unsigned int);

// Calls DestroyTransformData on pThis, then if flags has bit 1 set calls FUN_00aa1460 with 0x2c, and returns pThis.
// @fnv 0x00a4e5b0
void* __fastcall FUN_00a4e5b0(void* pThis, int, unsigned int flags)
{
    DestroyTransformData(pThis);
    if (flags & 1)
        FUN_00aa1460(pThis, 0x2c);
    return pThis;
}

extern "C" const NiRTTI g_011f3fbc;

// @fnv 0x00a4e0a0
const NiRTTI* __cdecl NiTransformData_GetRTTI()
{
    return &g_011f3fbc;
}

struct NiBlendInterpolator;
struct FUN_00a4eaa0_shell : public NiFloatsExtraDataPoint3Controller
{
    NiBlendInterpolator* FUN_00a4eaa0(unsigned short, bool, bool, float, unsigned char);
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct BlendPoint3Stub
{
    BlendPoint3Stub* FUN_00a55a10(bool, float, unsigned char);
};
// @fnv 0x00a4eaa0
NiBlendInterpolator* FUN_00a4eaa0_shell::FUN_00a4eaa0(unsigned short usIndex, bool bManagerControlled,
                                                      bool bAccumulateAnimations, float fWeightThreshold,
                                                      unsigned char ucArraySize)
{
    BlendPoint3Stub* p = (BlendPoint3Stub*)BSFadeNode::operator new(0x40);
    if (p)
        return (NiBlendInterpolator*)p->FUN_00a55a10(bManagerControlled, fWeightThreshold, ucArraySize);
    return 0;
}

namespace fnv_00a4e040 {
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

struct _Call_a5d3a0 : BSFadeNode
{
    _Call_a5d3a0() throw();
};

extern int DAT_01099004;

struct Obj : _Call_a5d3a0
{
    void* mVtable;
    int m4;
    short mS08;
    short mS0a;
    short mS0c;
    int mI10;
    int mI14;
    int mI18;
    char mC1c;
    char mC1d;
    char mC1e;
    int mI20;
    int mI24;
    int mI28;

    Obj() throw();
};

inline Obj::Obj() throw()
{
    mS08 = 0;
    mI20 = 0;
    mI10 = 0;
    mC1c = 0;
    mI24 = 0;
    mI14 = 0;
    mC1d = 0;
    mI28 = 0;
    mI18 = 0;
    mC1e = 0;
    mVtable = &DAT_01099004;
    mS0a = 0;
    mS0c = 0;
}

// Allocates and default-constructs a new Obj, returning the pointer.
// @fnv 0x00a4e040
Obj* FUN_00a4e040()
{
    return new Obj;
}
}  // namespace fnv_00a4e040

// Iterates three slots, deletes each non-null key via the function at DAT_011f38a0 indexed by the slot's index, then zeroes the key, index and count fields.
// @fnv 0x00a29ad0
void TimedRotationKey::ClearFloatKeys()
{
    int* p = (int*)((char*)this + 0x30);
    for (int i = 0; i < 3; ++i)
    {
        int key = *p;
        if (key != 0)
        {
            int iDeleteFuncIndex = *(p - 4);
            NiFloatKeyDeleteFunction pDeleteFunc = DAT_011f38a0[iDeleteFuncIndex];
            pDeleteFunc((TimedAnimationKey*)key);
        }
        *p = 0;
        *(p - 7) = 0;
        *(p - 4) = 0;
        ++p;
    }
}

struct FUN_00a4e0b0_Holder
{
    void FUN_00a4e0b0(void*, int, char*);
};
// Stores a1, a2 and a3 into fields at offsets 0x24, 0xa and 0x14, plus a byte from a3, or clears them when a1 or a2 is null.
// @fnv 0x00a4e0b0
void FUN_00a4e0b0_Holder::FUN_00a4e0b0(void* a1, int a2, char* a3)
{
    if (a1 && a2)
    {
        *(short*)((char*)this + 0xa) = (short)a2;
        *(void**)((char*)this + 0x24) = a1;
        *(void**)((char*)this + 0x14) = a3;
        *(char*)((char*)this + 0x1d) = a3[0x11f375e];
    }
    else
    {
        *(short*)((char*)this + 0xa) = 0;
        *(void**)((char*)this + 0x24) = 0;
        *(void**)((char*)this + 0x14) = 0;
        *(char*)((char*)this + 0x1d) = 0;
    }
}

struct FUN_00a4e0f0_shell
{
    void InitFromParams(unsigned int, unsigned int, unsigned int);
};

// @fnv 0x00a4e0f0
void FUN_00a4e0f0_shell::InitFromParams(unsigned int a, unsigned int b, unsigned int pSource)
{
    if (a && b)
    {
        *(unsigned short*)((char*)this + 0xc) = (unsigned short)b;
        *(unsigned int*)((char*)this + 0x28) = a;
        *(unsigned int*)((char*)this + 0x18) = pSource;
        *(unsigned char*)((char*)this + 0x1e) = *(unsigned char*)((char*)pSource + 0x11f3758);
    }
    else
    {
        *(unsigned short*)((char*)this + 0xc) = 0;
        *(unsigned int*)((char*)this + 0x28) = 0;
        *(unsigned char*)((char*)this + 0x1e) = 0;
        *(unsigned int*)((char*)this + 0x18) = 0;
    }
}

namespace fnv_00a4e990 {
struct FUN_00a4e990_shell : public NiTransformData
{
    void AppendTransformKeyCounts(void*);
};

struct StrArr
{
    void* _vt;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    unsigned int SetAtGrow(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(char* element)
    {
        return SetAtGrow(m_usSize, element);
    }
};
struct Base380
{
    void AppendCameraPathEntries(StrArr*);
};
char* FUN_00a7d330(const char*);
char* __cdecl FUN_00a7d490(const char*, unsigned short);
extern const char* g_011f3fbc;

// @fnv 0x00a4e990
void FUN_00a4e990_shell::AppendTransformKeyCounts(void* pStrArr)
{
    StrArr* apViewerStrings = (StrArr*)pStrArr;
    ((Base380*)this)->AppendCameraPathEntries(apViewerStrings);
    apViewerStrings->Add(FUN_00a7d330(g_011f3fbc));
    apViewerStrings->Add(FUN_00a7d490("m_usNumRotKeys", *(unsigned short*)((char*)this + 8)));
    apViewerStrings->Add(FUN_00a7d490("m_usNumPosKeys", *(unsigned short*)((char*)this + 0xa)));
    apViewerStrings->Add(FUN_00a7d490("m_usNumScaleKeys", *(unsigned short*)((char*)this + 0xc)));
}
}  // namespace fnv_00a4e990

void UpdateSlotStates(unsigned int content, AnimationKey::KeyType type, AnimationKey*& keys, unsigned int& count,
                      float start, float end);
struct TransformRange : NiTransformData
{
    void FUN_00a4df40(float start, float end);
};
// @fnv 0x00a4df40
void TransformRange::FUN_00a4df40(float start, float end)
{
    unsigned int count;
    AnimationKey* keys;
    if (m_usNumRotKeys)
    {
        count = m_usNumRotKeys;
        keys = reinterpret_cast<AnimationKey*>(m_pkRotationKeys);
        UpdateSlotStates(2, m_eRotationKeyType, keys, count, start, end);
        m_usNumRotKeys = static_cast<unsigned short>(count);
        m_pkRotationKeys = reinterpret_cast<TimedRotationKey*>(keys);
    }
    if (m_usNumPosKeys)
    {
        count = m_usNumPosKeys;
        keys = reinterpret_cast<AnimationKey*>(m_pkPositionKeys);
        UpdateSlotStates(1, m_ePositionKeyType, keys, count, start, end);
        m_usNumPosKeys = static_cast<unsigned short>(count);
        m_pkPositionKeys = reinterpret_cast<PositionKeyInterpolator*>(keys);
    }
    if (m_usNumScaleKeys)
    {
        count = m_usNumScaleKeys;
        keys = reinterpret_cast<AnimationKey*>(m_pkScaleKeyArray);
        UpdateSlotStates(0, m_eScaleKeyType, keys, count, start, end);
        m_usNumScaleKeys = static_cast<unsigned short>(count);
        m_pkScaleKeyArray = reinterpret_cast<TimedAnimationKey*>(keys);
    }
}

typedef bool(__cdecl* NiAnimKeyEqualFunction)(void*, void*);
extern NiAnimKeyEqualFunction DAT_011f3b10[AnimationKey::NUMKEYTYPES];
extern NiAnimKeyEqualFunction DAT_011f3af8[AnimationKey::NUMKEYTYPES];
extern NiAnimKeyEqualFunction DAT_011f3ae0[AnimationKey::NUMKEYTYPES];

struct NiObjectBaseEq : NiObject
{
    bool IsSameAs(NiObject* pkObject) const;
};

struct TransformDataEqual : NiTransformData
{
    bool NiTransformData_IsEqual(NiObject* pkObject);
};

// @fnv 0x00a4e130
bool TransformDataEqual::NiTransformData_IsEqual(NiObject* pkObject)
{
    if (!((NiObjectBaseEq*)this)->IsSameAs(pkObject))
        return false;

    NiTransformData* pkData = (NiTransformData*)pkObject;
    if (m_usNumRotKeys != pkData->m_usNumRotKeys || m_eRotationKeyType != pkData->m_eRotationKeyType ||
        m_usNumPosKeys != pkData->m_usNumPosKeys || m_ePositionKeyType != pkData->m_ePositionKeyType ||
        m_usNumScaleKeys != pkData->m_usNumScaleKeys || m_eScaleKeyType != pkData->m_eScaleKeyType ||
        m_ucRotationKeySize != pkData->m_ucRotationKeySize || m_ucPositionKeySize != pkData->m_ucPositionKeySize ||
        m_ucScaleKeySize != pkData->m_ucScaleKeySize)
        return false;

    NiAnimKeyEqualFunction pfnKeyEqual = DAT_011f3b10[m_eRotationKeyType];
    unsigned int i;
    for (i = 0; i < m_usNumRotKeys; i++)
    {
        char* pKeyB = (char*)pkData->m_pkRotationKeys + i * m_ucRotationKeySize;
        char* pKeyA = (char*)m_pkRotationKeys + i * m_ucRotationKeySize;
        if (!pfnKeyEqual(pKeyA, pKeyB))
            return false;
    }

    pfnKeyEqual = DAT_011f3af8[m_ePositionKeyType];
    for (i = 0; i < m_usNumPosKeys; i++)
    {
        char* pKeyB = (char*)pkData->m_pkPositionKeys + i * m_ucPositionKeySize;
        char* pKeyA = (char*)m_pkPositionKeys + i * m_ucPositionKeySize;
        if (!pfnKeyEqual(pKeyA, pKeyB))
            return false;
    }

    pfnKeyEqual = DAT_011f3ae0[m_eScaleKeyType];
    for (i = 0; i < m_usNumScaleKeys; i++)
    {
        char* pKeyB = (char*)pkData->m_pkScaleKeyArray + i * m_ucScaleKeySize;
        char* pKeyA = (char*)m_pkScaleKeyArray + i * m_ucScaleKeySize;
        if (!pfnKeyEqual(pKeyA, pKeyB))
            return false;
    }

    return true;
}

class PSysRef4e4
{
  public:
    virtual ~PSysRef4e4();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};

template <class T> class PSysPtr4e4
{
  public:
    PSysPtr4e4(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    PSysPtr4e4(const PSysPtr4e4& kOther)
    {
        m_pObject = kOther.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~PSysPtr4e4()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    PSysPtr4e4& operator=(T* pObject)
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

    T* m_pObject;
};

class PSysData4e4 : public PSysRef4e4
{
  public:
    void FUN_00a4e2e0(int iA, int iB, void* pvSrc);
    void FUN_00a4e350(int iA, int iB, void* pvSrc);
    void FUN_00a4e3b0(int iA, int iB, void* pvSrc);
};

void __cdecl FUN_00a3d630(int iKind, void* pvData, void* pvExtra, unsigned int ItemUpdateArray, float fA, float fB, int* piOutA,
                          int* piOutB);

struct FUN_00a4e410_shell
{
    int m_00;
    int m_04;
    unsigned short m_usCount0;
    unsigned short m_usCount1;
    unsigned short m_usCount2;
    unsigned short m_usPad;
    void* m_pvData0;
    void* m_pvData1;
    void* m_pvData2;
    int m_1c;
    void* m_pvExtra0;
    void* m_pvExtra1;
    void* m_pvExtra2;

    void FUN_00a5d510(PSysData4e4** ppkData);
    void FUN_00a4e410(float fA, float fB, PSysPtr4e4<PSysData4e4>& spOut);
};

// @fnv 0x00a4e410
void FUN_00a4e410_shell::FUN_00a4e410(float fA, float fB, PSysPtr4e4<PSysData4e4>& spOut)
{
    PSysData4e4* pkData = 0;
    FUN_00a5d510(&pkData);
    PSysData4e4* pkResult = pkData;
    if (pkResult)
        pkResult->IncRefCount();
    int iOutA = 0;
    int iOutB = 0;
    if (m_usCount0 > 0)
    {
        FUN_00a3d630(2, m_pvData0, m_pvExtra0, m_usCount0, fA, fB, &iOutA, &iOutB);
        pkResult->FUN_00a4e2e0(iOutA, iOutB, m_pvData0);
    }
    if (m_usCount1 > 0)
    {
        FUN_00a3d630(1, m_pvData1, m_pvExtra1, m_usCount1, fA, fB, &iOutA, &iOutB);
        pkResult->FUN_00a4e350(iOutA, iOutB, m_pvData1);
    }
    if (m_usCount2 > 0)
    {
        FUN_00a3d630(0, m_pvData2, m_pvExtra2, m_usCount2, fA, fB, &iOutA, &iOutB);
        pkResult->FUN_00a4e3b0(iOutA, iOutB, m_pvData2);
    }
    spOut = pkResult;
    if (pkResult)
        pkResult->DecRefCount();
    if (pkData)
        pkData->DecRefCount();
}

struct AnimationBinaryStream
{
    unsigned int unk00, position, unk08;
    unsigned int(__cdecl* write)(AnimationBinaryStream*, const void*, unsigned int, const unsigned int*, unsigned int);
    void Write(const void* data, unsigned int bytes)
    {
        unsigned int size = bytes;
        position += write(this, data, bytes, &size, 1);
    }
};
class NiStream
{
  public:
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
    unsigned int unk0d8;
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
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    AnimationBinaryStream* output;
};
template <class T> inline void SaveAnimationValue(NiStream& stream, const T& value)
{
    stream.output->Write(&value, sizeof(T));
}
typedef void(__cdecl* RotationSave)(NiStream&, TimedRotationKey*, unsigned int);
typedef void(__cdecl* PositionSave)(NiStream&, PositionKeyInterpolator*, unsigned int);
typedef void(__cdecl* ScaleSave)(NiStream&, TimedAnimationKey*, unsigned int);
extern RotationSave g_011f3a80[];
extern PositionSave g_011f3a68[];
extern ScaleSave g_011f3a50[];
struct TransformSaveQuery : NiTransformData
{
    void NiTransformData_SaveBinary(NiStream& stream);
};
// Saves the transform data's rotation, position and scale key counts and key arrays to the stream via the per-type save function tables.
// @fnv 0x00a4e810
void TransformSaveQuery::NiTransformData_SaveBinary(NiStream& stream)
{
    NiObject::SaveBinary(stream);
    unsigned int count = m_usNumRotKeys;
    SaveAnimationValue(stream, count);
    if (m_usNumRotKeys > 0)
    {
        SaveAnimationValue(stream, m_eRotationKeyType);
        count = m_usNumRotKeys;
        g_011f3a80[m_eRotationKeyType](stream, m_pkRotationKeys, count);
    }
    count = m_usNumPosKeys;
    SaveAnimationValue(stream, count);
    if (m_usNumPosKeys > 0)
    {
        SaveAnimationValue(stream, m_ePositionKeyType);
        count = m_usNumPosKeys;
        g_011f3a68[m_ePositionKeyType](stream, m_pkPositionKeys, count);
    }
    count = m_usNumScaleKeys;
    SaveAnimationValue(stream, count);
    if (m_usNumScaleKeys > 0)
    {
        SaveAnimationValue(stream, m_eScaleKeyType);
        count = m_usNumScaleKeys;
        g_011f3a50[m_eScaleKeyType](stream, m_pkScaleKeyArray, count);
    }
}

extern void FUN_00a57630();

// @fnv 0x00a4eaf0
void FUN_00a4eaf0()
{
    FUN_00a57630();
}

struct FUN_00a57100_Caller
{
    bool NiExtraDataController_RegisterStreamables(NiStream&);
};

struct FUN_00a4eb00_Caller : FUN_00a57100_Caller
{
    bool FUN_00a4eb00(NiStream&);
};

// @fnv 0x00a4eb00
bool FUN_00a4eb00_Caller::FUN_00a4eb00(NiStream& kStream)
{
    return NiExtraDataController_RegisterStreamables(kStream);
}

struct TransformDataBinaryInputView
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(TransformDataBinaryInputView*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* destination, unsigned int bytes)
    {
        unsigned int componentSize = bytes;
        position += read(this, destination, bytes, &componentSize, 1);
    }
};
class TransformDataInputView
{
  public:
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
    unsigned int unk0d8;
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
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    TransformDataBinaryInputView* input;
    void Read(void* destination, unsigned int bytes)
    {
        input->Read(destination, bytes);
    }
};
template <class T> inline void TransformDataReadEnum(NiStream& stream, T& value)
{
    unsigned int serialized;
    reinterpret_cast<TransformDataInputView&>(stream).Read(&serialized, sizeof(serialized));
    value = static_cast<T>(serialized);
}
extern TimedRotationKey*(__cdecl* DAT_011f3de0[])(NiStream&, unsigned int);
extern PositionKeyInterpolator*(__cdecl* DAT_011f3dc8[])(NiStream&, unsigned int);
extern TimedAnimationKey*(__cdecl* DAT_011f3db0[])(NiStream&, unsigned int);
extern void(__cdecl* DAT_011f37b0[])(TimedRotationKey*, unsigned int, unsigned char);
extern void(__cdecl* DAT_011f3798[])(PositionKeyInterpolator*, unsigned int, unsigned char);
extern void(__cdecl* DAT_011f3780[])(TimedAnimationKey*, unsigned int, unsigned char);
typedef TimedRotationKey*(__cdecl* RotCreateFunction)(NiStream&, unsigned int);
typedef void(__cdecl* RotLoadFunction)(TimedRotationKey*, unsigned int, unsigned char);
inline unsigned char GetRotKeySize(AnimationKey::KeyType type)
{
    return DAT_011f3764[type];
}
inline RotCreateFunction GetRotCreateFunction(AnimationKey::KeyType type)
{
    return DAT_011f3de0[type];
}
inline RotLoadFunction GetRotLoadFunction(AnimationKey::KeyType type)
{
    return DAT_011f37b0[type];
}
typedef PositionKeyInterpolator*(__cdecl* PosCreateFunction)(NiStream&, unsigned int);
typedef void(__cdecl* PosLoadFunction)(PositionKeyInterpolator*, unsigned int, unsigned char);
inline unsigned char GetPosKeySize(AnimationKey::KeyType type)
{
    return DAT_011f375e[type];
}
inline PosCreateFunction GetPosCreateFunction(AnimationKey::KeyType type)
{
    return DAT_011f3dc8[type];
}
inline PosLoadFunction GetPosLoadFunction(AnimationKey::KeyType type)
{
    return DAT_011f3798[type];
}
typedef TimedAnimationKey*(__cdecl* ScaleCreateFunction)(NiStream&, unsigned int);
typedef void(__cdecl* ScaleLoadFunction)(TimedAnimationKey*, unsigned int, unsigned char);
inline unsigned char GetScaleKeySize(AnimationKey::KeyType type)
{
    return DAT_011f3758[type];
}
inline ScaleCreateFunction GetScaleCreateFunction(AnimationKey::KeyType type)
{
    return DAT_011f3db0[type];
}
inline ScaleLoadFunction GetScaleLoadFunction(AnimationKey::KeyType type)
{
    return DAT_011f3780[type];
}
void __cdecl FUN_00a29680(const char* message);
class TransformDataLoader : public NiTransformData
{
  public:
    void NiTransformData_LoadBinary(NiStream& stream);
};
// Reads rotation, position, and scale key data from a NiStream, creating and loading each key set via type-specific factory and load functions.
// @fnv 0x00a4e5d0
void TransformDataLoader::NiTransformData_LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    unsigned int numKeys;
    reinterpret_cast<TransformDataInputView&>(stream).Read(&numKeys, 4);
    if (numKeys > 0)
    {
        AnimationKey::KeyType type;
        TransformDataReadEnum(stream, type);
        unsigned char keySize = GetRotKeySize(type);
        TimedRotationKey* keys = GetRotCreateFunction(type)(stream, numKeys);
        GetRotLoadFunction(type)(keys, numKeys, keySize);
        if (numKeys > 65535)
        {
            numKeys = 65535;
            FUN_00a29680("Transform data loading has more than 65535 rotation keys!");
        }
        SetRotationKeys(keys, numKeys, type);
    }
    reinterpret_cast<TransformDataInputView&>(stream).Read(&numKeys, 4);
    if (numKeys > 0)
    {
        AnimationKey::KeyType type;
        TransformDataReadEnum(stream, type);
        unsigned char keySize = GetPosKeySize(type);
        PositionKeyInterpolator* keys = GetPosCreateFunction(type)(stream, numKeys);
        GetPosLoadFunction(type)(keys, numKeys, keySize);
        if (numKeys > 65535)
        {
            numKeys = 65535;
            FUN_00a29680("Transform data loading has more than 65535 position keys!");
        }
        SetPositionKeys(keys, numKeys, type);
    }
    reinterpret_cast<TransformDataInputView&>(stream).Read(&numKeys, 4);
    if (numKeys > 0)
    {
        AnimationKey::KeyType type;
        TransformDataReadEnum(stream, type);
        unsigned char keySize = GetScaleKeySize(type);
        TimedAnimationKey* keys = GetScaleCreateFunction(type)(stream, numKeys);
        GetScaleLoadFunction(type)(keys, numKeys, keySize);
        if (numKeys > 65535)
        {
            numKeys = 65535;
            FUN_00a29680("Transform data loading has more than 65535 scale keys!");
        }
        SetScaleKeys(keys, numKeys, type);
    }
}
