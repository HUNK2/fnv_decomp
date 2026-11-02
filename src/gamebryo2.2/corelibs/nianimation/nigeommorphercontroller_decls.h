// gamebryo2.2/corelibs/nianimation/nigeommorphercontroller_decls.h: declares NiGeomMorpherController, InterpItem, MorphData
#ifndef FNV_NIGEOMMORPHERCONTROLLER_DECLS_H
#define FNV_NIGEOMMORPHERCONTROLLER_DECLS_H

#include "NiRefObject.h"
#include "MemoryManager.h"
extern MemoryManager g_memoryManager;
class NiGeomMorpherController
{
  public:
    struct InterpItem
    {
        NiRefObject* m_spControllerInterpolator;
        float m_fWeight;
        __declspec(nothrow) InterpItem();
        __declspec(nothrow) __forceinline ~InterpItem()
        {
            if (m_spControllerInterpolator)
                m_spControllerInterpolator->DecRefCount();
        }
        static void* operator new[](unsigned int size) throw()
        {
            return g_memoryManager.Allocate(size);
        }
        static void operator delete[](void* p) throw()
        {
            g_memoryManager.Deallocate(p);
        }
    };
    unsigned char padding[0x38];
    struct MorphData
    {
        unsigned char padding[8];
        unsigned int m_uiNumTargets;
    };
    MorphData* m_spMorphTargetData;
    InterpItem* m_pInterpolatorItems;
    void ClearInterpolatorArray();
};
#endif
