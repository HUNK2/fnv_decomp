// gamebryo2.2/corelibs/nimain/nitribasedgeom_decls.h: declares NiObject, BSTextureSet, NiAVObject, NiPropertyState, NiGeometry and more
class NiObject
{
  public:
    NiObject();
    void* vtable;
    unsigned int refs;
};
class BSTextureSet : public NiObject
{
  public:
    BSTextureSet();
};
extern void* BSTextureSet_vtable[];
class NiAVObject
{
  public:
    NiAVObject();
    virtual void GeometrySlot();
    char pad[0x98];
};
class NiPropertyState
{
  public:
    NiPropertyState();
    char props[0x1c];
};
class NiGeometry : public NiAVObject
{
  public:
    NiGeometry();
    virtual void GeometrySlot();
    NiPropertyState properties;
    void* model;
    void* skin;
    void* shader;
};
extern void* NiGeometry_vtable[];

class NiTriBasedGeom
{
  public:
    char padding[0xac];
    unsigned short flags;
    void SetBitfield(unsigned short, unsigned short, unsigned short);
};
