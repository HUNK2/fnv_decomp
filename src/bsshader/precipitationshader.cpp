
// src/bsshader/precipitationshader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/precipitationshader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_012005c0;

// @fnv 0x00bb0540
void* __cdecl FUN_00bb0540()
{
    return &g_012005c0;
}

extern void* g_012005fc;

// @fnv 0x00bb0d10
void* __cdecl FUN_00bb0d10()
{
    return &g_012005fc;
}

struct FUN_00bb0d20_shell
{
    void* __thiscall FUN_00bb0d20();
};

// @fnv 0x00bb0d20
void* FUN_00bb0d20_shell::FUN_00bb0d20()
{
    return *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x94);
}

struct FUN_00bb0d30_shell
{
    void __thiscall FUN_00bb0d30(int value);
};

// @fnv 0x00bb0d30
void __thiscall FUN_00bb0d30_shell::FUN_00bb0d30(int value)
{
    *(int*)((char*)this + 0x94) = value;
}

void* __cdecl FUN_00bb0550();
extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00bb0a50_shell
{
    void* __thiscall DestroyIfFlagged(int flags);
};
// @fnv 0x00bb0a50
void* __thiscall FUN_00bb0a50_shell::DestroyIfFlagged(int flags)
{
    FUN_00bb0550();
    if (flags & 1)
        operator delete(this, 0xac);
    return this;
}

void FUN_00be2200();

struct V3
{
    float x;
    float y;
    float z;
    V3()
    {}
    V3(float a, float b, float c) : x(a), y(b), z(c)
    {}
};

extern V3 g_011a9b7c;

struct FUN_00bb04b0_Base
{
    FUN_00bb04b0_Base();
    virtual void vf();
};

struct FUN_00bb04b0 : FUN_00bb04b0_Base
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned char m_24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int m_68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    V3 m_90;
    int m_9c;
    V3 m_a0;

    FUN_00bb04b0();
    virtual void vf();
};

// Initializes the object's fields: sets m_68 to 0x12, zeroes m_90, copies g_011a9b7c into m_a0, and sets m_24 to 1.
// @fnv 0x00bb04b0
FUN_00bb04b0::FUN_00bb04b0() : m_9c(0), m_a0(0.0f, 0.0f, 0.0f)
{
    m_68 = 0x12;
    m_90 = V3(0.0f, 0.0f, 0.0f);
    m_a0 = g_011a9b7c;
    m_24 = 1;
}

struct SpawnedBase
{
    SpawnedBase();
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v4c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v8c(int, int, int, int, int);
    virtual void v090();
    virtual void v94(int, int, int, int, int, int, int, int);
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void vb4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void vc0(void*);
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
};

struct SpawnedObject : SpawnedBase
{
    SpawnedObject();
    static void* operator new(unsigned int size);
    unsigned int unk04;
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
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
};

extern "C" void* g_011f9508;
void* __cdecl FUN_00aa13e0(unsigned int aiSize);
void* __cdecl FUN_00e76700(void* apTag, int a1, int a2);

