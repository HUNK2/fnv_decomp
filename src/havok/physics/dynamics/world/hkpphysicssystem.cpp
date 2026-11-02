
// src/havok/physics/dynamics/world/hkpphysicssystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpphysicssystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPhysicsSystem.h"

struct DDCC60World
{
    void removeReference();
};

struct FUN_00d06090_Class
{
    void* vftable;
    int padding0;
    DDCC60World** refs0;
    int count0;
    int padding1;
    DDCC60World** refs1;
    int count1;
    int padding2;
    DDCC60World** refs2;
    int count2;
    int padding3;
    DDCC60World** refs3;
    int count3;

    void ReleaseAllReferences();
};

// Calls removeReference on each non-null entry of the four reference arrays, then resets their counts to zero.
// @fnv 0x00d06090
void FUN_00d06090_Class::ReleaseAllReferences()
{
    int count = count0;
    for (int i = 0; i < count; ++i)
    {
        if (refs0[i])
        {
            refs0[i]->removeReference();
        }
    }
    count0 = 0;

    count = count3;
    for (int i = 0; i < count; ++i)
    {
        if (refs3[i])
        {
            refs3[i]->removeReference();
        }
    }
    count3 = 0;

    count = count1;
    for (int i = 0; i < count; ++i)
    {
        if (refs1[i])
        {
            refs1[i]->removeReference();
        }
    }
    count1 = 0;

    count = count2;
    for (int i = 0; i < count; ++i)
    {
        if (refs2[i])
        {
            refs2[i]->removeReference();
        }
    }
    count2 = 0;
}

extern int DAT_010cce28;
extern int _DAT_0102e388;

struct MemoryAllocator
{
    virtual void FUN_00() = 0;
    virtual void FUN_01() = 0;
    virtual void FUN_02() = 0;
    virtual void FUN_03() = 0;
    virtual void Free(void* data, unsigned int size) = 0;
};

struct MemoryRouter
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0C;
    MemoryAllocator* m_p10;
};

MemoryRouter* _D1A0E0GetMemoryRouter();

struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};

struct FUN_00d06640_class
{
    struct Buffer
    {
        void* volatile m_pData;
        unsigned int m_uCount;
        unsigned int m_uCapacity;
    };

    void* volatile m_pVtable;
    void* m_pPadding;
    Buffer m_pWorkingSet[4];
    S_00d49310_Lock m_lock;

    void ReleaseAllReferences();
    void Destroy();
};

// @fnv 0x00d06640
void FUN_00d06640_class::Destroy()
{
    unsigned int highBit = 0x80000000u;

    m_pVtable = &DAT_010cce28;
    ReleaseAllReferences();
    m_lock.~S_00d49310_Lock();

    MemoryRouter* router = _D1A0E0GetMemoryRouter();
    MemoryAllocator* allocator = router->m_p10;
    unsigned int capacity = m_pWorkingSet[3].m_uCapacity;
    m_pWorkingSet[3].m_uCount = 0;
    if (!(capacity & highBit))
        allocator->Free(m_pWorkingSet[3].m_pData, (capacity & 0x3FFFFFFFu) * 4u);
    m_pWorkingSet[3].m_pData = 0;
    m_pWorkingSet[3].m_uCapacity = highBit;

    router = _D1A0E0GetMemoryRouter();
    allocator = router->m_p10;
    capacity = m_pWorkingSet[2].m_uCapacity;
    m_pWorkingSet[2].m_uCount = 0;
    if (!(capacity & highBit))
        allocator->Free(m_pWorkingSet[2].m_pData, (capacity & 0x3FFFFFFFu) * 4u);
    m_pWorkingSet[2].m_pData = 0;
    m_pWorkingSet[2].m_uCapacity = highBit;

    router = _D1A0E0GetMemoryRouter();
    allocator = router->m_p10;
    capacity = m_pWorkingSet[1].m_uCapacity;
    m_pWorkingSet[1].m_uCount = 0;
    if (!(capacity & highBit))
        allocator->Free(m_pWorkingSet[1].m_pData, (capacity & 0x3FFFFFFFu) * 4u);
    m_pWorkingSet[1].m_pData = 0;
    m_pWorkingSet[1].m_uCapacity = highBit;

    router = _D1A0E0GetMemoryRouter();
    allocator = router->m_p10;
    capacity = m_pWorkingSet[0].m_uCapacity;
    m_pWorkingSet[0].m_uCount = 0;
    if (!(capacity & highBit))
        allocator->Free(m_pWorkingSet[0].m_pData, (capacity & 0x3FFFFFFFu) * 4u);
    m_pWorkingSet[0].m_pData = 0;
    m_pWorkingSet[0].m_uCapacity = highBit;

    m_pVtable = &_DAT_0102e388;
}

