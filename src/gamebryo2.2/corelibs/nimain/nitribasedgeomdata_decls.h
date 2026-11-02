// gamebryo2.2/corelibs/nimain/nitribasedgeomdata_decls.h: declares NiGeometryData, NiTriBasedGeomData
#ifndef NITRIBASEDGEOMDATA_DECLS_H
#define NITRIBASEDGEOMDATA_DECLS_H

class NiStream;
class NiPoint3;
class NiPoint2;
class RgbaColor;
enum NiGeometryData__DataFlags
{
    DataFlags_None = 0
};
class NiGeometryData
{
  public:
    NiGeometryData(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short,
                   NiGeometryData__DataFlags);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    void LoadBinary(NiStream&);
    void SaveBinary(NiStream&);
    unsigned char data[60];
};
class NiTriBasedGeomData : public NiGeometryData
{
  public:
    NiTriBasedGeomData(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short,
                       NiGeometryData__DataFlags, unsigned short);
    void GetTriangles(unsigned short&, const unsigned short*&, const unsigned short*&, unsigned int&);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    void LoadBinary(NiStream&);
    void SaveBinary(NiStream&);
    unsigned short m_usTriangles;
};
#endif
