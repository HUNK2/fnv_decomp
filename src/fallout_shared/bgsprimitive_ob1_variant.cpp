
// src/fallout_shared/bgsprimitive_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout_shared/bgsprimitive.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "bgsprimitive_decls.h"

class ColorPair
{
  public:
    float r;
    float g;
    float b;
    bool operator==(const ColorPair& c) const
    {
        return r == c.r && g == c.g && b == c.b;
    }
};

class ColorPropertyBase
{
  public:
    bool BSMultiBoundShape_IsEqual(const ColorPropertyBase* pkOther);
};

class ColorProperty : public ColorPropertyBase
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ColorPair m_kPrimaryColor;  // +0x0c
    ColorPair m_kColorB;        // +0x18

    bool BSMultiBoundAABB_IsEqual(const ColorPropertyBase* pkObject);
};

// @fnv 0x00c38090
bool ColorProperty::BSMultiBoundAABB_IsEqual(const ColorPropertyBase* pkObject)
{
    bool bEqual = BSMultiBoundShape_IsEqual(pkObject);
    if (bEqual)
    {
        const ColorProperty* pkOther = (const ColorProperty*)pkObject;
        bEqual = m_kPrimaryColor == pkOther->m_kPrimaryColor;
        bEqual &= m_kColorB == pkOther->m_kColorB;
    }
    return bEqual;
}

extern "C" double __cdecl fabs(double);

class Pt
{
  public:
    float x, y, z;
    Pt()
    {}
    Pt(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    Pt operator-(const Pt& pt) const
    {
        return Pt(x - pt.x, y - pt.y, z - pt.z);
    }
};

inline float PtFabsf(float _X)
{
    return ((float)fabs((double)_X));
}
inline float PtFabs(float _X)
{
    return (PtFabsf(_X));
}
inline float PtAbs(float _X)
{
    return (PtFabs(_X));
}

class CenteredPointBounds
{
  public:
    int unk00;
    int unk04;
    int unk08;
    Pt m_kCenter;
    Pt m_kExtent;
    bool BSMultiBoundAABB_GetPointWithin(const Pt& kPoint);
};

// @fnv 0x00c38a20
bool CenteredPointBounds::BSMultiBoundAABB_GetPointWithin(const Pt& kPoint)
{
    Pt kDiff = kPoint - m_kCenter;
    return !(PtAbs(kDiff.x) - m_kExtent.x > 0.01f) && !(PtAbs(kDiff.y) - m_kExtent.y > 0.01f) &&
           !(PtAbs(kDiff.z) - m_kExtent.z > 0.01f);
}

extern int g_01202818;
extern void fnv_stub_grow(unsigned int, unsigned int);

struct Obj_0096a610
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;

    unsigned int __thiscall GetSize()
    {
        return unk08;
    }

    void __thiscall FUN_0096a610(const unsigned int& value)
    {
        unsigned int index = GetSize();
        unsigned int temp = value;
        unsigned int max = unk04;
        unsigned int base = unk00;
        if (index >= max)
            fnv_stub_grow(base, max);
        temp = temp + base;
        unk08 = index + 1;
        unk0C = temp;
    }
};

struct Obj_00a598f0
{
    unsigned int __thiscall ToString(const char* name);
};

struct C_00c36580
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
    Obj_00a598f0 unk24;

    void __thiscall AddPropertyNames(int value);
    void __thiscall BSMultiBoundOBB_GetViewerStrings(Obj_0096a610* value);
};

int __cdecl FUN_00a7d330(int value);

// @fnv 0x00c36580
void __thiscall C_00c36580::BSMultiBoundOBB_GetViewerStrings(Obj_0096a610* value)
{
    AddPropertyNames((int)value);

    int src = g_01202818;
    unsigned int first = (unsigned int)FUN_00a7d330(src);
    value->FUN_0096a610(first);

    unsigned int second = unk24.ToString("Axis");
    value->FUN_0096a610(second);
}

// Previous geometry reconstruction credited to another contributor.

namespace BoxGeometry {

struct Point3
{

    float x, y, z;

    __forceinline Point3()
    {}

    Point3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Point3 operator-(const Point3& p) const
    {
        return Point3(x - p.x, y - p.y, z - p.z);
    }
    Point3 operator+(const Point3&) const;
    Point3 operator*(float) const;
};

struct Color
{
    float r, g, b, a;
};

extern Color DAT_011a9be0;
extern Point3 DAT_011a946c, DAT_011a9478, DAT_011a9484;

struct GeometryData
{

    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;

    Point3* vertices;

    unsigned int unk24;

    Color* colors;

    unsigned int unk2c, unk30, unk34, unk38, unk3c;

    bool* flags;

    unsigned short* FUN_00a7b850();

    __forceinline Point3* GetVertices()
    {
        Point3* result = vertices;
        return result;
    }

    __forceinline Color* GetColors()
    {
        Color* result = colors;
        return result;
    }

    __forceinline bool* GetFlags()
    {
        bool* result = flags;
        return result;
    }
};

struct Geometry
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

    Point3 position;

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

    GeometryData* data;

    __forceinline GeometryData* GetData()
    {
        return data;
    }
};

struct Bound
{

    unsigned int unk00, unk04, unk08;

    Point3 center;

