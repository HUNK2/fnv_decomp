// fallout_shared/region system/tesregiondataimposter.h: declares TESRegionDataImposter
#ifndef FNV_TESREGIONDATAIMPOSTER_H
#define FNV_TESREGIONDATAIMPOSTER_H


class TESForm;
class TESObjectREFR;
class TESTopic;
class TESGrass;
class QuantityData;

template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    bool AddHead(T& item);
    void AddTail(T& item);
};

template <> class BSSimpleList<TESGrass*>
{
  public:
    void AddTail(TESGrass* const& item);
};

template <> class BSSimpleList<QuantityData*>
{
  public:
    void AddTail(QuantityData*& item);
};

class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*>* GetLinkToList();
};

#pragma pack(push, 4)
class TESRegionDataImposter
{
  public:
    unsigned char baseStorage[8];
    BSSimpleList<TESObjectREFR*> m_kImposterList;

    bool AddImposter(TESObjectREFR* ref);
};
#pragma pack(pop)

#endif
