// gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderinterface.cpp: NiD3DShaderInterface (11 functions)

#include "nid3dshaderinterface_decls.h"

// @fnv 0x00e81a90
bool NiD3DShaderInterface::Initialize()
{
    if (!NiRenderer::ms_pRenderer)
        return false;
    SetShaderObject((GraphicsRenderer*)NiRenderer::ms_pRenderer);
    return NiShader::Initialize();
}

// @fnv 0x00e818d0
void NiD3DShaderInterface::SetShaderObject(GraphicsRenderer* renderer)
{
    m_pShaderObject = renderer;
    if (renderer)
    {
        ShaderPassRenderer* state = renderer->m_pCurrentRenderState;
        if (m_pRenderState)
        {
            typedef void(__stdcall * ReleaseFunction)(ShaderPassRenderer*);
            ReleaseFunction release = (ReleaseFunction)m_pRenderState->m_ppVirtualMethodTable[2];
            release(m_pRenderState);
        }
        m_pRenderState = state;
        if (state)
        {
            typedef void(__stdcall * AddRefFunction)(ShaderPassRenderer*);
            AddRefFunction addRef = (AddRefFunction)state->m_ppVirtualMethodTable[1];
            addRef(state);
        }
        m_pD3DDevice = m_pShaderObject->m_pD3DDevice;
    }
    else
    {
        m_pD3DDevice = 0;
        if (m_pRenderState)
        {
            typedef void(__stdcall * ReleaseFunction)(ShaderPassRenderer*);
            ReleaseFunction release = (ReleaseFunction)m_pRenderState->m_ppVirtualMethodTable[2];
            release(m_pRenderState);
        }
        m_pRenderState = 0;
    }
}

// @fnv 0x00e81940
unsigned int NiD3DShaderInterface::InitializeShaderRenderer(GraphicsRenderer* renderer)
{
    Direct3DDeviceInterface* device = renderer->m_pD3DDevice;
    FUN_00e7f920(renderer);
    FUN_00e7e8d0(renderer);
    DAT_0126f99c = device;
    FUN_00e92f70(renderer);
    FUN_00e93f50(renderer);
    NiD3DPass::SetActiveRenderer(renderer);
    device->vfn_100();
    NiD3DShaderFactory* factory = NiD3DShaderFactory::GetShaderFactory();
    if (factory)
        factory->vfn_70(renderer);
    if (!DAT_0126fa10)
    {
        Program* p = (Program*)NiMemObject::operator new(28);
        DAT_0126fa10 = p ? p->FUN_00e93ad0() : 0;
        if (!DAT_0126fa10)
            NiD3DDefaultShader::SetShaderName("Failed to create shader program factory!");
    }
    return 0;
}

extern int vftable_NiRefObject;
extern int DAT_0109f584;
extern long volatile DAT_011f4400;
extern int EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

// Sets the vtable and clears fields of the object, increments the global counter, then assigns the second vtable and initializes the remaining fields.
// @fnv 0x00a8f440
void* __fastcall FUN_00a8f440(void* apObject)
{
    *(int**)apObject = &vftable_NiRefObject;
    *((int*)apObject + 1) = 0;
    InterlockedIncrement(&DAT_011f4400);
    *(int**)apObject = &DAT_0109f584;
    *((int*)apObject + 2) = EmptyFS;
    *((int*)apObject + 3) = 0;
    *((char*)apObject + 16) = 0;
    return apObject;
}

extern const char* const g_011f603c_arg1;
// @fnv 0x00a8f1b0
const char* const* __fastcall FUN_00a8f1b0(void* p, int)
{
    return &g_011f603c_arg1;
}

extern const char* const g_0126f75c_arg1;
// @fnv 0x00a8f480
const char* const* __fastcall FUN_00a8f480(void* p, int)
{
    return &g_0126f75c_arg1;
}

