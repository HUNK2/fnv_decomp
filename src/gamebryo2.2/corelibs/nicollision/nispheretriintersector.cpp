
// src/gamebryo2.2/corelibs/nicollision/nispheretriintersector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nispheretriintersector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Vector3
{
    float x, y, z;
    Vector3()
    {}
    Vector3(float x0, float y0, float z0) : x(x0), y(y0), z(z0)
    {}
};
struct FloatMatrix3
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct StoredPosition
{
    float unk00;
    Vector3 position;
};
extern "C" double DAT_01012070;
extern "C" float __cdecl GetSquaredDistanceToTriangle(const Vector3*, const FloatMatrix3*, void*, void*);
struct CollisionGeometry
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    StoredPosition* base;
    FloatMatrix3 basis;
    float scaling;
    int param64, param68;
    float __thiscall FUN_00eb5bf0(const Vector3*, const Vector3*, float);
};
// @fnv 0x00eb5bf0
float __thiscall CollisionGeometry::FUN_00eb5bf0(const Vector3* motion, const Vector3* translation, float amount)
{
    Vector3 scaledMotion(motion->x * amount, motion->y * amount, motion->z * amount);
    const Vector3& storedPos = base->position;
    Vector3 offsetPoint(storedPos.x + scaledMotion.x, storedPos.y + scaledMotion.y, storedPos.z + scaledMotion.z);
    FloatMatrix3 adjustedBasis = basis;
    Vector3 scaledTranslation(translation->x * amount, translation->y * amount, translation->z * amount);
    adjustedBasis.m00 = adjustedBasis.m00 + scaledTranslation.x;
    adjustedBasis.m01 = scaledTranslation.y + adjustedBasis.m01;
    adjustedBasis.m02 = scaledTranslation.z + adjustedBasis.m02;
    return (float)(GetSquaredDistanceToTriangle(&offsetPoint, &adjustedBasis, &param64, &param68) * scaling -
                   DAT_01012070);
}
