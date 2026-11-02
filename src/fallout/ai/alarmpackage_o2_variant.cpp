
// src/fallout/ai/alarmpackage_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/alarmpackage.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "alarmpackage_decls.h"
TESForm* __cdecl GetFormByID(unsigned int);
struct ChangesMap
{
    bool FUN_00855220(unsigned int, bool);
};
struct FUN_0085a290_t
{
    ChangesMap* pChanges;
    void DeleteForm(TESForm*);
    void DeleteFormById(unsigned int id);
};
struct Actor;
struct LH
{
    bool IsInList(Actor*&);
};
struct Crime
{
    unsigned char _pad[0x1c];
    LH _list;
    bool IsActorInList(Actor* apActor);
};
struct Actor;
struct SL
{
    void _ref_00905330(Actor* const& a);
};
struct FUN_009eba00_t
{
    int m_uiItemCount;
    void FUN_009eba00(Actor* a);
};
struct BSSimpleListTESRaceSize
{
    bool _ref_008256d0();
    int GetSize();
};
struct FUN_009ebab0_host
{
    char _pad[0x1C];
    BSSimpleListTESRaceSize _list;
    int GetRaceListSize();
};
void __cdecl Deallocate(void*);
struct FUN_009ec640_t
{
    void FUN_009ec700();
    FUN_009ec640_t* FUN_009ec640(unsigned int flags);
};
struct G2
{
    void AddHead(int* const& a);
};
struct FUN_009ec830_t
{
    void AddHeadAtOffset(int* a);
};
