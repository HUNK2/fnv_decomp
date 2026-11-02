// bsshader/tileshader.cpp: TileShader, TileStandin, TileShaderS, PassShader (18 functions)

#include "tileshader_decls.h"

// @fnv 0x00bcac60
void TileShader::UpdateMaterial(const NiPropertyState* state)
{
    NiMaterialPropertyView* material = (NiMaterialPropertyView*)state->m_spProperties[3];
    if (material->m_bUnknown)
        AddToCounterIfIdle(0, 0);

    NiRendererSpecificPropertyView* rendererSpecific = (NiRendererSpecificPropertyView*)state->m_spProperties[4];
    if (rendererSpecific && (rendererSpecific->m_ucFlags & 1))
        UpdateRendererStateCount(0, 0);
}

class NiGPUProgram;

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer<T>& operator=(T* pObject);
};

extern NiGPUProgram* DAT_012021e0;
extern NiGPUProgram* DAT_012021e4;
extern int DAT_0126f74c;

// @fnv 0x00bcb180
void __fastcall SelectGPUProgram(char* this_ptr, int, int arg)
{
    switch (arg)
    {
    case 0x24c:
        DAT_0126f74c = *(int*)(this_ptr + 0x6c);
        *(NiPointer<NiGPUProgram>*)(this_ptr + 0x28) = DAT_012021e0;
        break;
    case 0x24d:
        DAT_0126f74c = *(int*)(this_ptr + 0x70);
        *(NiPointer<NiGPUProgram>*)(this_ptr + 0x28) = DAT_012021e4;
        break;
    }
}

extern int DAT_0126f74c;

struct FUN_00bca500_shell
{
    void __thiscall FUN_00bca500(void* p);
};

// @fnv 0x00bca500
void __thiscall FUN_00bca500_shell::FUN_00bca500(void* p)
{
    DAT_0126f74c = *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x6c);
}

extern "C" void* g_012021b8;

// @fnv 0x00bca6b0
void* __cdecl FUN_00bca6b0()
{
    return &g_012021b8;
}

// Sets byte at offset 8 of the objects at thisptr+0x84/0x88/0x8c based on whether a3 equals 0x24d, then calls vtable slot 0x24 on the object at thisptr+0x34.
// @fnv 0x00bcb1d0
void __fastcall SetFlagState(void* thisptr, int, int a3)
{
    char* obj84 = *(char**)((char*)thisptr + 0x84);
    char al;
    if (a3 != 0x24d)
    {
        obj84[8] = 1;
        al = 0;
    }
    else
    {
        obj84[8] = 0;
        al = 1;
    }
    *(char*)(*(char**)((char*)thisptr + 0x88) + 8) = al;
    *(char*)(*(char**)((char*)thisptr + 0x8c) + 8) = al;
    char* obj34 = *(char**)((char*)thisptr + 0x34);
    void** vtable = *(void***)obj34;
    typedef void(__thiscall * VFunc)(void*);
    ((VFunc)vtable[0x24 / 4])(obj34);
}

struct VShader
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void UnkA0() = 0;
};
struct PShader
{
    virtual void g00() = 0;
    virtual void g01() = 0;
    virtual void g02() = 0;
    virtual void g03() = 0;
    virtual void g04() = 0;
    virtual void g05() = 0;
    virtual void g06() = 0;
    virtual void g07() = 0;
    virtual void g08() = 0;
    virtual void g09() = 0;
    virtual void g10() = 0;
    virtual void g11() = 0;
    virtual void g12() = 0;
    virtual void g13() = 0;
    virtual void g14() = 0;
    virtual void g15() = 0;
    virtual void g16() = 0;
    virtual void g17() = 0;
    virtual void g18() = 0;
    virtual void g19() = 0;
    virtual void g20() = 0;
    virtual void g21() = 0;
    virtual void g22() = 0;
    virtual void g23() = 0;
    virtual void g24() = 0;
    virtual void g25() = 0;
    virtual void g26() = 0;
    virtual void g27() = 0;
    virtual void g28() = 0;
    virtual void g29() = 0;
    virtual void g30() = 0;
    virtual void g31() = 0;
    virtual void g32() = 0;
    virtual void g33() = 0;
    virtual void Unk88() = 0;
};
struct TileStandin
{
    char _0[0x28];
    int unk28;
    char _1[0x44];
    VShader* vs[3];
    PShader* ps[3];
    void FUN_00be08b0();
    void FUN_00bca070();
};
// Calls UnkA0 on each non-null vertex shader when unk28 is set, then Unk88 on each non-null pixel shader, and finally calls FUN_00be08b0.
// @fnv 0x00bca070
void TileStandin::FUN_00bca070()
{
    unsigned int i;
    if (unk28)
    {
        for (i = 0; i < 3; i++)
        {
            VShader* p = vs[i];
            if (p)
                p->UnkA0();
        }
    }
    for (i = 0; i < 3; i++)
    {
        PShader* p = ps[i];
        if (p)
            p->Unk88();
    }
    FUN_00be08b0();
}

