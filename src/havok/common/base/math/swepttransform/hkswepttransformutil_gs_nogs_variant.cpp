
// src/havok/common/base/math/swepttransform/hkswepttransformutil_gs_nogs_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/base/math/swepttransform/hkswepttransformutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

void FUN_00cf1480(float a, float b, int* c);
struct S_00cf10f0_BinaryStream;
typedef unsigned int(__cdecl* S_00cf10f0_ReadFn)(S_00cf10f0_BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                 unsigned int* puiComponentSizes, unsigned int uiNumComponents);
struct S_00cf10f0_BinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    S_00cf10f0_ReadFn m_pfnRead;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T>
inline void S_00cf10f0_BinaryStreamLoad(S_00cf10f0_BinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}
struct S_00cf10f0_Stream
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    S_00cf10f0_BinaryStream* unk24c;
};
struct S_00cf10f0_Tls
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00cf10f0_Tls DAT_tls;
struct S_00cf10f0_Ctx
{
    int saved;
    __forceinline S_00cf10f0_Ctx(int c)
    {
        saved = DAT_tls.ctx;
        DAT_tls.ctx = c;
    }
    __forceinline ~S_00cf10f0_Ctx()
    {
        DAT_tls.ctx = saved;
    }
};
struct S_00cf10f0_Heap
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10(void* p, int bytes) throw();
    __forceinline void ReturnMemory(void* p, int bytes) throw()
    {
        vfn_10(p, bytes);
    }
};
struct S_00cf10f0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00cf10f0_Heap* m10;
    __forceinline S_00cf10f0_Heap& heap()
    {
        return *m10;
    }
};
S_00cf10f0_Router* FUN_00c85750() throw();
struct S_00cf10f0_Arr4;
void __cdecl FUN_00c908c0(S_00cf10f0_Heap* heap, S_00cf10f0_Arr4* arr, int n, int elemSize);
struct S_00cf10f0_Arr4
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void reserve(int n) throw()
    {
        S_00cf10f0_Heap& h = FUN_00c85750()->heap();
        int cap = m_cap & 0x3fffffff;
        if (cap < n)
            FUN_00c908c0(&h, this, (n < cap * 2) ? cap * 2 : n, 4);
    }
    __forceinline void SetSizeAndGrow(int n) throw()
    {
        reserve(n);
        m_iElementCount = n;
    }
    __forceinline void _clearAndDeallocate(S_00cf10f0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.ReturnMemory(m_data, (cap & 0x3fffffff) * 4);
        m_data = 0;
        m_cap = 0x80000000;
    }
};
int __cdecl LoadIntArray(S_00cf10f0_Stream* kStream, S_00cf10f0_Arr4* arr);
int __cdecl FUN_00cf1f80(int, int, int);
int __cdecl FUN_00cf2160(unsigned int arg0, unsigned int arg1);
#include <xmmintrin.h>
struct F4
{
    float x, y, z, w;
};
struct Obj
{
    __m128 m00;
    __m128 m10;
    __m128 m20;
    int unk30;
    int unk34;
    __m128 m40;
    __m128 m50;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    __m128 m80;
};
struct Calc
{
    __declspec(align(16)) F4 res;
    void __thiscall mul(Obj* o, F4* v);
};
extern const __m128 g_mask;
void ApplyDelta(__m128* a, Obj* b);
extern double DAT_010924a8;
extern double DAT_0101de30;
extern double DAT_01011588;
extern double DAT_01016ff0;
extern float DAT_01016248;
extern float DAT_01011d78;
extern float DAT_01017718;
extern __declspec(align(16)) float DAT_010ec7f0[4];
__forceinline void normalize4(__m128& q)
{
    __m128 x2 = _mm_mul_ps(q, q);
    __m128 s = _mm_add_ps(x2, _mm_shuffle_ps(x2, x2, 0x4E));
    s = _mm_add_ps(s, _mm_shuffle_ps(s, s, 0xB1));
    __m128 r = _mm_rsqrt_ss(s);
    __m128 zero = _mm_set_ss(0.0f);
    __m128 eq = _mm_cmpeq_ss(s, zero);
    __m128 prod = _mm_mul_ss(_mm_mul_ss(s, r), r);
    __m128 three = _mm_set_ss(3.0f);
    __m128 half = _mm_set_ss(0.5f);
    __m128 nr = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, prod));
    nr = _mm_andnot_ps(eq, nr);
    q = _mm_mul_ps(q, _mm_shuffle_ps(nr, nr, 0));
}
struct V4
{
    __m128 q;
};
struct FUN_008cd6a0_Class
{
    V4 col0;
    V4 col1;
    V4 col2;
    V4 translation;
    V4 com0;
    V4 com1;
    V4 rot0;
    V4 rot1;
    V4 comLocal;
    void __thiscall FUN_00cb2d90(void*);
};
__forceinline void interpolate(__m128& dst, __m128 a, __m128 b, float w)
{
    __m128 wb = _mm_load_ss(&w);
    wb = _mm_shuffle_ps(wb, wb, 0);
    __m128 other = _mm_sub_ps(_mm_load_ps(DAT_010ec7f0), wb);
    dst = _mm_add_ps(_mm_mul_ps(other, a), _mm_mul_ps(wb, b));
}
void __cdecl UpdateRotationInterpolation(float time, FUN_008cd6a0_Class* self);
void FUN_00cf1480(float a, float b, int* c);
struct __declspec(align(16)) MotionVec4
{
    float x;
    float y;
    float z;
    float w;
};
struct __declspec(align(16)) MotionMat4
{
    MotionVec4 c0;
    MotionVec4 c1;
    MotionVec4 c2;
    MotionVec4 c3;
};
class MotionRotSet_cls
{
  public:
    void Set(const MotionMat4* m);
};
struct __declspec(align(16)) MotionState_cls
{
    MotionMat4 m_kMotionTransform;  // +0x00
    MotionVec4 m_com0;              // +0x40
    MotionVec4 m_com1;              // +0x50
    MotionVec4 m_rot0;              // +0x60
    MotionVec4 m_rot1;              // +0x70
    MotionVec4 m_comLocal;          // +0x80
    MotionVec4 m_kDeltaAngle;       // +0x90
};
void SetMotionState(const MotionMat4* transform, MotionState_cls* ms);
struct TransformData
{
    __m128 row0;
    __m128 row1;
    __m128 row2;
    __m128 sourceCopy;
    __m128 output;
    __m128 output2;
    __m128 output3;
    __m128 translation;
    __m128 transform;
    __m128 zero;
};
// @fnv 0x00cf20d0
extern "C" void __cdecl FUN_00cf20d0(const __m128* source, TransformData* data)
{
    data->zero = _mm_setzero_ps();
    data->sourceCopy = *source;
    volatile float* savedLane = (volatile float*)((char*)data + 0x4c);
    float oldW = *savedLane;
    __m128 transform = data->transform;
    __m128 result = _mm_mul_ps(_mm_shuffle_ps(transform, transform, _MM_SHUFFLE(1, 1, 1, 1)), data->row1);
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(transform, transform, _MM_SHUFFLE(0, 0, 0, 0)), data->row0));
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(transform, transform, _MM_SHUFFLE(2, 2, 2, 2)), data->row2));
    result = _mm_add_ps(result, *source);
    data->output = result;
    *savedLane = oldW;
    data->output2 = result;
    ((float*)&data->output2)[3] = 0.0f;
    data->output3 = data->translation;
}
struct Obj_t
{
    __m128 m00;
    __m128 m10;
    __m128 m20;
    __m128 m30;
    __m128 m40;
    __m128 m50;
    __m128 m60;
    __m128 m70;
    __m128 m80;
    __m128 m90;

    void FUN_00cb2d90(const __m128& value);
};
void __cdecl FUN_00cf1f80(const __m128& first, const __m128& second, Obj_t* obj);