// @fnv 0x00cb0020
void __stdcall FUN_00cb0020(unsigned char* output)
{
    *output = 0;
}

inline void memMoveD062(void* pvDst, const void* pvSrc, int iNumBytes)
{
    for (int i = 0; i < iNumBytes; i += 4)
        *(int*)((char*)pvDst + i) = *(const int*)((const char*)pvSrc + i);
}

template <typename T> struct hkArrayD062
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
    void removeAtAndCopy(int iIndex)
    {
        m_iElementCount--;
        memMoveD062(m_data + iIndex, m_data + iIndex + 1, (m_iElementCount - iIndex) * sizeof(T));
    }
};

class hkObjD062
{
  public:
    int unk00[0xb];
    hkArrayD062<void*> m_entries;

    void RemoveNullEntries();
};

// Iterates m_entries backwards and removes every entry that is null via removeAtAndCopy.
// @fnv 0x00d06230
void hkObjD062::RemoveNullEntries()
{
    for (int i = m_entries.GetLogicalSize() - 1; i >= 0; i--)
    {
        if (m_entries[i] == 0)
            m_entries.removeAtAndCopy(i);
    }
}

typedef unsigned int Size64;
inline void* __cdecl operator new(Size64, void* p)
{
    return p;
}
struct Shape64
{
    void __thiscall FUN_00c90510();
};
typedef Shape64* ShapePtr64;
struct Array64
{
    ShapePtr64* items;
    int size;
    unsigned int capacityAndFlags;
};
struct Router64
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* allocator;
};
Router64* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* allocator, Array64* array, int elementSize);
struct Container64
{
    void* vtable;
    void* pad04;
    Array64 array;
    void __thiscall AddShape(Shape64* object);
};
// Calls FUN_00c90510 on object, then appends object to array, growing it via ResizeAudioStream when full.
// @fnv 0x00d064a0
void Container64::AddShape(Shape64* pShape)
{
    if (pShape)
    {
        pShape->FUN_00c90510();
        Array64* pArray = &array;
        Router64* router = FUN_00c85750();
        if (pArray->size == (pArray->capacityAndFlags & 0x3fffffff))
        {
            ResizeAudioStream(router->allocator, pArray, 4);
        }
        ShapePtr64* pSlot = pArray->items + pArray->size;
        __assume(pSlot != 0);
        new (pSlot) ShapePtr64(pShape);
        ++pArray->size;
    }
}

struct FUN_00cb0b80
{
    char* m_kStringBuffer;
    FUN_00cb0b80(const char* s) throw();
};

template <class T> struct hkArrayD065
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayD065() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkRefObjD065
{
  public:
    virtual ~hkRefObjD065() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjD065()
    {
        m_sReferenceCount = 1;
    }
};

class FUN_00d065e0 : public hkRefObjD065
{
  public:
    hkArrayD065<void*> m_kPointA;
    hkArrayD065<void*> m_kPointB;
    hkArrayD065<void*> m_iThirdValue;
    hkArrayD065<void*> m_iFourthElementInteger;
    FUN_00cb0b80 m_name;
    int m_3c;
    bool m_40;

    FUN_00d065e0() throw();
    virtual ~FUN_00d065e0() throw();
};

// Initializes the object's name, m_3c to 0 and m_40 to true, leaving the four arrays default-constructed.
// @fnv 0x00d065e0
FUN_00d065e0::FUN_00d065e0() throw() : m_name(0), m_3c(0), m_40(true)
{}

