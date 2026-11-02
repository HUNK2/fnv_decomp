// fallout/interface/fadermanager_object_decls.h: declares NiMemObject, NiRefObject, NiObject, NiObjectNET, NiAVObject and more
#ifndef FADERMANAGER_OBJECT_DECLS_H
#define FADERMANAGER_OBJECT_DECLS_H

// FaderManager unit: file-static fader table plus the small accessors.
// The three covered functions here only need the table layout and a few
// out-of-line helpers; the larger EH functions follow in later work.
#include <stddef.h>

template <int> struct FNVAssert;
template <> struct FNVAssert<1>
{
};
#define FNV_STATIC_ASSERT(cond) typedef FNVAssert<(cond) ? 1 : 0> FNVAssertLine##__LINE__

enum FADER_ENUM
{
    FADER_ENUM_FADER_BLACK_UNDER_MENUS = 0,
    FADER_ENUM_FADER_TO_BLACK = 1,
    FADER_ENUM_FADER_TO_WHITE = 2,
    FADER_ENUM_FADER_COUNT = 3
};

// Forward declarations for vtable signature fidelity (JIP-LN-NVSE order).
class NiRTTI;
class NiNode;
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
class NiUpdateData;
class NiMatrix33;
class NiVector3;
class NiFixedString;
class NiPoint3;
class NiCullingProcess;
class NiDX9Renderer;
class GeometryProperties;
class TES;

class NiMemObject
{
  public:
    static void* operator new(size_t);
    static void operator delete(void*, unsigned int);
};

class NiRefObject : public NiMemObject
{
  public:
    /*00*/ virtual void Destructor(bool bFreeThis);
    /*04*/ virtual void Free(void);
};

class NiObject : public NiRefObject
{
  public:
    /*08*/ virtual NiRTTI* GetType();
    /*0C*/ virtual NiNode* GetNiNode();
    /*10*/ virtual BSFadeNode* GetFadeNode();
    /*14*/ virtual BSMultiBoundNode* GetMultiBoundNode();
    /*18*/ virtual NiGeometry* GetNiGeometry();
    /*1C*/ virtual NiTriBasedGeom* GetTriBasedGeom();
    /*20*/ virtual NiTriStrips* GetTriStrips();
    /*24*/ virtual NiTriShape* GetTriShape();
    /*28*/ virtual BSSegmentedTriShape* GetSegmentedTriShape();
    /*2C*/ virtual BSResizableTriShape* GetResizableTriShape();
    /*30*/ virtual NiParticles* GetNiParticles();
    /*34*/ virtual NiLines* GetNiLines();
    /*38*/ virtual bhkNiCollisionObject* GetCollisionObject();
    /*3C*/ virtual bhkBlendCollisionObject* GetBlendCollisionObject();
    /*40*/ virtual bhkRigidBody* GetRigidBody();
    /*44*/ virtual bhkLimitedHingeConstraint* GetLimitedHingeConstraint();
    /*48*/ virtual NiObject* Clone(NiObjectCopyInfo* pCopyInfo);
    /*4C*/ virtual void LoadBinary(NiStream* pStream);
    /*50*/ virtual void LinkObject(NiStream& pStream);
    /*54*/ virtual void RegisterStreamables(NiStream* pStream);
    /*58*/ virtual void SaveBinary(NiStream* pStream);
    /*5C*/ virtual bool Compare(NiObject* pOther);
    /*60*/ virtual void GetViewerStrings(void* apViewerStrings);
    /*64*/ virtual void AddViewerStrings(void* apViewerStrings);
    /*68*/ virtual void ProcessClone(NiObjectCopyInfo* pCopyInfo);
    /*6C*/ virtual void PostLinkObject(NiStream* pStream);
    /*70*/ virtual bool StreamCanSkip();
    /*74*/ virtual NiRTTI* GetStreamableRTTI();
    /*78*/ virtual void SetWorldBound(NiBound* pWorldBound);
    /*7C*/ virtual unsigned int GetBlockAllocationSize();
    /*80*/ virtual void Unk_20(void);
    /*84*/ virtual void Unk_21(unsigned int uArg);
    /*88*/ virtual NiControllerManager* GetControllerManager();
};

class NiObjectNET : public NiObject
{
  public:
};