struct VF
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void Op(int);
};
void FUN_00aa0000();
void DestroyProgram();
// @fnv 0x00e819f0
int FUN_00e819f0()
{
    VF* pShaderFactory = (VF*)NiD3DShaderFactory::GetShaderFactory();
    if (pShaderFactory)
    {
        FUN_00aa0000();
        pShaderFactory->Op(0);
    }
    FUN_00e7f920(0);
    FUN_00e7e8d0(0);
    DAT_0126f99c = 0;
    DestroyProgram();
    FUN_00e92f70(0);
    FUN_00e93f50(0);
    NiD3DPass::SetActiveRenderer(0);
    return 0;
}

extern int DAT_010ef39c;
struct Rel
{
    virtual void a();
    virtual void b();
    virtual unsigned long __stdcall Release();
};
struct Obj
{
    void* vt;
    int p[4];
    Rel* dev;
    int r;
    int s;
};
void __fastcall FUN_00a8f490(Obj*);
// Sets the object's vtable, clears r and s, releases dev if set, nulls dev, then calls FUN_00a8f490.
// @fnv 0x00e81a50
void __fastcall FUN_00e81a50(Obj* pObj, int)
{
    *(int**)pObj = &DAT_010ef39c;
    Rel* d = pObj->dev;
    pObj->r = 0;
    pObj->s = 0;
    if (d)
        d->Release();
    pObj->dev = 0;
    FUN_00a8f490(pObj);
}

namespace fnv_00e81ab0 {
extern int DAT_010ef39c;
struct Rel
{
    virtual void a();
    virtual void b();
    virtual unsigned long __stdcall Release();
};
struct Obj
{
    void* vt;
    int p[4];
    Rel* dev;
    int r;
    int s;
};
void __fastcall FUN_00a8f490(Obj*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
// @fnv 0x00e81ab0
Obj* __fastcall FUN_00e81ab0(Obj* o, int, unsigned int flags)
{
    *(int**)o = &DAT_010ef39c;
    Rel* d = o->dev;
    o->r = 0;
    o->s = 0;
    if (d)
        d->Release();
    o->dev = 0;
    FUN_00a8f490(o);
    if (flags & 1)
        __Dummy_00b6fef0(o, 0x24);
    return o;
}
}  // namespace fnv_00e81ab0

struct Rf
{
    virtual void a();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
extern void* DAT_0126fa2c;
extern Rf* DAT_0126fa28;
// Stores r in DAT_0126fa2c and, if r is non-null, releases the old DAT_0126fa28 and AddRefs the object at r+0x288; otherwise releases and clears DAT_0126fa28.
// @fnv 0x00e93f50
void FUN_00e93f50(void* apObject)
{
    DAT_0126fa2c = apObject;
    if (apObject)
    {
        Rf* pRef = *(Rf**)((char*)apObject + 0x288);
        if (DAT_0126fa28)
            DAT_0126fa28->Release();
        DAT_0126fa28 = pRef;
        if (pRef)
            pRef->AddRef();
    }
    else
    {
        if (DAT_0126fa28)
            DAT_0126fa28->Release();
        DAT_0126fa28 = 0;
    }
}

// Constructor of a derived object: base ctor call, two zeroed fields, vtable pointer, one more zeroed field.
extern int DAT_0109f4dc;

struct FUN_00a8f190_cls
{
    void* m_pVTable;  // +0x00
    int m_i04;        // +0x04
    int m_i08;        // +0x08
    int m_i0C;        // +0x0C
    int m_i10;        // +0x10

    void Init();  // base constructor (external)

    FUN_00a8f190_cls();
};

// @fnv 0x00a8f190
FUN_00a8f190_cls::FUN_00a8f190_cls()
{
    Init();
    m_i08 = 0;
    m_i0C = 0;
    *(void* volatile*)&m_pVTable = &DAT_0109f4dc;
    *(int volatile*)&m_i10 = 0;
}
