
// src/gamebryo2.2/corelibs/nianimation/nipathcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nipathcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef void NiRTTI;

extern NiRTTI* g_011f3f80;

// @fnv 0x00a49e00
NiRTTI* __cdecl FUN_00a49e00()
{
    return &g_011f3f80;
}

struct AnimationKey;
extern void(__cdecl* DAT_011f3ca8[])(float, AnimationKey const*, AnimationKey const*, void*);
struct FUN_00a49e10_shell
{
    char _0[0x40];
    struct Inner
    {
        char _00[12];
        AnimationKey const* base;
        int idx;
        unsigned char sz;
    }* p;
    void* InvokeIndexedCallback(void* a1, int a2, int a3, float f);
};
// Reads idx, sz and base from p (or zeros), calls DAT_011f3ca8[idx] with f and two base+sz*index pointers, and returns a1.
// @fnv 0x00a49e10
void* FUN_00a49e10_shell::InvokeIndexedCallback(void* a1, int iIndexA, int iIndexB, float fValue)
{
    Inner* pInner = p;
    int idx;
    AnimationKey const* base;
    unsigned char sz;
    if (pInner)
    {
        idx = pInner->idx;
        sz = pInner->sz;
        base = pInner->base;
    }
    else
    {
        idx = 0;
        base = 0;
        sz = 0;
    }
    DAT_011f3ca8[idx](fValue, (AnimationKey const*)((char const*)base + (unsigned)sz * (unsigned)iIndexA),
                      (AnimationKey const*)((char const*)base + (unsigned)sz * (unsigned)iIndexB), a1);
    return a1;
}

void __cdecl FUN_00a49d60();
void __cdecl _delete(void*, int);

struct FUN_00a4a8c0_shell
{
    void* __thiscall FUN_00a4a8c0(unsigned int flags);
};

// Calls FUN_00a49d60, then deletes this with size 100 if flags has bit 1 set, and returns this.
// @fnv 0x00a4a8c0
void* __thiscall FUN_00a4a8c0_shell::FUN_00a4a8c0(unsigned int flags)
{
    FUN_00a49d60();
    if (flags & 1)
        _delete(this, 100);
    return this;
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
void __stdcall FUN_00a6d830(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
struct NiPathController
{
    void AppendString(StrArr*);
};
// Appends a string obtained from g_011f3f80 to pkStrings, growing the array by its capacity step when it is full.
// @fnv 0x00a4b2e0
void NiPathController::AppendString(StrArr* pkStrings)
{
    FUN_00a6d830(pkStrings);
    char* pStr = _FUN_00a7d330((const char*)g_011f3f80);
    unsigned int nSize = *(unsigned short*)((char*)pkStrings + 0xa);
    if (nSize >= *(unsigned short*)((char*)pkStrings + 8))
        pkStrings->SetSize(nSize + *(unsigned short*)((char*)pkStrings + 0xe));
    pkStrings->SetAt(nSize, pStr);
}

namespace fnv_00a49c80 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];

struct NiTimeController
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
    virtual void ProcessClone(CloningProcess&);
    char _pad[60];
};
struct NiPtr
{
    NiTimeController* m_pObject;
};
struct NiPathController : NiTimeController
{
    NiPtr m_pPathObject;
    NiPtr m_pPathInterp;
    void FUN_00a49c80(CloningProcess&);
};
// @fnv 0x00a49c80
void NiPathController::FUN_00a49c80(CloningProcess& kCloning)
{
    NiTimeController::ProcessClone(kCloning);
    NiTimeController* pkPathData = m_pPathObject.m_pObject;
    if (pkPathData)
        pkPathData->ProcessClone(kCloning);
    NiTimeController* pkPctData = m_pPathInterp.m_pObject;
    if (pkPctData)
        pkPctData->ProcessClone(kCloning);
}
}  // namespace fnv_00a49c80

namespace fnv_00a49cc0 {
struct NiStream;
struct FakeObj
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
    virtual void RegisterStreamables(NiStream&);
};
struct Base40
{
    char _pad[0x40];
    bool FUN_00a6d0f0(NiStream&);
};
struct NiPathController : public Base40
{
    FakeObj* m_pPathObject;
    FakeObj* m_pPathInterp;
    bool FUN_00a49cc0(NiStream&);
};
// @fnv 0x00a49cc0
bool NiPathController::FUN_00a49cc0(NiStream& kStream)
{
    if (!FUN_00a6d0f0(kStream))
        return false;
    FakeObj* pkPath = m_pPathObject;
    if (pkPath)
        pkPath->RegisterStreamables(kStream);
    FakeObj* pkPct = m_pPathInterp;
    if (pkPct)
        pkPct->RegisterStreamables(kStream);
    return true;
}
}  // namespace fnv_00a49cc0

extern float DAT_011a8b40[5];
extern float DAT_011a8b2c[5];

struct FUN_00a4a6a0_cls
{
    float GetKeyDerivativeLength(int a1, int a2, float a3);
    float FUN_00a4a6a0(int a1, int a2, float a3);
};

// Sums five weighted samples of GetKeyDerivativeLength at offsets scaled by a3, then multiplies the total by a3.
// @fnv 0x00a4a6a0
float FUN_00a4a6a0_cls::FUN_00a4a6a0(int a1, int a2, float afScale)
{
    float sum = 0.0f;
    for (int i = 0; i < 5; i++)
    {
        float t = DAT_011a8b40[i] * afScale;
        sum += GetKeyDerivativeLength(a1, a2, t) * DAT_011a8b2c[i];
    }
    return sum * afScale;
}

