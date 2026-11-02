#ifndef NIQUATTRANSFORM_DECLS_H
#define NIQUATTRANSFORM_DECLS_H

class ThreeByThreeMatrix
{
  public:
    float m[3][3];
    NiPoint3 operator*(const NiPoint3&) const;
};
extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
inline NiQuatTransform::NiQuatTransform()
    : m_kTranslate(DAT_011a8400), m_kRotate(DAT_011f3704), m_fScale(-3.4028234663852886e38F)
{}
extern double _DAT_010241b0;
extern unsigned char DAT_011a9448;
NiQuaternion __cdecl FUN_00a6dc00(const NiQuaternion&);
__forceinline NiPoint3 MakePoint(float x, float y, float z)
{
    NiPoint3 p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}
__forceinline NiPoint3 RotatePoint(const ThreeByThreeMatrix& mat, const NiPoint3& p)
{
    return MakePoint(mat.m[0][0] * p.x + mat.m[0][1] * p.y + mat.m[0][2] * p.z,
                     mat.m[1][0] * p.x + mat.m[1][1] * p.y + mat.m[1][2] * p.z,
                     mat.m[2][0] * p.x + mat.m[2][1] * p.y + mat.m[2][2] * p.z);
}
inline NiPoint3 ScalePoint(const NiPoint3& p, float scale)
{
    NiPoint3 result;
    result.x = p.x * scale;
    result.y = p.y * scale;
    result.z = p.z * scale;
    return result;
}
inline NiPoint3 AddPoint(const NiPoint3& a, const NiPoint3& b)
{
    NiPoint3 p;
    p.x = a.x + b.x;
    p.y = a.y + b.y;
    p.z = a.z + b.z;
    return p;
}
#endif
