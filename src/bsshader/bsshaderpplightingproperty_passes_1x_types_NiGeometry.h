// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIGEOMETRY_H
#define FNV_NIGEOMETRY_H

#include "layout_support.h"
#include "NiObjectNET.h"
#include "NiPoint3.h"
#include "NiProperty.h"
#include "layout_support.h"
class FourComponentFloatVector;
class NiAVObject;
class NiCollisionObject;
class NiGeometry;
class NiGeometryData;
class ThreeByThreeMatrix;
class NiPoint4;
class NiPropertyState;
class NiShader;
class NiSkinInstance;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator;
class NiTListItem_NiPointer_NiProperty___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_NiPointer_NiProperty___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___;
class NiTransform;
class FourComponentNumericValue;
#pragma pack(push, 4)
class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTAbstractPoolAllocator_unsigned_int_) == 1);
#pragma pack(push, 4)
class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
    // void* __cdecl NiTPointerAllocator<unsigned int>::*()
    // void __cdecl NiTPointerAllocator<unsigned int>::*(void*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerAllocator_unsigned_int_) == 1);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator) ==
                  4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator,
                           m_uiCount) == 0);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
    NiTListItem_NiPointer_NiProperty___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_NiPointer_NiProperty___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(NiTListItem<NiPointer<NiProperty> >*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(NiTListItem<NiPointer<NiProperty> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*, NiTListItem<NiPointer<NiProperty> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*, NiTListItem<NiPointer<NiProperty> >*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(const NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___, m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
    // base NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> > at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(const NiPointer<NiProperty>&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(const NiPointer<NiProperty>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*, const NiPointer<NiProperty>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*, const NiPointer<NiProperty>&)
    // const NiPointer<NiProperty>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // const NiPointer<NiProperty>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // const NiPointer<NiProperty>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*)
    // const NiPointer<NiProperty>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*&)
    // const NiPointer<NiProperty>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*&)
    // NiPointer<NiProperty> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // NiPointer<NiProperty> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // NiPointer<NiProperty> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(const NiPointer<NiProperty>&)
    // NiPointer<NiProperty> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(const NiPointer<NiProperty>&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(int __cdecl (void*, void*)*)
    // NiTListItem<NiPointer<NiProperty> >* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(NiTListItem<NiPointer<NiProperty> >*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___) == 12);
#pragma pack(push, 4)
class NiTPointerList_NiPointer_NiProperty___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
    // base NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> > at +0x0, size 12
    // NiTPointerList<NiPointer<NiProperty> >
    // void __cdecl NiTPointerList<NiPointer<NiProperty> >::*()
    // NiTPointerList<NiPointer<NiProperty> >& __cdecl NiTPointerList<NiPointer<NiProperty> >::*(const NiTPointerList<NiPointer<NiProperty> >&)
    // void* __cdecl NiTPointerList<NiPointer<NiProperty> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerList_NiPointer_NiProperty___) == 12);
#pragma pack(push, 4)
class FourComponentNumericValue
{
  public:
    union
    {                                     // overlapping CodeView storage
        float m_afComponents[4];          // +0x0, 16 bytes
        unsigned int m_auiComponents[4];  // +0x0, 16 bytes
        struct
        {
            float x;  // +0x0, 4 bytes
            float y;  // +0x4, 4 bytes
            float z;  // +0x8, 4 bytes
            float w;  // +0xC, 4 bytes
        };
        float v[4];         // +0x0, 16 bytes
        unsigned int u[4];  // +0x0, 16 bytes
    };
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FourComponentNumericValue) == 16);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, m_afComponents) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, m_auiComponents) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, x) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, y) == 4);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, z) == 8);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, w) == 12);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, v) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, u) == 0);
#pragma pack(push, 4)
class NiPoint4
{
  public:
    union
    {                                             // overlapping CodeView storage
        FourComponentNumericValue m_kComponents;  // +0x0, 16 bytes
        float m_afExtents[4];                     // +0x0, 16 bytes
    };
    // NiPoint4
    // bool __cdecl NiPoint4::*(const NiPoint4&)
    // void __cdecl NiPoint4::*()
    // Set
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // NiPoint4 __cdecl NiPoint4::*(const NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(const NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(float)
    // NiPoint4 __cdecl NiPoint4::*(NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(NiPoint4*, unsigned int, NiPoint3*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint4) == 16);
FNV_STATIC_ASSERT(offsetof(NiPoint4, m_kComponents) == 0);
FNV_STATIC_ASSERT(offsetof(NiPoint4, m_afExtents) == 0);
#pragma pack(push, 4)
class ThreeByThreeMatrix
{
  public:
    NiPoint4 m_afEntries[3];  // +0x0, 48 bytes
    // GetRow
    // SetRow
    // GetCol
    // SetCol
    // operator*
    // Inverse
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ThreeByThreeMatrix) == 48);
FNV_STATIC_ASSERT(offsetof(ThreeByThreeMatrix, m_afEntries) == 0);
#pragma pack(push, 4)
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;  // +0x0, 48 bytes
    NiPoint3 m_kTranslation;   // +0x30, 12 bytes
    float m_fScale;            // +0x3C, 4 bytes
    // void __cdecl NiTransform::*()
    // bool __cdecl NiTransform::*(const NiTransform&)
    // operator*
    // void __cdecl NiTransform::*(NiTransform&)
    // void __cdecl NiTransform::*(NiTransform&)
    // bool __cdecl NiTransform::*()
    // void __cdecl NiTransform::*(NiStream&)
    // void __cdecl NiTransform::*(NiStream&)
    // void __cdecl NiTransform::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTransform) == 64);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_kOrientation) == 0);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_kTranslation) == 48);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_fScale) == 60);
