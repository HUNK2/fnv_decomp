#pragma once

#include "hkIArchive.h"

class hkVector4;
class hkTransform;
class hkGeometry;
class hkDisplayGeometry;

class hkDisplaySerializeIStream : public hkIArchive
{
public:
    virtual ~hkDisplaySerializeIStream();

    void hkIArchive_readArrayGeneric(void* buf, int elemSize, int numElems);
    void FUN_00ddac80(hkTransform* target);
    void FUN_00ddac80(hkTransform& t);
    void readQuadVector4(hkVector4& v);
    void readGeometry(hkGeometry* geom);
    void FUN_00ddada0(hkDisplayGeometry*& geometry);

    signed char readInt8();
    int readInt32();
    float readFloat32();
    void ReadVector4(hkVector4& v);
    void ReadTransform(hkTransform& t);
    void ReadGeometry(hkGeometry* g);
};

