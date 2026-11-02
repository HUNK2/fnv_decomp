// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSTEMPEFFECTSIMPLEDECAL_H
#define FNV_BSTEMPEFFECTSIMPLEDECAL_H

#include "layout_support.h"
#include "NiObject.h"
#include "NiPoint3.h"
#include "layout_support.h"
class BGSDecalNode;
class BGSTextureSet;
class RenderQuery;
class BSRenderedTexture;
class BSTempEffect;
class BSTempEffectSimpleDecal;
class DecalPointRecord;
class NiAVObject;
class NiColor;
class RgbaColor;
class NiPlane;
class NiPoint2;
#pragma pack(push, 4)
class BSTempEffect : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    float m_fParticleParameter5;  // +0x8, 4 bytes
    TESObjectCELL* pCell;         // +0xC, 4 bytes
    float m_fFirstFloatValue;                   // +0x10, 4 bytes
    bool bInitialized;            // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    // const NiRTTI* __cdecl BSTempEffect::*()
    // IsExactKindOf
    // NiNode* __cdecl BSTempEffect::*()
    // BSFadeNode* __cdecl BSTempEffect::*()
    // BSMultiBoundNode* __cdecl BSTempEffect::*()
    // NiGeometry* __cdecl BSTempEffect::*()
    // NiTriBasedGeom* __cdecl BSTempEffect::*()
    // NiTriStrips* __cdecl BSTempEffect::*()
    // NiTriShape* __cdecl BSTempEffect::*()
    // BSSegmentedTriShape* __cdecl BSTempEffect::*()
    // BSResizableTriShape* __cdecl BSTempEffect::*()
    // NiParticles* __cdecl BSTempEffect::*()
    // NiLines* __cdecl BSTempEffect::*()
    // bhkNiCollisionObject* __cdecl BSTempEffect::*()
    // bhkBlendCollisionObject* __cdecl BSTempEffect::*()
    // bhkRigidBody* __cdecl BSTempEffect::*()
    // bhkLimitedHingeConstraint* __cdecl BSTempEffect::*()
    // DynamicCast
    // BSTempEffect
    // void __cdecl BSTempEffect::*()
    // float __cdecl BSTempEffect::*()
    // float __cdecl BSTempEffect::*()
    // TESObjectCELL* __cdecl BSTempEffect::*()
    // void __cdecl BSTempEffect::*(TESObjectCELL*)
    // SaveGame
    // LoadGame
    // void __cdecl BSTempEffect::*(BSTempEffect*)
    // void __cdecl BSTempEffect::*()
    // BSTempEffect& __cdecl BSTempEffect::*(const BSTempEffect&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTempEffect) == 24);