struct StrArr;
void __stdcall FUN_00a6d730(StrArr*);
struct S_00a4aeb0_Source
{
    int unk00;
    int unk04;
    int unk08;
    int(__cdecl* FUN_00a4aeb0_callback)(S_00a4aeb0_Source*, void*, int, int*, int);
};
struct S_00a4aeb0_Stream
{
    virtual void FUN_00a4aeb0_v00() = 0;
    virtual void FUN_00a4aeb0_v01() = 0;
    virtual void FUN_00a4aeb0_v02() = 0;
    virtual void FUN_00a4aeb0_v03() = 0;
    virtual void FUN_00a4aeb0_v04() = 0;
    virtual void FUN_00a4aeb0_v05() = 0;
    virtual void FUN_00a4aeb0_v06() = 0;
    virtual void FUN_00a4aeb0_v07() = 0;
    virtual void FUN_00a4aeb0_v08() = 0;
    virtual void FUN_00a4aeb0_v09() = 0;
    virtual void FUN_00a4aeb0_v10() = 0;
    virtual void FUN_00a4aeb0_v11() = 0;
    virtual void FUN_00a4aeb0_v12(int) = 0;
};
struct S_00a4aeb0_Source;
struct S_00a4aeb0_Controller
{
    void LoadFromStream(S_00a4aeb0_Stream& kStream);
};
inline int S_00a4aeb0_Read(S_00a4aeb0_Source* s, void* p, int n)
{
    int v = n;
    return s->FUN_00a4aeb0_callback(s, p, n, &v, 1);
}
// @fnv 0x00a4aeb0
void S_00a4aeb0_Controller::LoadFromStream(S_00a4aeb0_Stream& kStream)
{
    unsigned char* controller = reinterpret_cast<unsigned char*>(this);
    FUN_00a6d730(reinterpret_cast<StrArr*>(&kStream));
    {
        S_00a4aeb0_Source* src =
            *reinterpret_cast<S_00a4aeb0_Source**>(reinterpret_cast<unsigned char*>(&kStream) + 0x250);
        src->unk04 += S_00a4aeb0_Read(src, controller + 0x34, 2);
    }
    {
        S_00a4aeb0_Source* src =
            *reinterpret_cast<S_00a4aeb0_Source**>(reinterpret_cast<unsigned char*>(&kStream) + 0x250);
        src->unk04 += S_00a4aeb0_Read(src, controller + 0x60, 4);
    }
    {
        S_00a4aeb0_Source* src =
            *reinterpret_cast<S_00a4aeb0_Source**>(reinterpret_cast<unsigned char*>(&kStream) + 0x250);
        src->unk04 += S_00a4aeb0_Read(src, controller + 0x50, 4);
    }
    {
        S_00a4aeb0_Source* src =
            *reinterpret_cast<S_00a4aeb0_Source**>(reinterpret_cast<unsigned char*>(&kStream) + 0x250);
        src->unk04 += S_00a4aeb0_Read(src, controller + 0x54, 4);
    }
    {
        S_00a4aeb0_Source* src =
            *reinterpret_cast<S_00a4aeb0_Source**>(reinterpret_cast<unsigned char*>(&kStream) + 0x250);
        src->unk04 += S_00a4aeb0_Read(src, controller + 0x58, 2);
    }
    kStream.FUN_00a4aeb0_v12(*reinterpret_cast<int*>(controller + 0x40));
    kStream.FUN_00a4aeb0_v12(*reinterpret_cast<int*>(controller + 0x44));
}

void* __cdecl FUN_00aa13e0(unsigned int size) throw();
extern int DAT_0109893c;
extern float DAT_01012054;

struct SpawnedObject
{
    void* m_pVTable;
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
    unsigned short m34;
    unsigned short unk36;
    int m38;
    int m3c;
    int m40;
    int m44;
    void* m48;
    float m4c;
    float m50;
    float m54;
    unsigned short m58;
    unsigned short unk5a;
    float m5c;
    int m60;

    void InitBase() throw();
};

// Allocates a 0x64-byte SpawnedObject, runs InitBase, sets its vtable and initializes its fields, returning the object or null on allocation failure.
// @fnv 0x00a4b270
SpawnedObject* __cdecl FUN_00a4b270() throw()
{
    SpawnedObject* p = (SpawnedObject*)FUN_00aa13e0(0x64);
    if (p != 0)
    {
        p->InitBase();
        *(void* volatile*)&p->m_pVTable = (void*)&DAT_0109893c;
        *(int volatile*)&p->m40 = 0;
        *(int volatile*)&p->m44 = 0;
        *(float volatile*)&p->m50 = 0.0f;
        *(float volatile*)&p->m54 = 0.0f;
        *(float volatile*)&p->m5c = 0.0f;
        *(int volatile*)&p->m38 = 0;
        p->m4c = DAT_01012054;
        p->m3c = 0;
        p->m48 = 0;
        p->m58 = 0;
        p->m60 = 1;
        p->m34 = 3;
        return p;
    }
    return 0;
}

void __cdecl NiFree(void* p);
void* __cdecl FUN_00aa1070(unsigned int size);

struct Keys_a4
{
    int unk;
    int unkCur;
    unsigned int count;
};

