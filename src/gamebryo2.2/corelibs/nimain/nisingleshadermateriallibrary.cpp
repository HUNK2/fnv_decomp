
// src/gamebryo2.2/corelibs/nimain/nisingleshadermateriallibrary.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nisingleshadermateriallibrary.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiFixedString
{
    char* m_kHandle;
};
struct NiMaterial;

extern NiMaterial* __cdecl FindOrCreateShaderEntry(NiMaterial*, int);

// @fnv 0x00a8fd60
NiMaterial* __stdcall FUN_00a8fd60(const NiFixedString* kName)
{
    char* p = kName->m_kHandle;
    return FindOrCreateShaderEntry((NiMaterial*)p, 1);
}

extern NiMaterial* DAT_011f5e40;

// @fnv 0x00a8fcc0
void __cdecl FUN_00a8fcc0()
{
    NiMaterial* material = DAT_011f5e40;
    if (material)
        ((void(__thiscall*)(NiMaterial*, int))(*reinterpret_cast<void***>(material))[0])(material, 1);
    DAT_011f5e40 = 0;
}

struct IndexedObjectCollection
{
    unsigned int FUN_00a9ffd0();
};
struct RefCountedNamedObject
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual IndexedObjectCollection* w5();
};
struct NiShaderFactory
{
    static NiShaderFactory* __cdecl GetInstance();
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
    virtual RefCountedNamedObject* v14();
    virtual RefCountedNamedObject* v15();
};
// Walks the shader factory's library list, summing the material count reported by each library's descriptor, and returns the total.
// @fnv 0x00a8fc70
unsigned int FUN_00a8fc70()
{
    RefCountedNamedObject* pkLib;
    NiShaderFactory* pkFactory;
    unsigned int uiTotalMaterials;
    uiTotalMaterials = 0;
    pkFactory = NiShaderFactory::GetInstance();
    if (!pkFactory)
        return uiTotalMaterials;
    pkLib = pkFactory->v14();
    while (pkLib)
    {
        IndexedObjectCollection* pkDesc = pkLib->w5();
        if (pkDesc)
            uiTotalMaterials += pkDesc->FUN_00a9ffd0();
        pkLib = pkFactory->v15();
    }
    return uiTotalMaterials;
}