FNV_STATIC_ASSERT(offsetof(BSTempEffect, m_fParticleParameter5) == 8);
FNV_STATIC_ASSERT(offsetof(BSTempEffect, pCell) == 12);
FNV_STATIC_ASSERT(offsetof(BSTempEffect, m_fFirstFloatValue) == 16);
FNV_STATIC_ASSERT(offsetof(BSTempEffect, bInitialized) == 20);
#pragma pack(push, 4)
class NiPlane
{
  public:
    NiPoint3 m_kPlaneNormal;  // +0x0, 12 bytes
    float m_fPlaneConstant;   // +0xC, 4 bytes
    // NiPlane
    // bool __cdecl NiPlane::*(const NiPlane&)
    // bool __cdecl NiPlane::*(const NiPlane&)
    // NiPlane __cdecl NiPlane::*()
    // void __cdecl NiPlane::*(const NiPoint3&)
    // const NiPoint3& __cdecl NiPlane::*()
    // void __cdecl NiPlane::*(float)
    // float __cdecl NiPlane::*()
    // float __cdecl NiPlane::*(const NiPoint3&)
    // int __cdecl NiPlane::*(const NiPoint3&)
    // void __cdecl NiPlane::*(NiStream&)
    // void __cdecl NiPlane::*(NiStream&)
    // char* __cdecl NiPlane::*(const char*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPlane) == 16);
FNV_STATIC_ASSERT(offsetof(NiPlane, m_kPlaneNormal) == 0);
FNV_STATIC_ASSERT(offsetof(NiPlane, m_fPlaneConstant) == 12);
#pragma pack(push, 4)
class NiColor
{
  public:
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    // void __cdecl NiColor::*(float, float, float)
    // bool __cdecl NiColor::*(const NiColor&)
    // bool __cdecl NiColor::*(const NiColor&)
    // NiColor __cdecl NiColor::*(const NiColor&)
    // operator-
    // operator*
    // operator/
    // NiColor& __cdecl NiColor::*(const NiColor&)
    // NiColor& __cdecl NiColor::*(const NiColor&)
    // operator*=
    // operator/=
    // void __cdecl NiColor::*()
    // void __cdecl NiColor::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiColor::*(const char*)
    // float __cdecl NiColor::*()
    // void __cdecl NiColor::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiColor) == 12);
FNV_STATIC_ASSERT(offsetof(NiColor, r) == 0);
FNV_STATIC_ASSERT(offsetof(NiColor, g) == 4);
FNV_STATIC_ASSERT(offsetof(NiColor, b) == 8);
#pragma pack(push, 4)
class BSTempEffectSimpleDecal : public BSTempEffect
{
  public:
    // base BSTempEffect at +0x0, size 24
    bool bWasPlaying;                                    // +0x18, 1 bytes
    bool m_bTextureDirty;                                // +0x19, 1 bytes
    bool m_bNeedsManagerUpdate;                          // +0x1A, 1 bytes
    bool m_bDecalRenderingEnabled;                       // +0x1B, 1 bytes
    RenderQuery* m_pRenderQuery;                         // +0x1C, 4 bytes
    NiPointer<BSRenderedTexture> m_pDecalRenderTexture;  // +0x20, 4 bytes
    unsigned int m_uiTextureReferenceCount;              // +0x24, 4 bytes
    NiPointer<NiAVObject> m_pSceneObject;                // +0x28, 4 bytes
    bool bPermanent;                                     // +0x2C, 1 bytes
    bool m_bSecondObjectFlag;                            // +0x2D, 1 bytes
    bool TexturedObjectPlacementInfo;                    // +0x2E, 1 bytes
    unsigned char layoutPadding2F[1];
    BGSTextureSet* m_pTextureSet;                 // +0x30, 4 bytes
    NiPoint3 pOrigin;                             // +0x34, 12 bytes
    NiPoint3 m_kSecondVertex;                     // +0x40, 12 bytes
    NiPoint3 m_kThirdPoint;                       // +0x4C, 12 bytes
    NiPoint3 m_kFourthPoint;                      // +0x58, 12 bytes
    NiPlane m_akFacePlanes[6];                    // +0x64, 96 bytes
    int m_iFirstValueAfterPlanes;                 // +0xC4, 4 bytes
    int m_iSecondValueAfterPlanes;                // +0xC8, 4 bytes
    NiPoint3* m_pFirstPoint3Array;                // +0xCC, 4 bytes
    NiPoint3* m_pVertexNormals;                   // +0xD0, 4 bytes
    NiPoint3* m_pThirdPoint3Array;                // +0xD4, 4 bytes
    NiPoint3* m_pVertexBitangents;                // +0xD8, 4 bytes
    NiPoint2* m_pPrimaryTextureCoordinates;       // +0xDC, 4 bytes
    NiPoint2* m_pSecondaryTextureCoordinates;     // +0xE0, 4 bytes
    RgbaColor* m_pFirstElementArray;              // +0xE4, 4 bytes
    RgbaColor* NavMeshGeometryBuffers;            // +0xE8, 4 bytes
    unsigned short* m_pFirstUnsignedShortArray;   // +0xEC, 4 bytes
    unsigned short* m_pSecondUnsignedShortArray;  // +0xF0, 4 bytes
    short* m_pSignedShortArray;                   // +0xF4, 4 bytes
    unsigned char m_aucByteBuffer[16];            // +0xF8, 16 bytes
    BGSDecalNode* m_pDecalNode;                   // +0x108, 4 bytes
    NiPointer<NiAVObject> m_pTargetNode;          // +0x10C, 4 bytes
    float fScale;                                 // +0x110, 4 bytes
    float fPathHeading;                           // +0x114, 4 bytes
    float m_fGlyphWidthInPixels;                                 // +0x118, 4 bytes
    float m_fGlyphExtent;                                // +0x11C, 4 bytes
    float m_fProjectionDepth;                     // +0x120, 4 bytes
    unsigned char m_ucByteAfterFloats;            // +0x124, 1 bytes
    bool m_bFlagBeforeFloat;                      // +0x125, 1 bytes
    unsigned char layoutPadding126[2];
    float m_fFloatBeforeScalarFlagState;  // +0x128, 4 bytes
    unsigned char ScalarFlagState;  // +0x12C, 1 bytes
    bool m_bFirstBooleanFlag;       // +0x12D, 1 bytes
    bool m_bSecondBooleanFlag;      // +0x12E, 1 bytes
    unsigned char layoutPadding12F[1];
    float m_fSpecularStrength;    // +0x130, 4 bytes
    NiColor m_kSurfaceColor;      // +0x134, 12 bytes
    bool m_bTextureFlag;          // +0x140, 1 bytes
    bool m_bDecalTextureCreated;  // +0x141, 1 bytes
    unsigned char layoutPadding142[2];
    bool ReleaseTextureObject();
    bool CreateDecalTexture();
    void SetDecalTint(RgbaColor&, bool);
    bool GetByteAt2D();
    TESTopicInfoData* FUN_004a0330();
    // const NiRTTI* __cdecl BSTempEffectSimpleDecal::*()
    // BSTempEffectSimpleDecal
    // void __cdecl BSTempEffectSimpleDecal::*()
    // void __cdecl BSTempEffectSimpleDecal::*()
    // void __cdecl BSTempEffectSimpleDecal::*()
    // void __cdecl BSTempEffectSimpleDecal::*()
    // void __cdecl BSTempEffectSimpleDecal::*()
    // void __cdecl BSTempEffectSimpleDecal::*()
    // void __cdecl BSTempEffectSimpleDecal::*()
    // bool __cdecl BSTempEffectSimpleDecal::*(NiAVObject*)
    // bool __cdecl BSTempEffectSimpleDecal::*()
    // bool __cdecl BSTempEffectSimpleDecal::*(float)
    // NiTriShape* __cdecl BSTempEffectSimpleDecal::*(NiTriShapeData*)
    // CreateTriData
    // int __cdecl BSTempEffectSimpleDecal::*()
    // NiPoint3 __cdecl BSTempEffectSimpleDecal::*()
    // NiPoint3 __cdecl BSTempEffectSimpleDecal::*()
    // float __cdecl BSTempEffectSimpleDecal::*()
    // float __cdecl BSTempEffectSimpleDecal::*()
    // float __cdecl BSTempEffectSimpleDecal::*()
    // float __cdecl BSTempEffectSimpleDecal::*()
    // NiAVObject* __cdecl BSTempEffectSimpleDecal::*()
    // NiAVObject* __cdecl BSTempEffectSimpleDecal::*()
    // bool __cdecl BSTempEffectSimpleDecal::*(int, int*, NiPoint3*, const NiPoint3*)
    // void __cdecl BSTempEffectSimpleDecal::*(NiAVObject*)
    // int __cdecl BSTempEffectSimpleDecal::*(int, const int*, const NiPoint3*, const NiPoint3*, int*, NiPoint3*, NiPoint3*)
    // int __cdecl BSTempEffectSimpleDecal::*(NiPlane*, int, const int*, const NiPoint3*, const NiPoint3*, int*, NiPoint3*, NiPoint3*)
    // bool __cdecl BSTempEffectSimpleDecal::*()
    // void __cdecl BSTempEffectSimpleDecal::*(RgbaColor&, bool)
    // bool __cdecl BSTempEffectSimpleDecal::*()
    // void __cdecl BSTempEffectSimpleDecal::*(bool)
    // void __cdecl BSTempEffectSimpleDecal::*(NiTriStrips*, NiGeometryData*)
    // void __cdecl BSTempEffectSimpleDecal::*()
    // BSTempEffectSimpleDecal& __cdecl BSTempEffectSimpleDecal::*(const BSTempEffectSimpleDecal&)
    // void __cdecl BSTempEffectSimpleDecal::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTempEffectSimpleDecal) == 324);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, bWasPlaying) == 24);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_bTextureDirty) == 25);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_bNeedsManagerUpdate) == 26);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_bDecalRenderingEnabled) == 27);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pRenderQuery) == 28);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pDecalRenderTexture) == 32);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_uiTextureReferenceCount) == 36);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pSceneObject) == 40);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, bPermanent) == 44);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_bSecondObjectFlag) == 45);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, TexturedObjectPlacementInfo) == 46);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pTextureSet) == 48);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, pOrigin) == 52);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_kSecondVertex) == 64);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_kThirdPoint) == 76);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_kFourthPoint) == 88);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_akFacePlanes) == 100);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_iFirstValueAfterPlanes) == 196);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_iSecondValueAfterPlanes) == 200);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pFirstPoint3Array) == 204);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pVertexNormals) == 208);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pThirdPoint3Array) == 212);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pVertexBitangents) == 216);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pPrimaryTextureCoordinates) == 220);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pSecondaryTextureCoordinates) == 224);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pFirstElementArray) == 228);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, NavMeshGeometryBuffers) == 232);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pFirstUnsignedShortArray) == 236);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pSecondUnsignedShortArray) == 240);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pSignedShortArray) == 244);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_aucByteBuffer) == 248);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pDecalNode) == 264);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_pTargetNode) == 268);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, fScale) == 272);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, fPathHeading) == 276);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_fGlyphWidthInPixels) == 280);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_fGlyphExtent) == 284);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_fProjectionDepth) == 288);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_ucByteAfterFloats) == 292);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_bFlagBeforeFloat) == 293);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_fFloatBeforeScalarFlagState) == 296);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, ScalarFlagState) == 300);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_bFirstBooleanFlag) == 301);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_bSecondBooleanFlag) == 302);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_fSpecularStrength) == 304);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_kSurfaceColor) == 308);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_bTextureFlag) == 320);
FNV_STATIC_ASSERT(offsetof(BSTempEffectSimpleDecal, m_bDecalTextureCreated) == 321);
#endif
