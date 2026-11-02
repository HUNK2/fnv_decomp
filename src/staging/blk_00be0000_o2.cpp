
// src/staging/blk_00be0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct NiD3DPass
{
    static void __cdecl CreateD3DPass(NiPointer<NiD3DPass>&);
};
// @fnv 0x00be08e0
bool __fastcall FUN_00be08e0(char* self, int)
{
    NiD3DPass::CreateD3DPass(*(NiPointer<NiD3DPass>*)(self + 0x5c));
    return true;
}

class SubTarget
{
  public:
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual int v39(void* pObj);
};

class SubOwner
{
  public:
    SubTarget* GetSub(int kind);
};

// @fnv 0x00be08c0
int __stdcall DispatchSubTarget(SubOwner* self)
{
    SubTarget* sub = self->GetSub(3);
    return sub->v39(self);
}

struct PassBase
{
    virtual void OnRelease();
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
    PassBase(void* owner, unsigned int mode);
};

struct FUN_00be08f0 : PassBase
{
    unsigned int unk2c;
    FUN_00be08f0(void* owner);
    virtual void OnRelease();
};

// Constructs a PassBase-derived object in mode 2 and initialises its extra field to zero.
// @fnv 0x00be08f0
FUN_00be08f0::FUN_00be08f0(void* owner) : PassBase(owner, 2), unk2c(0)
{}

void __cdecl FUN_00aa1460(void* object, unsigned int size);

struct FNVNiD3DPassStandIn
{
    void __thiscall FUN_00be0f10();
    void* __thiscall FUN_00be2290(unsigned int flags);
};

// Calls FUN_00be0f10, then if bit 0 of flags is set calls FUN_00aa1460 on this with size 0x6c, and returns this.
// @fnv 0x00be2290
void* __thiscall FNVNiD3DPassStandIn::FUN_00be2290(unsigned int flags)
{
    FUN_00be0f10();

    if (flags & 1)
        FUN_00aa1460(this, 0x6c);

    return this;
}

struct RefObject
{
    virtual void slot0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
    }
};
struct RenderStateBlock
{
    void SetNodeValue(unsigned int, unsigned int, bool);
};
RenderStateBlock* FUN_00e7f5d0();
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
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
    int references;
    void FUN_00e7ecd0();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            FUN_00e7ecd0();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void AssignStageFromPool(ShaderStagePointer*);
