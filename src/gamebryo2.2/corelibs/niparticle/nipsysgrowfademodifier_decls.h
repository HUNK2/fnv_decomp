// gamebryo2.2/corelibs/niparticle/nipsysgrowfademodifier_decls.h: declares NiBinaryStream, NiStream, NiPSysModifier, NiPSysGrowFadeModifier
#pragma once

class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
class NiStream
{
  public:
    void* vtable;
    unsigned int version;
    char padding[0x244];
    NiBinaryStream* m_pUnderlyingStream;
};
class NiPSysModifier
{
  public:
    virtual void LoadBinary(NiStream&);
    char padding[0x14];
};
class NiPSysGrowFadeModifier : public NiPSysModifier
{
  public:
    float m_fGrowthTime;
    unsigned short m_usGrowGenerationLimit;
    float m_fFadeDuration;
    unsigned short m_usFadeGenerationLimit;
    float m_fInitialScale;
    virtual void LoadBinary(NiStream&);
};
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& stream, T* value)
{
    unsigned int size = sizeof(T);
    stream.position += stream.read(&stream, value, sizeof(T), &size, 1);
}
