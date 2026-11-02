
#include "nitransform_decls.h"
#pragma optimize("gty", on)
// @fnv 0x00a68bf0
void NiAVObject::UpdateWorldLoc()
{
 if (parent) {
  if ((unsigned char)(flags >> 9) & 1) world = parent->world;
  else world = parent->world * local;
 } else world = local;
}
#pragma optimize("", off)
// @fnv 0x004b4880
void NiTransform::CalculateInverse(NiTransform& out)
{
 out.rotation = rotation.Transpose();
 out.scale = 1.0f / scale;
 out.translation = NiPosData::ComputePositionAtTime(out.scale, out.rotation * translation.FUN_004a0bd0());
}
#pragma optimize("", on)