    float extentX, extentY, extentZ;
    void FUN_00c39270(Point3* out)
    {
        Point3 axisX = DAT_011a946c * extentX;
        Point3 axisY = DAT_011a9478 * extentY;
        Point3 axisZ = DAT_011a9484 * extentZ;
        out[0] = center + axisX + axisY + axisZ;
        out[1] = center + axisX + axisY - axisZ;
        out[2] = center + axisX - axisY + axisZ;
        out[3] = center + axisX - axisY - axisZ;
        out[4] = center - axisX + axisY + axisZ;
        out[5] = center - axisX + axisY - axisZ;
        out[6] = center - axisX - axisY + axisZ;
        out[7] = center - axisX - axisY - axisZ;
    }

    void BSMultiBoundAABB_CreateDebugGeometry(Geometry*, Geometry*, Color);
};

// @fnv 0x00c38b00
void Bound::BSMultiBoundAABB_CreateDebugGeometry(Geometry* lines, Geometry* triangles, Color color)
{

    Point3 corners[8];

    FUN_00c39270(corners);

    unsigned short edgesA[12][2] = {{0, 1}, {0, 2}, {1, 3}, {3, 2}, {4, 5}, {4, 6},
                                    {5, 7}, {7, 6}, {0, 4}, {1, 5}, {2, 6}, {3, 7}};

    unsigned short faces[12][3] = {{2, 3, 1}, {2, 1, 0}, {5, 7, 6}, {5, 6, 4}, {7, 2, 6}, {7, 3, 2},
                                   {4, 0, 5}, {5, 0, 1}, {6, 0, 4}, {6, 2, 0}, {3, 7, 1}, {7, 5, 1}};

    Color faceColor9 = color;

    Color edgeColor = DAT_011a9be0;

    Point3* vertices9 = lines->GetData()->GetVertices();

    Color* colors8 = lines->GetData()->GetColors();

    bool* lineFlags9 = lines->GetData()->GetFlags();

    lines->position = center;

    for (int edge = 0; edge < 12; ++edge)
    {

        vertices9[2 * edge] = corners[edgesA[edge][0]] - center;

        colors8[2 * edge] = edgeColor;

        vertices9[2 * edge + 1] = corners[edgesA[edge][1]] - center;

        colors8[2 * edge + 1] = edgeColor;

        lineFlags9[2 * edge] = true;

        lineFlags9[2 * edge + 1] = false;
    }

    vertices9 = triangles->GetData()->GetVertices();

    colors8 = triangles->GetData()->GetColors();

    unsigned short* indices = triangles->GetData()->FUN_00a7b850();

    triangles->position = center;

    for (unsigned short triangle3 = 0; triangle3 < 12; ++triangle3)
    {

        vertices9[3 * triangle3] = corners[faces[triangle3][0]] - center;

        colors8[3 * triangle3] = faceColor9;

        vertices9[3 * triangle3 + 1] = corners[faces[triangle3][1]] - center;

        colors8[3 * triangle3 + 1] = faceColor9;

        vertices9[3 * triangle3 + 2] = corners[faces[triangle3][2]] - center;

        colors8[3 * triangle3 + 2] = faceColor9;

        indices[3 * triangle3] = 3 * triangle3;

        indices[3 * triangle3 + 1] = 3 * triangle3 + 1;

        indices[3 * triangle3 + 2] = 3 * triangle3 + 2;
    }
}

}

namespace bs {
struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    static const NiPoint3 ZERO;
};
struct NiObject
{
    NiObject();
    virtual ~NiObject();
    unsigned int m_uiRefCount;
};
struct NiPoint2
{
    float x, y;
    NiPoint2()
    {}
    NiPoint2(float fX, float fY)
    {
        x = fX;
        y = fY;
    }
};
struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
    static const ThreeByThreeMatrix IDENTITY;
};
struct NiPlane
{
    NiPlane();
    NiPoint3 m_kPlaneNormal;
    float m_fPlaneConstant;
};
struct NiFrustumPlanes
{
    NiFrustumPlanes()
    {
        m_uiActivePlaneMask = 0x3f;
    }
    NiPlane m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;
};
struct FUN_00c335d0 : NiObject
{
    NiPoint3 kTargetCenter;
    NiPoint2 m_kPoint2;
    ThreeByThreeMatrix kRotationBasis;
    int m_uiShapeType;
    NiFrustumPlanes m_kFrustumPlanes;
    NiPoint3 m_kCornerPoints[4];
    NiPoint3 m_kReferencePoint;
    bool m_bIsInFrustum;
    bool m_bIsVisible;
    bool m_bCornerVisible[4];
    bool m_bDecalTextureCreated;
    FUN_00c335d0* m_apDecalObjects[4];
    FUN_00c335d0();
    virtual ~FUN_00c335d0();
};

// @fnv 0x00c335d0
FUN_00c335d0::FUN_00c335d0()
{
    kTargetCenter = NiPoint3::ZERO;
    m_kPoint2 = NiPoint2(50.0f, 50.0f);
    kRotationBasis = ThreeByThreeMatrix::IDENTITY;
    m_uiShapeType = 0;
    m_bDecalTextureCreated = true;
    for (int i = 0; i < 4; i++)
        m_apDecalObjects[i] = 0;
}
}

#include <math.h>
class NiPoint3_ext
{
  public:
    float x, y, z;
    NiPoint3_ext()
    {}
    float Dot(const NiPoint3&) const;
    NiPoint3_ext operator+(const NiPoint3_ext&) const;
    NiPoint3_ext operator-(const NiPoint3_ext&) const;
    void operator*=(float);
};

class NiPlane
{
  public:
    NiPoint3_ext m_kPlaneNormal;
    float m_fPlaneConstant;
    NiPlane();
    float Distance(const NiPoint3& kPt) const
    {
        return m_kPlaneNormal.Dot(kPt) - m_fPlaneConstant;
    }
};

