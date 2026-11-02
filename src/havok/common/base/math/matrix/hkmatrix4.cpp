
// src/havok/common/base/math/matrix/hkmatrix4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00de8f30_Class
{
    float m_data[16];
    void TransposeTo(float* dst);
};

// @fnv 0x00de8f30
void FUN_00de8f30_Class::TransposeTo(float* afOut)
{
    afOut[0] = m_data[0];
    afOut[4] = m_data[1];
    afOut[8] = m_data[2];
    afOut[12] = m_data[3];
    afOut[1] = m_data[4];
    afOut[5] = m_data[5];
    afOut[9] = m_data[6];
    afOut[13] = m_data[7];
    afOut[2] = m_data[8];
    afOut[6] = m_data[9];
    afOut[10] = m_data[10];
    afOut[14] = m_data[11];
    afOut[3] = m_data[12];
    afOut[7] = m_data[13];
    afOut[11] = m_data[14];
    afOut[15] = m_data[15];
}

struct FUN_00de8f10_Class
{
    float m_data[16];
    void FUN_00de8f10();
};

// @fnv 0x00de8f10
void FUN_00de8f10_Class::FUN_00de8f10()
{
    m_data[11] = 0.0f;
    m_data[7] = 0.0f;
    m_data[3] = 0.0f;
    m_data[15] = 1.0f;
}

struct FUN_00de8fa0_Class
{
    float m_data[16];
    void FUN_00de8fa0(const float* src);
};

// Copies 16 floats from src into m_data in transposed order (row/column swap).
// @fnv 0x00de8fa0
void FUN_00de8fa0_Class::FUN_00de8fa0(const float* src)
{
    m_data[0] = src[0];
    m_data[1] = src[4];
    m_data[2] = src[8];
    m_data[3] = src[12];
    m_data[4] = src[1];
    m_data[5] = src[5];
    m_data[6] = src[9];
    m_data[7] = src[13];
    m_data[8] = src[2];
    m_data[9] = src[6];
    m_data[10] = src[10];
    m_data[11] = src[14];
    m_data[12] = src[3];
    m_data[13] = src[7];
    m_data[14] = src[11];
    m_data[15] = src[15];
}

struct FUN_00de9010_Class
{
    float m_data[16];
    void CopyTo(float* dst);
};

// Copies the 16 floats in m_data into the destination array.
// @fnv 0x00de9010
void FUN_00de9010_Class::CopyTo(float* afOut)
{
    *afOut = m_data[0];
    afOut[1] = m_data[1];
    afOut[2] = m_data[2];
    afOut[3] = m_data[3];
    afOut[4] = m_data[4];
    afOut[5] = m_data[5];
    afOut[6] = m_data[6];
    afOut[7] = m_data[7];
    afOut[8] = m_data[8];
    afOut[9] = m_data[9];
    afOut[10] = m_data[10];
    afOut[11] = m_data[11];
    afOut[12] = m_data[12];
    afOut[13] = m_data[13];
    afOut[14] = m_data[14];
    afOut[15] = m_data[15];
}

struct FUN_00de9080_Class
{
    float m_data[16];
    void CopyFromFloats(const float* src);
};
// Copies 16 floats from src into m_data.
// @fnv 0x00de9080
void FUN_00de9080_Class::CopyFromFloats(const float* apSource)
{
    m_data[0] = apSource[0];
    m_data[1] = apSource[1];
    m_data[2] = apSource[2];
    m_data[3] = apSource[3];
    m_data[4] = apSource[4];
    m_data[5] = apSource[5];
    m_data[6] = apSource[6];
    m_data[7] = apSource[7];
    m_data[8] = apSource[8];
    m_data[9] = apSource[9];
    m_data[10] = apSource[10];
    m_data[11] = apSource[11];
    m_data[12] = apSource[12];
    m_data[13] = apSource[13];
    m_data[14] = apSource[14];
    m_data[15] = apSource[15];
}

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    void operator=(const hkVector4& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
};

struct hkMatrix4
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_kColumn3;
    void FUN_00de8da0(const hkMatrix4& a, const hkMatrix4& b);
    void FUN_00de8e50(const hkMatrix4& b);
    void operator=(const hkMatrix4& o)
    {
        m_kColumn0 = o.m_kColumn0;
        m_kColumn1 = o.m_kColumn1;
        m_kColumn2 = o.m_kColumn2;
        m_kColumn3 = o.m_kColumn3;
    }
};

// @fnv 0x00de8e50
void hkMatrix4::FUN_00de8e50(const hkMatrix4& b)
{
    hkMatrix4 t;
    t.FUN_00de8da0(*this, b);
    *this = t;
}

struct FUN_00de90f0_Class
{
    __m128 rows[4];
    void FUN_00de90f0(const __m128* source);
};
// Copies four __m128 rows from source into rows, then forces the fourth component of each row to 0,0,0,1.
// @fnv 0x00de90f0
void FUN_00de90f0_Class::FUN_00de90f0(const __m128* source)
{
    rows[0] = source[0];
    rows[1] = source[1];
    rows[2] = source[2];
    rows[3] = source[3];
    volatile float* pfValues = (volatile float*)this;
    pfValues[3] = 0.0f;
    pfValues[7] = 0.0f;
    pfValues[11] = 0.0f;
    pfValues[15] = 1.0f;
}

