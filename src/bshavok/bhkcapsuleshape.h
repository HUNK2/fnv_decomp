// bshavok/bhkcapsuleshape.h: declares bhkConvexShape, bhkCapsuleShape
#ifndef FNV_BSHAVOK_BHKCAPSULESHAPE_H
#define FNV_BSHAVOK_BHKCAPSULESHAPE_H

#include "layout_support.h"

class NiRTTI;
class NiObject;
class NiNode;
class NiColor;
class NiPoint3;
class CloningProcess;
class NiStream;
class hkVector4;
class hkSphere;
class hkTransform;
class hkContactPoint;
class hkGeometry;
class hkpShape;
class hkpConvexShape;
class hkpCapsuleShape;
class RigidBodyShape;
class PhysicsShapeClass;
class hkSerializableCinfo;
class bhkSerializable;
template <class T> class NiTPrimitiveArray;

// Parent header bhkConvexShape.h is not part of this unit; its declarations
// belong to the bhkConvexShape source unit.
class bhkConvexShape
{
  public:
    virtual ~bhkConvexShape();
    virtual const NiRTTI* GetRTTI() const;
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* viewerStrings);
    hkpConvexShape* Gethk();
    hkpConvexShape* operator*();
    PhysicsShapeClass& GetCinfo();
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    float GetRadius();
    void SetRadius(float radius);
    static bhkConvexShape* GetFromRigidBody(const hkpShape* shape);
    void CopyCinfo(PhysicsShapeClass& cinfo);
    static const NiRTTI ms_kRTTI;
    static unsigned int iCount;
};

class bhkCapsuleShape : public bhkConvexShape
{
  public:
    bhkCapsuleShape();
    virtual ~bhkCapsuleShape();
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* viewerStrings);
    hkpCapsuleShape* Gethk();
    hkpCapsuleShape* operator*();
    RigidBodyShape& GetCinfo();
    static NiObject* CreateObject();
    virtual NiObject* MakeClone(CloningProcess& cloningProcess);
    virtual void CopyMemberData(bhkSerializable* serializable, CloningProcess& cloningProcess);
    virtual hkSerializableCinfo& CreateCinfo(bool& cinfo);
    virtual void KillCinfo(bool cinfo);
    virtual unsigned int GetInstanceSize();
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual void BuildDisplayGeometry(NiNode* node, const NiColor& color);
    NiPoint3 GetVertex(int which);
    const hkVector4& GethkVertex(int which);
    static bhkCapsuleShape* GetFromRigidBody(const hkpShape* shape);
    bool GetClosestPoints(const hkSphere& sphere, const hkTransform& transform, hkContactPoint& point);
    void GetDisplayGeometry(hkGeometry& geometry);
    virtual const NiRTTI* GetRTTI() const;
    static const NiRTTI ms_kRTTI;
    static unsigned int iCount;

  protected:
    void CopyCinfo(RigidBodyShape& cinfo);

  public:
    bhkCapsuleShape& operator=(const bhkCapsuleShape& other);
};

// @fnv 0x0066d720
const NiRTTI* bhkCapsuleShape::GetRTTI() const
{
    return &ms_kRTTI;
}
#endif
