// fallout_shared/region system/tesregion_data_types.h: declares TESWorldSpace, TESRegionData
#ifndef FNV_TESREGION_DATA_TYPES_H
#define FNV_TESREGION_DATA_TYPES_H

#include "tesregion_TESForm.h"
#include "TESFullName.h"
#include "TESTexture.h"
// No size, allocation, construction, or member-layout use in this unit.
class TESWorldSpace : public TESForm, public TESFullName, public TESTexture
{
};
class TESRegion;
struct BaseRegionData;
class TESRegionData
{
  public:
    virtual ~TESRegionData();
    virtual void Save();
    virtual bool ApplyEntry(BaseRegionData* data);
    virtual void Initialize(TESRegion* region);
};
#endif