struct FUN_00a4a8e0_cls
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0C;
    int uNewnk;
    int uTmpnk;
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
    Keys_a4* keys;
    int unk44;
    float* lengths;
    float totalLength;
    double FUN_00a4a6a0(unsigned int a1, unsigned int a2, float a3);
    float GetTotalLength();
};

// If totalLength is negative, rebuilds the lengths array from segment lengths and caches the total; returns totalLength.
// @fnv 0x00a4a8e0
float FUN_00a4a8e0_cls::GetTotalLength()
{
    if (totalLength < 0.0f)
    {
        unsigned int count = keys ? keys->count : 0;
        NiFree(lengths);
        lengths = (float*)FUN_00aa1070(count * sizeof(float));
        lengths[0] = 0.0f;
        for (unsigned int i = 0; i < count - 1; i++)
        {
            float fSegment = FUN_00a4a6a0(i, i + 1, 1.0f);
            float* p = lengths;
            p[i + 1] = p[i] + fSegment;
        }
        totalLength = lengths[count - 1];
    }
    return totalLength;
}

struct BinaryReader;
typedef unsigned int(__cdecl* ReadBinary)(BinaryReader*, void*, unsigned int, unsigned int*, int);
struct BinaryReader
{
    int context;
    unsigned int readPosition;
    ReadBinary read;
    void Read(void* dst, unsigned int n)
    {
        unsigned int bytes = n;
        readPosition += read(this, dst, n, &bytes, 1);
    }
};
struct VersionView
{
    unsigned int version;
};
struct ReaderView
{
    BinaryReader* reader;
};
struct LegacyView
{
    unsigned short flags;
};
struct NiStream;
void __stdcall func_0x00a6d5e0(NiStream* stream);
void __fastcall FUN_00a645b0(NiStream* stream);
template <class T> inline void StreamRead(NiStream& stream, T& dst)
{
    BinaryReader* reader = ((ReaderView*)((char*)&stream + 0x24c))->reader;
    reader->Read(&dst, sizeof(T));
}
struct NiPathControllerView
{
    char _00[0x34];
    unsigned short m_34;
    char _36[0x1a];
    unsigned int m_50;
    unsigned int m_54;
    unsigned short m_58;
    char _5a[6];
    unsigned int m_60;
    void ReadFromStream(NiStream* stream);
};
// @fnv 0x00a4acb0
void NiPathControllerView::ReadFromStream(NiStream* stream)
{
    func_0x00a6d5e0(stream);
    unsigned int mode;
    if (((VersionView*)((char*)stream + 0xd8))->version < 0x0a000102)
    {
        m_34 = ((LegacyView*)((char*)stream + 0x286))->flags >> 5;
    }
    else
    {
        StreamRead(*stream, m_34);
    }
    StreamRead(*stream, mode);
    m_60 = mode;
    StreamRead(*stream, m_50);
    StreamRead(*stream, m_54);
    StreamRead(*stream, m_58);
    FUN_00a645b0(stream);
    FUN_00a645b0(stream);
}

extern "C" double __cdecl fmod(double, double);
extern "C" double __cdecl fabs(double);
extern double DAT_01032980;
inline float PathRemainder(float x, float y)
{
    return (float)fmod(x, y);
}
struct PathController : FUN_00a4a8e0_cls
{
    void FUN_00a4a980(float time, unsigned int* first, unsigned int* second, float* position);
};
// Adjusts time to the unit interval, then finds the path segment and refines its local parameter for that distance.
// @fnv 0x00a4a980
void PathController::FUN_00a4a980(float time, unsigned int* apFirstKey, unsigned int* apSecondKey, float* apLocalParam)
{
    unsigned int count = keys ? keys->count : 0;
    if (time == 0.0f)
    {
        *apFirstKey = 0;
        *apSecondKey = 1;
        *apLocalParam = 0.0f;
        return;
    }
    if (time < 0.0f)
        time = PathRemainder(time, 1.0f) + 1.0f;
    if (time == 1.0f)
    {
        *apFirstKey = count - 2;
        *apSecondKey = count - 1;
        *apLocalParam = 1.0f;
        return;
    }
    if (time > 1.0f)
    {
        volatile float remainder = PathRemainder(time, 1.0f);
        time = remainder;
    }
    float distance = time * totalLength;
    unsigned int i = 0;
    unsigned int uiSecondKey = 1;
    float base = 0.0f;
    float t = 0.0f;
    for (; i < count - 1; ++i, ++uiSecondKey)
    {
        if (lengths[uiSecondKey] >= distance)
        {
            base = distance - lengths[i];
            t = base / (lengths[uiSecondKey] - lengths[i]);
            break;
        }
    }
    int iteration = 0;
    do
    {
        float error = ((FUN_00a4a6a0_cls*)this)->FUN_00a4a6a0(i, uiSecondKey, t) - base;
        if ((float)fabs(error) <= DAT_01032980)
            break;
        t = t - (double)error / ((FUN_00a4a6a0_cls*)this)->GetKeyDerivativeLength(i, uiSecondKey, t);
        ++iteration;
    } while (iteration < 32);
    *apFirstKey = i;
    *apSecondKey = uiSecondKey;
    *apLocalParam = t;
}

struct PathIndices
{
    int first;
    int second;
};
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct ThreeByThreeMatrix
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
};

struct PathTarget
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
    ThreeByThreeMatrix m_kRotate;
    NiPoint3 m_kTranslate;
};

