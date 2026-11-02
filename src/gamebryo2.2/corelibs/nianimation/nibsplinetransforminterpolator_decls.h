
class NiStream;
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadScalar(void* value, unsigned int size)
    {
        unsigned int componentSize = size;
        position += read(this, value, size, &componentSize, 1);
    }
};
class NiStream
{
  public:
    char prefix[0x24c];
    NiBinaryStream* m_pUnderlyingStream;
};
class NiQuatTransform
{
  public:
    char data[0x20];
    void LoadBinary(NiStream&);
};
class NiBSplineInterpolator
{
  public:
    char data[0x1c];
    void LoadBinary(NiStream&);
};
class NiBSplineTransformInterpolator : public NiBSplineInterpolator
{
  public:
    NiQuatTransform m_kTransform;
    unsigned int m_uiTranslationHandle;
    unsigned int m_uiRotationHandle;
    unsigned int m_uiScaleHandle;
    void LoadBinary(NiStream&);
};
