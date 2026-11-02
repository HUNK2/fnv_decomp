// bsshader/bsorderednode_decls.h: declares NiBinaryStream, NiStream, NiNode, NiSphere, BSOrderedNode
#ifndef BSORDEREDNODE_DECLS_H
#define BSORDEREDNODE_DECLS_H
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, const unsigned int*, unsigned int);
    unsigned int Read(void* buffer, unsigned int bytes)
    {
        unsigned int size = 1;
        unsigned int result = read(this, buffer, bytes, &size, 1);
        position += result;
        return result;
    }
};
class NiStream
{
  public:
    void* vtable;
    unsigned int version;
    char padding[0x244];
    NiBinaryStream* input;
};
class NiNode
{
  public:
    char data[0xac];
    void LoadBinary(NiStream&);
};
class NiSphere
{
  public:
    char data[16];
    void LoadBinary(NiStream&);
};
class BSOrderedNode : public NiNode
{
  public:
    NiSphere bound;
    bool staticBound;
    void LoadBinary(NiStream&);
};
#endif
