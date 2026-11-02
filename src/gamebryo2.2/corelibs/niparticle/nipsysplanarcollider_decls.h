// gamebryo2.2/corelibs/niparticle/nipsysplanarcollider_decls.h: declares NiBinaryStream, NiStream, NiColor
#ifndef NIPSYSPLANARCOLLIDER_DECLS_H
#define NIPSYSPLANARCOLLIDER_DECLS_H

#include "nipsysplanarcollider_types_NiPSysPlanarCollider.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
struct NiBinaryStream
{
    unsigned unused;
    unsigned position;
    unsigned(__cdecl* read)(NiBinaryStream*, void*, unsigned, unsigned*, unsigned);
    void Read(void* buffer, unsigned bytes)
    {
        unsigned size;
        position += read(this, buffer, bytes, (size = bytes, &size), 1);
    }
};
class NiStream
{
  public:
    char padding[0x24c];
    NiBinaryStream* input;
    void ResetStreamState();
};
class NiColor
{
  public:
    void LoadBinary(NiStream&);
};
inline void PlanarReadFloat(NiStream& stream, float& value)
{
    stream.input->Read(&value, 4);
}
#endif
