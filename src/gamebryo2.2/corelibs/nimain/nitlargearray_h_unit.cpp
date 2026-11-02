// gamebryo2.2/corelibs/nimain/nitlargearray_h_unit.cpp: free functions (1 function)

#include "nitlargearray.inl"

struct TESRegion;

struct BGSAcousticSpace
{
    void SetRegion(TESRegion*);
};

struct NiTLargeArray_TESTopicInfo
{
    void** m_ppVirtualMethodTable;
    unsigned int* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void SetSize(unsigned int index, unsigned int* value);
    TESTopicInfo* RemoveAt(unsigned int index);
    void Compact();
};

struct FUN_005ff560_shell
{
    TESTopicInfo* GetChildByIndex(unsigned int index);
    void RemoveChildAndRelinkNeighbors(unsigned int index);
};

// If the child array exists, links the next child's region to the previous child, then removes the child at index and compacts the array.
// @fnv 0x005ff560
void FUN_005ff560_shell::RemoveChildAndRelinkNeighbors(unsigned int index)
{
    if (*(void**)(this + 0x40))
    {
        TESTopicInfo* pNext = this->GetChildByIndex(index + 1);
        TESTopicInfo* pPrevVal = this->GetChildByIndex(index - 1);
        if (pNext)
            ((BGSAcousticSpace*)pNext)->SetRegion((TESRegion*)pPrevVal);
        ((NiTLargeArray_TESTopicInfo*)*(void**)(this + 0x40))->RemoveAt(index);
        ((NiTLargeArray_TESTopicInfo*)*(void**)(this + 0x40))->Compact();
    }
}