struct NiMatrix33
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

struct SphereBound
{
    float x, y, z, r;
};

class BSMultiBoundShape
{
  public:
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual int v8c();
    virtual void d36();
    virtual void d37();
    virtual int v98(SphereBound* b);
    virtual void d39();
    virtual void d40();
    virtual void va4(SphereBound* b);

    int unk04;
    int unk08;
    NiPoint3_ext m_kCenter;
    NiPoint3_ext m_kHalfExtents;
    NiMatrix33 m_kRotationMatrix;

    void FUN_00c39270(NiPoint3_ext* pts);

    void FUN_00c37a00(NiPoint3_ext* pts)
    {
        NiPoint3_ext axisX, axisY, axisZ;
        axisX *= m_kHalfExtents.x;
        axisY *= m_kHalfExtents.y;
        axisZ *= m_kHalfExtents.z;
        pts[0] = m_kCenter - axisX - axisY - axisZ;
        pts[1] = m_kCenter + axisX - axisY - axisZ;
        pts[2] = m_kCenter + axisX + axisY - axisZ;
        pts[3] = m_kCenter - axisX + axisY - axisZ;
        pts[4] = m_kCenter - axisX - axisY + axisZ;
        pts[5] = m_kCenter + axisX - axisY + axisZ;
        pts[6] = m_kCenter + axisX + axisY + axisZ;
        pts[7] = m_kCenter - axisX + axisY + axisZ;
    }

    void GetPlanes(NiPlane* planes)
    {
        for (int i = 0; i < 3; i++)
        {
            NiPoint3_ext kNormal;
            float* pRow = &m_kRotationMatrix.m00;
            kNormal.x = pRow[i];
            kNormal.y = pRow[i + 3];
            kNormal.z = pRow[i + 6];
            planes[i].m_kPlaneNormal = kNormal;
            planes[i].m_fPlaneConstant = kNormal.Dot(*(const NiPoint3*)&m_kCenter);
        }
    }

    int BSMultiBoundOBB_CheckBSBound(struct BSMultiBound* p);
};

template <class T> class MyPtr
{
  public:
    T* m_pObject;
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

struct BSMultiBound
{
    int unk00;
    int unk04;
    int unk08;
    MyPtr<BSMultiBoundShape> pShape;
    BSMultiBoundShape* GetShape() const
    {
        return pShape;
    }
};

// @fnv 0x00c369b0
int BSMultiBoundShape::BSMultiBoundOBB_CheckBSBound(BSMultiBound* p)
{
    int v = p->GetShape()->v8c();
    if (v == 1)
    {
        BSMultiBoundShape* j = (BSMultiBoundShape*)p->GetShape();
        NiPoint3_ext e[8];
        j->FUN_00c39270(e);
        NiPlane c[3];
        this->GetPlanes(c);
        for (int i = 0; i < 8; i++)
        {
            float dx = (float)fabs(c[0].Distance(*(NiPoint3*)&e[i]));
            if (dx - m_kHalfExtents.x > 0.0)
                return 0;
            float dz = (float)fabs(c[1].Distance(*(NiPoint3*)&e[i]));
            if (dz - m_kHalfExtents.y > 0.0)
                return 0;
            float dy = (float)fabs(c[2].Distance(*(NiPoint3*)&e[i]));
            if (dy - m_kHalfExtents.z > 0.0)
                return 0;
        }
        return 2;
    }
    else if (v == 2)
    {
        BSMultiBoundShape* c = (BSMultiBoundShape*)p->GetShape();
        NiPoint3_ext j[8];
        c->FUN_00c37a00(j);
        NiPlane e[3];
        this->GetPlanes(e);
        for (int i = 0; i < 8; i++)
        {
            float dx = (float)fabs(e[0].Distance(*(NiPoint3*)&j[i]));
            if (dx - m_kHalfExtents.x > 0.0)
                return 0;
            float dz = (float)fabs(e[1].Distance(*(NiPoint3*)&j[i]));
            if (dz - m_kHalfExtents.y > 0.0)
                return 0;
            float dy = (float)fabs(e[2].Distance(*(NiPoint3*)&j[i]));
            if (dy - m_kHalfExtents.z > 0.0)
                return 0;
        }
        return 2;
    }
    else if (v == 3)
    {
        BSMultiBoundShape* c = (BSMultiBoundShape*)p->GetShape();
        SphereBound j;
        c->va4(&j);
        return this->v98(&j);
    }
    return 0;
}

struct C37050_Point
{
    float x, y, z;
    C37050_Point()
    {}
};
struct C37050_Plane
{
    float a, b, c, d;
    int ClassifyPoint(const C37050_Point& point) const;
};
struct C37050_Frustum
{
    C37050_Plane m_kPlaneArray[6];
    unsigned int m_activePlanes;
    bool IsPlaneActive(int i) const
    {
        int unused[83];
        (void)unused;
        return ((1 << i) & m_activePlanes) ? true : false;
    }
};
struct C37050_Bound
{
    void FUN_00c37a00(C37050_Point* corners);
    bool BSMultiBoundOBB_CompletelyWithinFrustum(const C37050_Frustum& frustum);
};
// @fnv 0x00c37050
bool C37050_Bound::BSMultiBoundOBB_CompletelyWithinFrustum(const C37050_Frustum& frustum)
{
    C37050_Point corners[8];
    FUN_00c37a00(corners);
    for (int i = 0; i < 6; i++)
    {
        if (frustum.IsPlaneActive(i))
        {
            for (int j = 0; j < 8; j++)
            {
                if (frustum.m_kPlaneArray[i].ClassifyPoint(corners[j]) == 2)
                    return false;
            }
        }
    }
    return true;
}

static __forceinline void DeadQ1()
{
    int dq[1];
}
static __forceinline void DeadQ2()
{
    int dq[2];
}
static __forceinline void DeadQ3()
{
    int dq[3];
}
static __forceinline void DeadQ4()
{
    int dq[4];
}
static __forceinline void DeadQ5()
{
    int dq[5];
}
static __forceinline void DeadQ6()
{
    int dq[6];
}

extern const double DAT_01016408;
struct Pt3Q
{
    float x, y, z;
    float DotProduct(const Pt3Q& o) const;
};
struct PlaneQ
{
    Pt3Q m_kPlaneNormal;
    float m_fPlaneConstant;
    PlaneQ()
    {
        FUN_00a69940();
    }
    void FUN_00a69940();
    float Distance(const Pt3Q& p)
    {
        return m_kPlaneNormal.DotProduct(p) - m_fPlaneConstant;
    }
};
static inline float DistOf(PlaneQ* pl, const Pt3Q& p)
{
    return pl->m_kPlaneNormal.DotProduct(p) - pl->m_fPlaneConstant;
}
static inline float AbsQ(float f)
{
    return fabs(f);
}
struct FrustQ
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    float m_fTolX, m_fTolY, m_fTolZ;
    void GetPlanes(PlaneQ* p);
    bool BSMultiBoundOBB_GetPointWithin(const Pt3Q& kPt);
};
// @fnv 0x00c378c0
bool FrustQ::BSMultiBoundOBB_GetPointWithin(const Pt3Q& kPt)
{
    PlaneQ akPlanes3[3];
    DeadQ6();
    GetPlanes(akPlanes3);
    {
        float fDistZ = AbsQ(akPlanes3[0].Distance(kPt));
        if (fDistZ - m_fTolX > DAT_01016408)
            return false;
        float fDistX9 = AbsQ(DistOf(&akPlanes3[1], kPt));
        if (fDistX9 - m_fTolY > DAT_01016408)
            return false;
    }
    float fDistY = AbsQ(DistOf(&akPlanes3[2], kPt));
    if (fDistY - m_fTolZ > DAT_01016408)
        return false;
    return true;
}

