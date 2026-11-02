// gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator_decls.h: declares NiBinaryStream, NiStream, NiBSplineInterpolator, NiBSplineFloatInterpolator
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    template <class T> void Read(T& value)
    {
        unsigned int size = sizeof(T);
        position += read(this, &value, sizeof(T), &size, 1);
    }
};
class NiStream
{
  public:
    char padding[0x24c];
    NiBinaryStream* input;
};
class NiBSplineInterpolator
{
  public:
    virtual void LoadBinary(NiStream& stream);
    char padding[24];
};
class NiBSplineFloatInterpolator : public NiBSplineInterpolator
{
  public:
    virtual void LoadBinary(NiStream& stream);
    float m_fFloatValue;
    unsigned int m_kFloatCPHandle;
};
