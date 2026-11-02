
// src/fallout_shared/bgssceneinfo_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgssceneinfo.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/bgssceneinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgssceneinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_004a7cf0_shell
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int m_002c;
    int m_0030;
    int m_0034;
    int m_0038;
    int m_003c;

    int GetValueAt(int index);
};
struct Flt
{
    operator unsigned int() const;
};
struct Script
{
    int GetText();
};
struct FUN_004a8070_shell
{
    int GetScriptText();
};
extern unsigned char DAT_0118868c;
unsigned char __cdecl FUN_004a82c0();
int __cdecl MinInt(int iA, int iB);
struct FUN_004a8f50_shell
{
    void FUN_004a95d0(int a);
    void* FUN_004a8f50();
};
struct GlobalObject2_0040c150
{
    int* Int();
};
struct GlobalObject2_0045cfe0
{
    int* Int();
};
GlobalObject2_0045cfe0 g_011c59e0;
int FUN_004a9100();
struct DummyArr
{
    int GetBufferElementAddress(unsigned int);
    int FUN_004a95b0(unsigned int);
};
struct FUN_004a9630_shell
{
    void* FUN_004a9630(unsigned int flags);
};
struct FUN_004a9850_shell
{
    void FUN_004a9850();
};
void __cdecl _Deallocate(void* p);
