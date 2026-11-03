// fallout_shared/sky/precipitation.cpp: Precipitation, PrecipS (6 functions)

#include "precipitation_decls.h"
int FUN_00404dc0(const char*, const char*);
// @fnv 0x00636c40
void Precipitation::Load(const char* path)
{
    if (m_pPrecipitationNode)
    {
        pParent->RemoveObject(m_pPrecipitationNode);
        m_pPreviousNode = m_pPrecipitationNode;
        pParent->AddObject(m_pPreviousNode, true);
        m_pPrecipitationNode = 0;
    }
    if (path && *path)
    {
        NiNode* model = g_modelLoader->LoadFile(path, ENUM_LOD_MULT_Default, true, false, false, false);
        if (model)
        {
            bool bIsSnow = FUN_00404dc0(path, DAT_0104ed9c) == 0;
            NiUpdateData kUpdateData(0.0f, false, false);
            model->UpdateDownwardPass(kUpdateData, 0);
            m_pPrecipitationNode = reinterpret_cast<NiNode*>(new NiSortAdjustNode(0));
            fEmissionRate = 0.0f;
            for (unsigned int index = 0; index < model->NiNode_GetChildCount(); ++index)
            {
                NiAVObject* m_pShaderGeometry = model->FUN_0043b4a0(index)->vfn_000c();
                SkyShaderProperty* pShaderProperty =
                    m_pShaderGeometry ? FUN_00653270(&DAT_012024e0, m_pShaderGeometry->FUN_0045bc00(false)) : 0;
                if (!pShaderProperty)
                    continue;
                NiAVObject* precipParticle = CreateParticleShape(pShaderProperty, pParent->NiAVObject_GetWorldRotate(bIsSnow));
                if (precipParticle)
                    static_cast<NiNode*>(m_pPrecipitationNode)->AddObject(precipParticle, true);
            }
            pParent->AddObject(m_pPrecipitationNode, true);
            static_cast<NiNode*>(m_pPrecipitationNode)->UpdateSceneObject();
        }
    }
}

struct FUN_00636bb0_shell
{
    void FUN_00636bb0();
};

NiAVObject* __cdecl FUN_0054f4f0(void);

// @fnv 0x00636bb0
void FUN_00636bb0_shell::FUN_00636bb0()
{
    *(NiAVObject**)((char*)this + 0xc) = FUN_0054f4f0();
}

struct NodeS
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
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void RemoveChild(void*);
};
struct Flt
{
    void* p;
    operator unsigned int() const;
};
struct NP : Flt
{
    NP& operator=(void*);
};
struct PrecipS
{
    char pad[4];
    NP m_pPrecipitationNode;
    NP m_pPreviousNode;
    NodeS* pParent;
    void RemoveChildren();
};
// @fnv 0x00637800
void PrecipS::RemoveChildren()
{
    if (m_pPreviousNode.Flt::operator unsigned int())
    {
        pParent->RemoveChild((void*)m_pPreviousNode.Flt::operator unsigned int());
        m_pPreviousNode.NP::operator=(0);
    }
    if (m_pPrecipitationNode.Flt::operator unsigned int())
    {
        pParent->RemoveChild((void*)m_pPrecipitationNode.Flt::operator unsigned int());
        m_pPrecipitationNode.NP::operator=(0);
    }
}

void _Deallocate(void*);
struct Cls636af0
{
    void FUN_00636b20();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00636b20, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x00636af0
void* Cls636af0::DestroyIfFlagged(unsigned int flags)
{
    FUN_00636b20();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct PrecipQueuedObject
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void* vfn_0014(int a0, int a1, int a2, int a3, int a4, int a5);

    int FUN_0048cee0();
};

struct PrecipPointerHelper
{
    int FUN_00559450();
};

struct PrecipManager
{
    void FUN_00444040(void* object);
};

extern PrecipManager* DAT_011c3b3c;

struct FUN_00636bd0_cls
{
    void** m_ppVirtualMethodTable;
    void* m_pPrecipitationNode;
    void* m_pPreviousNode;
    void* pParent;
    float fEmissionRate;
    const void* m_pPrecipitationData;

    void QueuePrecipitationObject(PrecipQueuedObject* object);
    void FUN_00636c40(void* arg);
};

// @fnv 0x00636bd0
void FUN_00636bd0_cls::QueuePrecipitationObject(PrecipQueuedObject* object)
{
    if (((PrecipPointerHelper*)&m_pPreviousNode)->FUN_00559450())
        return;

    if (object != 0 && object->FUN_0048cee0() != 0)
    {
        DAT_011c3b3c->FUN_00444040(object->vfn_0014(0, 0, 0, 0, 0, 0));
        m_pPrecipitationData = object;
    }
    else
        FUN_00636c40(0);
}

// Destructor: release both handles and clear the cached pointer before the handle members are destroyed.

class B20Handle
{
  public:
    ~B20Handle();
    void Reset(void* pvObject);

    void* m_pvObject;
};

class FUN_00636b20
{
  public:
    virtual ~FUN_00636b20();

    B20Handle m_kFirst;
    B20Handle m_kSecond;
    int unk0C;
    int unk10;
    void* m_pvCached;
};

// Resets both B20Handle members to null and clears m_pvCached.
// @fnv 0x00636b20
FUN_00636b20::~FUN_00636b20()
{
    m_kFirst.Reset(0);
    m_kSecond.Reset(0);
    m_pvCached = 0;
}
