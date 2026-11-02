
// src/havok/animation/animation/rig/hkaskeletonutils_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/rig/hkaskeletonutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/animation/rig/hkaskeletonutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/rig/hkaskeletonutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00cdd3f0_s
{
    int a[6];
    int* field_0x18;
    int field_0x1c;
};
void FUN_00cdd3f0(struct FUN_00cdd3f0_s* p);
extern "C" void __cdecl FUN_00cddad0(int, int, int*, int, int);
extern int DAT_01268700;
void __cdecl CallWithGlobal(int a, int b, int c, int d);
extern "C" void __cdecl FUN_00cddd20(void* a, void* b, void* c, void* d, void* e);
extern int DAT_01268700;
void FUN_00cddef0(void* a, void* b, void* c, void* d);
extern "C" void __cdecl Atan2(float, float);
void __cdecl FUN_00ce00f0(float a, float b);
int __cdecl CompareStringsCaseInsensitive(const void* pKey, const void* pItem);
struct S_00cdd390_Entry
{
    unsigned int m_uiTaggedItem;
    int unk04;
};
struct S_00cdd390_Table
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S_00cdd390_Entry* m_pEntries;
    int m_iArrayLength;
    int GetCount() const
    {
        return m_iArrayLength;
    }
    void* GetAt(int i) const
    {
        return (void*)(m_pEntries[i].m_uiTaggedItem & ~1u);
    }
};
short __cdecl FindIndexByKey(S_00cdd390_Table* pSearchEntries, const void* pKey,
                             int(__cdecl* pfnCompare)(const void*, const void*));
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
template <class T> struct Array
{
    T* data;
    int size;
    int capacity;
    __forceinline T& operator[](int index)
    {
        return data[index];
    }
};
struct Hierarchy
{
    int unk00;
    int unk04;
    int unk08;
    Array<short> parents;
    void* nodes;
    int count;
};
void __cdecl MarkHierarchyDescendants(Hierarchy* hierarchy, int root, unsigned char* flags, unsigned char finalValue);
struct Sequence
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    short* values;
    int count;
};
bool* __cdecl AreSequenceValuesInRange(bool* result, FUN_00cdd3f0_s* limits, Sequence* sequence);
struct Msg
{
    int f0, f4, f8;
    void Init(void* buf, int size);
    void Done();
    Msg& Add(const char* s);
    Msg& Add(const char* s, int v);
    Msg& Add();
    Msg& Fin();
};
struct Logger
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Report(int a, int code, void* msg, const char* file, int line);
};
extern Logger* DAT_01268360;
struct Names
{
    int pad[6];
    unsigned int* names;
    int count;
};
struct Track
{
    int pad[4];
    short* out;
    int cnt;
};
struct Src
{
    int pad[4];
    int n;
    int p14;
    int p18;
    unsigned int* arr;
    int f20;
};
struct Dst
{
    int pad[4];
    short* out;
    int cnt;
};
typedef int(__cdecl* CmpFn)(unsigned int, unsigned int);
int __cdecl MapTracksToBones(Names* names, Src* src, CmpFn cmp, Dst* dst);
struct HolderRec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_10;
};
struct ScanRec
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short* m_0c;
};
struct ScanObj
{
    void FUN_00cde940(int a, int b, void* c);
};
HolderRec* FUN_00c85750();
unsigned char* WalkChainUntilLimit(unsigned char* pOut, ScanRec* rec, short limit, short start, ScanObj* obj);

#include <xmmintrin.h>
// ---------------------------------------------------------------------------
// FUN_00cdd480 - batch interpolation of 0x30 byte records.
//
//   arg1  number of records to process (compared unsigned)
//   arg2  first  record array   (0x30 byte stride)
//   arg3  second record array   (0x30 byte stride)
//   arg4  array of blend factors (float, one per record)
//   arg5  output record array   (0x30 byte stride)
//
// For every record the blend factor is put into a 16 byte, 16 byte aligned
// vector whose first component carries the factor; that vector is handed to
// FUN_00cde740, which broadcasts its first component and interpolates the
// three 4 x float blocks of the two 0x30 byte records into the output.
//
// The original code of this module was built with /GS- and with SSE code
// generation for scalar floats, so the vector is written through a plain
// 16 byte structure here: a __m128 local whose address is taken makes MSVC
// 2008 add a /GS stack cookie that the original does not have.
// ---------------------------------------------------------------------------

// The 16 byte vector that is passed to FUN_00cde740: the blend factor in
// component 0, the remaining components are zero.
struct __declspec(align(16)) FUN_00cde740_v4
{
    float x, y, z, w;
};

// One 0x30 byte record: three blocks of four floats.
struct FUN_00cde740_v
{
    float a0, a1, a2, a3;
    float b0, b1, b2, b3;
    float c0, c1, c2, c3;
};

