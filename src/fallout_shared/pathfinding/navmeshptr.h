
#include "navmeshptr_decls.h"

// @fnv 0x00690860
bool NavMeshInfo::AcquireNavMesh(NavMeshPtr& out)
{
    ProcessWithScopedRef(out, m_pLocationNavMesh);
    return m_pLocationNavMesh != 0;
}
