
// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
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
struct Entry
{
    hkVector4 m_iThirdValue;
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
    int m_flag;
};
struct Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_num;
    int m_iThirdValue;
    int m_auiShapeKeys[4];
    Entry m_usTrailingValue[4];
    void FUN_00e2d440();
    void SetEntries(const hkVector4* a, const hkVector4* b, const hkVector4* c);
};
struct FUN_00df9c40_Obj
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
    __m128* unk60;
    __m128* unk64;
    __m128* unk68;
    int unk6C;

    void PushVectorTriple(const __m128* src);
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" void _mm_store_ps(float* p, __m128 a);

extern const __m128 DAT_010c44d0;
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_unpacklo_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movelh_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movehl_ps(__m128 a, __m128 b);

class hkMatrix3DF9B;

struct hkVector4DF9B
{
    __m128 m_vComponents;

    hkVector4DF9B()
    {}
    hkVector4DF9B(const hkVector4DF9B& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4DF9B& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void _setRotatedDir(const hkMatrix3DF9B& r, const hkVector4DF9B& b);
    __forceinline void _setRotatedInverseDir(const hkMatrix3DF9B& r, const hkVector4DF9B& b);
    void setSub4(const hkVector4DF9B& a, const hkVector4DF9B& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setNeg4(const hkVector4DF9B& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
    __forceinline void _setTransformedPos(const struct hkTransformDF9B& t, const hkVector4DF9B& b);
};

class hkMatrix3DF9B
{
  public:
    __forceinline void SetMulInverse(const hkMatrix3DF9B& kA, const hkMatrix3DF9B& kB)
    {
        hkMatrix3DF9B kATrans;
        kATrans.m_kColumn0 = kA.m_kColumn0;
        kATrans.m_kColumn1 = kA.m_kColumn1;
        kATrans.m_kColumn2 = kA.m_kColumn2;
        kATrans.transpose();
        for (int i = 0; i < 3; i++)
        {
            hkVector4DF9B kCol = kB.getColumn(i);
            getColumn(i)._setRotatedDir(kATrans, kCol);
        }
    }

    hkVector4DF9B& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    const hkVector4DF9B& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
    __forceinline void transpose()
    {
        __m128 tmp = _mm_unpacklo_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents);
        __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents),
                                     m_kColumn2.m_vComponents, 0xe4);
        m_kColumn0.m_vComponents = _mm_movelh_ps(tmp, m_kColumn2.m_vComponents);
        tmp = _mm_movehl_ps(m_kColumn0.m_vComponents, tmp);
        m_kColumn1.m_vComponents = _mm_shuffle_ps(tmp, m_kColumn2.m_vComponents, 0xd4);
        m_kColumn2.m_vComponents = ctmp;
    }

    hkVector4DF9B m_kColumn0;
    hkVector4DF9B m_kColumn1;
    hkVector4DF9B m_kColumn2;
};

__forceinline void hkVector4DF9B::_setRotatedDir(const hkMatrix3DF9B& r, const hkVector4DF9B& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(r.m_kColumn0.m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(r.m_kColumn1.m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(r.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

__forceinline void hkVector4DF9B::_setRotatedInverseDir(const hkMatrix3DF9B& r, const hkVector4DF9B& b)
{
    hkVector4DF9B kC0 = r.m_kColumn0;
    hkVector4DF9B kC1 = r.m_kColumn1;
    hkVector4DF9B kC2 = r.m_kColumn2;
    __m128 tmp = _mm_unpacklo_ps(kC0.m_vComponents, kC1.m_vComponents);
    const __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(kC0.m_vComponents, kC1.m_vComponents), kC2.m_vComponents, 0xe4);
    kC0.m_vComponents = _mm_movelh_ps(tmp, kC2.m_vComponents);
    tmp = _mm_movehl_ps(kC0.m_vComponents, tmp);
    kC1.m_vComponents = _mm_shuffle_ps(tmp, kC2.m_vComponents, 0xd4);
    kC2.m_vComponents = ctmp;
    const __m128 r0 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00), kC0.m_vComponents);
    const __m128 r1 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55), kC1.m_vComponents);
    const __m128 r2 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa), kC2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

