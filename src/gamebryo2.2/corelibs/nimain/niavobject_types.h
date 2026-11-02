// gamebryo2.2/corelibs/nimain/niavobject_types.h: declares NiPoint3, NiBound, FourComponentFloatVector, NiRefObject, NiObject and more
#ifndef FNV_NIAVOBJECT_TYPES_H
#define FNV_NIAVOBJECT_TYPES_H

// JohnnyGuitarNVSE PC reverse-engineering headers. No dependency definitions.
#include <stddef.h>
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
class CloningProcess;
class NiStream;
class NiObjectGroup;
class NiControllerManager;
class NiTimeController;
class NiExtraData;
class NiCollisionObject;
class NiUpdateData;
class FourComponentFloatVector;
template <class T> class NiTPrimitiveArray;
typedef NiTPrimitiveArray<char*> NiViewerStringsArray;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);
class NiPoint3
{
  public:
    float x, y, z;
    static const NiPoint3 ZERO;
};
class NiBound
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
    void SetCenterAndRadius(const NiPoint3&, float);
};
// FourComponentFloatVector, but these two parameter types are inferred from the PC call site.
class FourComponentFloatVector : public NiBound
{
  public:
    FourComponentFloatVector(unsigned int, unsigned int);
};
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};
class NiObject : public NiRefObject
{
  public:
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* IsSceneNode() const;
    virtual BSFadeNode* IsFadeNode() const;
    virtual BSMultiBoundNode* IsMultiBoundNode() const;
    virtual NiGeometry* IsGeometry() const;
    virtual NiTriBasedGeom* IsTriBasedGeometry() const;
    virtual NiTriStrips* IsTriStrips() const;
    virtual NiTriShape* IsTriShape() const;
    virtual BSSegmentedTriShape* IsSegmentedTriShape() const;
    virtual BSResizableTriShape* IsResizableTriShape() const;
    virtual NiParticles* IsParticlesGeom() const;
    virtual NiLines* IsLineGeometry() const;
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject() const;
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject() const;
    virtual bhkRigidBody* IsBhkRigidBody() const;
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint() const;
    virtual NiObject* MakeClone(CloningProcess&);
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual void RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);
    virtual bool IsEqual(NiObject*) const;
    virtual void GetViewerStrings(NiViewerStringsArray*);
    virtual void AddViewerStrings(NiViewerStringsArray*);
    virtual void ProcessClone(CloningProcess&);
    virtual void PostLinkObject(NiStream&);
    virtual bool StreamCanSkip();
    virtual const NiRTTI* GetStreamableRTTI();
    virtual void SetObjectBound(FourComponentFloatVector*);
    virtual void GetBlockAllocationSize();
    virtual NiObjectGroup* GetGroup();
    virtual void SetGroup(NiObjectGroup*);
    virtual NiControllerManager* IsControllerManager() const;
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    operator T*() const;
};
class NiFixedString
{
  public:
    const char* m_kHandle;
};
class NiObjectNET : public NiObject
{
  public:
    NiFixedString m_kName;
    NiPointer<NiTimeController> m_pControllers;
    NiExtraData** m_ppExtraData;
    unsigned short m_usExtraDataCount;
    unsigned short m_usMaxSize;
    NiTimeController* GetControllers() const;
};
class NiTimeController : public NiObject
{
  public:
    virtual void Start(float);
    virtual void Stop();
    virtual void Update(NiUpdateData&);
    NiTimeController* GetNext() const;
};
class NiProperty : public NiObjectNET
{
  public:
    enum Type
    {
        ALPHA,
        CULLING,
        MATERIAL,
        SHADE,
        STENCIL,
        TEXTURING,
        WIREFRAME,
        COUNT
    };
    virtual Type GetType() const;
    virtual void Update(NiUpdateData&);
};
typedef void* NiTListIterator;
template <class T> class NiTListItem;
template <class T> class NiTPointerAllocator
{
};
template <class Allocator, class T> class NiTListBase
{
  public:
    struct MapEntryCount : Allocator
    {
        unsigned int m_uiCount;
    };
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    MapEntryCount m_kItemCount;
    NiTListIterator GetHeadPos() const;
};
template <class Allocator, class T> class NiTPointerListBase : public NiTListBase<Allocator, T>
{
  public:
    T& GetNext(NiTListIterator&);
};
template <class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, T>
{
};
class ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];
};
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};
class NiAVObject : public NiObjectNET
{
  public:
    NiNode* m_pParentNode;
    NiPointer<NiCollisionObject> m_spCollisionObject;
    FourComponentFloatVector* m_kWorldBound;
    NiTPointerList<NiPointer<NiProperty> > SceneGraphObject;
    unsigned int m_uiObjectFlags;
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;
    bool GetHasPropertyController() const;
    void UpdateTimeControllers(NiUpdateData&, bool);
    void EnsureWorldBound();
};
typedef char NiObjectNET_size_check[sizeof(NiObjectNET) == 0x18 ? 1 : -1];
typedef char NiAVObject_size_check[sizeof(NiAVObject) == 0x9c ? 1 : -1];
typedef char NiAVObject_bound_check[offsetof(NiAVObject, m_kWorldBound) == 0x20 ? 1 : -1];
typedef char NiAVObject_property_check[offsetof(NiAVObject, SceneGraphObject) == 0x24 ? 1 : -1];
#endif
