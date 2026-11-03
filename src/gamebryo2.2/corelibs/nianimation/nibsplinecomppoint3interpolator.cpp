// gamebryo2.2/corelibs/nianimation/nibsplinecomppoint3interpolator.cpp: NiBSplineCompPoint3Interpolator, SplineEvaluationState (8 functions)

#include "nibsplinecomppoint3interpolator_decls.h"
// Calls the base LoadBinary, then reads 8 bytes from the stream's input into the interpolator's data.
// @fnv 0x00a51400
void NiBSplineCompPoint3Interpolator::LoadBinary(NiStream& stream)
{
    NiBSplinePoint3Interpolator::LoadBinary(stream);
    NiBinaryStream* input = stream.input;
    input->Read(&m_fSequenceOffset, 8);
}

extern "C" void* g_011f4014;

// @fnv 0x00a51270
void* __cdecl NiBSplineCompPoint3Interpolator_GetRTTI()
{
    return &g_011f4014;
}

struct NiObject
{
    char _d;
};
struct BaseFor51230
{
    bool NiBSplinePoint3Interpolator_IsEqual(NiObject* pkObject);
    char _pad[0x2c];
};
struct OwnerFor51230 : BaseFor51230
{
    float m_afOffsetAndHalfRange[2];
    bool NiBSplineCompPoint3Interpolator_IsEqual(NiObject* pkObject);
};
// @fnv 0x00a51230
bool OwnerFor51230::NiBSplineCompPoint3Interpolator_IsEqual(NiObject* pkObject)
{
    OwnerFor51230* pkDest;
    unsigned int iIndex;
    if (!NiBSplinePoint3Interpolator_IsEqual(pkObject))
        return false;
    pkDest = (OwnerFor51230*)pkObject;
    for (iIndex = 0; iIndex < 2; iIndex++)
    {
        if (m_afOffsetAndHalfRange[iIndex] != pkDest->m_afOffsetAndHalfRange[iIndex])
            return false;
    }
    return true;
}

struct StrArr
{
    char _pad[8];
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short _pad2;
    unsigned short m_usGrow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
void __stdcall NiBSplinePoint3Interpolator_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// Grows the string array if it is full, then appends the string returned by _FUN_00a7d330(g_011f4014) at the current size index.
// @fnv 0x00a51480
void __stdcall NiBSplineCompPoint3Interpolator_GetViewerStrings(StrArr* pkStrings)
{
    NiBSplinePoint3Interpolator_GetViewerStrings(pkStrings);
    char* pszStr = _FUN_00a7d330((const char*)g_011f4014);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiMax = pkStrings->m_usMax;
    if (uiSize >= uiMax)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrow);
    pkStrings->SetAt(uiSize, pszStr);
}

struct Vec3
{
    float x, y, z;
    Vec3()
    {}
    Vec3(float inX, float inY, float inZ) : x(inX), y(inY), z(inZ)
    {}
};
struct SplinePath
{
    void __thiscall FUN_00a526b0(float time, float* output, unsigned int count, unsigned int offset, unsigned int index,
                                 float scale, float bias);
};
struct SplineEvaluationState
{
    unsigned int unk00;
    unsigned int unk04;
    float lastTime;
    float startTime;
    float endTime;
    SplinePath* spline;
    unsigned int componentOffset;
    Vec3 lastValue;
    unsigned int controlPointIndex;
    float scale;
    float bias;

    bool __thiscall EvaluateSplineAtTime(float time, unsigned int unused, Vec3* out);
};
// @fnv 0x00a51280
bool SplineEvaluationState::EvaluateSplineAtTime(float time, unsigned int unused, Vec3* out)
{
    if (lastTime == time)
    {
        *out = lastValue;
        return true;
    }
    if (controlPointIndex != 0xffff)
    {
        float samples[4];
        float normalized = (time - startTime) / (endTime - startTime);
        spline->FUN_00a526b0(normalized, samples, 3, componentOffset, controlPointIndex, scale, bias);
        Vec3 updatedValue(samples[0], samples[1], samples[2]);
        lastValue = updatedValue;
    }
    *out = lastValue;
    lastTime = time;
    return true;
}

