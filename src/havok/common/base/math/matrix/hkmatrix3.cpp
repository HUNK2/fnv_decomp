
// src/havok/common/base/math/matrix/hkmatrix3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CD4AF0Bool
{
    char m_cBooleanValue;

    CD4AF0Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct CD4AF0Vector4
{
    float x;
    float y;
    float z;
    float w;

    CD4AF0Bool IsStreamValid() const;
};

struct CD4AF0Matrix3
{
    CD4AF0Vector4 m_kColumn0;
    CD4AF0Vector4 m_kColumn1;
    CD4AF0Vector4 m_kColumn2;

    CD4AF0Bool FUN_00cd4af0() const;
};

// @fnv 0x00cd4af0
CD4AF0Bool CD4AF0Matrix3::FUN_00cd4af0() const
{
    return m_kColumn0.IsStreamValid() && m_kColumn1.IsStreamValid() && m_kColumn2.IsStreamValid();
}

// @fnv 0x00cd4b50
int __cdecl FUN_00cd4b50()
{
    return 0x1268370;
}

struct S_00cd4b60
{
    float m[3][4];
    void FUN_00cd4b60();
};
static inline void S_00cd4b60_Swap(float& a, float& b)
{
    float t = a;
    a = b;
    b = t;
}
// @fnv 0x00cd4b60
void S_00cd4b60::FUN_00cd4b60()
{
    S_00cd4b60_Swap(m[1][0], m[0][1]);
    S_00cd4b60_Swap(m[2][0], m[0][2]);
    S_00cd4b60_Swap(m[2][1], m[1][2]);
}

struct S_00cd55a0
{
    void FUN_00cd5050();
};
// @fnv 0x00cd55a0
void FUN_00cd55a0(S_00cd55a0* p)
{
    p->FUN_00cd5050();
}

struct CD4BA0Matrix3
{
    float m_kColumn0[4];
    float m_kColumn1[4];
    float m_kColumn2[4];

    void Transpose(const CD4BA0Matrix3& s);
};

// Copies the transpose of s into this matrix: diagonal entries copied directly, off-diagonal entries swapped, and the fourth column zeroed.
// @fnv 0x00cd4ba0
void CD4BA0Matrix3::Transpose(const CD4BA0Matrix3& s)
{
    m_kColumn0[0] = s.m_kColumn0[0];
    m_kColumn1[1] = s.m_kColumn1[1];
    m_kColumn2[2] = s.m_kColumn2[2];
    m_kColumn2[3] = m_kColumn1[3] = m_kColumn0[3] = 0.0f;
    m_kColumn0[1] = s.m_kColumn1[0];
    m_kColumn1[0] = s.m_kColumn0[1];
    m_kColumn0[2] = s.m_kColumn2[0];
    m_kColumn2[0] = s.m_kColumn0[2];
    m_kColumn1[2] = s.m_kColumn2[1];
    m_kColumn2[1] = s.m_kColumn1[2];
}

struct Matrix3x4
{
    float m[3][4];
};
class CMatrixOps
{
  public:
    bool FUN_00cd4e90(float epsilon);

  private:
    Matrix3x4 m_mat;
    unsigned char* FUN_00cd4e00(unsigned char* out, const Matrix3x4* temp, float epsilon);
};
// @fnv 0x00cd4e90
bool CMatrixOps::FUN_00cd4e90(float epsilon)
{
    __declspec(align(16)) Matrix3x4 temp;
    temp.m[0][0] = m_mat.m[0][0];
    temp.m[1][1] = m_mat.m[1][1];
    temp.m[2][2] = m_mat.m[2][2];
    temp.m[0][3] = 0.0f;
    temp.m[1][3] = 0.0f;
    temp.m[2][3] = 0.0f;
    temp.m[0][1] = m_mat.m[1][0];
    temp.m[1][0] = m_mat.m[0][1];
    temp.m[0][2] = m_mat.m[2][0];
    temp.m[2][0] = m_mat.m[0][2];
    temp.m[1][2] = m_mat.m[2][1];
    temp.m[2][1] = m_mat.m[1][2];
    unsigned char out;
    return *FUN_00cd4e00(&out, &temp, epsilon) != 0;
}

struct CdOwner_cls;

struct CdPairOut_cls
{
    unsigned int m_00;
    unsigned int m_04;
    void FUN_00cd5610(CdOwner_cls* owner, unsigned int a1);
};

__declspec(align(16)) struct CdBlob_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
};

struct FUN_00cd5880_cls
{
    unsigned int unk00;
    unsigned int unk04;
    void FUN_00cd55b0(unsigned int a1, CdPairOut_cls* out);
    void FUN_00cd5880(unsigned int a1);
};

struct CdOwner_cls
{
    unsigned int unk00;
    unsigned int unk04;
};

// @fnv 0x00cd5880
void FUN_00cd5880_cls::FUN_00cd5880(unsigned int a1)
{
    CdBlob_cls blob;
    ((CdPairOut_cls*)&blob.m_00)->FUN_00cd5610((CdOwner_cls*)this, a1);
    this->FUN_00cd55b0(a1, (CdPairOut_cls*)&blob.m_00);
}

