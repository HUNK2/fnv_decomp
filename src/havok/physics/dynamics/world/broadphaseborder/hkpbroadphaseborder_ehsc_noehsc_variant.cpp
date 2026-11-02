
// src/havok/physics/dynamics/world/broadphaseborder/hkpbroadphaseborder_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/dynamics/world/broadphaseborder/hkpbroadphaseborder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

int __cdecl CompareByOffsetD4(const void* a, const void* b);
struct hkReferencedObject
{
    void removeReference();
};
struct Item : hkReferencedObject
{
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
    void FUN_00d07c80(void* owner);
};
struct Manager
{
    void FUN_00c95800(Item** entries, int count);
};
struct Collection
{
    virtual void slot00();
    virtual void removeItems(Manager* manager);
};
struct AllocatorOwner
{
    int unk00;
    int unk04;
    Collection collection;
    int unk0C;
    int unk10;
    Manager* manager;
    Item* entries[6];
    void ReleaseEntries();
};
struct DispatchItem;
struct DispatchOwner
{
    void ProcessTarget(bool*, DispatchItem*);
};
struct DispatchItem
{
    unsigned int unknown00;
    unsigned int unknown04;
    DispatchOwner* owner;
    void FUN_00ca8420(unsigned char, unsigned char, unsigned char);
};
struct Dispatcher
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    DispatchOwner* owner;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    int mode;
    void DispatchItemByMode(DispatchItem* item);
};
template <typename T> inline void S_00e10760_swap(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}
struct S_00e10760_Item;
typedef bool (*S_00e10760_Less)(S_00e10760_Item* a, S_00e10760_Item* b);
void FUN_00e10760(S_00e10760_Item** pArr, int d, int h, S_00e10760_Less cmpLess);
struct OwnerDest
{
    void FUN_00c91a70(void* p);
    void ClearValue(void* p);
};
struct NodeHdr
{
    void FUN_00c905b0();
};
struct FUN_00d0b530_cls
{
    int unk00;
    int unk04;
    int unk08;
    OwnerDest* m_0C;

    void FUN_00d0b530(int unused);
};
struct D0B630Entity;
int __cdecl CompareByOffsetD4(const void* a, const void* b);
void __cdecl FUN_00e10760(D0B630Entity** data, int lo, int hi, int(__cdecl* cmp)(const void*, const void*));
void __cdecl FUN_00c90740(D0B630Entity** objects, int numObjects, int strideInBytes);
class D0B630Primary
{
  public:
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void entityAdded(D0B630Entity* entity);

    int unk04;
    int unk08;
    int unk0C;
};
class D0B630Secondary
{
  public:
    virtual void FlushDeferredEntities(const void* event);
};
class D0B630Collector : public D0B630Primary, public D0B630Secondary
{
  public:
    virtual void FlushDeferredEntities(const void* event);

    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    D0B630Entity** m_deferred;
    int m_numDeferred;
};
struct D0B6A0Allocator;
struct D0B6A0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D0B6A0Allocator* m_pStreamAllocator;

    D0B6A0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" D0B6A0MemoryRouter& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);
struct D0B6A0Entity
{
    void RetainReference() const;
};
struct D0B6A0Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    unsigned char m_type;

    void* getOwner() const
    {
        return const_cast<char*>(reinterpret_cast<const char*>(this)) + m_iOwnerOffset;
    }
};
struct D0B6A0Event
{
    int unk00;
    const D0B6A0Collidable* m_kCollidable;
};
struct D0B6A0EntityArray
{
    D0B6A0Entity** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    static void construct(D0B6A0Entity** p, int n, D0B6A0Entity* const& e)
    {
        for (int i = 0; i < n; i++)
            p[i] = e;
    }

    __forceinline void AddBack(D0B6A0Entity* const& e)
    {
        D0B6A0Allocator& alloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(D0B6A0Entity*));
        construct(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};
class D0B6A0Primary
{
  public:
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void entityAdded(D0B6A0Entity* entity);

    int unk04;
    int unk08;
};
class D0B6A0Secondary
{
  public:
    virtual void HandleEvent(const D0B6A0Event& event);
};
class D0B6A0Collector : public D0B6A0Primary, public D0B6A0Secondary
{
  public:
    virtual void HandleEvent(const D0B6A0Event& event);

    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    bool m_deferAdds;
    D0B6A0EntityArray m_deferredEntities;
};
void __stdcall FUN_00d0b520(int);

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setr_ps(float e0, float e1, float e2, float e3);

struct hkVector4
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    const float& operator()(int i) const
    {
        return m_vComponents.m128_f32[i];
    }
};

struct hkAabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

struct D0B6A0Allocator
{
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void* AllocateMemoryBlock(int numBytes);
};