struct CompBinaryStreamView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(CompBinaryStreamView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    void LoadArray(float* values, unsigned int count)
    {
        unsigned int size = 4;
        absolutePosition += read(this, values, 4 * count, &size, 1);
    }
};

struct CompStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    CompBinaryStreamView* m_pUnderlyingStream;
};

struct Point3InterpolatorStand
{
    void* vtable;
    char unk04[0x28];
    void LoadStream(NiStream& stream);
};

struct FUN_00a51440_cls : public NiBSplineCompPoint3Interpolator
{
    void NiBSplineCompPoint3Interpolator_SaveBinary(NiStream& stream);
};

// Loads the base point3 interpolator from the stream, then reads two floats into the array via the binary stream.
// @fnv 0x00a51440
void FUN_00a51440_cls::NiBSplineCompPoint3Interpolator_SaveBinary(NiStream& stream)
{
    reinterpret_cast<Point3InterpolatorStand*>(this)->LoadStream(stream);

    CompStreamView* pStream = reinterpret_cast<CompStreamView*>(&stream);
    CompBinaryStreamView* pBinaryStream = pStream->m_pUnderlyingStream;

    pBinaryStream->LoadArray(&m_fSequenceOffset, 2);
}

class CloningProcessA513;
const float DAT_01099a1c = 3.402823466e+38f;
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

class FUN_00a506c0
{
  public:
    FUN_00a506c0(int a, int b, int c) throw();
    virtual ~FUN_00a506c0() throw();
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
};

class ObjA513 : public FUN_00a506c0
{
  public:
    ObjA513() throw() : FUN_00a506c0(0, 0xffff, 0)
    {}
    virtual ~ObjA513() throw();

    static void* operator new(unsigned int n)
    {
        return BSFadeNode::operator new(n);
    }

    float m_2c;
    float m_30;

    void CopyUnknownFields(ObjA513* dest, CloningProcessA513& cloning);
    ObjA513* NiBSplineCompPoint3Interpolator_CreateClone(CloningProcessA513& cloning);
};

// Allocates a new ObjA513, copies unknown fields via cloning, then overwrites m_2c and m_30 with the source values and returns the new object.
// @fnv 0x00a51360
ObjA513* ObjA513::NiBSplineCompPoint3Interpolator_CreateClone(CloningProcessA513& cloning)
{
    ObjA513* pNew = new ObjA513;
    if (pNew)
    {
        pNew->m_30 = pNew->m_2c = DAT_01099a1c;
    }
    else
    {
        pNew = 0;
    }
    CopyUnknownFields(pNew, cloning);
    pNew->m_2c = m_2c;
    pNew->m_30 = m_30;
    return pNew;
}

extern "C" void* g_011f4014;
void* __cdecl NiBSplineCompPoint3Interpolator_GetRTTI();

void __stdcall NiBSplinePoint3Interpolator_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
void __stdcall NiBSplineCompPoint3Interpolator_GetViewerStrings(StrArr* pkStrings);

extern void* FUN_00aa13e0(unsigned int bytes) throw();

struct Base506
{
    char pad[0x28];
    virtual void vf0() throw();
    Base506(int a, unsigned int b, int c) throw();
};

struct Pair
{
    float hi; /* +0x2c */
    float lo; /* +0x30 */
    Pair() throw()
    {
        lo = hi = 3.4028234663852886e+038f;
    }
};
struct Comp4 : Base506
{
    Pair m_pair;
    static void* operator new(unsigned int bytes) throw()
    {
        return FUN_00aa13e0(bytes);
    }
    Comp4() throw() : Base506(0, 0xffff, 0)
    {}
};
// Allocates and returns a new Comp4 instance on the heap.
// @fnv 0x00a513c0
void* __cdecl CreateComp4()
{
    return new Comp4();
}
