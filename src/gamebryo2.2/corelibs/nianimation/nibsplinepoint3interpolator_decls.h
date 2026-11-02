#ifndef NIBSPLINEPOINT3INTERPOLATOR_DECLS_H
#define NIBSPLINEPOINT3INTERPOLATOR_DECLS_H
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadUInt(unsigned int& value)
    {
        unsigned int size = 4;
        position += read(this, &value, 4, &size, 1);
    }
};
class NiStream
{
  public:
    unsigned char prefix[0x24c];
    NiBinaryStream* input;
};
class NiColor
{
  public:
    float r, g, b;
    void LoadBinary(NiStream&);
};
class NiBSplineInterpolator
{
  public:
    virtual void LoadBinary(NiStream&);
    unsigned char data[24];
};
class NiBSplinePoint3Interpolator : public NiBSplineInterpolator
{
  public:
    NiColor m_kPoint3Value;
    unsigned int m_kPoint3CPHandle;
    virtual void LoadBinary(NiStream&);
};
#endif
