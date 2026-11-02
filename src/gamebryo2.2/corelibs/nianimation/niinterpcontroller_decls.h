struct NiBinaryStream
{
    unsigned int vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* buffer, unsigned int bytes)
    {
        unsigned int size = 1;
        position += read(this, buffer, bytes, &size, 1);
    }
};
class NiStream
{
  public:
    char padding[0xd8];
    unsigned int version;
    char padding2[0x24c - 0xdc];
    NiBinaryStream* input;
};
class NiTimeController
{
  public:
    virtual void LinkObject(NiStream&);
    virtual void LoadBinary(NiStream&);
    unsigned int refcount;
    unsigned short flags;
};
class NiInterpController : public NiTimeController
{
  public:
    virtual void LinkObject(NiStream&);
    virtual void LoadBinary(NiStream&);
};

// 0x00c9a6c0 has no canonical PC declaration; private layout used only for
// byte-matching the covered reset function.
struct NiInterpControllerTriple
{
    float f0;
    float f1;
    float f2;
    void ResetTriple();
};
extern double g_d100;  // 0x01017a40 (100.0)