struct NiGlobalStringTable
{
    static char* __cdecl AddString(const char*);
};
extern char* _EmptyFS;
extern int DAT_0109f7b4;
struct BaseStub
{
    void __thiscall FUN_00a8fe70(char**);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct NiSingleShaderMaterialLibrary
{
    void* _vf;
    char _pad[8];
    int _c;
    int _d;
    NiSingleShaderMaterialLibrary* FUN_00a8fce0();
};
// Registers the class name string, releases it if not empty, zeroes _c and _d, sets the vtable, and returns this.
// @fnv 0x00a8fce0
NiSingleShaderMaterialLibrary* NiSingleShaderMaterialLibrary::FUN_00a8fce0()
{
    char* tmp = NiGlobalStringTable::AddString("NiSingleShaderMaterialLibrary");
    ((BaseStub*)this)->FUN_00a8fe70(&tmp);
    if (tmp != _EmptyFS)
        InterlockedDecrement((long volatile*)(tmp - 8));
    _c = 0;
    _d = 0;
    *(void**)this = (void*)&DAT_0109f7b4;
    return this;
}

struct FUN_00a8fdb0_shell
{
    void FUN_00a8fdb0();
};
extern int DAT_0109f7b4;
void __cdecl _delete(void*, unsigned int);
struct FUN_00a8fd30_shell
{
    void* vfptr;
    int _a;
    int _b;
    void* m1;
    unsigned int m2;
    void* Destroy(unsigned int);
};
// Sets the vfptr to DAT_0109f7b4, clears m1 and m2, calls FUN_00a8fdb0, and deletes this with size 0x14 when flag bit 0 is set.
// @fnv 0x00a8fd30
void* FUN_00a8fd30_shell::Destroy(unsigned int auiFlags)
{
    vfptr = (void*)&DAT_0109f7b4;
    m1 = 0;
    m2 = 0;
    ((FUN_00a8fdb0_shell*)this)->FUN_00a8fdb0();
    if (auiFlags & 1)
        _delete(this, 0x14);
    return this;
}

struct NiShaderLibraryDescHelper
{
    void* FUN_00a9ffe0(int);
};
struct FUN_00a8fac0_shell : NiSingleShaderMaterialLibrary
{
    void* FUN_00a8fac0();
};
// @fnv 0x00a8fac0
void* FUN_00a8fac0_shell::FUN_00a8fac0()
{
    NiShaderFactory* pkFactory = NiShaderFactory::GetInstance();
    RefCountedNamedObject* library = pkFactory->v14();
    *(RefCountedNamedObject**)((char*)this + 0xc) = library;
    *(unsigned int*)((char*)this + 0x10) = 0;
    if (library)
    {
        IndexedObjectCollection* desc = library->w5();
        while (!desc->FUN_00a9ffd0())
        {
            *(RefCountedNamedObject**)((char*)this + 0xc) = pkFactory->v15();
            *(unsigned int*)((char*)this + 0x10) = 0;
            desc = (*(RefCountedNamedObject**)((char*)this + 0xc))->w5();
        }
        if (desc)
        {
            if (desc->FUN_00a9ffd0())
                return ((NiShaderLibraryDescHelper*)desc)->FUN_00a9ffe0(*(unsigned int*)((char*)this + 0x10));
        }
    }
    return 0;
}

// Stand-in for NameProvider (not declared in this unit)
struct NameProvider
{
    virtual void w0();
    virtual void w1();
    virtual const char* GetName();
};

// Stand-in for IndexedObjectCollection::FUN_00a9ffe0 (not visible in this unit)
struct NiShaderLibraryDescStub
{
    void* FUN_00a9ffe0(int);
};

// @fnv 0x00a8fbf0
const char* __stdcall GetShaderNameByIndex(unsigned int uiShaderIndex)
{
    unsigned int uiBaseIndex;
    RefCountedNamedObject* pkLib;
    NiShaderFactory* pkFactory;
    IndexedObjectCollection* pkDesc;
    NameProvider* pkShaderDesc;

    uiBaseIndex = 0;
    pkFactory = NiShaderFactory::GetInstance();
    pkLib = pkFactory->v14();
    if (pkLib)
    {
        do
        {
            pkDesc = pkLib->w5();
            if (pkDesc)
            {
                if (pkDesc->FUN_00a9ffd0() + uiBaseIndex > uiShaderIndex)
                {
                    pkShaderDesc =
                        (NameProvider*)((NiShaderLibraryDescStub*)pkDesc)->FUN_00a9ffe0(uiShaderIndex - uiBaseIndex);
                    return pkShaderDesc->GetName();
                }
                uiBaseIndex += pkDesc->FUN_00a9ffd0();
            }
            pkLib = pkFactory->v15();
        } while (pkLib);
    }
    return 0;
}

void* __cdecl FUN_00a9fff0();

struct FUN_00a8fb50_cls
{
    void* unk00;
    int unk04;
    int unk08;
    RefCountedNamedObject* m_pLibrary;
    unsigned int m_uiPosition;
    void* FUN_00a8fb50();
};

// @fnv 0x00a8fb50
void* FUN_00a8fb50_cls::FUN_00a8fb50()
{
    NiShaderFactory* factory = reinterpret_cast<NiShaderFactory*>(FUN_00a9fff0());
    RefCountedNamedObject* lib = factory->v14();
    if (lib != m_pLibrary)
    {
        do
        {
            lib = factory->v15();
        } while (lib != m_pLibrary);
    }
    m_uiPosition++;
    if (lib == 0)
    {
        goto L_008b;
    }
    IndexedObjectCollection* desc;
L_0035:
    desc = lib->w5();
    if (desc != 0)
    {
        if (desc->FUN_00a9ffd0() > m_uiPosition)
        {
            goto L_0067;
        }
    }
    lib = factory->v15();
    m_pLibrary = lib;
    m_uiPosition = 0;
    if (lib != 0)
    {
        goto L_0035;
    }
L_0067:
    if (m_pLibrary == 0)
    {
        goto L_008b;
    }
    if (desc == 0)
    {
        goto L_008b;
    }
    {
        unsigned int idx = m_uiPosition;
        if (desc->FUN_00a9ffd0() > idx)
        {
            return reinterpret_cast<NiShaderLibraryDescHelper*>(desc)->FUN_00a9ffe0(idx);
        }
    }
L_008b:
    return 0;
}
