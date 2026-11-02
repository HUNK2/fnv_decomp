// gamebryo2.2/corelibs/niparticle/nipsyscylinderemitter_decls.h: declares NiBinaryStream, NiStream, NiPSysVolumeEmitter, NiPSysCylinderEmitter
#ifndef NIPSYSCYLINDEREMITTER_DECLS_H
#define NIPSYSCYLINDEREMITTER_DECLS_H

class NiBinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiPosition;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadFloat(float& value)
    {
        unsigned int size = 4;
        m_uiPosition += m_pfnRead(this, &value, 4, &size, 1);
    }
};
class NiStream
{
  public:
    unsigned char padding[0x24c];
    NiBinaryStream* m_pUnderlyingStream;
};
class NiPSysVolumeEmitter
{
  public:
    virtual void LoadBinary(NiStream&);
    unsigned char padding[0x54];
};
class NiPSysCylinderEmitter : public NiPSysVolumeEmitter
{
  public:
    float m_fCylinderRadius;
    float m_fCylinderHeight;
    virtual void LoadBinary(NiStream&);
};
#endif
