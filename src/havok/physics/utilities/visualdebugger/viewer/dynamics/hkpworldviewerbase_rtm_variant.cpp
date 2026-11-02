// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldviewerbase_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldviewerbase.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


unsigned int FUN_00ddcdd0(unsigned int auiValue, unsigned int auiIndex, unsigned int auiFieldValue);
int __cdecl ExtractBitField(unsigned short ausValue, char acShiftIndex);
struct DDCC60BaseObject
{
    virtual ~DDCC60BaseObject()
    {}
};
struct DDCC60ReferencedObject : DDCC60BaseObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct DDCC60Action
{
    virtual ~DDCC60Action()
    {}

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct DDCC60Listener
{
    virtual ~DDCC60Listener()
    {}
};
struct DDCC60World
{
    __declspec(nothrow) void removeListener(DDCC60Listener* listener);
    __declspec(nothrow) void removeReference();
};
struct FUN_00ddcc60 : DDCC60ReferencedObject, DDCC60Action, DDCC60Listener
{
    DDCC60World* m_pOwningWorld;

    virtual ~FUN_00ddcc60();
};
struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl FUN_00c85750();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00ddcc60();
    CpuObject* DestroyOrFree(unsigned int flags);
};
extern double DAT_010cd5a8;
extern double DAT_0101ff40;
int FindAngleIndex(float angle);
int __cdecl FUN_00cb0fa0(const char* pcA, const char* pcB);
class __declspec(novtable) BDDCCB0ReferencedObject
{
  public:
    BDDCCB0ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual ~BDDCCB0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
class BDDCCB0ProcessContext
{
  public:
    virtual ~BDDCCB0ProcessContext();
    virtual const char* getType();
};
class BDDCCB0WorldAddedListener;
class BDDCCB0PhysicsContext : public BDDCCB0ReferencedObject, public BDDCCB0ProcessContext
{
  public:
    void AddWorldAddedListener(BDDCCB0WorldAddedListener* pkListener);
    void RetainReference();
};
template <class T> class BDDCCB0Array
{
  public:
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i) const
    {
        return m_data[i];
    }

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class BDDCCB0Process
{
  public:
    BDDCCB0Process(bool bSelectable) : m_bSelectable(bSelectable)
    {}
    virtual ~BDDCCB0Process();

    bool m_bSelectable;
    void* m_pkProcessHandler;
    void* m_pkDisplayHandler;
    void* m_pkInStream;
    void* m_pkOutStream;
};
class BDDCCB0WorldAddedListener
{
  public:
    virtual ~BDDCCB0WorldAddedListener();
};
class FUN_00ddccb0_cls : public BDDCCB0ReferencedObject, public BDDCCB0Process, public BDDCCB0WorldAddedListener
{
  public:
    FUN_00ddccb0_cls(const BDDCCB0Array<BDDCCB0ProcessContext*>& kContexts) throw();
    virtual ~FUN_00ddccb0_cls();

    BDDCCB0PhysicsContext* m_pkContext;
};
struct Item
{
    int unk00;
    int unk04;
    float unk08;
};
struct Flag
{
    bool value;
    Flag(bool v) : value(v)
    {}
};
Flag __cdecl FUN_00ddcda0(Item* apLeft, Item* apRight);
#include <math.h>
struct DDCE80Point
{
    float x;
    float y;
    float z;
};
struct DDCE80Bool
{
    char m_cBooleanValue;

