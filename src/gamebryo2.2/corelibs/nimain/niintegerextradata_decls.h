// gamebryo2.2/corelibs/nimain/niintegerextradata_decls.h: declares NiBinaryStream, NiStream, NiExtraData, NiIntegerExtraData
#ifndef NIINTEGEREXTRADATA_DECLS_H
#define NIINTEGEREXTRADATA_DECLS_H

struct NiBinaryStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, const unsigned int*, unsigned int);

    __forceinline void Read(void* data)
    {
        unsigned int size = 4;
        m_uiStreamFlags += m_pfnRead(this, data, 4, &size, 1);
    }
};
__forceinline void NiIntegerRead(void* data, NiBinaryStream* input,
                                 unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, const unsigned int*,
                                                             unsigned int))
{
    unsigned int size = 4;
    input->m_uiStreamFlags += read(input, data, 4, &size, 1);
}
class NiStream
{
  public:
    char padding[0x24c];
    NiBinaryStream* m_pUnderlyingStream;
};
class NiExtraData
{
  public:
    char storage[12];
    void LoadBinary(NiStream& stream);
};
class NiIntegerExtraData : public NiExtraData
{
  public:
    int m_iValue;
    void LoadBinary(NiStream& stream);
};
#endif
