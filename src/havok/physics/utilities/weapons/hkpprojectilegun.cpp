
// src/havok/physics/utilities/weapons/hkpprojectilegun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpprojectilegun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpProjectileGun.h"

struct FUN_00e44c70_cls
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    unsigned char flags;
    unsigned char pad1;
    unsigned char pad2;
    unsigned char pad3;
    unsigned char pad4;
    unsigned char pad5;
    unsigned char pad6;
    unsigned char pad7;
    unsigned char pad8;
    unsigned char pad9;
    unsigned char padA;
    unsigned char padB;
    unsigned char padC;
    void InitOnce();
};

// @fnv 0x00e44c70
void FUN_00e44c70_cls::InitOnce()
{
    if (!(reinterpret_cast<unsigned char*>(this)[0xc] & 1))
    {
        vC();
        reinterpret_cast<unsigned char*>(this)[0xc] |= 1;
    }
}

struct hkpEntity
{
    void AddContactListener(void*);
    void RemoveContactListener(void*);
};
struct FUN_00e44d50_cls
{
    void FUN_00e44d50(bool);
};
// @fnv 0x00e44d50
void FUN_00e44d50_cls::FUN_00e44d50(bool on)
{
    if (on != (((unsigned char*)this)[0xc] >> 2 & 1))
    {
        void* e = *(void**)((char*)this + 0x10);
        if (e && *(int*)((char*)e + 8))
        {
            void* arg = (void*)((char*)this + 8);
            if (on)
                ((hkpEntity*)e)->AddContactListener(arg);
            else
                ((hkpEntity*)e)->RemoveContactListener(arg);
        }
        if (on)
            ((unsigned char*)this)[0xc] |= 4;
        else
            ((unsigned char*)this)[0xc] &= 0xfb;
    }
}

struct FUN_00e44be0_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(float, int, int, int, int, int);

    unsigned char pad[0x24];
    float value;

    void UpdateValue(float, int, int, int, int, int);
};

// Subtracts a from value when value is above zero, then forwards all arguments to v10.
// @fnv 0x00e44be0
void FUN_00e44be0_cls::UpdateValue(float afDelta, int b, int c, int d, int e, int f)
{
    if (value > 0.0f)
        value = value - afDelta;

    v10(afDelta, b, c, d, e, f);
}

struct DDCC60World
{
    void removeReference();
};
struct hkpGunProjectile
{
    void FUN_00e44cc0();
    void ReleaseWorld();
};
// If the world pointer at offset 0x10 is set, calls FUN_00e44cc0 when its field at +8 is nonzero, then calls removeReference and clears the pointer.
// @fnv 0x00e44cf0
void hkpGunProjectile::ReleaseWorld()
{
    if (*(DDCC60World**)((char*)this + 0x10))
    {
        if (*(int*)((char*)*(void**)((char*)this + 0x10) + 8))
            FUN_00e44cc0();
        (*(DDCC60World**)((char*)this + 0x10))->removeReference();
        *(void**)((char*)this + 0x10) = 0;
    }
}

struct FUN_00e44d20_cls
{
    void FUN_00e44d20(float);
};

struct FUN_00e44de0_cls
{
    unsigned char pad[0x2c];
    FUN_00e44d20_cls** m_kTrackedObjects;
    int m_uiItemCount;

    void ApplyToAll(float);
};

// @fnv 0x00e44de0
void FUN_00e44de0_cls::ApplyToAll(float value)
{
    int count = m_uiItemCount;
    for (int i = 0; i < count; ++i)
        m_kTrackedObjects[i]->FUN_00e44d20(value);
}

struct FUN_00e44e40_object
{
    unsigned char pad[0x0c];
    unsigned char flags;
};

struct FUN_00e44e40_cls
{
    unsigned char pad[0x2c];
    FUN_00e44e40_object** m_kTrackedObjects;
    int m_uiItemCount;

    FUN_00e44e40_object* FindFirstUnflaggedObject();
};

// @fnv 0x00e44e40
FUN_00e44e40_object* FUN_00e44e40_cls::FindFirstUnflaggedObject()
{
    int i = 0;
    while (i < m_uiItemCount)
    {
        FUN_00e44e40_object* object = m_kTrackedObjects[i];
        if ((object->flags & 1) == 0)
            return object;
        ++i;
    }
    return 0;
}

struct Iface1
{
    virtual void v0();
};

