// speedtree/libvector_source/idvvector.h: declares RotationMatrix3x3, Vector3D
#ifndef FNV_IDVVECTOR_H
#define FNV_IDVVECTOR_H

class RotationMatrix3x3
{
  public:
    float m_fComponents[3][3];
};
class Vector3D
{
  public:
    float x, y, z;
    __forceinline Vector3D(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Vector3D operator*(const RotationMatrix3x3& transform) const;
};
// @fnv 0x00b12890
Vector3D Vector3D::operator*(const RotationMatrix3x3& transform) const
{
    float result[3];
    result[0] =
        transform.m_fComponents[2][0] * z + (transform.m_fComponents[1][0] * y + transform.m_fComponents[0][0] * x);
    result[1] =
        transform.m_fComponents[2][1] * z + (transform.m_fComponents[1][1] * y + transform.m_fComponents[0][1] * x);
    result[2] =
        transform.m_fComponents[2][2] * z + (transform.m_fComponents[1][2] * y + transform.m_fComponents[0][2] * x);
    return Vector3D(result[0], result[1], result[2]);
}
#endif
