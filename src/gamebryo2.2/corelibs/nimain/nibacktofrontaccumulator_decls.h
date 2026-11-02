// gamebryo2.2/corelibs/nimain/nibacktofrontaccumulator_decls.h: declares NiObject, NiBackToFrontListItem, NiBackToFrontGeometryList, NiBackToFrontAccumulator
#ifndef FNV_NIBACKTOFRONTACCUMULATOR_DECLS_H
#define FNV_NIBACKTOFRONTACCUMULATOR_DECLS_H


class RecursiveSpinLock
{
  public:
    void Lock(const char*);
    unsigned int m_uiLock;
    unsigned int m_uiCount;
};

class __declspec(novtable) NiObject
{
  public:
    NiObject() throw();
    virtual void FnvLayoutAnchor()
    {}
    unsigned int m_uiRefCount;
};

template <class T> class PoolAllocatorBase
{
  public:
    struct LinkedListEntry
    {
        LinkedListEntry* m_pkNext;
    };

    static RecursiveSpinLock ms_kPoolState;
    static LinkedListEntry* ms_pFreeList;
};

struct NiBackToFrontListItem
{
    NiBackToFrontListItem* m_pkNext;
    NiBackToFrontListItem* m_pkPrevious;
    void* m_pInventoryEntryData;
};

struct NiBackToFrontGeometryList
{
    NiBackToFrontListItem* m_pkHead;
    NiBackToFrontListItem* m_pkTail;
    unsigned int m_uiCount;
    void FUN_00b71300();
};

class __declspec(novtable) NiBackToFrontAccumulator : public NiObject
{
  public:
    NiBackToFrontAccumulator();
    virtual ~NiBackToFrontAccumulator();
    void FUN_00a5d3d0();
    void QuickSort(int, int);
    float GetPivotValue(int, int);

    // NiObject contributes the vfptr and reference count at offsets 0 and 4.
    void* m_pkAccumulationCamera;
    NiBackToFrontGeometryList m_kUnsortedGeometryList;
    NiBackToFrontGeometryList* m_pkGeometryList;
    int m_iGeometryCount;
    int m_iGeometryCapacity;
    void** m_ppGeometries;
    float* m_pfGeometrySortValues;
    int m_iCurrentItem;
};

extern void NiFree(void*);

#endif