struct CB20B0_Class
{
    void FUN_00cb20b0(void* src);
};
struct Matrix44_shell
{
    float m_data[16];
    void FUN_00de9130(CB20B0_Class* dst);
};
// @fnv 0x00de9130
void Matrix44_shell::FUN_00de9130(CB20B0_Class* dst)
{
    dst->FUN_00cb20b0(this);
}

struct Owner
{
    __m128 row00;
    __m128 row10;
    __m128 row20;
    __m128 row30;
    void FUN_00de8910(float value);
    void FUN_00de8c50(const __m128* source, float value);
};
// Copies four __m128 rows from source into row00..row30, then calls FUN_00de8910 with value.
// @fnv 0x00de8c50
void Owner::FUN_00de8c50(const __m128* apRows, float value)
{
    row00 = apRows[0];
    row10 = apRows[1];
    row20 = apRows[2];
    row30 = apRows[3];
    FUN_00de8910(value);
}

struct SourceBlockCDF
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};
struct TargetBlockCDF
{
    void FUN_00cd55b0(SourceBlockCDF* pkSource, int iArg);
};
struct FUN_00cdf230_cls
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    SourceBlockCDF m_kSource;
    TargetBlockCDF m_kRoomNode;
    void FUN_00cdf230(int iArg);
};
// @fnv 0x00cdf230
void FUN_00cdf230_cls::FUN_00cdf230(int iArg)
{
    m_kRoomNode.FUN_00cd55b0(&m_kSource, iArg);
}

extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);

struct Row
{
    __m128 v;
    void operator+=(const Row& o)
    {
        __m128 t = o.v;
        v = _mm_add_ps(t, v);
    }
};

struct MatR
{
    Row m_row0;
    Row m_row1;
    Row m_row2;
    Row m_row3;
    const MatR* Add(const MatR* other);
};

// Adds each of other's four rows into this matrix's matching rows and returns other.
// @fnv 0x00de8c90
const MatR* MatR::Add(const MatR* other)
{
    m_row0 += other->m_row0;
    m_row1 += other->m_row1;
    m_row2 += other->m_row2;
    m_row3 += other->m_row3;
    return other;
}

extern float DAT_0104da4c;

__declspec(align(16)) struct S00de9270_Vec
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};

struct S00de9270_Mat
{
    S00de9270_Vec m_r0;
    S00de9270_Vec m_r1;
    S00de9270_Vec m_r2;
    S00de9270_Vec m_r3;
};

struct FUN_00de8910_Class
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void FUN_00de8910(float s);
};

struct FUN_00de8da0_Class
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void FUN_00de8da0(void* dst, const float* src);
};

__declspec(noinline) void FUN_00de8910_Class::FUN_00de8910(float s)
{
    unk00 = s;
    unsigned u = (unsigned)(int)s;
    unk04 = (float)(int)(u / 10u);
}

struct S00de9270_cls
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void FUN_00de9270(void* dst, const S00de9270_Mat* src);
};

// Copies the matrix into a local, passes its first row to FUN_00de8910, then passes the local data to FUN_00de8da0 for writing to dst.
// @fnv 0x00de9270
void S00de9270_cls::FUN_00de9270(void* dst, const S00de9270_Mat* src)
{
    S00de9270_Mat matTmp;
    *(__m128*)&matTmp.m_r0 = *(const __m128*)&src->m_r0;
    *(__m128*)&matTmp.m_r1 = *(const __m128*)&src->m_r1;
    *(__m128*)&matTmp.m_r2 = *(const __m128*)&src->m_r2;
    *(__m128*)&matTmp.m_r3 = *(const __m128*)&src->m_r3;

    FUN_00de8910_Class* row = (FUN_00de8910_Class*)&matTmp.m_r0;
    row->FUN_00de8910(DAT_0104da4c);

    ((FUN_00de8da0_Class*)this)->FUN_00de8da0(dst, (const float*)&matTmp.m_r0);
}

extern "C" __m128 _mm_sub_ps(__m128, __m128);

struct MatrixSubtract : hkMatrix4
{
    const hkMatrix4* FUN_00de8ce0(const hkMatrix4* rhs);
};

// Subtracts the four columns of rhs from this matrix using SSE and returns rhs.
// @fnv 0x00de8ce0
const hkMatrix4* MatrixSubtract::FUN_00de8ce0(const hkMatrix4* rhs)
{
    *(__m128*)&m_kColumn0 = _mm_sub_ps(*(const __m128*)&m_kColumn0, *(const __m128*)&rhs->m_kColumn0);
    *(__m128*)&m_kColumn1 = _mm_sub_ps(*(const __m128*)&m_kColumn1, *(const __m128*)&rhs->m_kColumn1);
    *(__m128*)&m_kColumn2 = _mm_sub_ps(*(const __m128*)&m_kColumn2, *(const __m128*)&rhs->m_kColumn2);
    *(__m128*)&m_kColumn3 = _mm_sub_ps(*(const __m128*)&m_kColumn3, *(const __m128*)&rhs->m_kColumn3);
    return rhs;
}

extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

struct C
{
    __m128 m_00;
    __m128 m_10;
    __m128 m_20;
    __m128 m_30;
    const __m128* FUN_00de8d30(const __m128* s);
};

// @fnv 0x00de8d30
const __m128* C::FUN_00de8d30(const __m128* apVector)
{
    __m128 v = *apVector;
    m_00 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), m_00);
    v = *apVector;
    m_10 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), m_10);
    v = *apVector;
    m_20 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), m_20);
    v = *apVector;
    m_30 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), m_30);
    return apVector;
}

extern "C"
{
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    void _mm_store_ss(float*, __m128);
}

struct Matrix4Q
{
    hkVector4 row0;
    hkVector4 row1;
    hkVector4 row2;
    hkVector4 row3;

    Matrix4Q(const Matrix4Q& value)
    {
        *(__m128*)&row0 = *(const __m128*)&value.row0;
        *(__m128*)&row1 = *(const __m128*)&value.row1;
        *(__m128*)&row2 = *(const __m128*)&value.row2;
        *(__m128*)&row3 = *(const __m128*)&value.row3;
    }

    __declspec(noinline) void __fastcall SwapFields(hkMatrix4* context);
};

void __fastcall Matrix4Q::SwapFields(hkMatrix4* context)
{
    __m128* vectors = reinterpret_cast<__m128*>(this);
    __m128 low01 = _mm_unpacklo_ps(vectors[0], vectors[1]);
    __m128 high01 = _mm_unpackhi_ps(vectors[0], vectors[1]);
    __m128 low23 = _mm_unpacklo_ps(vectors[2], vectors[3]);
    __m128 high23 = _mm_unpackhi_ps(vectors[2], vectors[3]);
    vectors[0] = _mm_movelh_ps(low01, low23);
    vectors[1] = _mm_movehl_ps(low23, low01);
    vectors[2] = _mm_movelh_ps(high01, high23);
    vectors[3] = _mm_movehl_ps(high23, high01);
}

__forceinline float Dot4(const float* left, const float* right)
{
    __m128 first = *reinterpret_cast<const __m128*>(left);
    __m128 second = *reinterpret_cast<const __m128*>(right);
    __m128 product = _mm_mul_ps(first, second);
    __m128 halves = _mm_add_ps(_mm_shuffle_ps(product, product, 0x4e), product);
    __m128 sum = _mm_add_ps(_mm_shuffle_ps(halves, halves, 0xb1), halves);
    float scalar;
    _mm_store_ss(&scalar, sum);
    return scalar;
}

struct MatrixPointerQ
{
    const Matrix4Q* volatile value;
    MatrixPointerQ(const MatrixPointerQ& other);
};
struct Matrix4V
{
    void FUN_00de8da0(const Matrix4Q* left, MatrixPointerQ right);
};

// Stores the matrix product formed by dotting each row of right with each column of left.
// @fnv 0x00de8da0
void Matrix4V::FUN_00de8da0(const Matrix4Q* left, MatrixPointerQ right)
{
    Matrix4Q columns(*left);
    columns.SwapFields((hkMatrix4*)this);
    float* destination = reinterpret_cast<float*>(this);
    const float* input = reinterpret_cast<const float*>(right.value);
    for (int row = 0; row != 4; ++row)
    {
        for (int column = 0; column != 4; ++column)
        {
            destination[row * 4 + column] =
                Dot4(input + row * 4, reinterpret_cast<const float*>(&columns) + column * 4);
        }
    }
}

extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_set_ps1(float);
    __m128 _mm_cmple_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
}

extern float DAT_01011d78;
extern float DAT_01012068;
extern __m128 DAT_01017d10;

struct FUN_00de8ea0_cls
{
    float m_data[16];

    int FUN_00de8ea0();
};

// Compares four selected values with two constants, then returns whether the first three absolute differences are at most DAT_01011d78.
// @fnv 0x00de8ea0
int FUN_00de8ea0_cls::FUN_00de8ea0()
{
    __m128 column = _mm_setr_ps(m_data[3], m_data[7], m_data[11], m_data[15]);
    __m128 ref = _mm_setr_ps(DAT_01011d78, DAT_01011d78, DAT_01011d78, DAT_01012068);
    __m128 diff = _mm_sub_ps(column, ref);
    __m128 absDiff = _mm_and_ps(diff, DAT_01017d10);
    __m128 bound = _mm_set_ps1(DAT_01011d78);
    __m128 cmp = _mm_cmple_ps(absDiff, bound);
    int mask = _mm_movemask_ps(cmp) & 7;
    return mask == 7;
}
