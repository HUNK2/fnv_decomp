// corrected to the evidenced PC layouts. See EVIDENCE.md. No helper bodies.
#ifndef FNV_FONT_PRIVATE_GEOMETRY_TYPES_H
#define FNV_FONT_PRIVATE_GEOMETRY_TYPES_H

#include "font_types.h"
#define FONT_GEOMETRY_JOIN_(a, b) a##b
#define FONT_GEOMETRY_JOIN(a, b) FONT_GEOMETRY_JOIN_(a, b)
#define FONT_GEOMETRY_ASSERT(e) typedef char FONT_GEOMETRY_JOIN(font_geometry_assert_, __LINE__)[(e) ? 1 : -1]
FONT_GEOMETRY_ASSERT(sizeof(void*) == 4);
FONT_GEOMETRY_ASSERT(sizeof(unsigned short) == 2);
class NiNode;
class NiCollisionObject;
class FourComponentFloatVector;
class NiProperty;
class NiTimeController;
class NiExtraData;
class NiAdditionalGeometryData;
class NiGeometryData;
class NiGeometryData__RendererData;
class NiSkinInstance;
class NiShader;
class NiTriShapeData__SharedNormalArray;
class NiTriShapeData__SNAMemBlock;
class NiTListItem_NiPointer_NiProperty___;

class NiMemObject
{
  public:
};
FONT_GEOMETRY_ASSERT(sizeof(NiMemObject) == 0x1);

class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;  // +0x4
    virtual ~NiRefObject();
    virtual void DeleteThis();
};
FONT_GEOMETRY_ASSERT(sizeof(NiRefObject) == 0x8);
FONT_GEOMETRY_ASSERT(offsetof(NiRefObject, m_uiRefCount) == 0x4);

class NiObject : public NiRefObject
{
  public:
};
FONT_GEOMETRY_ASSERT(sizeof(NiObject) == 0x8);

class NiFixedString
{
  public:
    char* m_kHandle;  // +0x0
};
FONT_GEOMETRY_ASSERT(sizeof(NiFixedString) == 0x4);
FONT_GEOMETRY_ASSERT(offsetof(NiFixedString, m_kHandle) == 0x0);

class NiObjectNET : public NiObject
{
  public:
    NiFixedString m_kName;                       // +0x8
    NiPointer<NiTimeController> m_pControllers;  // +0xC
    NiExtraData** m_ppExtraData;                 // +0x10
    unsigned short m_usExtraDataCount;           // +0x14
    unsigned short m_usMaxSize;                  // +0x16
};
FONT_GEOMETRY_ASSERT(sizeof(NiObjectNET) == 0x18);
FONT_GEOMETRY_ASSERT(offsetof(NiObjectNET, m_kName) == 0x8);
FONT_GEOMETRY_ASSERT(offsetof(NiObjectNET, m_pControllers) == 0xC);
FONT_GEOMETRY_ASSERT(offsetof(NiObjectNET, m_ppExtraData) == 0x10);
FONT_GEOMETRY_ASSERT(offsetof(NiObjectNET, m_usExtraDataCount) == 0x14);
FONT_GEOMETRY_ASSERT(offsetof(NiObjectNET, m_usMaxSize) == 0x16);

class NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
};
FONT_GEOMETRY_ASSERT(sizeof(NiPoint3) == 0xC);
FONT_GEOMETRY_ASSERT(offsetof(NiPoint3, x) == 0x0);
FONT_GEOMETRY_ASSERT(offsetof(NiPoint3, y) == 0x4);
FONT_GEOMETRY_ASSERT(offsetof(NiPoint3, z) == 0x8);

class RgbaColor
{
  public:
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    float a;  // +0xC, 4 bytes
};
FONT_GEOMETRY_ASSERT(sizeof(RgbaColor) == 16);
FONT_GEOMETRY_ASSERT(offsetof(RgbaColor, r) == 0);
FONT_GEOMETRY_ASSERT(offsetof(RgbaColor, g) == 4);
FONT_GEOMETRY_ASSERT(offsetof(RgbaColor, b) == 8);
FONT_GEOMETRY_ASSERT(offsetof(RgbaColor, a) == 12);

class TextureCoordinate
{
  public:
    float fTextureCoordinateU;  // +0x0, 4 bytes
    float fV;                   // +0x4, 4 bytes
};
FONT_GEOMETRY_ASSERT(sizeof(TextureCoordinate) == 8);
FONT_GEOMETRY_ASSERT(offsetof(TextureCoordinate, fTextureCoordinateU) == 0);
FONT_GEOMETRY_ASSERT(offsetof(TextureCoordinate, fV) == 4);

