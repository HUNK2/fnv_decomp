#ifndef BSSCRAPARRAY_H
#define BSSCRAPARRAY_H

#include "bsscraparray_decls.h"
template <>
// @fnv 0x0087d1b0
BSScrapArray<NiPointer<NiAVObject>, 1024>::BSScrapArray()
{
    vtable = &DAT_01084074;
    m_pAllocator = FUN_00401020()->GetGeneralAllocator();
    FUN_00822860(0, false);
}
template <>
// @fnv 0x009789e0
BSScrapArray<Animation*, 1024>::BSScrapArray()
{
    vtable = &DAT_0108c228;
    m_pAllocator = FUN_00401020()->GetGeneralAllocator();
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(this)->FUN_006b3eb0(0, false);
}
#endif
