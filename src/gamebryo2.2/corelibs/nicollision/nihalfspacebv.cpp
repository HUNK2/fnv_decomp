
// src/gamebryo2.2/corelibs/nicollision/nihalfspacebv.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nihalfspacebv.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiBoundingVolume
{
    virtual ~NiBoundingVolume();
};

struct NiHalfSpaceBV : NiBoundingVolume
{
    void SetWaterColorParameter();
};

extern "C" void __cdecl SetFromPlane(const NiBoundingVolume* kABV);

// @fnv 0x00e9cc10
void __cdecl FUN_00e9cc10(const NiBoundingVolume* kABV)
{
    SetFromPlane(kABV + 1);
}

// @fnv 0x00e9e670
int __cdecl FUN_00e9e670()
{
    return 5;
}

struct NiStream;
struct NiSphere
{
    void SaveBinary(NiStream&);
};
struct NiColor
{
    void SaveBinary(NiStream&);
};
struct NiBoundingVolume_SaveHelper
{
    void SaveBinary(NiStream&);
};
struct FUN_00e9cb80_Holder
{
    void FUN_00e9cb80(NiStream&);
};
// Saves the bounding volume, sphere and color sub-objects to the stream in sequence.
// @fnv 0x00e9cb80
void FUN_00e9cb80_Holder::FUN_00e9cb80(NiStream& kStream)
{
    ((NiBoundingVolume_SaveHelper*)this)->SaveBinary(kStream);
    ((NiSphere*)((char*)this + 4))->SaveBinary(kStream);
    ((NiColor*)((char*)this + 0x14))->SaveBinary(kStream);
}

struct Q
{
    bool FUN_00a92660(const Q&) const;
};
struct BVProxy
{
    virtual void _f0();
    virtual void _f1();
    virtual void _f2();
    virtual int _f3() const;
};
struct Holder00e9cc20
{
    int MatchesBoundingVolume(const NiBoundingVolume&) const;
};
// Returns 1 when kABV's proxy type is 5 and the Q at offset 4 matches the Q at offset 4 of this; otherwise 0.
// @fnv 0x00e9cc20
int Holder00e9cc20::MatchesBoundingVolume(const NiBoundingVolume& kABV) const
{
    if (reinterpret_cast<const BVProxy&>(kABV)._f3() == 5)
    {
        if (reinterpret_cast<const Q*>(reinterpret_cast<const char*>(&kABV) + 4)
                ->FUN_00a92660(*reinterpret_cast<const Q*>(reinterpret_cast<const char*>(this) + 4)))
            return 1;
    }
    return 0;
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};
extern NiPoint3 DAT_011a9478;
extern NiPoint3 _NiPoint3_ZERO;
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct FUN_00e9e700_Helper
{
    NiBoundingVolume* FUN_00e9e680(const NiPoint3&, const NiPoint3&);
};
// @fnv 0x00e9e700
NiBoundingVolume* FUN_00e9e700()
{
    FUN_00e9e700_Helper* p = (FUN_00e9e700_Helper*)g_memoryManager.Allocate(32);
    if (p)
        return p->FUN_00e9e680(_NiPoint3_ZERO, DAT_011a9478);
    return 0;
}

struct D_00e9e980
{
    char _00[8];
    void** m_pp;
    char _0C[2];
    unsigned short m_cnt;
    char _10[4];
    int m_found;
};
bool __cdecl CallConditionFunction(float, void*, void*, void*, void*);
// Scans the pointer array in d up to m_cnt, calls CallConditionFunction on each element, and on success stores the index in m_found and returns true.
// @fnv 0x00e9e980
bool __cdecl FUN_00e9e980(float afValue, D_00e9e980* pContainer, void* a, void* b, void* c)
{
    unsigned int i = 0;
    for (; i < pContainer->m_cnt; ++i)
    {
        void* e = pContainer->m_pp[i];
        if (CallConditionFunction(afValue, e, a, b, c))
        {
            pContainer->m_found = (int)i;
            return true;
        }
    }
    return false;
}

namespace fnv_00e9cb50 {
struct NiStream
{
};
struct NiObject
{
    virtual void LinkObject(NiStream&);
};
struct NiPlane
{
    void LoadBinary(NiStream&);
};
struct NiPoint3
{
    void LoadBinary(NiStream&);
};

struct NiHalfSpaceBV : NiObject
{
    NiPlane m_kHalfSpacePlane;
    char pad[15];
    NiPoint3 m_kCenter;
    void FUN_00e9cb50(NiStream&);
};

// Links the object to the stream, then loads the plane and center point from the stream.
// @fnv 0x00e9cb50
void NiHalfSpaceBV::FUN_00e9cb50(NiStream& stream)
{
    NiObject::LinkObject(stream);
    m_kHalfSpacePlane.LoadBinary(stream);
    m_kCenter.LoadBinary(stream);
}
}  // namespace fnv_00e9cb50

