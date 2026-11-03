// gamebryo2.2/corelibs/nimain/nisingleshadermaterial.cpp: NiDepthStencilBuffer, StandInUnload (8 functions)

#include "nisingleshadermaterial_decls.h"
// Creates a NiDepthStencilBuffer when format.format is 15, sets width/height, and returns it or 0 if CreateRendererData fails.
// @fnv 0x00a9fe90
NiDepthStencilBuffer* NiDepthStencilBuffer::Create(unsigned int width, unsigned int height, NiRenderer*,
                                                   const NiPixelFormat& format, unsigned int samples)
{
    if (format.format != 15)
        return 0;
    NiDepthStencilBuffer* buffer = new NiDepthStencilBuffer;
    buffer->width = width;
    buffer->height = height;
    if (!buffer->CreateRendererData(format, samples))
    {
        delete buffer;
        return 0;
    }
    return buffer;
}

extern "C" void* g_011f6048;

// @fnv 0x00aa06e0
void* __cdecl NiSingleShaderMaterial_GetRTTI()
{
    return &g_011f6048;
}

struct NiFixedString
{
    char* m_pcString;
};

struct NiShader
{
    NiFixedString m_kShaderFilename;
    NiFixedString const& GetFilename() const;
};

struct NiGeometry;
struct NiSkinInstance;
struct NiPropertyState;
struct NiDynamicEffectState;

struct NiSingleShaderMaterial
{
    NiFixedString m_kShaderFilename;
};

struct FUN_00aa0770_shell : NiSingleShaderMaterial
{
    bool __thiscall MatchesShaderFilename(NiShader* pkShader, const NiGeometry* pkGeometry,
                                          const NiSkinInstance* pkSkinInstance, const NiPropertyState* pkPropertyState,
                                          const NiDynamicEffectState* pkDynamicEffectState,
                                          unsigned int uiMaterialExtraData);
};

// Returns true if pkShader is non-null and its filename string equals the string stored at this+0x0C; otherwise false.
// @fnv 0x00aa0770
bool __thiscall FUN_00aa0770_shell::MatchesShaderFilename(NiShader* pkShader, const NiGeometry* pkGeometry,
                                                          const NiSkinInstance* pkSkinInstance,
                                                          const NiPropertyState* pkPropertyState,
                                                          const NiDynamicEffectState* pkDynamicEffectState,
                                                          unsigned int uiMaterialExtraData)
{
    if (pkShader && pkShader->GetFilename().m_pcString == *(char**)((char*)this + 0x0C))
        return true;
    return false;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct ShaderForUnload
{
    virtual void f0();
    virtual void f1();
    long volatile m_lRef;
};
struct StandInUnload
{
    char _pad[16];
    ShaderForUnload* m_sp;
    bool m_bManual;
    void ReleaseShader();
};
// If not manual, decrements the shader's reference count, calls its release when it hits zero, and clears m_sp.
// @fnv 0x00aa0830
void StandInUnload::ReleaseShader()
{
    if (!m_bManual)
    {
        ShaderForUnload* pShader = m_sp;
        if (pShader)
        {
            if (InterlockedDecrement(&pShader->m_lRef) == 0)
                pShader->f1();
            m_sp = 0;
        }
    }
}

extern int DAT_010a21dc;
extern char* _EmptyFS;

struct NiGlobalStringTable
{
    static char* __cdecl AddString(char const*);
};

struct NiShaderFactory
{
    virtual void f0();
    virtual void f1();
    virtual ShaderForUnload* Create(char const*, int, int);
    static NiShaderFactory* __cdecl GetInstance();
};

struct FUN_00a8f950_shell
{
    void __thiscall FUN_00a8f950(void*);
};

struct FUN_00aa06f0_shell
{
    virtual void f0();
    virtual void f1();
    char _pad[8];
    char* m_pcString;
    void* m_pGeometryShader;
    bool m_bFlag;

    FUN_00aa06f0_shell* FUN_00aa06f0(void*, char const*, bool);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

// @fnv 0x00aa06f0
FUN_00aa06f0_shell* FUN_00aa06f0_shell::FUN_00aa06f0(void* arg1, char const* apcString, bool abCreateShader)
{
    reinterpret_cast<FUN_00a8f950_shell*>(this)->FUN_00a8f950(arg1);

    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_010a21dc);

    if (!apcString)
    {
        m_pcString = _EmptyFS;
    }
    else
    {
        m_pcString = NiGlobalStringTable::AddString(apcString);
    }

    m_pGeometryShader = 0;
    m_bFlag = false;

    if (abCreateShader)
    {
        NiShaderFactory* factory = NiShaderFactory::GetInstance();
        ShaderForUnload* shader = factory->Create(apcString, -1, 0);
        if (shader)
        {
            long volatile* refs = &shader->m_lRef;
            InterlockedIncrement(refs);
            if (!InterlockedDecrement(refs))
            {
                shader->f1();
            }
        }
    }

    return this;
}

struct S_00aa07a0_Obj;
struct S_00aa07a0_Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual bool v48();
    virtual bool v4c();
    int unk04;
    int unk08;
    int FUN_00cc0760();
};
struct S_00aa07a0_Mgr
{
    virtual void v00();
    virtual void v04();
    virtual S_00aa07a0_Obj* v08(int, int, int);
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual bool v24(S_00aa07a0_Obj*);
};
S_00aa07a0_Mgr* FUN_00a9fff0();
struct S_00aa07a0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00aa07a0_Obj* unk10;
    S_00aa07a0_Obj* FUN_00aa07a0(int a, int b, int c, int d, int key);
};
// Returns unk10 if its FUN_00cc0760 matches key (or key is -1 and mgr->v24 accepts it), otherwise asks mgr->v08 for an object and returns it if v48 or v4c holds.
// @fnv 0x00aa07a0
S_00aa07a0_Obj* S_00aa07a0_Class::FUN_00aa07a0(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int key)
{
    S_00aa07a0_Mgr* pManager = FUN_00a9fff0();
    if (unk10)
    {
        if (unk10->FUN_00cc0760() == key)
            return unk10;
        if (key == -1)
        {
            if (pManager)
            {
                S_00aa07a0_Obj* pCached = unk10;
                if (pManager->v24(pCached))
                    return unk10;
            }
        }
    }
    S_00aa07a0_Obj* pResult = 0;
    if (pManager)
    {
        int h = unk0c;
        pResult = pManager->v08(h, key, 1);
    }
    if (pResult && (pResult->v48() || pResult->v4c()))
        return pResult;
    return 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern int DAT_010a21dc;
extern int DAT_0109b220;
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00aa0870_cls
{
    int m_vptr;
    int unk04;
    int unk08;
    char* m_pcString;
    ShaderForUnload* m_sp;
    int unk14;

    void BaseCleanup();

    FUN_00aa0870_cls* Destroy(unsigned char acFlags);
};

// Releases the shader reference and string buffer, runs base cleanup, and optionally frees the 0x18-byte object.
// @fnv 0x00aa0870
FUN_00aa0870_cls* FUN_00aa0870_cls::Destroy(unsigned char acFlags)
{
    long(__stdcall * pfnRelease)(long volatile*) = InterlockedDecrement;
    *(int volatile*)&m_vptr = (int)&DAT_010a21dc;
    ShaderForUnload* sp = *(ShaderForUnload* volatile*)&m_sp;
    if (sp != 0)
    {
        if (pfnRelease(&sp->m_lRef) == 0)
        {
            sp->f1();
        }
    }
    if ((int)m_pcString != DAT_0109b220)
    {
        pfnRelease((long volatile*)((char*)m_pcString - 8));
    }
    BaseCleanup();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x18);
    }
    return this;
}

