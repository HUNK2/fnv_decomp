// gamebryo2.2/corelibs/nimain/console/nipoint3_decls.h: declares NiPoint3, NiPlane
#ifndef FNV_NIPOINT3_CONSOLE_DECLS_H
#define FNV_NIPOINT3_CONSOLE_DECLS_H


#include "layout_support.h"

// Private declarations retain the canonical twelve-byte PC vector layout.
class NiPoint3
{
  public:
    float x;
    float y;
    float z;

    NiPoint3(float fX, float fY, float fZ);
    float ComputeMagnitude() const;
    float GetLengthSquared();
    NiPoint3 CrossProduct(const NiPoint3& kPoint) const;
    NiPoint3 FUN_0053d280(float fScalar) const;
};

FNV_STATIC_ASSERT(sizeof(NiPoint3) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(NiPoint3, y) == 4);
FNV_STATIC_ASSERT(offsetof(NiPoint3, z) == 8);

float FUN_004579e0(float fValue);
extern const double DAT_01017cf8;

class NiPlane
{
  public:
    NiPoint3 m_kPlaneNormal;
    float m_fPlaneConstant;
    NiPlane(const NiPoint3& kNormal, const NiPoint3& kPoint);
};

#endif
