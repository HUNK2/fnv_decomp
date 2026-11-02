// fallout/magic/magicmodelhiteffect_decls.h: declares NiAVObject, NiObjectNET, EffectSetting, TimeGlobal, PlayerCharacter and more
#ifndef FNV_MAGICMODELHITEFFECT_DECLS_H
#define FNV_MAGICMODELHITEFFECT_DECLS_H

#include "layout_support.h"
#include "magichiteffect_classes.h"
struct NiRTTI;
class NiProperty;
class SkyShaderProperty;
class NiTimeController;
class NiControllerSequence;
class NiNode;
class NiUpdateData;
class NiAVObject
{
  public:
    NiNode* GetParent();
    void Update(NiUpdateData&);
};
class NiObjectNET
{
  public:
    NiTimeController* GetControllers() const;
};
class EffectSetting
{
  public:
    bool IsFlagSet(unsigned int);
};
class ActiveEffect
{
  public:
    float GetAge();
    EffectSetting* GetEffectSetting();
};
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};
class PlayerCharacter
{
  public:
    bool FUN_004eaf60();
};
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
};
class NiUpdateData
{
  public:
    float time;
    unsigned int flags;
    void* data;
    NiUpdateData(float, bool, bool);
};
// NiControllerSequence: PC vftable 36 slots = NiObject's 35 + Deactivate (v8C). The NiObject slots v08..v88 are
// declared here for the same reason as in magichiteffect_classes.h (canonical NiObject.h lacks them).
class NiControllerSequence : public NiObject
{
  public:
    virtual const NiRTTI* GetRTTI();                                     // v08
    virtual NiNode* IsSceneNode();                                       // v0C
    virtual BSFadeNode* IsFadeNode();                                    // v10
    virtual BSMultiBoundNode* IsMultiBoundNode();                        // v14
    virtual NiGeometry* IsGeometry();                                    // v18
    virtual NiTriBasedGeom* IsTriBasedGeom();                            // v1C
    virtual NiTriStrips* IsTriStrips();                                  // v20
    virtual NiTriShape* IsTriShape();                                    // v24
    virtual BSSegmentedTriShape* IsSegmentedTriShape();                  // v28
    virtual BSResizableTriShape* IsResizableTriShape();                  // v2C
    virtual NiParticles* IsParticlesGeom();                              // v30
    virtual NiLines* IsLineGeometry();                                   // v34
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject();              // v38
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject();        // v3C
    virtual bhkRigidBody* IsBhkRigidBody();                              // v40
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint();    // v44
    virtual NiObject* MakeClone(CloningProcess& arCloning);              // v48
    virtual void LoadBinary(NiStream& arStream);                         // v4C
    virtual void LinkObject(NiStream& arStream);                         // v50
    virtual bool RegisterStreamables(NiStream& arStream);                // v54
    virtual void SaveBinary(NiStream& arStream);                         // v58
    virtual bool IsEqual(NiObject* apObject);                            // v5C
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* apStrings);  // v60
    virtual void AddViewerStrings(NiTPrimitiveArray<char*>* apStrings);  // v64
    virtual void ProcessClone(CloningProcess& arCloning);                // v68
    virtual void PostLinkObject(NiStream& arStream);                     // v6C
    virtual bool StreamCanSkip();                                        // v70
    virtual const NiRTTI* GetStreamableRTTI();                           // v74
    virtual void SetObjectBound(FourComponentFloatVector* apBound);      // v78
    virtual unsigned int GetBlockAllocationSize();                       // v7C
    virtual NiObjectGroup* GetGroup();                                   // v80
    virtual void SetGroup(NiObjectGroup* apGroup);                       // v84
    virtual NiControllerManager* IsNiControllerManager();                // v88
    virtual bool Deactivate(float afEaseOutTime, bool abTransition);     // v8C
    void SetSequenceTime(float, bool);
};
class NiControllerManager
{
  public:
    NiControllerSequence* FindSequenceByName(const NiFixedString&);
    void DeactivateAllSequences(float);
    bool ActivateControllerSequence(NiControllerSequence*, int, bool, float, float, NiControllerSequence*);
    void FUN_0047aa40(bool);
};
class ModelLoader
{
  public:
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
    void QueueModelLoad(const char*, bool, unsigned int);
};
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    NiPointer<NiAVObject>& operator=(NiAVObject*);
};
template <> class NiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    NiNode* operator->() const;
};
extern ModelLoader* g_modelLoader;
extern TimeGlobal g_timeGlobal;
extern PlayerCharacter* g_thePlayer;
extern NiRTTI DAT_011f36ac;
SkyShaderProperty* __cdecl FUN_00653270(const NiRTTI*, NiProperty*);
NiAVObject* __cdecl LoadAndCloneModel(const char*);
void __cdecl FUN_00c4b500(NiAVObject*);
extern const char kMagicModelHitEffectName[];
#endif
