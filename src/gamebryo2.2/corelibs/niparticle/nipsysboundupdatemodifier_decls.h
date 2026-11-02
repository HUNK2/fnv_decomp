// gamebryo2.2/corelibs/niparticle/nipsysboundupdatemodifier_decls.h: declares NiBound, NiPSysModifier, NiPSysBoundUpdateModifier
#ifndef FNV_NIPSYSBOUNDUPDATEMODIFIER_DECLS_H
#define FNV_NIPSYSBOUNDUPDATEMODIFIER_DECLS_H

#include "NiFixedString.h"
#include "NiObject.h"
#include "NiPoint3.h"
#include "MemoryManager.h"

extern MemoryManager g_memoryManager;
extern "C" const NiPoint3 NiPoint3_ZERO;
class NiParticleSystem;

class NiBound
{
  public:
    NiPoint3 m_kCenter;
    union
    {
        float m_fBoundRadius;
        int m_iRadius;
    };
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    void SetCenterAndRadius(const NiPoint3& center, float radius)
    {
        m_kCenter = center;
        m_fBoundRadius = radius;
    }
};

class NiPSysModifier : public NiObject
{
  public:
    NiFixedString m_kName;
    unsigned int m_uiUpdateOrder;
    NiParticleSystem* m_pkTarget;
    bool m_bModifierActive;
};

class NiPSysBoundUpdateModifier : public NiPSysModifier
{
  public:
    short m_usUpdateSkip;
    unsigned short m_usUpdateSkipCounter;
    NiBound* m_pkBounds;
    // The PC body reads a full stack slot and narrows both the stored skip and count.
    void SetUpdateSkipCounter(int iUpdateSkip);
};

FNV_STATIC_ASSERT(sizeof(NiBound) == 0x10);
FNV_STATIC_ASSERT(sizeof(NiPSysModifier) == 0x18);
FNV_STATIC_ASSERT(sizeof(NiPSysBoundUpdateModifier) == 0x20);
FNV_STATIC_ASSERT(offsetof(NiPSysBoundUpdateModifier, m_usUpdateSkip) == 0x18);
FNV_STATIC_ASSERT(offsetof(NiPSysBoundUpdateModifier, m_pkBounds) == 0x1C);
#endif