#pragma pack(push, 4)
class NiAVObject : public NiObjectNET
{
  public:
    // base NiObjectNET at +0x0, size 24
    NiNode* m_pParentNode;                                    // +0x18, 4 bytes
    NiPointer<NiCollisionObject> m_spCollisionObject;         // +0x1C, 4 bytes
    FourComponentFloatVector* m_kWorldBound;                  // +0x20, 4 bytes
    NiTPointerList_NiPointer_NiProperty___ SceneGraphObject;  // +0x24, 12 bytes
    unsigned int m_uiObjectFlags;                                    // +0x30, 4 bytes
    unsigned char layoutPadding34[12];
    NiTransform m_kLocalTransform;  // +0x40, 64 bytes
    NiTransform m_kWorldSpaceTransform;           // +0x80, 64 bytes
    // const NiRTTI* __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(NiStream&)
    // void __cdecl NiAVObject::*(NiStream&)
    // bool __cdecl NiAVObject::*(NiStream&)
    // void __cdecl NiAVObject::*(NiStream&)
    // bool __cdecl NiAVObject::*(NiObject*)
    // void __cdecl NiAVObject::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiAVObject::*()
    // GetParent
    // void __cdecl NiAVObject::*(NiUpdateData&)
    // void __cdecl NiAVObject::*(NiUpdateData&)
    // void __cdecl NiAVObject::*(NiUpdateData&, bool)
    // void __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(FourComponentFloatVector*)
    // const NiPoint3& __cdecl NiAVObject::*()
    // GetRotate
    // void __cdecl NiAVObject::*(float)
    // float __cdecl NiAVObject::*()
    // const NiPoint3& __cdecl NiAVObject::*()
    // float __cdecl NiAVObject::*()
    // const NiBound& __cdecl NiAVObject::*()
    // float __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*()
    // GetPropertyList
    // void __cdecl NiAVObject::*(NiProperty*)
    // void __cdecl NiAVObject::*(NiProperty*)
    // void __cdecl NiAVObject::*()
    // NiProperty* __cdecl NiAVObject::*(int)
    // RemoveProperty
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(bool)
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(NiCollisionObject*)
    // NiCollisionObject* __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(const NiPoint3&)
    // void __cdecl NiAVObject::*(float)
    // void __cdecl NiAVObject::*(const NiBound&)
    // int __cdecl NiAVObject::*()
    // int __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(NiPropertyState*, bool, NiPropertyState*&)
    // void __cdecl NiAVObject::*(NiNode*)
    // void __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(NiCullingProcess&)
    // void __cdecl NiAVObject::*(NiUpdateData&, unsigned int)
    // const NiTransform& __cdecl NiAVObject::*()
    // const NiTransform& __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*()
    // bool __cdecl NiAVObject::*()
    // NiAVObject
    // void __cdecl NiAVObject::*(bool)
    // bool __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*()
    // void __cdecl NiAVObject::*(unsigned int, unsigned int, unsigned int)
    // unsigned int __cdecl NiAVObject::*(unsigned int, unsigned int)
    // void __cdecl NiAVObject::*(bool, unsigned int)
    // bool __cdecl NiAVObject::*(unsigned int)
    // void __cdecl NiAVObject::*(const NiAVObject*)
    // bool __cdecl NiAVObject::*()
    // bool __cdecl NiAVObject::*()
    // NiAVObject& __cdecl NiAVObject::*(const NiAVObject&)
    // void __cdecl NiAVObject::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiAVObject) == 192);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_pParentNode) == 24);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_spCollisionObject) == 28);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kWorldBound) == 32);
FNV_STATIC_ASSERT(offsetof(NiAVObject, SceneGraphObject) == 36);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_uiObjectFlags) == 48);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kLocalTransform) == 64);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kWorldSpaceTransform) == 128);
#pragma pack(push, 4)
class NiPropertyState
{
  public:
    NiPointer<NiProperty> m_spProperties[7];  // +0x0, 28 bytes
    // NiPropertyState
    // void __cdecl NiPropertyState::*()
    // NiPropertyState& __cdecl NiPropertyState::*(const NiPropertyState&)
    // NiPointer<NiProperty>& __cdecl NiPropertyState::*(int)
    // void __cdecl NiPropertyState::*()
    // void __cdecl NiPropertyState::*(NiProperty*)
    // void __cdecl NiPropertyState::*(NiProperty**)
    // void __cdecl NiPropertyState::*(NiTPointerList<NiPointer<NiProperty> >&)
    // NiAlphaProperty* __cdecl NiPropertyState::*()
    // NiDitherProperty* __cdecl NiPropertyState::*()
    // NiCullingProperty* __cdecl NiPropertyState::*()
    // NiMaterialProperty* __cdecl NiPropertyState::*()
    // NiRendererSpecificProperty* __cdecl NiPropertyState::*()
    // NiShadeProperty* __cdecl NiPropertyState::*()
    // NiSpecularProperty* __cdecl NiPropertyState::*()
    // NiStencilProperty* __cdecl NiPropertyState::*()
    // NiTexturingProperty* __cdecl NiPropertyState::*()
    // NiVertexColorProperty* __cdecl NiPropertyState::*()
    // NiWireframeProperty* __cdecl NiPropertyState::*()
    // NiZBufferProperty* __cdecl NiPropertyState::*()
    // void* __cdecl NiPropertyState::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPropertyState) == 28);
FNV_STATIC_ASSERT(offsetof(NiPropertyState, m_spProperties) == 0);
#pragma pack(push, 4)
class NiGeometry : public NiAVObject
{
  public:
    // base NiAVObject at +0x0, size 192
    NiPropertyState m_kPropertyState;                // +0xC0, 28 bytes
    NiPointer<NiGeometryData> m_spGeometryData;      // +0xDC, 4 bytes
    NiPointer<NiSkinInstance> m_spSkinningInstance;  // +0xE0, 4 bytes
    NiShader* m_pGeometryShader;                     // +0xE4, 4 bytes
    unsigned int m_uiGeometryShaderFlags;            // +0xE8, 4 bytes
    unsigned char layoutPaddingEC[4];
    // const NiRTTI* __cdecl NiGeometry::*()
    // void __cdecl NiGeometry::*(NiStream&)
    // void __cdecl NiGeometry::*(NiStream&)
    // bool __cdecl NiGeometry::*(NiStream&)
    // void __cdecl NiGeometry::*(NiStream&)
    // bool __cdecl NiGeometry::*(NiObject*)
    // void __cdecl NiGeometry::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiGeometry::*()
    // unsigned short __cdecl NiGeometry::*()
    // NiPoint3* __cdecl NiGeometry::*()
    // void __cdecl NiGeometry::*(unsigned short)
    // unsigned short __cdecl NiGeometry::*()
    // void __cdecl NiGeometry::*(bool)
    // NiPoint3* __cdecl NiGeometry::*()
    // NiGeometryData::DataFlags __cdecl NiGeometry::*()
    // void __cdecl NiGeometry::*(NiGeometryData::DataFlags)
    // void __cdecl NiGeometry::*(const NiBound&)
    // NiBound& __cdecl NiGeometry::*()
    // void __cdecl NiGeometry::*(bool)
    // void __cdecl NiGeometry::*(bool, unsigned short)
    // unsigned short __cdecl NiGeometry::*()
    // NiPoint2* __cdecl NiGeometry::*()
    // NiPoint2* __cdecl NiGeometry::*(unsigned short)
    // void __cdecl NiGeometry::*(NiPoint2*)
    // NiSkinInstance* __cdecl NiGeometry::*()
    // void __cdecl NiGeometry::*(NiSkinInstance*)
    // NiAdditionalGeometryData* __cdecl NiGeometry::*()
    // void __cdecl NiGeometry::*(NiAdditionalGeometryData*)
    // void __cdecl NiGeometry::*(bool)
    // bool __cdecl NiGeometry::*()
    // NiPropertyState* __cdecl NiGeometry::*()
    // NiGeometry* __cdecl NiGeometry::*()
    // void __cdecl NiGeometry::*(FourComponentFloatVector*)
    // NiShader* __cdecl NiGeometry::*()
    // NiShader* __cdecl NiGeometry::*()
    // void __cdecl NiGeometry::*(NiShader*)
    // NiGeometryData* __cdecl NiGeometry::*()
    // bool __cdecl NiGeometry::*(NiShaderDeclaration::ShaderParameter)
    // void __cdecl NiGeometry::*(NiCullingProcess&)
    // void __cdecl NiGeometry::*(NiPropertyState*)
    // NiGeometryData::Consistency __cdecl NiGeometry::*()
    // void __cdecl NiGeometry::*(NiGeometryData::Consistency)
    // void __cdecl NiGeometry::*(NiStream&)
    // void __cdecl NiGeometry::*(bool&, bool, bool&)
    // void __cdecl NiGeometry::*(NiRenderer*)
    // unsigned int __cdecl NiGeometry::*()
    // NiGeometry
    // void __cdecl NiGeometry::*()
    // NiGeometry& __cdecl NiGeometry::*(const NiGeometry&)
    // void __cdecl NiGeometry::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiGeometry) == 240);
FNV_STATIC_ASSERT(offsetof(NiGeometry, m_kPropertyState) == 192);
FNV_STATIC_ASSERT(offsetof(NiGeometry, m_spGeometryData) == 220);
FNV_STATIC_ASSERT(offsetof(NiGeometry, m_spSkinningInstance) == 224);
FNV_STATIC_ASSERT(offsetof(NiGeometry, m_pGeometryShader) == 228);
FNV_STATIC_ASSERT(offsetof(NiGeometry, m_uiGeometryShaderFlags) == 232);
#endif
