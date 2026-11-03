
// src/fallout/ai/combat/vats_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/vats.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "vats_decls.h"
struct BooleanFloatQuery;
struct TESObjectREFR;
struct VATSCommand
{
    void Initialize();
    void* __vecDelDtor(unsigned int);
    int eAction;
    bool bSuccess;
    bool m_kFieldAfterWeaponFlags;
    bool m_bFirstActionFlag;
    bool m_bSecondActionFlag;
    unsigned char m_ucFirstActionCode;
    unsigned char m_ucSecondActionCode;
    char _pad_a[2];
    TESObjectREFR* pTarget;
    int m_iActionValue;
    BooleanFloatQuery* m_pActionObject;
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fOverrideActionPoints;
    bool m_bFinalActionFlag;
    char _pad_25[3];
};
typedef char _sizecheck_VATS_COMMAND[sizeof(VATSCommand) == 40 ? 1 : -1];
struct FUN_009ca410_shell : public VATS
{
    void ProcessVATSCommands();
};
struct PlayerCharacter;
extern PlayerCharacter* DAT_011f21f0;
struct Animation;
struct Actor
{
    Animation* GetAnimation() const;
};
struct FUN_00498910_shell
{
    void Animation_SpecialIdleFree(bool, bool);
};
struct Node
{
    VATSCommand* item;
    Node* next;
};
struct FUN_009ca410_shell_base : public VATS
{
    bool FUN_008256d0();
    Node* FUN_006815c0();
    void FUN_0063f7b0();
};
struct StandIn
{
    void* FUN_009c8870(unsigned int);
};
extern float DAT_011afe74;
extern float DAT_011afe78;
extern unsigned char DAT_012677cc;
float __cdecl FUN_009c8ef0();
struct SoundListEntry;
struct SoundListView
{
    void AddTail(SoundListEntry* const&);
    void AddCommand(SoundListEntry* apCommand);
};
struct ListHolder
{
    bool _ref_008256d0();
    void* _ref_006815c0();
    void* FUN_009c71c0();
};
struct MyList
{
    bool _ref_008256d0();
    MyList* _ref_00726070();
    VATSCommand** _ref_006815c0();
    VATSCommand* FUN_009c71f0();
};
struct bhkWorld
{
    static bool __cdecl QPickCountOverride();
};
float __cdecl FUN_009c8ef0();
extern float DAT_012677c4;
bool __cdecl FUN_009c8ea0();
struct FUN_009c9900_shell
{
    void SetByteAt76(unsigned char param_2);
};
struct FUN_009ca4a0
{
    void FUN_009ca500();
    FUN_009ca4a0();
};
struct Helper62d0
{
    Helper62d0& operator=(void const*);
};
struct FUN_009d9ec0_shell
{
    void AssignAtOffsetB0(void* p);
};
