// gamebryo2.2/corelibs/nimain/nialphaaccumulator_decls.h: declares NiAccumulator, NiBackToFrontAccumulator, ItemList, Allocator, NiAlphaAccumulator
#ifndef FNV_NIALPHAACCUMULATOR_DECLS_H
#define FNV_NIALPHAACCUMULATOR_DECLS_H

extern "C" unsigned int kVtbl_NiBackToFrontAccumulator;

struct ItemListNode;

class NiAccumulator
{
  public:
    unsigned int m_layout0;
    unsigned int m_layout4;
    void* m_pkAccumulationCamera;
};

class NiBackToFrontAccumulator : public NiAccumulator
{
  public:
    NiBackToFrontAccumulator();

    struct ItemList
    {
        ItemListNode* volatile m_pkHead;
        ItemListNode* volatile m_pkTail;
        struct Allocator
        {
            volatile unsigned int m_uiCount;
        } m_kItemCount;
    } m_kUnsortedGeometryList;
    ItemList* volatile m_pkGeometryList;
    volatile int m_iGeometryCount;
    volatile int m_iGeometryCapacity;
    void** volatile m_ppGeometries;
    float* volatile m_pfGeometrySortValues;
    volatile int m_iCurrentItem;
};

class NiAlphaAccumulator : public NiBackToFrontAccumulator
{
  public:
    NiAlphaAccumulator();
    bool m_bSkipObjectsWithFlag13;
    bool m_bSkipObjectsWithFlag14;
    bool m_bInterface;
    unsigned char m_padding33;
};
#endif
