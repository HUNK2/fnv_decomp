
// src/havok/physics/utilities/weapons/hkpfirstpersongun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpfirstpersongun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpFirstPersonGun.h"

struct FUN_00e463b0_cls
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_0C;

    unsigned int FUN_00e463b0();
};

// @fnv 0x00e463b0
unsigned int FUN_00e463b0_cls::FUN_00e463b0()
{
    return m_0C & 0xfffffffeu;
}

struct FUN_00e463c0_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Tail(int a);
    void FUN_00e463c0(int a);
};

// @fnv 0x00e463c0
void FUN_00e463c0_cls::FUN_00e463c0(int a)
{
    this->Tail(a);
}

struct FUN_00cb0b80
{
    char* m_kStringBuffer;
    FUN_00cb0b80(const char* s) throw();
};
template <typename T> struct hkArrayE466
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayE466() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkRefObjE466
{
  public:
    virtual ~hkRefObjE466();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjE466()
    {
        m_sReferenceCount = 1;
    }
};
class FUN_00e46660 : public hkRefObjE466
{
  public:
    volatile unsigned char m_type;
    char unk09, unk0A, unk0B;
    FUN_00cb0b80 m_name;
    unsigned char m_uiKeyboardKey;
    char unk11, unk12, unk13;
    hkArrayE466<void*> m_kListeners;
    FUN_00e46660();
    virtual ~FUN_00e46660();
};
// @fnv 0x00e46660
FUN_00e46660::FUN_00e46660() : m_type(0), m_name(""), m_uiKeyboardKey(0x71)
{}

namespace fnv_00e466a0 {
struct hkFinishFlagE466
{
    int m_bFinishing;
};

struct FUN_00cb0a70
{
    char* m_kStringBuffer;
    FUN_00cb0a70(hkFinishFlagE466 flag) throw();
};

template <class T> struct hkArrayE466
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayE466() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkRefObjE466
{
  public:
    virtual ~hkRefObjE466();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjE466(hkFinishFlagE466 flag)
    {}
};

class FUN_00e466a0 : public hkRefObjE466
{
  public:
    unsigned char m_type;
    char unk09;
    char unk0A;
    char unk0B;
    FUN_00cb0a70 m_name;
    unsigned char m_uiKeyboardKey;
    char unk11;
    char unk12;
    char unk13;
    hkArrayE466<void*> m_kListeners;

    FUN_00e466a0(hkFinishFlagE466 flag);
    virtual ~FUN_00e466a0();
};

// @fnv 0x00e466a0
FUN_00e466a0::FUN_00e466a0(hkFinishFlagE466 flag) : hkRefObjE466(flag), m_name(flag)
{
    if (flag.m_bFinishing)
        m_type = 0;
}
}  // namespace fnv_00e466a0

namespace fnv_00e466e0 {
class hkMemoryAllocatorE466
{
  public:
    virtual ~hkMemoryAllocatorE466() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterE466
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE466* m_pStreamAllocator;
    hkMemoryAllocatorE466& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterE466& __cdecl FUN_00c85750();

template <class T> __forceinline void destructE466(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayE466
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline ~hkArrayE466()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructE466(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorE466& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00cb0c00_class
{
  public:
    const char* m_pcText;

    void FUN_00cb0c00() throw();
    ~FUN_00cb0c00_class()
    {
        FUN_00cb0c00();
    }
};

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class hkReferencedObjectE466
{
  public:
    virtual ~hkReferencedObjectE466() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class FUN_00e466e0_class : public hkReferencedObjectE466
{
  public:
    int m_08;
    FUN_00cb0c00_class m_name;
    int m_10;
    hkArrayE466<FUN_00d1df70*> m_children;

    virtual ~FUN_00e466e0_class() throw();
};

// Destructor releases every child in m_children by calling removeReference on each element.
// @fnv 0x00e466e0
FUN_00e466e0_class::~FUN_00e466e0_class() throw()
{
    for (int i = 0; i < m_children.m_iElementCount; i++)
        m_children.m_data[i]->removeReference();
}
}  // namespace fnv_00e466e0

struct FUN_00e466e0_Obj
{
    void FUN_00e466e0();
};

class FUN_00e46750_Obj;

struct VirtualObj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(FUN_00e46750_Obj* a, int b);
};

struct FUN_00c85750_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    VirtualObj* unk10;
};

FUN_00c85750_Obj* __cdecl FUN_00c85750();

class FUN_00e46750_Obj : public hkpFirstPersonGun
{
  public:
    void FUN_00e466e0();
    int FUN_00e46750(unsigned char flag);
};

// @fnv 0x00e46750
int FUN_00e46750_Obj::FUN_00e46750(unsigned char flag)
{
    FUN_00e466e0();

    if (flag & 1)
    {
        FUN_00c85750_Obj* audio = FUN_00c85750();
        audio->unk10->vf08(this, m_usMemSizeAndFlags);
    }

    return (int)this;
}

#include <xmmintrin.h>
namespace fnv_00e464e0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);

struct hkMemoryAllocator
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
};

