// gamebryo2.2/corelibs/niparticle/nipsysdata_stream.h: declares NiBinaryStream
#ifndef NIPSYSDATA_STREAM_H
#define NIPSYSDATA_STREAM_H

class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
};
#endif
