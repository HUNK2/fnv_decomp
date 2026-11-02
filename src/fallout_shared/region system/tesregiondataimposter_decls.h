// fallout_shared/region system/tesregiondataimposter_decls.h: declares TESRegionDataImposter, TESFile, TESForm, TESObjectREFR
#ifndef FNV_TESREGIONDATAIMPOSTER_DECLS_H
#define FNV_TESREGIONDATAIMPOSTER_DECLS_H


class TESFile;
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
    T& GetItem();
    BSSimpleList<T>* GetNext();
    void SetItem(const T& item);
    void RemoveHead();
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
    bool ReadRegionData(TESFile* file);
    void InitItem(TESForm* form);
};
#pragma pack(pop)

class TESFile
{
  public:
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void* data, unsigned int size);
    bool IsEndianConversionRequired();
};

class TESForm
{
  public:
    virtual ~TESForm();
    TESFile* GetFile(int index);
    static void RemapFormIDForFile(unsigned int& formID, TESFile* file);
    static TESForm* GetFormByID(unsigned int formID);
};
class TESObjectREFR : public TESForm
{
};

template <int N> struct EndianSizeTag
{
};
void BSEndian(unsigned int* value, EndianSizeTag<4>);
void* __cdecl operator new[](unsigned int size);
void __cdecl operator delete[](void* data);

#endif
