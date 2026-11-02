
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiD3DShaderProgramCreatorHLSL
{
    unsigned int m_uiCompileFlags;
    void __thiscall FUN_00e91ae0(unsigned int uiFlags);
};

// @fnv 0x00e91ae0
void __thiscall NiD3DShaderProgramCreatorHLSL::FUN_00e91ae0(unsigned int uiFlags)
{
    ((unsigned int*)this)[1] = uiFlags;
}

namespace fnv_00e91c10 {
extern "C" void* __cdecl __Dummy_00b6fef0(void* obj, unsigned int flags);
extern void* DAT_010f0a68;

struct NiD3DShaderProgramCreatorHLSL
{
    void* m_vftable;
    ~NiD3DShaderProgramCreatorHLSL();
    void* Destroy(unsigned int flags);
};

// @fnv 0x00e91c10
void* __thiscall NiD3DShaderProgramCreatorHLSL::Destroy(unsigned int flags)
{
    m_vftable = &DAT_010f0a68;
    if (flags & 1)
    {
        __Dummy_00b6fef0(this, 8);
    }
    return this;
}
}  // namespace fnv_00e91c10

void __cdecl _delete(void*, unsigned int);
extern int DAT_010f0a68;
struct NiD3DShaderProgramCreator
{
    void* vtable;
    void* __thiscall FUN_00e91be0(unsigned int);
};
// @fnv 0x00e91be0
void* __thiscall NiD3DShaderProgramCreator::FUN_00e91be0(unsigned int flags)
{
    vtable = (void*)&DAT_010f0a68;
    if (flags & 1)
        _delete(this, 4);
    return this;
}

void __cdecl _NiFreeAlias(void*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_010f0a68;
extern int DAT_010f0ac0;
struct Holder00e91c40
{
    int m0;
    int m4;
    void* m8;
    int mC;
    void* DestroyHolder(unsigned int);
};
// @fnv 0x00e91c40
void* Holder00e91c40::DestroyHolder(unsigned int auiFlags)
{
    void* p = m8;
    *(void**)this = (void*)&DAT_010f0ac0;
    _NiFreeAlias(p);
    *(void**)this = (void*)&DAT_010f0a68;
    if (auiFlags & 1)
        _delete(this, 0x10);
    return this;
}
