// gamebryo2.2/corelibs/nisystem/nibinaryloadsave_decls.h: declares NiBinaryStream, NiStream, AnimationKey, BooleanKey
#ifndef NIBINARYLOADSAVE_DECLS_H
#define NIBINARYLOADSAVE_DECLS_H

class NiBinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* data, unsigned int bytes, unsigned int* sizes, unsigned int count)
    {
        unsigned int result = m_pfnRead(this, data, bytes, sizes, count);
        m_uiStreamFlags += result;
        return result;
    }
};
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& input, T* value)
{
    unsigned int size = sizeof(T);
    input.BinaryRead(value, sizeof(T), &size, 1);
}
class NiStream
{
  public:
    unsigned char padding[0x24c];
    NiBinaryStream* m_pUnderlyingStream;
};
class AnimationKey
{
  public:
    float m_fTime;
};
class BooleanKey : public AnimationKey
{
  public:
    bool m_bValue;
    void LoadBinary(NiStream& stream);
};
#endif
