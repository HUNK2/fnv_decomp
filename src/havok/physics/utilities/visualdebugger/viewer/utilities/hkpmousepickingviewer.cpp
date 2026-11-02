
// src/havok/physics/utilities/visualdebugger/viewer/utilities/hkpmousepickingviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/utilities/hkpmousepickingviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* DAT_011b5ff0;

// @fnv 0x00d66bd0
void __stdcall FUN_00d66bd0(void** pOut, void** pCount)
{
    *pOut = &DAT_011b5ff0;
    *pCount = (void*)3;
}

struct FUN_00d66c10_class
{
    void RemoveAmbientLight();
};

struct FUN_00d66cb0_class
{
    int m0;
    int m4;
    int m8;
    void FUN_00d66cb0(int a);
};

// @fnv 0x00d66cb0
void FUN_00d66cb0_class::FUN_00d66cb0(int aiValue)
{
    if (aiValue == *(int*)((char*)this + 8))
        ((FUN_00d66c10_class*)((char*)this - 0x20))->RemoveAmbientLight();
}

extern int DAT_010d1cb4;
extern int DAT_010d1cc4;
extern int DAT_010d1ce4;
struct D698B0Base
{
    char m0[0x20];
    D698B0Base(void*);
};
struct FUN_00d66b90 : D698B0Base
{
    int m20;
    int m24;
    int m28;
    int m2c;
    float m30;
    FUN_00d66b90(int);
};
// @fnv 0x00d66b90
FUN_00d66b90::FUN_00d66b90(int a) : D698B0Base((void*)a)
{
    m30 = 1000.0f;
    m28 = 0;
    m2c = 0;
    *(int*)this = (int)&DAT_010d1ce4;
    *(int*)((char*)this + 8) = (int)&DAT_010d1cc4;
    m20 = (int)&DAT_010d1cb4;
}

struct Registry_00dd9380
{
    void* Register(const char*, void(__cdecl*)());
};
extern int DAT_01269cd0;
extern int DAT_01268ff8;
void __cdecl FUN_00d66c50();
// @fnv 0x00d66c90
void* __cdecl RegisterMousePicking()
{
    DAT_01268ff8 = (int)((Registry_00dd9380*)DAT_01269cd0)->Register("Mouse Picking", FUN_00d66c50);
    return (void*)DAT_01268ff8;
}

extern int DAT_01268ff8;

// @fnv 0x00d66ed0
int __cdecl FUN_00d66ed0()
{
    return DAT_01268ff8;
}

struct FnvCpu_FUN_00d66c50_CpuBlock;
struct FnvCpu_FUN_00d66c50_CpuAllocator
{
    virtual void slot00();
    virtual void* Invoke(unsigned int size);
};
struct FnvCpu_FUN_00d66c50_CpuHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d66c50_CpuAllocator* allocator;
};
void* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d66c50_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d66c50_CpuBlock* FUN_00d66b90(unsigned int value);
};
// @fnv 0x00d66c50
void* __cdecl FUN_00d66c50(unsigned int value)
{
    FnvCpu_FUN_00d66c50_CpuHolder* holder = static_cast<FnvCpu_FUN_00d66c50_CpuHolder*>(FUN_00c85750());
    FnvCpu_FUN_00d66c50_CpuBlock* block = static_cast<FnvCpu_FUN_00d66c50_CpuBlock*>(holder->allocator->Invoke(52));
    block->size = 52;
    block = block->FUN_00d66b90(value);
    if (block)
        return reinterpret_cast<char*>(block) + 8;
    return 0;
}

