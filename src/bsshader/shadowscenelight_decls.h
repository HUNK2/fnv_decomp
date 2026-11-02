// bsshader/shadowscenelight_decls.h: declares NiBound, NiTexture, NiLight, BSRenderedTexture, NiTriBasedGeom and more
#ifndef SHADOWSCENELIGHT_UNIT_DECLS_H
#define SHADOWSCENELIGHT_UNIT_DECLS_H

#include "shadowscenelight_types_ShadowSceneLight.h"
class NiBound
{
  public:
    NiPoint3 center;
    float radius;
};
extern NiBound DAT_011f4288;
class NiProperty;

class NiTexture : public NiRefObject
{
};
class NiLight : public NiRefObject
{
};
class BSRenderedTexture : public NiRefObject
{
};
class NiTriBasedGeom : public NiRefObject
{
};
class NiCamera : public NiRefObject
{
};
class BSShaderAccumulator : public NiRefObject
{
};
class NiAVObject : public NiRefObject
{
  public:
    unsigned char layoutPadding08[0x18];
    void* m_kWorldBound;
    unsigned char layoutPadding24[0x0C];
    unsigned int m_uiObjectFlags;
};
class NiTListItem_NiPointer_NiTriBasedGeom___
{
  public:
    NiTListItem_NiPointer_NiTriBasedGeom___* m_pkNext;
    NiTListItem_NiPointer_NiTriBasedGeom___* m_pkPrev;
    NiPointer<NiTriBasedGeom> m_kItem;
};
class BSShaderLightingProperty
{
  public:
    unsigned char layoutPadding00[0x1C];
    unsigned int m_uiActiveLightCount;
    unsigned char IsLightingProperty()
    {
        return m_uiActiveLightCount - 1 <= 11;
    }
    ShadowSceneLight* GetNextAttachedLight(void*);
};
struct ShadowGeomShaderPropertyView
{
    unsigned char layoutPadding00[0xA8];
    BSShaderLightingProperty* m_spShaderProperty;
};
struct ShadowBoundView
{
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
};
struct ShadowNodeChildrenView
{
    unsigned char layoutPadding00[0xA0];
    NiAVObject** m_ppChildren;
    unsigned short m_usAllocated;
    unsigned short m_usElementCount;
};
struct ShadowBoundRadiusView
{
    unsigned char layoutPadding00[0xC];
    float m_fBoundRadius;
};
class ShadowObjectSlots
{
  public:
    virtual void* Slot00() = 0;
    virtual void* Slot04() = 0;
    virtual void* Slot08() = 0;
    virtual NiNode* GetNiNode() = 0;
    virtual void* Slot10() = 0;
    virtual void* Slot14() = 0;
    virtual void* Slot18() = 0;
    virtual NiTriBasedGeom* GetTriBasedGeom() = 0;
};
struct ShadowPointerView
{
    NiTriBasedGeom* ptr;
    operator NiTriBasedGeom*() const
    {
        return ptr;
    }
};
struct ShadowItemView
{
    ShadowItemView* next;
    void* prev;
    ShadowPointerView item;
    ShadowPointerView& GetItem()
    {
        return item;
    }
};
#endif
