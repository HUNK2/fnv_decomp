
// src/bssystem/bssearchpath_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/bssystem/bssearchpath.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/bssystem/bssearchpath.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bssystem/bssearchpath.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct BSSearchPath
{
    bool FUN_00b013e0(char* apFile);
};
struct FUN_00b01c40_shell
{
    void SetByteAt45(unsigned char u8);
};
struct FUN_00b01c70_shell
{
    int __thiscall FUN_00b01c70(int a, int b);
};
struct FUN_00b01c80_shell
{
    void FUN_00b01c80(int a1);
};
struct BSWin32FileCache
{
    int FUN_00b01c90(int arg);
};
struct FUN_00b01ca0_shell
{
    void FUN_00b01ca0(int a, int b);
};
struct FUN_00b01cb0_shell
{
    bool FUN_00b01cb0(int arg1);
};
struct FUN_00b01cc0_shell
{
    void __thiscall FUN_00b01cc0(int);
};
struct FUN_00b01cd0_shell
{
    void FUN_00b01cd0();
};
struct FUN_00b01ce0_shell
{
    void __thiscall FUN_00b01ce0(int);
};
struct FUN_00b01cf0_shell
{
    void FUN_00b01cf0(float a, float b, float c, float d);
};
struct FUN_00b01d10_shell
{
    bool __thiscall FUN_00b01d10(int a);
};
struct FUN_00b01c60_shell
{
    void FUN_00b01c60();
};
struct FUN_00b01d00_shell
{
    void __thiscall FUN_00b01d00();
};
struct S_00b01d20_MemoryManager
{
    void Deallocate(void* p);
};
extern S_00b01d20_MemoryManager g_00b01d20_MemoryManager;
struct S_00b01d20_FileCache
{
    virtual ~S_00b01d20_FileCache();
    S_00b01d20_FileCache* DestroyFileCache(unsigned int uiFlags);
};
struct FUN_00b01390_cls
{
    int unk00;
    int m_uiItemCount;
    char m_path[0x104];

    bool CopyPathOnce(char* out, int unused);
};
int __cdecl FUN_00ec65a6(char* dst, unsigned int size, const char* src);

struct MemMgrSP
{
    void* __thiscall Allocate(unsigned int uiSize);
};
extern MemMgrSP g_memMgrSP;

struct NiSearchPathSP
{
    NiSearchPathSP();
    virtual ~NiSearchPathSP();
    int m_004, m_008, m_00c, m_010, m_014, m_018, m_01c, m_020;
    int m_024, m_028, m_02c, m_030, m_034, m_038, m_03c, m_040;
    int m_044, m_048, m_04c, m_050, m_054, m_058, m_05c, m_060;
    int m_064, m_068, m_06c, m_070, m_074, m_078, m_07c, m_080;
    int m_084, m_088, m_08c, m_090, m_094, m_098, m_09c, m_0a0;
    int m_0a4, m_0a8, m_0ac, m_0b0, m_0b4, m_0b8, m_0bc, m_0c0;
    int m_0c4, m_0c8, m_0cc, m_0d0, m_0d4, m_0d8, m_0dc, m_0e0;
    int m_0e4, m_0e8, m_0ec, m_0f0, m_0f4, m_0f8, m_0fc, m_100;
    int m_104, m_108, m_10c;
};

struct BSSearchPathSP : NiSearchPathSP
{
    virtual ~BSSearchPathSP();
    int m_110, m_114, m_118, m_11c, m_120, m_124, m_128, m_12c;
    int m_130, m_134, m_138, m_13c, m_140, m_144, m_148, m_14c;
    int m_150, m_154, m_158, m_15c, m_160, m_164, m_168, m_16c;
    int m_170, m_174, m_178, m_17c, m_180, m_184, m_188, m_18c;
    int m_190, m_194, m_198, m_19c, m_1a0, m_1a4, m_1a8, m_1ac;
    int m_1b0, m_1b4, m_1b8, m_1bc, m_1c0, m_1c4, m_1c8, m_1cc;
    int m_1d0, m_1d4, m_1d8, m_1dc, m_1e0, m_1e4, m_1e8, m_1ec;
    int m_1f0, m_1f4, m_1f8, m_1fc, m_200, m_204, m_208, m_20c;
    static void* operator new(unsigned int uiSize)
    {
        return g_memMgrSP.Allocate(uiSize);
    }
};

// @fnv 0x00b013f0
void* FUN_00b013f0()
{
    return new BSSearchPathSP;
}
