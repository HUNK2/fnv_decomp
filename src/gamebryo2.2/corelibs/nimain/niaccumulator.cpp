// src/gamebryo2.2/corelibs/nimain/niaccumulator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niaccumulator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern char const* const g_011f6058_arg1;

// @fnv 0x00aa0b00
char const* const* __cdecl NiAccumulator_GetRTTI()
{
    return &g_011f6058_arg1;
}

struct NiRefObject
{
    virtual ~NiRefObject();
};
void __cdecl _delete(void*, unsigned int);
extern int DAT_010a2304;
struct NiAccumulator : NiRefObject
{
    void* FUN_00aa0b10(unsigned int);
};
// Sets the vtable to DAT_010a2304, runs the NiRefObject destructor, and frees this with _delete when a1 has bit 0 set.
// @fnv 0x00aa0b10
void* NiAccumulator::FUN_00aa0b10(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_010a2304;
    this->NiRefObject::~NiRefObject();
    if (auiFlags & 1)
        _delete(this, 12);
    return this;
}
