// bshavok/bhkconvert_decls.h: declares hkRotation, hkTransform, NiPoint3, NiTransform
#pragma once

struct hkRotation;
class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
};
struct __declspec(align(16)) VectorComponentValue
{
    char data[16];
    float FUN_004586d0() const;
};
struct __declspec(align(16)) hkVector4
{
    union
    {
        float data[4];
        char bytes[16];
    };
    VectorComponentValue& FUN_00458700(VectorComponentValue&, int) const;
};
float FUN_004587d0(float);
struct hkRotation
{
    float data[12];
};
struct hkTransform : hkRotation
{
    hkVector4 position;
    void FUN_0056d300(const hkVector4&);
};
struct NiPoint3
{
    float x, y, z;
};
struct ThreeByThreeMatrix
{
    float data[9];
};
struct NiTransform
{
    ThreeByThreeMatrix rotation;
    NiPoint3 position;
    float scale;
};
hkRotation& VisitAndFetchThree(hkRotation&, const ThreeByThreeMatrix&);
hkVector4& FUN_004a3e00(hkVector4&, const NiPoint3&);