class FontCharacterInfo
{
  public:
    int m_iCharacterCode;           // +0x0, 4 bytes
    TextureCoordinate pMapping[4];  // +0x4, 32 bytes
    float m_fGlyphWidthInPixels;                   // +0x24, 4 bytes
    float m_fGlyphExtent;                  // +0x28, 4 bytes
    float m_fHorizontalAdvance;     // +0x2C, 4 bytes
    float m_fHorizontalSpacing;     // +0x30, 4 bytes
    float m_fVerticalOffset;        // +0x34, 4 bytes
};
FONT_GEOMETRY_ASSERT(sizeof(FontCharacterInfo) == 56);
FONT_GEOMETRY_ASSERT(offsetof(FontCharacterInfo, m_iCharacterCode) == 0);
FONT_GEOMETRY_ASSERT(offsetof(FontCharacterInfo, pMapping) == 4);
FONT_GEOMETRY_ASSERT(offsetof(FontCharacterInfo, m_fGlyphWidthInPixels) == 36);
FONT_GEOMETRY_ASSERT(offsetof(FontCharacterInfo, m_fGlyphExtent) == 40);
FONT_GEOMETRY_ASSERT(offsetof(FontCharacterInfo, m_fHorizontalAdvance) == 44);
FONT_GEOMETRY_ASSERT(offsetof(FontCharacterInfo, m_fHorizontalSpacing) == 48);
FONT_GEOMETRY_ASSERT(offsetof(FontCharacterInfo, m_fVerticalOffset) == 52);

// PC NiPoint2 coordinates: JohnnyGuitar NiPoint2.hpp declarations only.
class NiPoint2
{
  public:
    float x;
    float y;
};
FONT_GEOMETRY_ASSERT(sizeof(NiPoint2) == 8);
FONT_GEOMETRY_ASSERT(offsetof(NiPoint2, x) == 0);
FONT_GEOMETRY_ASSERT(offsetof(NiPoint2, y) == 4);

class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
FONT_GEOMETRY_ASSERT(sizeof(NiTAbstractPoolAllocator_unsigned_int_) == 1);

class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
FONT_GEOMETRY_ASSERT(sizeof(NiTPointerAllocator_unsigned_int_) == 1);

class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
FONT_GEOMETRY_ASSERT(
    sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator) == 4);
FONT_GEOMETRY_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator,
                              m_uiCount) == 0);

class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
    NiTListItem_NiPointer_NiProperty___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_NiPointer_NiProperty___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
};
FONT_GEOMETRY_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___) == 12);
FONT_GEOMETRY_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___, m_pkHead) == 0);
FONT_GEOMETRY_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___, m_pkTail) == 4);
FONT_GEOMETRY_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___, m_kItemCount) ==
                     8);

class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
};
FONT_GEOMETRY_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___) == 12);

class NiTPointerList_NiPointer_NiProperty___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
};
FONT_GEOMETRY_ASSERT(sizeof(NiTPointerList_NiPointer_NiProperty___) == 12);

class ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];  // PC: +0x0, 36 bytes
};
FONT_GEOMETRY_ASSERT(sizeof(ThreeByThreeMatrix) == 36);
FONT_GEOMETRY_ASSERT(offsetof(ThreeByThreeMatrix, m_afEntries) == 0);

class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;  // PC: +0x0, 36 bytes
    NiPoint3 m_kTranslation;   // PC: +0x24, 12 bytes
    float m_fScale;            // PC: +0x30, 4 bytes
};
FONT_GEOMETRY_ASSERT(sizeof(NiTransform) == 52);
FONT_GEOMETRY_ASSERT(offsetof(NiTransform, m_kOrientation) == 0);
FONT_GEOMETRY_ASSERT(offsetof(NiTransform, m_kTranslation) == 36);
FONT_GEOMETRY_ASSERT(offsetof(NiTransform, m_fScale) == 48);

class NiAVObject : public NiObjectNET
{
  public:
    NiNode* m_pParentNode;                                    // +0x18, 4 bytes
    NiPointer<NiCollisionObject> m_spCollisionObject;         // +0x1C, 4 bytes
    FourComponentFloatVector* m_kWorldBound;                  // +0x20, 4 bytes
    NiTPointerList_NiPointer_NiProperty___ SceneGraphObject;  // +0x24, 12 bytes
    unsigned int m_uiObjectFlags;                                    // +0x30, 4 bytes
    NiTransform m_kLocalTransform;                            // PC: +0x34, 52 bytes
    NiTransform m_kWorldSpaceTransform;                                     // PC: +0x68, 52 bytes
};
FONT_GEOMETRY_ASSERT(sizeof(NiAVObject) == 156);
FONT_GEOMETRY_ASSERT(offsetof(NiAVObject, m_pParentNode) == 24);
FONT_GEOMETRY_ASSERT(offsetof(NiAVObject, m_spCollisionObject) == 28);
FONT_GEOMETRY_ASSERT(offsetof(NiAVObject, m_kWorldBound) == 32);
FONT_GEOMETRY_ASSERT(offsetof(NiAVObject, SceneGraphObject) == 36);
FONT_GEOMETRY_ASSERT(offsetof(NiAVObject, m_uiObjectFlags) == 48);
FONT_GEOMETRY_ASSERT(offsetof(NiAVObject, m_kLocalTransform) == 52);
FONT_GEOMETRY_ASSERT(offsetof(NiAVObject, m_kWorldSpaceTransform) == 104);

