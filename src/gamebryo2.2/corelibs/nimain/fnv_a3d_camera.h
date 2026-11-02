// gamebryo2.2/corelibs/nimain/fnv_a3d_camera.h: declares NiPoint3, NiTransform, NiBound, NiFrustum, NiUpdateData and more
#ifndef FNV_A3D_CAMERA_H
#define FNV_A3D_CAMERA_H

#include <stddef.h>
#define FNV_ASSERT(name, expression) typedef char name[(expression) ? 1 : -1]
class NiRTTI;
class NiNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class NiParticles;
class NiLines;
class NiObjectCopyInfo;
class BSFadeNode;
class BSMultiBoundNode;
class BSSegmentedTriShape;
class BSResizableTriShape;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;
class NiControllerManager;
class NiTimeController;
class NiExtraData;
class NiCollisionObject;
class NiStream;
class NiBound;
class NiFixedString;
class NiCullingProcess;
class NiDX9Renderer;
class GeometryProperties;
class NiRenderTargetGroup;
template <class T> class NiTArray;
class NiPoint3
{
  public:
    float x, y, z;
    void ComputeMagnitude();
    NiPoint3 CrossProduct(const NiPoint3& vector) const;
    static const NiPoint3 ZERO;
};
class ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];
    ThreeByThreeMatrix ComposeMatrices(const ThreeByThreeMatrix& matrix) const;
};
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};
class NiBound
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
};
class NiFrustum
{
  public:
    float m_fLeftBound, m_fRightBound, m_fTopBound, m_fBottomBound, m_fNearPlane, m_fFarPlane;
    bool m_bOrthographic;
};
template <class T> class NiRect
{
  public:
    T m_fMinimumU, m_fMaximumU, m_fMinimumV, m_fMaximumV;
};
class NiUpdateData
{
  public:
    float fTime;
    bool m_bUpdateEnabled, m_bRender, m_bInterpolate, m_bTimeToDie, m_bVisible;
};
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};
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
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool Compare(NiObject* other);
    virtual void GetViewerStrings(NiTArray<char*>* strings);
    virtual void AddViewerStrings(NiTArray<char*>* strings);
    virtual void ProcessClone(NiObjectCopyInfo* copyInfo);
    virtual void PostLinkObject(NiStream& stream);
    virtual bool StreamCanSkip();
    virtual NiRTTI* GetStreamableRTTI();
    virtual void SetWorldBound(NiBound* bound);
    virtual unsigned int GetBlockAllocationSize();
    virtual void Unk_20();
    virtual void Unk_21(unsigned int argument);
    virtual NiControllerManager* GetControllerManager();
};
class NiObjectNET : public NiObject
{
  public:
    const char* m_kName;
    NiTimeController* m_pControllers;
    NiExtraData** m_ppExtraData;
    unsigned short m_usExtraDataCount, m_usMaxSize;
};
class NiAVObject : public NiObjectNET
{
  public:
    NiNode* m_pParentNode;
    NiCollisionObject* m_spCollisionObject;
    NiBound* m_kWorldBound;
    unsigned char SceneGraphObject[12];
    unsigned int m_uiObjectFlags;
    NiTransform m_kLocalTransform, m_kWorldSpaceTransform;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void UpdateControllers(NiUpdateData& update);
    virtual void ApplyTransform(ThreeByThreeMatrix* rotate, NiPoint3* translate, bool multiply);
    virtual void Unk_25(unsigned int value);
    virtual void Unk_26(unsigned int value);
    virtual NiAVObject* GetObjectByName(NiFixedString* name);
    virtual void SetSelectiveUpdateFlags(unsigned char* selective, unsigned int transform, unsigned char* rigid);
    virtual void UpdateDownwardPass(NiUpdateData& update, unsigned int flags);
    virtual void UpdateSelectedDownwardPass(NiUpdateData& update, unsigned int flags);
    virtual void UpdateRigidDownwardPass(NiUpdateData& update, unsigned int flags);
    virtual void Unk_2C(const GeometryProperties& properties);
    virtual void Unk_2D(unsigned int value);
    virtual void UpdateWorldData(NiUpdateData& update);
    virtual void UpdateWorldBound();
    virtual void UpdateTransformAndBounds(NiUpdateData& update);
    virtual void PreAttachUpdate(NiNode* parent, NiUpdateData& update);
    virtual void PreAttachUpdateProperties(NiNode* parent);
    virtual void DetachParent(unsigned int value);
    virtual void UpdateUpwardPassParent();
    virtual void OnVisible(NiCullingProcess* culling);
    virtual void PurgeRendererData(NiDX9Renderer* renderer);
};
class NiNode : public NiAVObject
{
};
class NiCamera : public NiAVObject
{
  public:
    float m_afWorldToCamera[4][4];
    NiFrustum m_kViewFrustum;
    float m_fMinNearPlaneDist, m_fMaxFarNearRatio;
    NiRect<float> m_kPort;
    float m_fTrailingValue;
    const NiFrustum& GetViewFrustum() const;
    void UpdateViewFrustum(const NiFrustum& frustum);
    virtual void UpdateWorldData(NiUpdateData& update);
    virtual void UpdateWorldBound();
    void UpdateWorldFrustum();
    virtual void LinkObject(NiStream& stream);
    virtual void LoadBinary(NiStream& stream);
    bool WindowPixelToRay(long x, long y, NiPoint3& origin, NiPoint3& direction, const NiRenderTargetGroup* group);
    void ScreenPointToRay(float x, float y, NiPoint3& origin, NiPoint3& direction);
    bool AimAt(const NiPoint3& point, const NiPoint3& up);
    void GetScreenSpaceBounds(const NiBound& bound, NiPoint3& minimum, NiPoint3& maximum, float tolerance);
};
class NiBinaryStream
{
  public:
    typedef unsigned int(__cdecl* ReadFunction)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    typedef unsigned int(__cdecl* WriteFunction)(NiBinaryStream*, const void*, unsigned int, unsigned int*,
                                                 unsigned int);
    virtual ~NiBinaryStream();
    virtual bool FileIsGood();
    virtual void Seek(int displacement);
    virtual unsigned int GetPosition() const;
    virtual void SetEndianSwap(bool swap);
    unsigned int m_uiStreamFlags;
    ReadFunction m_pfnRead;
    WriteFunction m_pfnWrite;
};
class NiStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned char streamHeaderAndGroups[0xd4];
    unsigned int m_uiNifVersion;
    unsigned char streamTables[0x170];
    NiBinaryStream* m_pUnderlyingStream;
    unsigned char outputAndLinkTables[0x34];
    unsigned short m_usAVObjectFlags;
    NiObject* GetLoadedObject();
    unsigned int GetLinkID();
    void ResetStreamState();
    unsigned int ReadUnsignedInteger();
};
class MemoryManager
{
  public:
    void* Allocate(unsigned int size);
};
extern MemoryManager g_memoryManager;
extern const double runtimeInitializationDouble2;
class NiRenderer
{
  public:
    static NiRenderer* ms_pRenderer;
    bool MapScreenCoordinates(unsigned int x, unsigned int y, float& mappedX, float& mappedY,
                              const NiRenderTargetGroup* group);
    char _pdbpad_1[7];
    char m_spAccum_pad7_pad7[4];
    void* m_pCamera;
    void* m_pActiveRenderTargetGroup;
    char m_acRendererDataB[4];
    char _pdbpad_18[104];
    char m_acRendererDataC[128];
    char m_acRendererDataD[128];
    char m_acRendererDataE[128];
    int m_iRendererState;
    unsigned int m_uiRendererFlags;
    bool m_bRendererFlagA;
    bool m_bRendererFlagB;
    char _pdbpad_20a[118];
};
extern "C"
{
    __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
    __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
}
FNV_ASSERT(NiMatrix3PCSize, sizeof(ThreeByThreeMatrix) == 36);
FNV_ASSERT(NiTransformPCSize, sizeof(NiTransform) == 52);
FNV_ASSERT(NiAVObjectPCSize, sizeof(NiAVObject) == 0x9c);
FNV_ASSERT(NiCameraPCSize, sizeof(NiCamera) == 0x114);
FNV_ASSERT(NiCameraFrustumOffset, offsetof(NiCamera, m_kViewFrustum) == 0xdc);
FNV_ASSERT(NiCameraWorldTranslateOffset,
           offsetof(NiAVObject, m_kWorldSpaceTransform) + offsetof(NiTransform, m_kTranslation) == 0x8c);
FNV_ASSERT(NiStreamVersionOffset, offsetof(NiStream, m_uiNifVersion) == 0xd8);
FNV_ASSERT(NiStreamInputOffset, offsetof(NiStream, m_pUnderlyingStream) == 0x24c);
FNV_ASSERT(NiStreamAVFlagsOffset, offsetof(NiStream, m_usAVObjectFlags) == 0x284);
FNV_ASSERT(NiBinaryReadOffset, offsetof(NiBinaryStream, m_pfnRead) == 8);
#endif