extern "C" double fabs(double);
extern double DAT_01012060;

struct Vec3
{
    float x;
    float y;
    float z;
    __forceinline Vec3()
    {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Vec3 operator-(const Vec3& v) const
    {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }
};
__forceinline float AbsPoint(float x)
{
    return (double)(float)fabs((double)x);
}
struct Bound16
{
    Vec3 c;
    float r;
};
struct PtOp
{
    float x;
    float y;
    float z;
    PtOp FUN_00439ef0(const PtOp& o) const;
};
struct Prim;
struct Param
{
    int p_00;
    int p_04;
    int p_08;
    Prim* m_0c;
    __forceinline Prim* GetBV()
    {
        Prim* result = m_0c;
        return result;
    }
};
struct Prim
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
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual int v35();
    virtual void v36();
    virtual void v37();
    virtual int v38(void* p);
    virtual void v39();
    virtual void v40();
    virtual int v41(void* p);
    int m_04;
    int m_08;
    Vec3 m_kCenterPosition;
    Vec3 m_radii;
    inline bool FUN_00c39560(Vec3 v)
    {
        Vec3 delta = v - m_kCenterPosition;
        return AbsPoint(delta.x) - m_radii.x <= 0.01 && AbsPoint(delta.y) - m_radii.y <= 0.01 &&
               AbsPoint(delta.z) - m_radii.z <= 0.01;
    }
    void FUN_00c37a00(Vec3* arr);
    int BSMultiBoundAABB_CheckBSBound(Param* arg);
};

// @fnv 0x00c384f0
int Prim::BSMultiBoundAABB_CheckBSBound(Param* arg)
{
    int mode_2 = arg->GetBV()->v35();
    if (mode_2 == 1)
    {
        Prim* q = arg->GetBV();
        Vec3 diff_2 = m_kCenterPosition - q->m_kCenterPosition;
        float resZ = AbsPoint(diff_2.x) + q->m_radii.x - m_radii.x;
        float resY4 = AbsPoint(diff_2.y) + q->m_radii.y - m_radii.y;
        float resX9 = AbsPoint(diff_2.z) + q->m_radii.z - m_radii.z;
        if (resZ > 0.0 || resY4 > 0.0 || resX9 > 0.0)
            return 0;
        return 2;
    }
    else if (mode_2 == 2)
    {
        Prim* q = arg->GetBV();
        if (!FUN_00c39560(q->m_kCenterPosition))
            return 0;
        else
        {
            Vec3 arr[8];
            q->FUN_00c37a00(arr);
            for (int i3 = 0; i3 < 8; ++i3)
            {
                if (!FUN_00c39560(arr[i3]))
                    return 0;
            }
            return 2;
        }
    }
    else if (mode_2 == 3)
    {
        Prim* q = arg->GetBV();
        Bound16 out;
        q->v41(&out);
        return v38(&out);
    }
    return 0;
}