struct PathKeyData
{
    int unk00;
    int unk04;
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;

    void* ComputePositionAtTime(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize) const
    {
        uiNumKeys = m_uiNumKeys;
        eType = m_eRequestType;
        ucSize = m_ucKeyDataSize;
        return m_pKeyArray;
    }
};

float __cdecl InterpolateKey(float fTime, void* pkKeys, int eType, unsigned int uiNumKeys, unsigned int& uiLastIdx,
                             unsigned char ucSize);

struct PathCtlr
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
    float m_fControllerTime;
    PathTarget* m_pkTarget;
    int unk30;
    unsigned short m_usFlags;
    bool GetFollow() const
    {
        return (m_usFlags >> 5) & 1;
    }
    int unk38;
    unsigned int m_uiPercentKeyCount;
    PathKeyData* m_pPathObject;
    PathKeyData* m_pPathInterp;

    bool FUN_00a36250(float fTime);
    void FUN_00a4ab50(float fPct, int* piIdx1, int* piIdx2, float* pfPct);
    void FUN_00a49e70(int iIdx1, int iIdx2, float fPct, ThreeByThreeMatrix* pkRot);
    void InvokeIndexedCallback(NiPoint3* result, int iIdx1, int iIdx2, float fPct);
    void UpdatePathTarget(float* pfTime);
};

// Evaluates the percent and path keys at controller time, writes translation to m_pkTarget, and writes rotation when follow is enabled.
// @fnv 0x00a4afa0
void PathCtlr::UpdatePathTarget(float* apfTime)
{
    if (!m_pPathInterp)
        return;
    unsigned int uiNumPctKeys;
    int ePctType;
    unsigned char ucPctSize;
    void* pkPctKeys = m_pPathInterp->ComputePositionAtTime(uiNumPctKeys, ePctType, ucPctSize);
    if (!pkPctKeys || !m_pPathObject)
        return;
    unsigned int uiNumPathKeys;
    int ePathType;
    unsigned char ucPathSize;
    void* pkPathKeys = m_pPathObject->ComputePositionAtTime(uiNumPathKeys, ePathType, ucPathSize);
    if (!pkPathKeys)
        return;
    if (FUN_00a36250(*apfTime))
        return;

    float fPct = InterpolateKey(m_fControllerTime, pkPctKeys, ePctType, uiNumPctKeys, m_uiPercentKeyCount, ucPathSize);
    {
        PathIndices stIndices;
        FUN_00a4ab50(fPct, (int*)&stIndices.first, (int*)&stIndices.second, &fPct);
        int i2;
        if ((GetFollow() ? (i2 = stIndices.second, true) : (i2 = stIndices.second, false)))
        {
            ThreeByThreeMatrix kRot;
            FUN_00a49e70(stIndices.first, i2, fPct, &kRot);
            m_pkTarget->m_kRotate = kRot;
        }
        NiPoint3 kPos;
        InvokeIndexedCallback(&kPos, stIndices.first, i2, fPct);
        m_pkTarget->m_kTranslate = kPos;
    }
}

#include <math.h>
extern void(__cdecl* DAT_011f3c18[])(float, AnimationKey const*, AnimationKey const*, void*);

struct NiPoint3A4A6
{
    float x, y, z;
};

struct NiPosDataA4A6
{
    int unk00, unk04, unk08;
    AnimationKey* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;
};

struct FUN_00a4a610_shell
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    NiPosDataA4A6* m_spPosData;

    float GetKeyDerivativeLength(unsigned int uiKey1, unsigned int uiKey2, float fTime);
};

// Computes the length of the derivative vector between two animation keys at a given time using a type-specific function pointer.
// @fnv 0x00a4a610
float FUN_00a4a610_shell::GetKeyDerivativeLength(unsigned int uiKey1, unsigned int uiKey2, float fTime)
{
    unsigned int uiRequestType;
    unsigned char ucSize;
    AnimationKey* pkKeys;
    NiPosDataA4A6* pkData = m_spPosData;
    if (pkData)
    {
        uiRequestType = pkData->m_eRequestType;
        ucSize = pkData->m_ucKeyDataSize;
        pkKeys = pkData->m_pKeyArray;
    }
    else
    {
        uiRequestType = 0;
        pkKeys = 0;
        ucSize = 0;
    }

    NiPoint3A4A6 kDeriv;
    DAT_011f3c18[uiRequestType](fTime, (AnimationKey*)((char*)pkKeys + uiKey1 * ucSize),
                                (AnimationKey*)((char*)pkKeys + uiKey2 * ucSize), &kDeriv);
    float fLengthSquared = kDeriv.x * kDeriv.x + kDeriv.y * kDeriv.y + kDeriv.z * kDeriv.z;
    return (float)sqrt(fLengthSquared);
}