void __cdecl _delete(void*, unsigned int);
struct X
{
    void __thiscall FUN_00bca510();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// Calls FUN_00bca510, then if bit 0 of a1 is set frees this with _delete and returns this.
// @fnv 0x00bcae60
void* __thiscall X::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00bca510();
    if (auiFlags & 1)
        _delete(this, 0x90);
    return this;
}

namespace fnv_00bcaca0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class NiPointer
{
  public:
    NiPointer()
    {
        m_pObject = 0;
    }
    ~NiPointer()
    {
        if (m_pObject)
            ((RefObj*)m_pObject)->DecRefCount();
    }
    NiPointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                ((RefObj*)m_pObject)->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                ((RefObj*)m_pObject)->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};

class NiD3DPass;
class NiD3DPixelShader;
class NiD3DVertexShader;

struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float fR, float fG, float fB, float fA)
    {
        r = fR;
        g = fG;
        b = fB;
        a = fA;
    }
};

extern RgbaColor DAT_01202188;
extern RgbaColor DAT_012021a8;

struct BSShader
{
    BSShader();
    virtual ~BSShader();
    char pad04[0x60];
    bool m_b64;
    int m_i68;
};

struct FUN_00bcaca0 : public BSShader
{
    NiPointer<NiD3DPass> m_spPass[1];
    NiPointer<NiD3DPixelShader> m_spPS1[3];
    NiPointer<NiD3DPixelShader> m_spPS2[3];
    NiPointer<NiD3DVertexShader> m_sp88;
    NiPointer<NiD3DVertexShader> m_sp8c;
    FUN_00bcaca0(NiD3DVertexShader* p1, NiD3DVertexShader* p2);
    virtual ~FUN_00bcaca0();
};

// @fnv 0x00bcaca0
FUN_00bcaca0::FUN_00bcaca0(NiD3DVertexShader* pVertexShader1, NiD3DVertexShader* pVertexShader2)
{
    m_b64 = true;
    m_i68 = 0x14;
    m_sp88 = pVertexShader1;
    m_sp8c = pVertexShader2;
    DAT_01202188 = RgbaColor(1.0f, 1.0f, 1.0f, 1.0f);
    DAT_012021a8 = RgbaColor(1.0f, 1.0f, 1.0f, 1.0f);
}
}  // namespace fnv_00bcaca0