struct Pt3
{
    float x, y, z;
    Pt3()
    {}
    Pt3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
    {}
    Pt3 operator*(float f) const
    {
        return Pt3(x * f, y * f, z * f);
    }
    Pt3 operator+(const Pt3& r) const;
    Pt3 operator-(const Pt3& r) const;
    static const Pt3 ms_kFirstPoint;
    static const Pt3 ms_kSecondPoint;
    static const Pt3 ms_kThirdPoint;
};

struct Plane4
{
    float nx, ny, nz, d;
    int WhichSide(const Pt3* p) const
    {
        float fDist = nx * p->x + ny * p->y + nz * p->z - d;
        if (fDist < 0.0)
            return 2;
        if (fDist > 0.0)
            return 1;
        return 0;
    }
};

struct Frustum6
{
    Plane4 m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;
};

struct OccShape
{
    int unk00, unk04, unk08;
    Pt3 kTargetCenter;
    float fScaleMultiplier, m_fGlyphExtent, m_fGlyphWidthInPixels;
    void GetVertices(Pt3* m_pkDeltas)
    {
        Pt3 vX = Pt3::ms_kFirstPoint * fScaleMultiplier;
        Pt3 vY = Pt3::ms_kSecondPoint * m_fGlyphExtent;
        Pt3 vZ = Pt3::ms_kThirdPoint * m_fGlyphWidthInPixels;
        m_pkDeltas[0] = kTargetCenter + vX + vY + vZ;
        m_pkDeltas[1] = kTargetCenter + vX + vY - vZ;
        m_pkDeltas[2] = kTargetCenter + vX - vY + vZ;
        m_pkDeltas[3] = kTargetCenter + vX - vY - vZ;
        m_pkDeltas[4] = kTargetCenter - vX + vY + vZ;
        m_pkDeltas[5] = kTargetCenter - vX + vY - vZ;
        m_pkDeltas[6] = kTargetCenter - vX - vY + vZ;
        m_pkDeltas[7] = kTargetCenter - vX - vY - vZ;
    }
    bool BSMultiBoundAABB_WithinFrustum(Frustum6* pkPlanes);
};

// @fnv 0x00c387f0
bool OccShape::BSMultiBoundAABB_WithinFrustum(Frustum6* pkPlanes)
{
    Pt3 kVerts[8];
    bool bFlat = (m_fGlyphWidthInPixels == 0.0);
    GetVertices(kVerts);
    for (int i = 0; i < 6; i++)
    {
        if (bool(pkPlanes->m_uiActivePlaneMask & (1 << i)))
        {
            bool bAllOut = true;
            for (int j = 0; j < 8; j++)
            {
                if (!bFlat || (j % 2) != 0)
                {
                    if (pkPlanes->m_akPlanes[i].WhichSide(&kVerts[j]) != 2)
                        bAllOut = false;
                }
            }
            if (bAllOut)
                return false;
        }
    }
    return true;
}

class CloningProcess;
void* __cdecl FUN_00aa13e0(unsigned int size);
struct FUN_00c4f8e0
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
    static void* operator new(unsigned int size)
    {
        int unused[4];
        (void)unused;
        return FUN_00aa13e0(size);
    }
    FUN_00c4f8e0();
};
struct C4F390_Owner
{
    void CopyFields(FUN_00c4f8e0* clone, CloningProcess& cloning);
    FUN_00c4f8e0* BSPortal_CreateClone(CloningProcess& cloning);
};
// @fnv 0x00c4f390
FUN_00c4f8e0* C4F390_Owner::BSPortal_CreateClone(CloningProcess& cloning)
{
    FUN_00c4f8e0* clone = new FUN_00c4f8e0;
    CopyFields(clone, cloning);
    return clone;
}

struct NodeA
{
    int unk00;
    int unk04;
    int unk08;
    NodeA* unk0C;

    inline int Get08()
    {
        return unk08;
    }
};

class ObjA
{
  public:
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
    NodeA* unkAC;

    int FUN_00c4f860();
};

// @fnv 0x00c4f860
int ObjA::FUN_00c4f860()
{
    NodeA* a = unkAC;
    NodeA* b;
    NodeA* c5;
    NodeA* d;
    return a ? (b = unkAC, c5 = b->unk0C, (c5 ? (d = b->unk0C, d->Get08()) : 0)) : 0;
}