extern "C" void __cdecl FUN_00cde740(FUN_00cde740_v* a, FUN_00cde740_v* b, void* c, FUN_00cde740_v* d);

// @fnv 0x00cdd480
void FUN_00cdd480(unsigned count, FUN_00cde740_v* a, FUN_00cde740_v* b, float* c, FUN_00cde740_v* d)
{
    for (unsigned i = 0; i < count; i++)
    {
        FUN_00cde740_v4 t;
        _mm_store_ps((float*)&t, _mm_load_ss(&c[i]));
        FUN_00cde740(a + i, b + i, &t, d + i);
    }
}

struct __declspec(align(16)) S_00cdd4f0_Vec
{
    float x, y, z, w;
};
void __cdecl FUN_00cde740(void* a, void* b, S_00cdd4f0_Vec* s, void* c);
// @fnv 0x00cdd4f0
void __cdecl FUN_00cdd4f0(unsigned int n, char* a, char* b, float f, char* c)
{
    S_00cdd4f0_Vec s;
    *(__m128*)&s = _mm_load_ss(&f);
    for (unsigned int i = 0; i < n; i++)
        FUN_00cde740(a + i * 48, b + i * 48, &s, c + i * 48);
}

extern const __m128 DAT_010c71e0;

class hkQuaternionDAD;

class __declspec(align(16)) hkVector4DAD
{
  public:
    __forceinline void SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction);
    __forceinline void setAdd4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void setCross(const hkVector4DAD& v1, const hkVector4DAD& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setBroadcast3(const hkVector4DAD& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline __m128 dot3(const hkVector4DAD& v) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }

    __m128 m_vComponents;
};

class hkQuaternionDAD
{
  public:
    void FUN_00c66320(const hkQuaternionDAD& q0, const hkQuaternionDAD& q1);  // SetProduct
    const hkVector4DAD& getImag() const
    {
        return m_vec;
    }

    hkVector4DAD m_vec;
};