struct FUN_00bcaff0_shell : public TileShader
{
    void CreateShaderConstantMaps();
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
    static void __cdecl operator delete(void*);
};
struct NiD3DShaderConstantMap : public BSFadeNode
{
    virtual void v0();
    virtual void DeleteThis();
    virtual int AddEntry(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*, unsigned int,
                         unsigned int, const void*, bool);
    long m_uiRefCount;
    char pad8[0x3c];
    NiD3DShaderConstantMap(void*, int);
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <class T> struct NiPtr
{
    T* m_pObject;
    NiPtr& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
    bool operator==(T* p) const
    {
        return m_pObject == p;
    }
};
struct TileShaderLayout
{
    char pad0[0x18];
    void* m_pOwnerShader;
    char pad1c[0x14];
    NiPtr<NiD3DShaderConstantMap> m_spSecondShaderConstantMap;
    NiPtr<NiD3DShaderConstantMap> m_spFirstShaderConstantMap;
};
extern float DAT_01202188[4];
extern float DAT_01202198[4];

// Lazily creates the two NiD3DShaderConstantMap objects and adds the tintcolor, WorldViewProjTranspose and TexScroll entries.
// @fnv 0x00bcaff0
void FUN_00bcaff0_shell::CreateShaderConstantMaps()
{
    TileShaderLayout* p = (TileShaderLayout*)this;
    if (p->m_spSecondShaderConstantMap == 0)
    {
        p->m_spSecondShaderConstantMap = new NiD3DShaderConstantMap(p->m_pOwnerShader, 2);
        p->m_spSecondShaderConstantMap->AddEntry("tintcolor", 0x10000007, 0, 0, 1, "", 0x10, 4, DAT_01202188, false);
    }
    if (p->m_spFirstShaderConstantMap == 0)
    {
        p->m_spFirstShaderConstantMap = new NiD3DShaderConstantMap(p->m_pOwnerShader, 0);
        p->m_spFirstShaderConstantMap->AddEntry("WorldViewProjTranspose", 0x20000009, 0, 0, 4, 0, 0, 0, 0, false);
        p->m_spFirstShaderConstantMap->AddEntry("TexScroll", 0x10000007, 0, 4, 1, "", 0x10, 4, DAT_01202198, false);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct _D3DXMACRO
{
    const char* Name;
    const char* Definition;
};
struct NiD3DVertexShader
{
    virtual void v0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};
struct VSPtr_bca0d0
{
    NiD3DVertexShader* m_pObject;
    VSPtr_bca0d0& operator=(NiD3DVertexShader* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct BSShader
{
    virtual ~BSShader();
    unsigned int m_uiRefCount;  // +04
    static void __cdecl GetShaderPath(char const*, char*);
    NiD3DVertexShader* CompileVertexShader(char const*, _D3DXMACRO const*, char const*, char const*);
};
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
extern const char $SG3295[];
void* _fnv_zlib_memset(void*, int, unsigned int);
struct TileShaderDef_bca0d0
{
    const char* pFile;
    _D3DXMACRO kMacros[9];
};
struct FUN_00bca0d0_shell : BSShader
{
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    VSPtr_bca0d0 m_spVertexShaders[3];
    void CreateTileVertexShaders();
};
// @fnv 0x00bca0d0
void FUN_00bca0d0_shell::CreateTileVertexShaders()
{
    TileShaderDef_bca0d0 kDefs[3];
    kDefs[0].pFile = "tile\\tile.v.hlsl";
    kDefs[0].kMacros[0].Name = 0;
    _fnv_zlib_memset(&kDefs[0].kMacros[0].Definition, 0, 0x44);
    kDefs[1].pFile = "tile\\tile.v.hlsl";
    kDefs[1].kMacros[0].Name = "TEXSCROLL";
    kDefs[1].kMacros[0].Definition = $SG3295;
    kDefs[1].kMacros[1].Name = 0;
    _fnv_zlib_memset(&kDefs[1].kMacros[1].Definition, 0, 0x3c);
    kDefs[2].pFile = "tile\\tile.v.hlsl";
    kDefs[2].kMacros[0].Name = "VC";
    kDefs[2].kMacros[0].Definition = $SG3295;
    kDefs[2].kMacros[1].Name = 0;
    _fnv_zlib_memset(&kDefs[2].kMacros[1].Definition, 0, 0x3c);
    char acName[260];
    char acPath[260];
    for (int i = 0; i < 3; i++)
    {
        if (kDefs[i].pFile)
        {
            BSShader::GetShaderPath(kDefs[i].pFile, acPath);
            _sprintf_s(acName, 260, "TILE1%03i.vso", i);
            m_spVertexShaders[i] = CompileVertexShader(acPath, kDefs[i].kMacros, "vs_1_1", acName);
        }
    }
}

struct NiShader
{
    virtual void Initialize();
};
struct NiD3DPass
{
    void DestroyPass();
};
struct FUN_00bca6c0_shell : NiShader
{
    bool FUN_00bca6c0();
};
// Calls NiShader::Initialize, then releases three pairs of reference-counted objects and a NiD3DPass, clearing each pointer and returning true.
// @fnv 0x00bca6c0
bool FUN_00bca6c0_shell::FUN_00bca6c0()
{
    NiShader::Initialize();
    for (int i = 0; i < 3; ++i)
    {
        void* pObject = *(void**)((char*)this + 0x70 + i * 4);
        if (pObject)
        {
            if (InterlockedDecrement((volatile long*)((char*)pObject + 4)) == 0)
                ((void(__thiscall*)(void*))(*(void***)pObject)[1])(pObject);
            *(void**)((char*)this + 0x70 + i * 4) = 0;
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        void* pObject = *(void**)((char*)this + 0x7c + i * 4);
        if (pObject)
        {
            if (InterlockedDecrement((volatile long*)((char*)pObject + 4)) == 0)
                ((void(__thiscall*)(void*))(*(void***)pObject)[1])(pObject);
            *(void**)((char*)this + 0x7c + i * 4) = 0;
        }
    }
    void* pass = *(void**)((char*)this + 0x6c);
    if (pass)
    {
        if (--*(int*)((char*)pass + 0x64) == 0)
            ((NiD3DPass*)pass)->DestroyPass();
        *(void**)((char*)this + 0x6c) = 0;
    }
    return true;
}

extern void* DAT_011f9508;

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct NiD3DVertexDeclaration
{
    static NiD3DVertexDeclaration* __cdecl Create(void*, unsigned int, unsigned int);

    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void vfn_08c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void vfn_0b4();
};

struct FUN_00bcaca0 : A51BF0Base
{
    FUN_00bcaca0(NiD3DVertexDeclaration*, NiD3DVertexDeclaration*);

    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void vfn_04c();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void vfn_0c0(NiD3DVertexDeclaration*);
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void vfn_11c();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void vfn_13c();
    virtual void v80();
    virtual void v81();
    virtual void vfn_148();
    virtual void vfn_14c();

    char m_ucUnknownByte[0x8c];
};

// @fnv 0x00bcae90
FUN_00bcaca0* FUN_00bcae90()
{
    NiD3DVertexDeclaration* pFirstObject = NiD3DVertexDeclaration::Create(DAT_011f9508, 2, 1);
    NiD3DVertexDeclaration* pSecondObject = NiD3DVertexDeclaration::Create(DAT_011f9508, 3, 1);

    pFirstObject->vfn_08c(0, 0, 0, 2, 0);
    pFirstObject->vfn_08c(1, 0, 5, 1, 0);
    pFirstObject->vfn_0b4();

    pSecondObject->vfn_08c(0, 0, 0, 2, 0);
    pSecondObject->vfn_08c(1, 0, 5, 1, 0);
    pSecondObject->vfn_08c(2, 0, 4, 3, 0);
    pSecondObject->vfn_0b4();

    FUN_00bcaca0* pshader = new FUN_00bcaca0(pFirstObject, pSecondObject);

    pshader->vfn_04c();
    pshader->vfn_13c();
    pshader->vfn_148();
    pshader->vfn_14c();
    pshader->vfn_11c();
    pshader->vfn_0c0(pFirstObject);

    return pshader;
}

extern unsigned int DAT_011ffce8;
extern unsigned long DAT_011ff9d8[];
extern void* DAT_011f9508;

struct SlotObj
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
    virtual void Target(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
};

struct Renderer8b8
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    unsigned int unk8ac;
    unsigned int unk8b0;
    unsigned int unk8b4;
    SlotObj* m_pk08b8;
};

// If the counter at DAT_011ff9d8[idx] is zero, calls Target(0xae, a1 & 0xFF, 0, 0) on m_pk08b8, then adds a2 to the counter.
// @fnv 0x00b984f0
void AddToCounterIfIdle(unsigned int uiValue, unsigned int uiIncrement)
{
    unsigned int idx = DAT_011ffce8;
    if (DAT_011ff9d8[idx] == 0)
    {
        Renderer8b8* pR = (Renderer8b8*)DAT_011f9508;
        SlotObj* p = pR->m_pk08b8;
        p->Target(0xae, uiValue & 0xFF, 0, 0);
    }
    DAT_011ff9d8[idx] += uiIncrement;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class NiD3DGPUProgramCache
{
  public:
    static const char* __cdecl GetPixelShaderProfile(bool);
};

struct NiD3DPixelShader
{
    virtual void v0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

struct PSPtr_bca240
{
    NiD3DPixelShader* m_pObject;
    PSPtr_bca240& operator=(NiD3DPixelShader* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

struct TileShaderDef_bca240
{
    const char* pFile;
    _D3DXMACRO kMacros[9];
};

struct FUN_00bca240_shell : BSShader
{
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    PSPtr_bca240 m_spPixelShaders[3];
    NiD3DPixelShader* CompilePixelShader(char const*, _D3DXMACRO const*, char const*, char const*);
    void CreateTilePixelShaders();
};

// Builds three tile pixel-shader definitions, resolves the pixel shader profile, and creates each shader into m_spPixelShaders.
// @fnv 0x00bca240
void FUN_00bca240_shell::CreateTilePixelShaders()
{
    TileShaderDef_bca240 kDefs[3];
    kDefs[0].pFile = "tile\\tile.p.hlsl";
    kDefs[0].kMacros[0].Name = 0;
    _fnv_zlib_memset(&kDefs[0].kMacros[0].Definition, 0, 0x44);
    kDefs[1].pFile = "tile\\tile.p.hlsl";
    kDefs[1].kMacros[0].Name = "ALPHAMAP";
    kDefs[1].kMacros[0].Definition = "";
    kDefs[1].kMacros[1].Name = 0;
    _fnv_zlib_memset(&kDefs[1].kMacros[1].Definition, 0, 0x3c);
    kDefs[2].pFile = "tile\\tile.p.hlsl";
    kDefs[2].kMacros[0].Name = "VC";
    kDefs[2].kMacros[0].Definition = "";
    kDefs[2].kMacros[1].Name = 0;
    _fnv_zlib_memset(&kDefs[2].kMacros[1].Definition, 0, 0x3c);
    const char* pPixelShaderProfile = NiD3DGPUProgramCache::GetPixelShaderProfile(true);
    for (int i = 0; i < 3; i++)
    {
        if (kDefs[i].pFile)
        {
            char acPath[260];
            char acName[260];
            GetShaderPath(kDefs[i].pFile, acPath);
            _sprintf_s(acName, 260, "TILE1%03i.pso", i);
            m_spPixelShaders[i] = CompilePixelShader(acPath, kDefs[i].kMacros, pPixelShaderProfile, acName);
        }
    }
}

struct RefObject
{
    virtual void Slot0();
    virtual void DeleteThis();
    volatile long refs;
    void Dec()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
struct FUN_00b66f20
{
    RefObject* object;
    ~FUN_00b66f20()
    {
        if (object)
            object->Dec();
    }
    void Clear()
    {
        if (object)
        {
            object->Dec();
            object = 0;
        }
    }
};
struct PassObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int refs;
    void DestroyPass();
    void Dec()
    {
        if (--refs == 0)
            DestroyPass();
    }
};
struct FUN_00b79930
{
    PassObject* object;
    ~FUN_00b79930()
    {
        if (object)
            object->Dec();
    }
    void Clear()
    {
        if (object)
        {
            object->Dec();
            object = 0;
        }
    }
};
struct FUN_00be0f10
{
    virtual ~FUN_00be0f10();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int value60;
    unsigned char enabled64;
    unsigned int unk68;
};
struct FUN_00bca510 : FUN_00be0f10
{
    FUN_00b79930 pass[1];
    FUN_00b66f20 vertex[3];
    FUN_00b66f20 pixel[3];
    FUN_00b66f20 other88;
    FUN_00b66f20 other8c;
    virtual ~FUN_00bca510();
};
// Releases the vertex, pixel and pass references, then resets enabled64, other88 and value60.
// @fnv 0x00bca510
FUN_00bca510::~FUN_00bca510()
{
    for (unsigned int i = 0; i < 3; ++i)
        vertex[i].Clear();
    for (unsigned int i = 0; i < 3; ++i)
        pixel[i].Clear();
    pass[0].Clear();
    enabled64 = 0;
    other88.Clear();
    value60 = 0;
}

struct Stage321
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int refCount;
    void ReturnToPool();
    void FUN_00e7def0(unsigned int mode);
    void Release()
    {
        --refCount;
        if (refCount == 0)
            ReturnToPool();
    }
};
struct StagePtr321
{
    Stage321* object;
    StagePtr321() : object(0)
    {}
    ~StagePtr321()
    {
        if (object)
            object->Release();
    }
};
struct RenderState321
{
    void SetNodeValue(unsigned int state, unsigned int value, bool save);
};
RenderState321* FUN_00e7f5d0();
struct Pass321
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int stageCount;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    RenderState321* state;
    void FUN_00e802b0(unsigned int index, Stage321* stage);
    RenderState321* GetState()
    {
        if (!state)
            state = FUN_00e7f5d0();
        return state;
    }
};
void FUN_00e804d0(Pass321*&);
void AssignStageFromPool(Stage321*&);
void ConfigureBeamStage(Stage321*, unsigned int, unsigned int, unsigned int, unsigned int);
struct Shader321
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    Pass321* pass;
    bool ConfigurePassStages();
};
// @fnv 0x00bca3c0
bool Shader321::ConfigurePassStages()
{
    FUN_00e804d0(pass);
    StagePtr321 stage;
    AssignStageFromPool(stage.object);
    ConfigureBeamStage(stage.object, 0, 1, 2, 1);
    pass->FUN_00e802b0(pass->stageCount, stage.object);
    stage.object->FUN_00e7def0(1);
    AssignStageFromPool(stage.object);
    ConfigureBeamStage(stage.object, 1, 1, 2, 1);
    pass->FUN_00e802b0(pass->stageCount, stage.object);
    pass->GetState()->SetNodeValue(7, 0, true);
    pass->GetState()->SetNodeValue(14, 0, true);
    pass->GetState()->SetNodeValue(168, 15, true);
    return true;
}

namespace fnv_00bca980 {
struct RgbaColor
{
    float r;
    float g;
    float b;
    float a;
};
struct NiRectF
{
    float left;
    float right;
    float top;
    float bottom;
};
struct NiRectI
{
    int left;
    int top;
    int right;
    int bottom;
};

extern RgbaColor DAT_01202188;
extern float DAT_01202198;
extern float DAT_0120219c;
extern float DAT_012021a0;
extern float DAT_012021a4;
extern NiRectF DAT_011ad840;
extern unsigned char DAT_011f9426;
extern char DAT_011f4288;

void AccumulateAndDispatch(int, int, int, int, int);
void FUN_00b980c0(unsigned int, unsigned int, unsigned int, unsigned int);
void FUN_00b98180(unsigned int, unsigned int, unsigned int, unsigned int);

struct RenderTarget
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0C;
};

struct ShaderCtxB8
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    void* unk34;
};

struct ShaderCtx
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void* unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    ShaderCtxB8* unkB8;
    void* unkBC;
};

struct ShaderManager
{
    ShaderCtx* unk00;
};
extern ShaderManager* DAT_011f91e0;

struct ShaderList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    void* unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    void* unk5C;
};
extern ShaderList* DAT_0126f74c;

struct AlphaProp
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    float unk3C;
};

struct MaterialProp
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    RgbaColor unk68;
    float unk78;
    float unk7C;
    float unk80;
    float unk84;
    float unk88;
    char unk8C;
    char unk8D;
    char unk8E;
    char unk8F;
    char unk90;
    bool unk91;
    char unk92;
    char unk93;
    int unk94;
    int unk98;
    NiRectI unk9C;
    bool unkAC;
};

struct FlagProp
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short unk18;
    unsigned int unk1C;
    unsigned int unk20;
};