class NiAVObject : public NiObjectNET
{
  public:
    NiNode* GetParent();
    void FUN_00440490(float);
    void FUN_00440460(const NiPoint3&);
    void SetName(const NiFixedString&);
    void AttachProperty(NiObject*);
    void UpdateSceneObject();
    void Update(NiUpdateData&);
    /*8C*/ virtual void UpdateControllers(NiUpdateData& kUpdParams);
    /*90*/ virtual void ApplyTransform(NiMatrix33* pArg1, NiVector3* pArg2, bool bArg3);
    /*94*/ virtual void Unk_25(unsigned int uArg);
    /*98*/ virtual void Unk_26(unsigned int uArg);
    /*9C*/ virtual NiAVObject* GetObjectByName(NiFixedString* pObjName);
    /*A0*/ virtual void SetSelectiveUpdateFlags(unsigned char* pbSelectiveUpdate,
                                                unsigned int uSelectiveUpdateTransform, unsigned char* pbRigid);
    /*A4*/ virtual void UpdateDownwardPass(NiUpdateData& kUpdParams, unsigned int uFlags);
    /*A8*/ virtual void UpdateSelectedDownwardPass(NiUpdateData& kUpdParams, unsigned int uFlags);
    /*AC*/ virtual void UpdateRigidDownwardPass(NiUpdateData& kUpdParams, unsigned int uFlags);
    /*B0*/ virtual void Unk_2C(GeometryProperties& kProperties);
    /*B4*/ virtual void Unk_2D(unsigned int uArg);
    /*B8*/ virtual void UpdateWorldData(NiUpdateData& kUpdParams);
    /*BC*/ virtual void UpdateWorldBound();
    /*C0*/ virtual void UpdateTransformAndBounds(NiUpdateData& kUpdParams);
    /*C4*/ virtual void PreAttachUpdate(NiNode* pNewParent, NiUpdateData& kUpdParams);
    /*C8*/ virtual void PreAttachUpdateProperties(NiNode* pNewParent);
    /*CC*/ virtual void DetachParent(unsigned int uArg);
    /*D0*/ virtual void UpdateUpwardPassParent();
    /*D4*/ virtual void OnVisible(NiCullingProcess* pCulling);
    /*D8*/ virtual void PurgeRendererData(NiDX9Renderer* pRenderer);
};

// NiNode vtable order follows community/JIP-LN-NVSE netimmerse.h; the
// covered StopFader calls slot 0xE8 (RemoveObject).
class NiNode : public NiAVObject
{
  public:
    /*DC*/ virtual void AddObject(NiAVObject* pObject, bool bFirstFree);
    /*E0*/ virtual void AddObjectAt(unsigned int uIndex, NiAVObject* pObject);
    /*E4*/ virtual void RemoveObject2(NiAVObject* pToRemove, NiAVObject** ppArg2);
    /*E8*/ virtual void RemoveObject(NiAVObject* pToRemove);
    /*EC*/ virtual void RemoveNthObject2(unsigned int uIndex, NiAVObject** ppArg2);
    /*F0*/ virtual void RemoveNthObject(unsigned int uIndex);
    /*F4*/ virtual void ReplaceNthObject2(unsigned int uIndex, NiAVObject* pReplaceWith, NiAVObject** ppArg3);
    /*F8*/ virtual void ReplaceNthObject(unsigned int uIndex, NiAVObject* pReplaceWith);
    /*FC*/ virtual void UpdateUpwardPass();
};

// BSFadeNode adds no virtuals over NiNode (community/JIP-LN-NVSE).
class BSFadeNode : public NiNode
{
  public:
};

// NiPointer assignment stays out-of-line (defined in its own unit), so the
// covered StopFader calls it instead of inlining it.
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer<T>& operator=(T* pObject);
    operator T*() const;
};

class TES
{
  public:
    void RefreshWorldState(int iArg1, int iArg2, int iArg3);
};

class FaderManager
{
  public:
    NiNode* m_pRootBelowMenus;  // +0x0
    NiNode* m_pRootAboveMenus;  // +0x4
    bool HasFader(FADER_ENUM eFader);
    float GetFadeValue(FADER_ENUM eFader);
    void StopFader(FADER_ENUM eFader, bool bForce);
    void AdvanceFaders(bool bUpdate);
    void AddFader(FADER_ENUM eFader, float fDuration, bool bFadeOut);
    void AddRoot(NiNode* pParent, float m_fProjectionDepth, bool m_bUseAlternateRoot);
};
FNV_STATIC_ASSERT(sizeof(FaderManager) == 8);
FNV_STATIC_ASSERT(offsetof(FaderManager, m_pRootBelowMenus) == 0);
FNV_STATIC_ASSERT(offsetof(FaderManager, m_pRootAboveMenus) == 4);

// One entry per FADER_ENUM value (FADER_COUNT == 3); entry size is 0x1C.
struct FaderEntry
{
    bool m_bUseAlternateRoot;  // +0x00
    unsigned char pad01[3];
    const char* pTextureName;  // +0x04
    bool bUnk08;               // +0x08
    unsigned char pad09[3];
    float fUnk0C;                     // +0x0C
    BSFadeNode* pFadeNode;            // +0x10
    float fAlpha;                     // +0x14
    NiPointer<NiNode> m_pParentNode;  // +0x18
};
FNV_STATIC_ASSERT(sizeof(FaderEntry) == 0x1C);
FNV_STATIC_ASSERT(offsetof(FaderEntry, bUnk08) == 0x08);
FNV_STATIC_ASSERT(offsetof(FaderEntry, fUnk0C) == 0x0C);
FNV_STATIC_ASSERT(offsetof(FaderEntry, pFadeNode) == 0x10);
FNV_STATIC_ASSERT(offsetof(FaderEntry, fAlpha) == 0x14);
FNV_STATIC_ASSERT(offsetof(FaderEntry, m_pParentNode) == 0x18);

static FaderEntry s_faders[FADER_ENUM_FADER_COUNT];
static bool s_bAllowDetach;
extern const float s_faderClearedAlpha;
extern TES* g_TES;

#endif
