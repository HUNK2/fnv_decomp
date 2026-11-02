
// gamebryo2.2/corelibs/nimain/nitpointerlistbase.cpp: free functions (3 functions)
#include "nitpointerlistbase.inl"

// Explicit instantiation selects the original optimized NiPointer consumer.
// @fnv 0x00e74d40
template void NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> >::RemoveAll();

// char* explicit-specialization members (declared in the .inl above).
// RemoveTail is defined in its own original TU and linked externally.
void NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>::RemoveAll()
{
    NiTListItem<char*>* item = this->m_pkHead;
    while (item)
    {
        NiTListItem<char*>* removed = item;
        item = item->m_pkNext;
        DeleteItem(removed);
    }
    this->m_kItemCount.m_uiCount = 0;
    this->m_pkHead = 0;
    this->m_pkTail = 0;
}

// @fnv 0x00b602d0
char* NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>::RemoveHead()
{
    NiTListItem<char*>* item = this->m_pkHead;
    NiTListItem<char*>* next = item->m_pkNext;
    this->m_pkHead = next;
    if (next)
        next->m_pkPrev = 0;
    else
        this->m_pkTail = 0;
    char* element = item->m_element;
    DeleteItem(item);
    --this->m_kItemCount.m_uiCount;
    return element;
}

// @fnv 0x00e7d7f0
char* NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>::RemovePos(void*& position)
{
    NiTListItem<char*>* item = static_cast<NiTListItem<char*>*>(position);
    if (item == this->m_pkHead)
    {
        position = item->m_pkNext;
        return RemoveHead();
    }
    if (item == this->m_pkTail)
    {
        position = 0;
        return RemoveTail();
    }
    NiTListItem<char*>* previous = item->m_pkPrev;
    NiTListItem<char*>* next = item->m_pkNext;
    position = next;
    if (previous)
        previous->m_pkNext = next;
    if (next)
        next->m_pkPrev = previous;
    char* element = item->m_element;
    DeleteItem(item);
    --this->m_kItemCount.m_uiCount;
    return element;
}

char* NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>::Remove(char*& element)
{
    NiTListItem<char*>* item = this->m_pkHead;
    while (item)
    {
        if (item->m_element == element)
            break;
        item = item->m_pkNext;
    }
    void* position = item;
    if (position)
        return RemovePos(position);
    return element;
}
