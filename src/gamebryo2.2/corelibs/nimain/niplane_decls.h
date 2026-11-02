// gamebryo2.2/corelibs/nimain/niplane_decls.h: declares NiPoint3, NiPlane, NiColor, NiBinaryStream, NiStream and more
class NiStream;
class NiPoint3
{
  public:
    float x, y, z;
    static const NiPoint3 ZERO;
};
class NiPlane
{
  public:
    NiPoint3 normal;
    float constant;
    NiPlane();
};
class NiColor
{
  public:
    float r, g, b;
    void LoadBinary(NiStream&);
    void SaveBinary(NiStream&);
};
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    typedef unsigned int(__cdecl* Transfer)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    Transfer read, write;
    void Read(float* value)
    {
        unsigned int size = 4;
        position += read(this, value, 4, &size, 1);
    }
    void Write(float* value)
    {
        unsigned int size = 4;
        position += write(this, value, 4, &size, 1);
    }
};
class NiStream
{
  public:
    char padding[0x24c];
    NiBinaryStream* input;
    NiBinaryStream* output;
};
class NiSphere
{
  public:
    NiColor center;
    float radius;
    void LoadBinary(NiStream&);
    void SaveBinary(NiStream&);
};
