// gamebryo2.2/corelibs/nimain/nialphaproperty_decls.h: declares NiBinaryStream, NiStream, NiProperty, NiAlphaProperty

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
    char pad0[0xd8];
    unsigned int version;
    char padDC[0x24c - 0xdc];
    NiBinaryStream* input;
    char pad250[0x288 - 0x250];
    unsigned short propertyFlags;
};
class NiProperty
{
  public:
    char base[0x18];
    void LoadBinary(NiStream&);
};
class NiAlphaProperty : public NiProperty
{
  public:
    unsigned short m_uiObjectFlags;
    unsigned char m_ucAlphaThreshold;
    void LoadBinary(NiStream&);
};
