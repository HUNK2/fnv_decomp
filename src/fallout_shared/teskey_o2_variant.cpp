
// src/fallout_shared/teskey_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/teskey.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/teskey.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/teskey.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl _Deallocate(void*);
struct TESKey
{
    void* Destroy(unsigned int flags);
    void FUN_0050a6a0();
};

// FUN_0050a760 : MSVC this-adjusting thunk  (sub ecx, 0x3c ; jmp <impl>)
struct A1_0050a760
{
    A1_0050a760();
    virtual void FUN_0050a760();
    char pad[0x38];
};
struct A2_0050a760
{
    A2_0050a760();
    virtual void FUN_0050a760();
};
struct Own_0050a760 : A1_0050a760, A2_0050a760
{
    Own_0050a760();
    virtual void key_fn();
// @fnv 0x0050a760
    void FUN_0050a760();
};
Own_0050a760::Own_0050a760()
{}
void Own_0050a760::key_fn()
{}
Own_0050a760* make_0050a760()
{
    static Own_0050a760 o;
    return &o;
}
