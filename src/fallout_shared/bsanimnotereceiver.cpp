
// src/fallout_shared/bsanimnotereceiver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bsanimnotereceiver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct IBSAnimNoteReceiver
{
    virtual ~IBSAnimNoteReceiver();
    void __thiscall FUN_004b0530();
    void* FUN_004b0550(unsigned int flags);
};
void __cdecl _Deallocate(void*);

// Calls FUN_004b0530, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x004b0550
void* IBSAnimNoteReceiver::FUN_004b0550(unsigned int flags)
{
    FUN_004b0530();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct BSAnimNoteReceiver
{
    void __thiscall FUN_004b0480();
    void* __thiscall FUN_004b0580(unsigned int);
};
void __cdecl _Deallocate(void*);

// Calls FUN_004b0480, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004b0580
void* __thiscall BSAnimNoteReceiver::FUN_004b0580(unsigned int flags)
{
    FUN_004b0480();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00658930_class
{
    unsigned int __thiscall GetShortAtOffsetA() const;
};
struct NiFormArray
{
    void*& __thiscall FUN_00877a30(unsigned int index);
};
unsigned int __fastcall FUN_0044ddc0(void* note);
struct ReceiverEntry
{
    unsigned int type;
    void(__cdecl* callback)(void*, void*);
};
struct FUN_004b0730_class
{
    int unk00;
    void* unk04;
    int unk08;
    void __thiscall DispatchNoteToReceivers(void* note);
};
// @fnv 0x004b0730
void FUN_004b0730_class::DispatchNoteToReceivers(void* note)
{
    for (int i = 0; i < ((FUN_00658930_class*)((char*)this + 8))->GetShortAtOffsetA(); ++i)
    {
        if (((ReceiverEntry*)((NiFormArray*)((char*)this + 8))->FUN_00877a30(i))->type == FUN_0044ddc0(note))
        {
            ((ReceiverEntry*)((NiFormArray*)((char*)this + 8))->FUN_00877a30(i))->callback(unk04, note);
        }
    }
}
