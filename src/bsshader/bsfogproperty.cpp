// bsshader/bsfogproperty.cpp: BSFogProperty, StandIn (8 functions)

#include "bsfogproperty_decls.h"
// @fnv 0x00bb8180
BSFogProperty::BSFogProperty()
{
    m_fFogStartDistance = (1.0 - m_fFogDepth * DAT_010b9e30) * DAT_0103a480;
    m_fFogEndDistance = 163840.0f;
    m_kFogPlane.x = 0.0f;
    m_kFogPlane.y = 0.0f;
    m_kFogPlane.z = 0.0f;
    m_kFogPlane.c = 0.0f;
    m_fAlpha = 1.0f;
}

struct FUN_00bb8140_shell : public BSFogProperty
{
    void SetDepthParams(float);
};

// Stores a scaled depth value at offset 0x2c and the constant 163840.0f at offset 0x30.
// @fnv 0x00bb8140
void FUN_00bb8140_shell::SetDepthParams(float afDepth)
{
    *(float*)((char*)this + 0x2c) = (1.0 - afDepth * DAT_010b9e30) * DAT_0103a480;
    *(float*)((char*)this + 0x30) = 163840.0f;
}

struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_00a5c240_shell : public NiFogProperty
{
    void DestroyFogProperty();
};

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

extern unsigned char* DAT_0109b244;
extern int EmptyFS;

struct NiRefObject
{
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

struct NiAVObject
{
    void UpdateModelBound();
};

// @fnv 0x00a5c240
void FUN_00a5c240_shell::DestroyFogProperty()
{
    *(void**)this = (void*)&DAT_0109b244;
    ((NiAVObject*)this)->UpdateModelBound();

    NiRefObject* pExtra = *(NiRefObject**)((char*)this + 0xc);
    if (pExtra)
        pExtra->DecRefCount();

    char* pString = *(char**)((char*)this + 8);
    if (pString != (char*)EmptyFS)
    {
        InterlockedDecrement((volatile long*)(pString - 8));
    }

    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
}

extern int g_012007e0;

// @fnv 0x00bb8170
int* __cdecl FUN_00bb8170()
{
    return &g_012007e0;
}

extern char const* const g_012007e0_arg1;

// @fnv 0x00a99f20
char const* const* __cdecl FUN_00a99f20()
{
    return &g_012007e0_arg1;
}

void __fastcall DestroyFogProperty(void*);
void __cdecl _delete(void*, unsigned int);
struct S00a99f40
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls DestroyFogProperty on this, deletes this with size 0x2c when bit 0 of a1 is set, and returns this.
// @fnv 0x00a99f40
void* S00a99f40::DestroyIfFlagged(unsigned int auiFlags)
{
    DestroyFogProperty(this);
    if (auiFlags & 1)
        _delete(this, 0x2c);
    return this;
}

void __cdecl ReleaseObjectArray(void*);
extern int DAT_010a1458;
struct MMStandIn
{
    void __thiscall _DeallocateAlias(void*);
};
extern MMStandIn g_memoryManager;
struct StandIn
{
    void* __thiscall Destroy(unsigned int);
};
// @fnv 0x00a9bbc0
void* __thiscall StandIn::Destroy(unsigned int auiFlags)
{
    void* p = *(void**)((char*)this + 4);
    *(void**)this = (void*)&DAT_010a1458;
    ReleaseObjectArray(p);
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

void DestroyFogProperty();
// @fnv 0x00a99f30
void FUN_00a99f30()
{
    DestroyFogProperty();
}
