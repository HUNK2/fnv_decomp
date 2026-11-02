
// src/havok/physics/utilities/actions/reorient/hkpreorientaction_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/actions/reorient/hkpreorientaction.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

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
#include <xmmintrin.h>
