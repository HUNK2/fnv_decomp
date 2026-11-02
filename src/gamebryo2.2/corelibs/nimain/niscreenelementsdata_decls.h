// gamebryo2.2/corelibs/nimain/niscreenelementsdata_decls.h: declares NiPoint2, NiBound, NiGeometryData, NiTriBasedGeomData, NiTriShapeData and more
#ifndef FNV_NISCREENELEMENTSDATA_DECLS_H
#define FNV_NISCREENELEMENTSDATA_DECLS_H

#include "layout_support.h"
#include "NiObject.h"
#include "NiPoint3.h"
#include "layout_support.h"
class NiAdditionalGeometryData;
class NiBound;
class RgbaColor;
class NiGeometryData;
class NiGeometryData__RendererData;
class NiPoint2
{
  public:
    float x, y;
};
class NiScreenElementsData;
class NiScreenElementsData__Polygon;
class NiTriBasedGeomData;
class NiTriShapeData;
class NiTriShapeData__SNAMemBlock;
class NiTriShapeData__SharedNormalArray;
#pragma pack(push, 4)
class NiBound
{
  public:
    NiPoint3 m_kCenter;  // +0x0, 12 bytes
    union
    {                          // overlapping CodeView storage
        float m_fBoundRadius;  // +0xC, 4 bytes
        int m_iRadius;         // +0xC, 4 bytes
    };
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBound) == 16);
FNV_STATIC_ASSERT(offsetof(NiBound, m_kCenter) == 0);
FNV_STATIC_ASSERT(offsetof(NiBound, m_fBoundRadius) == 12);
FNV_STATIC_ASSERT(offsetof(NiBound, m_iRadius) == 12);
#pragma pack(push, 4)
class NiGeometryData : public NiObject
{
  public:
    void SetDirtyFlags(unsigned int);
    // Unnamed PC texture-set accessor; see manifest binding.
    NiPoint2* FUN_00a66960(unsigned short);
    NiPoint3* GetVertices()
    {
        return m_pkVertex;
    }
    unsigned short m_usVertices;                                 // +0x8, 2 bytes
    unsigned short m_usGeometryFlags;                            // +0xA, 2 bytes
    unsigned short m_usTrianglePoints;                           // +0xC, 2 bytes
    unsigned short m_usDirtyFlags;                               // +0xE, 2 bytes
    NiBound m_kBound;                                            // +0x10, 16 bytes
    NiPoint3* m_pkVertex;                                        // +0x20, 4 bytes
    NiPoint3* m_pkNormal;                                        // +0x24, 4 bytes
    RgbaColor* m_pkColor;                                        // +0x28, 4 bytes
    NiPoint2* m_pkTexture;                                       // +0x2C, 4 bytes
    NiPointer<NiAdditionalGeometryData> m_spAdditionalGeomData;  // +0x30, 4 bytes
    NiGeometryData__RendererData* m_pkGeometryRendererData;      // +0x34, 4 bytes
    unsigned char m_ucKeepFlags;                                 // +0x38, 1 bytes
    unsigned char m_ucCompressFlags;                             // +0x39, 1 bytes
    bool m_bIsDynamic;                                           // +0x3A, 1 bytes
    bool m_bBoundDirty;                                          // +0x3B, 1 bytes
    bool m_bVerticesDirty;                                       // +0x3C, 1 bytes
    unsigned char layoutPadding3D[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiGeometryData) == 64);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_usVertices) == 8);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_usGeometryFlags) == 10);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_usTrianglePoints) == 12);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_usDirtyFlags) == 14);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_kBound) == 16);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkVertex) == 32);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkNormal) == 36);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkColor) == 40);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkTexture) == 44);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_spAdditionalGeomData) == 48);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkGeometryRendererData) == 52);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_ucKeepFlags) == 56);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_ucCompressFlags) == 57);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_bIsDynamic) == 58);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_bBoundDirty) == 59);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_bVerticesDirty) == 60);
#pragma pack(push, 4)
class NiTriBasedGeomData : public NiGeometryData
{
  public:
    unsigned short m_usTriangles;  // +0x40, 2 bytes
    unsigned char layoutPadding42[2];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTriBasedGeomData) == 68);
