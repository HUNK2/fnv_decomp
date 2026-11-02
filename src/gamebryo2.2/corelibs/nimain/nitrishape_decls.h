// gamebryo2.2/corelibs/nimain/nitrishape_decls.h: declares NiMemObject, NiTriBasedGeomData, NiTriShapeData, NiGeometry, NiTriBasedGeom and more
#ifndef NITRISHAPE_DECLS_H
#define NITRISHAPE_DECLS_H


#include "nitrishape_types_NiGeometryData__DataFlags.h"

class NiPoint2;
class NiPoint3;
class RgbaColor;
class NiTriShape;

class NiMemObject
{
  public:
    static void* operator new(unsigned int) throw();
};

class NiTriBasedGeomData : public NiMemObject
{
  public:
    unsigned char geometryFields[68];
};

class NiTriShapeData : public NiTriBasedGeomData
{
  public:
    unsigned char shapeFields[20];
    NiTriShapeData(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short,
                   NiGeometryData__DataFlags, unsigned short, unsigned short*) throw();
};

class NiGeometry
{
  public:
    virtual ~NiGeometry();
    unsigned char geometryFields[192];
};

class NiTriBasedGeom : public NiGeometry
{
  public:
    NiTriBasedGeom(NiTriBasedGeomData*) throw();
};

class NiTriShape : public NiTriBasedGeom
{
  public:
    NiTriShape(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short, NiGeometryData__DataFlags,
               unsigned short, unsigned short*);
    virtual ~NiTriShape();
};

FNV_STATIC_ASSERT(sizeof(NiTriShapeData) == 0x58);
FNV_STATIC_ASSERT(sizeof(NiTriShape) == 0xc4);

#endif