struct PlaneInput
{
    NiPoint3 normal;
    float distance;
};
struct NormalProxy
{
    float x, y, z;
    float FUN_00457910();
};
struct HalfSpaceProxy : NiHalfSpaceBV
{
    NormalProxy normal;
    float distance;
    void SetFromPlane(const PlaneInput* source);
};
// Copies the plane normal into this half-space and stores the distance divided by the normal's length.
// @fnv 0x00e9cbb0
void HalfSpaceProxy::SetFromPlane(const PlaneInput* apPlane)
{
    NormalProxy normalized = *reinterpret_cast<const NormalProxy*>(&apPlane->normal);
    const double originalDistance = apPlane->distance;
    float adjustedDistance = static_cast<float>(originalDistance / normalized.FUN_00457910());
    normal = normalized;
    distance = adjustedDistance;
}

struct AffineMatrix
{
    float r00, r01, r02, r10, r11, r12, r20, r21, r22, t0, t1, t2, scale;
};
struct NiPlane4
{
    void* vtable;
    NiPoint3 normal;
    float distance;
    void TransformPlane(const NiPlane4& source, const AffineMatrix& matrix);
};
// @fnv 0x00e9cc60
void NiPlane4::TransformPlane(const NiPlane4& source, const AffineMatrix& matrix)
{
    NiPoint3 transformedNormal;
    const volatile float& x = source.normal.x;
    const volatile float& m = matrix.r00;
    transformedNormal.x = m * x + matrix.r01 * source.normal.y + matrix.r02 * source.normal.z;
    transformedNormal.y = matrix.r10 * source.normal.x + matrix.r11 * source.normal.y + matrix.r12 * source.normal.z;
    transformedNormal.z = matrix.r20 * source.normal.x + matrix.r21 * source.normal.y + matrix.r22 * source.normal.z;
    const volatile NiPoint3& t = transformedNormal;
    float translation = matrix.t0 * t.x + matrix.t1 * t.y + matrix.t2 * t.z;
    double newDistance = static_cast<volatile float&>(translation);
    newDistance += matrix.scale * source.distance;
    float result = (float)newDistance;
    normal = transformedNormal;
    distance = result;
}

struct V3
{
    float x;
    float y;
    float z;
};
struct PA
{
    char _0[4];
    V3 n;
    float d;
};
struct PB
{
    char _0[0x20];
    V3 u;
    V3 w;
    float r;
};
static float Dot(const V3& l, const V3& r)
{
    return l.x * r.x + l.y * r.y + l.z * r.z;
}
// @fnv 0x00e9cf50
bool __cdecl FUN_00e9cf50(float afScale, PA* apPlane, V3* apStart, PB* b, V3* apEnd)
{
    float dist = Dot(b->u, apPlane->n);
    dist = dist - apPlane->d;
    float t = -b->r;
    if (dist >= t)
        return true;
    float d2 = Dot(b->w, apPlane->n);
    d2 = d2 + dist;
    if (d2 >= t)
        return true;
    V3 v;
    v.x = apEnd->x - apStart->x;
    v.y = apEnd->y - apStart->y;
    v.z = apEnd->z - apStart->z;
    float fDot = apPlane->n.x * v.x + apPlane->n.y * v.y + apPlane->n.z * v.z;
    if (fDot <= 0.0f)
        return false;
    float e = -(fDot * afScale + b->r);
    return e <= dist || d2 >= e;
}

struct Pt3_e9e
{
    float x, y, z;
    float operator*(const Pt3_e9e& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};

struct Plane_e9e
{
    Pt3_e9e m_kPlaneNormal;
    float m_fPlaneConstant;
    Plane_e9e();
};

struct FUN_00e9e680
{
    Plane_e9e m_kHalfSpacePlane;
    Pt3_e9e m_kStartPoint;
    virtual void v00();
    void SetFromPlane(const Plane_e9e& m_kFogPlane);
    FUN_00e9e680(const Pt3_e9e& akStart, const Pt3_e9e& kNormal);
};

// @fnv 0x00e9e680
FUN_00e9e680::FUN_00e9e680(const Pt3_e9e& akPoint, const Pt3_e9e& kNormal) : m_kStartPoint(akPoint)
{
    Plane_e9e m_kFogPlane;
    m_kFogPlane.m_kPlaneNormal = kNormal;
    m_kFogPlane.m_fPlaneConstant = akPoint * kNormal;
    SetFromPlane(m_kFogPlane);
}

// FUN_00e9e730 — clone method: allocates a new object via the memory
// manager, initializes its member, copies the bounding-volume data and the
// trailing NiPoint3, and returns the clone (NULL when allocation fails).
//
// Target: __thiscall, caller pops, size 78, /MT /O2 /GS /EHsc /Gy.
// Uses the pack's declarations: NiBoundingVolume, NiPoint3, P03MM,
// g_memoryManager.

// Non-polymorphic stand-in for the member object living at wrapper offset
// +4 (16 bytes); FUN_00a69940 is its out-of-line initialization helper.
struct FUN_00a69940_Member
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void FUN_00a69940();
};

// The cloned object: NiBoundingVolume-derived, vtable at +0, member at +4,
// NiPoint3 at +0x14, total size 0x20 (operator new hands exactly 0x20 to
// the memory manager). The class carries no FUN_00e9e730 token in its own
// name so the target symbol stays unique.
struct CloneNode : NiBoundingVolume
{
    virtual ~CloneNode();
    void SetFromPlane(const FUN_00a69940_Member* kABV);
    FUN_00a69940_Member member;
    NiPoint3 point;
    void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    NiBoundingVolume* FUN_00e9e730();
};

