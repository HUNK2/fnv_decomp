// fallout/misc/saveload/bgssaveloadreferencesmap_decls.h: declares BGSCellNumericIDArrayMap, TESForm, TESWorldSpace, TESObjectCELL, BGSSaveLoadReferencesMap
#ifndef FNV_BGSSAVELOADREFERENCESMAP_DECLS_H
#define FNV_BGSSAVELOADREFERENCESMAP_DECLS_H


// Private declarations for the map and array specializations used by this unit.
template <class K, class V> class NiTMapItem
{
  public:
    NiTMapItem<K, V>* m_pkNext;
    K m_key;
    V m_val;
};

template <class T> class DFALL
{
};

template <class Allocator, class K, class V> class NiTMapBase
{
  public:
    virtual ~NiTMapBase();
    unsigned int m_uiHashSize;
    NiTMapItem<K, V>** m_ppkHashTable;
    struct MapEntryCount : public Allocator
    {
        unsigned int m_uiCount;
    } m_kItemCount;

    void* GetFirstPos();
    void GetNext(void*& position, K& key, V& value);
    bool GetAt(K key, V& result);
    bool RemoveAt(K key);
    void RemoveAll();
};

template <class K, class V> class NiTMap : public NiTMapBase<DFALL<NiTMapItem<K, V> >, K, V>
{
};

template <class K, class V> class NiTPointerMap : public NiTMapBase<DFALL<NiTMapItem<K, V> >, K, V>
{
  public:
    void RemoveAll();
    bool GetAt(K key, V& result) const;
};

template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    virtual ~BSSimpleArray();
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    unsigned int GetSize();
    T& GetAt(int index);
};

class BGSCellNumericIDArrayMap : public NiTMap<unsigned int, BSSimpleArray<unsigned int, 1024>*>
{
  public:
    virtual ~BGSCellNumericIDArrayMap();
    void Clear();
};

// API-only declarations: no cell, form, or worldspace layout is used here.
class TESForm
{
  public:
    unsigned int GetFormID();
};

class TESWorldSpace : public TESForm
{
  public:
    static int BuildCellKey(short x, short y);
};

class TESObjectCELL : public TESForm
{
  public:
    bool IsCellInterior() const;
    int GetCellGridX();
    int GetCellGridY();
    TESWorldSpace* GetParentWorldSpace();
};

class BGSReconstructFormsInAllFilesMap;

class BGSSaveLoadReferencesMap
{
  public:
    NiTPointerMap<unsigned int, unsigned int> m_kReferenceIDMap;
    BGSCellNumericIDArrayMap m_kCellReferences;
    NiTPointerMap<unsigned int, BGSCellNumericIDArrayMap*> m_kWorldspaceCellReferenceMaps;

    void Clear();
    void LoadCellReferences(TESObjectCELL* cell, BGSReconstructFormsInAllFilesMap* forms);
    void ReconstructFormID(unsigned int id, BGSReconstructFormsInAllFilesMap* forms);
};

typedef char bgssaveloadreferencesmap_cell_map_size[(sizeof(BGSCellNumericIDArrayMap) == 16) ? 1 : -1];
typedef char bgssaveloadreferencesmap_references_size[(sizeof(BGSSaveLoadReferencesMap) == 48) ? 1 : -1];

#endif