namespace bpb {

struct hkpPhantom;

struct hkpWorld
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    hkVector4 m_broadPhaseExtentsMin;
    hkVector4 m_broadPhaseExtentsMax;
    void FUN_00c93a60(void* listener);
    void FUN_00c93920(void* listener);
    void FUN_00c936a0(hkpPhantom* phantom);
};

struct hkReferencedObject
{
    virtual ~hkReferencedObject();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    hkReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    static void* operator new(unsigned int nbytes)
    {
        hkReferencedObject* b = static_cast<hkReferencedObject*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);
};

struct hkpWorldDeletionListener
{
    virtual ~hkpWorldDeletionListener();
};
struct hkpPhantomOverlapListener
{
    virtual ~hkpPhantomOverlapListener();
};
struct hkpWorldPostSimulationListener
{
    virtual ~hkpWorldPostSimulationListener();
};

struct hkpTypedBroadPhaseHandle
{
    unsigned int m_iOwnerObjectOffset;
    char m_type;
    void setType(int type)
    {
        m_type = static_cast<char>(type);
    }
};

struct hkpPhantom : hkReferencedObject
{
    int m_pOwningWorld;
    int m_ulUserData;
    int m_pCollisionShape;
    int m_uiCollisionShapeKey;
    int m_pMotionState;
    int m_parent;
    int m_iOwnerOffset;
    hkpTypedBroadPhaseHandle m_kBroadPhaseHandle;
    void FUN_00d07de0(hkpPhantomOverlapListener* listener);
};

struct hkpAabbPhantom : hkpPhantom
{
    hkpAabbPhantom* FUN_00cf2cb0(const hkAabb& aabb, unsigned int collisionFilterInfo);
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct hkpBroadPhaseBorder : hkReferencedObject,
                             hkpWorldDeletionListener,
                             hkpPhantomOverlapListener,
                             hkpWorldPostSimulationListener
{
    hkpBroadPhaseBorder(hkpWorld* world, int type, bool postponeAndSortCallbacks);
    void FUN_00c90510();
    __forceinline void createPhantom(hkpWorld* world, const hkAabb& aabb, int i)
    {
        hkpAabbPhantom* phantom =
            static_cast<hkpAabbPhantom*>(hkReferencedObject::operator new(0xe0))->FUN_00cf2cb0(aabb, 0);
        phantom->m_kBroadPhaseHandle.setType(3);
        phantom->FUN_00d07de0(this);
        m_kPhantoms[i] = phantom;
        world->FUN_00c936a0(phantom);
    }
    hkpWorld* m_pOwningWorld;
    hkpPhantom* m_kPhantoms[6];
    int m_type;
    bool m_bPostponeAndSortCallbacks;
    hkArray<void*> m_kPostponedCallbacks;
};

}

// @fnv 0x00d0b710
bpb::hkpBroadPhaseBorder::hkpBroadPhaseBorder(hkpWorld* world, int type, bool postponeAndSortCallbacks)
{
    m_type = type;
    m_pOwningWorld = world;
    m_bPostponeAndSortCallbacks = postponeAndSortCallbacks;
    FUN_00c90510();
    m_pOwningWorld->FUN_00c93a60(static_cast<hkpWorldDeletionListener*>(this));
    m_pOwningWorld->FUN_00c93920(static_cast<hkpWorldPostSimulationListener*>(this));

    hkVector4 wMin = m_pOwningWorld->m_broadPhaseExtentsMin;
    hkVector4 wMax = m_pOwningWorld->m_broadPhaseExtentsMax;

    hkAabb aabb;
    aabb.m_kMinimumCorner.set(wMax(0), wMin(1), wMin(2));
    aabb.m_kMaximumCorner.set(wMax(0), wMax(1), wMax(2));
    createPhantom(world, aabb, 0);

    aabb.m_kMinimumCorner.set(wMin(0), wMin(1), wMin(2));
    aabb.m_kMaximumCorner.set(wMin(0), wMax(1), wMax(2));
    createPhantom(world, aabb, 1);

    aabb.m_kMinimumCorner.set(wMin(0), wMax(1), wMin(2));
    aabb.m_kMaximumCorner.set(wMax(0), wMax(1), wMax(2));
    createPhantom(world, aabb, 2);

    aabb.m_kMinimumCorner.set(wMin(0), wMin(1), wMin(2));
    aabb.m_kMaximumCorner.set(wMax(0), wMin(1), wMax(2));
    createPhantom(world, aabb, 3);

    aabb.m_kMinimumCorner.set(wMin(0), wMin(1), wMax(2));
    aabb.m_kMaximumCorner.set(wMax(0), wMax(1), wMax(2));
    createPhantom(world, aabb, 4);

    aabb.m_kMinimumCorner.set(wMin(0), wMin(1), wMin(2));
    aabb.m_kMaximumCorner.set(wMax(0), wMax(1), wMin(2));
    createPhantom(world, aabb, 5);
}
