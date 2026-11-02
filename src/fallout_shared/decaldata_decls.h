// fallout_shared/decaldata_decls.h: declares ImpactDecalData, DecalData
#ifndef DECALDATA_DECLS_H
#define DECALDATA_DECLS_H

class TESFile;
struct ImpactDecalData
{
    float m_fDecalMinWidth, m_fDecalMaxWidth, m_fDecalMinHeight, m_fDecalMaxHeight;
    float m_fProjectionDepth, m_fShininess, m_fParallaxScale;
    unsigned char m_ucParallaxPasses, cFlags, padding[2];
    unsigned int iColor;
};
class DecalData
{
  public:
    ImpactDecalData Data;
    DecalData();
    void Copy(DecalData* source);
    void Load(TESFile* file);
    void SwapEndianFields();
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
