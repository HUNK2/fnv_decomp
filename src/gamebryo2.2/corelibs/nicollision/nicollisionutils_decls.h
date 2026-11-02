// gamebryo2.2/corelibs/nicollision/nicollisionutils_decls.h: declares NiPoint3, NiPosData, RayTriangleIntersector

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    NiPoint3 operator-(const NiPoint3& p) const
    {
        return NiPoint3(x - p.x, y - p.y, z - p.z);
    }
    NiPoint3 operator+(const NiPoint3& p) const
    {
        return NiPoint3(x + p.x, y + p.y, z + p.z);
    }
    NiPoint3 Cross(const NiPoint3& p) const
    {
        return NiPoint3(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
    }
    float Dot(const NiPoint3& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
};
class NiPosData
{
  public:
    static NiPoint3 ComputePositionAtTime(float, const NiPoint3&);
};
class RayTriangleIntersector
{
  public:
    static bool IntersectRayTriangle(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&,
                                     const NiPoint3&, bool, NiPoint3&, float&, float&, float&);
};
