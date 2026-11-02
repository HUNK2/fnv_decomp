// gamebryo2.2/corelibs/niparticle/nipsyssphereemitter_decls.h: declares NiBinaryStream, NiStream, NiPSysVolumeEmitter, NiPSysSphereEmitter
#ifndef NIPSYSSPHEREEMITTER_DECLS_H
#define NIPSYSSPHEREEMITTER_DECLS_H

class NiBinaryStream
{
  public:
    unsigned int unknown;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
    {
        unsigned int(__cdecl * reader)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int) = read;
        position += reader(this, buffer, bytes, sizes, count);
    }
};
class NiStream
{
  public:
    char padding[0x24c];
    NiBinaryStream* input;
};
class NiPSysVolumeEmitter
{
  public:
    virtual void LoadBinary(NiStream& stream);
    char padding[0x54];
};
class NiPSysSphereEmitter : public NiPSysVolumeEmitter
{
  public:
    float m_fBoundRadius;
    virtual void LoadBinary(NiStream& stream);
};
inline void __fastcall ReadBinaryValue(NiStream& stream, float& value)
{
    NiBinaryStream* input = stream.input;
    unsigned int reader = reinterpret_cast<unsigned int>(input->read);
    unsigned int size = 4;
    input->position +=
        reinterpret_cast<unsigned int(__cdecl*)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int)>(
            reader)(input, &value, 4, &size, 1);
}
#endif
