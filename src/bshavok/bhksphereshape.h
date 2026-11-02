// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/bshavok/bhksphereshape.h
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x0056e9f0  bhkSphereShape::GetRTTI                 (16 bytes)
#ifndef BHKSPHERESHAPE_H
#define BHKSPHERESHAPE_H


#include "layout_support.h"

class NiRTTI;
class NiObject;
class NiNode;
class NiColor;
class NiPoint3;
class CloningProcess;
class NiStream;
class hkpConvexShape;
class PhysicsShapeClass;
class hkpShape;
template <class T> class NiTPrimitiveArray;

// Parent header bhkConvexShape.h belongs to the bhkConvexShape source unit;
// its layout is authored here to keep the translation unit self-contained.
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

class bhkSphereShape : public bhkConvexShape
{
  public:
    virtual const NiRTTI* GetRTTI() const;
    static const NiRTTI ms_kRTTI;
};

// @fnv 0x0056e9f0
const NiRTTI* bhkSphereShape::GetRTTI() const
{
    return &ms_kRTTI;
}
#endif
