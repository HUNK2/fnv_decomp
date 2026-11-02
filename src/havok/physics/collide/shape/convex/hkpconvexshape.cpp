
// src/havok/physics/collide/shape/convex/hkpconvexshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/hkpconvexshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConvexShape.h"

// @fnv 0x00c9e1e0
int __stdcall FUN_00c9e1e0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    return 2;
}

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class hkReferencedObjectC9E3
{
  public:
    hkReferencedObjectC9E3() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectC9E3() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class hkpShapeC9E3 : public hkReferencedObjectC9E3
{
  public:
    hkpShapeC9E3(int iType) : m_ulUserData(0), m_type(iType)
    {}
    hkUlong m_ulUserData;
    int m_type;
};

class hkpConvexShapeC9E3 : public hkpShapeC9E3
{
  public:
    hkpConvexShapeC9E3(int iType, hkReal fRadius) : hkpShapeC9E3(iType)
    {
        m_fSphereRadius = fRadius;
    }
    hkReal m_fSphereRadius;
};

class hkpShapeContainerC9E3
{
  public:
    virtual ~hkpShapeContainerC9E3() throw()
    {}
};

class hkpSingleShapeContainerC9E3 : public hkpShapeContainerC9E3
{
  public:
    hkpSingleShapeContainerC9E3(FUN_00d1df70* pkChild, int iRef) : m_pContainedShape(pkChild)
    {
        if (iRef == 1)
            m_pContainedShape->FUN_00c90510();
    }
    virtual ~hkpSingleShapeContainerC9E3() throw();
    FUN_00d1df70* m_pContainedShape;
};

class FUN_00c9e340 : public hkpConvexShapeC9E3
{
  public:
    hkpSingleShapeContainerC9E3 m_pContainedShape;

    FUN_00c9e340(int iType, hkReal fRadius, FUN_00d1df70* pkChild, int iRef) throw();
    virtual ~FUN_00c9e340() throw();
};

// @fnv 0x00c9e340
FUN_00c9e340::FUN_00c9e340(int iShapeType, hkReal fRadius, FUN_00d1df70* pkChild, int iRef) throw()
    : hkpConvexShapeC9E3(iShapeType, fRadius), m_pContainedShape(pkChild, iRef)
{}

#include <xmmintrin.h>
struct S00c9e1f0_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void method(int arg, float* out);

    float unk04;
    float unk08;
    float unk0C;
    float m_10;

    float GetDotProductOffset(int arg);
};

// Calls method(arg, buf), then returns m_10 plus the 3-component dot product of the vector at arg and buf.
// @fnv 0x00c9e1f0
float S00c9e1f0_Obj::GetDotProductOffset(int arg)
{
    __declspec(align(16)) float buf[4];
    method(arg, buf);

    __m128 v = _mm_load_ps(reinterpret_cast<const float*>(arg));
    __m128 w = _mm_load_ps(buf);
    __m128 vProduct = _mm_mul_ps(v, w);

    __m128 s1 = _mm_shuffle_ps(vProduct, vProduct, 0x55);
    __m128 s2 = _mm_shuffle_ps(vProduct, vProduct, 0xAA);

    s1 = _mm_add_ss(s1, vProduct);
    s2 = _mm_add_ss(s2, s1);

    float dot;
    _mm_store_ss(&dot, s2);
    return m_10 + dot;
}

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

struct Mat3
{
    Vec4 c0, c1, c2;
};

struct Out
{
    Vec4 v;
    float t;
    int flags;
    int unk01;
    int unk02;
    int b;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int c;
};

struct P2
{
    int unk0;
    int unk1;
    Mat3* m;
};

struct Cb;

struct VTable
{
    void(__thiscall* fn)(Cb*, P2*, Vec4*);
};

struct Cb
{
    VTable* vt;
    float f;
};

class Shape
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(bool* ok, void* p1, Out* out);
};

struct FN : public Shape
{
    void FUN_00c9e2a0(int p1, int p2, Cb* p3);
};

// Calls v8 to fill out.v, multiplies it by the Mat3 in P2, stores the result back, then invokes the VTable callback fn on Cb.
// @fnv 0x00c9e2a0
void FN::FUN_00c9e2a0(int p1, int p2, Cb* apCb)
{
    bool ok;
    Out out;

    out.t = apCb->f;
    out.flags = -1;
    out.b = -1;
    out.c = 0;

    this->v8(&ok, (void*)(*(volatile int*)&p1), &out);

    if (ok)
    {
        __m128 v = _mm_load_ps(&out.v.x);
        int p2Value = p2;
        P2* pP2 = (P2*)p2Value;
        Mat3* m = pP2->m;
        VTable* vt = apCb->vt;
        void(__thiscall * fn)(Cb*, P2*, Vec4*) = vt->fn;

        __m128 c0 = _mm_load_ps(&m->c0.x);
        __m128 c1 = _mm_load_ps(&m->c1.x);
        __m128 c2 = _mm_load_ps(&m->c2.x);

        __m128 r = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1), _mm_mul_ps(_mm_shuffle_ps(v, v, 0), c0));
        r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2));

        _mm_store_ps(&out.v.x, r);
        fn(apCb, pP2, &out.v);
    }
}
