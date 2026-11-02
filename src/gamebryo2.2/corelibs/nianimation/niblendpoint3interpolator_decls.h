// gamebryo2.2/corelibs/nianimation/niblendpoint3interpolator_decls.h: declares NiInterpolator, NiBlendInterpolator, NiBlendPoint3Interpolator
#ifndef FNV_NIBLENDPOINT3INTERPOLATOR_PRIVATE_DECLS_H
#define FNV_NIBLENDPOINT3INTERPOLATOR_PRIVATE_DECLS_H


#include "NiObject.h"
#include "NiPoint3.h"

class NiObjectNET;
class NiAVObject;
class NiQuatTransform;
class NiStream;
class NiBlendInterpolator__InterpArrayItem;

// The PC NiObject slots preceding the interpolator Update overloads.
class NiInterpolator : public NiObject
{
  public:
    virtual void GetType();
    virtual void GetNiNode();
    virtual void GetFadeNode();
    virtual void GetMultiBoundNode();
    virtual void GetNiGeometry();
    virtual void GetTriBasedGeom();
    virtual void GetTriStrips();
    virtual void GetTriShape();
    virtual void GetSegmentedTriShape();
    virtual void GetResizableTriShape();
    virtual void GetNiParticles();
    virtual void GetNiLines();
    virtual void GetCollisionObject();
    virtual void GetBlendCollisionObject();
    virtual void GetRigidBody();
    virtual void GetLimitedHingeConstraint();
    virtual void Clone();
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject();
    virtual void RegisterStreamables();
    virtual void SaveBinary();
    virtual void Compare();
    virtual void GetViewerStrings();
    virtual void AddViewerStrings();
    virtual void ProcessClone();
    virtual void PostLinkObject();
    virtual void StreamCanSkip();
    virtual void GetStreamableRTTI();
    virtual void SetWorldBound();
    virtual void GetBlockAllocationSize();
    virtual void Unk_20();
    virtual void Unk_21(unsigned int);
    virtual void GetControllerManager();
    virtual bool Update(float, NiObjectNET*, NiPoint3&);
    virtual bool Update(float, NiObjectNET*, float&);
    virtual bool Update(float, NiAVObject*, const NiQuatTransform&);

    float m_fLastTime;
};

class NiBlendInterpolator : public NiInterpolator
{
  public:
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    char m_cHighPriority;
    char m_cNextHighPriority;
    NiBlendInterpolator__InterpArrayItem* m_pInterpArray;
    NiInterpolator* m_pSingleInterpolator;
    float m_fWeightThreshold;
    float m_fSingleInterpolatorTime;
    float m_fHighSumOfWeights;
    float m_fNextHighSumOfWeights;
    float m_fTrailingValue;

    void NormalizeWeights();
};

class NiBlendPoint3Interpolator : public NiBlendInterpolator
{
  public:
    NiPoint3 m_kPoint3Value;
    bool m_bValueValid;

    bool UpdateAccumulatedTransform(float, NiObjectNET*, NiPoint3&);
    bool UpdateSingleInterpolator(float, NiObjectNET*, NiPoint3&);
    virtual bool Update(float, NiObjectNET*, NiPoint3&);
};

extern const float DAT_0109696c;
extern const NiPoint3 DAT_011a9424;

FNV_STATIC_ASSERT(sizeof(NiInterpolator) == 12);
FNV_STATIC_ASSERT(sizeof(NiBlendInterpolator) == 48);
FNV_STATIC_ASSERT(sizeof(NiBlendPoint3Interpolator) == 64);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_pSingleInterpolator) == 24);
FNV_STATIC_ASSERT(offsetof(NiBlendPoint3Interpolator, m_kPoint3Value) == 48);

#endif
