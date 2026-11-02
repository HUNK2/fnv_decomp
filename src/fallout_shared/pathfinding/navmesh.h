// fallout_shared/pathfinding/navmesh.h: declares CenterCalculation
#ifndef FNV_NAVMESH_H
#define FNV_NAVMESH_H

#include "navmesh_decls.h"
// @fnv 0x00558220
NiPoint3 NavMesh::GetNavMeshData(unsigned short m_usTriangleID)
{
    struct CenterCalculation
    {
        NiPoint3 Center;
        NavMeshTriangle* pTriangle;
    } calculation;
    calculation.pTriangle = GetTriangle(m_usTriangleID);
    calculation.Center = FUN_0068f0a0(calculation.pTriangle->FUN_005582d0(0));
    calculation.Center += FUN_0068f0a0(calculation.pTriangle->FUN_005582d0(1));
    calculation.Center += FUN_0068f0a0(calculation.pTriangle->FUN_005582d0(2));
    calculation.Center *= DAT_0102f200;
    return calculation.Center;
}
#endif