struct Shader
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v28();
    virtual void v29();
    virtual void Draw(void*, ShaderCtx*, void*, int, void*, const NiPropertyState*, int, void*, void*, int, int);
};

struct Renderer
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual int GetC8();
    virtual int GetCC();
    virtual void d52();
    virtual RenderTarget* GetD4();
};
extern Renderer* DAT_011f4748;

struct ShaderProp
{
    void FUN_00e6fbb0(void*, int);
};

struct TileShaderS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ShaderProp* unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    Shader* unk30;
    Shader* unk34;
    void FUN_00bca980(const NiPropertyState* state);
};

// @fnv 0x00bca980
void TileShaderS::FUN_00bca980(const NiPropertyState* state)
{
    ShaderManager* mgr = DAT_011f91e0;
    if (!mgr)
        return;
    ShaderCtx* ctx = mgr->unk00;
    void* sub68 = &ctx->unk68;
    void* v20 = ctx->unk20;
    if (!v20)
        v20 = &DAT_011f4288;
    void* p34 = ctx->unkB8->unk34;
    void* vBC = ctx->unkBC;
    MaterialProp* mat = (MaterialProp*)state->m_spProperties[3];
    unk18->FUN_00e6fbb0(sub68, 0);

    if (mat->unk91)
    {
        DAT_01202198 = mat->unk7C;
        DAT_0120219c = mat->unk80;
        DAT_012021a0 = mat->unk84;
        DAT_012021a4 = mat->unk88;
    }
    float scale = 1.0f;
    DAT_01202188 = mat->unk68;
    AlphaProp* pAlpha = (AlphaProp*)state->m_spProperties[2];
    if (pAlpha)
        scale = pAlpha->unk3C;
    DAT_01202188.a = mat->unk78 * scale;

    Shader* pShader = unk30;
    if (pShader)
    {
        void* q = DAT_0126f74c->unk44;
        if (q)
            pShader->Draw(q, ctx, vBC, 0, p34, state, 0, sub68, v20, 0, 1);
    }
    pShader = unk34;
    if (pShader)
    {
        void* q = DAT_0126f74c->unk5C;
        if (q)
            pShader->Draw(q, ctx, vBC, 0, p34, state, 0, sub68, v20, 0, 1);
    }

    if (mat->unkAC)
    {
        NiRectI rect = mat->unk9C;
        if (DAT_011f9426)
        {
            Renderer* dev = DAT_011f4748;
            if (DAT_011f4748->GetCC() == dev->GetC8())
            {
                NiRectF vp = DAT_011ad840;
                unsigned int h1 = DAT_011f4748->GetD4()->unk0C;
                RenderTarget* rt = DAT_011f4748->GetD4();
                rect.top = (int)(h1 * vp.bottom + rect.top * (vp.top - vp.bottom));
                rect.bottom = (int)(rt->unk0C * vp.bottom + rect.bottom * (vp.top - vp.bottom));
            }
        }
        AddToCounterIfIdle(1, 0);
        AccumulateAndDispatch(rect.left, rect.top, rect.right, rect.bottom, 0);
    }

    FlagProp* pFlag = (FlagProp*)state->m_spProperties[4];
    if (pFlag && (pFlag->unk18 & 1))
    {
        UpdateRendererStateCount(1, 0);
        FUN_00b980c0((pFlag->unk18 >> 1) & 7, (pFlag->unk18 >> 4) & 7, (pFlag->unk18 >> 7) & 7, 0);
        FUN_00b98180(pFlag->unk18 >> 12, pFlag->unk1C, pFlag->unk20, 0);
    }
}
}  // namespace fnv_00bca980