#ifndef _INCLUDED_MM2
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
#endif

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_unpacklo_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_movelh_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_movehl_ps(__m128 a, __m128 b);
#endif

class hkMatrix3CD4B;

struct hkVector4CD4B
{
    __m128 m_vComponents;

    hkVector4CD4B()
    {}
    hkVector4CD4B(const hkVector4CD4B& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4CD4B& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void _setRotatedDir(const hkMatrix3CD4B& r, const hkVector4CD4B& b);
};

class hkMatrix3CD4B
{
  public:
    void FUN_00cd4bf0(const hkMatrix3CD4B& kA, const hkMatrix3CD4B& kB);

    hkVector4CD4B& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    const hkVector4CD4B& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
    void transpose()
    {
        __m128 tmp = _mm_unpacklo_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents);
        __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents),
                                     m_kColumn2.m_vComponents, 0xe4);
        m_kColumn0.m_vComponents = _mm_movelh_ps(tmp, m_kColumn2.m_vComponents);
        tmp = _mm_movehl_ps(m_kColumn0.m_vComponents, tmp);
        m_kColumn1.m_vComponents = _mm_shuffle_ps(tmp, m_kColumn2.m_vComponents, 0xd4);
        m_kColumn2.m_vComponents = ctmp;
    }

    hkVector4CD4B m_kColumn0;
    hkVector4CD4B m_kColumn1;
    hkVector4CD4B m_kColumn2;
};

__forceinline void hkVector4CD4B::_setRotatedDir(const hkMatrix3CD4B& r, const hkVector4CD4B& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(r.m_kColumn0.m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(r.m_kColumn1.m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(r.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

// Transposes kA, applies the transposed matrix to each column of kB, and stores those results here.
// @fnv 0x00cd4bf0
void hkMatrix3CD4B::FUN_00cd4bf0(const hkMatrix3CD4B& kA, const hkMatrix3CD4B& kB)
{
    hkMatrix3CD4B kATrans;
    kATrans.m_kColumn0 = kA.m_kColumn0;
    kATrans.m_kColumn1 = kA.m_kColumn1;
    kATrans.m_kColumn2 = kA.m_kColumn2;
    kATrans.transpose();
    for (int i = 0; i < 3; i++)
    {
        hkVector4CD4B kCol = kB.getColumn(i);
        getColumn(i)._setRotatedDir(kATrans, kCol);
    }
}

struct S_V4
{
    __m128 q;
};
struct S_00cd4c70
{
    S_V4 r0, r1, r2;
    const S_V4& Multiply(const S_V4& s);
};
// Multiplies each of r0, r1, r2 by the x component of s and returns s.
// @fnv 0x00cd4c70
const S_V4& S_00cd4c70::Multiply(const S_V4& apFactor)
{
    r0.q = _mm_mul_ps(_mm_shuffle_ps(apFactor.q, apFactor.q, 0), r0.q);
    r1.q = _mm_mul_ps(_mm_shuffle_ps(apFactor.q, apFactor.q, 0), r1.q);
    r2.q = _mm_mul_ps(_mm_shuffle_ps(apFactor.q, apFactor.q, 0), r2.q);
    return apFactor;
}

#include <math.h>
struct JacobiRot
{
    float c;
    float s;
    int q;
    int p;
};

struct RotRef
{
    JacobiRot* p;
    JacobiRot* operator->() const
    {
        return p;
    }
};
struct Mat34
{
    float m[3][4];
};

// Computes the c, s, p, q of a Jacobi rotation that zeroes a.m[p][q] of a 3x4 matrix, storing the result in outp.
// @fnv 0x00cd5270
static __declspec(noinline) void FUN_00cd5270(const Mat34& apMatrix, int q, int p, JacobiRot* apOut)
{
    JacobiRot* out = apOut;
    JacobiRot** ppOut = &apOut;
    out->q = q;
    out->p = p;
    if (apMatrix.m[p][q] != 0.0f)
    {
        float theta = (apMatrix.m[p][p] - apMatrix.m[q][q]) / (2.0f * apMatrix.m[p][q]);
        float r = sqrtf(theta * theta + 1.0f);
        r = 1.0f / (theta >= 0.0f ? theta + r : theta - r);
        float c = 1.0f / sqrtf(r * r + 1.0f);
        out->c = c;
        out->s = c * r;
    }
    else
    {
        out->c = 1.0f;
        out->s = 0.0f;
    }
}

volatile int g_p5270;
volatile int g_q5270;
Mat34 g_m5270;
JacobiRot g_r5270;
void caller_cd5270()
{
    FUN_00cd5270(g_m5270, g_q5270, g_p5270, &g_r5270);
}

struct Mat
{
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
};

// Computes the Euclidean norm of the 3x3 block formed by the first three entries of each row.
// @fnv 0x00cd5340
static __declspec(noinline) float FUN_00cd5340(const Mat* apMatrix)
{
    float sum = 0.0f;
    const float* q = &apMatrix->f00 + 8;
    for (int i = 3; i != 0; --i)
    {
        sum = q[-8] * q[-8] + sum;
        sum = q[-4] * q[-4] + sum;
        sum = q[0] * q[0] + sum;
        q += 1;
    }
    return sqrtf(sum);
}

float MatNorm(const Mat* m)
{
    return FUN_00cd5340(m) * 2.0f;
}

struct S_00cd53a0_Matrix3
{
    float m_col[3][4];
    float FUN_00cd53a0();
};

// Computes the Frobenius norm of the 3x3 matrix by summing the squares of the off-diagonal elements and returning the square root.
// @fnv 0x00cd53a0
float S_00cd53a0_Matrix3::FUN_00cd53a0()
{
    float sum = 0.0f;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i != j)
            {
                sum += m_col[j][i] * m_col[j][i];
            }
        }
    }
    return sqrtf(sum);
}

namespace cd5400 {
struct Vec4
{
    float x, y, z, w;
};
struct Mat3
{
    Vec4 col[3];
    float& operator()(int r, int c)
    {
        return (&col[c].x)[r];
    }
};
}

// Finds the element with the largest absolute value in the upper triangle of m and stores its row and column indices.
// @fnv 0x00cd5400
static void FUN_00cd5400(cd5400::Mat3& m, int& rowOut, int& colOut)
{
    float maxVal = 0.0f;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i < j)
            {
                float v = fabsf(m(i, j));
                if (v >= maxVal)
                {
                    rowOut = i;
                    maxVal = v;
                    colOut = j;
                }
            }
        }
    }
}