extern int DAT_010ebf74;
extern int DAT_010ebf94;
extern int _DAT_0102e388;
extern const Iface1 vftable_Iface1;

struct FUN_00e44e70_cls
{
    void ReleaseWorld();
    void ResetVtables();
};

// @fnv 0x00e44e70
void FUN_00e44e70_cls::ResetVtables()
{
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_010ebf94);
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8) = reinterpret_cast<void*>(&DAT_010ebf74);

    ReleaseWorld();

    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8) =
        const_cast<void*>(static_cast<const void*>(&vftable_Iface1));
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&_DAT_0102e388);
}

struct FUN_00e44f30_cls
{
    void ApplyToAll(float);
    void ClearProjectileFlags();
    void FUN_00e44f30(float, int, int, int, int, int);
};

void __cdecl FUN_00e44ef0();

// Calls ApplyToAll with a, then ClearProjectileFlags, then FUN_00e44ef0; b through f are unused.
// @fnv 0x00e44f30
void FUN_00e44f30_cls::FUN_00e44f30(float a, int b, int c, int d, int e, int f)
{
    ApplyToAll(a);
    ClearProjectileFlags();
    FUN_00e44ef0();
}

extern void __cdecl FUN_00e45040();

struct FUN_00e450f0_manager
{
    virtual void v0();
    virtual void v4();
    virtual void deallocate(void*, unsigned short);
};

struct FUN_00e450f0_router
{
    unsigned char pad[0x10];
    FUN_00e450f0_manager* manager;
};

extern FUN_00e450f0_router* __cdecl _D1A0E0GetMemoryRouter();

struct FUN_00e450f0_cls
{
    void* vftable;
    unsigned short size;

    void* FUN_00e450f0(int flags);
};

// Calls FUN_00e45040, then if flags bit 0 is set deallocates this via the memory router's manager, and returns this.
// @fnv 0x00e450f0
void* FUN_00e450f0_cls::FUN_00e450f0(int flags)
{
    FUN_00e45040();

    if (flags & 1)
    {
        FUN_00e450f0_router* router = _D1A0E0GetMemoryRouter();
        router->manager->deallocate(this, size);
    }

    return this;
}

struct CallTarget_00e44eb0
{
    int FUN_00e44eb0();
};
struct SearchObject
{
    int GetCallResult(unsigned int arg0);
};
// Calls FUN_00e44eb0 on this object and returns its result as an int.
// @fnv 0x00e44f50
int SearchObject::GetCallResult(unsigned int auiUnused)
{
    unsigned int callResult0 = (unsigned int)((CallTarget_00e44eb0*)this)->FUN_00e44eb0();
    return (int)callResult0;
}

struct V
{
    virtual void __fastcall f0(int);
    virtual void __fastcall f1(int);
    virtual void __fastcall f2(int);
    virtual void __fastcall f3(int);
    virtual void __fastcall f4(int);
};
struct C
{
    void __fastcall FUN_00e45090(int);
};
// @fnv 0x00e45090
void __fastcall C::FUN_00e45090(int x)
{
    V* base = reinterpret_cast<V*>(reinterpret_cast<char*>(this) - 8);
    base->f4(x);
}

struct FUN_00e450b0_cls
{
    void FUN_00e450b0(int);
};

// @fnv 0x00e450b0
void __thiscall FUN_00e450b0_cls::FUN_00e450b0(int)
{
    *(unsigned char*)(this + 0xc) |= 2;
}

class hkTimerE44B
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void trigger(int a, int b);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    float m_period;
    float m_remaining;

    void TriggerIfElapsed(int a, int b);
};

// @fnv 0x00e44bc0
void hkTimerE44B::TriggerIfElapsed(int a, int b)
{
    if (!(m_remaining > 0.0f))
    {
        m_remaining = m_period;
        trigger(a, b);
    }
}

