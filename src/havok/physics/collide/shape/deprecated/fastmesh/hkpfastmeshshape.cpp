
// src/havok/physics/collide/shape/deprecated/fastmesh/hkpfastmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/fastmesh/hkpfastmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpFastMeshShape.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_mul_ps(__m128 kA, __m128 kB);
extern "C" __m128 _mm_load_ps(const float*);

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct hkVector4E48C
{
    __m128 m_vComponents;

    hkVector4E48C()
    {}
    hkVector4E48C(const hkVector4E48C& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4E48C& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    void setMul4(const hkVector4E48C& kA, const hkVector4E48C& kB)
    {
        m_vComponents = _mm_mul_ps(kA.m_vComponents, kB.m_vComponents);
    }
};

template <class T> struct hkArrayE48C
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkBaseObjectE48C
{
  public:
    virtual ~hkBaseObjectE48C() throw();
};

class hkReferencedObjectE48C : public hkBaseObjectE48C
{
  public:
    hkReferencedObjectE48C() throw() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectE48C() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShapeE48C : public hkReferencedObjectE48C
{
  public:
    hkpShapeE48C(unsigned int uiType) throw() : m_ulUserData(0), m_type(uiType)
    {}
    virtual ~hkpShapeE48C() throw();

    unsigned long m_ulUserData;
    unsigned int m_type;
};

class hkpSphereRepShapeE48C : public hkpShapeE48C
{
  public:
    hkpSphereRepShapeE48C(unsigned int uiType) throw() : hkpShapeE48C(uiType)
    {}
    virtual ~hkpSphereRepShapeE48C() throw();
};

class hkpConvexShapeE48C : public hkpSphereRepShapeE48C
{
  public:
    hkpConvexShapeE48C(unsigned int uiType, float fRadius) throw()
        : hkpSphereRepShapeE48C(uiType), m_fSphereRadius(fRadius)
    {}
    virtual ~hkpConvexShapeE48C() throw();

    float m_fSphereRadius;
};

class FUN_00de10b0 : public hkpConvexShapeE48C
{
  public:
    FUN_00de10b0(float fRadius, unsigned short usWeldingInfo, int eWeldingType) throw() : hkpConvexShapeE48C(3, fRadius)
    {
        m_kWeldingInfo = usWeldingInfo;
        m_eWeldingType = static_cast<unsigned char>(eWeldingType);
        m_kVertexTransform.setZero4();
        m_ucWeldingPadding = 0;
    }
    virtual ~FUN_00de10b0() throw();

    void setVertex(int i, const hkVector4E48C& kVertexDelta)
    {
        (&m_kVertexA)[i] = kVertexDelta;
    }

    unsigned short m_kWeldingInfo;
    unsigned char m_eWeldingType;
    unsigned char m_ucWeldingPadding;
    hkVector4E48C m_kVertexA;
    hkVector4E48C m_kVertexB;
    hkVector4E48C m_kVertexC;
    hkVector4E48C m_kVertexTransform;
};

class hkpShapeContainerE48C
{
  public:
    virtual ~hkpShapeContainerE48C() throw();
    virtual const hkpShapeE48C* FUN_00e48cb0(unsigned int uiKey, unsigned char* pucBuffer) const = 0;
};

class hkpShapeCollectionE48C : public hkpShapeE48C, public hkpShapeContainerE48C
{
  public:
    virtual ~hkpShapeCollectionE48C() throw();

    char m_bDisableWelding;
    unsigned char m_eCollectionType;
};

struct hkpMeshShapeSubpartE48C
{
    const void* m_pMaterialIndexBase;
    int m_iTriangleIndexStride;
    int m_iStridedVertexCount;
    const void* m_pMaterialDataBase;
    int m_ucIndexStridingType;
    int m_iMaterialStriding;
    int m_bFlipAlternateTriangles;
    int m_iTriangleCount;
    unsigned int unk20, unk24, unk28, unk2C, unk30;
    int m_iTriangleOffset;
};

class hkpMeshShapeE48C : public hkpShapeCollectionE48C
{
  public:
    virtual ~hkpMeshShapeE48C() throw();
    virtual const hkpShapeE48C* FUN_00e48cb0(unsigned int uiKey, unsigned char* pucBuffer) const;

    unsigned int unk18, unk1C;
    hkVector4E48C m_kScaling;
    int m_iNumBitsForSubpartIndex;
    hkArrayE48C<hkpMeshShapeSubpartE48C> m_kSubparts;
    hkArrayE48C<unsigned short> m_kWeldingInfo;
    unsigned char m_eWeldingType;
    float m_fSphereRadius;
};

// Builds a FUN_00de10b0 triangle in pucBuffer from subpart 0 vertex data, scaling, and welding info for the given uiKey.
// @fnv 0x00e48cb0
const hkpShapeE48C* hkpMeshShapeE48C::FUN_00e48cb0(unsigned int uiKey, unsigned char* pucBuffer) const
{
    const hkpMeshShapeSubpartE48C& kPart = m_kSubparts[0];
    const unsigned short* pusTriangle = reinterpret_cast<const unsigned short*>(
        static_cast<const char*>(kPart.m_pMaterialDataBase) + kPart.m_iMaterialStriding * uiKey);
    int iFlip = kPart.m_bFlipAlternateTriangles & uiKey;
    const hkVector4E48C* pkA = reinterpret_cast<const hkVector4E48C*>(
        static_cast<const char*>(kPart.m_pMaterialIndexBase) + pusTriangle[0] * kPart.m_iTriangleIndexStride);
    const hkVector4E48C* pkB = reinterpret_cast<const hkVector4E48C*>(
        static_cast<const char*>(kPart.m_pMaterialIndexBase) + pusTriangle[1 + iFlip] * kPart.m_iTriangleIndexStride);
    const hkVector4E48C* pkC =
        reinterpret_cast<const hkVector4E48C*>(static_cast<const char*>(kPart.m_pMaterialIndexBase) +
                                               pusTriangle[1 + (iFlip ^ 1)] * kPart.m_iTriangleIndexStride);
    unsigned short usWeldingInfo = (m_kWeldingInfo.m_iElementCount == 0) ? 0 : m_kWeldingInfo[kPart.m_iTriangleOffset + uiKey];
    FUN_00de10b0* pkTriangle = new (pucBuffer) FUN_00de10b0(m_fSphereRadius, usWeldingInfo, m_eWeldingType);
    pkTriangle->m_kVertexA.setMul4(*pkA, m_kScaling);
    pkTriangle->m_kVertexB.m_vComponents =
        _mm_mul_ps(_mm_load_ps(pkB->m_vComponents.m128_f32), m_kScaling.m_vComponents);
    pkTriangle->m_kVertexC.setMul4(*pkC, m_kScaling);
    return pkTriangle;
}