CloneNode::~CloneNode()
{}

// Allocates a new CloneNode, initialises its member, copies this node's member and point into it, and returns it.
// @fnv 0x00e9e730
NiBoundingVolume* CloneNode::FUN_00e9e730()
{
    CloneNode* clone = new CloneNode();
    if (clone == 0)
    {
        return 0;
    }
    clone->member.FUN_00a69940();
    clone->SetFromPlane(&this->member);
    clone->point = this->point;
    return clone;
}

struct NiStream;

extern NiPoint3 DAT_011a9478;
extern NiPoint3 DAT_011f426c;
extern NiPoint3 _NiPoint3_ZERO;

extern P03MM g_memoryManager;

NiBoundingVolume* FUN_00e9e700();

struct FUN_00e9e780_Virtual
{
    virtual void Call(void* p);
};

// Allocates a 0x20-byte helper, builds a NiBoundingVolume from two NiPoint3 constants, invokes Call(p) on it, and returns it.
// @fnv 0x00e9e780
NiBoundingVolume* __cdecl CreateBoundingVolumeAndCall(void* apArg)
{
    FUN_00e9e700_Helper* helper = static_cast<FUN_00e9e700_Helper*>(g_memoryManager.Allocate(0x20));

    NiBoundingVolume* result;

    if (helper)
        result = helper->FUN_00e9e680(DAT_011f426c, DAT_011a9478);
    else
        result = 0;

    reinterpret_cast<FUN_00e9e780_Virtual*>(result)->Call(apArg);
    return result;
}

extern "C" size_t __cdecl strlen(const char*);
void* __cdecl NiMalloc(unsigned int uiSize);
int __cdecl FUN_00a305b0(char* pcBuffer, unsigned int uiSize, const char* pcFormat, ...);

class E9E7D0StrArray
{
  public:
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, char*& pcValue);

    unsigned int Add(char*& pcValue)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcValue);
        return uiIndex;
    }

    void* m_ppVirtualMethodTable;
    char** m_ppcBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class E9E7D0BoundingVolume
{
  public:
    void AddHalfspaceName(const char* pcName, E9E7D0StrArray* pkStrings);
};

// Formats "<pcName> = HALFSPACE_BV" into a newly allocated buffer and appends it to pkStrings.
// @fnv 0x00e9e7d0
void E9E7D0BoundingVolume::AddHalfspaceName(const char* pcName, E9E7D0StrArray* pkStrings)
{
    unsigned int uiLen = strlen(pcName) + 16;
    char* pcString = static_cast<char*>(NiMalloc(uiLen));
    FUN_00a305b0(pcString, uiLen, "%s = HALFSPACE_BV", pcName);
    pkStrings->Add(pcString);
}

struct Pt3
{
    float x;
    float y;
    float z;
};

struct HalfSpaceBV
{
    void* m_ppVirtualMethodTable;
    Pt3 m_kPlaneNormal;
    float m_fPlaneConstant;
};

// @fnv 0x00e9d070
bool __cdecl FUN_00e9d070(float fT, HalfSpaceBV* a, Pt3* p0, HalfSpaceBV* b, Pt3* p1)
{
    const Pt3& na = a->m_kPlaneNormal;
    const Pt3& nb = b->m_kPlaneNormal;
    float fDot = nb.y * na.y + na.x * b->m_kPlaneNormal.x + nb.z * na.z;
    if (fDot > (double)-0.999999f)
        return true;
    if (a->m_fPlaneConstant <= -b->m_fPlaneConstant)
        return true;
    Pt3 vDelta;
    vDelta.x = p1->x - p0->x;
    vDelta.y = p1->y - p0->y;
    vDelta.z = p1->z - p0->z;
    float fT2 = na.x * vDelta.x + na.y * vDelta.y + na.z * vDelta.z;
    if (fT2 <= 0.0f)
        return false;
    return a->m_fPlaneConstant <= fT2 * fT - b->m_fPlaneConstant;
}

class SweepPoint
{
  public:
    float x, y, z;