__forceinline void hkVector4DAD::SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction)
{
    hkVector4DAD qreal;
    qreal.setBroadcast3(quat.m_vec);
    hkVector4DAD q2minus1;
    q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), DAT_010c71e0);
    hkVector4DAD ret;
    ret.setMul4(q2minus1, direction);
    hkVector4DAD imagDotDir;
    imagDotDir.m_vComponents = quat.getImag().dot3(direction);
    imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    hkVector4DAD imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(imagDotDir, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

class hkQsTransformDAD
{
  public:
    __forceinline void SetProduct(const hkQsTransformDAD& t1, const hkQsTransformDAD& t2)
    {
        hkVector4DAD temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.FUN_00c66320(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }

    hkVector4DAD m_vTranslation;
    hkQuaternionDAD m_rotation;
    hkVector4DAD m_vScale;
};

// @fnv 0x00cddad0
extern "C" void __cdecl FUN_00cddad0(int numTransforms, int parentIndicesIn, int* worldFromModelIn, int poseLocalIn,
                                     int poseModelIn)
{
    for (int i = 0; i < numTransforms; i++)
    {
        const int parentId = ((const short*)parentIndicesIn)[i];
        const hkQsTransformDAD& worldFromParent = (-1 != parentId) ? ((hkQsTransformDAD*)poseModelIn)[parentId]
                                                                   : (*(const hkQsTransformDAD*)worldFromModelIn);
        ((hkQsTransformDAD*)poseModelIn)[i].SetProduct(worldFromParent, ((const hkQsTransformDAD*)poseLocalIn)[i]);
    }
}

namespace fnv_00cddbf0 {
extern const __m128 DAT_010c71e0;

class hkQuaternionDAD;

class __declspec(align(16)) hkVector4DAD
{
  public:
    __forceinline void SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction);
    inline hkVector4DAD& operator=(const hkVector4DAD& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline void setAdd4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void setCross(const hkVector4DAD& v1, const hkVector4DAD& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setBroadcast3(const hkVector4DAD& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline __m128 dot3(const hkVector4DAD& v) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }

    __m128 m_vComponents;
};

class hkQuaternionDAD
{
  public:
    void FUN_00c66320(const hkQuaternionDAD& q0, const hkQuaternionDAD& q1);  // SetProduct
    const hkVector4DAD& getImag() const
    {
        return m_vec;
    }

    hkVector4DAD m_vec;
};

__forceinline void hkVector4DAD::SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction)
{
    hkVector4DAD qreal;
    qreal.setBroadcast3(quat.m_vec);
    hkVector4DAD q2minus1;
    q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), DAT_010c71e0);
    hkVector4DAD ret;
    ret.setMul4(q2minus1, direction);
    hkVector4DAD imagDotDir;
    imagDotDir.m_vComponents = quat.getImag().dot3(direction);
    imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    hkVector4DAD imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(imagDotDir, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

class hkQsTransformDAD
{
  public:
    __forceinline void SetProduct(const hkQsTransformDAD& t1, const hkQsTransformDAD& t2)
    {
        hkVector4DAD temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.FUN_00c66320(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }

    hkVector4DAD m_vTranslation;
    hkQuaternionDAD m_rotation;
    hkVector4DAD m_vScale;
};

// @fnv 0x00cddbf0
void __cdecl FUN_00cddbf0(int boneIndex, const short* parentIndices, const hkQsTransformDAD* poseLocal,
                          hkQsTransformDAD& poseModelOut)
{
    poseModelOut = poseLocal[boneIndex];
    for (int parentId = parentIndices[boneIndex]; parentId >= 0; parentId = parentIndices[parentId])
    {
        poseModelOut.SetProduct(poseLocal[parentId], poseModelOut);
    }
}
}  // namespace fnv_00cddbf0

namespace fnv_00cddf20 {
extern const __m128 DAT_010c71e0;

class hkQuaternionDAD;

class __declspec(align(16)) hkVector4DAD
{
  public:
    __forceinline void SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction);
    inline hkVector4DAD& operator=(const hkVector4DAD& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline void setAdd4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void setCross(const hkVector4DAD& v1, const hkVector4DAD& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setBroadcast3(const hkVector4DAD& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline __m128 dot3(const hkVector4DAD& v) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }

    __m128 m_vComponents;
};

class hkQuaternionDAD
{
  public:
    void FUN_00c66320(const hkQuaternionDAD& q0, const hkQuaternionDAD& q1);  // SetProduct
    const hkVector4DAD& getImag() const
    {
        return m_vec;
    }

    hkVector4DAD m_vec;
};

__forceinline void hkVector4DAD::SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction)
{
    hkVector4DAD qreal;
    qreal.setBroadcast3(quat.m_vec);
    hkVector4DAD q2minus1;
    q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), DAT_010c71e0);
    hkVector4DAD ret;
    ret.setMul4(q2minus1, direction);
    hkVector4DAD imagDotDir;
    imagDotDir.m_vComponents = quat.getImag().dot3(direction);
    imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    hkVector4DAD imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(imagDotDir, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

class hkQsTransformDAD
{
  public:
    __forceinline void SetProduct(const hkQsTransformDAD& t1, const hkQsTransformDAD& t2)
    {
        hkVector4DAD temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.FUN_00c66320(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }

    hkVector4DAD m_vTranslation;
    hkQuaternionDAD m_rotation;
    hkVector4DAD m_vScale;
};

// @fnv 0x00cddf20
void __cdecl FUN_00cddf20(int numTransforms, const hkQsTransformDAD& transform, const hkQsTransformDAD* transformsIn,
                          hkQsTransformDAD* transformsOut)
{
    for (int i = 0; i < numTransforms; i++)
    {
        transformsOut[i].SetProduct(transform, transformsIn[i]);
    }
}
}  // namespace fnv_00cddf20

namespace fnv_00cde010 {
extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;

class hkQuaternionCDE;

class hkVector4CDE
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4CDE& operator=(const hkVector4CDE& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4CDE& a, const hkVector4CDE& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4CDE& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4CDE& a, const hkVector4CDE& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4CDE& a, const hkVector4CDE& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4CDE& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4CDE& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4CDE& v1, const hkVector4CDE& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4CDE& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4CDE& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionCDE& q, const hkVector4CDE& dir);
    void setRotatedInverseDir(const hkQuaternionCDE& q, const hkVector4CDE& dir);
};

class hkQuaternionCDE
{
  public:
    hkVector4CDE m_vec;

    __forceinline void SetConjugate(const hkQuaternionCDE& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionCDE& q0, const hkQuaternionCDE& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

__forceinline void hkVector4CDE::SetRotatedDirection(const hkQuaternionCDE& quat, const hkVector4CDE& direction)
{
    hkVector4CDE qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4CDE q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4CDE ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4CDE imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4CDE::setRotatedInverseDir(const hkQuaternionCDE& quat, const hkVector4CDE& direction)
{
    hkVector4CDE qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4CDE q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4CDE ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4CDE imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformCDE
{
  public:
    hkVector4CDE m_vTranslation;
    hkQuaternionCDE m_rotation;
    hkVector4CDE m_vScale;

    __forceinline void SetConjugate(const hkQsTransformCDE& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4CDE s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
    }
    __forceinline void SetProduct(const hkQsTransformCDE& t1, const hkQsTransformCDE& t2)
    {
        hkVector4CDE temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.SetProduct(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
    __forceinline void SetMulInverse(const hkQsTransformCDE& a, const hkQsTransformCDE& b)
    {
        hkQsTransformCDE h;
        h.SetConjugate(a);
        SetProduct(h, b);
    }
};

// @fnv 0x00cde010
void __cdecl FUN_00cde010(int iCount, const hkQsTransformCDE& kA, const hkQsTransformCDE* pkB, hkQsTransformCDE* pkOut)
{
    for (int i = 0; i < iCount; i++)
        pkOut[i].SetMulInverse(kA, pkB[i]);
}
}  // namespace fnv_00cde010

__declspec(align(16)) struct Vec4f
{
    float x;
    float y;
    float z;
    float w;
    void normalize();
};

struct PoseBlend
{
    Vec4f pos;
    Vec4f rot;
    Vec4f scale;
};

extern __m128 DAT_010ec7f0;
extern __m128 DAT_010c71b0;
extern const float DAT_01012054 = -1.0f;
extern const float DAT_0104da4c = 1.192092896e-07f;

static __m128 ld(const Vec4f& v)
{
    return _mm_load_ps(&v.x);
}

static void st(Vec4f& v, __m128 m)
{
    _mm_store_ps(&v.x, m);
}

static __m128 hsum4(__m128 p)
{
    __m128 h = _mm_add_ps(p, _mm_shuffle_ps(p, p, 0x4e));
    return _mm_add_ps(h, _mm_shuffle_ps(h, h, 0xb1));
}

static __forceinline __m128 blend(__m128 a, __m128 b, const Vec4f* tp)
{
    __m128 t = _mm_shuffle_ps(ld(*tp), ld(*tp), 0);
    __m128 omt = _mm_sub_ps(DAT_010ec7f0, t);
    return _mm_add_ps(_mm_mul_ps(omt, a), _mm_mul_ps(b, t));
}
// @fnv 0x00cde740
void __cdecl FUN_00cde740(const PoseBlend* a, const PoseBlend* b, const Vec4f* tp, PoseBlend* out)
{
    st(out->pos, blend(ld(a->pos), ld(b->pos), tp));
    float dot;
    _mm_store_ss(&dot,
                 hsum4(_mm_mul_ps(reinterpret_cast<const __m128&>(a->rot), reinterpret_cast<const __m128&>(b->rot))));
    Vec4f qb = b->rot;
    __m128 vQuaternionSign;
    if (dot < 0.0f)
    {
        __m128 neg = _mm_load_ss(&DAT_01012054);
        neg = _mm_shuffle_ps(neg, neg, 0);
        vQuaternionSign = _mm_mul_ps(neg, ld(qb));
    }
    else
    {
        vQuaternionSign = ld(qb);
    }
    st(out->rot, blend(ld(a->rot), vQuaternionSign, tp));
    st(out->scale, blend(ld(a->scale), ld(b->scale), tp));
    _mm_store_ss(&dot, hsum4(_mm_mul_ps(ld(out->rot), ld(out->rot))));
    if (dot < DAT_0104da4c)
    {
        st(out->rot, DAT_010c71b0);
    }
    else
    {
        out->rot.normalize();
    }
}

struct SkinFlagEntry
{
    int unk00;
    unsigned char m_bEnableState;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
};

struct SkinXformSet
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short* m_pIndices;
    int unk10;
    int unk14;
    SkinFlagEntry* m_pFlags;
    int m_uiItemCount;
};

struct SkinXformEntry
{
    __m128 v0;
    __m128 v1;
    __m128 v2;
};

static __forceinline __m128 rotate(__m128 a, __m128 b)
{
    __m128 w = _mm_shuffle_ps(b, b, 0xff);
    __m128 weight = _mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0);
    __m128 r = _mm_mul_ps(a, weight);
    __m128 product = _mm_mul_ps(a, b);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 xyz = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    __m128 dot = _mm_shuffle_ps(xyz, xyz, 0);
    r = _mm_add_ps(r, _mm_mul_ps(dot, b));
    __m128 left = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 right = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    __m128 cross = _mm_sub_ps(right, left);
    r = _mm_add_ps(_mm_mul_ps(cross, w), r);
    return _mm_add_ps(r, r);
}

// @fnv 0x00cde2d0
void __cdecl FUN_00cde2d0(SkinXformSet* set, const SkinXformEntry* input, SkinXformEntry* output)
{
    int count = set->m_uiItemCount;
    for (int index = 0; index < count; ++index)
    {
        short parent = (short)set->m_pIndices[index];
        SkinXformEntry& destination = output[index];
        if (set->m_pFlags[index].m_bEnableState)
        {
            if (parent != -1)
            {
                SkinXformEntry* parentEntry = output + parent;
                __m128 r = rotate(input[index].v0, parentEntry->v1);
                destination.v0 = _mm_add_ps(r, parentEntry->v0);
            }
            else
            {
                destination.v0 = input[index].v0;
            }
        }
    }
}