struct ShortField
{
    unsigned short value;
    __forceinline ShortField(unsigned short n) : value(n)
    {}
    __forceinline ShortField& operator=(unsigned short n)
    {
        value = n;
        return *this;
    }
};
void __fastcall FUN_00a6d220(void* object);
struct PathBase
{
    void* m_pVTable;
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
    __forceinline PathBase()
    {
        FUN_00a6d220(this);
        m_pVTable = &DAT_0109893c;
    }
};
struct PathRef
{
    void* m_pObject;
    PathRef() : m_pObject(0)
    {}
};
struct PathObject : PathBase
{
    unsigned short m34;
    unsigned short unk36;
    int m38;
    int m3c;
    PathRef m40;
    PathRef m44;
    void* m48;
    float m4c;
    float m50;
    float m54;
    unsigned short m58;
    unsigned short unk5a;
    float m5c;
    int m60;
    __forceinline PathObject()
    {
        m50 = 0.0f;
        m54 = 0.0f;
        m5c = 0.0f;
        m4c = DAT_01012054;
        m38 = 0;
        m3c = 0;
        m60 = 1;
        m58 = 0;
        m48 = 0;
        m34 = 3;
    }
};
struct PathShell
{
    void FUN_00a4b0b0(PathObject*, int);
    PathObject* CreatePathObject(int value);
};
// Allocates and initializes a PathObject, then calls FUN_00a4b0b0 with the given value and returns the new object or null.
// @fnv 0x00a4b330
PathObject* PathShell::CreatePathObject(int value)
{
    PathObject* object = (PathObject*)FUN_00aa13e0(0x64);
    PathObject* result;
    if (object)
    {
        object->PathObject::PathObject();
        result = object;
    }
    else
    {
        result = 0;
    }
    FUN_00a4b0b0(result, value);
    return result;
}

#include <string.h>
struct NiObject
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual bool IsEqual(NiObject* pkObject);
};

struct NiTimeControllerStub : NiObject
{
    bool TimeControllerIsEqual(NiObject* pkObject);
};

struct NiPtr
{
    NiObject* m_pObject;
    operator NiObject*() const
    {
        return m_pObject;
    }
    NiObject* operator->() const
    {
        return m_pObject;
    }
};

struct NiPathControllerStub : NiTimeControllerStub
{
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
    unsigned short m_uiObjectFlags;
    short unk36;
    int unk38;
    int unk3c;
    NiPtr m_pPathObject;
    NiPtr m_pPathInterp;
    unsigned int* m_pkPartLengths;
    float unk4c;
    float unk50;
    float unk54;
    short unk58;
    short unk5a;
    int unk5c;
    int unk60;

    bool GetBit(int n) const
    {
        return ((m_uiObjectFlags >> n) & 1) ? true : false;
    }
    void GetLengths(unsigned int* a, unsigned int* count, int* c, unsigned char* d);
    bool FUN_00a4a710(NiObject* pkObject);
};

// Compares this NiPathControllerStub with pkObject, checking path, interpolation, part lengths, and various flags and fields for equality.
// @fnv 0x00a4a710
bool NiPathControllerStub::FUN_00a4a710(NiObject* pkObject)
{
    if (!TimeControllerIsEqual(pkObject))
        return false;

    NiPathControllerStub* pkOther = (NiPathControllerStub*)pkObject;

    if (!m_pPathObject->IsEqual(pkOther->m_pPathObject))
        return false;
    if (!m_pPathInterp->IsEqual(pkOther->m_pPathInterp))
        return false;

    if (m_pkPartLengths && !pkOther->m_pkPartLengths)
        return false;
    if (!m_pkPartLengths && pkOther->m_pkPartLengths)
        return false;

    if (m_pkPartLengths)
    {
        unsigned int* pkLengths = m_pkPartLengths;
        unsigned int a;
        unsigned int ItemUpdateArray;
        int c;
        unsigned char d;
        GetLengths(&a, &ItemUpdateArray, &c, &d);
        if (memcmp(pkLengths, pkOther->m_pkPartLengths, ItemUpdateArray * sizeof(unsigned int)) != 0)
            return false;
    }

    if (unk4c != pkOther->unk4c || pkOther->GetBit(0) != GetBit(0) || pkOther->GetBit(1) != GetBit(1) ||
        unk60 != pkOther->unk60 || pkOther->GetBit(2) != GetBit(2) || pkOther->GetBit(3) != GetBit(3) ||
        pkOther->GetBit(4) != GetBit(4) || pkOther->GetBit(5) != GetBit(5) || unk50 != pkOther->unk50 ||
        unk54 != pkOther->unk54 || unk58 != pkOther->unk58 || pkOther->GetBit(6) != GetBit(6))
    {
        return false;
    }
    return true;
}

#include <windows.h>
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};
struct RefObj : NiRefObject
{
    unsigned int m_08;
    const void* m_0c;
    unsigned int m_10;
};

struct SampleData
{
    unsigned int index;
    const void* value;
};
struct SpawnedArg
{
    RefObj* FUN_00a63430();
};

extern float(__cdecl* DAT_011f3d38[])(const void*, unsigned int);

struct FUN_00a4adc0_cls
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
    unsigned short m_34;
    unsigned short unk36;
    int unk38;
    int unk3c;
    RefObj* m_40;
    RefObj* m_44;
    int unk48;
    float m_4c;
    int unk50;
    int unk54;
    int unk58;
    float m_5c;

    float GetTotalLength();
    void FUN_00a6d500(SpawnedArg* a);
    void SetSpawnedArgs(SpawnedArg* a);
};

