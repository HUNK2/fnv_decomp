
// pathfind_ctx_variant.cpp: context variant of src/fallout_shared/pathfinding/pathfind.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "pathfind_decls.h"

struct Vec3 : NiPoint3
{
    Vec3();
    Vec3 FUN_00439e90(const Vec3&) const;
    Vec3 FUN_00439ef0(const Vec3&) const;
    Vec3 ApplyScaled(float) const;
};
struct Matrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    void FUN_006815c0();
    void FUN_004a0c90(float);
    Vec3 FUN_004b4500(const Vec3*);
};
struct PointOperations
{
    Vec3 FUN_0053d1a0(const Vec3&) const;
    float FUN_004a7290() const;
    float FUN_00457910();
    float DotProduct(const Vec3&) const;
    Vec3& Subtract(const Vec3&);
};
struct PathingLocationOperations
{
    Vec3 FUN_005c3420() const;
};
extern Vec3 DAT_011a9478;
extern const Vec3 DAT_011a9484;
extern const Vec3 DAT_011f426c;
extern const float DAT_01032adc;
extern const float DAT_01018204;
extern const double DAT_0106cbc8;
extern const double DAT_01012060;
extern const double DAT_010240c0;
extern bool __cdecl FUN_006d7490(PathingLocation&, const Vec3&, PathingLocation*, void*);
extern bool __cdecl FUN_006d7350(PathingLocation&, PathingLocation&, PathingLocation*, void*);

// @fnv 0x006d99a0
Vec3 __cdecl FUN_006d99a0(float angle, PathingLocation* startRef, PathingLocation* endRef, float radius)
{
    Matrix rotation6;
    rotation6.FUN_006815c0();
    rotation6.FUN_004a0c90(angle);
    Vec3 forwardAxis = rotation6.FUN_004b4500(&DAT_011a9478);
    PathingLocation start0(*startRef);
    Vec3 origin20 = ((PathingLocationOperations*)&start0)->FUN_005c3420();
    Vec3 goalId_ = origin20.FUN_00439e90(forwardAxis.ApplyScaled(DAT_01032adc));
    PathingLocation first2;
    if (!FUN_006d7490(start0, goalId_, &first2, 0))
        goalId_ = ((PathingLocationOperations*)&first2)->FUN_005c3420();
    Vec3 initial = goalId_.FUN_00439ef0(origin20);
    Vec3 sideShape7 = ((PointOperations*)&initial)->FUN_0053d1a0(DAT_011a9484).ApplyScaled(radius);
    PathingLocation leftStartB(origin20.FUN_00439ef0(sideShape7), start0);
    PathingLocation leftEnd5(goalId_.FUN_00439ef0(sideShape7), start0);
    if (!FUN_006d7350(leftStartB, leftEnd5, &first2, 0))
    {
        if (((PointOperations*)&(
                 const Vec3&)(((PathingLocationOperations*)&first2)
                                  ->FUN_005c3420()
                                  .FUN_00439ef0(((PathingLocationOperations*)&leftStartB)->FUN_005c3420())))
                ->FUN_004a7290() < ((PointOperations*)&initial)->FUN_004a7290())
            goalId_ = ((PathingLocationOperations*)&first2)->FUN_005c3420();
    }
    PathingLocation rightStart2(origin20.FUN_00439e90(sideShape7), start0);
    PathingLocation rightEnd2(goalId_.FUN_00439e90(sideShape7), start0);
    if (!FUN_006d7350(rightStart2, rightEnd2, &first2, 0))
    {
        if (((PointOperations*)&(
                 const Vec3&)(((PathingLocationOperations*)&first2)
                                  ->FUN_005c3420()
                                  .FUN_00439ef0(((PathingLocationOperations*)&rightStart2)->FUN_005c3420())))
                ->FUN_004a7290() < ((PointOperations*)&initial)->FUN_004a7290())
            goalId_ = ((PathingLocationOperations*)&first2)->FUN_005c3420();
    }
    ((PointOperations*)&goalId_)->Subtract(forwardAxis.ApplyScaled(radius).ApplyScaled(DAT_01018204));
    PathingLocation end19(*endRef);
    Vec3 endOriginVal = ((PathingLocationOperations*)&end19)->FUN_005c3420();
    PathingLocation endHitX;
    if (!FUN_006d7490(end19, goalId_, &endHitX, 0))
        return DAT_011f426c;
    Vec3 endDelta = goalId_.FUN_00439ef0(endOriginVal);
    Vec3 endSide = ((PointOperations*)&endDelta)->FUN_0053d1a0(DAT_011a9484).ApplyScaled(radius);
    PathingLocation endLeftEndA(endOriginVal.FUN_00439ef0(sideShape7), end19);
    PathingLocation endLeftStart6(goalId_.FUN_00439ef0(sideShape7), end19);
    if (!FUN_006d7350(endLeftEndA, endLeftStart6, &endHitX, 0))
        return DAT_011f426c;
    PathingLocation endRightStart4(endOriginVal.FUN_00439e90(sideShape7), end19);
    PathingLocation endRightEnd2(goalId_.FUN_00439e90(sideShape7), end19);
    if (!FUN_006d7350(endRightStart4, endRightEnd2, &endHitX, 0))
        return DAT_011f426c;
    Vec3 directionX = endOriginVal.FUN_00439ef0(origin20);
    float distance29 = ((PointOperations*)&directionX)->FUN_00457910();
    float i = ((PointOperations*)&directionX)->DotProduct(forwardAxis);
    if (i < DAT_0106cbc8)
    {
        return DAT_011f426c;
    }
    else if (i < DAT_01012060 && distance29 < DAT_010240c0)
    {
        return DAT_011f426c;
    }
    return goalId_.FUN_00439ef0(origin20);
}