    DDCE80Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
inline float DDCE80Fabs(float r)
{
    return (float)fabs(r);
}
inline bool DDCE80IsNearlyEqual(float d)
{
    if (DDCE80Fabs(d) < 0.001f)
        return true;
    return false;
}
DDCE80Bool __cdecl AreZDiffering(const DDCE80Point& a, const DDCE80Point& b);
#include <xmmintrin.h>
#include <math.h>
struct FUN_00ddcc40
{
    virtual ~FUN_00ddcc40();
};
struct Base1
{
// @fnv 0x00ddcd50
    virtual void FUN_00ddcd50();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct Base2
{
    virtual void FUN_00ddcd50();
};
struct Derived : Base1, Base2
{
    Derived();
    virtual void FUN_00ddcd50();
};
Derived::Derived()
{}
// FUN_00ddcd60 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00ddcd60
{
    A1_00ddcd60();
    virtual void FUN_00ddcd60();
    char pad[0x04];
};
struct A2_00ddcd60
{
    A2_00ddcd60();
    virtual void FUN_00ddcd60();
};
struct Own_00ddcd60 : A1_00ddcd60, A2_00ddcd60
{
    Own_00ddcd60();
    virtual void key_fn();
// @fnv 0x00ddcd60
    void FUN_00ddcd60();
};
Own_00ddcd60::Own_00ddcd60()
{}
void Own_00ddcd60::key_fn()
{}
Own_00ddcd60* make_00ddcd60()
{
    static Own_00ddcd60 o;
    return &o;
}

namespace ClipSimd {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float x, y, z, w;
};
extern "C"
{
    __m128 _mm_load_ps(const float*);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, __m128);
}
}

struct __declspec(align(16)) hkVector4
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        ClipSimd::__m128 q;
    };
    __forceinline const float& operator()(int i) const
    {
        return (&x)[i];
    }
};
extern const ClipSimd::__m128 g_kQuadRealConstant;
static __forceinline float dot3(ClipSimd::__m128 a, ClipSimd::__m128 b)
{
    ClipSimd::__m128 product = ClipSimd::_mm_mul_ps(a, b);
    ClipSimd::__m128 sum = ClipSimd::_mm_add_ss(ClipSimd::_mm_shuffle_ps(product, product, 0x55), product);
    float r;
    ClipSimd::_mm_store_ss(&r, ClipSimd::_mm_add_ss(ClipSimd::_mm_shuffle_ps(product, product, 0xaa), sum));
    return r;
}
struct Hit
{
    bool value;
    __forceinline Hit(bool b) : value(b)
    {}
};
// @fnv 0x00ddd0b0
Hit __cdecl FUN_00ddd0b0(const hkVector4& start, const hkVector4& end, int planeCount, const hkVector4* planes,
                         float* first, float* last)
{
    hkVector4 a = start;
    hkVector4 b = end;
    const ClipSimd::__m128& ONE = g_kQuadRealConstant;
    for (int i = 0; i < planeCount; ++i)
    {
        hkVector4 plane = planes[i];
        float w = plane(3);
        float da = w + dot3(plane.q, a.q);
        float db = w + dot3(b.q, plane.q);
        if (da >= 0.0f && db >= 0.0f)
        {
            return Hit(false);
        }
        if (da * db < 0.0f)
        {
            float fraction = da / (da - db);
            ClipSimd::__m128 t = ClipSimd::_mm_load_ss(&fraction);
            t = ClipSimd::_mm_shuffle_ps(t, t, 0);
            ClipSimd::__m128 p = ClipSimd::_mm_add_ps(ClipSimd::_mm_mul_ps(ClipSimd::_mm_sub_ps(ONE, t), a.q),
                                                      ClipSimd::_mm_mul_ps(t, b.q));
            if (da > 0.0f)
                a.q = p;
            else
                b.q = p;
        }
    }
    ClipSimd::__m128 origin = start.q;
    ClipSimd::__m128 direction = ClipSimd::_mm_sub_ps(end.q, origin);
    float lengthSquared = dot3(direction, direction);
    float firstFraction = dot3(ClipSimd::_mm_sub_ps(a.q, origin), direction) / lengthSquared;
    float lastFraction = dot3(ClipSimd::_mm_sub_ps(b.q, origin), direction) / lengthSquared;
    *first = firstFraction;
    *last = lastFraction;
    return Hit(true);
}
