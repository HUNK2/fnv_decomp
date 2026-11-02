// gamebryo2.2/corelibs/nimain/nitrishapedata_decls.h: declares MemoryManager, NiTriBasedGeomData, NiTriShapeData
#ifndef NITRISHAPEDATA_DECLS_H
#define NITRISHAPEDATA_DECLS_H


#include "nitrishapedata_types_NiGeometryData__DataFlags.h"

class NiPoint2;
class NiPoint3;
class RgbaColor;
class NiStream;

class MemoryManager
{
  public:
    void* Allocate(unsigned int);
};

extern "C" void* __cdecl NiMalloc(unsigned int);
extern "C" void __cdecl vector_constructor_iterator(void*, unsigned int, int, void*);
#pragma comment(linker, "/alternatename:_vector_constructor_iterator=??_H@YGXPAXIHP6EPAX0@Z@Z")

class NiTriBasedGeomData
{
  public:
    unsigned char baseFields[64];
    unsigned short m_usTriangles;
    unsigned char basePadding[2];

    NiTriBasedGeomData(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short,
                       NiGeometryData__DataFlags, unsigned short);
    void LoadBinary(NiStream&);
    void SaveBinary(NiStream&);
};

class NiTriShapeData : public NiTriBasedGeomData
{
  public:
    unsigned int m_uiTriListLength;
    unsigned short* m_pusTriList;
    void* m_pkSharedNormalArray;
    unsigned short m_usSharedNormalCount;
    unsigned char shapePadding[2];
    void* m_pkSharedNormalArrayMemoryBlock;

    NiTriShapeData(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short,
                   NiGeometryData__DataFlags, unsigned short, unsigned short*);
    void LoadBinary(NiStream&);
    void SaveBinary(NiStream&);
};

#endif
