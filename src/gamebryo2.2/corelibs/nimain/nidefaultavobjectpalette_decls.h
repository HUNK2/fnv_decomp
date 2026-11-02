// gamebryo2.2/corelibs/nimain/nidefaultavobjectpalette_decls.h: declares NiBinaryStream
#ifndef NIDEFAULTAVOBJECTPALETTE_DECLS_H
#define NIDEFAULTAVOBJECTPALETTE_DECLS_H


class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int components)
    {
        unsigned int bytesRead = m_pfnRead(this, buffer, bytes, componentSizes, components);
        m_uiStreamFlags += bytesRead;
        return bytesRead;
    }
};

template <class T> void NiBinaryStreamLoad(NiBinaryStream& stream, T* value, unsigned int count = 1)
{
    unsigned int componentSize = sizeof(T);
    stream.BinaryRead(value, sizeof(T) * count, &componentSize, 1);
}

template <class T> void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStreamLoad(*stream.m_pUnderlyingStream, &value, 1);
}

extern NiFixedString EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
void __cdecl NiFree(void*);

#endif