class NiPropertyState
{
  public:
    NiPointer<NiProperty> m_spProperties[7];  // +0x0, 28 bytes
};
FONT_GEOMETRY_ASSERT(sizeof(NiPropertyState) == 28);
FONT_GEOMETRY_ASSERT(offsetof(NiPropertyState, m_spProperties) == 0);

class NiGeometry : public NiAVObject
{
  public:
    NiPropertyState m_kPropertyState;                // +0x9C, 28 bytes
    NiPointer<NiGeometryData> m_spGeometryData;      // +0xB8, 4 bytes
    NiPointer<NiSkinInstance> m_spSkinningInstance;  // +0xBC, 4 bytes
    NiShader* m_pGeometryShader;                     // +0xC0, 4 bytes
};
FONT_GEOMETRY_ASSERT(sizeof(NiGeometry) == 196);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometry, m_kPropertyState) == 156);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometry, m_spGeometryData) == 184);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometry, m_spSkinningInstance) == 188);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometry, m_pGeometryShader) == 192);

class NiTriBasedGeom : public NiGeometry
{
  public:
};
FONT_GEOMETRY_ASSERT(sizeof(NiTriBasedGeom) == 196);

class NiTriShape : public NiTriBasedGeom
{
  public:
};
FONT_GEOMETRY_ASSERT(sizeof(NiTriShape) == 196);

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
FONT_GEOMETRY_ASSERT(sizeof(NiBound) == 16);
FONT_GEOMETRY_ASSERT(offsetof(NiBound, m_kCenter) == 0);
FONT_GEOMETRY_ASSERT(offsetof(NiBound, m_fBoundRadius) == 12);
FONT_GEOMETRY_ASSERT(offsetof(NiBound, m_iRadius) == 12);

class NiGeometryData : public NiObject
{
  public:
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
FONT_GEOMETRY_ASSERT(sizeof(NiGeometryData) == 64);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_usVertices) == 8);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_usGeometryFlags) == 10);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_usTrianglePoints) == 12);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_usDirtyFlags) == 14);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_kBound) == 16);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_pkVertex) == 32);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_pkNormal) == 36);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_pkColor) == 40);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_pkTexture) == 44);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_spAdditionalGeomData) == 48);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_pkGeometryRendererData) == 52);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_ucKeepFlags) == 56);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_ucCompressFlags) == 57);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_bIsDynamic) == 58);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_bBoundDirty) == 59);
FONT_GEOMETRY_ASSERT(offsetof(NiGeometryData, m_bVerticesDirty) == 60);

class NiTriBasedGeomData : public NiGeometryData
{
  public:
    unsigned short m_usTriangles;    // +0x40, 2 bytes
    unsigned short activeTriangles;  // PC +0x42, JIP name
};
FONT_GEOMETRY_ASSERT(sizeof(NiTriBasedGeomData) == 68);
FONT_GEOMETRY_ASSERT(offsetof(NiTriBasedGeomData, m_usTriangles) == 64);
FONT_GEOMETRY_ASSERT(offsetof(NiTriBasedGeomData, activeTriangles) == 0x42);

class NiTriShapeData : public NiTriBasedGeomData
{
  public:
    unsigned short* GetTriangleList();
    unsigned int m_uiTriListLength;                            // +0x44, 4 bytes
    unsigned short* m_pusTriList;                              // +0x48, 4 bytes
    NiTriShapeData__SharedNormalArray* m_pkSharedNormalArray;  // +0x4C, 4 bytes
    unsigned short m_usSharedNormalCount;                      // +0x50, 2 bytes
    unsigned char layoutPadding52[2];
    NiTriShapeData__SNAMemBlock* m_pkSharedNormalArrayMemoryBlock;  // +0x54, 4 bytes
};
FONT_GEOMETRY_ASSERT(sizeof(NiTriShapeData) == 88);
FONT_GEOMETRY_ASSERT(offsetof(NiTriShapeData, m_uiTriListLength) == 68);
FONT_GEOMETRY_ASSERT(offsetof(NiTriShapeData, m_pusTriList) == 72);
FONT_GEOMETRY_ASSERT(offsetof(NiTriShapeData, m_pkSharedNormalArray) == 76);
FONT_GEOMETRY_ASSERT(offsetof(NiTriShapeData, m_usSharedNormalCount) == 80);
FONT_GEOMETRY_ASSERT(offsetof(NiTriShapeData, m_pkSharedNormalArrayMemoryBlock) == 84);

#endif
