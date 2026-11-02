
#include "niquattransform_types_NiQuatTransform.h"

extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
extern float DAT_01096b8c;

#pragma optimize("", off)
// @fnv 0x00494260
NiQuatTransform::NiQuatTransform()
{
    m_kTranslate = DAT_011a8400;
    m_kRotate = DAT_011f3704;
    m_fScale = DAT_01096b8c;
}

#pragma optimize("", on)
// @fnv 0x00a39180
bool NiQuatTransform::IsInvalid() const
{
    return m_fScale == -3.4028234663852886e+38 && m_kRotate.m_fVectorY == -3.4028234663852886e+38 && m_kTranslate.x == -3.4028234663852886e+38;
}

