
// src/havok/physics/utilities/actions/reorient/hkpreorientaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/reorient/hkpreorientaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpReorientAction.h"

class hkMemoryAllocatorE445
{
  public:
    virtual ~hkMemoryAllocatorE445() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterE445
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE445* m_pStreamAllocator;
    hkMemoryAllocatorE445& heap()
    {
        return *m_pStreamAllocator;
    }
    static hkMemoryRouterE445& GetMonitorStream();
};
extern "C" hkMemoryRouterE445& __cdecl FUN_00c85750();
inline hkMemoryRouterE445& hkMemoryRouterE445::GetMonitorStream()
{
    return FUN_00c85750();
}

class hkpPhantom;

template <class T> struct hkArrayE445
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

class hkReferencedObjectE445
{
  public:
    virtual ~hkReferencedObjectE445() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void* operator new(unsigned int uiSize)
    {
        hkReferencedObjectE445* pkObj = static_cast<hkReferencedObjectE445*>(
            hkMemoryRouterE445::GetMonitorStream().heap().AllocateMemoryBlock(uiSize));
        pkObj->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return pkObj;
    }
    static void operator delete(void* p) throw();
};

class FUN_00e444f0 : public hkReferencedObjectE445
{
  public:
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    hkUlong m_ulUserData;
    hkStringPtr m_name;
    hkpEntity* m_pEntity;
    int unk1C;
    hkVector4 m_vRotationAxis;
    hkVector4 m_vUpAxis;
    hkReal m_fSpringStrength;
    hkReal m_fMotorDamping;
    int unk48;
    int unk4C;

    FUN_00e444f0(hkpEntity* entity, const hkVector4& rotationAxis, const hkVector4& upAxis, hkReal strength,
                 hkReal damping) throw();
    virtual ~FUN_00e444f0() throw();
};

class hkpReorientActionE445
{
  public:
    int unk00;
    int unk04;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    hkUlong m_ulUserData;
    hkStringPtr m_name;
    hkpEntity* m_pEntity;
    int unk1C;
    hkVector4 m_vRotationAxis;
    hkVector4 m_vUpAxis;
    hkReal m_fSpringStrength;
    hkReal m_fMotorDamping;

    FUN_00e444f0* Clone(const hkArrayE445<hkpEntity*>& newEntities, const hkArrayE445<hkpPhantom*>& newPhantoms) const;
};
// Returns null unless there is one entity and no phantoms; else builds a FUN_00e444f0 for it from this action's fields and user data.
// @fnv 0x00e44540
FUN_00e444f0* hkpReorientActionE445::Clone(const hkArrayE445<hkpEntity*>& newEntities,
                                           const hkArrayE445<hkpPhantom*>& newPhantoms) const
{
    if (newEntities.GetLogicalSize() != 1)
        return 0;
    if (newPhantoms.GetLogicalSize() != 0)
        return 0;
    FUN_00e444f0* ra = new FUN_00e444f0(newEntities[0], m_vRotationAxis, m_vUpAxis, m_fSpringStrength, m_fMotorDamping);
    ra->m_ulUserData = m_ulUserData;
    return ra;
}

#include <xmmintrin.h>
namespace fnv_00e444f0 {
struct FNVAction
{
    const void* vtable;
    unsigned short memoryFlags;
    short referenceCount;
    void* world;
    void* island;
    unsigned int userData;
    const char* name;
    void* entity;
    void FUN_00d2b260(void* entity, unsigned int option);
};
extern int DAT_010e6834;
struct FUN_00e444f0 : FNVAction
{
    int unk1c;
    __m128 rotationAxis;
    __m128 upAxis;
    float strength;
    float damping;
    FUN_00e444f0(void* entity, const __m128* rotation, const __m128* up, float strengthValue, float dampingValue);
};
// Initializes the action by calling FUN_00d2b260, setting the vtable, and copying rotation, up, strength, and damping values from the arguments.
// @fnv 0x00e444f0
FUN_00e444f0::FUN_00e444f0(void* apEntity, const __m128* apRotation, const __m128* apUp, float afStrength,
                           float afDamping)
{
    FUN_00d2b260(apEntity, 0);
    vtable = &DAT_010e6834;
    rotationAxis = *apRotation;
    upAxis = *apUp;
    strength = afStrength;
    damping = afDamping;
}
}  // namespace fnv_00e444f0
