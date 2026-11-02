// fallout_shared/region system/tesregiondatagrass_decls.h: declares TESRegionData, TESRegionDataGrass
#ifndef TESREGIONDATAGRASS_DECLS_H
#define TESREGIONDATAGRASS_DECLS_H

class TESGrass;
template <class T> class BSSimpleList
{
  public:
    BSSimpleList();
    T m_item;
    BSSimpleList<T>* m_pkNext;
};
class TESRegionData
{
  public:
    TESRegionData();
    virtual ~TESRegionData();
    bool bOverride;
    bool m_bHasRegionData;
    unsigned char m_ucRegionPriority;
};
class TESRegionDataGrass : public TESRegionData
{
  public:
    TESRegionDataGrass();
    virtual ~TESRegionDataGrass();
    BSSimpleList<TESGrass*> kObjects;
};
#endif