// Updates m_40 and m_44 from a SpawnedArg, sets a flag in m_34, and computes m_4c and m_5c from the current m_40 sample data.
// @fnv 0x00a4adc0
void FUN_00a4adc0_cls::SetSpawnedArgs(SpawnedArg* apSpawnedArg)
{
    FUN_00a6d500(apSpawnedArg);

    RefObj* p = apSpawnedArg->FUN_00a63430();
    RefObj* old = m_40;
    if (old != p)
    {
        if (old != 0)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)) == 0)
            {
                old->DeleteThis();
            }
        }
        m_40 = p;
        if (p != 0)
        {
            InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
        }
    }

    p = apSpawnedArg->FUN_00a63430();
    old = m_44;
    if (old != p)
    {
        if (old != 0)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)) == 0)
            {
                old->DeleteThis();
            }
        }
        m_44 = p;
        if (p != 0)
        {
            InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
        }
    }

    unsigned char bit = 1;
    m_34 |= bit;
    unsigned char hi = (unsigned char)(m_34 >> 4);
    if ((hi & bit) != 0 && ((unsigned char)m_34 & bit) != 0)
    {
        m_4c = GetTotalLength();
        m_34 &= ~bit;
    }

    RefObj* t = m_40;
    if (t != 0)
    {
        unsigned int count = t->m_08;
        SampleData sample = {t->m_10, t->m_0c};
        if (count > 0)
        {
            float(__cdecl * pfnSample)(const void*, unsigned int) = DAT_011f3d38[sample.index];
            m_5c = pfnSample(sample.value, count);
        }
    }
}

__declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void* NiMalloc(unsigned int);

struct PathRefObj
{
    virtual void v00();
    virtual void DeleteThis();
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
    virtual PathRefObj* MakeClone(void* kCloning);
    long m_uiRefCount;
    unsigned int m_uiNumKeys;

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

struct PathRefPtr
{
    PathRefObj* m_pObject;
    PathRefPtr& operator=(PathRefObj* p)
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
    operator PathRefObj*() const
    {
        return m_pObject;
    }
    PathRefObj* operator->() const
    {
        return m_pObject;
    }
};

struct CloneableObj
{
    void* m_pVTable;
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
    void FUN_00a6cfe0(CloneableObj* pDest, void* kCloning);
};

struct PathCtl : CloneableObj
{
    unsigned short m_uiObjectFlags;
    unsigned short unk36;
    int unk38;
    int unk3c;
    PathRefPtr m_pPathObject;
    PathRefPtr m_pPathInterp;
    float* m_pfPathLengths;
    float m_fTotalPathLength;
    float m50;
    float m54;
    unsigned short m58;
    unsigned short unk5a;
    float unk5c;
    int m60;