namespace fnv_00bca760 {
template <class T> struct FieldPtr
{
    T* object;
    __forceinline operator T*() const
    {
        return object;
    }
    __forceinline T* operator->() const
    {
        return object;
    }
};

struct Renderer
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void SetVertexShader(int iHandle);
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void SetPixelShader(int iHandle);
};

struct ShaderProgram
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual int GetVertexHandle(int i);
    virtual void vf80();
    virtual int GetHandle(int i);
};

struct RefTarget
{
    void* vtable;
    int unk04;
    void* m_pFlagTarget;
    int unk0C;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    unsigned int m_uiRefCount;

    void ApplyPairToState(int iValue);
    void FUN_00e7eb00(bool bFlag);
    void FUN_00e7ecd0();

    __forceinline void IncRefCount()
    {
        ++m_uiRefCount;
    }
    __forceinline void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            FUN_00e7ecd0();
    }
};

template <class T> class RefPtr
{
  public:
    __forceinline RefPtr(T* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~RefPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    __forceinline T* operator->() const
    {
        return m_pObject;
    }
    __forceinline operator T*() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

struct TargetPair
{
    RefTarget* m_pFirst;
    RefTarget* m_pSecond;
};

struct ShaderState
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    TargetPair* m_pTargets;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    ShaderProgram* m_pVertexProgram;
    int unk48, unk4C, unk50, unk54, unk58;
    ShaderProgram* m_pPixelProgram;

    Renderer* FUN_00e7f7c0();
    void FUN_00b79950(void* pValue);
    void FUN_00b80600(void* pValue);
};

extern ShaderState* DAT_0126f74c;

struct GeometryData
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    void* m_pFlagTarget;
    FieldPtr<GeometryData> m_pNext;
    __forceinline GeometryData* GetNext() const
    {
        return m_pNext;
    }
    __forceinline bool GetAlt() const
    {
        return m_bAlt;
    }
    __forceinline bool GetSecond() const
    {
        return m_bSecondPass;
    }
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88;
    int m_iTargetValue;
    unsigned char unk90;
    bool m_bAlt;
    bool m_bSecondPass;
    unsigned char m_bNoTarget;
};

