#ifndef NIBSPLINECOMPPOINT3INTERPOLATOR_DECLS_H
#define NIBSPLINECOMPPOINT3INTERPOLATOR_DECLS_H

struct NiBinaryStream
{
    unsigned int reserved;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    __forceinline void Read(void* buffer, unsigned int size)
    {
        unsigned int componentSize = 4;
        position += read(this, buffer, size, &componentSize, 1);
    }
};
class NiStream
{
  public:
    char reserved[0x24c];
    NiBinaryStream* input;
};
class NiBSplinePoint3Interpolator
{
  public:
    char reserved[0x2c];
    void LoadBinary(NiStream& stream);
};
class NiBSplineCompPoint3Interpolator : public NiBSplinePoint3Interpolator
{
  public:
    float m_fSequenceOffset;
    float m_fDecodeScale;
    void LoadBinary(NiStream& stream);
};
#endif
