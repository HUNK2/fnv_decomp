// gamebryo2.2/corelibs/nimain/nibound_decls.h: declares NiPoint3, NiTransform, NiBound
#ifndef NIBOUND_DECLS_H
#define NIBOUND_DECLS_H

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    // Preserve the original x87 load order for the middle component.
    NiPoint3 operator*(float s) const
    {
        NiPoint3 r;
        r.x = x * s;
        r.y = (*(volatile const float*)&y) * s;
        r.z = z * s;
        return r;
    }
    NiPoint3 operator+(const NiPoint3& p) const
    {
        return NiPoint3(x + p.x, y + p.y, z + p.z);
    }
};
class ThreeByThreeMatrix
{
  public:
    float m[3][3];
    NiPoint3 operator*(const NiPoint3& p) const
    {
        return NiPoint3(m[0][0] * p.x + m[0][1] * p.y + m[0][2] * p.z, m[1][0] * p.x + m[1][1] * p.y + m[1][2] * p.z,
                        m[2][0] * p.x + m[2][1] * p.y + m[2][2] * p.z);
    }
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
    void Update(const NiBound&, const NiTransform&);
};
#endif
