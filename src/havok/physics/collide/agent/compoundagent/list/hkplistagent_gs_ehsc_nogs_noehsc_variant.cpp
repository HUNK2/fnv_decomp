// src/havok/physics/collide/agent/compoundagent/list/hkplistagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-11-01 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/compoundagent/list/hkplistagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/compoundagent/list/hkplistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/list/hkplistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl FUN_00da3510(void*, void*);
struct hkAgent1nMachine
{
    void __thiscall InvalidateTim(void*);
};
struct hkpListAgent
{
    char m0[0x10];
    void __thiscall FUN_00d36850(void* arg);
};
extern "C" void __cdecl FUN_00d36990(int, int, int, int);
void __stdcall FUN_00d36b00(int aiArg1, int aiArg2, int aiArg3, int aiArg4);
extern "C" void __cdecl FUN_00da35f0(void*, float, float, int);
struct Owner
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void FUN_00d36870(float a1, float a2, int a3);
};
void __cdecl FUN_00d36920(void* a, void* b, void* c, void* d);
void __stdcall FUN_00d36940(void* apArg1, void* apArg2, void* apArg3, void* apArg4);
void __cdecl FUN_00d36930(int a1, int a2, int a3, int a4, int a5);
void __stdcall FUN_00d36960(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5);
extern "C" void __cdecl FUN_00da42b0(void* a, int b, int c, int d);
struct FUN_00d36820_cls
{
    virtual void v00(int a);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void FUN_00d36820(int a1);
};
struct S_00d368a0_Arg
{
    int unk00;
    int unk04;
    int m_field08;
};
void __cdecl FUN_00d97250(void* sub, int field08, S_00d368a0_Arg* arg);
struct S_00d368a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_sub10;

    void FUN_00d368a0(S_00d368a0_Arg* a, int unused);
};
extern "C" void __cdecl FUN_00da48e0(void*, void*);
struct VirtTarget
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    virtual int v10();
};
struct CallArgs
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct FUN_00d368c0_cls
{
    int unk00;
    int unk04;
    int m_08;
    int unk0C;
    int unk10;
    void FUN_00d368c0(void* a1, void* a2, void* a3, void* a4);
};
