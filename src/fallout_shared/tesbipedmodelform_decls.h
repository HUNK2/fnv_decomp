// fallout_shared/tesbipedmodelform_decls.h: declares BGSListForm, BSFaceGenModelExtraData, NiNode, BipedAnim, ModelLoader
#ifndef FNV_TESBIPEDMODELFORM_DECLS_H
#define FNV_TESBIPEDMODELFORM_DECLS_H

class BSExtraData;
class InventoryChanges;
class TESBoundObject;
class TESObjectCELL;
class CellDataNode;
class ValidBip01Names;
class TESForm;
class TESModel;
class BSFaceGenModel;
class BGSListForm;
template <class T> class BSSimpleList;
#include "tesbipedmodelform_types_BIPED_OBJECT.h"
class BGSListForm
{
  public:
    BSSimpleList<TESForm*>* FUN_00500940();
    char _pdbpad_1[23];
    char ListOfForms_pad17_pad17_pad17[8];
    unsigned int m_uiFormCount;
};
class BSFaceGenModelExtraData
{
  public:
    BSFaceGenModel* GetModelFilePath();
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    T* operator->() const;
};
class NiNode
{
  public:
    void ApplyRDTNodeScales();
};
class BipedAnim
{
  public:
    void SetBipedObject(TESForm*, TESModel*, BIPED_OBJECT);
    NiNode* FUN_0043f010(BSFaceGenModel*);
};
class ModelLoader
{
  public:
    void FUN_004472a0(BSFaceGenModel*, NiPointer<BSFaceGenModelExtraData>*);
};
extern ModelLoader* g_modelLoader;
#endif