FNV_STATIC_ASSERT(offsetof(NiTriBasedGeomData, m_usTriangles) == 64);
#pragma pack(push, 4)
class NiTriShapeData : public NiTriBasedGeomData
{
  public:
    unsigned int m_uiTriListLength;                            // +0x44, 4 bytes
    unsigned short* m_pusTriList;                              // +0x48, 4 bytes
    NiTriShapeData__SharedNormalArray* m_pkSharedNormalArray;  // +0x4C, 4 bytes
    unsigned short m_usSharedNormalCount;                      // +0x50, 2 bytes
    unsigned char layoutPadding52[2];
    NiTriShapeData__SNAMemBlock* m_pkSharedNormalArrayMemoryBlock;  // +0x54, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTriShapeData) == 88);
FNV_STATIC_ASSERT(offsetof(NiTriShapeData, m_uiTriListLength) == 68);
FNV_STATIC_ASSERT(offsetof(NiTriShapeData, m_pusTriList) == 72);
FNV_STATIC_ASSERT(offsetof(NiTriShapeData, m_pkSharedNormalArray) == 76);
FNV_STATIC_ASSERT(offsetof(NiTriShapeData, m_usSharedNormalCount) == 80);
FNV_STATIC_ASSERT(offsetof(NiTriShapeData, m_pkSharedNormalArrayMemoryBlock) == 84);
#pragma pack(push, 4)
class NiScreenElementsData__Polygon
{
  public:
    unsigned short m_usVertexCount;
    unsigned short m_usVertexOffset;
    unsigned short m_usTriangleCount;
    unsigned short m_usTriangleIndexOffset;
};
FNV_STATIC_ASSERT(sizeof(NiScreenElementsData__Polygon) == 8);
class NiScreenElementsData : public NiTriShapeData
{
  public:
    bool SetRectangle(int, float, float, float, float);
    bool SetRectangleBounds(int, unsigned short, float, float, float, float);
    NiScreenElementsData__Polygon* m_akPolygon;  // +0x58, 4 bytes
    unsigned short* m_ausPIndexer;               // +0x5C, 4 bytes
    unsigned short m_usMaxPQuantity;             // +0x60, 2 bytes
    unsigned short m_usPGrowBy;                  // +0x62, 2 bytes
    unsigned short m_usPQuantity;                // +0x64, 2 bytes
    unsigned short m_usMaxVQuantity;             // +0x66, 2 bytes
    unsigned short m_usVGrowBy;                  // +0x68, 2 bytes
    unsigned short m_usMaxIQuantity;             // +0x6A, 2 bytes
    unsigned short m_usIGrowBy;                  // +0x6C, 2 bytes
    bool m_bGeometryInitialized;                 // +0x6E, 1 bytes
    unsigned char layoutPadding6F[1];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiScreenElementsData) == 112);
FNV_STATIC_ASSERT(offsetof(NiScreenElementsData, m_akPolygon) == 88);
FNV_STATIC_ASSERT(offsetof(NiScreenElementsData, m_ausPIndexer) == 92);
FNV_STATIC_ASSERT(offsetof(NiScreenElementsData, m_usMaxPQuantity) == 96);
FNV_STATIC_ASSERT(offsetof(NiScreenElementsData, m_usPGrowBy) == 98);
FNV_STATIC_ASSERT(offsetof(NiScreenElementsData, m_usPQuantity) == 100);
FNV_STATIC_ASSERT(offsetof(NiScreenElementsData, m_usMaxVQuantity) == 102);
FNV_STATIC_ASSERT(offsetof(NiScreenElementsData, m_usVGrowBy) == 104);
FNV_STATIC_ASSERT(offsetof(NiScreenElementsData, m_usMaxIQuantity) == 106);
FNV_STATIC_ASSERT(offsetof(NiScreenElementsData, m_usIGrowBy) == 108);
FNV_STATIC_ASSERT(offsetof(NiScreenElementsData, m_bGeometryInitialized) == 110);
#endif