namespace fnv_00d66d00 {
typedef unsigned __int64 hkUint64D66D;

struct hkBoolD66D
{
    char m_cBooleanValue;
    hkBoolD66D(bool b)
    {
        m_cBooleanValue = b;
    }
};

__declspec(align(16)) struct hkVector4D66D
{
    float x, y, z, w;
    void FUN_00c7f690(const void* pkTransform, const hkVector4D66D& kPos);
};

struct hkAllocatorD66D
{
    virtual void V0();
    virtual void* AllocateMemoryBlock(int iNumBytes);
};

struct hkMemoryRouterD66D
{
    char m_acUnk00[0x10];
    hkAllocatorD66D* m_pkHeap;
    hkAllocatorD66D& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterD66D* __cdecl FUN_00c85750();

struct hkpEntityD66D;

struct FUN_00cbb560
{
    char m_acUnk00[0x60];
    static __forceinline void* operator new(unsigned int uiSize)
    {
        void* p = FUN_00c85750()->heap().AllocateMemoryBlock(uiSize);
        ((unsigned short*)p)[2] = (unsigned short)uiSize;
        return p;
    }
    FUN_00cbb560(const hkVector4D66D& kPositionInRbLocal, const hkVector4D66D& kMousePositionInWorld,
                 float fSpringDamping, float fSpringElasticity, float fObjectDamping, hkpEntityD66D* pkRigidBody,
                 void* pkRigidBodies) throw();
    void FUN_00cbb1b0(float fMaxRelativeForce);
};

struct hkpWorldD66D
{
    void FUN_00c97370(FUN_00cbb560* pkAction);
};

struct hkpEntityD66D
{
    char m_acUnk00[8];
    hkpWorldD66D* m_pkWorld;
    char m_acUnk0c[0xdc];
    char m_cMotionType;
    char m_acUnkE9[7];
    char m_kTransform[0x40];
};

struct hkpCollidableD66D
{
    char m_acUnk00[0x10];
    signed char m_cOwnerOffset;
    char m_acUnk11[7];
    char m_cType;
};

struct MousePickD66D
{
    char m_acUnk00[0x28];
    hkpWorldD66D* m_pkWorld;
    FUN_00cbb560* m_pkMouseSpring;
    float m_fMaxRelativeForce;
    hkBoolD66D PickEntity(hkUint64D66D uiUserData, const hkVector4D66D& kPositionInWorld);
};

// Validates the user data as a collidable, stores its entity's world, and creates and adds a mouse spring action for the entity.
// @fnv 0x00d66d00
hkBoolD66D MousePickD66D::PickEntity(hkUint64D66D uiCollidableUserData, const hkVector4D66D& kPositionInWorld)
{
    hkUint64D66D uiUserDataTag = uiCollidableUserData & 3;
    if (uiUserDataTag == 3)
        uiCollidableUserData &= ~(hkUint64D66D)3;
    else if (uiUserDataTag != 0)
        return false;
    hkpCollidableD66D* pkCollidable = (hkpCollidableD66D*)(unsigned int)uiCollidableUserData;
    if (pkCollidable->m_cType == 1)
    {
        hkpEntityD66D* pkEntity = (hkpEntityD66D*)((char*)pkCollidable + pkCollidable->m_cOwnerOffset);
        if (pkEntity)
        {
            m_pkWorld = pkEntity->m_pkWorld;
            if (pkEntity->m_cMotionType != 5 && pkEntity->m_pkWorld == m_pkWorld)
            {
                hkVector4D66D kPositionInRbLocal;
                kPositionInRbLocal.FUN_00c7f690(pkEntity->m_kTransform, kPositionInWorld);
                m_pkMouseSpring =
                    new FUN_00cbb560(kPositionInRbLocal, kPositionInWorld, 0.5f, 0.3f, 0.95f, pkEntity, 0);
                m_pkMouseSpring->FUN_00cbb1b0(m_fMaxRelativeForce);
                m_pkWorld->FUN_00c97370(m_pkMouseSpring);
            }
        }
    }
    return true;
}
}  // namespace fnv_00d66d00

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float x, y, z, w;
} __m128;

typedef __m128 FourFloatVector;

struct Derived;

struct Stream
{
    void FUN_00ddac60(void* vec);
    int FUN_00dd8fe0(void* buf, int size, int count);
    char* GetStreamResult(char* buf);
};

struct Base2
{
    void* vptr;
    int unk04;
    Stream* stream;
    Derived* getDerived()
    {
        return (Derived*)((char*)this - 8);
    }
    void FUN_00d66e10(unsigned char type);
};

struct Derived
{
    void FUN_00d66c10();
    void DispatchToChild(void* vec);
    void PickEntity(char* str, int a, int b, void* vec);
};

struct Buf4
{
    char b0, b1, b2, b3;
};

