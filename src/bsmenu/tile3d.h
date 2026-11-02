// bsmenu/tile3d.h: declares Tile3D
#ifndef FNV_TILE3D_H
#define FNV_TILE3D_H
#include "tile3d_decls.h"
class Tile3D
{
  public:
    virtual void vfn_00();
    GlobalObject_0048f200 children;
    Tile3D_Traits traits;
    BSStringT<char> name;
    Tile3D* parent;
    NiPointer<NiAVObject> model;
    unsigned int flags;
    bool needsUpdate;
    Tile3D();
    int GetType();
};
// @fnv 0x00a0bdc0
int Tile3D::GetType()
{
    return 0x388;
}
// @fnv 0x00709860
Tile3D::Tile3D() : traits(16, 0), model(0)
{
    model = 0;
    parent = 0;
    flags = 0;
    needsUpdate = false;
}
#endif
