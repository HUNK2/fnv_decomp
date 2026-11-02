// Source layout: NiPoint3. PC corrections are in generate_headers.py.
#ifndef FNV_NIPOINT3_H
#define FNV_NIPOINT3_H
#include "layout_support.h"
#pragma pack(push, 4)
class NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
    NiPoint3 operator+(const NiPoint3& point) const;
    NiPoint3 operator-(const NiPoint3& point) const;
    NiPoint3 operator*(float scalar) const;
    NiPoint3& operator+=(const NiPoint3& point)
    {
        x += point.x;
        y += point.y;
        z += point.z;
        return *this;
    }
    NiPoint3& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }
    float Dot(const NiPoint3& point) const
    {
        return x * point.x + y * point.y + z * point.z;
    }
    float Length() const;
    void Unitize();
    static const NiPoint3 ZERO;
    float GetLengthSquared();
    NiPoint3 CrossProduct(const NiPoint3& point) const;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint3) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiPoint3, x) == 0x0);
FNV_STATIC_ASSERT(offsetof(NiPoint3, y) == 0x4);
FNV_STATIC_ASSERT(offsetof(NiPoint3, z) == 0x8);
#endif
