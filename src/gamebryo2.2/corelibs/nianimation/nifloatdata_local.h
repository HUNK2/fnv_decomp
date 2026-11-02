// Copied verbatim (with layout asserts) from the task's
// vtable constructor entries are declared out-of-line so calls resolve
// to the canonical symbols instead of being emitted inline.
#ifndef FNV_NILODDATA_H
#define FNV_NILODDATA_H

#include "layout_support.h"
#include "NiObject.h"
class NiLODData;
#pragma pack(push, 4)
class NiLODData : public NiObject
{
  public:
    NiLODData();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiLODData) == 8);
#endif

#ifndef FNV_NIFLOATDATA_H
#define FNV_NIFLOATDATA_H
#include "layout_support.h"
#include "NiObject.h"
class NiFloatData;
class TimedAnimationKey;
enum NiAnimationKey__KeyType
{
    NiAnimationKey__KeyType_NOINTERP = 0,
    NiAnimationKey__KeyType_LINKEY = 1,
    NiAnimationKey__KeyType_BEZKEY = 2,
    NiAnimationKey__KeyType_TCBKEY = 3,
    NiAnimationKey__KeyType_EULERKEY = 4,
    NiAnimationKey__KeyType_STEPKEY = 5,
    NiAnimationKey__KeyType_NUMKEYTYPES = 6
};
#pragma pack(push, 4)
class NiFloatData : public NiLODData
{
  public:
    NiFloatData();
    unsigned int m_uiNumKeys;                // +0x8, 4 bytes
    TimedAnimationKey* m_pKeyArray;          // +0xC, 4 bytes
    NiAnimationKey__KeyType m_eRequestType;  // +0x10, 4 bytes
    unsigned char m_ucKeyDataSize;           // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiFloatData) == 24);
FNV_STATIC_ASSERT(offsetof(NiFloatData, m_uiNumKeys) == 8);
FNV_STATIC_ASSERT(offsetof(NiFloatData, m_pKeyArray) == 12);
FNV_STATIC_ASSERT(offsetof(NiFloatData, m_eRequestType) == 16);
FNV_STATIC_ASSERT(offsetof(NiFloatData, m_ucKeyDataSize) == 20);
#endif
