#pragma once

#include "bhkconvert_decls.h"
#pragma strict_gs_check(on)
// @fnv 0x0056df80
hkTransform& FromHK(hkTransform& out, const NiTransform& in)
{
    VisitAndFetchThree(*reinterpret_cast<hkRotation*>(&reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(&out)->GetItem()),
                       in.rotation);
    hkVector4 position;
    reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(&position)->GetItem();
    out.FUN_0056d300(FUN_004a3e00(position, in.position));
    return out;
}

#pragma strict_gs_check(on)
// @fnv 0x00458620
NiPoint3& SetNiPoint3FromHkVector4(NiPoint3& out, const hkVector4& in)
{
    VectorComponentValue x, y, z;
    out.x = FUN_004587d0(in.FUN_00458700(x, 0).FUN_004586d0());
    out.y = FUN_004587d0(in.FUN_00458700(y, 1).FUN_004586d0());
    out.z = FUN_004587d0(in.FUN_00458700(z, 2).FUN_004586d0());
    return out;
}
