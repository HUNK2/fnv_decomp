// gamebryo2.2/corelibs/nianimation/niquattransform_binary.h: declares NiBinaryStream
#ifndef NIQUATTRANSFORM_BINARY_H
#define NIQUATTRANSFORM_BINARY_H

class NiBinaryStream;
typedef unsigned int(__cdecl* NiBinaryStreamRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
class NiBinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiPosition;
    NiBinaryStreamRead m_pfnRead;
    __forceinline void ReadScalar(void* data, unsigned int bytes)
    {
        unsigned int size = bytes;
        m_uiPosition += m_pfnRead(this, data, bytes, &size, 1);
    }
};

extern const float kInvalidTransformValue;

#endif
