// gamebryo2.2/corelibs/nimain/nishaderfactory.cpp: NiShaderFactory, NiRefObject (11 functions)

#include "nishaderfactory_types.h"

// @fnv 0x00a9fff0
NiShaderFactory* __cdecl NiShaderFactory::GetInstance()
{
    return ms_pShaderFactory;
}

void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);
struct FUN_00aa06c0
{
    void FUN_00aa05a0();
    FUN_00aa06c0* FUN_00aa06c0_impl(unsigned int flags);
};
// @fnv 0x00aa06c0
FUN_00aa06c0* FUN_00aa06c0::FUN_00aa06c0_impl(unsigned int flags)
{
    FUN_00aa05a0();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x24);
    return this;
}

struct BSFadeNode;
struct BSMultiBoundNode;
struct BSResizableTriShape;
struct BSSegmentedTriShape;
struct Direct3DDeviceInterface;
struct NiD3DShaderProgramCreator;
struct NiGeometry;
struct NiLines;
struct NiNode;
struct NiParticles;
struct NiShaderConstantMapEntry;
struct NiTriBasedGeom;
struct NiTriShape;
struct NiTriStrips;
struct ShaderPassRenderer;
struct GraphicsRenderer;
struct bhkBlendCollisionObject;
struct bhkLimitedHingeConstraint;
struct bhkNiCollisionObject;
struct bhkRigidBody;
struct NiGPUProgram : public NiRefObject
{
    virtual void __vslot_0();
    virtual void* GetRTTI();
    virtual NiNode* IsSceneNode();
    virtual BSFadeNode* IsFadeNode();
    virtual BSMultiBoundNode* IsMultiBoundNode();
    virtual NiGeometry* IsGeometry();
    virtual NiTriBasedGeom* IsTriBasedGeom();
    virtual NiTriStrips* IsTriStrips();
    virtual NiTriShape* IsTriShape();
    virtual BSSegmentedTriShape* IsSegmentedTriShape();
    virtual BSResizableTriShape* IsResizableTriShape();
    virtual NiParticles* IsParticlesGeom();
    virtual NiLines* IsLineGeometry();
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject();
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject();
    virtual bhkRigidBody* IsBhkRigidBody();
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint();
    virtual unsigned int GetNumberOfVariables();
    virtual char* GetVariableName(unsigned int);
    bool IsExactKindOf(void*);
    static bool IsExactKindOf(void*, void*);
    bool IsKindOfType(void*);
    static bool IsKindOfType(void*, void*);
    NiGPUProgram* DynamicCast(void*);
    static NiGPUProgram* DynamicCast(void*, void*);
    int GetProgramType();
    int m_iProgramType;
};
typedef char _sizecheck_NiGPUProgram[sizeof(NiGPUProgram) == 12 ? 1 : -1];
struct NiD3DShaderProgram : public NiGPUProgram
{
    virtual void __vslot_0();
    virtual char* GetName();
    virtual void SetName(char*);
    virtual char* GetProgramProfile();
    virtual void SetShaderProfile(char*);
    virtual unsigned int GetCodeSize();
    virtual void* GetCode();
    virtual void SetProgramCode(unsigned int, void*);
    virtual NiD3DShaderProgramCreator* GetCreator();
    virtual void SetCreator(NiD3DShaderProgramCreator*);
    virtual bool SetShaderConstant(NiShaderConstantMapEntry*, void*, unsigned int);
    virtual bool SetShaderConstantArray(NiShaderConstantMapEntry*, void*, unsigned int, unsigned int, unsigned short*);
    virtual void* GetRTTI();
    void SetD3DDevice(Direct3DDeviceInterface*);
    void SetD3DRenderState(ShaderPassRenderer*);
    void SetShaderObject(GraphicsRenderer*);
    void SetVertexShaderConstant(int, int, float*);
    void SetPixelShaderConstant(int, int, float*);
    char* m_pcProgramName;
    char* m_pcProfile;
    unsigned int m_uiProgramCodeSize;
    void* m_pProgramCode;
    NiD3DShaderProgramCreator* m_pCreator;
    Direct3DDeviceInterface* m_pD3DDevice;
    GraphicsRenderer* m_pShaderObject;
    ShaderPassRenderer* m_pRenderState;
};
typedef char _sizecheck_NiD3DShaderProgram[sizeof(NiD3DShaderProgram) == 44 ? 1 : -1];
struct FUN_00e89830_shell : public NiD3DShaderProgram
{
    void* FUN_00e89830();
};

extern char const* const g_0126f9ac_arg1;
// @fnv 0x00e89830
void* FUN_00e89830_shell::FUN_00e89830()
{
    return (void*)&g_0126f9ac_arg1;
}

struct NiFileHack
{
    unsigned int FileRead(void*, unsigned int);
};
int __cdecl SwapBufferBySizes(void*, unsigned int, void*, void*);
// @fnv 0x00aa19e0
unsigned int __cdecl FUN_00aa19e0(NiFile* apFile, void* apBuffer, unsigned int auiSize, void* apArg4, void* apArg5)
{
    if (auiSize <= 0)
        return 0;
    unsigned int r = ((NiFileHack*)apFile)->FileRead(apBuffer, auiSize);
    SwapBufferBySizes(apBuffer, auiSize, apArg4, apArg5);
    return r;
}