struct hkTransformDF9B
{
    hkMatrix3DF9B m_rotation;
    hkVector4DF9B m_vTranslation;
};

__forceinline void hkVector4DF9B::_setTransformedPos(const hkTransformDF9B& t, const hkVector4DF9B& b)
{
    const __m128 r0 =
        _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00), t.m_rotation.m_kColumn0.m_vComponents);
    const __m128 r1 =
        _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55), t.m_rotation.m_kColumn1.m_vComponents);
    const __m128 r2 =
        _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa), t.m_rotation.m_kColumn2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.m_vTranslation.m_vComponents));
}

struct hkVector4StoreDF9B
{
    __declspec(align(16)) float m_v[4];

    void operator=(const hkVector4DF9B& v)
    {
        _mm_store_ps(m_v, v.m_vComponents);
    }
    operator const hkVector4DF9B&() const
    {
        return *reinterpret_cast<const hkVector4DF9B*>(m_v);
    }
};

struct hkpCdVertexPairDF9B
{
    hkVector4DF9B m_vContactPosition;
    hkVector4DF9B m_kVertexA;
    hkVector4DF9B m_kVertexB;
};

class hkpConvexShapeDF9B
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void GetSupportPoint(const hkVector4DF9B& kDirection, hkVector4DF9B& kSupportOut) const = 0;
};

class hkpMinkowskiDF9B
{
  public:
    void FUN_00df9b50(const hkVector4DF9B& kDirection, hkpCdVertexPairDF9B& kOut) const;

    hkTransformDF9B m_kTransform;
    unsigned int unk40, unk44, unk48, unk4C, unk50;
    const hkpConvexShapeDF9B* m_pShapeA;
    const hkpConvexShapeDF9B* m_pShapeB;
};

// @fnv 0x00df9b50
void hkpMinkowskiDF9B::FUN_00df9b50(const hkVector4DF9B& kDirection, hkpCdVertexPairDF9B& kOut) const
{
    m_pShapeA->GetSupportPoint(kDirection, kOut.m_kVertexA);
    hkVector4DF9B kNegDir;
    kNegDir.setNeg4(kDirection);
    hkVector4DF9B kRotated;
    kRotated._setRotatedInverseDir(m_kTransform.m_rotation, kNegDir);
    hkVector4StoreDF9B kLocalDir;
    kLocalDir = kRotated;
    m_pShapeB->GetSupportPoint(kLocalDir, kOut.m_kVertexB);
    hkVector4DF9B kBInA;
    kBInA._setTransformedPos(m_kTransform, kOut.m_kVertexB);
    kOut.m_vContactPosition.setSub4(kOut.m_kVertexA, kBInA);
}

extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);

struct __declspec(align(16)) S00df9ef0_Vec4
{
    float x;
    float y;
    float z;
    float w;
};

template <class T> struct S00df9ef0_Pad
{
    T* m_p;
    __forceinline T* val() const
    {
        return m_p;
    }
    __forceinline T* operator->() const
    {
        return m_p;
    }
};

struct S00df9ef0_Hit
{
    S00df9ef0_Vec4 a;
    S00df9ef0_Vec4 b;
    S00df9ef0_Vec4 c;
    int d;
};

struct S00df9ef0_Obj
{
    void FUN_00df9b50(const S00df9ef0_Vec4* in, S00df9ef0_Vec4* out);

    void FUN_00df9ef0(S00df9ef0_Vec4* p, S00df9ef0_Pad<S00df9ef0_Vec4> r, S00df9ef0_Hit* q, S00df9ef0_Pad<float> outF);
};

