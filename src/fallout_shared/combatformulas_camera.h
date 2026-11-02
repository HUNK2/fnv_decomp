#ifndef FNV_NICAMERA_H
#define FNV_NICAMERA_H

#include "layout_support.h"
#include "NiObjectNET.h"
#include "NiPoint3.h"
#include "NiProperty.h"
#include "layout_support.h"
class FourComponentFloatVector;
class NiAVObject;
class NiCamera;
class NiCollisionObject;
class NiFrustum;
class ThreeByThreeMatrix;
class NiPoint4;
class NiRect_float_;
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
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerAllocator_unsigned_int_) == 1);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    unsigned int m_uiCount;
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
    NiTListItem_NiPointer_NiProperty___* m_pkHead;
    NiTListItem_NiPointer_NiProperty___* m_pkTail;
    NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator m_kItemCount;
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
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___) == 12);
#pragma pack(push, 4)
class NiTPointerList_NiPointer_NiProperty___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerList_NiPointer_NiProperty___) == 12);
#pragma pack(push, 4)
class FourComponentNumericValue
{
  public:
    union
    {
        float m_afComponents[4];
        unsigned int m_auiComponents[4];
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        float v[4];
        unsigned int u[4];
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
    {
        FourComponentNumericValue m_kComponents;
        float m_afExtents[4];
    };
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint4) == 16);
FNV_STATIC_ASSERT(offsetof(NiPoint4, m_kComponents) == 0);
FNV_STATIC_ASSERT(offsetof(NiPoint4, m_afExtents) == 0);
#pragma pack(push, 4)
class ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ThreeByThreeMatrix) == 36);
FNV_STATIC_ASSERT(offsetof(ThreeByThreeMatrix, m_afEntries) == 0);
#pragma pack(push, 4)
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTransform) == 52);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_kOrientation) == 0);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_kTranslation) == 36);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_fScale) == 48);
#pragma pack(push, 4)
class NiAVObject : public NiObjectNET
{
  public:
    NiNode* m_pParentNode;
    NiPointer<NiCollisionObject> m_spCollisionObject;
    FourComponentFloatVector* m_kWorldBound;
    NiTPointerList_NiPointer_NiProperty___ SceneGraphObject;
    unsigned int m_uiObjectFlags;
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiAVObject) == 156);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_pParentNode) == 24);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_spCollisionObject) == 28);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kWorldBound) == 32);
FNV_STATIC_ASSERT(offsetof(NiAVObject, SceneGraphObject) == 36);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_uiObjectFlags) == 48);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kLocalTransform) == 52);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kWorldSpaceTransform) == 104);
#pragma pack(push, 4)
class NiFrustum
{
  public:
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
    unsigned char layoutPadding19[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiFrustum) == 28);
FNV_STATIC_ASSERT(offsetof(NiFrustum, m_fLeftBound) == 0);
FNV_STATIC_ASSERT(offsetof(NiFrustum, m_fRightBound) == 4);
FNV_STATIC_ASSERT(offsetof(NiFrustum, m_fTopBound) == 8);
FNV_STATIC_ASSERT(offsetof(NiFrustum, m_fBottomBound) == 12);
FNV_STATIC_ASSERT(offsetof(NiFrustum, m_fNearPlane) == 16);
FNV_STATIC_ASSERT(offsetof(NiFrustum, m_fFarPlane) == 20);
FNV_STATIC_ASSERT(offsetof(NiFrustum, m_bOrthographic) == 24);
#pragma pack(push, 4)
class NiRect_float_
{
  public:
    float m_fMinimumU;
    float m_fMaximumU;
    float m_fMinimumV;
    float m_fMaximumV;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiRect_float_) == 16);
FNV_STATIC_ASSERT(offsetof(NiRect_float_, m_fMinimumU) == 0);
FNV_STATIC_ASSERT(offsetof(NiRect_float_, m_fMaximumU) == 4);
FNV_STATIC_ASSERT(offsetof(NiRect_float_, m_fMinimumV) == 8);
FNV_STATIC_ASSERT(offsetof(NiRect_float_, m_fMaximumV) == 12);
#pragma pack(push, 4)
class NiCamera : public NiAVObject
{
  public:
    float m_afWorldToCamera[4][4];
    NiFrustum m_kViewFrustum;
    float m_fMinNearPlaneDist;
    float GetMaxFarNearRatio() const;
    float m_fMaxFarNearRatio;
    NiRect_float_ m_kPort;
    float m_fTrailingValue;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiCamera) == 276);
FNV_STATIC_ASSERT(offsetof(NiCamera, m_afWorldToCamera) == 156);
FNV_STATIC_ASSERT(offsetof(NiCamera, m_kViewFrustum) == 220);
FNV_STATIC_ASSERT(offsetof(NiCamera, m_fMinNearPlaneDist) == 248);
FNV_STATIC_ASSERT(offsetof(NiCamera, m_fMaxFarNearRatio) == 252);
FNV_STATIC_ASSERT(offsetof(NiCamera, m_kPort) == 256);
FNV_STATIC_ASSERT(offsetof(NiCamera, m_fTrailingValue) == 272);
#endif