void cd5400_caller(cd5400::Mat3& m, int* r, int* c)
{
    FUN_00cd5400(m, *r, *c);
}

struct VProduct
{
    __m128 q;
    VProduct()
    {}
    VProduct(const VProduct& a) : q(a.q)
    {}
    void operator=(const VProduct& a)
    {
        q = a.q;
    }
    void product(const VProduct& a, const VProduct& b)
    {
        q = _mm_mul_ps(a.q, b.q);
    }
    void accum(const VProduct& a, const VProduct& b)
    {
        q = _mm_add_ps(q, _mm_mul_ps(a.q, b.q));
    }
    template <int lane> void broadcast(const VProduct& a)
    {
        q = _mm_shuffle_ps(a.q, a.q, lane);
    }
};
struct MProduct
{
    VProduct columns[3];
    void FUN_00cd55b0(const MProduct& a, const MProduct& b);
};
// Computes the matrix product of a and b, storing the result in columns.
// @fnv 0x00cd55b0
void MProduct::FUN_00cd55b0(const MProduct& aLeft, const MProduct& aRight)
{
    MProduct m = aLeft;
    for (int i = 2; i >= 0; --i)
    {
        const VProduct& v = aRight.columns[i];
        VProduct x, y, z;
        x.broadcast<0>(v);
        y.broadcast<85>(v);
        z.broadcast<170>(v);
        VProduct r;
        r.product(x, m.columns[0]);
        r.accum(y, m.columns[1]);
        r.accum(z, m.columns[2]);
        columns[i] = r;
    }
}

extern "C" __m128 _mm_setzero_ps(void);
extern "C" void _mm_store_ps(float* p, __m128 a);

struct SrcRec
{
    float unk00;
    float unk04;
    int unk08;
    int unk0C;
};

struct Matrix34
{
    float m[12];
};

// Initializes a 3x4 matrix to identity, then replaces four elements using fields and indices from src.
// @fnv 0x00cd54d0
static __declspec(noinline) void FUN_00cd54d0(Matrix34* apMatrix, const SrcRec* src)
{
    _mm_store_ps(&apMatrix->m[0], _mm_setzero_ps());
    _mm_store_ps(&apMatrix->m[4], _mm_setzero_ps());
    _mm_store_ps(&apMatrix->m[8], _mm_setzero_ps());

    apMatrix->m[0] = 1.0f;
    apMatrix->m[5] = 1.0f;
    apMatrix->m[10] = 1.0f;

    apMatrix->m[src->unk08 * 5] = src->unk00;
    apMatrix->m[src->unk0C * 4 + src->unk08] = src->unk04;
    apMatrix->m[src->unk0C + src->unk08 * 4] = -src->unk04;
    apMatrix->m[src->unk0C * 5] = src->unk00;
}

void S00cd54d0_wrap(const SrcRec* src, Matrix34* dest)
{
    FUN_00cd54d0(dest, src);
}

extern "C" __m128 _mm_setr_ps(float, float, float, float);

struct S00cd4cc0_V
{
    __m128 q;
    __forceinline void set(float a, float b, float c, float d = 0.0f)
    {
        q = _mm_setr_ps(a, b, c, d);
    }
};

struct S00cd4cc0_M
{
    S00cd4cc0_V c0;
    S00cd4cc0_V c1;
    S00cd4cc0_V c2;
    void FUN_00cd4cc0(const float* r);
};

// Builds the three column vectors of a cross-product matrix from the components of the input vector r.
// @fnv 0x00cd4cc0
void S00cd4cc0_M::FUN_00cd4cc0(const float* apVec)
{
    c0.set(0.0f, apVec[2], -apVec[1]);
    c1.set(-apVec[2], 0.0f, apVec[0]);
    c2.set(apVec[1], -apVec[0], 0.0f);
}

