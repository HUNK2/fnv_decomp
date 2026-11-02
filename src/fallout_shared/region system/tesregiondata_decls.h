// fallout_shared/region system/tesregiondata_decls.h: declares TESForm, RegionDataEntry, TESRegionData
#ifndef TESREGIONDATA_DECLS_H
#define TESREGIONDATA_DECLS_H

enum ENUM_FORM_ID
{
    ENUM_FORM_ID_ZERO = 0
};
class TESForm
{
  public:
    void SetFormType(ENUM_FORM_ID);
};
class RegionDataEntry
{
  public:
    unsigned int m_eRegionDataId;
    bool bOverride;
    unsigned char m_ucRegionPriority;
    unsigned char padding[2];
};
class TESRegionData
{
  public:
    void** m_ppVirtualMethodTable;
    bool bOverride;
    bool m_bHasRegionData;
    unsigned char m_ucRegionPriority;
    unsigned char padding;
    bool ApplyEntry(RegionDataEntry* data);
    bool SetPriority(unsigned char priority);
};
#endif
