// independently confirmed PC canonical declarations. The emitter pointer at
// +0x54 is corroborated by the covered PC LinkObject disassembly.
// Direct qualified calls only; this header does not assert complete vtable slots.
#ifndef FNV_NIPSYSVOLUMEEMITTER_MATCH_TYPES_H
#define FNV_NIPSYSVOLUMEEMITTER_MATCH_TYPES_H

#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObject.h"
class NiAVObject;
class NiStream;
class RgbaColor;
class NiPSysEmitter;
class NiPSysModifier;
class NiPSysVolumeEmitter;
class NiParticleSystem;
class NiPSysModifier : public NiObject
{
  public:
    NiFixedString m_kName;         // +0x8, 4 bytes
    unsigned int m_uiUpdateOrder;  // +0xC, 4 bytes
    NiParticleSystem* m_pkTarget;  // +0x10, 4 bytes
    bool m_bModifierActive;        // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
FNV_STATIC_ASSERT(sizeof(NiPSysModifier) == 24);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_kName) == 8);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_uiUpdateOrder) == 12);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_pkTarget) == 16);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_bModifierActive) == 20);
class RgbaColor
{
  public:
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    float a;  // +0xC, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(RgbaColor) == 16);
FNV_STATIC_ASSERT(offsetof(RgbaColor, r) == 0);
FNV_STATIC_ASSERT(offsetof(RgbaColor, g) == 4);
FNV_STATIC_ASSERT(offsetof(RgbaColor, b) == 8);
FNV_STATIC_ASSERT(offsetof(RgbaColor, a) == 12);
class NiPSysEmitter : public NiPSysModifier
{
  public:
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
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
};
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
class NiPSysVolumeEmitter : public NiPSysEmitter
{
  public:
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    NiAVObject* m_pkEmitterObject;  // +0x54, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(NiPSysVolumeEmitter) == 88);
FNV_STATIC_ASSERT(offsetof(NiPSysVolumeEmitter, m_pkEmitterObject) == 84);
// Only out-of-line interfaces used by this unit. No NiStream layout is accessed.
class NiStream
{
  public:
    void ResetStreamState();
    NiObject* GetLoadedObject();
};
#endif
