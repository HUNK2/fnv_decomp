// fallout_shared/sky/precipitation_decls.h: declares NiUpdateData, NiAVObject, NiNode, ModelLoader, Precipitation and more
#ifndef FNV_PRECIPITATION_DECLS_H
#define FNV_PRECIPITATION_DECLS_H


#include "layout_support.h"

struct NiRTTI;
class NiProperty;
class SkyShaderProperty;

class NiUpdateData
{
  public:
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    unsigned char layoutPadding0;
    unsigned char layoutPadding1;
    unsigned char layoutPadding2;
    NiUpdateData(float time, bool updateControllers, bool parallelUpdate);
};
FNV_STATIC_ASSERT(sizeof(NiUpdateData) == 12);

class NiAVObject
{
  public:
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual NiAVObject* vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void UpdateDownwardPass(NiUpdateData& updateData, unsigned int flags);
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void vfn_00d0();
    virtual void vfn_00d4();
    virtual void vfn_00d8();

    NiProperty* FUN_0045bc00(bool flag);
    void UpdateSceneObject();
};

class NiNode : public NiAVObject
{
  public:
    virtual void AddObject(NiAVObject* object, bool firstFree);
    virtual void AddObjectAt(unsigned int index, NiAVObject* object);
    virtual void RemoveObject2(NiAVObject* object, NiAVObject** result);
    virtual void RemoveObject(NiAVObject* object);

    unsigned int FUN_00453470();
    NiAVObject* FUN_0043b4a0(int index);
    NiAVObject* FUN_00461130(bool flag);
};

template <> class NiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    operator NiNode*() const;
    NiPointer<NiNode>& operator=(NiNode* object);
    NiPointer<NiNode>& operator=(const NiPointer<NiNode>& other);
};

enum ENUM_LOD_MULT
{
    ENUM_LOD_MULT_Default = 0
};
class ModelLoader
{
  public:
    NiNode* LoadFile(const char* path, ENUM_LOD_MULT lodMult, bool assignShaders, bool suppressWarning, bool keepUV,
                     bool noUseCountIncrease);
};
extern ModelLoader* g_modelLoader;

class Precipitation
{
  public:
    void** m_ppVirtualMethodTable;
    NiPointer<NiNode> m_pPrecipitationNode;
    NiPointer<NiNode> m_pPreviousNode;
    NiNode* pParent;
    float fEmissionRate;
    const void* m_pPrecipitationData;
    void Load(const char* path);
    NiAVObject* CreateParticleShape(SkyShaderProperty* property, NiAVObject* object);
};
FNV_STATIC_ASSERT(sizeof(Precipitation) == 24);

class NiMemObject
{
  public:
    static void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
};

class NiSortAdjustNode : public NiMemObject
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned char layoutPadding[0xa8];
    NiSortAdjustNode(int flags);
};
FNV_STATIC_ASSERT(sizeof(NiSortAdjustNode) == 0xac);

extern const NiRTTI DAT_012024e0;
extern const char DAT_0104ed9c[];

SkyShaderProperty* FUN_00653270(const NiRTTI* rtti, NiProperty* property);

#endif
