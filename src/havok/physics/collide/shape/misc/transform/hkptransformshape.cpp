
// src/havok/physics/collide/shape/misc/transform/hkptransformshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/misc/transform/hkptransformshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpTransformShape.h"

struct FUN_00cf5900
{
    int calc(int a2, int a3);
};

// @fnv 0x00cf5900
int FUN_00cf5900::calc(int aiArg, int aiLimit)
{
    int result = (*(int(__thiscall**)(void*, int, int))(*(int*)(*(int*)((char*)this + 0x14)) + 0x18))(
        *(void**)((char*)this + 0x14), aiArg, aiLimit - 0x70);
    if (result < 0)
        return -1;
    if (result > aiLimit - 0x70)
        return -1;
    if (*(void**)((char*)this + 0x14) == (void*)((char*)this + 0x70))
    {
        *(int*)((char*)this + 0x18) = 0;
        return result + 0x70;
    }
    *(int*)((char*)this + 0x18) = result;
    return 0x70;
}

class hkClassCF58;

extern const hkClassCF58 DAT_01268910;

class hkStatisticsCollectorCF58
{
  public:
    virtual ~hkStatisticsCollectorCF58() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
};

class hkpShapeCF58
{
  public:
    void FUN_00c90360(hkStatisticsCollectorCF58* pkCollector, const hkClassCF58* pkClass) const throw();
};

class hkpSingleShapeContainerCF58 : public hkpShapeCF58
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    const void* m_pContainedShape;

    void AddChildShapeToCollector(hkStatisticsCollectorCF58* pkCollector, const hkClassCF58* pkClass) const throw();
};

// @fnv 0x00cf58c0
void hkpSingleShapeContainerCF58::AddChildShapeToCollector(hkStatisticsCollectorCF58* pkCollector,
                                                           const hkClassCF58* pkClass) const throw()
{
    pkCollector->addChildObject("ChildShape", m_pContainedShape, 0);
    FUN_00c90360(pkCollector, &DAT_01268910);
}

struct FnvCpu_FUN_00cf58f0_CpuObject
{
    char* FUN_00cf58f0();
};
// @fnv 0x00cf58f0
char* FnvCpu_FUN_00cf58f0_CpuObject::FUN_00cf58f0()
{
    return reinterpret_cast<char*>(this) + 16;
}

class hkMemoryAllocatorCF5E
{
  public:
    virtual ~hkMemoryAllocatorCF5E() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCF5E
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF5E* m_pStreamAllocator;
    hkMemoryAllocatorCF5E& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF5E& __cdecl FUN_00c85750();

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class hkReferencedObjectCF5E
{
  public:
    virtual ~hkReferencedObjectCF5E() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkReferencedObjectCF5E*>(p)->m_usMemSizeAndFlags);
    }
};

class hkpShapeCF5E : public hkReferencedObjectCF5E
{
  public:
    hkUlong m_ulUserData;
    hkUint32 m_type;
};

class hkpShapeContainerCF5E
{
  public:
    virtual ~hkpShapeContainerCF5E() throw()
    {}
};

class hkpSingleShapeContainerCF5E : public hkpShapeContainerCF5E
{
  public:
    FUN_00d1df70* m_pContainedShape;

    ~hkpSingleShapeContainerCF5E() throw()
    {
        if (m_pContainedShape)
            m_pContainedShape->removeReference();
    }
};

class hkpTransformShapeCF5E : public hkpShapeCF5E, public hkpSingleShapeContainerCF5E
{
  public:
    hkpTransformShapeCF5E* DestroyAndMaybeFree(unsigned int uiFlags) throw();
};

// Destructs the object, then frees it via operator delete when uiFlags has bit 0 set, and returns this.
// @fnv 0x00cf5e50
hkpTransformShapeCF5E* hkpTransformShapeCF5E::DestroyAndMaybeFree(unsigned int uiFlags) throw()
{
    this->hkpTransformShapeCF5E::~hkpTransformShapeCF5E();
    if (uiFlags & 1)
        hkpTransformShapeCF5E::operator delete(this);
    return this;
}

extern int DAT_010cc41c;
extern int DAT_010c6fd0;

struct FUN_00c90510_class
{
    void FUN_00c90510();
};

