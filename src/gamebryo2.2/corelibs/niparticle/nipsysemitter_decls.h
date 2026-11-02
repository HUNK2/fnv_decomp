// gamebryo2.2/corelibs/niparticle/nipsysemitter_decls.h: declares NiBinaryStream, NiStream
#ifndef FNV_NIPSYSEMITTER_DECLS_H
#define FNV_NIPSYSEMITTER_DECLS_H

class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
class NiStream
{
  public:
    char pad0[0xd8];
    unsigned int m_uiNifVersion;
    char padDC[0x24c - 0xdc];
    NiBinaryStream* m_pUnderlyingStream;
};
inline void BinaryRead(NiBinaryStream* b, void* p)
{
    unsigned int size = 4;
    unsigned int got = b->m_pfnRead(b, p, 4, &size, 1);
    b->m_uiStreamFlags += got;
}
inline void ReadFloat(NiStream& s, float& f)
{
    BinaryRead(s.m_pUnderlyingStream, &f);
}
#endif
