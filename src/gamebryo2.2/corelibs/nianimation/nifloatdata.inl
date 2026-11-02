
#include "nifloatdata_local.h"

// @fnv 0x0052cf30
NiFloatData::NiFloatData()
    : NiLODData()
    , m_uiNumKeys(0)
    , m_pKeyArray(0)
    , m_eRequestType(NiAnimationKey__KeyType_NOINTERP)
    , m_ucKeyDataSize(0)
{
}
