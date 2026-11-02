
// src/havok/common/visualize/shape/hkdisplaybox.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaybox.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;

struct hkTransform;
struct hkMemoryAllocator;

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    void FUN_00c7f640(const hkTransform& t, const hkVector4& p);
    void set(const hkVector4& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
};
struct hkRotation
{
    hkVector4 c0, c1, c2;
};
struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};

__declspec(nothrow) void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

struct hkVector4Array
{
    hkVector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void SetSizeAndGrow(hkMemoryAllocator& alloc, int n)
    {
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(hkVector4));
        }
        m_iElementCount = n;
    }
};

struct hkBoxGeometry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkTransform m_kMotionTransform;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    hkVector4 m_vHalfExtents;

    void GetEdgeLines(hkVector4Array& lines, hkMemoryAllocator& alloc);
};

// @fnv 0x00de2050
void hkBoxGeometry::GetEdgeLines(hkVector4Array& aEdgeLines, hkMemoryAllocator& aAllocator)
{
    aEdgeLines.SetSizeAndGrow(aAllocator, 24);

    hkVector4 verts[8];
    for (int iVertex = 0; iVertex < 8; iVertex++)
    {
        hkVector4 halfExtent = m_vHalfExtents;
        if (iVertex & 1)
            halfExtent.x *= -1.0;
        if (iVertex & 2)
            halfExtent.y *= -1.0;
        if (iVertex & 4)
            halfExtent.z *= -1.0;
        verts[iVertex].FUN_00c7f640(m_kMotionTransform, halfExtent);
    }

    int n = 0;
    for (int iVertex = 0; iVertex < 8; iVertex++)
    {
        for (int iBit = 1; iBit < 8; iBit <<= 1)
        {
            int iOtherVertex = iVertex ^ iBit;
            if (iVertex < iOtherVertex)
            {
                aEdgeLines.m_data[n++].set(verts[iVertex]);
                aEdgeLines.m_data[n++].set(verts[iOtherVertex]);
            }
        }
    }
}

extern "C" __m128 _mm_setzero_ps(void);
struct __declspec(align(16)) Vector4D22DC0
{
    float x;
    float y;
    float z;
    float w;
    void setZero4()
    {
        *reinterpret_cast<__m128*>(this) = _mm_setzero_ps();
    }
    void operator=(const Vector4D22DC0& kOther)
    {
        *reinterpret_cast<__m128*>(this) = *reinterpret_cast<const __m128*>(&kOther);
    }
};
struct RotationD22DC0
{
    Vector4D22DC0 m_kColumn0;
    Vector4D22DC0 m_kColumn1;
    Vector4D22DC0 m_kColumn2;
    float& operator()(int iRow, int iCol)
    {
        return reinterpret_cast<float*>(&m_kColumn0 + iCol)[iRow];
    }
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        (*this)(0, 0) = 1.0f;
        (*this)(1, 1) = 1.0f;
        (*this)(2, 2) = 1.0f;
    }
};
struct TransformD22DC0
{
    RotationD22DC0 m_rotation;
    Vector4D22DC0 m_vTranslation;
    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};
struct ReferencedD22DC0
{
    ReferencedD22DC0() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~ReferencedD22DC0() throw();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
struct ShapeD22DC0 : public ReferencedD22DC0
{
    ShapeD22DC0(int iType) throw() : m_ulUserData(0), m_type(iType)
    {
        m_kMotionTransform.setIdentity();
    }
    virtual ~ShapeD22DC0() throw();
    int m_ulUserData;
    int unk0C;
    TransformD22DC0 m_kMotionTransform;
    int m_type;
};
struct FUN_00d58510 : public ShapeD22DC0
{
    FUN_00d58510(const Vector4D22DC0& kA, const Vector4D22DC0& kB, float fRadius, int iA, int iB) throw();
    virtual ~FUN_00d58510() throw();
    Vector4D22DC0 m_kA;
    Vector4D22DC0 m_kB;
    float m_fBoundRadius;
    int m_iA;
    int m_iB;
};

// @fnv 0x00d58510
FUN_00d58510::FUN_00d58510(const Vector4D22DC0& kA, const Vector4D22DC0& kB, float afBoundRadius, int iA,
                           int iB) throw()
    : ShapeD22DC0(9), m_iA(iA), m_iB(iB)
{
    m_kA = kA;
    m_kB = kB;
    m_fBoundRadius = afBoundRadius;
}
