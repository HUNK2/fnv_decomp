// bsmenu/tile3d_decls.h: declares Tile3D_Traits
#ifndef FNV_TILE3D_DECLS_H
#define FNV_TILE3D_DECLS_H
class GlobalObject_0048f200
{
  public:
    GlobalObject_0048f200();
    ~GlobalObject_0048f200();
    char data[12];
};
class Tile3D_Traits
{
  public:
    Tile3D_Traits(int, int);
    ~Tile3D_Traits();
    char data[16];
};
template <class T> class BSStringT
{
  public:
    BSStringT();
    ~BSStringT();
    char data[8];
};
class NiAVObject;
template <class T> class NiPointer
{
  public:
    NiPointer(T*);
    ~NiPointer();
    NiPointer& operator=(T*);
    T* ptr;
};
#endif