struct cf5990_TransformShape
{
    void* m_vtbl;                      // 0x00
    unsigned short unk04;              // 0x04 (memSizeAndFlags, untouched here)
    unsigned short m_sReferenceCount;  // 0x06
    unsigned int m_ulUserData;         // 0x08
    unsigned int m_type;               // 0x0c
    void* m_childContainerVtbl;        // 0x10
    hkpShape* m_pContainedShape;       // 0x14

    void CopyBlock(const hkTransform& transform);
    int FUN_00cf5990(hkpShape* child, const hkTransform& transform);
};

// Initializes the shape with a contained child shape and transform, setting reference count, type, and vtables.
// @fnv 0x00cf5990
int cf5990_TransformShape::FUN_00cf5990(hkpShape* apContainedShape, const hkTransform& transform)
{
    m_sReferenceCount = 1;
    m_ulUserData = 0;
    m_type = 15;
    m_vtbl = &DAT_010cc41c;
    m_childContainerVtbl = &DAT_010c6fd0;
    m_pContainedShape = apContainedShape;
    ((FUN_00c90510_class*)apContainedShape)->FUN_00c90510();
    CopyBlock(transform);
    return (int)this;
}

struct __declspec(align(16)) Quaternion
{
    float x, y, z, w;
};
struct PackedTransform
{
    Quaternion rotationColumn0;
    Quaternion rotationColumn1;
    Quaternion rotationColumn2;
    Quaternion translation;
    void FUN_00cb2240(int a, Quaternion* base);
};
struct Dispatch
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c(PackedTransform* tmp, float factor, int flags);
};
struct FUN_00cf59e0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Dispatch* dispatch;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Quaternion quaternion;
    void FUN_00cf59e0(int a, float factor, int flags);
};
// Builds a PackedTransform from a and quaternion, then forwards it to dispatch->vfn1c with factor and flags.
// @fnv 0x00cf59e0
void FUN_00cf59e0_Class::FUN_00cf59e0(int a, float factor, int flags)
{
    PackedTransform transformed;
    transformed.FUN_00cb2240(a, &quaternion);
    dispatch->vfn1c(&transformed, factor, flags);
}

#include <xmmintrin.h>
struct __declspec(align(16)) Vec4_cf5a
{
    float x, y, z, w;
};

class ConvexChild_cf5a
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual float getMaximumProjection(const Vec4_cf5a& direction) const;
};

class TransformShape_cf5a
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ConvexChild_cf5a* m_pContainedShape;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_vTranslation;

    float FUN_00cf5a20(const __m128& direction);
};

// @fnv 0x00cf5a20
float TransformShape_cf5a::FUN_00cf5a20(const __m128& direction)
{
    __m128 c0 = m_kColumn0;
    __m128 c1 = m_kColumn1;
    __m128 c2 = m_kColumn2;
    {
        __m128 t = _mm_unpacklo_ps(c0, c1);
        __m128 ct = _mm_unpackhi_ps(c0, c1);
        c0 = _mm_movelh_ps(t, c2);
        c1 = _mm_movehl_ps(c0, t);
        c1 = _mm_shuffle_ps(c1, c2, 0xd4);
        c2 = _mm_shuffle_ps(ct, c2, 0xe4);
    }
    __m128 dir = direction;
    __m128 kDirY = _mm_shuffle_ps(dir, dir, 0x55);
    __m128 kDirX = _mm_shuffle_ps(dir, dir, 0x00);
    __m128 kDirZ = _mm_shuffle_ps(dir, dir, 0xaa);
    Vec4_cf5a localDir;
    *(__m128*)&localDir = _mm_add_ps(_mm_add_ps(_mm_mul_ps(kDirY, c1), _mm_mul_ps(kDirX, c0)), _mm_mul_ps(kDirZ, c2));

    float projection = m_pContainedShape->getMaximumProjection(localDir);

    __m128 support = _mm_mul_ps(_mm_load1_ps(&projection), *(const __m128*)&localDir);
    __m128 kWorldSupport =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(support, support, 0x55), m_kColumn1),
                              _mm_mul_ps(_mm_shuffle_ps(support, support, 0x00), m_kColumn0)),
                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(support, support, 0xaa), m_kColumn2), m_vTranslation));
    __m128 prod = _mm_mul_ps(kWorldSupport, direction);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
    float result;
    _mm_store_ss(&result, sum);
    return result;
}