    float GetTotalLength();
    bool GetBit(int pos) const
    {
        return ((m_uiObjectFlags >> pos) & 1) != 0;
    }
    void SetBit(bool b, unsigned short mask)
    {
        if (b)
            m_uiObjectFlags |= mask;
        else
            m_uiObjectFlags &= ~mask;
    }
    void SetConstVelocity(bool b)
    {
        SetBit(b, 0x10);
        if (b && GetBit(0))
        {
            m_fTotalPathLength = GetTotalLength();
            m_uiObjectFlags &= ~1;
        }
    }
    void FUN_00a4b0b0(PathCtl* pDest, void* kCloning);
};

// Copies PathCtl state into pDest, cloning m_pPathObject and m_pPathInterp, and duplicating the m_pfPathLengths array.
// @fnv 0x00a4b0b0
void PathCtl::FUN_00a4b0b0(PathCtl* pDest, void* kCloning)
{
    CloneableObj::FUN_00a6cfe0(pDest, kCloning);
    pDest->m_uiObjectFlags = m_uiObjectFlags;

    if (m_pPathObject)
        pDest->m_pPathObject = m_pPathObject->MakeClone(kCloning);
    if (m_pPathInterp)
        pDest->m_pPathInterp = m_pPathInterp->MakeClone(kCloning);

    pDest->SetBit(GetBit(2), 4);
    pDest->SetBit(GetBit(3), 8);
    pDest->m60 = m60;
    pDest->SetConstVelocity(GetBit(4));
    pDest->SetBit(GetBit(5), 0x20);
    pDest->m50 = m50;
    pDest->m54 = m54;
    pDest->m58 = m58;
    pDest->SetBit(GetBit(6), 0x40);
    pDest->SetBit(GetBit(1), 2);

    if (m_pfPathLengths)
    {
        unsigned int uiSize = (m_pPathObject ? m_pPathObject->m_uiNumKeys : 0) * sizeof(float);
        pDest->m_pfPathLengths = (float*)NiMalloc(uiSize);
        memcpy(pDest->m_pfPathLengths, m_pfPathLengths, uiSize);
    }
    pDest->m_fTotalPathLength = m_fTotalPathLength;
}

#include <math.h>
namespace fnv_00a49e70 {
// Refines the prior NiPathController draft, another contributor (2026-10-23).
extern "C" double __cdecl atan(double);
extern "C" double __cdecl sqrt(double);
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    NiPoint3 operator+(const NiPoint3&) const;
    void FUN_004a0c10();
    NiPoint3 Cross(const NiPoint3&) const;
    __declspec(noinline) NiPoint3 FUN_0053d1a0(const NiPoint3& v) const
    {
        NiPoint3 r(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
        float len = (float)sqrt(r.x * r.x + r.y * r.y + r.z * r.z);
        if (len != 0.0f)
        {
            r.x /= len;
            r.y /= len;
            r.z /= len;
        }
        return r;
    }
    NiPoint3 operator-() const
    {
        NiPoint3 r(-x, -y, -z);
        return r;
    }
    NiPoint3 InlineCross(const NiPoint3& v) const
    {
        NiPoint3 r(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
        return r;
    }
};
NiPoint3 __cdecl FUN_004a3760(float, const NiPoint3&);
struct PathMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    PathMatrix()
    {}
    PathMatrix(float, float, float, float);
    PathMatrix FUN_0043f8d0(const PathMatrix&) const;
    void Set0(const NiPoint3& v)
    {
        m00 = v.x;
        m10 = v.y;
        m20 = v.z;
    }
    void Set1(const NiPoint3& v)
    {
        m01 = v.x;
        m11 = v.y;
        m21 = v.z;
    }
    void Set2(const NiPoint3& v)
    {
        m02 = v.x;
        m12 = v.y;
        m22 = v.z;
    }
    void Get0(NiPoint3& v) const
    {
        v.x = m00;
        v.y = m10;
        v.z = m20;
    }
    NiPoint3 Get1() const
    {
        NiPoint3 v(m01, m11, m21);
        return v;
    }
    NiPoint3 Get2() const
    {
        NiPoint3 v(m02, m12, m22);
        return v;
    }
};
extern const PathMatrix DAT_011a9448;
extern const NiPoint3 DAT_011a9484;
extern float DAT_01097304;
void __cdecl ComputeFrenetFrame(float, const AnimationKey*, const AnimationKey*, int, NiPoint3*, NiPoint3*, NiPoint3*,
                                float*);
inline float& GetBankFactor()
{
    static float f = DAT_01097304;
    return f;
}
struct PathKeys
{
    int unk00, unk04;
    unsigned count;
    const AnimationKey* base;
    int type;
    unsigned char size;
};
struct PathController
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    union
    {
        unsigned short flags;
        struct
        {
            unsigned short flag0 : 1;
            unsigned short flag1 : 1;
            unsigned short follow : 1;
            unsigned short bankEnabled : 1;
            unsigned short flag4 : 1;
            unsigned short flag5 : 1;
            unsigned short reverse : 1;
        };
    };
    unsigned short unk36;
    int unk38, unk3c;
    PathKeys* keys;
    int unk44, unk48;
    float unk4c, bankAngle, smoothing;
    short axis, unk5a;
    float maxCurvature;
    int bankDirection;
    bool IsFollow() const
    {
        return (flags & 4) >> 2;
    }
    bool IsReverse() const
    {
        return (flags & 64) >> 6;
    }
    bool IsBank() const
    {
        return (flags & 8) >> 3;
    }
    bool IsFlag1() const
    {
        return (flags & 2) >> 1;
    }
    void FUN_00a49e70(unsigned, unsigned, float, PathMatrix&);
};

// Evaluates the path at time t between keys first and second, applying smoothing, axis, reverse, and bank to produce the output matrix.
// @fnv 0x00a49e70
void PathController::FUN_00a49e70(unsigned aiFirstKey, unsigned aiSecondKey, float afTime, PathMatrix& output)
{
    PathKeys* data = keys;
    NiPoint3 vTangent;
    PathMatrix result;
    NiPoint3 position;
    NiPoint3 normal;
    result = DAT_011a9448;
    if (data)
    {
        unsigned count = data->count;
        int type = data->type;
        unsigned char size = data->size;
        const AnimationKey* base = data->base;
        if (count < 2)
        {
            output = result;
            return;
        }

        float curvature, w1;
        if (IsFollow())
        {
            float otherCurvature;
            ComputeFrenetFrame(afTime, (const AnimationKey*)((const char*)base + size * aiFirstKey),
                               (const AnimationKey*)((const char*)base + size * aiSecondKey), type, &position,
                               &vTangent, &normal, &curvature);
            if (smoothing != 0.0f)
            {
                unsigned adjacent;
                float w0;
                NiPoint3 vScratch, vOther;

                if (afTime >= 1.0f - smoothing)
                {
                    adjacent = !IsFlag1() && aiSecondKey == count - 1 ? 0 : aiSecondKey;
                    if (adjacent < count - 1)
                    {
                        w0 = (1.0f - afTime + smoothing) / (smoothing * 2.0f);
                        w1 = 1.0f - w0;
                        float u = 1.0f - smoothing;
                        ComputeFrenetFrame(u, (const AnimationKey*)((const char*)base + size * aiFirstKey),
                                           (const AnimationKey*)((const char*)base + size * aiSecondKey), type,
                                           &vScratch, &vTangent, &normal, &curvature);
                        ComputeFrenetFrame(smoothing, (const AnimationKey*)((const char*)base + size * adjacent),
                                           (const AnimationKey*)((const char*)base + size * (adjacent + 1)), type,
                                           &vScratch, &vOther, &normal, &otherCurvature);
                        vTangent = FUN_004a3760(w0, vTangent) + FUN_004a3760(w1, vOther);
                        vTangent.FUN_004a0c10();
                        curvature = w1 * otherCurvature + w0 * curvature;
                        normal = position.Cross(vTangent);
                    }
                }
                else if (afTime <= smoothing)
                {
                    adjacent = !IsFlag1() && aiFirstKey == 0 ? count - 1 : aiFirstKey;
                    if (adjacent >= 1)
                    {
                        w1 = (smoothing - afTime) / (smoothing * 2.0f);
                        w0 = 1.0f - w1;
                        ComputeFrenetFrame(smoothing, (const AnimationKey*)((const char*)base + size * aiFirstKey),
                                           (const AnimationKey*)((const char*)base + size * aiSecondKey), type,
                                           &vScratch, &vTangent, &normal, &curvature);
                        float u = 1.0f - smoothing;
                        ComputeFrenetFrame(u, (const AnimationKey*)((const char*)base + size * (adjacent - 1)),
                                           (const AnimationKey*)((const char*)base + size * adjacent), type, &vScratch,
                                           &vOther, &normal, &otherCurvature);
                        vTangent = FUN_004a3760(w0, vTangent) + FUN_004a3760(w1, vOther);
                        vTangent.FUN_004a0c10();
                        curvature = w1 * otherCurvature + w0 * curvature;
                        normal = position.Cross(vTangent);
                    }
                }
            }
            result.Set0(position);
            result.Set1(-vTangent);
            result.Set2(-normal);
        }
        else
        {
            ComputeFrenetFrame(afTime, (const AnimationKey*)((const char*)base + size * aiFirstKey),
                               (const AnimationKey*)((const char*)base + size * aiSecondKey), type, &position,
                               &vTangent, &normal, &curvature);
            result.Set0(position);
            NiPoint3 vUp = DAT_011a9484.FUN_0053d1a0(position);
            result.Set1(vUp);
            result.Set2(position.InlineCross(vUp));
        }
        if (IsReverse())
        {
            result.Set0(-position);
            result.Set1(-result.Get1());
        }
        NiPoint3 old;
        switch (axis)
        {
        case 1: {
            result.Get0(old);
            result.Set0(-result.Get1());
            result.Set1(old);
            break;
        }
        case 2: {
            result.Get0(old);
            result.Set0(-result.Get2());
            result.Set2(old);
            break;
        }
        }
        if (IsBank())
        {
            NiPoint3 vAxis = position;
            float& factor = GetBankFactor();
            float angle = bankDirection * bankAngle;
            if (curvature < maxCurvature)
            {
                float ratio = curvature / maxCurvature;
                ratio = (float)atan(ratio);
                angle = ratio * factor * angle;
            }
            PathMatrix bank(angle, vAxis.x, vAxis.y, vAxis.z);
            result = bank.FUN_0043f8d0(result);
        }
    }
    output = result;
}
}  // namespace fnv_00a49e70