char* __cdecl FUN_00a5b690(const char* pcString) throw();
void* __cdecl FUN_00aa13e0(unsigned int uiSize) throw();

class BSFixedString
{
  public:
    BSFixedString(const char* pcString) throw()
    {
        if (pcString == 0)
            m_kHandle = (char*)DAT_0109b220;
        else
            m_kHandle = FUN_00a5b690(pcString);
    }

    BSFixedString() throw()
    {}
    BSFixedString& operator=(const char* pcString) throw()
    {
        if (pcString == 0)
            m_kHandle = (char*)DAT_0109b220;
        else
            m_kHandle = FUN_00a5b690(pcString);
        return *this;
    }
    ~BSFixedString() throw()
    {
        if (m_kHandle != (char*)DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
    }

    operator const char*() const
    {
        return m_kHandle;
    }
    char* m_kHandle;
};

class ShaderEntry
{
  public:
    static void* operator new(unsigned int uiSize) throw()
    {
        return FUN_00aa13e0(uiSize);
    }
    static void operator delete(void*) throw()
    {}
    ShaderEntry(const BSFixedString& kName, const char* pcName, bool bFlag) throw();
    virtual void f0();
    virtual void f1();
    int unk04;
    int unk08;
    char* m_pcString;
    void* m_pGeometryShader;
    bool m_bFlag;
};

ShaderEntry* __cdecl FUN_00a8fe20(const char* const& pcName) throw();

// Looks up a ShaderEntry by pcName via FUN_00a8fe20 and returns it, otherwise allocates a new ShaderEntry with pcName and bFlag.
// @fnv 0x00aa08d0
ShaderEntry* __cdecl FindOrCreateShaderEntry(const char* pcName, bool bFlag)
{
    ShaderEntry* pkFound = FUN_00a8fe20(BSFixedString(pcName));
    if (pkFound)
        return pkFound;
    return new ShaderEntry(BSFixedString() = pcName, pcName, bFlag);
}
