
// src/fallout_shared/bgsragdoll_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsragdoll.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bgsragdoll_types_BGSRagdoll.h"
#include <malloc.h>
template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);
class TESFileLoadView : public TESFile
{
  public:
    unsigned int GetTESForm();
};
class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int formID);
};
int __cdecl Warning(const char*, ...);
void __cdecl operator delete(void*);
class BGSBodyPartData : public TESForm
{
};
class TESActorBase : public TESForm
{
};

struct StandIn_C74FB0
{
    unsigned char flag00;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    int i38;
    int i3C;
    int unk40;
    unsigned short* data44;
    unsigned int count48;

    bool FUN_00c74fb0(const StandIn_C74FB0& other) const;
};

// @fnv 0x00c74fb0
bool StandIn_C74FB0::FUN_00c74fb0(const StandIn_C74FB0& other) const
{
    bool diff = false;
    if (count48 != other.count48)
        goto fail;
    {
        unsigned int i = 0;
        while (i < count48)
        {
            if (diff)
                goto fail;
            diff = data44[i] != other.data44[i];
            i++;
        }
    }
    if (diff)
        goto fail;
    if (flag00 != other.flag00)
        goto fail;
    if (f04 != other.f04)
        goto fail;
    if (f08 != other.f08)
        goto fail;
    if (f0C != other.f0C)
        goto fail;
    if (f10 != other.f10)
        goto fail;
    if (f14 != other.f14)
        goto fail;
    if (f18 != other.f18)
        goto fail;
    if (f1C != other.f1C)
        goto fail;
    if (f20 != other.f20)
        goto fail;
    if (f24 != other.f24)
        goto fail;
    if (f28 != other.f28)
        goto fail;
    if (f2C != other.f2C)
        goto fail;
    if (f30 != other.f30)
        goto fail;
    if (i38 != other.i38)
        goto fail;
    if (i3C != other.i3C)
        goto fail;
    if (f34 != other.f34)
        goto fail;
    goto done;
fail:
    diff = true;
done:
    return diff;
}

// FUN_005effb0 : MSVC this-adjusting thunk  (sub ecx, 0x18 ; jmp <impl>)
struct A1_005effb0
{
    A1_005effb0();
    virtual void FUN_005effb0();
    char pad[0x14];
};
struct A2_005effb0
{
    A2_005effb0();
    virtual void FUN_005effb0();
};
struct Own_005effb0 : A1_005effb0, A2_005effb0
{
    Own_005effb0();
    virtual void key_fn();
// @fnv 0x005effb0
    void FUN_005effb0();
};
Own_005effb0::Own_005effb0()
{}
void Own_005effb0::key_fn()
{}
Own_005effb0* make_005effb0()
{
    static Own_005effb0 o;
    return &o;
}