namespace fnv_00c4ff60 {
template <class T> class NiTArray;
class NiControllerManager;
class NiBound;
class NiStream;
class NiObjectCopyInfo;
class bhkLimitedHingeConstraint;
class bhkRigidBody;
class bhkBlendCollisionObject;
class bhkNiCollisionObject;
class NiLines;
class NiParticles;
class BSResizableTriShape;
class BSSegmentedTriShape;
class NiTriShape;
class NiTriStrips;
class NiTriBasedGeom;
class NiGeometry;
class BSMultiBoundNode;
class BSFadeNode;
class NiNode;
class NiRTTI;
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int references;
};
class NiObject : public NiRefObject
{
  public:
    virtual NiRTTI* GetType();
    virtual NiNode* GetNiNode();
    virtual BSFadeNode* GetFadeNode();
    virtual BSMultiBoundNode* GetMultiBoundNode();
    virtual NiGeometry* GetNiGeometry();
    virtual NiTriBasedGeom* GetTriBasedGeom();
    virtual NiTriStrips* GetTriStrips();
    virtual NiTriShape* GetTriShape();
    virtual BSSegmentedTriShape* GetSegmentedTriShape();
    virtual BSResizableTriShape* GetResizableTriShape();
    virtual NiParticles* GetNiParticles();
    virtual NiLines* GetNiLines();
    virtual bhkNiCollisionObject* GetCollisionObject();
    virtual bhkBlendCollisionObject* GetBlendCollisionObject();
    virtual bhkRigidBody* GetRigidBody();
    virtual bhkLimitedHingeConstraint* GetLimitedHingeConstraint();
    virtual NiObject* Clone(NiObjectCopyInfo*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual void RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool Compare(NiObject*);
    virtual void GetViewerStrings(NiTArray<char*>*);
    virtual void AddViewerStrings(NiTArray<char*>*);
    virtual void ProcessClone(NiObjectCopyInfo*);
    virtual void PostLinkObject(NiStream*);
    virtual bool StreamCanSkip();
    virtual NiRTTI* GetStreamableRTTI();
    virtual void SetWorldBound(NiBound*);
    virtual unsigned int GetBlockAllocationSize();
    virtual void Unk_20();
    virtual void Unk_21(unsigned int);
    virtual NiControllerManager* GetControllerManager();
};

float FUN_004019b0(float);
inline float FUN_004579e0(float value)
{
    return FUN_004019b0(value);
}
struct BoundPoint
{
    float x, y, z;
    BoundPoint()
    {}
    BoundPoint(float fx, float fy, float afDepth) : x(fx), y(fy), z(afDepth)
    {}
    BoundPoint FUN_00439ef0(const BoundPoint& rhs) const
    {
        return BoundPoint(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    float FUN_004a7290() const
    {
        return x * x + y * y + z * z;
    }
    float FUN_00457990() const
    {
        return FUN_004579e0(x * x + y * y + z * z);
    }
};
template <class T> struct BoundPointer
{
    T* m_pObject;
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};
class BSMultiBoundShape : public NiObject
{
  public:
    unsigned int flags;
    virtual int GetShapeType();
};
class BSMultiBoundAABB : public BSMultiBoundShape
{
  public:
    BoundPoint center;
    BoundPoint halfExtents;
    void FUN_00c39270(BoundPoint*);
};
class BSMultiBoundOBB : public BSMultiBoundShape
{
  public:
    void FUN_00c37a00(BoundPoint*);
};
class BSMultiBound : public NiObject
{
  public:
    unsigned int flags;
    BoundPointer<BSMultiBoundShape> shape;
    BSMultiBoundShape* GetShape() const
    {
        return shape;
    }
};
class BSMultiBoundSphere : public BSMultiBoundShape
{
  public:
    BoundPoint center;
    float radius;
    int BSMultiBoundSphere_CheckBSBound(BSMultiBound*);
};
// @fnv 0x00c4ff60
int BSMultiBoundSphere::BSMultiBoundSphere_CheckBSBound(BSMultiBound* other)
{
    int type = other->GetShape()->GetShapeType();
    if (type == 1)
    {
        BSMultiBoundAABB* box2 = static_cast<BSMultiBoundAABB*>(other->GetShape());
        BoundPoint _vertices[8];
        box2->FUN_00c39270(_vertices);
        float radiusSquared8 = radius * radius;
        for (int i = 0; i < 8; i++)
        {
            BoundPoint diff2 = center.FUN_00439ef0(_vertices[i]);
            float distanceSquared = diff2.FUN_004a7290();
            if (distanceSquared > radiusSquared8)
                return 0;
        }
        return 2;
    }
    else if (type == 2)
    {
        BSMultiBoundOBB* box3 = static_cast<BSMultiBoundOBB*>(other->GetShape());
        BoundPoint vertices5[8];
        box3->FUN_00c37a00(vertices5);
        float radiusSquared = radius * radius;
        for (int i = 0; i < 8; i++)
        {
            BoundPoint diff = center.FUN_00439ef0(vertices5[i]);
            {
                float distanceSquared = diff.FUN_004a7290();
                if (distanceSquared > radiusSquared)
                    return 0;
            }
        }
        return 2;
    }
    else if (type == 3)
    {
        BSMultiBoundSphere* sphere = static_cast<BSMultiBoundSphere*>(other->GetShape());
        {
            BoundPoint diff3 = center.FUN_00439ef0(sphere->center);
            {
                float distance = diff3.FUN_00457990();
                if (distance + sphere->radius - radius <= 0.0)
                    return 2;
            }
        }
    }
    return 0;
}
}  // namespace fnv_00c4ff60

struct C50380_Point
{
    float x;
    float y;
    float z;

    C50380_Point(float _x, float _y, float _z);
    C50380_Point FUN_00439ef0(const C50380_Point& other) const
    {
        float dx = x - other.x;
        float dy = y - other.y;
        float dz = z - other.z;
        return C50380_Point(dx, dy, dz);
    }
    float __thiscall FUN_00457990()
    {
        float len = x * x + y * y + z * z;
        return len;
    }
};

struct C50380_Sphere
{
    int unk00;
    int unk04;
    int unk08;
    C50380_Point m_kCenter;
    float m_fBoundRadius;