extern "C" double __cdecl fabs(double);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" void _mm_store_ss(float* p, __m128 a);
extern "C" __m128 _mm_div_ss(__m128 a, __m128 b);

extern float DAT_01012068;

typedef __m128 VectorComponentValue;

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void setCross(const hkVector4& v0, const hkVector4& v1)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }

    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }

    __forceinline void setMul4(VectorComponentValue r, const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v.m_vComponents);
    }

    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
};

struct hkMatrix3
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;

    __forceinline hkVector4& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    __forceinline const hkVector4& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }

    float& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }

    void transpose()
    {
        float h1 = (*this)(0, 1);
        (*this)(0, 1) = (*this)(1, 0);
        (*this)(1, 0) = h1;
        float h2 = (*this)(0, 2);
        (*this)(0, 2) = (*this)(2, 0);
        (*this)(2, 0) = h2;
        float h3 = (*this)(1, 2);
        (*this)(1, 2) = (*this)(2, 1);
        (*this)(2, 1) = h3;
    }

    int FUN_00cd4f10(float epsilon);
};

// Computes the inverse of the matrix via cofactor columns and transpose, returning 0 on success or 1 if the determinant is near zero.
// @fnv 0x00cd4f10
int hkMatrix3::FUN_00cd4f10(float epsilon)
{
    hkVector4 r0;
    r0.setCross(getColumn(1), getColumn(2));
    hkVector4 r1;
    r1.setCross(getColumn(2), getColumn(0));
    hkVector4 r2;
    r2.setCross(getColumn(0), getColumn(1));

    VectorComponentValue det = getColumn(0).dot3(r0);
    float d;
    _mm_store_ss(&d, det);

    if ((float)fabs(d) > epsilon * epsilon * epsilon)
    {
        VectorComponentValue dinv = _mm_div_ss(_mm_load_ss(&DAT_01012068), det);
        getColumn(0).setMul4(dinv, r0);
        getColumn(1).setMul4(dinv, r1);
        getColumn(2).setMul4(dinv, r2);
        transpose();
        return 0;
    }
    return 1;
}

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" void _mm_store_ss(float* p, __m128 a);

extern double DAT_010cb418;
extern float DAT_010cb414;

struct InvScale
{
    __m128 q;
    InvScale(float f)
    {
        q = _mm_load_ss(&f);
        q = _mm_shuffle_ps(q, q, 0);
    }
    __m128 get() const
    {
        return q;
    }
};
struct hkVecInv
{
    __m128 m_vComponents;
    void setCross(const hkVecInv& v1, const hkVecInv& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    void scale(const InvScale& s, const hkVecInv& a)
    {
        m_vComponents = _mm_mul_ps(s.get(), a.m_vComponents);
    }
    float dot3(const hkVecInv& a) const
    {
        __m128 x = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(x, x, 0xaa), _mm_add_ss(_mm_shuffle_ps(x, x, 0x55), x));
        float r;
        _mm_store_ss(&r, s);
        return r;
    }
};

struct hkMatInv
{
    hkVecInv m_kColumn0;
    hkVecInv m_kColumn1;
    hkVecInv m_kColumn2;
    hkVecInv& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
};

// Computes three column cross products, substitutes a value when the determinant is below a threshold, then scales the columns by its reciprocal.
// @fnv 0x00cd5050
void S_00cd55a0::FUN_00cd5050()
{
    hkMatInv* m = (hkMatInv*)this;
    hkVecInv r0;
    r0.setCross(m->getColumn(1), m->getColumn(2));
    hkVecInv r1;
    r1.setCross(m->getColumn(2), m->getColumn(0));
    hkVecInv r2;
    r2.setCross(m->getColumn(0), m->getColumn(1));
    float det = m->getColumn(0).dot3(r0);
    if (det < DAT_010cb418)
        det = DAT_010cb414;
    float fInvDet = 1.0f / det;
    InvScale d(fInvDet);
    m->getColumn(0).scale(d, r0);
    m->getColumn(1).scale(d, r1);
    m->getColumn(2).scale(d, r2);
}

struct FUN_00cd5180_cls
{
    __declspec(align(16)) float m_v[12];

    const __m128* Subtract(const __m128* p);
};

// Subtracts the three __m128 values at p from the corresponding values in m_v, then returns p.
// @fnv 0x00cd5180
const __m128* FUN_00cd5180_cls::Subtract(const __m128* apVector)
{
    const __m128* b = apVector;
    __m128* a = (__m128*)m_v;
    a[0] = _mm_sub_ps(a[0], b[0]);
    a[1] = _mm_sub_ps(a[1], b[1]);
    a[2] = _mm_sub_ps(a[2], b[2]);
    return apVector;
}

