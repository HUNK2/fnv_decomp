
// src/bsshader/bsshaderbloodsplatter_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/bsshaderbloodsplatter.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bsshaderbloodsplatter_types_BSShaderBloodSplatter.h"
#include "bsshaderbloodsplatter_types_BSShaderManager.h"
#include "bsshaderbloodsplatter_types_NiConsoleShaderDeclaration.h"
extern GraphicsRenderer* g_pkRenderer;
extern float g_splatterDefaultFirst;
extern float g_splatterDefaultSecond;
extern float g_splatterValueA;
extern char g_splatterWhiteFlashPath[];
extern char g_splatterWhiteFlashTexture;
struct SplatterFloat4
{
    float x;
    float y;
    float z;
    float w;
};
#include "bsshaderbloodsplatter_decls.h"
struct SplatterShaderInfo
{
    const char* file;
    _D3DXMACRO macros[9];
};
struct FUN_00b807c0_shell
{
    int __thiscall FUN_00b807c0(void* a, void* b);
};
extern int g_011fedc8;
int* __cdecl FUN_00b807b0();

struct FUN_0068ab60_shell
{
    void __thiscall FUN_0068ab80();
    void __thiscall FUN_0068ab60();
};
// @fnv 0x0068ab60
void __thiscall FUN_0068ab60_shell::FUN_0068ab60()
{
    FUN_0068ab80();
}
