// fallout/misc/saveload/FormIDConverter.h: declares TESDataHandler, FormIDConverter
#ifndef FNV_BGSSAVELOADFORMIDMAP_H
#define FNV_BGSSAVELOADFORMIDMAP_H


// Map node layout shared by the NiT map family (pointer-value map variant).
template <class K, class V> class NiTMapItem
{
  public:
    NiTMapItem<K, V>* m_pkNext;
    K m_key;
    V m_val;
};

// Gamebryo pointer map: vtable, hash size, bucket table and the packed
template <class K, class V> class NiTPointerMap
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    NiTMapItem<K, V>** m_ppkHashTable;
    struct MapEntryCount
    {
        unsigned int m_uiCount;
    } m_kItemCount;

    NiTPointerMap(unsigned int uiHashSize);
    ~NiTPointerMap();
    bool GetAt(K key, V& result) const;
    void SetAt(K key, V value);
    void RemoveAll();
};

class TESDataHandler
{
  public:
    bool FormIDExists(unsigned int formID);
};

extern TESDataHandler* g_dataHandler;

// Save/load form-ID remapping table: forward map (formID -> save index),
// reverse map (save index -> formID) and the next index to hand out.
class FormIDConverter
{
  public:
    NiTPointerMap<unsigned int, unsigned int> m_kSourceToTargetFormIDMap;  // +0x0
    NiTPointerMap<unsigned int, unsigned int> m_kTargetToSourceFormIDMap;  // +0x10
    unsigned int m_uiFormIDCount;                                          // +0x20

    FormIDConverter(unsigned int uiHashSize);
    ~FormIDConverter();
    void Clear();
    unsigned int RegisterFormID(unsigned int formID);
};

typedef char bgsSaveLoadFormIDMapSizeAssert[(sizeof(FormIDConverter) == 36) ? 1 : -1];
typedef char bgsSaveLoadFormIDMapIndexToFormIDMapOffsetAssert
    [((int)&((FormIDConverter*)0)->m_kTargetToSourceFormIDMap == 0x10) ? 1 : -1];
typedef char
    bgsSaveLoadFormIDMapICurrentIndexOffsetAssert[((int)&((FormIDConverter*)0)->m_uiFormIDCount == 0x20) ? 1 : -1];
typedef char
    niTPointerMapUnsignedUnsignedSizeAssert[(sizeof(NiTPointerMap<unsigned int, unsigned int>) == 16) ? 1 : -1];

#endif