// @fnv 0x00d66e10
void Base2::FUN_00d66e10(unsigned char type)
{
    Buf4 buf;
    union
    {
        FourFloatVector b1_vec;
        struct
        {
            int pair0;
            int pair1;
            FourFloatVector vec;
        } b0;
    } u;

    switch (type)
    {
    case 0xb2:
        getDerived()->FUN_00d66c10();
        return;
    case 0xb1: {
        stream->FUN_00ddac60(&u.b1_vec);
        if (stream->GetStreamResult(&buf.b1)[0])
        {
            getDerived()->DispatchToChild(&u.b1_vec);
        }
        return;
    }
    case 0xb0: {
        stream->FUN_00ddac60(&u.b0.vec);
        stream->FUN_00dd8fe0(&u.b0.pair0, 8, 1);
        if (stream->GetStreamResult(&buf.b2)[0])
        {
            getDerived()->PickEntity(&buf.b3, u.b0.pair0, u.b0.pair1, &u.b0.vec);
        }
        break;
    }
    default:
        break;
    }
}

namespace fnv_00d66f00 {
struct FnvCpu_FUN_00d66f00_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d66f00_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d66f00_CpuAllocator* allocator;
};
FnvCpu_FUN_00d66f00_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d66f00_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00d66cd0();
    FnvCpu_FUN_00d66f00_CpuObject* FUN_00d66f00(unsigned int flags);
};
// Calls FUN_00d66cd0, then if flags bit 0 is set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00d66f00
FnvCpu_FUN_00d66f00_CpuObject* FnvCpu_FUN_00d66f00_CpuObject::FUN_00d66f00(unsigned int flags)
{
    FUN_00d66cd0();
    if (flags & 1)
    {
        FnvCpu_FUN_00d66f00_CpuAllocatorHolder* holder = FUN_00c85750();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00d66f00

class UnkCall
{
  public:
    void FUN_00c9c1d0();
};

class hkReferencedObject
{
  public:
    void removeReference();
};

class hkpEntityD66C : public hkReferencedObject
{
  public:
    int unk00;
    int unk04;
    int m_pOwningWorld;
    int unk0C, unk10, unk14;
    UnkCall* m_18;
};

class hkpWorldD66C
{
  public:
    void DispatchOrQueue(hkpEntityD66C* pkEntity);
};

class FUN_00d66c10_cls
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    hkpWorldD66C* m_pOwningWorld;
    hkpEntityD66C* m_pEntity;

    void FUN_00d66c10();
};

// @fnv 0x00d66c10
void FUN_00d66c10_cls::FUN_00d66c10()
{
    if (m_pEntity)
    {
        if (m_pEntity->m_pOwningWorld)
        {
            m_pOwningWorld->DispatchOrQueue(m_pEntity);
            m_pEntity->m_18->FUN_00c9c1d0();
            m_pEntity->removeReference();
        }
        else
        {
            m_pEntity->removeReference();
        }
        m_pEntity = 0;
    }
    m_pOwningWorld = 0;
}

namespace FUN_00ddcc60 {
class hkpWorldViewerBase
{
  public:
    virtual ~hkpWorldViewerBase();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
}

class hkpWorldDeletionListenerD66C
{
  public:
    virtual void WorldDeletedCallback(void* pkWorld) = 0;
    int unk04, unk08, unk0C, unk10, unk14;
};

class hkpActionListenerD66C
{
  public:
    virtual void ActionAddedCallback(void* pkAction) = 0;
};

namespace FUN_00d66cd0 {
class hkpMousePickingViewer : public FUN_00ddcc60::hkpWorldViewerBase,
                              public hkpWorldDeletionListenerD66C,
                              public hkpActionListenerD66C
{
  public:
    virtual ~hkpMousePickingViewer();
    virtual void WorldDeletedCallback(void* pkWorld);
    virtual void ActionAddedCallback(void* pkAction);

    void FUN_00d66c10() throw();
};

// @fnv 0x00d66cd0
hkpMousePickingViewer::~hkpMousePickingViewer()
{
    FUN_00d66c10();
}
}

namespace fnv_00d66ee0 {
// sub ecx,0x20; jmp target: MSVC adjustor thunk for the secondary base (PrimaryBase is 0x20 bytes).
struct PrimaryBase
{
    virtual void FUN_00d66ee0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct SecondaryBase
{
    virtual void FUN_00d66ee0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66ee0
    virtual void FUN_00d66ee0();
};

Derived::Derived()
{}
}  // namespace fnv_00d66ee0

namespace fnv_00d66ef0 {
// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00d66ef0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d66ef0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66ef0
    virtual void FUN_00d66ef0();
};

Derived::Derived()
{}
}  // namespace fnv_00d66ef0
