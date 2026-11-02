
// src/fallout/magic/bhktelekinesislistener_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/bhktelekinesislistener.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout/magic/bhktelekinesislistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/bhktelekinesislistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct bhkTelekinesisListener
{
    void FUN_00807910();
    void* Destroy(unsigned int flags);
};
extern "C" void __cdecl _Deallocate(void*);
struct FUN_00807da0_shell
{
    unsigned short m_0006;
    int FUN_00807da0();
};

// FUN_00807df0 : MSVC this-adjusting thunk  (sub ecx, 0x04 ; jmp <impl>)
struct A1_00807df0
{
    A1_00807df0();
    virtual void FUN_00807df0();
};
struct A2_00807df0
{
    A2_00807df0();
    virtual void FUN_00807df0();
};
struct Own_00807df0 : A1_00807df0, A2_00807df0
{
    Own_00807df0();
    virtual void key_fn();
// @fnv 0x00807df0
    void FUN_00807df0();
};
Own_00807df0::Own_00807df0()
{}
void Own_00807df0::key_fn()
{}
Own_00807df0* make_00807df0()
{
    static Own_00807df0 o;
    return &o;
}

// FUN_00807e00 - MSVC 2008 adjustor thunk (8 bytes):
//
//     sub ecx, 8
//     jmp  0x008078e0
//
// The vftable of a secondary base inside a derived class (the one at
// 0x01079718, RTTI ".?AVbhkTelekinesisListener@@", complete object locator
// offset 8) points at a compiler generated adjustor thunk for the virtual
// that the derived class overrides: the secondary base sub-object starts
// eight bytes into the derived object, so the thunk moves `this' back to the
// derived object and tail-calls the overriding implementation.
//
// The primary base is eight bytes long (its vptr plus one int), which is what
// puts the secondary base at offset 8.  The overriding implementation is only
// declared, never defined, so the jmp stays an undefined external exactly
// like in the image and the checker resolves that relocation from the
// original bytes.

struct bhkTelekinesisListenerBase
{
    bhkTelekinesisListenerBase();
    virtual void* FUN_00807e00(unsigned int flags);
    int unk04;
};

struct bhkTelekinesisListenerSecondary
{
    bhkTelekinesisListenerSecondary();
    virtual void* FUN_00807e00(unsigned int flags);
};

struct bhkTelekinesisListenerDerived : public bhkTelekinesisListenerBase, public bhkTelekinesisListenerSecondary
{
    bhkTelekinesisListenerDerived();
// @fnv 0x00807e00
    virtual void* FUN_00807e00(unsigned int flags);
};

bhkTelekinesisListenerBase::bhkTelekinesisListenerBase()
{}
bhkTelekinesisListenerSecondary::bhkTelekinesisListenerSecondary()
{}
bhkTelekinesisListenerDerived::bhkTelekinesisListenerDerived()
    : bhkTelekinesisListenerBase(), bhkTelekinesisListenerSecondary()
{}
