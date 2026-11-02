
// src/fallout_shared/bipedanim_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bipedanim.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bipedanim_decls.h"

extern int EmptyFS;
struct NiShader
{
    const NiFixedString& GetFilename() const;
};
struct Holder
{
    bool FUN_00a5ba40(NiTexture* pkTex);
    bool FUN_00a5bc40(const NiFixedString& kName, NiTexture* pkTex);
};
// @fnv 0x00a5bc40
bool Holder::FUN_00a5bc40(const NiFixedString& kName, NiTexture* pkTex)
{
    if ((int)kName.data == EmptyFS)
        return false;
    if (!pkTex)
        return false;
    if (((NiShader*)pkTex)->GetFilename().data == (const char*)EmptyFS)
    {
        ((NiAVObject*)pkTex)->SetName(kName);
    }
    else
    {
        if (kName.data != ((NiShader*)pkTex)->GetFilename().data)
            return false;
    }
    return FUN_00a5ba40(pkTex);
}

struct FUN_00b553d0_PropertyLayout
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
    NiPoint3 value;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int count;
};

struct FUN_00b553d0_NodeLayout
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
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    NiAVObject** children;
    unsigned short unkA4;
    unsigned short childCount;
};

// @fnv 0x00b553d0
void __cdecl FUN_00b553d0(NiGeometry* pObject, NiPoint3* pValue)
{
    if (pObject == 0)
        return;

    if (pObject->IsGeometry() != 0)
    {
        NiProperty* pFirst = pObject->GetProperty(2);
        NiProperty* pSecond = pObject->GetProperty(3);

        if (pFirst != 0 && pSecond != 0)
        {
            FUN_00b553d0_PropertyLayout* pFirstLayout = (FUN_00b553d0_PropertyLayout*)pFirst;
            FUN_00b553d0_PropertyLayout* pSecondLayout = (FUN_00b553d0_PropertyLayout*)pSecond;

            if ((pSecondLayout->unk20 & 0x20000000u) <= 0)
                return;

            pFirstLayout->value = *pValue;
            ++pFirstLayout->count;
        }
        return;
    }

    NiNode* pNode = pObject->IsSceneNode();
    if (pNode == 0)
        return;

    FUN_00b553d0_NodeLayout* pNodeLayout = (FUN_00b553d0_NodeLayout*)pNode;

    unsigned int count = pNodeLayout->childCount;
    for (unsigned int i = 0; i < count; ++i)
    {
        NiAVObject* pChild = pNodeLayout->children[i];
        if (pChild != 0)
            FUN_00b553d0((NiGeometry*)pChild, pValue);
    }
}

struct NiStub10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class NiController
{
  public:
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2C();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual NiStub10* GetTarget();
};

struct SceneNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    SceneNode* m_parent;
    NiController* m_controller;
    SceneNode* GetParent() const
    {
        return m_parent;
    }
};

class NiGlobalStringTable
{
  public:
    static char* AddString(const char* s);
};

struct BackpackName
{
    char* m_data;
    BackpackName(const char* s)
    {
        m_data = NiGlobalStringTable::AddString(s);
    }
    ~BackpackName();
};

SceneNode* FUN_00c4b310(SceneNode* root, const char* name, int flag);
SceneNode* FUN_00c4b470(SceneNode* root, BackpackName* name, int flag);
struct AttachInfo
{
    void* m_data;
};

void FUN_00c88a40(void* a1, AttachInfo a2, SceneNode* obj, SceneNode* parent, bool a4);

static __forceinline SceneNode* FindAttachParent(SceneNode* obj, SceneNode* root)
{
    SceneNode* p = obj ? obj->GetParent() : 0;
    while (p)
    {
        NiController* c = p->m_controller;
        if (c && (!c->GetTarget() || p->m_controller->GetTarget()->unk10 != 0))
            break;
        if (p == root)
            break;
        p = p->GetParent();
    }
    if (p == root)
        return 0;
    return p;
}

// @fnv 0x00c89050
void __stdcall FUN_00c89050(void* a1, AttachInfo a2, SceneNode* root, bool a4)
{
    SceneNode* obj = FUN_00c4b310(root, "Weapon", 0);
    SceneNode* parent = FindAttachParent(obj, root);
    if (obj && parent)
        FUN_00c88a40(a1, a2, obj, parent, a4);

    static BackpackName kBackpack("Backpack");
    obj = FUN_00c4b470(root, &kBackpack, 0);
    parent = FindAttachParent(obj, root);
    if (obj && parent)
        FUN_00c88a40(a1, a2, obj, parent, a4);
}