// @fnv 0x00bb0660
void* __cdecl FUN_00bb0660()
{
    SpawnedBase* pHost = (SpawnedBase*)FUN_00e76700(g_011f9508, 3, 2);
    pHost->v8c(0, 0, 0, 2, 0);
    pHost->v8c(1, 7, 5, 1, 0);
    pHost->v94(1, 0, 6, 0x80000000, 2, 5, 1, 0);
    pHost->vb4();

    SpawnedObject* pObj = new SpawnedObject();
    pObj->v4c();
    pObj->v13c();
    pObj->v148();
    pObj->v11c();
    pObj->vc0(pHost);
    return pObj;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

struct ShaderProgram
{
    virtual void v00();
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

template <class T> struct ProgramPtr
{
    T* m_pObject;
    ProgramPtr& operator=(T* pObject)
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

struct RenderStateBlock
{
    void SetNodeValue(unsigned int uiState, unsigned int uiValue, bool bSave);
};
RenderStateBlock* __cdecl FUN_00e7f5d0();

struct RenderStateHolder
{
    RenderStateBlock* m_pCurrentRenderState;
    RenderStateBlock*& Get()
    {
        if (!m_pCurrentRenderState)
            m_pCurrentRenderState = FUN_00e7f5d0();
        return m_pCurrentRenderState;
    }
};

struct ShaderPass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18[6];
    RenderStateHolder m_kRenderState;
    int unk34[4];
    ProgramPtr<ShaderProgram> m_spPixelShaderObject;
    int unk48[5];
    ProgramPtr<ShaderProgram> m_spVertexShaderObject;
    unsigned int m_uiRefCount;

    void FUN_00e7def0(int iFlag);
    void FUN_00e802b0(int iIndex, ShaderPass* pkPass);
    void FUN_00e7ecd0();
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            FUN_00e7ecd0();
    }
};

template <class T> struct PassPtr
{
    T* m_pObject;
    PassPtr() : m_pObject(0)
    {}
    ~PassPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

extern ShaderPass* g_pkPass_012005e0;
extern ShaderProgram* g_pkPixelShader_012005d0;
extern ShaderProgram* g_pkVertexShader_012005c8;

void __cdecl FUN_00e804d0(ShaderPass** ppkPass);
void __cdecl AssignStageFromPool(PassPtr<ShaderPass>* pspPass);
void __cdecl ConfigureBeamStage(ShaderPass* pkPass, int a1, int a2, int a3, int a4);

// @fnv 0x00bb0770
bool __cdecl FUN_00bb0770()
{
    PassPtr<ShaderPass> spRenderPass;
    FUN_00e804d0(&g_pkPass_012005e0);
    AssignStageFromPool(&spRenderPass);
    ConfigureBeamStage(spRenderPass, 0, 3, 2, 1);
    spRenderPass->FUN_00e7def0(1);
    g_pkPass_012005e0->FUN_00e802b0(g_pkPass_012005e0->unk14, spRenderPass);
    g_pkPass_012005e0->m_spVertexShaderObject = g_pkPixelShader_012005d0;
    g_pkPass_012005e0->m_spPixelShaderObject = g_pkVertexShader_012005c8;
    g_pkPass_012005e0->m_kRenderState.Get()->SetNodeValue(7, 1, true);
    g_pkPass_012005e0->m_kRenderState.Get()->SetNodeValue(0xe, 0, true);
    g_pkPass_012005e0->m_kRenderState.Get()->SetNodeValue(0x17, 4, true);
    g_pkPass_012005e0->m_kRenderState.Get()->SetNodeValue(0x1b, 1, true);
    RenderStateHolder& kRS = g_pkPass_012005e0->m_kRenderState;
    kRS.Get()->SetNodeValue(0x13, 5, true);
    kRS.Get()->SetNodeValue(0x14, 6, true);
    g_pkPass_012005e0->m_kRenderState.Get()->SetNodeValue(0xf, 0, true);
    g_pkPass_012005e0->m_kRenderState.Get()->SetNodeValue(0xa8, 7, true);
    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

void* __cdecl FUN_00aa13e0(unsigned int uiSize);
void __cdecl CmFree(void* pvMem);

struct ConstantMap
{
    virtual void v00();
    virtual void DeleteThis();
    virtual int AddEntry(const char* pcKey, unsigned int uiFlags, unsigned int uiExtra, unsigned int uiShaderRegister,
                         unsigned int uiRegisterCount, const char* pcVariableName, unsigned int uiConstantDataSize,
                         unsigned int uiDataStride, const void* pvDataSource, bool bCopyData);
    long m_uiRefCount;
    int unk08[0x44 / 4 - 2];

    ConstantMap(void* pkRenderer, int iType);
    static void* operator new(unsigned int uiSize)
    {
        return FUN_00aa13e0(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        CmFree(pvMem);
    }
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

template <class T> struct ConstantMapPtr
{
    T* m_pObject;
    ConstantMapPtr& operator=(T* pObject)
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
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
};

extern float g_afEyePos_012005e4[4];
extern float g_afCamUp_012005f0[4];

struct ShaderConstantsImpl
{
    char pad00[0x18];
    void* m_pOwnerShader;
    char pad1c[0x30 - 0x1c];
    ConstantMapPtr<ConstantMap> m_spFirstShaderConstantMap;
    ConstantMapPtr<ConstantMap> m_spSecondShaderConstantMap;
    char pad38[0x6c - 0x38];
    float m_afVelocity[3];
    float m_afMin[3];
    float m_afMax[3];
    float m_afParams[4];
    float m_afAmbientColor[4];

    void InitConstantMaps();
};

// @fnv 0x00bb0a80
void ShaderConstantsImpl::InitConstantMaps()
{
    if (!m_spFirstShaderConstantMap.m_pObject)
    {
        m_spFirstShaderConstantMap = new ConstantMap(m_pOwnerShader, 2);
        m_spFirstShaderConstantMap->AddEntry("ambient color", 0x10000006, 0, 0, 1, "", 0xc, 4, m_afAmbientColor, false);
    }
    if (!m_spSecondShaderConstantMap.m_pObject)
    {
        m_spSecondShaderConstantMap = new ConstantMap(m_pOwnerShader, 0);
        m_spSecondShaderConstantMap->AddEntry("WorldViewProjTranspose", 0x20000009, 0, 0, 4, 0, 0, 0, 0, false);
        m_spSecondShaderConstantMap->AddEntry("eye pos", 0x10000006, 0, 8, 1, "", 0xc, 4, g_afEyePos_012005e4, false);
        m_spSecondShaderConstantMap->AddEntry("velocity", 0x10000006, 0, 9, 1, "", 0xc, 4, m_afVelocity, false);
        m_spSecondShaderConstantMap->AddEntry("min", 0x10000006, 0, 0xa, 1, "", 0xc, 4, m_afMin, false);
        m_spSecondShaderConstantMap->AddEntry("max", 0x10000006, 0, 0xb, 1, "", 0xc, 4, m_afMax, false);
        m_spSecondShaderConstantMap->AddEntry("params", 0x10000006, 0, 0xc, 1, "", 0xc, 4, m_afParams, false);
        m_spSecondShaderConstantMap->AddEntry("cam up", 0x10000006, 0, 0xd, 1, "", 0xc, 4, g_afCamUp_012005f0, false);
    }
}

struct FUN_00bb0cf0_cls
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
    int m_94;
    void __thiscall FUN_00bb0cf0(int value);
};

// @fnv 0x00bb0cf0
void FUN_00bb0cf0_cls::FUN_00bb0cf0(int value)
{
    m_94 = (value != 3) ? 3 : 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class NiRefObject
{
  public:
    virtual void vf00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
        }
        return *this;
    }
};

struct SharedResource
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
    int m_iRefCount;
    void Release();
    void DecRefCount()
    {
        int* p = &m_iRefCount;
        if (--*p == 0)
            Release();
    }
};

template <class T> class RefPtr
{
  public:
    T* m_pObject;
    RefPtr& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
        }
        return *this;
    }
};