struct hkBoolE44C
{
    char m_cBooleanValue;
    hkBoolE44C()
    {}
    hkBoolE44C(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct hkpEntityE44C;
struct hkpEntityListenerE44C;

struct hkpWorldE44C
{
    hkBoolE44C ProcessTarget(hkpEntityE44C* entity);
};

struct hkpEntityE44C
{
    int unk00;
    int unk04;
    hkpWorldE44C* m_pOwningWorld;
    void FUN_00c9c140(hkpEntityListenerE44C* listener);
};

struct hkBaseAE44C
{
    int unk00;
    int unk04;
};

struct hkpEntityListenerE44C
{
    int unk08;
};

struct hkObjE44C : public hkBaseAE44C, public hkpEntityListenerE44C
{
    unsigned char m_flags;
    char unk0D;
    char unk0E;
    char unk0F;
    hkpEntityE44C* m_pEntity;

    void FUN_00e44cc0();
};

// @fnv 0x00e44cc0
void hkObjE44C::FUN_00e44cc0()
{
    if (m_pEntity)
    {
        m_pEntity->m_pOwningWorld->ProcessTarget(m_pEntity);
        if (m_flags & 4)
            m_pEntity->FUN_00c9c140(this);
    }
}

struct hkFlagsE44E
{
    unsigned char m_kStorage;

    void clear(unsigned char mask)
    {
        m_kStorage &= ~mask;
    }
};

struct hkpGunProjectileE44E
{
    int m_00;
    int m_04;
    int m_08;
    hkFlagsE44E m_flags;
};

template <class T> struct hkArrayE44E
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

class hkpProjectileGunE44E
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_iMaxProjectiles;
    hkReal m_fReloadTime;
    hkReal m_fTimeSinceLastShot;
    hkArrayE44E<hkpGunProjectileE44E*> m_kRigidBodies;

    void ClearProjectileFlags();
};

// @fnv 0x00e44e10
void hkpProjectileGunE44E::ClearProjectileFlags()
{
    const int n = m_kRigidBodies.GetLogicalSize();
    for (int i = 0; i < n; i++)
        m_kRigidBodies[i]->m_flags.clear(2);
}

void __cdecl ReleaseWorld();

// @fnv 0x00e44ea0
void __cdecl FUN_00e44ea0()
{
    ReleaseWorld();
}

extern float DAT_01017870;

class FUN_00e46660
{
  public:
    FUN_00e46660() throw();
    virtual ~FUN_00e46660() throw();
    int unk04[7];
    int m_20;
};

class hkRangeE44F
{
  public:
    float m_24;
    float m_28;

    hkRangeE44F() throw() : m_24(DAT_01017870), m_28(0.0f)
    {}
};

template <class T> class hkArrayE44F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00e44fc0 : public FUN_00e46660, public hkRangeE44F
{
  public:
    hkArrayE44F<int> m_items;
    int m_38;
    int m_3c;

    FUN_00e44fc0(int a, int b) throw();
    virtual ~FUN_00e44fc0() throw();
};

// Initializes the object: sets m_20 to 5, inits m_items, and stores the two constructor arguments into m_38 and m_3c.
// @fnv 0x00e44fc0
FUN_00e44fc0::FUN_00e44fc0(int a, int b) throw()
{
    m_20 = 5;
    m_items.init();
    m_38 = a;
    m_3c = b;
}

struct FnvCpu_FUN_00e450c0_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00e450c0_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00e450c0_CpuAllocator* allocator;
};
FnvCpu_FUN_00e450c0_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00e450c0_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void ResetVtables();
    FnvCpu_FUN_00e450c0_CpuObject* FUN_00e450c0(unsigned int flags);
};
// @fnv 0x00e450c0
FnvCpu_FUN_00e450c0_CpuObject* FnvCpu_FUN_00e450c0_CpuObject::FUN_00e450c0(unsigned int flags)
{
    ResetVtables();
    if (flags & 1)
    {
        FnvCpu_FUN_00e450c0_CpuAllocatorHolder* pAllocatorHolder = FUN_00c85750();
        pAllocatorHolder->allocator->Invoke(this, size);
    }
    return this;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    void _mm_store_ss(float*, __m128);
    float _mm_cvtss_f32(__m128);
}

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline __m128 dot3(const hkVector4q& v) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    }

    __forceinline hkReal length3() const
    {
        hkReal len;
        _mm_store_ss(&len, _mm_sqrt_ss(dot3(*this)));
        return len;
    }

    __forceinline void normalize3()
    {
        __m128 len2 = dot3(*this);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                              _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
        r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }

    __forceinline void setCross(const hkVector4q& v0, const hkVector4q& v1)
    {
        m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                                              _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2)),
                                   _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                                              _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9)));
    }
};

struct hkRotationq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;

    __forceinline void operator=(const hkRotationq& r)
    {
        m_kColumn0 = r.m_kColumn0;
        m_kColumn1 = r.m_kColumn1;
        m_kColumn2 = r.m_kColumn2;
    }

    void SetAxisAngle(const hkVector4q& axis, hkReal angle);
    void SetProduct(const hkRotationq& a, const hkRotationq& b);
};

