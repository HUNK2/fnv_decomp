// gamebryo2.2/corelibs/niparticle/nipsysemitter_types.h: declares NiPSysModifier, RgbaColor, NiPSysEmitter

class NiStream;
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPSYSEMITTER_H
#define FNV_NIPSYSEMITTER_H
#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObject.h"
class RgbaColor;
class NiPSysEmitter;
class NiPSysModifier;
class NiParticleSystem;
#pragma pack(push, 4)
class NiPSysModifier : public NiObject
{
  public:
    virtual void LoadBinary(NiStream&);
    // base NiObject at +0x0, size 8
    NiFixedString m_kName;         // +0x8, 4 bytes
    unsigned int m_uiUpdateOrder;  // +0xC, 4 bytes
    NiParticleSystem* m_pkTarget;  // +0x10, 4 bytes
    bool m_bModifierActive;        // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    // const NiRTTI* __cdecl NiPSysModifier::*()
    // void __cdecl NiPSysModifier::*(NiStream&)
    // void __cdecl NiPSysModifier::*(NiStream&)
    // bool __cdecl NiPSysModifier::*(NiStream&)
    // void __cdecl NiPSysModifier::*(NiStream&)
    // bool __cdecl NiPSysModifier::*(NiObject*)
    // void __cdecl NiPSysModifier::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiPSysModifier::*(float, NiPSysData*)
    // const NiFixedString& __cdecl NiPSysModifier::*()
    // void __cdecl NiPSysModifier::*(const NiFixedString&)
    // unsigned int __cdecl NiPSysModifier::*()
    // NiParticleSystem* __cdecl NiPSysModifier::*()
    // bool __cdecl NiPSysModifier::*()
    // NiPSysModifier
    // void __cdecl NiPSysModifier::*()
    // NiPSysModifier& __cdecl NiPSysModifier::*(const NiPSysModifier&)
    // void __cdecl NiPSysModifier::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysModifier) == 24);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_kName) == 8);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_uiUpdateOrder) == 12);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_pkTarget) == 16);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_bModifierActive) == 20);
#pragma pack(push, 4)
class RgbaColor
{
  public:
    void LoadBinary(NiStream&);
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    float a;  // +0xC, 4 bytes
    // void __cdecl RgbaColor::*(float, float, float, float)
    // bool __cdecl RgbaColor::*(const RgbaColor&)
    // bool __cdecl RgbaColor::*(const RgbaColor&)
    // RgbaColor __cdecl RgbaColor::*(const RgbaColor&)
    // operator-
    // operator*
    // operator/
    // RgbaColor& __cdecl RgbaColor::*(const RgbaColor&)
    // RgbaColor& __cdecl RgbaColor::*(const RgbaColor&)
    // operator*=
    // operator/=
    // void __cdecl RgbaColor::*()
    // void __cdecl RgbaColor::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl RgbaColor::*(const char*)
    // float __cdecl RgbaColor::*()
    // void __cdecl RgbaColor::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RgbaColor) == 16);
FNV_STATIC_ASSERT(offsetof(RgbaColor, r) == 0);
FNV_STATIC_ASSERT(offsetof(RgbaColor, g) == 4);
FNV_STATIC_ASSERT(offsetof(RgbaColor, b) == 8);
FNV_STATIC_ASSERT(offsetof(RgbaColor, a) == 12);
#pragma pack(push, 4)
class NiPSysEmitter : public NiPSysModifier
{
  public:
    virtual void LoadBinary(NiStream&);
    // base NiPSysModifier at +0x0, size 24
    float m_fEmissionSpeed;         // +0x18, 4 bytes
    float m_fSpeedVariation;        // +0x1C, 4 bytes
    float m_fEmissionDeclination;   // +0x20, 4 bytes
    float m_fDeclinationVariation;  // +0x24, 4 bytes
    float m_fEmissionPlanarAngle;   // +0x28, 4 bytes
    float m_fPlanarAngleVariation;  // +0x2C, 4 bytes
    RgbaColor m_kParticleColor;     // +0x30, 16 bytes
    float m_fEmissionRadius;        // +0x40, 4 bytes
    float m_fRadiusVariation;       // +0x44, 4 bytes
    float m_fYValue;                // +0x48, 4 bytes
    float m_fLifeSpanVariation;     // +0x4C, 4 bytes
    float m_fScale;                 // +0x50, 4 bytes
    // const NiRTTI* __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(NiStream&)
    // void __cdecl NiPSysEmitter::*(NiStream&)
    // bool __cdecl NiPSysEmitter::*(NiStream&)
    // void __cdecl NiPSysEmitter::*(NiStream&)
    // bool __cdecl NiPSysEmitter::*(NiObject*)
    // void __cdecl NiPSysEmitter::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiPSysEmitter::*(float, NiPSysData*)
    // float __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(float)
    // float __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(float)
    // float __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(float)
    // float __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(float)
    // float __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(float)
    // float __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(float)
    // RgbaColor __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(const RgbaColor&)
    // float __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(float)
    // float __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(float)
    // float __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(float)
    // float __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(float)
    // float __cdecl NiPSysEmitter::*()
    // void __cdecl NiPSysEmitter::*(float)
    // NiPSysEmitter
    // void __cdecl NiPSysEmitter::*()
    // NiPSysEmitter& __cdecl NiPSysEmitter::*(const NiPSysEmitter&)
    // void __cdecl NiPSysEmitter::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysEmitter) == 84);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fEmissionSpeed) == 24);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fSpeedVariation) == 28);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fEmissionDeclination) == 32);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fDeclinationVariation) == 36);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fEmissionPlanarAngle) == 40);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fPlanarAngleVariation) == 44);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_kParticleColor) == 48);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fEmissionRadius) == 64);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fRadiusVariation) == 68);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fYValue) == 72);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fLifeSpanVariation) == 76);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fScale) == 80);
#endif
