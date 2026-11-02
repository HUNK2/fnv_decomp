// fallout/interface/interface_rebase_PC_NiAVObject.h: declares BSMemObject, NiTransform, NiAVObject
#ifndef FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_PC_NIAVOBJECT_DECLARATION_H
#define FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_PC_NIAVOBJECT_DECLARATION_H
#include "interface_rebase_NiObjectNET.h"
#include "interface_rebase_NiPoint3.h"
#include "interface_rebase_NiProperty.h"
class NiCullingProcess;
class NiNode;
class NiCamera;
class NiCollisionObject;
class NiPropertyState;
class NiRenderer;
class NiDynamicEffectState;
class NiUpdateData;
class FourComponentFloatVector;
class BSMemObject
{
};
class ThreeByThreeMatrix : public BSMemObject
{
  public:
    float m_afEntries[3][3];
};
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kRotate;
    NiPoint3 m_kTranslate;
    float m_fScale;
};
template <class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, T>
{
};
class NiAVObject : public NiObjectNET
{
  public:
    void SetAppCulled(bool);
    virtual ~NiAVObject();
    virtual void UpdateControllers(NiUpdateData& arData);
    virtual void ApplyTransform(const ThreeByThreeMatrix& arRotation, const NiPoint3& arPosition, bool abOnLeft);
    virtual void SetMaterialNeedsUpdate(bool abNeedsUpdate);
    virtual void SetDefaultMaterialNeedsUpdateFlag(bool abNeedsUpdate);
    virtual NiAVObject* GetObjectByName(const NiFixedString& arName) const;
    virtual void SetSelectiveUpdateFlags(bool& arSelectiveUpdate, bool abSelectiveUpdateTransforms, bool& arRigid);
    virtual void UpdateDownwardPass(NiUpdateData& arData, unsigned int auiFlags);
    virtual void UpdateSelectedDownwardPass(NiUpdateData& arData, unsigned int auiFlags);
    virtual void UpdateRigidDownwardPass(NiUpdateData& arData, unsigned int auiFlags);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState* apParentState);
    virtual void UpdateEffectsDownward(NiDynamicEffectState* apEffectState);
    virtual void UpdateWorldData(NiUpdateData& arData);
    virtual void UpdateWorldBound();
    virtual void UpdateTransformAndBounds(NiUpdateData& arData);
    virtual void PreAttachUpdate(NiNode* apEventualParent, NiUpdateData& arData);
    virtual void PreAttachUpdateProperties(NiNode* apEventualParent);
    virtual void FinalizeAttachUpdate(NiNode* apEventualParent);
    virtual void CompleteAttachUpdate();
    virtual void OnVisible(NiCullingProcess& arCuller);
    virtual void PurgeRendererData(NiRenderer* apRenderer);
    NiNode* m_pParentNode;
    NiPointer<NiCollisionObject> m_spCollisionObject;
    FourComponentFloatVector* m_kWorldBound;
    NiTPointerList<NiPointer<NiProperty> > SceneGraphObject;
    unsigned int m_uiObjectFlags;
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;
};
FNV_STATIC_ASSERT(sizeof(BSMemObject) == 1);
FNV_STATIC_ASSERT(sizeof(ThreeByThreeMatrix) == 0x24);
FNV_STATIC_ASSERT(offsetof(ThreeByThreeMatrix, m_afEntries) == 0);
FNV_STATIC_ASSERT(sizeof(NiTransform) == 0x34);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_kRotate) == 0);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_kTranslate) == 0x24);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_fScale) == 0x30);
FNV_STATIC_ASSERT(sizeof(NiAVObject) == 0x9C);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_pParentNode) == 0x18);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_spCollisionObject) == 0x1C);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kWorldBound) == 0x20);
FNV_STATIC_ASSERT(offsetof(NiAVObject, SceneGraphObject) == 0x24);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_uiObjectFlags) == 0x30);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kLocalTransform) == 0x34);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kWorldSpaceTransform) == 0x68);
#endif