struct hkTransformq
{
    hkRotationq m_rotation;
    hkVector4q m_vTranslation;
};

class hkpRigidBodyq
{
  public:
    __forceinline const hkTransformq& getTransform() const
    {
        return *reinterpret_cast<const hkTransformq*>(reinterpret_cast<const char*>(this) + 0xf0);
    }

    __forceinline const hkVector4q& getLinearVelocity() const
    {
        return *reinterpret_cast<const hkVector4q*>(reinterpret_cast<const char*>(this) + 0x1b0);
    }

    void SetGeometryTransform(const hkTransformq& transform);
};

// If speed exceeds minSpeed, rotates the body's transform about the cross of its normalized velocity and rotation column 0, by an angle scaled by turnRate.
// @fnv 0x00e44990
void __cdecl ApplyTurnRate(hkpRigidBodyq* body, hkReal minSpeed, hkReal turnRate)
{
    hkTransformq t;
    t = body->getTransform();
    const hkVector4q& vel = body->getLinearVelocity();

    if (vel.length3() > minSpeed)
    {
        hkVector4q col0;
        col0 = t.m_rotation.m_kColumn0;
        hkVector4q dir;
        dir = vel;
        dir.normalize3();

        hkVector4q cross;
        cross.setCross(dir, col0);

        hkReal len = cross.length3();
        if (len > 1e-5f)
        {
            hkReal angle = len * turnRate * -5.0;
            hkVector4q axis;
            axis = cross;
            axis.normalize3();

            hkRotationq rot;
            rot.SetAxisAngle(axis, angle);

            hkRotationq newRot;
            newRot.SetProduct(rot, t.m_rotation);
            t.m_rotation = newRot;

            body->SetGeometryTransform(t);
        }
    }
}

class hkRefObjE44
{
  public:
    hkRefObjE44()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkRefObjE44();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void FUN_00c90510() const throw();
};

class hkpContactListenerE44
{
  public:
    virtual void HandleContactPointEvent(void* event)
    {}
    virtual void collisionAddedCallback(void* event)
    {}
    virtual void collisionRemovedCallback(void* event)
    {}
    virtual ~hkpContactListenerE44()
    {}
};

template <class BITS, class STORAGE> class hkFlagsE44
{
  public:
    hkFlagsE44(STORAGE s)
    {
        m_kStorage = s;
    }
    STORAGE m_kStorage;
};

enum ProjectileFlagsE44
{
    PROJECTILE_FLAG_NONE
};

class FUN_00e44c20 : public hkRefObjE44, public hkpContactListenerE44
{
  public:
    hkFlagsE44<ProjectileFlagsE44, unsigned char> m_flags;
    hkRefObjE44* m_kCollisionBody;
    float m_fDamage;
    void* m_pGun;

    FUN_00e44c20(void* gun, hkRefObjE44* body);
    virtual ~FUN_00e44c20();
    virtual void HandleContactPointEvent(void* event);
};

// Stores gun and body, zeroes flags and damage, and calls FUN_00c90510 on the body.
// @fnv 0x00e44c20
FUN_00e44c20::FUN_00e44c20(void* gun, hkRefObjE44* apCollisionBody)
    : m_flags(0), m_fDamage(0.0f), m_kCollisionBody(apCollisionBody), m_pGun(gun)
{
    m_kCollisionBody->FUN_00c90510();
}