extern "C" __m128 _mm_setr_ps(float, float, float, float);
struct DiagVec
{
    union
    {
        __m128 q;
        float f[4];
    };
    DiagVec()
    {}
    DiagVec(const DiagVec& v)
    {
        q = v.q;
    }
    void operator=(const DiagVec& v)
    {
        q = v.q;
    }
};
class DiagMat
{
  public:
    DiagVec c0, c1, c2;
    DiagMat()
    {}
    DiagMat(const DiagMat& v)
    {
        c0 = v.c0;
        c1 = v.c1;
        c2 = v.c2;
    }
    int FUN_00cd56c0(DiagMat& vectors, DiagVec& values, int maxIter, float epsilon) const;
    void FUN_00cd5680(const DiagMat& other);
    void FUN_00cd55b0(const DiagMat& a, const DiagMat& b);
    void FUN_00cd4b60();
    float offnorm()
    {
        return ((S_00cd53a0_Matrix3*)this)->FUN_00cd53a0();
    }
    float& at(int row, int col)
    {
        return (&c0)[col].f[row];
    }
    void identity()
    {
        c0.q = _mm_setzero_ps();
        c1.q = _mm_setzero_ps();
        c2.q = _mm_setzero_ps();
        at(0, 0) = 1.0f;
        at(1, 1) = 1.0f;
        at(2, 2) = 1.0f;
    }
};
// Diagonalizes the matrix via Jacobi rotations, accumulating eigenvectors in vectors and eigenvalues in values, returning 1 on failure.
// @fnv 0x00cd56c0
int DiagMat::FUN_00cd56c0(DiagMat& apEigenvectors, DiagVec& apEigenvalues, int aiMaxIterations, float epsilon) const
{
    if (!((CMatrixOps*)this)->FUN_00cd4e90(epsilon))
        return 1;
    DiagMat current(*this);
    apEigenvectors.identity();
    float tolerance = FUN_00cd5340((const Mat*)this) * epsilon;
    int iteration = 0;
    float norm = current.offnorm();
    while (!(norm < tolerance) && iteration < aiMaxIterations)
    {
        int p = 0, q = 0;
        FUN_00cd5400((cd5400::Mat3&)current, p, q);
        JacobiRot rotation;
        FUN_00cd5270((const Mat34&)current, p, q, &rotation);
        DiagMat jacobi;
        FUN_00cd54d0((Matrix34*)&jacobi, (const SrcRec*)&rotation);
        DiagMat transposed(jacobi);
        transposed.FUN_00cd4b60();
        current.FUN_00cd5680(jacobi);
        current.FUN_00cd55b0(transposed, current);
        apEigenvectors.FUN_00cd5680(jacobi);
        ++iteration;
        norm = current.offnorm();
    }
    apEigenvalues.q = _mm_setr_ps(current.c0.f[0], current.c1.f[1], current.c2.f[2], 0.0f);
    if (norm > tolerance)
        return 1;
    return 0;
}

extern const float DAT_01011d78;

class FUN_00cd51c0_cls
{
  public:
    float m_00;
    float unk04;
    float unk08;
    float unk0C;
    float m_10;
    float unk14;
    float unk18;
    float unk1C;
    float m_20;
    float unk24;
    float unk28;
    float unk2C;

    __m128 FUN_00cd51c0();
};

// @fnv 0x00cd51c0
__m128 FUN_00cd51c0_cls::FUN_00cd51c0()
{
    __m128 a = _mm_setr_ps(unk04, unk14, unk24, DAT_01011d78);
    __m128 b = _mm_setr_ps(unk08, unk18, unk28, DAT_01011d78);
    __m128 v = _mm_setr_ps(m_00, m_10, m_20, DAT_01011d78);

    __m128 a4 = _mm_shuffle_ps(a, a, 0xD2);
    __m128 b3 = _mm_shuffle_ps(b, b, 0xC9);
    __m128 vProduct1 = _mm_mul_ps(b3, a4);
    __m128 aS = _mm_shuffle_ps(a, a, 0xC9);
    __m128 b2 = _mm_shuffle_ps(b, b, 0xD2);
    __m128 vProduct2 = _mm_mul_ps(b2, aS);
    __m128 c = _mm_sub_ps(vProduct2, vProduct1);
    __m128 d = _mm_mul_ps(c, v);

    __m128 t = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
    return _mm_add_ss(_mm_shuffle_ps(d, d, 0xAA), t);
}

extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_cmple_ps(__m128, __m128);
extern "C" int _mm_movemask_ps(__m128);
extern "C" __declspec(align(16)) const __m128 g_signClear;