    SweepPoint()
    {}
    SweepPoint(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    SweepPoint operator+(const SweepPoint& pt) const;
    SweepPoint operator-(const SweepPoint& pt) const
    {
        return SweepPoint(x - pt.x, y - pt.y, z - pt.z);
    }
    SweepPoint operator-() const
    {
        return SweepPoint(-x, -y, -z);
    }
    float operator*(const SweepPoint& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};
SweepPoint operator*(float fScalar, const SweepPoint& pt);

class SweepPlane
{
  public:
    int unk00;
    SweepPoint m_kPlaneNormal;
    float m_fPlaneConstant;

    float Distance(const SweepPoint& kPoint) const
    {
        return m_kPlaneNormal * kPoint - m_fPlaneConstant;
    }
};

// @fnv 0x00e9e2c0
bool __cdecl FUN_00e9e2c0(float fRadius, const SweepPlane& akPlane, const SweepPoint& kStart, const SweepPoint& kP0,
                          const SweepPoint& kP1, const SweepPoint& kP2, const SweepPoint& kEnd, float& fTime,
                          SweepPoint& kIntersect, bool bCalcNormals, SweepPoint& akNormal, SweepPoint& akPlaneNormal)
{
    const SweepPoint& kN = akPlane.m_kPlaneNormal;
    float fD0 = kN * kP0 - akPlane.m_fPlaneConstant;
    if (fD0 >= 0.0f)
    {
        fTime = 0.0f;
        kIntersect = kP0;
        if (bCalcNormals)
        {
            akPlaneNormal = akPlane.m_kPlaneNormal;
            akNormal = -akPlaneNormal;
        }
        return true;
    }

    float fD1 = kN * kP1 - akPlane.m_fPlaneConstant;
    if (fD1 >= 0.0f)
    {
        fTime = 0.0f;
        kIntersect = kP1;
        if (bCalcNormals)
        {
            akPlaneNormal = akPlane.m_kPlaneNormal;
            akNormal = -akPlaneNormal;
        }
        return true;
    }

    float fD2 = kN * kP2 - akPlane.m_fPlaneConstant;
    if (fD2 >= 0.0f)
    {
        fTime = 0.0f;
        kIntersect = kP2;
        if (bCalcNormals)
        {
            akPlaneNormal = akPlane.m_kPlaneNormal;
            akNormal = -akPlaneNormal;
        }
        return true;
    }

    float fSpeed = (kEnd - kStart) * akPlane.m_kPlaneNormal;
    if (fSpeed <= 0.0f)
        return false;

    float fThreshold = -fRadius * fSpeed;
    if (!(fThreshold <= fD0 || fThreshold <= fD1 || fThreshold <= fD2))
        return false;

    if (fD0 >= fD1)
    {
        if (fD0 >= fD2)
        {
            fTime = -fD0 / fSpeed;
            kIntersect = kP0 + fRadius * kEnd;
        }
        else
        {
            fTime = -fD2 / fSpeed;
            kIntersect = kP2 + fRadius * kEnd;
        }
    }
    else
    {
        if (fD1 >= fD2)
        {
            fTime = -fD1 / fSpeed;
            kIntersect = kP1 + fRadius * kEnd;
        }
        else
        {
            fTime = -fD2 / fSpeed;
            kIntersect = kP2 + fRadius * kEnd;
        }
    }
    if (bCalcNormals)
    {
        akPlaneNormal = akPlane.m_kPlaneNormal;
        akNormal = -akPlaneNormal;
    }
    return true;
}

struct HalfSpace
{
    void* vtable;
    float nx;
    volatile float ny;
    float nz;
    float d;
};
struct Sphere
{
    void* vtable;
    float cx, cy, cz, r;
};
struct Vec3
{
    float x, y, z;
};
// Checks the sphere's signed plane distance against its radius, then tests whether motion over t reaches that threshold.
// @fnv 0x00e9cd10
bool __cdecl FUN_00e9cd10(float afTime, HalfSpace* plane, Vec3* apStart, Sphere* sphere, Vec3* apEnd)
{
    float dot = sphere->cy * plane->ny + sphere->cx * plane->nx + sphere->cz * plane->nz;
    float distance = dot - plane->d;
    float radius = -sphere->r;
    if (distance >= radius)
        return true;
    Vec3 relative;
    relative.x = apEnd->x - apStart->x;
    relative.y = apEnd->y - apStart->y;
    relative.z = apEnd->z - apStart->z;
    float speed = plane->ny * relative.y + relative.x * plane->nx + plane->nz * relative.z;
    if (speed <= 0.0f)
        return false;
    return distance + speed * afTime >= radius;
}

#include <math.h>
namespace fnv_00e9cde0 {
struct Vec3
{
    float x;
    float y;
    float z;
    float Dot(const Vec3& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    Vec3 operator-(const Vec3& p) const
    {
        Vec3 r;
        r.x = x - p.x;
        r.y = y - p.y;
        r.z = z - p.z;
        return r;
    }
    Vec3 operator*(float f) const
    {
        Vec3 r;
        r.x = x * f;
        r.y = y * f;
        r.z = z * f;
        return r;
    }
};

struct NiPlane
{
    Vec3 m_kPlaneNormal;
    float m_fPlaneConstant;
};

struct OrientedBoxBound
{
    Vec3 m_kCenter;
    Vec3 m_akAxes[3];
    float m_afExtents[3];
};

struct BVBase
{
    virtual ~BVBase();
};

struct HalfSpaceBV : BVBase
{
    NiPlane m_kHalfSpacePlane;
};

struct BoxBV : BVBase
{
    OrientedBoxBound m_kBoundsBox;
};

// Tests whether an oriented box overlaps a half-space plane now or within fTime, using projected extents and relative velocity.
// @fnv 0x00e9cde0
bool IsIntersectingFogPlane(float fTime, const BVBase& kBV0, const Vec3& kV0, const BVBase& kBV1, const Vec3& kV1)
{
    const HalfSpaceBV& kHS = (const HalfSpaceBV&)kBV0;
    const BoxBV& kBox = (const BoxBV&)kBV1;
    const NiPlane& m_kFogPlane = kHS.m_kHalfSpacePlane;
    const OrientedBoxBound& box = kBox.m_kBoundsBox;

    float afD[3];
    afD[0] = box.m_akAxes[0].Dot(m_kFogPlane.m_kPlaneNormal) * box.m_afExtents[0];
    afD[1] = box.m_akAxes[1].Dot(m_kFogPlane.m_kPlaneNormal) * box.m_afExtents[1];
    afD[2] = box.m_akAxes[2].Dot(m_kFogPlane.m_kPlaneNormal) * box.m_afExtents[2];
    float fRadius = fabsf(afD[0]) + fabsf(afD[1]) + fabsf(afD[2]);

    float fDist = box.m_kCenter.Dot(m_kFogPlane.m_kPlaneNormal) - m_kFogPlane.m_fPlaneConstant;
    if (fDist >= -fRadius)
        return true;

    Vec3 kV = kV1 - kV0;
    float fSpeed = m_kFogPlane.m_kPlaneNormal.Dot(kV);
    if (fSpeed <= 0.0f)
        return false;

    return fDist + fSpeed * fTime >= -fRadius;
}
}  // namespace fnv_00e9cde0

struct V3_e9d150
{
    float x, y, z;
    float operator*(const V3_e9d150& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
};
struct Plane_e9d150
{
    V3_e9d150 m_kPlaneNormal;
    float m_fPlaneConstant;
    float Distance(const V3_e9d150& p) const
    {
        float fDot = m_kPlaneNormal * p;
        return fDot - m_fPlaneConstant;
    }
};
struct PA_e9d150
{
    int unk00;
    Plane_e9d150 m_kHalfSpacePlane;
};

// Tests the three vertex distances, then compares a scaled dot product with those distances.
// @fnv 0x00e9d150
bool __cdecl FUN_00e9d150(float afScale, PA_e9d150* apPlane, V3_e9d150* apOrigin, V3_e9d150* p0, V3_e9d150* p1,
                          V3_e9d150* p2, V3_e9d150* apPoint)
{
    const Plane_e9d150& m_kFogPlane = apPlane->m_kHalfSpacePlane;
    float fDist0 = m_kFogPlane.Distance(*p0);
    if (fDist0 >= 0.0f)
        return true;
    float fDist1 = m_kFogPlane.Distance(*p1);
    if (fDist1 >= 0.0f)
        return true;
    float d2 = m_kFogPlane.Distance(*p2);
    if (d2 >= 0.0f)
        return true;
    V3_e9d150 vDiff;
    vDiff.x = apPoint->x - apOrigin->x;
    vDiff.y = apPoint->y - apOrigin->y;
    vDiff.z = apPoint->z - apOrigin->z;
    float t = apPlane->m_kHalfSpacePlane.m_kPlaneNormal * vDiff;
    if (t <= 0.0f)
        return false;
    float s = -afScale * t;
    return s <= fDist0 || s <= fDist1 || s <= d2;
}

struct BvPt
{
    float x, y, z;
    BvPt()
    {}
    BvPt(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    BvPt operator+(const BvPt& p) const
    {
        return BvPt(x + p.x, y + p.y, z + p.z);
    }
    BvPt operator-(const BvPt& p) const
    {
        return BvPt(x - p.x, y - p.y, z - p.z);
    }
    float VelocityDot(BvPt p) const
    {
        const volatile float& nx = x;
        return nx * p.x + y * p.y + z * p.z;
    }
    float operator*(const BvPt& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    BvPt operator*(float f) const
    {
        return BvPt(x * f, y * f, z * f);
    }
    BvPt operator-() const
    {
        return BvPt(-x, -y, -z);
    }
};

inline BvPt operator*(float f, const BvPt& p)
{
    return BvPt(f * p.x, f * p.y, f * p.z);
}

inline BvPt ScaleNormal(float f, const BvPt& p)
{
    float fScale = f;
    return BvPt(fScale * p.x, fScale * p.y, fScale * p.z);
}

struct Plane3
{
    BvPt m_kPlaneNormal;
    float m_fPlaneConstant;
    const BvPt& GetPlaneNormal() const
    {
        return m_kPlaneNormal;
    }
    float Distance(const BvPt& p) const
    {
        return m_kPlaneNormal * p - m_fPlaneConstant;
    }
};

struct Sphere3
{
    BvPt m_kCenter;
    float m_fBoundRadius;
};

struct HSpaceBV : NiBoundingVolume
{
    Plane3 m_kHalfSpacePlane;
    const Plane3& GetPlane() const
    {
        return m_kHalfSpacePlane;
    }
};

struct SphBV : NiBoundingVolume
{
    Sphere3 m_kBoundingSphere;
    const Sphere3& GetSphere() const
    {
        return m_kBoundingSphere;
    }
};

__forceinline bool SweepContact(float fTime, const NiBoundingVolume& kBV0, const BvPt& kV0,
                                const NiBoundingVolume& kBV1, const BvPt& kV1, float& fIntrTime, BvPt& kIntrPt,
                                bool bCalcNormals, BvPt& akNormal0, BvPt& akNormal1)
{
    const HSpaceBV& kHalfSpaceBV = (const HSpaceBV&)kBV0;
    const SphBV& kSphereBV = (const SphBV&)kBV1;
    const Plane3& m_kFogPlane = kHalfSpaceBV.m_kHalfSpacePlane;
    const BvPt& kV = m_kFogPlane.m_kPlaneNormal;
    const Sphere3& kSphere = kSphereBV.m_kBoundingSphere;
    const BvPt& kNormal = kSphere.m_kCenter;

    float fDistance;
    fDistance = kV * kNormal - m_kFogPlane.m_fPlaneConstant;
    float fNdV = -kSphere.m_fBoundRadius;

    if (fDistance >= fNdV)
    {
        fIntrTime = 0.0f;
        kIntrPt = kNormal - fDistance * kV;
        if (bCalcNormals)
        {
            akNormal1 = kV;
            akNormal0 = -akNormal1;
        }
        return true;
    }

    BvPt kTargetCenter = kV1 - kV0;
    float fNegRadius;
    fNegRadius = kV.VelocityDot(kTargetCenter);
    if (fNegRadius <= 0.0f)
        return false;

    if (!(fDistance + fTime * fNegRadius >= fNdV))
        return false;

    fIntrTime = -(fDistance + kSphere.m_fBoundRadius) / fNegRadius;

    if (bCalcNormals)
    {
        akNormal1 = kV;
        akNormal0 = -akNormal1;
    }

    kIntrPt = (kNormal + kV1 * fIntrTime) + ScaleNormal(kSphere.m_fBoundRadius, akNormal1);
    return true;
}

// Delegates to SweepContact to compute the intersection time and point between a moving sphere and a half-space plane.
// @fnv 0x00e9d2c0
bool FUN_00e9d2c0(float fTime, const NiBoundingVolume& kBV0, const BvPt& kV0, const NiBoundingVolume& kBV1,
                  const BvPt& kV1, float& fIntrTime, BvPt& kIntrPt, bool bCalcNormals, BvPt& akNormal0, BvPt& akNormal1)
{
    return SweepContact(fTime, kBV0, kV0, kBV1, kV1, fIntrTime, kIntrPt, bCalcNormals, akNormal0, akNormal1);
}

extern "C" void _ReadWriteBarrier();
struct Pt
{
    float x, y, z;
    Pt()
    {}
    Pt(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
    {}
    Pt operator-() const
    {
        return Pt(-x, -y, -z);
    }
    Pt operator+(const Pt& r) const
    {
        return Pt(x + r.x, y + r.y, z + r.z);
    }
    Pt operator-(const Pt& r) const
    {
        return Pt(x - r.x, y - r.y, z - r.z);
    }
    Pt operator*(float s) const
    {
        return Pt(x * s, y * s, z * s);
    }
    float operator*(const Pt& r) const
    {
        return x * r.x + y * r.y + z * r.z;
    }
};

struct Plane
{
    int unk00;
    Pt n;
    float d;
    float D() const
    {
        return d;
    }
};

inline Pt ScaleNormal(const Pt& p, float f)
{
    return Pt(p.x * f, p.y * f, p.z * f);
}
// Computes a point and time for the two plane inputs, with optional output normals.
// @fnv 0x00e9dfa0
bool __cdecl IntersectPlanes(float fTime, Plane* pkABV0, Pt* pkV0, Plane* pkABV1, Pt* pkV1, float* pfT, Pt* pkPoint,
                             bool bSide, Pt* pkSide0, Pt* pkSide1)
{
    const Pt& n0 = pkABV0->n;
    const Pt& n1 = pkABV1->n;
    double product = n1.x * n0.x;
    _ReadWriteBarrier();
    float fDot = product + n1.y * n0.y + n1.z * n0.z;
    if (fDot > -0.999999f)
    {
        float fInv = 1.0f / (1.0f - fDot * fDot);
        float fC0 = (pkABV0->d - pkABV1->d * fDot) * fInv;
        float fC1 = (pkABV1->d - pkABV0->d * fDot) * fInv;

        *pfT = 0.0f;
        *pkPoint = pkABV0->n * fC0 + pkABV1->n * fC1;

        if (bSide)
        {
            *pkSide0 = -pkABV0->n;
            *pkSide1 = -pkABV1->n;
        }
        return true;
    }

    if (pkABV0->d <= -pkABV1->d)
    {
        *pfT = 0.0f;
        *pkPoint = ScaleNormal(pkABV0->n, pkABV0->d - pkABV1->d);

        if (bSide)
        {
            *pkSide1 = pkABV0->n;
            *pkSide0 = pkABV1->n;
        }
        return true;
    }

    Pt kDiff = *pkV1 - *pkV0;
    float fDot2 = kDiff * pkABV0->n;
    if (!(fDot2 <= 0.0f))
    {
        if (pkABV0->d <= fDot2 * fTime - pkABV1->d)
        {
            float fW = (pkABV1->D() + pkABV0->d) / fDot2;
            *pfT = fW;
            *pkPoint = pkABV0->n * pkABV0->d + *pkV0 * *pfT;

            if (bSide)
            {
                *pkSide1 = pkABV0->n;
                *pkSide0 = pkABV1->n;
            }
            return true;
        }
        return false;
    }
    return false;
}

class S9d540_Pt
{
  public:
    float x, y, z;
    S9d540_Pt()
    {}
    S9d540_Pt(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    S9d540_Pt operator+(const S9d540_Pt& pt) const
    {
        return S9d540_Pt(x + pt.x, y + pt.y, z + pt.z);
    }
    S9d540_Pt operator-(const S9d540_Pt& pt) const
    {
        return S9d540_Pt(x - pt.x, y - pt.y, z - pt.z);
    }
    float operator*(const S9d540_Pt& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
    S9d540_Pt operator*(float fScalar) const
    {
        return S9d540_Pt(fScalar * x, fScalar * y, fScalar * z);
    }
    S9d540_Pt operator-() const
    {
        return S9d540_Pt(-x, -y, -z);
    }
    S9d540_Pt& operator+=(const S9d540_Pt& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
        return *this;
    }
    S9d540_Pt& operator-=(const S9d540_Pt& pt)
    {
        x -= pt.x;
        y -= pt.y;
        z -= pt.z;
        return *this;
    }
    friend S9d540_Pt operator*(float fScalar, const S9d540_Pt& pt)
    {
        return S9d540_Pt(fScalar * pt.x, fScalar * pt.y, fScalar * pt.z);
    }
};
inline float S9d540_Abs(double f)
{
    return (float)fabs(f);
}
class S9d540_Plane
{
  public:
    S9d540_Pt m_kPlaneNormal;
    float m_fPlaneConstant;
    const S9d540_Pt& GetPlaneNormal() const
    {
        return m_kPlaneNormal;
    }
    float Distance(const S9d540_Pt& kPoint) const
    {
        return m_kPlaneNormal * kPoint - m_fPlaneConstant;
    }
};
class S9d540_HalfSpaceBV
{
  public:
    void* m_vtbl;
    S9d540_Plane m_kHalfSpacePlane;
    const S9d540_Plane& GetPlane() const
    {
        return m_kHalfSpacePlane;
    }
};
class S9d540_Box
{
  public:
    S9d540_Pt m_kCenter;
    S9d540_Pt m_akAxes[3];
    float m_afExtents[3];
};
class S9d540_BoxBV
{
  public:
    void* m_vtbl;
    S9d540_Box m_kBoundsBox;
    const S9d540_Box& GetBox() const
    {
        return m_kBoundsBox;
    }
};

// Tests a moving box against a half-space plane and writes a contact time, point, and optional normals.
// @fnv 0x00e9d540
bool __cdecl FUN_00e9d540(float fTime, const S9d540_HalfSpaceBV& kBV0, const S9d540_Pt& kV0, const S9d540_BoxBV& kBV1,
                          const S9d540_Pt& kV1, float& fIntrTime, S9d540_Pt& kIntrPt, bool bCalcNormals,
                          S9d540_Pt& akNormal0, S9d540_Pt& akNormal1)
{
    const S9d540_Plane& m_kFogPlane = kBV0.GetPlane();
    const S9d540_Box& kBox = kBV1.GetBox();
    const S9d540_Pt& kNormal = m_kFogPlane.GetPlaneNormal();

    float afProj[3];
    afProj[0] = (kNormal * kBox.m_akAxes[0]) * kBox.m_afExtents[0];
    afProj[1] = (kNormal * kBox.m_akAxes[1]) * kBox.m_afExtents[1];
    afProj[2] = (kBV0.m_kHalfSpacePlane.m_kPlaneNormal * kBox.m_akAxes[2]) * kBox.m_afExtents[2];
    float fRadius = S9d540_Abs(afProj[0]) + S9d540_Abs(afProj[1]) + S9d540_Abs(afProj[2]);
    float fDistance = m_kFogPlane.Distance(kBV1.m_kBoundsBox.m_kCenter);

    if (fDistance >= -fRadius)
    {
        fIntrTime = 0.0f;
        kIntrPt = kBox.m_kCenter - fDistance * kNormal;
        if (bCalcNormals)
        {
            akNormal1 = kNormal;
            akNormal0 = -akNormal1;
        }
        return true;
    }

    const S9d540_Pt& kn2 = m_kFogPlane.GetPlaneNormal();
    float fNdV = (kV1 - kV0) * kn2;
    if (fNdV <= 0.0f)
        return false;
    if (fDistance + fTime * fNdV >= -fRadius)
    {
        fIntrTime = -(fDistance + fRadius) / fNdV;
        kIntrPt = kBox.m_kCenter + kV1 * fIntrTime;
        for (int i = 0; i < 3; i++)
        {
            if (S9d540_Abs(afProj[i]) > 0.001f)
            {
                if (afProj[i] > 0.0f)
                    kIntrPt += kBox.m_afExtents[i] * kBox.m_akAxes[i];
                else
                    kIntrPt -= kBox.m_afExtents[i] * kBox.m_akAxes[i];
            }
        }
        if (bCalcNormals)
        {
            akNormal0 = -kNormal;
            akNormal1 = kIntrPt - kBox.m_kCenter;
        }
        return true;
    }
    return false;
}

struct Vec72
{
    float x, y, z;
    Vec72()
    {}
    Vec72(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Vec72 operator+(const Vec72& b) const
    {
        return Vec72(b.x + x, b.y + y, b.z + z);
    }
    Vec72 operator-(const Vec72& b) const
    {
        return Vec72(x - b.x, y - b.y, z - b.z);
    }
    Vec72 operator-() const
    {
        return Vec72(-x, -y, -z);
    }
    Vec72 operator*(float k) const
    {
        return Vec72(x * k, y * k, z * k);
    }
    float operator*(const Vec72& b) const
    {
        return x * b.x + y * b.y + (z * b.z);
    }
};
Vec72 operator*(float k, const Vec72& v)
{
    return Vec72(k * v.x, k * v.y, k * v.z);
}
struct Plane72
{
    Vec72 normal;
    float constant;
    float Distance(const Vec72& p) const
    {
        return normal * p - constant;
    }
};
struct Half72
{
    void* vtbl;
    Plane72 plane;
    const Plane72& GetPlane() const
    {
        return plane;
    }
};
struct CapsuleData72
{
    Vec72 origin, direction;
    float radius;
    const Vec72& GetOrigin() const
    {
        return origin;
    }
    const Vec72& GetDirection() const
    {
        return direction;
    }
    float GetRadius() const
    {
        return radius;
    }
};
struct Capsule72
{
    void* vtbl;
    Vec72 center, axis;
    float extent;
    CapsuleData72 geometry;
    const CapsuleData72& GetGeometry() const
    {
        return geometry;
    }
};
struct Sphere72
{
    void* vtbl;
    Vec72 center;
    float radius;
    Sphere72(float, const Vec72&);
};
bool FUN_00e9d2c0(float, const Half72&, const Vec72&, const Sphere72&, const Vec72&, float&, Vec72&, bool, Vec72&,
                  Vec72&);
// Tests a capsule against a moving half-space, using sphere tests when an endpoint is within the capsule radius of the plane.
// @fnv 0x00e9da30
bool SweepCapsuleAgainstHalf(float maxTime, const Half72& half, const Vec72& halfVelocity, const Capsule72& capsule,
                             const Vec72& capsuleVelocity, float& time, Vec72& point, bool normals,
                             Vec72* __restrict normalHalf, Vec72* normalCapsule)
{
    const CapsuleData72& shape = capsule.geometry;
    const Vec72& origin = shape.origin;
    const Plane72& plane = half.plane;
    const Vec72& direction = shape.direction;
    float distance0;
    float distance1;
    distance0 = half.GetPlane().Distance(capsule.GetGeometry().origin);
    Vec72 endpoint;
    endpoint = shape.direction + origin;
    distance1 = plane.Distance(endpoint);
    if ((distance0 < 0.0f && distance1 > 0.0f) || (distance0 > 0.0f && distance1 < 0.0f))
    {
        time = 0.0f;
        float parameter = distance0 / (distance0 - distance1);
        point = capsule.GetGeometry().origin + direction * parameter;
    }
    else if (-shape.radius <= distance0)
    {
        time = 0.0f;
        Sphere72 sphere(1.0f, *(Vec72*)&DAT_011f426c);
        sphere.radius = capsule.geometry.radius;
        if (distance1 >= -shape.radius)
        {
            sphere.center = capsule.center;
            return FUN_00e9d2c0(maxTime, half, halfVelocity, sphere, capsuleVelocity, time, point, normals, *normalHalf,
                                *normalCapsule);
        }
        else
        {
            sphere.center = shape.GetOrigin();
            return FUN_00e9d2c0(maxTime, half, halfVelocity, sphere, capsuleVelocity, time, point, normals, *normalHalf,
                                *normalCapsule);
        }
    }
    else if (distance1 >= -shape.radius)
    {
        time = 0.0f;
        Sphere72 sphere(1.0f, *(Vec72*)&DAT_011f426c);
        sphere.radius = capsule.geometry.radius;
        sphere.center = capsule.geometry.origin + capsule.geometry.direction;
        return FUN_00e9d2c0(maxTime, half, halfVelocity, sphere, capsuleVelocity, time, point, normals, *normalHalf,
                            *normalCapsule);
    }
    else
    {
        Vec72 relativeVelocity;
        relativeVelocity = capsuleVelocity - halfVelocity;
        float rate = plane.normal * relativeVelocity;
        if (rate <= 0.0f)
            return false;
        float reach;
        reach = -(rate * maxTime + shape.radius);
        if (!(distance0 >= reach || distance1 >= reach))
            return false;
        if (distance1 + 0.000001f < distance0)
        {
            time = -(shape.radius + distance0) / rate;
            point = origin + time * capsuleVelocity + plane.normal * shape.radius;
        }
        else if (distance0 + 0.000001f < distance1)
        {
            time = -(distance1 + shape.radius) / rate;
            point = origin + shape.GetDirection() + time * capsuleVelocity + plane.normal * shape.radius;
        }
        else
        {
            time = -(shape.radius + distance1) / rate;
            point = origin + direction * 0.5f + time * capsuleVelocity + half.plane.normal * shape.radius;
        }
    }
    if (normals)
    {
        *normalCapsule = half.plane.normal;
        *normalHalf = -*normalCapsule;
    }
    return true;
}
