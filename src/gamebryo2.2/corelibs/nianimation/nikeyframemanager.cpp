// gamebryo2.2/corelibs/nianimation/nikeyframemanager.cpp: NiGeomMorpherController (1 function)

#include "nikeyframemanager_decls.h"

// @fnv 0x008d3ed0
unsigned int NiGeomMorpherController::GetNumTargets() const
{
    return m_spMorphTargetData.operator->()
               ? reinterpret_cast<GlobalObject_00869f00*>(m_spMorphTargetData.operator->())->GetSize()
               : 0;
}