// Compares each column of m_mat against other within epsilon and stores the result as a byte in out.
// @fnv 0x00cd4e00
unsigned char* CMatrixOps::FUN_00cd4e00(unsigned char* apResult, const Matrix3x4* other, float epsilon)
{
    const hkMatrix3& lhs = *reinterpret_cast<const hkMatrix3*>(&m_mat);
    const hkMatrix3& rhs = *reinterpret_cast<const hkMatrix3*>(other);
    const __m128 scalar = _mm_load_ss(&epsilon);
    const __m128 limit = _mm_shuffle_ps(scalar, scalar, 0);
    bool ok =
        ((_mm_movemask_ps(_mm_cmple_ps(
              _mm_and_ps(_mm_sub_ps(lhs.m_kColumn0.m_vComponents, rhs.m_kColumn0.m_vComponents), g_signClear), limit)) &
          7) == 7) &&
        ((_mm_movemask_ps(_mm_cmple_ps(
              _mm_and_ps(_mm_sub_ps(lhs.m_kColumn1.m_vComponents, rhs.m_kColumn1.m_vComponents), g_signClear), limit)) &
          7) == 7) &&
        ((_mm_movemask_ps(_mm_cmple_ps(
              _mm_and_ps(_mm_sub_ps(lhs.m_kColumn2.m_vComponents, rhs.m_kColumn2.m_vComponents), g_signClear), limit)) &
          7) == 7);
    *static_cast<volatile unsigned char*>(apResult) = ok;
    return apResult;
}

struct TransposeReceiver : CD4BA0Matrix3
{
    void Transpose(const CD4BA0Matrix3& source);
};
__declspec(noinline) void TransposeReceiver::Transpose(const CD4BA0Matrix3& source)
{
    m_kColumn0[0] = source.m_kColumn0[0];
    m_kColumn1[1] = source.m_kColumn1[1];
    m_kColumn2[2] = source.m_kColumn2[2];
    m_kColumn0[3] = 0.0f;
    m_kColumn1[3] = 0.0f;
    m_kColumn2[3] = 0.0f;
    m_kColumn0[1] = source.m_kColumn1[0];
    m_kColumn1[0] = source.m_kColumn0[1];
    m_kColumn0[2] = source.m_kColumn2[0];
    m_kColumn2[0] = source.m_kColumn0[2];
    m_kColumn1[2] = source.m_kColumn2[1];
    m_kColumn2[1] = source.m_kColumn1[2];
}
struct MatrixProduct
{
    hkVector4CD4B m_kColumn0, m_kColumn1, m_kColumn2;
    hkVector4CD4B& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    void FUN_00cd5610(const hkMatrix3CD4B& a, const CD4BA0Matrix3& b);
};
// Multiplies a by the transpose of b and stores the result in this object's columns.
// @fnv 0x00cd5610
void MatrixProduct::FUN_00cd5610(const hkMatrix3CD4B& apLeft, const CD4BA0Matrix3& apRight)
{
    hkMatrix3CD4B t;
    reinterpret_cast<TransposeReceiver&>(t).Transpose(apRight);
    hkMatrix3CD4B aaLeft = apLeft;
    for (int i = 2; i >= 0; i--)
    {
        const hkVector4CD4B& src = t.getColumn(i);
        __m128 vSrc = src.m_vComponents;
        __m128 b0 = _mm_shuffle_ps(src.m_vComponents, src.m_vComponents, 0x00);
        __m128 r0 = _mm_mul_ps(aaLeft.m_kColumn0.m_vComponents, b0);
        __m128 b1 = _mm_shuffle_ps(vSrc, vSrc, 0x55);
        __m128 r1 = _mm_mul_ps(aaLeft.m_kColumn1.m_vComponents, b1);
        __m128 b2 = _mm_shuffle_ps(src.m_vComponents, src.m_vComponents, 0xaa);
        __m128 r2 = _mm_mul_ps(aaLeft.m_kColumn2.m_vComponents, b2);
        getColumn(i).m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
    }
}

extern "C" __m128 _mm_load_ps(float const* p);

struct FUN_00cd55b0_cls
{
    void FUN_00cd55b0(const void* src, int arg);
};

struct FUN_00cd5680_cls
{
    __m128 m_v0;
    __m128 m_v1;
    __m128 m_v2;

    void FUN_00cd5680(int arg);
};

struct __declspec(align(16)) FUN_00cd5680_tmp
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
};

// Loads three 16-byte blocks from a temporary populated by FUN_00cd55b0 into m_v0, m_v1, and m_v2.
// @fnv 0x00cd5680
void FUN_00cd5680_cls::FUN_00cd5680(int arg)
{
    FUN_00cd5680_tmp tmp;
    ((FUN_00cd55b0_cls*)&tmp)->FUN_00cd55b0(this, arg);
    this->m_v0 = _mm_load_ps((float*)&tmp.unk00);
    this->m_v1 = _mm_load_ps((float*)&tmp.unk10);
    this->m_v2 = _mm_load_ps((float*)&tmp.unk20);
}

extern "C" __m128 _mm_load_ps(const float* p);

struct MatrixAddReceiver : hkMatrix3
{
    const __m128* FUN_00cd5140(const __m128* rhs);
};

// Adds the three column vectors of rhs to the corresponding columns of this hkMatrix3 and returns rhs.
// @fnv 0x00cd5140
const __m128* MatrixAddReceiver::FUN_00cd5140(const __m128* apOther)
{
    _mm_store_ps((float*)&m_kColumn0.m_vComponents, _mm_add_ps(_mm_load_ps((const float*)apOther + 0),
                                                               _mm_load_ps((const float*)&m_kColumn0.m_vComponents)));
    _mm_store_ps((float*)&m_kColumn1.m_vComponents, _mm_add_ps(_mm_load_ps((const float*)apOther + 4),
                                                               _mm_load_ps((const float*)&m_kColumn1.m_vComponents)));
    m_kColumn2.m_vComponents =
        _mm_add_ps(_mm_load_ps((const float*)apOther + 8), _mm_load_ps((const float*)&m_kColumn2.m_vComponents));
    return apOther;
}