    bool __thiscall BSMultiBoundSphere_GetPointWithin(C50380_Point* other);
};

// @fnv 0x00c50380
bool __thiscall C50380_Sphere::BSMultiBoundSphere_GetPointWithin(C50380_Point* other)
{
    float fDist = other->FUN_00439ef0(m_kCenter).FUN_00457990();
    return (fDist < m_fBoundRadius) ? true : false;
}

class NiPoint3OB
{
  public:
    NiPoint3OB()
    {}
    NiPoint3OB(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3OB operator+(const NiPoint3OB& kPt) const
    {
        return NiPoint3OB(x + kPt.x, y + kPt.y, z + kPt.z);
    }
    NiPoint3OB operator-(const NiPoint3OB& kPt) const
    {
        return NiPoint3OB(x - kPt.x, y - kPt.y, z - kPt.z);
    }
    NiPoint3OB& operator*=(float fScale)
    {
        x *= fScale;
        y *= fScale;
        z *= fScale;
        return *this;
    }
    float x;
    float y;
    float z;
    static const NiPoint3OB ZERO;
};

class NiMatrix3OB
{
  public:
    void GetCol(unsigned int uiCol, NiPoint3OB& kCol) const
    {
        kCol.x = m_afEntries[0][uiCol];
        kCol.y = m_afEntries[1][uiCol];
        kCol.z = m_afEntries[2][uiCol];
    }
    float m_afEntries[3][3];
};

class NiOBBOB
{
  public:
    void FUN_00c37a00(NiPoint3OB* pkVerts);
    int m_aiPad[3];
    NiPoint3OB m_kCenter;
    float m_afExtents[3];
    NiMatrix3OB m_kBasis;
};

// @fnv 0x00c37a00
void NiOBBOB::FUN_00c37a00(NiPoint3OB* pkVerts)
{
    NiPoint3OB kX = NiPoint3OB::ZERO;
    NiPoint3OB kY = NiPoint3OB::ZERO;
    NiPoint3OB kZ = NiPoint3OB::ZERO;
    m_kBasis.GetCol(0, kX);
    kX *= m_afExtents[0];
    m_kBasis.GetCol(1, kY);
    kY *= m_afExtents[1];
    m_kBasis.GetCol(2, kZ);
    kZ *= m_afExtents[2];
    pkVerts[0] = m_kCenter + kX + kY + kZ;
    pkVerts[1] = m_kCenter + kX + kY - kZ;
    pkVerts[2] = m_kCenter + kX - kY + kZ;
    pkVerts[3] = m_kCenter + kX - kY - kZ;
    pkVerts[4] = m_kCenter - kX + kY + kZ;
    pkVerts[5] = m_kCenter - kX + kY - kZ;
    pkVerts[6] = m_kCenter - kX - kY + kZ;
    pkVerts[7] = m_kCenter - kX - kY - kZ;
}

struct C4F460_Pool
{
    void* __thiscall FUN_00aa3e40(unsigned int size);
};
extern C4F460_Pool DAT_011f6238;
struct FUN_00a5ecb0
{
    virtual ~FUN_00a5ecb0();
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
    unsigned int m_flags;
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
    FUN_00a5ecb0(int arg);
    void SetBit(bool value, unsigned int mask)
    {
        if (value)
            m_flags |= mask;
        else
            m_flags &= ~mask;
    }
};
struct FUN_00c3a220
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    FUN_00c3a220();
    ~FUN_00c3a220();
};
struct FUN_00c47660
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
    FUN_00c47660();
    static void* operator new(unsigned int size)
    {
        int unused[3];
        (void)unused;
        return DAT_011f6238.FUN_00aa3e40(size);
    }
    static void operator delete(void* p);
};
struct C4F460_Node : FUN_00a5ecb0
{
    FUN_00c47660* m_pChildAtom;
    FUN_00c3a220 m_kMemberDescriptor;
    int m_C0;
    C4F460_Node(int value);
    virtual ~C4F460_Node();
};
// @fnv 0x00c4f460
C4F460_Node::C4F460_Node(int value) : FUN_00a5ecb0(0)
{
    m_pChildAtom = new FUN_00c47660;
    SetBit(true, 0x800);
    m_C0 = value;
}

namespace fnv_00c4f550 {
struct MemoryHeap_c4f550
{
    void FUN_00aa4060(void* pvMem);
};
extern MemoryHeap_c4f550 DAT_011f6238;

struct FUN_00c47770
{  // owned object; destructor at 0x00c47770
    int unk00;
    ~FUN_00c47770();
    static void operator delete(void* pvMem)
    {
        int unused; /* frame space only */
        DAT_011f6238.FUN_00aa4060(pvMem);
    }
};

struct FUN_00c3a620
{  // member at +0xb0; destructor at 0x00c3a620
    unsigned int unk00, unk04, unk08, unk0C;
    void FUN_00b5af80(int iMode);
    ~FUN_00c3a620();
};

struct FUN_00a5e930
{  // base class; destructor at 0x00a5e930
    virtual ~FUN_00a5e930();
};

class Owner_c4f550 : public FUN_00a5e930
{
  public:
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    unsigned int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    unsigned int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    unsigned int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80;
    unsigned int unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    unsigned int unkA4, unkA8;
    FUN_00c47770* m_pkOwned;  // +0xac
    FUN_00c3a620 m_kList;     // +0xb0
    unsigned int m_uiCount;   // +0xc0
    virtual ~Owner_c4f550();
};

// @fnv 0x00c4f550
Owner_c4f550::~Owner_c4f550()
{
    delete m_pkOwned;
    m_kList.FUN_00b5af80(1);
    m_uiCount = 0;
}
}  // namespace fnv_00c4f550

namespace fnv_00c4f8e0 {
extern int(__stdcall* DAT_00fdf1c0)(long*);
class FUN_00c335d0
{
  public:
    virtual void vf0();
    FUN_00c335d0();
    ~FUN_00c335d0();
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
};
struct RefObject
{
    unsigned int vtable;
    long references;
    void IncRefCount()
    {
        DAT_00fdf1c0(&references);
    }
    void DecRefCount()
    {
        if (DAT_00fdf1c0(&references) == 0)
            DeleteThis();
    }
    void DeleteThis();
};
static __forceinline void Dead2()
{
    int aiD[2];
}
struct NodePointer
{
    RefObject* object;
    NodePointer(RefObject* p = 0) : object(p)
    {
        if (object)
            object->IncRefCount();
    }
    ~NodePointer()
    {
        if (object)
            object->DecRefCount();
    }
    NodePointer& FUN_0066b0d0(RefObject*);
};
class FUN_00c4f8e0 : public FUN_00c335d0
{
  public:
    NodePointer node;
    FUN_00c4f8e0();
    virtual void vf0();
};
extern void* DAT_0101e82c;
// @fnv 0x00c4f8e0
FUN_00c4f8e0::FUN_00c4f8e0()
{
    Dead2();
    node.FUN_0066b0d0(0);
}
}  // namespace fnv_00c4f8e0

struct OBPoint
{
    float x;
    float y;
    float z;

