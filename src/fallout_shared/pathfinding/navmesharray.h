// fallout_shared/pathfinding/navmesharray.h: declares NavMeshCollection
#ifndef NAVMESHARRAY_H
#define NAVMESHARRAY_H

#include "navmesharray_decls.h"
class NavMeshCollection
{
  public:
    GlobalObject_00869f00 m_kGlobalObject;
    NavMeshPtr GetNavMeshAt(unsigned int index);
};
// @fnv 0x00464f60
NavMeshPtr NavMeshCollection::GetNavMeshAt(unsigned int index)
{
    if (index >= m_kGlobalObject.GetSize())
        return MakeNavMeshPointer(0);
    return reinterpret_cast<const NavMeshPtr&>(m_kGlobalObject.GetAt(index));
}
#endif