static float S00df9ef0_Dot3(__m128 v)
{
    __m128 s1 = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), s1);
    float f;
    _mm_store_ss(&f, s);
    return f;
}

// @fnv 0x00df9ef0
void S00df9ef0_Obj::FUN_00df9ef0(S00df9ef0_Vec4* p, S00df9ef0_Pad<S00df9ef0_Vec4> r, S00df9ef0_Hit* q,
                                 S00df9ef0_Pad<float> outF)
{
    S00df9ef0_Hit h;
    S00df9ef0_Vec4 neg;
    _mm_store_ps(&neg.x, _mm_xor_ps(_mm_load_ps(&p->x), DAT_010c44d0));
    this->FUN_00df9b50(p, &h.a);
    S00df9ef0_Hit* qq = q;
    this->FUN_00df9b50(&neg, &qq->a);

    float f1 = S00df9ef0_Dot3(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(&h.a.x), _mm_load_ps(&r->x)), _mm_load_ps(&p->x)));
    float f2 = S00df9ef0_Dot3(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(&qq->a.x), _mm_load_ps(&r->x)), _mm_load_ps(&neg.x)));

    if (f1 >= f2)
    {
        __m128 vb = _mm_load_ps(&h.b.x);
        _mm_store_ps(&qq->a.x, _mm_load_ps(&h.a.x));
        _mm_store_ps(&qq->b.x, vb);
        _mm_store_ps(&qq->c.x, _mm_load_ps(&h.c.x));
        qq->d = h.d;
        *outF.val() = f1;
    }
    else
    {
        *outF.val() = f2;
    }
}

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmplt_ps(__m128 a, __m128 b);
extern "C" int _mm_movemask_ps(__m128 a);

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

struct Tri
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    const Vec4* m_p0;
    int unk14;
    int unk18;
    int unk1C;
    const Vec4* m_p1;
    int unk24;
    int unk28;
    int unk2C;
    const Vec4* m_p2;
};

struct Edges
{
    Vec4 e0;
    Vec4 e1;
    Vec4 e2;
};

struct Result4 : Vec4
{
    __declspec(noalias) void FUN_004b4ab0(const Edges* edges, const Tri* tri);
};

struct Shape
{
    int unk00;
    int unk04;
    int unk08;
    int m_iThirdValue;
    int m_10;
    int FUN_00dfb040(const Tri* tri, const Vec4* pos, int* outA, int* outB);
    int FUN_00e2d1b0(int a, int b, const Vec4* pos);
};

struct Tester
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
    int unk34;
    int unk38;
    int unk3C;
    Vec4 m_40;
    int FUN_00df9c90(Shape* shape, const Tri* tri, const Vec4* pos, int* result);
};

// @fnv 0x00df9c90
int Tester::FUN_00df9c90(Shape* shape, const Tri* tri, const Vec4* pos, int* result)
{
    Edges edges;
    __m128 p = *(const __m128*)pos;
    *(__m128*)&edges.e0 = _mm_sub_ps(p, *(const __m128*)tri->m_p0);
    *(__m128*)&edges.e1 = _mm_sub_ps(p, *(const __m128*)tri->m_p1);
    *(__m128*)&edges.e2 = _mm_sub_ps(p, *(const __m128*)tri->m_p2);
    Result4 bary;
    bary.FUN_004b4ab0(&edges, tri);
    if (_mm_movemask_ps(_mm_cmplt_ps(*(__m128*)&bary, *(__m128*)&m_40)) & 7)
    {
        *result = 0;
        return 1;
    }
    int a = 0;
    int b;
    if (shape->FUN_00dfb040(tri, pos, &a, &b))
    {
        *result = 3;
        return 1;
    }
    if (shape->m_iThirdValue - shape->m_10 + 100 < a)
    {
        *result = 2;
        return 1;
    }
    if (shape->FUN_00e2d1b0(a, b, pos))
    {
        *result = 3;
        return 1;
    }
    return 0;
}