namespace fnv_00e44f60 {
template <int SIZE> __forceinline void memCpyOneAlignedE44F(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterE44F
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterE44F {
extern "C" hkMemoryRouterE44F& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayE44F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterE44F& router = hkRouterE44F::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedE44F<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class hkEntityE44F
{
  public:
    void FUN_00c90510();
    void FUN_00e44c90(int id);
};

class hkIslandE44F
{
  public:
    int unk00[11];
    hkArrayE44F<hkEntityE44F*> m_kActorEntries;
    int m_iOwnerObjectOffset;

    void FUN_00e44f60(hkEntityE44F* entity);
};

// Calls FUN_00c90510 on the entity, appends it to m_kActorEntries, and calls FUN_00e44c90 with m_iOwnerObjectOffset.
// @fnv 0x00e44f60
void hkIslandE44F::FUN_00e44f60(hkEntityE44F* entity)
{
    entity->FUN_00c90510();
    m_kActorEntries.AddBack(entity);
    entity->FUN_00e44c90(m_iOwnerObjectOffset);
}
}  // namespace fnv_00e44f60

class hkMemoryAllocatorE450
{
  public:
    virtual ~hkMemoryAllocatorE450() throw();
    virtual void* AllocateMemoryBlock(int n) throw();
    virtual void ReleaseBlock(void* p, int n) throw();
    virtual void* AllocateBufferWithSize(int& n) throw();
    virtual void ReturnMemory(void* p, int n) throw();
};

struct hkMemoryRouterE450
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE450* m_pStreamAllocator;
    hkMemoryAllocatorE450& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE450 {
extern "C" hkMemoryRouterE450& __cdecl FUN_00c85750() throw();
}

template <class T> struct hkArrayE450
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayE450() throw()
    {
        hkMemoryAllocatorE450& alloc = hkRouterE450::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00e466e0
{
  public:
    virtual ~FUN_00e466e0() throw();
    int unk04[10];
};

class FUN_00e45040 : public FUN_00e466e0
{
  public:
    hkArrayE450<void*> m_items;

    void FUN_00e44eb0() throw();
    virtual ~FUN_00e45040() throw();
};

// @fnv 0x00e45040
FUN_00e45040::~FUN_00e45040() throw()
{
    FUN_00e44eb0();
}

struct hkFinishLoadedObjectFlagE46F
{
    int m_bFinishing;
};

class hkMemoryAllocatorE46F
{
  public:
    virtual ~hkMemoryAllocatorE46F() throw();
    virtual void* AllocateMemoryBlock(int n) throw();
    virtual void ReleaseBlock(void* p, int n) throw();
};

struct hkMemoryRouterE46F
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE46F* m_pStreamAllocator;
    hkMemoryAllocatorE46F& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE46F {
extern "C" hkMemoryRouterE46F& __cdecl FUN_00c85750() throw();
}

class FUN_00e46e80
{
  public:
    FUN_00e46e80() throw();
    void FUN_00e45460(void* world) throw();

    static void* operator new(unsigned int n)
    {
        return hkRouterE46F::FUN_00c85750().heap().AllocateMemoryBlock(n);
    }
    static void operator delete(void* p);

    int unk00[5];
};

class FUN_00e466a0
{
  public:
    FUN_00e466a0(hkFinishLoadedObjectFlagE46F flag) throw();
    virtual ~FUN_00e466a0() throw();
    int unk04;
    char unk08;
};

class FUN_00e46f20 : public FUN_00e466a0
{
  public:
    FUN_00e46f20(hkFinishLoadedObjectFlagE46F flag) throw();
    virtual ~FUN_00e46f20() throw();

    int unk0C[9];
    void* m_pOwningWorld;
    int unk34[7];
    FUN_00e46e80* m_helper;
};

// Initializes the object and, when finishing, allocates a helper and binds it to the owning world.
// @fnv 0x00e46f20
FUN_00e46f20::FUN_00e46f20(hkFinishLoadedObjectFlagE46F flag) throw() : FUN_00e466a0(flag)
{
    if (flag.m_bFinishing)
    {
        unk08 = 1;
        m_helper = new FUN_00e46e80();
        m_helper->FUN_00e45460(m_pOwningWorld);
    }
}

namespace fnv_00e45010 {
namespace FUN_00e466a0 {
class hkpFirstPersonGun
{
  public:
    hkpFirstPersonGun(void* pkWorld);
    virtual ~hkpFirstPersonGun();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
};
}

template <class T> class hkArrayE450
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE450() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

namespace FUN_00e45010 {
class hkpProjectileGun : public FUN_00e466a0::hkpFirstPersonGun
{
  public:
    hkpProjectileGun(void* pkWorld);
    virtual ~hkpProjectileGun();

    hkArrayE450<void*> m_kProjectiles;
};

// @fnv 0x00e45010
hkpProjectileGun::hkpProjectileGun(void* pkWorld) : FUN_00e466a0::hkpFirstPersonGun(pkWorld)
{}
}
}  // namespace fnv_00e45010

// sub ecx,8; jmp target  ==  MSVC adjustor thunk
struct PrimaryBase
{
    virtual void FUN_00e450a0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00e450a0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e450a0
    virtual void FUN_00e450a0();
};

Derived::Derived()
{}

struct ProjectileBodyE44C : hkpEntityE44C
{
    void AddSlot(hkpEntityListenerE44C* listener) throw();
};

struct ProjectileWorldE44C
{
    hkpEntityE44C* FUN_00c914d0(hkpEntityE44C* body, int activation) throw();
};

struct ProjectileAddE44C : hkObjE44C
{
    void FUN_00e44c90(ProjectileWorldE44C* scene) throw();
};

// If m_flags bit 4 is set, calls FUN_00c9c540(this) on m_pEntity, then calls FUN_00c914d0(m_pEntity, 1) on scene.
// @fnv 0x00e44c90
void ProjectileAddE44C::FUN_00e44c90(ProjectileWorldE44C* scene) throw()
{
    if (m_flags & 4)
        static_cast<ProjectileBodyE44C*>(m_pEntity)->AddSlot(this);
    scene->FUN_00c914d0(m_pEntity, 1);
}

struct FUN_00e44c70_V
{
    void __thiscall InitOnce();
};

class FUN_00e44da0_cls : public hkpProjectileGun
{
  public:
    void __thiscall FUN_00e44da0(float value);
};

// Iterates m_kRigidBodies and calls FUN_00e44c70 on each item whose offset-0x14 float field exceeds value.
// @fnv 0x00e44da0
void __thiscall FUN_00e44da0_cls::FUN_00e44da0(float value)
{
    int count = m_kRigidBodies.m_iElementCount;
    int index = 0;

    while (index < count)
    {
        FUN_00e44c70_V* item = reinterpret_cast<FUN_00e44c70_V*>(m_kRigidBodies.m_data[index]);
        float itemValue = *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(item) + 0x14);

        if (itemValue > value)
        {
            item->InitOnce();
        }

        ++index;
    }
}

struct FUN_00e44d20_object
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14(float);

    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned char unk0E;
    unsigned char unk0F;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    float unk14;
    void FUN_00e44d20(float value);
};

// Adds value to unk14 and calls vf14 when the low bit of unk0C is clear.
// @fnv 0x00e44d20
void FUN_00e44d20_object::FUN_00e44d20(float value)
{
    if ((unk0C & 1) == 0)
    {
        unk14 += value;
        vf14(value);
    }
}

struct ProjQ
{
    void InitOnce();
};
struct FUN_00e44eb0_cls
{
    char m_auiShapeKeys[0x2c];
    void* m_pProjectiles;
    int m_iProjectileCount;
    void FUN_00e44eb0();
};

// Calls FUN_00e44c70 and removeReference on each projectile in m_pProjectiles, then resets m_iProjectileCount to 0.
// @fnv 0x00e44eb0
void FUN_00e44eb0_cls::FUN_00e44eb0()
{
    int count = m_iProjectileCount;
    for (int i = 0; i < count; ++i)
    {
        ProjQ* p = (ProjQ*)((char**)m_pProjectiles)[i];
        p->InitOnce();
        ((DDCC60World*)p)->removeReference();
    }
    m_iProjectileCount = 0;
}

struct ProjectileRelease
{
    int m_00;
    int m_04;
    int m_08;
    unsigned char m_flags;
    void FUN_00c905b0();
    __forceinline bool destroyed() const
    {
        return (m_flags & 1) != 0;
    }
};
__forceinline void copyProjectile(void* dst, const void* src)
{
    unsigned int k = 0;
    do
    {
        static_cast<int*>(dst)[k] = static_cast<const int*>(src)[k];
    } while (++k < sizeof(void*) / sizeof(int));
}

__forceinline void eraseProjectile(hkArray<void*>& a, int i)
{
    --a.m_iElementCount;
    if (a.m_iElementCount != i)
        copyProjectile(a.m_data + i, a.m_data + a.m_iElementCount);
}

class ProjectileCleanupEntry : public hkpProjectileGun
{
  public:
    void FUN_00e44ef0();
};

// For each item in m_kRigidBodies whose flags bit 0 is set, calls FUN_00c905b0 on it and removes it from the array.
// @fnv 0x00e44ef0
void ProjectileCleanupEntry::FUN_00e44ef0()
{
    int count = m_kRigidBodies.m_iElementCount;
    for (int i = 0; i < count; ++i)
    {
        ProjectileRelease* item = (ProjectileRelease*)m_kRigidBodies.m_data[i];
        if (item->destroyed())
        {
            item->FUN_00c905b0();
            eraseProjectile(m_kRigidBodies, i);
            --count;
            --i;
        }
    }
}
