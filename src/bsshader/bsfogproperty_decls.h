// bsshader/bsfogproperty_decls.h: declares NiProperty, NiColor, NiFogProperty, NiPlane, BSFogProperty
#ifndef BSFOGPROPERTY_DECLS_H
#define BSFOGPROPERTY_DECLS_H

class NiProperty
{
  public:
    NiProperty();
    virtual ~NiProperty();
    unsigned char data[20];
};
class NiColor
{
  public:
    float r, g, b;
    NiColor() : r(0), g(0), b(0)
    {}
};
extern NiColor DAT_011f4998;
extern const double DAT_010b9e30;
extern const double DAT_0103a480;
class NiFogProperty : public NiProperty
{
  public:
    virtual ~NiFogProperty();
    unsigned short m_uiObjectFlags;
    float m_fFogDepth;
    NiColor m_kFogTint;
    NiFogProperty()
    {
        m_uiObjectFlags = 0;
        m_fFogDepth = 1.0f;
        m_kFogTint = DAT_011f4998;
    }
};
class NiPlane
{
  public:
    NiPlane();
    float x, y, z, c;
};
class BSFogProperty : public NiFogProperty
{
  public:
    BSFogProperty();
    virtual ~BSFogProperty();
    float m_fFogStartDistance, m_fFogEndDistance, m_fFogParameterA, m_fFogParameterB;
    NiPlane m_kFogPlane;
    float fFalloff, m_fGlyphExtent;
    NiColor m_kFogColor;
    float m_fAlpha;
};
#endif
