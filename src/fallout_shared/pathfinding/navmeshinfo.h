
#include "navmeshinfo_decls.h"
// @fnv 0x0069ad00
bool NavMeshInfo::ResolveNavMesh(NavMeshPtr& out)
{
    if (FUN_0068f320())
        return false;
    ProcessWithScopedRef(out, m_pLocationNavMesh);
    return ((const NiPointer<NiNode>&)out).operator->() ? true : false;
}
// @fnv 0x006dd6a0
bool PathingLocation::HasValidTriangle()
{
    if (data == 0)
        return false;
    if (!data->HasNonZeroAtOffset54())
        return false;
    if (triangle == 0xffff)
        return false;
    return true;
}
