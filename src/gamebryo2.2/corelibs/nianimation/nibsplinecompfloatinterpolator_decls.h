#pragma once

class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(float* values)
    {
        unsigned int componentSize = 4;
        position += read(this, values, 8, &componentSize, 1);
    }
};
class NiStream
{
  public:
    char padding[0x24c];
    NiBinaryStream* input;
};
class NiBSplineFloatInterpolator
{
  public:
    virtual void LoadBinary(NiStream&);
    char data[0x20];
};
class NiBSplineCompFloatInterpolator : public NiBSplineFloatInterpolator
{
  public:
    virtual void LoadBinary(NiStream&);
    float m_afOffsetAndHalfRange[2];
};