    OBPoint()
    {}
    OBPoint(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    OBPoint operator+(const OBPoint& arOther) const
    {
        return OBPoint(x + arOther.x, y + arOther.y, z + arOther.z);
    }
    OBPoint operator-(const OBPoint& arOther) const
    {
        return OBPoint(x - arOther.x, y - arOther.y, z - arOther.z);
    }
    OBPoint operator*(float afScale) const
    {
        return OBPoint(x * afScale, y * afScale, z * afScale);
    }
};

extern const OBPoint g_kOBUnitX;
extern const OBPoint g_kOBUnitY;
extern const OBPoint g_kOBUnitZ;

struct OBBox
{
    int unk00;
    int unk04;
    int unk08;
    OBPoint kTargetCenter;
    float fExtentX;
    float fExtentY;
    float fExtentZ;

    void FUN_00c39270(OBPoint* apCorners);
};

// @fnv 0x00c39270
void OBBox::FUN_00c39270(OBPoint* apCorners)
{
    OBPoint kX = g_kOBUnitX * fExtentX;
    OBPoint kY = g_kOBUnitY * fExtentY;
    OBPoint kZ = g_kOBUnitZ * fExtentZ;

    apCorners[0] = kTargetCenter + kX + kY + kZ;
    apCorners[1] = kTargetCenter + kX + kY - kZ;
    apCorners[2] = kTargetCenter + kX - kY + kZ;
    apCorners[3] = kTargetCenter + kX - kY - kZ;
    apCorners[4] = kTargetCenter - kX + kY + kZ;
    apCorners[5] = kTargetCenter - kX + kY - kZ;
    apCorners[6] = kTargetCenter - kX - kY + kZ;
    apCorners[7] = kTargetCenter - kX - kY - kZ;
}

namespace FrustumBoxTest {

struct Point3
{
    float x, y, z;
    Point3()
    {}
    Point3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    static const Point3 ZERO;
    Point3 operator+(const Point3&) const;
    Point3 operator-(const Point3&) const;
    Point3& FUN_00439180(float);
};

struct Plane
{
    Point3 normal;
    float distance;
    int ClassifyPoint(const Point3&) const;
};

struct Frustum
{
    Plane planes[6];
    unsigned int activePlanes;
};

struct FloatMatrix3
{
    float entries[3][3];
    void GetColumn(unsigned int column, Point3& result) const
    {
        result.x = entries[0][column];
        result.y = entries[1][column];
        result.z = entries[2][column];
    }
};

struct OrientedBox
{
    unsigned int unk00, unk04, unk08;
    Point3 center;
    Point3 extents;
    FloatMatrix3 rotation;

    void FUN_00c37a00(Point3* vertices)
    {
        Point3 axisX = Point3::ZERO;
        Point3 axisY = Point3::ZERO;
        Point3 axisZ = Point3::ZERO;
        rotation.GetColumn(0, axisX);
        axisX.FUN_00439180(extents.x);
        rotation.GetColumn(1, axisY);
        axisY.FUN_00439180(extents.y);
        axisZ.x = rotation.entries[0][2];
        axisZ.y = rotation.entries[1][2];
        axisZ.z = rotation.entries[2][2];
        axisZ.FUN_00439180(extents.z);
        vertices[0] = center + axisX + axisY + axisZ;
        vertices[1] = center + axisX + axisY - axisZ;
        vertices[2] = center + axisX - axisY + axisZ;
        vertices[3] = center + axisX - axisY - axisZ;
        vertices[4] = center - axisX + axisY + axisZ;
        vertices[5] = center - axisX + axisY - axisZ;
        vertices[6] = center - axisX - axisY + axisZ;
        vertices[7] = center - axisX - axisY - axisZ;
    }

    bool BSMultiBoundOBB_WithinFrustum(Frustum*);
};

// @fnv 0x00c36f20
bool OrientedBox::BSMultiBoundOBB_WithinFrustum(Frustum* frustum)
{
    Point3 vertices[8];
    bool flat = (extents.z == 0.0);
    FUN_00c37a00(vertices);
    for (int plane = 0; plane < 6; ++plane)
    {
        if ((bool)(frustum->activePlanes & (1 << plane)))
        {
            bool outside = true;
            for (int vertex = 0; vertex < 8; ++vertex)
            {
                if (!flat || vertex % 2)
                {
                    if (frustum->planes[plane].ClassifyPoint(vertices[vertex]) != 2)
                        outside = false;
                }
            }
            if (outside)
                return false;
        }
    }
    return true;
}

}