struct TimeKey
{
    float time;
    float Time() const
    {
        return time;
    }
    TimeKey* At(unsigned int i, unsigned char stride) const
    {
        return (TimeKey*)((char*)this + i * stride);
    }
};
struct PositionKey : TimeKey
{
    PositionKey* At(unsigned int i, unsigned char stride)
    {
        return (PositionKey*)TimeKey::At(i, stride);
    }
};
struct RetryCtlr : CloneableObj
{
    unsigned short flags;
    unsigned short unk36;
    bool IsFollow() const
    {
        return ((flags >> 4) & 1) != 0;
    }
    unsigned int lastIdx;
    int unk3C;
    PathKeyData* data;
    PositionKey* GetKeys(unsigned int& n, int& kind, unsigned char& stride) const
    {
        if (data)
            return (PositionKey*)data->ComputePositionAtTime(n, kind, stride);
        n = 0;
        kind = 0;
        stride = 0;
        return 0;
    }
    void FUN_00a4a980(float t, unsigned int& i0, unsigned int& i1, float& frac);
    void FUN_00a4ab50(float t, unsigned int& i0, unsigned int& i1, float& frac);
};
// Selects two key indices and a fraction for t, using path-distance lookup when follow is enabled.
// @fnv 0x00a4ab50
void RetryCtlr::FUN_00a4ab50(float afTime, unsigned int& aiKey0, unsigned int& aiKey1, float& frac)
{
    if (IsFollow())
    {
        FUN_00a4a980(afTime, aiKey0, aiKey1, frac);
        lastIdx = aiKey0;
        return;
    }
    unsigned int n;
    int kind;
    unsigned char sz;
    PositionKey* keys;
    PathKeyData* d = data;
    if (d)
    {
        keys = (PositionKey*)d->ComputePositionAtTime(n, kind, sz);
    }
    else
    {
        n = 0;
        kind = 0;
        keys = 0;
        sz = 0;
    }
    if (afTime <= keys->At(0, sz)->Time())
    {
        aiKey0 = 0;
        aiKey1 = 1;
        frac = 0.0f;
        return;
    }
    if (afTime >= keys->At(n - 1, sz)->Time())
    {
        aiKey0 = n - 2;
        aiKey1 = n - 1;
        frac = 1.0f;
        return;
    }
    bool found = false;
    unsigned int idx = lastIdx;
    bool first = true;
    unsigned int next = 0;
    while (idx < n - 1)
    {
        if (afTime == keys->At(idx, sz)->Time())
        {
            lastIdx = idx;
            next = idx + 1;
            found = true;
            break;
        }
        else if (keys->At(idx, sz)->Time() < afTime && afTime < keys->At(idx + 1, sz)->Time())
        {
            lastIdx = idx;
            next = idx + 1;
            found = true;
            break;
        }
        if (idx == n - 2 && first)
        {
            idx = 0;
            first = false;
        }
        else
        {
            idx++;
        }
    }
    frac = (afTime - keys->At(idx, sz)->Time()) / (keys->At(next, sz)->Time() - keys->At(idx, sz)->Time());
    aiKey0 = idx;
    aiKey1 = next;
}