struct hkMemoryRouterStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pThreadAllocator;
    hkMemoryAllocator& heap()
    {
        return *m_pThreadAllocator;
    }
};
hkMemoryRouterStub* FUN_00c85750();

struct hkVector4q
{
    __m128 m_vComponents;

    void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    void setXYZ(const hkVector4q& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, _mm_unpackhi_ps(v.m_vComponents, m_vComponents), 0xc4);
    }
};

extern hkVector4q DAT_01267e30;
extern float DAT_0104da48;
extern float DAT_0104da4c;

struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;

    void setIdentityRotation()
    {
        m_kColumn0.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1.setZero4();
        m_kColumn1(1) = 1.0f;
        m_kColumn2.setZero4();
        m_kColumn2(2) = 1.0f;
    }
};

struct hkpSphereShapeq
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    static void* operator new(unsigned int nbytes)
    {
        hkpSphereShapeq* p = (hkpSphereShapeq*)FUN_00c85750()->heap().allocateChunk(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);

    hkpSphereShapeq(float radius) throw();
    void FUN_00c905b0();
};

struct hkpCollidableq
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char m_type;
    char unk19;
    char unk1A;
    char unk1B;
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

    hkpCollidableq(const hkpSphereShapeq* shape, const hkTransformq* transform, int type) throw();
    void* getOwner() const
    {
        return (char*)this + m_iOwnerOffset;
    }
};

struct hkpLinearCastInputq
{
    hkVector4q m_vTo;
    float m_fMaxExtraPenetration;
    float m_fMaxExtraPenetrationAgainstFixed;
    int unk18;
    int unk1C;
};

struct hkContactPointq
{
    hkVector4q m_vContactPosition;
    hkVector4q m_vSeparatingNormal;
    void setDistance(float d)
    {
        m_vSeparatingNormal(3) = d;
    }
};

struct hkpClosestCdPointCollectorq
{
    void* m_ppVirtualMethodTable;
    float m_fEarlyOutDistance;
    int unk08;
    int unk0C;
    hkContactPointq m_kPoint;
    const hkpCollidableq* m_pRootCollidableA;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    const hkpCollidableq* m_pRootCollidableB;
    unsigned int m_uiShapeKeyB;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;

    hkpClosestCdPointCollectorq()
    {
        m_ppVirtualMethodTable = &DAT_010c476c;
        reset();
    }
    void reset()
    {
        m_kPoint.setDistance(DAT_0104da48);
        m_fEarlyOutDistance = DAT_0104da48;
        m_pRootCollidableA = 0;
    }
    bool DidHit() const
    {
        return m_pRootCollidableA != 0;
    }

    static int DAT_010c476c;
};

struct hkpWorldq
{
    void FUN_00c92430(const hkpCollidableq* collA, const hkpLinearCastInputq& input,
                      hkpClosestCdPointCollectorq& castCollector, void* startCollector);
};

struct LinearCastResult
{
    hkVector4q m_vContactPosition;
    hkVector4q m_vHitNormal;
    unsigned int m_uiCollisionShapeKey;
    void* m_pRigidBody;
};

enum hkResult
{
    HK_SUCCESS = 0,
    HK_FAILURE = 1
};

// Performs a sphere linear cast in the physics world and stores the hit point, normal, rigid body, and shape key in the result.
// @fnv 0x00e464e0
hkResult FUN_00e464e0(hkpWorldq* world, const hkVector4q& from, float radius, const hkVector4q& to,
                      LinearCastResult* result)
{
    hkpSphereShapeq* sphere = new hkpSphereShapeq(radius);

    hkTransformq transform;
    transform.setIdentityRotation();
    transform.m_vTranslation = from;

    hkpCollidableq collidable(sphere, &transform, 0);

    hkpClosestCdPointCollectorq collector;

    hkpLinearCastInputq input;
    input.m_vTo = to;
    input.m_fMaxExtraPenetration = DAT_0104da4c;
    input.m_fMaxExtraPenetrationAgainstFixed = DAT_0104da4c;

    world->FUN_00c92430(&collidable, input, collector, 0);

    sphere->FUN_00c905b0();

    if (collector.DidHit())
    {
        result->m_vContactPosition = collector.m_kPoint.m_vContactPosition;
        result->m_vHitNormal = collector.m_kPoint.m_vSeparatingNormal;
        const hkpCollidableq* pHitCollidable = collector.m_pRootCollidableB;
        result->m_pRigidBody = (pHitCollidable->m_type == 1) ? pHitCollidable->getOwner() : 0;
        result->m_uiCollisionShapeKey = collector.m_uiShapeKeyB;
        return HK_SUCCESS;
    }

    result->m_pRigidBody = 0;
    result->m_vContactPosition = to;
    result->m_vHitNormal.setXYZ(DAT_01267e30);
    result->m_uiCollisionShapeKey = 0xffffffff;
    return HK_FAILURE;
}
}  // namespace fnv_00e464e0