namespace fnv_00d06c00 {
struct FnvCpu_FUN_00d06c00_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d06c00_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d06c00_CpuAllocator* allocator;
};
FnvCpu_FUN_00d06c00_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d06c00_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void Destroy();
    FnvCpu_FUN_00d06c00_CpuObject* FUN_00d06c00(unsigned int flags);
};
// @fnv 0x00d06c00
FnvCpu_FUN_00d06c00_CpuObject* FnvCpu_FUN_00d06c00_CpuObject::FUN_00d06c00(unsigned int flags)
{
    Destroy();
    if (flags & 1)
    {
        FnvCpu_FUN_00d06c00_CpuAllocatorHolder* holder = FUN_00c85750();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00d06c00

class hkMemoryAllocatorD29
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
struct hkMemoryRouterD29
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD29* m_pStreamAllocator;
    hkMemoryAllocatorD29& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterD29& __cdecl GetMemoryRouterD29() throw();

template <class T> __forceinline void copyD29(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}
template <class T> class hkArrayD29
{
  public:
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline hkArrayD29& operator=(const hkArrayD29& a)
    {
        hkMemoryAllocatorD29& kAlloc = GetMemoryRouterD29().heap();
        if (getCapacity() < a.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int iNumBytes = a.m_iElementCount * sizeof(T);
            m_data = static_cast<T*>(kAlloc.AllocateBufferWithSize(iNumBytes));
            m_iCapacityState = iNumBytes / (int)sizeof(T);
        }
        m_iElementCount = a.m_iElementCount;
        copyD29(m_data, a.m_data, m_iElementCount);
        return *this;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkStringPtrD29
{
  public:
    hkStringPtrD29& operator=(const hkStringPtrD29& kOther);
    const char* m_pcText;
};

class hkpRigidBodyD29;
class hkpConstraintInstanceD29;
class hkpActionD29;
class hkpPhantomD29;

class hkpPhysicsSystemD29
{
  public:
    virtual ~hkpPhysicsSystemD29();
    void FUN_00d06290(const hkpPhysicsSystemD29& kOther);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkArrayD29<hkpRigidBodyD29*> m_ppRigidBodies;
    hkArrayD29<hkpConstraintInstanceD29*> m_ppConstraints;
    hkArrayD29<hkpActionD29*> m_ppActions;
    hkArrayD29<hkpPhantomD29*> m_kPhantoms;
    hkStringPtrD29 m_name;
    unsigned long m_ulUserData;
    bool m_bSlotEnabled;
};

// Copies the rigid body, constraint, action, phantom, name, user data, and slot enabled state arrays and fields from kOther into this physics system.
// @fnv 0x00d06290
void hkpPhysicsSystemD29::FUN_00d06290(const hkpPhysicsSystemD29& kOther)
{
    m_ppRigidBodies = kOther.m_ppRigidBodies;
    m_kPhantoms = kOther.m_kPhantoms;
    m_ppConstraints = kOther.m_ppConstraints;
    m_ppActions = kOther.m_ppActions;
    m_name = kOther.m_name;
    m_ulUserData = kOther.m_ulUserData;
    m_bSlotEnabled = kOther.m_bSlotEnabled;
}

template <int SIZE> __forceinline void memCpyOneAlignedD064(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterD064
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterD064 {
extern "C" hkMemoryRouterD064& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayD064
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
        hkMemoryRouterD064& router = hkRouterD064::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedD064<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class hkShapeD064
{
  public:
    void FUN_00c90510();
};

class hkOwnerD064
{
  public:
    int unk00[11];
    hkArrayD064<hkShapeD064*> m_shapes;

    void FUN_00d064f0(hkShapeD064* shape);
};

// If shape is non-null, calls shape->FUN_00c90510() and appends it to m_shapes via AddBack.
// @fnv 0x00d064f0
void hkOwnerD064::FUN_00d064f0(hkShapeD064* shape)
{
    if (shape)
    {
        shape->FUN_00c90510();
        m_shapes.AddBack(shape);
    }
}

template <int SIZE> __forceinline void memCpyOneAlignedXd06540(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXd06540
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXd06540 {
extern "C" hkMemoryRouterXd06540& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayXd06540
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
        hkMemoryRouterXd06540& router = hkRouterXd06540::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXd06540<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class hkShapeXd06540
{
  public:
    void FUN_00c90510();
};

class hkOwnerXd06540
{
  public:
    int unk00[5];
    hkArrayXd06540<hkShapeXd06540*> m_shapes;

    void FUN_00d06540(hkShapeXd06540* shape);
};

// If shape is non-null, calls shape->FUN_00c90510() and appends shape to m_shapes via AddBack.
// @fnv 0x00d06540
void hkOwnerXd06540::FUN_00d06540(hkShapeXd06540* shape)
{
    if (shape)
    {
        shape->FUN_00c90510();
        m_shapes.AddBack(shape);
    }
}

template <int SIZE> __forceinline void memCpyOneAlignedXd06590(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXd06590
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXd06590 {
extern "C" hkMemoryRouterXd06590& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayXd06590
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
        hkMemoryRouterXd06590& router = hkRouterXd06590::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXd06590<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class hkShapeXd06590
{
  public:
    void FUN_00c90510();
};

class hkOwnerXd06590
{
  public:
    int unk00[8];
    hkArrayXd06590<hkShapeXd06590*> m_shapes;

    void FUN_00d06590(hkShapeXd06590* shape);
};

// If shape is non-null, calls shape->FUN_00c90510() and appends it to m_shapes via AddBack.
// @fnv 0x00d06590
void hkOwnerXd06590::FUN_00d06590(hkShapeXd06590* shape)
{
    if (shape)
    {
        shape->FUN_00c90510();
        m_shapes.AddBack(shape);
    }
}

#include <xmmintrin.h>
__declspec(align(16)) struct AlignedVector4
{
    float x, y, z, w;
    __forceinline AlignedVector4& operator=(const AlignedVector4& o)
    {
        *(__m128*)this = *(__m128*)&o;
        return *this;
    }
};

__declspec(align(16)) struct AlignedTransform
{
    AlignedVector4 m_kColumn0;
    AlignedVector4 m_kColumn1;
    AlignedVector4 m_kColumn2;
    AlignedVector4 m_vTranslation;

    AlignedTransform()
    {}
    AlignedTransform(const AlignedTransform& o)
    {
        m_kColumn0 = o.m_kColumn0;
        m_kColumn1 = o.m_kColumn1;
        m_kColumn2 = o.m_kColumn2;
        m_vTranslation = o.m_vTranslation;
    }

    void FUN_00cb23e0(const hkTransform* other);
};

struct FUN_00ca8890_Class
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC;
    int unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC;
    hkTransform m_kMotionTransform;

    void FUN_00ca8890(const AlignedTransform* t);
};

struct FUN_00cf30f0_Class
{
    void FUN_00cf30f0(const hkTransform* t);
};

void FUN_00d05df0(void* phantom, const hkTransform* t);

struct PhysicsSystemWrapper : public hkpPhysicsSystem
{
    void ApplyMotionTransform(const hkTransform* a2);
};

// Applies a2 to every rigid body, constraint, and phantom in the physics system.
// @fnv 0x00d05f60
void PhysicsSystemWrapper::ApplyMotionTransform(const hkTransform* a2)
{
    for (int i = 0; i < m_ppRigidBodies.m_iElementCount; ++i)
    {
        AlignedTransform t1;
        *(hkVector4*)&t1.m_kColumn0 = a2->m_rotation.m_kColumn0;
        *(hkVector4*)&t1.m_kColumn1 = a2->m_rotation.m_kColumn1;
        *(hkVector4*)&t1.m_kColumn2 = a2->m_rotation.m_kColumn2;
        *(hkVector4*)&t1.m_vTranslation = a2->m_vTranslation;

        AlignedTransform t2 = t1;

        t2.FUN_00cb23e0(&((FUN_00ca8890_Class*)m_ppRigidBodies.m_data[i])->m_kMotionTransform);
        ((FUN_00ca8890_Class*)m_ppRigidBodies.m_data[i])->FUN_00ca8890(&t2);
    }
    for (int i = 0; i < m_ppConstraints.m_iElementCount; ++i)
    {
        ((FUN_00cf30f0_Class*)m_ppConstraints.m_data[i])->FUN_00cf30f0(a2);
    }
    for (int i = 0; i < m_kPhantoms.m_iElementCount; ++i)
    {
        FUN_00d05df0(m_kPhantoms.m_data[i], a2);
    }
}

struct ReferenceBody
{
    void FUN_00c905b0();
};
struct BodyCollection
{
    unsigned int unk00, unk04;
    ReferenceBody** data;
    int count;
    unsigned int capacityFlags;
    void FUN_00d06130(unsigned int index);
};
// Calls FUN_00c905b0 on the element at index, decrements count, and shifts the last element into the slot if index is not the last.
// @fnv 0x00d06130
void BodyCollection::FUN_00d06130(unsigned int index)
{
    data[index]->FUN_00c905b0();
    --count;
    if (count != index)
    {
        ReferenceBody** dst = data + index;
        ReferenceBody* const* src = data + count;
        for (int n = 0; n < sizeof(ReferenceBody*); n += sizeof(ReferenceBody*))
            *(ReferenceBody**)((char*)dst + n) = *(ReferenceBody* const*)((const char*)src + n);
    }
}

struct hkRefD061
{
    void FUN_00c905b0();
};
struct OwnerD061
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    hkRefD061** refs3;
    int count3;
    unsigned int capacityFlags3;
    void FUN_00d06170(int index);
};
// Calls FUN_00c905b0 on refs3[index], decrements count3, and moves the last element into the slot if index is not the last.
// @fnv 0x00d06170
void OwnerD061::FUN_00d06170(int index)
{
    refs3[index]->FUN_00c905b0();
    --count3;
    if (count3 != index)
    {
        hkRefD061** dst = refs3 + index;
        hkRefD061* const* src = refs3 + count3;
        for (int n = 0; n < sizeof(hkRefD061*); n += sizeof(hkRefD061*))
            *(hkRefD061**)((char*)dst + n) = *(hkRefD061* const*)((const char*)src + n);
    }
}

struct RefObj
{
    void __thiscall FUN_00c905b0();
};

inline void memCpy4_d061(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_d061
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_d061(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

struct FUN_00d061b0_Class
{
    void* vftable;
    int unk04, unk08, unk0C, unk10;
    hkArray_d061<RefObj*> m_refs;
    void FUN_00d061b0(int index);
};

// Calls FUN_00c905b0 on m_refs[index], then removes that entry from m_refs.
// @fnv 0x00d061b0
void FUN_00d061b0_Class::FUN_00d061b0(int index)
{
    m_refs[index]->FUN_00c905b0();
    m_refs.removeAt(index);
}

namespace fnv_00d061f0 {
struct RefObj
{
    void __thiscall FUN_00c905b0();
};

inline void memCpy4_d061(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_d061
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_d061(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

struct FUN_00d061f0_Class
{
    void* vftable;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkArray_d061<RefObj*> m_refs;
    void FUN_00d061f0(int index);
};

// Calls FUN_00c905b0 on the RefObj at index, then removes that entry from m_refs.
// @fnv 0x00d061f0
void FUN_00d061f0_Class::FUN_00d061f0(int index)
{
    m_refs[index]->FUN_00c905b0();
    m_refs.removeAt(index);
}
}  // namespace fnv_00d061f0

extern float DAT_0104da48;
extern __m128 DAT_011b1bd0;

struct __declspec(align(16)) TerrainVec
{
    __m128 q;
    float& lane(int i)
    {
        return reinterpret_cast<float*>(&q)[i];
    }
    const float& lane(int i) const
    {
        return reinterpret_cast<const float*>(&q)[i];
    }
    TerrainVec& operator=(const TerrainVec& b)
    {
        q = b.q;
        return *this;
    }
    void set(float x, float y, float z, float w)
    {
        q = _mm_setr_ps(x, y, z, w);
    }
    void multiply(const TerrainVec& a, const TerrainVec& b)
    {
        q = _mm_mul_ps(a.q, b.q);
    }
    void add(const TerrainVec& a, const TerrainVec& b)
    {
        q = _mm_add_ps(a.q, b.q);
    }
    void multiply(const TerrainVec& b)
    {
        q = _mm_mul_ps(q, b.q);
    }
    void add(const TerrainVec& b)
    {
        q = _mm_add_ps(q, b.q);
    }
    __m128 sum3() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q);
        return _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), xy);
    }
    __forceinline void normalize()
    {
        __m128 half = _mm_set_ss(0.5f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 zero = _mm_set_ss(0.0f);
        TerrainVec square;
        square.q = _mm_mul_ps(q, q);
        __m128 len = square.sum3();
        __m128 eq = _mm_cmpeq_ss(len, zero);
        __m128 estimate = _mm_rsqrt_ss(len);
        __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, estimate), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, estimate), estimate)));
        __m128 inv = _mm_andnot_ps(eq, refined);
        q = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), q);
    }
};
union GridCodes
{
    unsigned short lanes[4];
    unsigned __int64 packed;
};
__forceinline void encodePoint(const TerrainVec& point, const TerrainVec& offset, const TerrainVec& scale,
                               GridCodes& codes)
{
    TerrainVec value;
    value.add(point, offset);
    value.q = _mm_mul_ps(value.q, _mm_load_ps((const float*)&scale));
    TerrainVec bias;
    bias.q = DAT_011b1bd0;
    value.add(bias);
    union Packed
    {
        __m128 q;
        unsigned int words[4];
    } raw;
    raw.q = value.q;
    codes.lanes[0] = (unsigned short)(raw.words[0] >> 6);
    codes.lanes[1] = (unsigned short)(raw.words[1] >> 6);
    codes.lanes[2] = (unsigned short)(raw.words[2] >> 6);
    codes.lanes[3] = (unsigned short)(raw.words[3] >> 6);
}
struct TerrainInput
{
    const TerrainVec* spheres;
    int count;
};
struct TerrainFlip
{
    char value;
    TerrainFlip()
    {}
    TerrainFlip(bool b) : value(b)
    {}
};
struct TerrainBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual float sample(int x, int z) const;
    virtual TerrainFlip flipped() const;
    int refInfo;
    unsigned int userData;
    unsigned int typeInfo;
    int width;
    int depth;
    float minHeight;
    char projection;
};
struct TerrainShape : TerrainBase
{
    TerrainVec worldScale;
    TerrainVec gridScale;
    TerrainVec floorOffset;
    void EvaluateSpheres(const TerrainInput& input, TerrainVec* output) const;
};
// For each input sphere, computes terrain height and normal at its grid position, then stores the signed distance to the sphere in the output vector.
// @fnv 0x00cb01f0
void TerrainShape::EvaluateSpheres(const TerrainInput& input, TerrainVec* output) const
{
    const TerrainVec* sphere = input.spheres;
    TerrainVec fallback;
    fallback.set(0.0f, 1.0f, 0.0f, DAT_0104da48);
    for (int remaining = input.count - 1; remaining >= 0; ++output, ++sphere, --remaining)
    {
        *output = fallback;
        TerrainVec position;
        position.q = _mm_mul_ps(_mm_load_ps((const float*)sphere), _mm_load_ps((const float*)&gridScale));
        GridCodes codes;
        encodePoint(*sphere, floorOffset, gridScale, codes);
        int x = codes.lanes[0];
        int z = codes.lanes[2];
        if (x >= width - 1 || z >= depth - 1)
            continue;
        float fx = position.lane(0) - float(x);
        float afDepth = position.lane(2) - float(z);
        float height;
        float vertexHeight;
        int vertexX;
        TerrainFlip flip = flipped();
        if (flip.value)
        {
            float a = sample(x, z);
            vertexHeight = a;
            vertexX = x;
            float b = sample(x + 1, z + 1);
            if (fx > afDepth)
            {
                float c = sample(x + 1, z);
                float sx = c - a;
                float sz = b - c;
                height = a + afDepth * sz + fx * sx;
                output->lane(0) = -sx;
                output->lane(2) = -sz;
            }
            else
            {
                float c = sample(x, z + 1);
                float sx = b - c;
                float sz = c - a;
                height = a + afDepth * sz + fx * sx;
                output->lane(0) = -sx;
                output->lane(2) = -sz;
            }
        }
        else
        {
            float a = sample(x + 1, z);
            vertexHeight = a;
            vertexX = x + 1;
            float b = sample(x, z + 1);
            if (fx + afDepth > 1.0)
            {
                float c = sample(x + 1, z + 1);
                float sx = c - b;
                float sz = c - a;
                height = a + afDepth * sz + (fx - 1.0) * sx;
                output->lane(0) = -sx;
                output->lane(2) = -sz;
            }
            else
            {
                float c = sample(x, z);
                float sx = a - c;
                float sz = b - c;
                height = c + afDepth * sz + fx * sx;
                output->lane(0) = -sx;
                output->lane(2) = -sz;
            }
        }
        output->q = _mm_mul_ps(output->q, gridScale.q);
        output->normalize();
        float distance;
        if (!projection)
        {
            distance = (position.lane(1) - height) * worldScale.lane(1) - sphere->lane(3);
        }
        else
        {
            TerrainVec vertex;
            vertex.set(float(vertexX), vertexHeight, float(z), 0.0f);
            TerrainVec delta;
            delta.q = _mm_sub_ps(position.q, vertex.q);
            delta.q = _mm_mul_ps(delta.q, worldScale.q);
            TerrainVec product;
            product.q = _mm_mul_ps(output->q, delta.q);
            float dot;
            _mm_store_ss(&dot, product.sum3());
            distance = dot - sphere->lane(3);
        }
        output->lane(3) = distance;
    }
}

namespace fnv_00d06720 {
#include <intrin.h>

class hkMemoryAllocatorD
{
  public:
    virtual ~hkMemoryAllocatorD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterD
{
    void* m_pvStack;
    void* m_pvStackStart;
    void* m_pvStackEnd;
    hkMemoryAllocatorD* m_pkTemp;
    hkMemoryAllocatorD* m_pkHeap;
    hkMemoryAllocatorD& heap() throw()
    {
        return *m_pkHeap;
    }
};
hkMemoryRouterD& __cdecl FUN_00c85750() throw();

struct hkArrayUtilD
{
    static void __cdecl FUN_00c908c0(hkMemoryAllocatorD& kAlloc, void* apvArray, int iNumElements,
                                     int iSizeElement) throw();
};

template <typename T> class hkArrayBaseD
{
  public:
    hkArrayBaseD() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int GetLogicalSize() const throw()
    {
        return m_iElementCount;
    }
    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i) throw()
    {
        return m_data[i];
    }
    const T& operator[](int i) const throw()
    {
        return m_data[i];
    }
    int indexOf(const T& t, int iStart = 0, int iEnd = -1) const throw()
    {
        if (iEnd < 0)
            iEnd = m_iElementCount;
        for (int i = iStart; i < iEnd; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void GrowArrayCapacity(hkMemoryAllocatorD& kAlloc, int n) throw()
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCapCur = 2 * iCap;
            int iNewSize = (n < iCapCur) ? iCapCur : n;
            hkArrayUtilD::FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    void _setSize(hkMemoryAllocatorD& kAlloc, int n) throw()
    {
        GrowArrayCapacity(kAlloc, n);
        m_iElementCount = n;
    }
    void _clearAndDeallocate(hkMemoryAllocatorD& kAlloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct hkContainerHeapAllocatorD
{
    struct Allocator
    {
        hkMemoryAllocatorD* get(const void*) const throw()
        {
            return &FUN_00c85750().heap();
        }
    };
};

template <typename T> class hkArrayD : public hkArrayBaseD<T>
{
  public:
    typedef hkContainerHeapAllocatorD::Allocator AllocatorType;
    hkArrayD() throw()
    {}
    ~hkArrayD() throw()
    {
        releaseMemory();
    }
    void releaseMemory() throw()
    {
        this->_clearAndDeallocate(*AllocatorType().get(this));
    }
    void SetSizeAndGrow(int n) throw()
    {
        this->_setSize(*AllocatorType().get(this), n);
    }
};

class hkBaseObjectD
{
  public:
    virtual ~hkBaseObjectD() throw();
};
class hkReferencedObjectD : public hkBaseObjectD
{
  public:
    void* operator new(unsigned int uiBytes) throw()
    {
        hkReferencedObjectD* b = static_cast<hkReferencedObjectD*>(FUN_00c85750().heap().AllocateMemoryBlock(uiBytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(uiBytes);
        return b;
    }
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpEntityD : public hkReferencedObjectD
{
};
class hkpRigidBodyD : public hkpEntityD
{
  public:
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual hkpRigidBodyD* clone() const throw();
};
class hkpPhantomD : public hkReferencedObjectD
{
  public:
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1c() throw();
    virtual void v20() throw();
    virtual void v24() throw();
    virtual void v28() throw();
    virtual hkpPhantomD* clone() const throw();
};

class hkBoolD
{
  public:
    hkBoolD(bool b) throw()
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkpConstraintInstanceD : public hkReferencedObjectD
{
  public:
    hkpRigidBodyD* getRigidBody() const throw()
    {
        return m_pEntityA;
    }
    hkpRigidBodyD* getRigidBodyB() const throw()
    {
        return m_pEntityB;
    }
    hkBoolD FUN_00cf2fb0() const throw();
    hkpConstraintInstanceD* FUN_00cf3fa0(hkpRigidBodyD* pk, hkpRigidBodyD* pkB, int eMode) const throw();

    void* m_pOwnerObject;
    void* m_data;
    void* m_pConstraintModifier;
    hkpRigidBodyD* m_pEntityA;
    hkpRigidBodyD* m_pEntityB;
};

class hkpActionD : public hkReferencedObjectD
{
  public:
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void GetEntities(hkArrayD<hkpEntityD*>& kEntitiesOut) throw();
    virtual void getPhantomArray(hkArrayD<hkpPhantomD*>& kPhantomsOut) throw();
    virtual void v18() throw();
    virtual hkpActionD* clone(const hkArrayD<hkpEntityD*>& kNewEntities,
                              const hkArrayD<hkpPhantomD*>& kNewPhantoms) const throw();
};

class FUN_00cb0c30
{
  public:
    FUN_00cb0c30& operator=(const FUN_00cb0c30& kOther) throw();
    const char* m_pcText;
};

class FUN_00d065e0 : public hkReferencedObjectD
{
  public:
    FUN_00d065e0() throw();
    FUN_00d065e0* FUN_00d06720() const throw();

    hkArrayD<hkpRigidBodyD*> m_ppRigidBodies;
    hkArrayD<hkpConstraintInstanceD*> m_ppConstraints;
    hkArrayD<hkpActionD*> m_ppActions;
    hkArrayD<hkpPhantomD*> m_kPhantoms;
    FUN_00cb0c30 m_name;
    unsigned long m_ulUserData;
    hkBoolD m_bSlotEnabled;
};

// @fnv 0x00d06720
FUN_00d065e0* FUN_00d065e0::FUN_00d06720() const throw()
{
    FUN_00d065e0* newSystem = new FUN_00d065e0();

    newSystem->m_name = m_name;
    newSystem->m_ulUserData = m_ulUserData;
    newSystem->m_bSlotEnabled = m_bSlotEnabled;

    newSystem->m_ppRigidBodies.SetSizeAndGrow(m_ppRigidBodies.GetLogicalSize());
    newSystem->m_kPhantoms.SetSizeAndGrow(m_kPhantoms.GetLogicalSize());
    newSystem->m_ppConstraints.SetSizeAndGrow(m_ppConstraints.GetLogicalSize());
    newSystem->m_ppActions.SetSizeAndGrow(m_ppActions.GetLogicalSize());

    int i;
    for (i = 0; i < m_ppRigidBodies.GetLogicalSize(); i++)
    {
        newSystem->m_ppRigidBodies[i] = m_ppRigidBodies[i]->clone();
    }

    for (i = 0; i < m_kPhantoms.GetLogicalSize(); i++)
    {
        newSystem->m_kPhantoms[i] = m_kPhantoms[i]->clone();
    }

    for (i = 0; i < m_ppConstraints.GetLogicalSize(); i++)
    {
        hkpConstraintInstanceD* constraint = m_ppConstraints[i];
        hkpRigidBodyD* pNewRigidBodyA = newSystem->m_ppRigidBodies[m_ppRigidBodies.indexOf(constraint->getRigidBody())];
        hkpRigidBodyD* pNewRigidBodyB =
            constraint->FUN_00cf2fb0()
                ? 0
                : newSystem->m_ppRigidBodies[m_ppRigidBodies.indexOf(constraint->getRigidBodyB())];
        newSystem->m_ppConstraints[i] = constraint->FUN_00cf3fa0(pNewRigidBodyA, pNewRigidBodyB, 0);
    }

    for (i = 0; i < m_ppActions.GetLogicalSize(); i++)
    {
        hkpActionD* action = m_ppActions[i];
        if (!action)
        {
            newSystem->m_ppActions[i] = 0;
        }
        else
        {
            hkArrayD<hkpEntityD*> oldEntities;
            _ReadWriteBarrier();
            action->GetEntities(oldEntities);
            hkArrayD<hkpEntityD*> newEntities;
            int numEntities = oldEntities.GetLogicalSize();
            newEntities.SetSizeAndGrow(numEntities);
            for (int j = 0; j < numEntities; j++)
            {
                int index = m_ppRigidBodies.indexOf(static_cast<hkpRigidBodyD*>(oldEntities[j]));
                newEntities[j] = newSystem->m_ppRigidBodies[index];
            }

            hkpActionD* actionCur = *(hkpActionD* volatile*)&action;
            _ReadWriteBarrier();
            hkArrayD<hkpPhantomD*> oldPhantoms;
            _ReadWriteBarrier();
            actionCur->getPhantomArray(oldPhantoms);
            hkArrayD<hkpPhantomD*> newPhantoms;
            int numPhantoms = oldPhantoms.GetLogicalSize();
            newPhantoms.SetSizeAndGrow(numPhantoms);
            for (int k = 0; k < numPhantoms; k++)
            {
                hkpPhantomD* phantom = oldPhantoms[k];
                int index = m_kPhantoms.indexOf(phantom);
                newPhantoms[k] = newSystem->m_kPhantoms[index];
            }

            newSystem->m_ppActions[i] = action->clone(newEntities, newPhantoms);
        }
    }

    return newSystem;
}
}  // namespace fnv_00d06720