extern NiPointer<NiRefObject> g_aspSmall[2];
extern NiPointer<NiRefObject> g_aspLarge[4];
extern RefPtr<SharedResource> g_spSharedResource;

class ResourceOwnerBase
{
  public:
    virtual void vf00();
    ~ResourceOwnerBase();
};

class FUN_00bb0550 : public ResourceOwnerBase
{
  public:
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
    NiPointer<NiRefObject> m_spUnk9C;
    virtual void vf00();
    ~FUN_00bb0550();
};

// Destructor that clears the four g_aspLarge and two g_aspSmall NiPointers and the g_spSharedResource RefPtr to null.
// @fnv 0x00bb0550
FUN_00bb0550::~FUN_00bb0550()
{
    for (int i = 0; i < 4; i++)
        g_aspLarge[i] = 0;
    for (int i = 0; i < 2; i++)
        g_aspSmall[i] = 0;
    g_spSharedResource = 0;
}

class ShaderManager_bb09
{
  public:
    bool FUN_00be0870();
    bool ResetSharedResources();
};

// Calls FUN_00be0870, zeroes g_aspLarge, g_aspSmall, and g_spSharedResource, then returns the result of FUN_00be0870.
// @fnv 0x00bb09b0
bool ShaderManager_bb09::ResetSharedResources()
{
    bool bResult = FUN_00be0870();
    for (int i = 0; i < 4; i++)
        g_aspLarge[i] = 0;
    for (int i = 0; i < 2; i++)
        g_aspSmall[i] = 0;
    g_spSharedResource = 0;
    return bResult;
}
