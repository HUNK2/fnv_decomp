// gamebryo2.2/corelibs/nimain/niobjectnet_bhk_decls.h: declares bhkConvexShape, bhkSphereShape
#ifndef NIOBJECTNET_BHK_DECLS_H
#define NIOBJECTNET_BHK_DECLS_H
class bhkConvexShape
{
  public:
    bhkConvexShape();
    virtual ~bhkConvexShape();
};
class bhkSphereShape : public bhkConvexShape
{
  public:
    bhkSphereShape(float, bool);
    virtual ~bhkSphereShape();
    void FUN_0056ea00(float);
};
extern unsigned int DAT_01268280;
float __cdecl FUN_004a3e90(float);
#endif
