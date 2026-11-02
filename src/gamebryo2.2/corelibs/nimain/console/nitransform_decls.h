// gamebryo2.2/corelibs/nimain/console/nitransform_decls.h: declares NiPoint3, NiTransform, NiAVObject, NiPosData
#ifndef NITRANSFORM_DECLS_H
#define NITRANSFORM_DECLS_H
class NiPoint3
{
  public:
    NiPoint3();
    float x, y, z;
    NiPoint3 FUN_004a0bd0() const;
};
class ThreeByThreeMatrix
{
  public:
    float entry[9];
    ThreeByThreeMatrix Transpose();
    NiPoint3 operator*(const NiPoint3&) const;
};
class NiTransform
{
  public:
    ThreeByThreeMatrix rotation;
    NiPoint3 translation;
    float scale;
    NiTransform operator*(const NiTransform&) const;
    void CalculateInverse(NiTransform&);
};
class NiAVObject
{
  public:
    char pad0[0x18];
    NiAVObject* parent;
    char pad1[0x14];
    unsigned int flags;
    NiTransform local;
    NiTransform world;
    void UpdateWorldLoc();
};
class NiPosData
{
  public:
    static NiPoint3 ComputePositionAtTime(float, const NiPoint3&);
};
#endif