void ConfigureBeamStage(ShaderStage*, unsigned int, unsigned int, unsigned int, bool);
extern unsigned int DAT_011f9534;
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    void FUN_00e80190();
    void FUN_00e802b0(unsigned int, ShaderStage*);
    __forceinline RenderStateBlock* GetState()
    {
        if (!state)
            state = FUN_00e7f5d0();
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            object->FUN_00e80190();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                object->FUN_00e80190();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern ShaderPass* DAT_011fe244;
extern ShaderPass* DAT_011fe7c0;
extern ShaderPass* DAT_011fe7bc;
extern ShaderPass* DAT_011fe7c8;
extern ShaderPass* DAT_011fe7b4;
extern ShaderPass* DAT_011fe7cc;
extern RefObject* DAT_011fddec;
extern RefObject* DAT_011fddf0;
extern RefObject* DAT_011fddf4;
extern RefObject* DAT_011fddf8;
extern RefObject* DAT_011fddfc;
extern RefObject* DAT_011fdae8;
extern RefObject* DAT_011fdaec;
extern RefObject* DAT_011fdaf0;
extern RefObject* DAT_011fdaf4;
extern RefObject* DAT_011fdaf8;
extern RefObject* DAT_011fdafc;
extern unsigned int DAT_011fcecc;
extern unsigned int DAT_011fc2ec;
extern unsigned int DAT_011fb70c;
extern unsigned int DAT_011fab2c;
extern unsigned int DAT_011fd448;
extern unsigned int DAT_011fc868;
extern unsigned int DAT_011fbc88;
extern unsigned int DAT_011fb0a8;
extern unsigned int DAT_011fd444;
extern unsigned int DAT_011fc864;
extern unsigned int DAT_011fd450;
extern unsigned int DAT_011fc870;
extern unsigned int DAT_011fd43c;
extern unsigned int DAT_011fc85c;
extern unsigned int DAT_011fd454;
extern unsigned int DAT_011fc874;
// @fnv 0x00bea040
void InitDefaultShaderPasses()
{
    ShaderPassPointer pass;
    ShaderStagePointer stage;
    pass = DAT_011fe244;
    if (pass->Count() < 2)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->FUN_00e802b0(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->FUN_00e802b0(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fddec;
    pass->pixelShader = DAT_011fdae8;
    pass->GetState()->SetNodeValue(27, 0, 1);
    pass->GetState()->SetNodeValue(15, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 1, 1);
    DAT_011fcecc = 128;
    DAT_011fc2ec = 12;
    DAT_011fb70c = 128;
    DAT_011fab2c = 12;
    pass = DAT_011fe7c0;
    if (pass->Count() < 2)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->FUN_00e802b0(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->FUN_00e802b0(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fddf0;
    pass->pixelShader = DAT_011fdaec;
    pass->GetState()->SetNodeValue(27, 1, 1);
    pass->GetState()->SetNodeValue(19, 5, 1);
    pass->GetState()->SetNodeValue(20, 6, 1);
    pass->GetState()->SetNodeValue(15, 1, 1);
    pass->GetState()->SetNodeValue(25, 5, 1);
    pass->GetState()->SetNodeValue(24, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 0, 1);
    DAT_011fd448 = 128;
    DAT_011fc868 = 12;
    DAT_011fbc88 = 128;
    DAT_011fb0a8 = 4;
    pass = DAT_011fe7bc;
    if (pass->Count() < 2)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->FUN_00e802b0(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->FUN_00e802b0(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fddf4;
    pass->pixelShader = DAT_011fdaf0;
    pass->GetState()->SetNodeValue(19, 5, 1);
    pass->GetState()->SetNodeValue(20, 2, 1);
    pass->GetState()->SetNodeValue(15, 1, 1);
    pass->GetState()->SetNodeValue(25, 5, 1);
    pass->GetState()->SetNodeValue(24, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 0, 1);
    DAT_011fd444 = 0;
    DAT_011fc864 = 8;
    pass = DAT_011fe7c8;
    if (pass->Count() < 2)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->FUN_00e802b0(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->FUN_00e802b0(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fddf4;
    pass->pixelShader = DAT_011fdaf4;
    pass->GetState()->SetNodeValue(27, 1, 1);
    pass->GetState()->SetNodeValue(19, 5, 1);
    pass->GetState()->SetNodeValue(20, 2, 1);
    pass->GetState()->SetNodeValue(15, 1, 1);
    pass->GetState()->SetNodeValue(25, 5, 1);
    pass->GetState()->SetNodeValue(24, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 0, 1);
    DAT_011fd450 = 0;
    DAT_011fc870 = 8;
    pass = DAT_011fe7b4;
    if (pass->Count() < 2)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->FUN_00e802b0(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->FUN_00e802b0(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fddf8;
    pass->pixelShader = DAT_011fdaf8;
    pass->GetState()->SetNodeValue(19, 5, 1);
    pass->GetState()->SetNodeValue(20, 2, 1);
    pass->GetState()->SetNodeValue(15, 1, 1);
    pass->GetState()->SetNodeValue(25, 5, 1);
    pass->GetState()->SetNodeValue(24, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 0, 1);
    DAT_011fb70c = 128;
    DAT_011fd43c = 128;
    DAT_011fc85c = 8;
    pass = DAT_011fe7cc;
    if (pass->Count() < 2)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->FUN_00e802b0(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->FUN_00e802b0(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fddfc;
    pass->pixelShader = DAT_011fdafc;
    pass->GetState()->SetNodeValue(27, 1, 1);
    pass->GetState()->SetNodeValue(19, 5, 1);
    pass->GetState()->SetNodeValue(20, 2, 1);
    pass->GetState()->SetNodeValue(15, 1, 1);
    pass->GetState()->SetNodeValue(25, 5, 1);
    pass->GetState()->SetNodeValue(24, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 0, 1);
    DAT_011fd454 = 128;
    DAT_011fc874 = 8;
}

namespace fnv_00beb830 {
struct RenderObject
{
    virtual void Unused();
    virtual void DeleteThis();
    volatile long references;
    void IncRefCount()
    {
        InterlockedIncrement(&references);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&references))
            DeleteThis();
    }
};
struct RenderState
{
    void SetNodeValue(unsigned int state, unsigned int value, unsigned int flags);
};
RenderState* __cdecl FUN_00e7f5d0();
struct StageReturn
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
    unsigned int references;
    void ReturnToPool();
    void IncRefCount()
    {
        ++references;
    }
    void DecRefCount()
    {
        if (--references == 0)
            ReturnToPool();
    }
};
void __cdecl AssignStageFromPool(StageReturn*&);
struct ShaderPassEntry
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
    RenderState* unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    NiPointer<RenderObject> unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    NiPointer<RenderObject> unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int GetStageCount() const
    {
        return unk18;
    }
    void FUN_00e80190();
    void FUN_00e802b0(unsigned int index, StageReturn* stage);
    void IncRefCount()
    {
        ++unk64;
    }
    void DecRefCount()
    {
        if (--unk64 == 0)
            FUN_00e80190();
    }
};
void __cdecl ConfigureBeamStage(StageReturn*, unsigned int, unsigned int, unsigned int, unsigned int);
extern NiPointer<ShaderPassEntry> DAT_011fe010;
extern NiPointer<ShaderPassEntry> DAT_011fe014;
extern NiPointer<ShaderPassEntry> DAT_011fe018;
extern RenderObject* DAT_011fdd88;
extern RenderObject* DAT_011fdb04;
extern RenderObject* DAT_011fde04;
extern unsigned int DAT_011fcc98, DAT_011fcc9c, DAT_011fcca0;
extern unsigned int DAT_011fc0b8, DAT_011fc0bc, DAT_011fc0c0;
// @fnv 0x00beb830
void __cdecl FUN_00beb830()
{
    NiPointer<ShaderPassEntry> pass;
    NiPointer<StageReturn> stage;
    pass = DAT_011fe010;
    if (pass->GetStageCount() < 1)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage, 0, 1, 2, 1);
        pass->FUN_00e802b0(pass->unk14, stage);
    }
    pass->unk5c = DAT_011fdd88;
    pass->unk44 = DAT_011fdb04;
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(27, 0, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(15, 0, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(7, 1, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(23, 4, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(14, 1, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(168, 3, 1);
    DAT_011fcc98 = 0;
    DAT_011fc0b8 = 4;
    pass = DAT_011fe014;
    if (pass->GetStageCount() < 1)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage, 0, 1, 2, 1);
        pass->FUN_00e802b0(pass->unk14, stage);
    }
    pass->unk5c = DAT_011fdd88;
    pass->unk44 = DAT_011fdb04;
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(27, 0, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(15, 1, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(7, 1, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(23, 4, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(14, 1, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(168, 3, 1);
    DAT_011fcc9c = 0;
    DAT_011fc0bc = 4;
    pass = DAT_011fe018;
    if (pass->GetStageCount() < 1)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage, 0, 1, 2, 1);
        pass->FUN_00e802b0(pass->unk14, stage);
    }
    pass->unk5c = DAT_011fde04;
    pass->unk44 = DAT_011fdb04;
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(27, 0, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(15, 0, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(7, 1, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(23, 4, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(14, 1, 1);
    if (!pass->unk30)
        pass->unk30 = FUN_00e7f5d0();
    pass->unk30->SetNodeValue(168, 3, 1);
    DAT_011fcca0 = 2048;
    DAT_011fc0c0 = 4;
}
}  // namespace fnv_00beb830

struct C0
{
    int __thiscall FUN_00be0b10();
};

// @fnv 0x00be0b10
int __thiscall C0::FUN_00be0b10()
{
    return *(int*)((char*)this + 0x2c);
}
