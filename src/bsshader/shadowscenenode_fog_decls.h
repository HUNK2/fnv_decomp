// bsshader/shadowscenenode_fog_decls.h: declares NiMemObject, NiColor, NiFogProperty, BSFogProperty, ShadowSceneNode
#ifndef FNV_SHADOWSCENENODE_FOG_DECLS_H
#define FNV_SHADOWSCENENODE_FOG_DECLS_H


#include "layout_support.h"

// PC allocation declarations missing from the shared layout-only header.
#ifndef FNV_NIMEMOBJECT_H
#define FNV_NIMEMOBJECT_H
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
#endif

#include "NiProperty.h"

class NiColor
{
  public:
    float r, g, b;
    NiColor(float red, float green, float blue) : r(red), g(green), b(blue)
    {}
};

class NiFogProperty : public NiProperty
{
  public:
    unsigned short m_uiObjectFlags;
    float m_fFogDepth;
    NiColor m_kFogTint;
    void SetColor(const NiColor& color)
    {
        m_kFogTint = color;
    }
};

class BSFogProperty : public NiFogProperty
{
  public:
    float m_fFogStartDistance;
    float m_fFogEndDistance;
    float m_fFogParameterA;
    float m_fFogParameterB;
    unsigned char planeData[16];
    float fFalloff;
    float m_fGlyphExtent;
    NiColor m_kFogColor;
    float m_fAlpha;
    BSFogProperty();
    void SetFog(float start, float end)
    {
        m_fFogStartDistance = start;
        m_fFogEndDistance = end;
    }
    void SetPower(float power)
    {
        m_fAlpha = power;
    }
    void SetWaterFog(float start, float end)
    {
        m_fFogParameterA = start;
        m_fFogParameterB = end;
    }
    void SetWaterColor(const NiColor& color)
    {
        m_kFogColor = color;
    }
};

template <> class NiPointer<BSFogProperty>
{
  public:
    BSFogProperty* m_pObject;
    NiPointer& operator=(BSFogProperty* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (object)
                object->IncRefCount();
        }
        return *this;
    }
    BSFogProperty* operator->() const
    {
        return m_pObject;
    }
};

// Only the PC prefix through m_spFogProperty is needed by this header unit.
class ShadowSceneNode
{
  public:
    unsigned char sceneNodePrefix[0x134];
    NiPointer<BSFogProperty> m_spFogProperty;
    void SetFogPropertyForIndex(BSFogProperty* property);
};

FNV_STATIC_ASSERT(sizeof(NiColor) == 12);
FNV_STATIC_ASSERT(sizeof(NiFogProperty) == 44);
FNV_STATIC_ASSERT(sizeof(BSFogProperty) == 100);
FNV_STATIC_ASSERT(offsetof(BSFogProperty, m_fFogStartDistance) == 0x2c);
FNV_STATIC_ASSERT(offsetof(BSFogProperty, m_kFogColor) == 0x54);
FNV_STATIC_ASSERT(offsetof(BSFogProperty, m_fAlpha) == 0x60);
FNV_STATIC_ASSERT(offsetof(ShadowSceneNode, m_spFogProperty) == 0x134);
#endif
