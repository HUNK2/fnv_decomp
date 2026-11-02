// gamebryo2.2/corelibs/nimain/nipoint3_stream.h: declares NiBinaryStream, NiStream, NiColor
struct NiBinaryStream
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* write)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data)
    {
        unsigned int size = 4;
        position += read(this, data, 4, &size, 1);
    }
    void Write(const void* data)
    {
        unsigned int size = 4;
        position += write(this, data, 4, &size, 1);
    }
};
class NiStream
{
  public:
    char padding[0x24c];
    NiBinaryStream* input;
    NiBinaryStream* output;
};
class NiColor
{
  public:
    float r, g, b;
    void LoadBinary(NiStream&);
    void SaveBinary(NiStream&);
};