extern "C" __m128 _mm_load_ps(const float* p);

// out[i] = m * in[i] for the three columns of a 3x4 SSE matrix (columns processed last to first).
// @fnv 0x00cd5530
void __cdecl FUN_00cd5530(float* out, const float* apMatrix, const float* in)
{
    __m128 r0 = _mm_load_ps(apMatrix);
    __m128 r1 = _mm_load_ps(apMatrix + 4);
    __m128 r2 = _mm_load_ps(apMatrix + 8);
    int i = 2;
    for (; i >= 0; --i)
    {
        const float* col = in + i * 4;
        __m128 v = _mm_load_ps(col);
        __m128 x = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(col), _mm_load_ps(col), 0), r0);
        __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 85), r1);
        __m128 result = _mm_add_ps(x, y);
        result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(v, v, 170), r2));
        _mm_store_ps(out + i * 4, result);
    }
}

extern const float DAT_0104da4c = 1.1920929e-7f;
extern "C" void FUN_00cd5530(void*, const void*, const void*);
extern "C" void FUN_00cd55a0(void*);

class ChainScalar
{
    __m128 value;

  public:
    ChainScalar(const __m128& v) : value(v)
    {}
    operator float() const
    {
        float result;
        _mm_store_ss(&result, value);
        return result;
    }
};
class ChainVec
{
    union
    {
        __m128 value;
        float lanes[4];
    };

  public:
    ChainVec()
    {}
    ChainVec(const __m128& q)
    {
        value = q;
    }
    void operator=(const __m128& q)
    {
        value = q;
    }
    void copy(const ChainVec& q)
    {
        value = q.value;
    }
    void set(const __m128& q)
    {
        value = q;
    }
    ChainVec(const ChainVec& v)
    {
        value = v.value;
    }
    void operator=(const ChainVec& v)
    {
        value = v.value;
    }
    operator __m128() const
    {
        return value;
    }
    float& operator()(int i)
    {
        return lanes[i];
    }
    const float& operator()(int i) const
    {
        return lanes[i];
    }
    __forceinline void zero()
    {
        value = _mm_setzero_ps();
    }
    __forceinline void product(const ChainVec& a, const ChainVec& b)
    {
        value = _mm_mul_ps((__m128)a, (__m128)b);
    }
    __forceinline void mul(const ChainVec& a)
    {
        value = _mm_mul_ps(value, a.value);
    }
    __forceinline void add(const ChainVec& a)
    {
        value = _mm_add_ps(value, a.value);
    }
    __forceinline void sub(const ChainVec& a)
    {
        value = _mm_sub_ps(value, a.value);
    }
    __forceinline void splat(const ChainVec& a, int lane)
    {
        value = _mm_shuffle_ps((__m128)a, (__m128)a, 255);
    }
    __forceinline ChainScalar sum() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(value, value, 85), value);
        return _mm_add_ss(_mm_shuffle_ps(value, value, 170), xy);
    }
};
class ChainMat
{
  public:
    ChainVec c0, c1, c2;
    ChainMat()
    {}
    ChainMat(const ChainMat& a)
    {
        c0 = a.c0;
        c1 = a.c1;
        c2 = a.c2;
    }
    void operator=(const ChainMat& a)
    {
        c0 = a.col(0);
        c1 = a.col(1);
        c2 = a.col(2);
    }
    ChainVec& col(int i)
    {
        return (&c0)[i];
    }
    const ChainVec& col(int i) const
    {
        return (&c0)[i];
    }
    float& operator()(int r, int c)
    {
        return col(c)(r);
    }
    const float& operator()(int r, int c) const
    {
        return col(c)(r);
    }
    void zeroCached()
    {
        ChainVec v;
        v.zero();
        ChainVec& copy = v;
        c0 = copy;
        c1 = copy;
        c2 = copy;
    }
    void zero()
    {
        c0.zero();
        c1.zero();
        c2.zero();
    }
    void transpose(const ChainMat& a)
    {
        (*this)(0, 0) = a(0, 0);
        (*this)(1, 1) = a(1, 1);
        (*this)(2, 2) = a(2, 2);
        (*this)(3, 0) = 0.0f;
        (*this)(3, 1) = 0.0f;
        (*this)(3, 2) = 0.0f;
        (*this)(1, 0) = a(0, 1);
        (*this)(0, 1) = a(1, 0);
        (*this)(2, 0) = a(0, 2);
        (*this)(0, 2) = a(2, 0);
        (*this)(2, 1) = a(1, 2);
        (*this)(1, 2) = a(2, 1);
    }
    void product(const ChainMat& a, const ChainMat& b)
    {
        FUN_00cd5530(static_cast<void*>(this), static_cast<const void*>(&a), static_cast<const void*>(&b));
    }
    void sub(const ChainMat& a)
    {
        c0.sub(a.c0);
        c1.sub(a.c1);
        c2.sub(a.c2);
    }
};
struct ChainBody
{
    unsigned type;
    unsigned deactivation;
    float gravity;
    ChainVec linearVelocity, angularVelocity, mass;
};
static inline float chainMaximum(float a, float b)
{
    return a > b ? a : b;
}

