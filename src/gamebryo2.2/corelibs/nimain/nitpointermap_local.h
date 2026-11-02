#ifndef FNV_NITPOINTERMAP_LOCAL_H
#define FNV_NITPOINTERMAP_LOCAL_H

class ChangeData;

template <class K, class V> class NiTMapItem
{
  public:
    NiTMapItem<K, V>* m_pkNext;
    NiTMapItem<K, V>* m_pkPrev;
    V m_val;
};

template <class K, class V> class NiTPointerMap
{
  public:
    NiTMapItem<K, V>* m_pkFirstItem;
    NiTMapItem<K, V>* m_pkLastItem;
    unsigned int m_uiCount;

    void NewItem(NiTMapItem<K, V>* pkItem);
};

#endif