struct RenderPassArg
{
    int unk00, unk04, unk08;
    GeometryData* m_pkGeometryData;
};

struct PassShader
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void SetConstant(unsigned int uiValue);
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    FieldPtr<void> m_pVertexA;
    FieldPtr<void> m_pVertexB;
    FieldPtr<void> m_pVertexC;
    FieldPtr<void> m_pPixelA;
    FieldPtr<void> m_pPixelB;
    FieldPtr<void> m_pPixelC;
    unsigned int m_uiConstA;
    unsigned int m_uiConstB;

    void ApplyToRenderer(RenderPassArg* pArg);
};

struct PassFlags
{
    unsigned char alt;
    unsigned char raw;
    unsigned char second;
    bool next;
};

// Sets vertex and pixel shader handles and constants on the renderer based on pass flags, then applies target pairs and flag targets to the shader state.
// @fnv 0x00bca760
void PassShader::ApplyToRenderer(RenderPassArg* pArg)
{
    GeometryData* pGeom = pArg->m_pkGeometryData;
    bool bAlt = pGeom->GetAlt();
    bool bNext = pGeom->GetNext() != 0;
    bool bSecond = pGeom->GetSecond();
    Renderer* pRenderer = DAT_0126f74c->FUN_00e7f7c0();
    ShaderState* state = DAT_0126f74c;
    if (!bSecond)
    {
        if (bAlt)
            state->FUN_00b79950(m_pVertexB);
        else
            state->FUN_00b79950(m_pVertexA);
        pRenderer->SetPixelShader(DAT_0126f74c->m_pPixelProgram->GetHandle(0));
        state = DAT_0126f74c;
        if (bNext)
        {
            state->FUN_00b80600(m_pPixelB);
            pRenderer->SetVertexShader(DAT_0126f74c->m_pVertexProgram->GetVertexHandle(0));
        }
        else
        {
            state->FUN_00b80600(m_pPixelA);
            pRenderer->SetVertexShader(DAT_0126f74c->m_pVertexProgram->GetVertexHandle(0));
        }
        {
            unsigned int uiConst = m_uiConstA;
            SetConstant(uiConst);
        }
    }
    else
    {
        state->FUN_00b79950(m_pVertexC);
        void* pPixelC = m_pPixelC;
        DAT_0126f74c->FUN_00b80600(pPixelC);
        pRenderer->SetPixelShader(DAT_0126f74c->m_pPixelProgram->GetHandle(0));
        pRenderer->SetVertexShader(DAT_0126f74c->m_pVertexProgram->GetVertexHandle(0));
        {
            unsigned int uiConst = m_uiConstB;
            SetConstant(uiConst);
        }
    }

    int iValue = bAlt ? 3 : pGeom->m_iTargetValue;
    RefPtr<RefTarget> spFirst(DAT_0126f74c->m_pTargets->m_pFirst);
    RefPtr<RefTarget> spSecond(DAT_0126f74c->m_pTargets->m_pSecond);
    spFirst->ApplyPairToState(iValue);
    if (!pGeom->m_bNoTarget && pGeom->m_pFlagTarget)
    {
        spFirst->m_pFlagTarget = pGeom->m_pFlagTarget;
        spFirst->FUN_00e7eb00(true);
    }
    GeometryData* pNext = pGeom->m_pNext;
    if (pNext)
    {
        spSecond->ApplyPairToState(0);
        spSecond->m_pFlagTarget = pNext;
        spSecond->FUN_00e7eb00(false);
    }
    else if (spSecond)
    {
        spSecond->m_pFlagTarget = 0;
    }
}
}  // namespace fnv_00bca760
