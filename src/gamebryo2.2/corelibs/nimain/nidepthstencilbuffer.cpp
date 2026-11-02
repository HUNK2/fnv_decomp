
// src/gamebryo2.2/corelibs/nimain/nidepthstencilbuffer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nidepthstencilbuffer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C"
{
    struct NiRTTI;
}

extern const NiRTTI DAT_011f603c;

// @fnv 0x00a9fe50
const NiRTTI* __cdecl FUN_00a9fe50()
{
    return &DAT_011f603c;
}

extern int vftable_NiDepthStencilBuffer;
struct Helper
{
    void __thiscall FUN_00a8f1c0();
};
void _delete(void*, unsigned int);
struct NiDepthStencilBuffer
{
    void* Destroy(unsigned int);
};
// Sets the vftable, calls FUN_00a8f1c0, and if flag bit 0 is set frees this with size 0x14, returning this.
// @fnv 0x00a9fe60
void* NiDepthStencilBuffer::Destroy(unsigned int auiFlags)
{
    *(void**)this = (void*)&vftable_NiDepthStencilBuffer;
    ((Helper*)this)->FUN_00a8f1c0();
    if (auiFlags & 1)
        _delete(this, 0x14);
    return this;
}