extern char* _EmptyFS;

struct ShaderConstantMap : NiTFixedStringMap_NiGlobalConstantEntry___
{
    void SetAt(NiFixedString* pkKey, NiGlobalConstantEntry* pkValue);
};

struct ShaderFactorySlot : NiShaderFactory
{
    static NiShaderFactory*& Get()
    {
        return ms_pShaderFactory;
    }
};

struct NiGlobalConstantEntryView : NiRefObject
{
    unsigned int unk08;
    unsigned int unk0C;
};

struct NiGlobalConstantEntryStub
{
    NiGlobalConstantEntry* Init(unsigned int uiKey, unsigned int a2, unsigned int a3, unsigned int a4);
};

void* __cdecl FUN_00aa13e0(unsigned int uiSize);

// @fnv 0x00aa0400
bool __cdecl AcquireGlobalConstantEntry(const NiFixedString* pkName, unsigned int a2, unsigned int a3, unsigned int a4)
{
    if (ShaderFactorySlot::Get() == 0)
        return false;
    NiShaderFactory* pkFactory = ShaderFactorySlot::Get();
    NiFixedString kLocal;
    NiTMapItem<NiFixedString, NiGlobalConstantEntry*>* pkItem =
        pkFactory->m_kGlobalConstantEntryMap
            .m_ppkHashTable[(unsigned int)pkName->m_kHandle % pkFactory->m_kGlobalConstantEntryMap.m_uiHashSize];
    while (pkItem != 0)
    {
        if ((unsigned int)pkName->m_kHandle == (unsigned int)pkItem->m_key.m_kHandle)
        {
            NiGlobalConstantEntryView* pkEntry = (NiGlobalConstantEntryView*)pkItem->m_val;
            if (pkEntry == 0)
                break;
            if (pkEntry->unk0C != a2)
                return false;
            InterlockedIncrement((long*)&pkEntry->m_uiRefCount);
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }

    void* pvMem = FUN_00aa13e0(0x18);
    if (pvMem == 0)
        return false;
    unsigned int uiKey = (unsigned int)pkName->m_kHandle;
    NiGlobalConstantEntry* pkNew = ((NiGlobalConstantEntryStub*)pvMem)->Init(uiKey, a2, a3, a4);
    if (pkNew == 0)
        return false;

    InterlockedIncrement((long*)&((NiRefObject*)pkNew)->m_uiRefCount);
    if (pkName->m_kHandle != _EmptyFS)
        InterlockedIncrement((long*)(pkName->m_kHandle - 8));

    char* pcHandle = pkName->m_kHandle;
    NiShaderFactory* pkMapOwner = ShaderFactorySlot::Get();
    kLocal.m_kHandle = pcHandle;
    ((ShaderConstantMap*)&pkMapOwner->m_kGlobalConstantEntryMap)->SetAt(&kLocal, pkNew);

    if (pcHandle != _EmptyFS)
        InterlockedDecrement((long*)(pcHandle - 8));
    return true;
}

struct SpawnedArgBase : public NiRefObject
{
    int m_iArg08;
    SpawnedArgBase(int a2) throw()
    {
        m_iArg08 = a2;
    }
};

struct FUN_00e897d0 : public SpawnedArgBase
{
    virtual ~FUN_00e897d0() throw();
    virtual void DeleteThis();
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    FUN_00e897d0(int a1, int a2) throw();
    void Init(int a1);
};

// Constructs the object from a base argument and a1, zeroes eight fields, then calls Init(a1).
// @fnv 0x00e897d0
FUN_00e897d0::FUN_00e897d0(int a1, int aiArg) throw() : SpawnedArgBase(aiArg)
{
    m_unk0C = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    Init(a1);
}

inline NiRefObject::~NiRefObject()
{
    NiAtomicSubtract(ms_lObjectCount);
}

void NiFree(void* p) throw();

extern char* g_pcEmptyFixedString;

struct FixedStr
{
    char* m_kHandle;
    FixedStr()
    {
        m_kHandle = g_pcEmptyFixedString;
    }
    ~FixedStr()
    {
        if (m_kHandle != g_pcEmptyFixedString)
            InterlockedDecrement((volatile long*)(m_kHandle - 8));
    }
};

struct GlobalConstantEntry;
struct GlobalConstantItem
{
    GlobalConstantItem* m_pkNext;
    FixedStr m_key;
    GlobalConstantEntry* m_val;
};

struct GlobalConstantMapBase
{
    unsigned int m_uiHashSize;
    GlobalConstantItem** m_ppkHashTable;
    unsigned int m_uiCount;

    virtual ~GlobalConstantMapBase()
    {
        RemoveAll();
        NiFree(m_ppkHashTable);
    }
    void RemoveAll() throw();
    void GetNext(void*& rkPos, FixedStr& rkKey, GlobalConstantEntry*& rkVal) const throw();
    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
};

struct GlobalConstantMap : public GlobalConstantMapBase
{
    virtual ~GlobalConstantMap()
    {
        RemoveAll();
    }
};

void __cdecl RemoveGlobalConstant(char** pkName) throw();

struct FUN_00aa05a0 : public NiRefObject
{
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual void ReleaseAllLibraries() throw();
    virtual void v9() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void ClearLibraries() throw();

    GlobalConstantMap m_kGlobalConstantEntryMap;
    void* m_pFindGlobalConstantEntry;
    void* GlobalConstantEntryRegistry;
    void* GlobalConstantMapContext;

    static FUN_00aa05a0* ms_pShaderFactory;

    virtual ~FUN_00aa05a0() throw();
};

// @fnv 0x00aa05a0
FUN_00aa05a0::~FUN_00aa05a0() throw()
{
    if (ms_pShaderFactory)
        ms_pShaderFactory->ReleaseAllLibraries();
    if (ms_pShaderFactory)
        ms_pShaderFactory->ClearLibraries();

    void* pos = m_kGlobalConstantEntryMap.GetFirstPos();
    while (pos)
    {
        FixedStr kName;
        GlobalConstantEntry* pkEntry = 0;
        m_kGlobalConstantEntryMap.GetNext(pos, kName, pkEntry);
        if (pkEntry)
            RemoveGlobalConstant(&kName.m_kHandle);
    }

    if (ms_pShaderFactory == this)
        ms_pShaderFactory = 0;
}

// @fnv 0x00a38de0
int __stdcall FUN_00a38de0(int unk08)
{
    return 0;
}

extern int DAT_010a2148;
extern int DAT_0101dce4;
extern void* DAT_0109b220;
extern int DAT_011f4400;

typedef int(__stdcall* FUN_00aa0190_Decrement)(void*);
extern FUN_00aa0190_Decrement DAT_00fdf1c4;

void __cdecl FUN_00aa10f0(void* p);
void __cdecl FUN_00aa1460(void* p, unsigned int size);

struct FUN_00aa0190_Obj
{
    int* vptr;
    int unk04;
    void* unk08;
    int unk0C;
    int unk10;
    void* unk14;

    void* __thiscall Destroy(int flag);
};

// @fnv 0x00aa0190
void* __thiscall FUN_00aa0190_Obj::Destroy(int aiFlags)
{
    void* saved = unk14;
    vptr = &DAT_010a2148;
    FUN_00aa10f0(saved);

    void* head = unk08;
    FUN_00aa0190_Decrement decrement = DAT_00fdf1c4;
    if (head != DAT_0109b220)
    {
        decrement(static_cast<char*>(head) - 8);
    }

    vptr = &DAT_0101dce4;
    decrement(&DAT_011f4400);

    if ((aiFlags & 1) != 0)
    {
        FUN_00aa1460(this, 0x18);
    }

    return this;
}

// Returns 0 regardless of its three arguments.
// @fnv 0x00b57fc0
int __stdcall FUN_00b57fc0(int arg0, int arg1, int arg2)
{
    return 0;
}

extern char* _EmptyFS;

struct Stub
{
    __declspec(noalias) void FUN_00aa0250(NiFixedString* kKey);
};

// Finds the global constant entry for pkName in the shader factory, decrements its ref count, and deletes it when it reaches zero.
// @fnv 0x00aa04e0
bool RemoveGlobalConstant(const NiFixedString* pkName)
{
    NiShaderFactory* pkFactory = ShaderFactorySlot::Get();
    if (pkFactory == 0)
        return false;

    unsigned int uiKey = (unsigned int)pkName->m_kHandle;
    ShaderConstantMap* pkMap = (ShaderConstantMap*)&pkFactory->m_kGlobalConstantEntryMap;
    NiTMapItem<NiFixedString, NiGlobalConstantEntry*>* pkItem = pkMap->m_ppkHashTable[uiKey % pkMap->m_uiHashSize];
    NiRefObject* pkEntry = 0;
    while (pkItem != 0)
    {
        if (uiKey == (unsigned int)pkItem->m_key.m_kHandle)
        {
            pkEntry = (NiRefObject*)pkItem->m_val;
            break;
        }
        pkItem = pkItem->m_pkNext;
    }
    if (pkEntry == 0)
        return false;

    if (pkName->m_kHandle != _EmptyFS)
        InterlockedIncrement((long*)(pkName->m_kHandle - 8));
    pkFactory = ShaderFactorySlot::Get();

    NiFixedString kLocal;
    char* pcHandle = pkName->m_kHandle;
    kLocal.m_kHandle = pcHandle;
    if (pkEntry->m_uiRefCount == 1)
    {
        ((Stub*)&pkFactory->m_kGlobalConstantEntryMap)->FUN_00aa0250(&kLocal);
        if (InterlockedDecrement((long*)&pkEntry->m_uiRefCount) == 0)
            pkEntry->DeleteThis();
    }
    else
    {
        if (InterlockedDecrement((long*)&pkEntry->m_uiRefCount) == 0)
            pkEntry->DeleteThis();
    }

    if (pcHandle != _EmptyFS)
        InterlockedDecrement((long*)(pcHandle - 8));
    return true;
}
