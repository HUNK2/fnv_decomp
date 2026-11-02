// bsshader/bsshadertextureset_stream.h: declares NiBinaryStream
#ifndef BSSHADERTEXTURESET_STREAM_H
#define BSSHADERTEXTURESET_STREAM_H


class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
};

#endif
