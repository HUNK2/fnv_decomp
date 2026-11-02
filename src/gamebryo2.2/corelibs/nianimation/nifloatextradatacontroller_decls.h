#ifndef FNV_NIFLOATEXTRADATACONTROLLER_DECLS_H
#define FNV_NIFLOATEXTRADATACONTROLLER_DECLS_H


#include "NiRefObject.h"
#include "NiFixedString.h"

class NiRTTI;
class NiAVObject;
class BSFadeNode;
class BSMultiBoundNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class BSResizableTriShape;
class NiParticles;
class NiLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;
class NiObjectCopyInfo;
class NiStream;
class NiBound;
class NiControllerManager;
class NiQuatTransform;

// The generated NiObject header omits these virtual declarations. This private
// declaration supplies the PC slots used by the controller and interpolator.
class NiObject : public NiRefObject
{
  public:
    virtual NiRTTI* GetType();
    virtual NiNode* GetNiNode();
    virtual BSFadeNode* GetFadeNode();
    virtual BSMultiBoundNode* GetMultiBoundNode();
    virtual NiGeometry* GetNiGeometry();
    virtual NiTriBasedGeom* GetTriBasedGeom();
    virtual NiTriStrips* GetTriStrips();
    virtual NiTriShape* GetTriShape();
    virtual BSSegmentedTriShape* GetSegmentedTriShape();
    virtual BSResizableTriShape* GetResizableTriShape();
    virtual NiParticles* GetNiParticles();
    virtual NiLines* GetNiLines();
    virtual bhkNiCollisionObject* GetCollisionObject();
    virtual bhkBlendCollisionObject* GetBlendCollisionObject();
    virtual bhkRigidBody* GetRigidBody();
    virtual bhkLimitedHingeConstraint* GetLimitedHingeConstraint();
    virtual NiObject* Clone(NiObjectCopyInfo* copyInfo);
    virtual void LoadBinary(NiStream* stream);
    virtual void LinkObject(NiStream* stream);
    virtual void RegisterStreamables(NiStream* stream);
    virtual void SaveBinary(NiStream* stream);
    virtual bool Compare(NiObject* other);
    virtual void GetViewerStrings(NiTArray<char*, NiTMallocInterface<char*> >* strings);
    virtual void AddViewerStrings(NiTArray<char*, NiTMallocInterface<char*> >* strings);
    virtual void ProcessClone(NiObjectCopyInfo* copyInfo);
    virtual void PostLinkObject(NiStream* stream);
    virtual bool StreamCanSkip();
    virtual NiRTTI* GetStreamableRTTI();
    virtual void SetWorldBound(NiBound* worldBound);
    virtual unsigned int GetBlockAllocationSize();
    virtual void Unk_20();
    virtual void Unk_21(unsigned int arg);
    virtual NiControllerManager* GetControllerManager();
};
FNV_STATIC_ASSERT(sizeof(NiObject) == 8);

class NiUpdateData
{
  public:
    const float& GetTime() const
    {
        return fTime;
    }
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    unsigned char layoutPadding9[3];
};
FNV_STATIC_ASSERT(sizeof(NiUpdateData) == 12);

class NiInterpolator : public NiObject
{
  public:
    virtual bool Update(float time, NiAVObject* target, const NiQuatTransform& transform);  // +0x8C
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual bool Unk_27(float time, NiObjectNET* target, float& value);  // +0x9C
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31(float time, float endTime);
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual bool Unk_35();  // +0xD4: whether updates are always required
    virtual void Unk_36();
    float m_fLastTime;
};
FNV_STATIC_ASSERT(sizeof(NiInterpolator) == 12);

class NiTimeController : public NiObject
{
  public:
    virtual void Start(float time);  // +0x8C
    virtual void Stop();
    virtual void Update(NiUpdateData& update);  // +0x94
    virtual void SetTarget(NiObjectNET* target);
    virtual bool Unk_27();
    virtual void Unk_28();
    virtual float ComputeScaledTime(float time);
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    unsigned short m_uiObjectFlags;
    unsigned char layoutPaddingA[2];
    float m_fFrequency;
    float m_fPhase;
    float m_fLoKeyTime;
    float m_fHiKeyTime;
    float m_fStartTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fControllerTime;
    NiObjectNET* m_pkTarget;
    NiPointer<NiTimeController> m_spNextController;
    bool AdvanceController(float time);
    bool GetManagerControlled() const
    {
        return ((m_uiObjectFlags >> 5) & 1) != 0;
    }
};
FNV_STATIC_ASSERT(sizeof(NiTimeController) == 0x34);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fControllerTime) == 0x28);

class NiInterpController : public NiTimeController
{
};
class NiSingleInterpController : public NiInterpController
{
  public:
    NiPointer<NiInterpolator> m_spControllerInterpolator;
};
class NiExtraDataController : public NiSingleInterpController
{
  public:
    NiFixedString m_kDataName;
    NiPointer<NiExtraData> m_pExtraData;
};
class NiFloatExtraDataController : public NiExtraDataController
{
  public:
    virtual void Update(NiUpdateData& update);
};
FNV_STATIC_ASSERT(sizeof(NiFloatExtraDataController) == 0x40);
FNV_STATIC_ASSERT(offsetof(NiFloatExtraDataController, m_spControllerInterpolator) == 0x34);
FNV_STATIC_ASSERT(offsetof(NiFloatExtraDataController, m_pExtraData) == 0x3C);

class NiExtraData : public NiObject
{
  public:
    NiFixedString m_kName;
};
class NiFloatExtraData : public NiExtraData
{
  public:
    float m_fValue;
};
FNV_STATIC_ASSERT(offsetof(NiFloatExtraData, m_fValue) == 0xC);
extern const float DAT_01096324;

#endif
