
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiD3DShaderConstantMap
{
    void* __thiscall Destroy(unsigned int flags);
};

extern "C" void __cdecl FUN_00e87690();
extern "C" void __cdecl __Dummy_00b6fef0(NiD3DShaderConstantMap* p, unsigned int flags);

// Calls FUN_00e87690, then if bit 0 of flags is set calls __Dummy_00b6fef0 on this with 0x44, and returns this.
// @fnv 0x00b7e410
void* __thiscall NiD3DShaderConstantMap::Destroy(unsigned int flags)
{
    FUN_00e87690();
    if (flags & 1)
    {
        __Dummy_00b6fef0(this, 0x44);
    }
    return this;
}

extern int DAT_0126f74c;

struct FUN_00e80610_shell
{
    void __thiscall FUN_00e80610();
};

// @fnv 0x00e80610
void __thiscall FUN_00e80610_shell::FUN_00e80610()
{
    DAT_0126f74c = 0;
    *(int*)((char*)this + 0x38) = 0;
}

extern "C" const char* const g_0126f554_arg1;

// @fnv 0x00e7c680
const char* const* __cdecl FUN_00e7c680()
{
    return &g_0126f554_arg1;
}

struct NiD3DShader
{
    void FUN_00e806c0();
    void* DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// @fnv 0x00e7c690
void* NiD3DShader::DestroyIfFlagged(unsigned int flags)
{
    FUN_00e806c0();
    if (flags & 1)
        _delete(this, 0x3c);
    return this;
}
