// gamebryo2.2/corelibs/nimain/nipoint2_decls.h: declares NiBinaryStream, NiStream, NiPoint2
#ifndef NIPOINT2_DECLS_H
#define NIPOINT2_DECLS_H

class NiBinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    __forceinline void ReadFloat(float& value)
    {
        unsigned int size = 4;
        m_uiStreamFlags += m_pfnRead(this, &value, 4, &size, 1);
    }
};
class NiStream
{
  public:
    unsigned char padding[0x24c];
    NiBinaryStream* m_pUnderlyingStream;
};
class NiPoint2
{
  public:
    float x, y;
    void LoadBinary(NiStream& stream);
};
#endif