struct ProbeJac
{
    ChainVec linear;
    ChainVec angular0;
    ChainVec angular1;
    __forceinline float paired(const ChainBody& a, const ChainBody& b, const ProbeJac& q) const;
    __forceinline float pairedCore(const ChainBody& a, const ChainBody& b, const ProbeJac& q) const;
    __forceinline float shared(const ChainBody& a, const ProbeJac& q) const;
};

float ProbeJac::paired(const ChainBody& a, const ChainBody& b, const ProbeJac& q) const
{
    return pairedCore(a, b, q);
}
float ProbeJac::pairedCore(const ChainBody& a, const ChainBody& b, const ProbeJac& q) const
{
    const ProbeJac& p = *this;
    ChainVec lin;
    lin.product(p.linear, q.linear);
    ChainVec ang0;
    ang0.product(p.angular0, q.angular0);
    ChainVec ang1;
    ang1.product(p.angular1, q.angular1);
    ChainVec ma;
    ma.splat(a.mass, 3);
    ChainVec mb;
    mb.splat(b.mass, 3);
    ChainVec la;
    la.product(ma, lin);
    ChainVec lb;
    lb.product(mb, lin);
    ang0.mul(a.mass);
    ang1.mul(b.mass);
    la.add(lb);
    ang0.add(ang1);
    ang0.add(la);
    float result = ang0.sum();
    return result;
}

float ProbeJac::shared(const ChainBody& a, const ProbeJac& q) const
{
    const ProbeJac& p = *this;
    ChainVec lin;
    lin.product(p.linear, q.linear);
    ChainVec angular;
    angular.product(p.angular1, q.angular0);
    ChainVec mass;
    mass.splat(a.mass, 3);
    ChainVec weighted;
    weighted.product(mass, lin);
    angular.mul(a.mass);
    angular.sub(weighted);
    float result = angular.sum();
    return result;
}

template <class T> __forceinline const T* offsetValue(const T* p, unsigned n)
{
    return reinterpret_cast<const T*>(reinterpret_cast<const char*>(p) + n);
}
struct ProbeOffset
{
    unsigned offset;
    const ChainBody& body(const ChainBody* p)
    {
        return *offsetValue(p, offset);
    }
};
struct ProbeRow
{
    ChainMat lower, diag, upper;
};
// Fills ProbeRow output with lower, diag, and upper matrices by computing paired and shared Jacobian terms over ChainBody offsets.
// @fnv 0x00dd0660
static __declspec(noinline) void FUN_00dd0660(int aiRowCount, float regularizer, ProbeJac* apJacobian,
                                              ProbeOffset* offsets, const ChainBody* bodies, ProbeRow* output,
                                              int bufferSize)
{
    ChainMat matPrevious;
    matPrevious.zeroCached();
    ChainMat upper;
    upper.zeroCached();
    for (int row = 0; row < aiRowCount; ++row)
    {
        int stride = 3;
        int start = row * stride;
        ChainMat diag;
        for (int r = 0; r < 3; ++r)
        {
            for (int c = r; c < 3; ++c)
            {
                diag(c, r) = diag(r, c) = apJacobian[start + r].paired(
                    offsets[row].body(bodies), offsets[row + 1].body(bodies), apJacobian[start + c]);
            }
            float& d = diag(r, r);
            d += regularizer;
        }
        ChainMat matNext;
        matNext.zeroCached();
        if (row < aiRowCount - 1)
        {
            for (int r = 0; r < 3; ++r)
            {
                for (int c = 0; c < 3; ++c)
                {
                    matNext(r, c) =
                        apJacobian[start + r].shared(offsets[row + 1].body(bodies), apJacobian[start + stride + c]);
                }
            }
        }
        else
        {
            matNext.col(0).zero();
            matNext.col(1).zero();
            matNext.col(2).zero();
        }
        output[row].lower.transpose(matPrevious);
        ChainMat product;
        product.product(output[row].lower, upper);
        output[row].diag = diag;
        output[row].diag.sub(product);
        for (int i = 0; i < 3; ++i)
        {
            float& value = output[row].diag(i, i);
            value = chainMaximum(value, 1.1920929e-7f);
        }
        FUN_00cd55a0(reinterpret_cast<void*>(&output[row].diag));
        output[row].upper.product(output[row].diag, matNext);
        matPrevious = matNext;
        upper = output[row].upper;
    }
}
volatile int probe_count;
volatile float probe_cfm;
ProbeJac* volatile probe_jac;
ProbeOffset* volatile probe_offsets;
const ChainBody* volatile probe_bodies;
ProbeRow* volatile probe_rows;
void native_entry()
{
    FUN_00dd0660(probe_count, probe_cfm, probe_jac, probe_offsets, probe_bodies, probe_rows, 0);
}
