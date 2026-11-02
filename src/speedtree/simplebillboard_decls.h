// speedtree/simplebillboard_decls.h: declares RotationMatrix3x3, Vector3D, SimpleBillboard
#ifndef SIMPLEBILLBOARD_DECLS_H
#define SIMPLEBILLBOARD_DECLS_H

class RotationMatrix3x3
{
  public:
    float m_fComponents[3][3];
    __forceinline void Set()
    {
        m_fComponents[0][0] = 1.0f;
        m_fComponents[0][1] = 0.0f;
        m_fComponents[0][2] = 0.0f;
        m_fComponents[1][0] = 0.0f;
        m_fComponents[1][1] = 1.0f;
        m_fComponents[1][2] = 0.0f;
        m_fComponents[2][0] = 0.0f;
        m_fComponents[2][1] = 0.0f;
        m_fComponents[2][2] = 1.0f;
    }
    void FUN_00b273d0(float);
};
class Vector3D
{
  public:
    float x, y, z;
    __forceinline Vector3D()
    {
        z = 0.0f;
        y = 0.0f;
        x = 0.0f;
    }
    __forceinline Vector3D(const float* p)
    {
        x = p[0];
        y = p[1];
        z = p[2];
    }
    __forceinline Vector3D(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    __forceinline const float& operator[](int i) const
    {
        return (&x)[i];
    }
    __forceinline void Set(const float& a, const float& b, const float& c)
    {
        x = a;
        y = b;
        z = c;
    }
    Vector3D operator*(const RotationMatrix3x3&) const;
};
class SimpleBillboard
{
  public:
    static void CalculateBillboardTransform(const float*);
};
// Preserve the original debug-build inline workspace allocation (23 float slots).
__forceinline void ReserveBillboardWorkspace()
{
    float workspace0, workspace1, workspace2, workspace3, workspace4, workspace5, workspace6, workspace7, workspace8,
        workspace9, workspace10, workspace11, workspace12, workspace13, workspace14, workspace15, workspace16,
        workspace17, workspace18, workspace19, workspace20, workspace21, workspace22;
}
#include <math.h>
extern const double DAT_010a4d90;
extern Vector3D DAT_011f8d08, DAT_011f8d14, DAT_011f8d20, DAT_011f8d2c;
#endif
