
// src/havok/physics/collide/shape/convex/hkpconvexshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/hkpconvexshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/convex/hkpconvexshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/hkpconvexshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpConvexShape.h"
int __stdcall FUN_00c9e1e0(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};
class hkReferencedObjectC9E3
{
  public:
    hkReferencedObjectC9E3() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectC9E3() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};
class hkpShapeC9E3 : public hkReferencedObjectC9E3
{
  public:
    hkpShapeC9E3(int iType) : m_ulUserData(0), m_type(iType)
    {}
    hkUlong m_ulUserData;
    int m_type;
};
class hkpConvexShapeC9E3 : public hkpShapeC9E3
{
  public:
    hkpConvexShapeC9E3(int iType, hkReal fRadius) : hkpShapeC9E3(iType)
    {
        m_fSphereRadius = fRadius;
    }
    hkReal m_fSphereRadius;
};
class hkpShapeContainerC9E3
{
  public:
    virtual ~hkpShapeContainerC9E3() throw()
    {}
};
class hkpSingleShapeContainerC9E3 : public hkpShapeContainerC9E3
{
  public:
    hkpSingleShapeContainerC9E3(FUN_00d1df70* pkChild, int iRef) : m_pContainedShape(pkChild)
    {
        if (iRef == 1)
            m_pContainedShape->FUN_00c90510();
    }
    virtual ~hkpSingleShapeContainerC9E3() throw();
    FUN_00d1df70* m_pContainedShape;
};
class FUN_00c9e340 : public hkpConvexShapeC9E3
{
  public:
    hkpSingleShapeContainerC9E3 m_pContainedShape;

    FUN_00c9e340(int iType, hkReal fRadius, FUN_00d1df70* pkChild, int iRef) throw();
    virtual ~FUN_00c9e340() throw();
};
