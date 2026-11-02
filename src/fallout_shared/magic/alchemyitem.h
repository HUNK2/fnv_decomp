// fallout_shared/magic/alchemyitem.h: declares bhkHingeConstraint, BSFile
#ifndef ALCHEMYITEM_H
#define ALCHEMYITEM_H

#include "alchemyitem_decls.h"
class bhkHingeConstraint
{
  public:
    unsigned int GetInstanceSize();
};
class BSFile
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    char padding04[0x150];
    char* fileName;
    char padding158[0x10];
    char* cachedFileName;
    char* FileName() const;
    char* FileName();
};
// @fnv 0x00402b00
unsigned int bhkHingeConstraint::GetInstanceSize()
{
    return 20;
}
// @fnv 0x00afc0c0
char* BSFile::FileName() const
{
    return cachedFileName;
}
// @fnv 0x00aff610
char* BSFile::FileName()
{
    if (!fileName)
        vfn_28();
    return fileName;
}
#endif
