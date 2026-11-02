
#include "bsmap_decls.h"

template <>
// @fnv 0x00a1e380
bool BSMapBase<unsigned long, ScrapHeapBuffer*>::GetAt(unsigned long key, ScrapHeapBuffer*& data)
{
    unsigned int index = this->Hash(key);
    BSMapEntry<unsigned long, ScrapHeapBuffer*>* item =
        ((BSMapEntry<unsigned long, ScrapHeapBuffer*>**)this->m_ppkHashTable)[index];
    while (item)
    {
        if (this->Equal(key, item->m_key))
        {
            data = item->m_data;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

template <>
// @fnv 0x00aa4860
void BSMapBase<void*, PointerMapValue*>::SetAt(void* key, PointerMapValue* data)
{
    unsigned int index = this->Hash((unsigned int)key);
    BSMapEntry<void*, PointerMapValue*>* item =
        ((BSMapEntry<void*, PointerMapValue*>**)this->m_ppkHashTable)[index];
    unsigned int count = 0;
    while (item)
    {
        ++count;
        if (this->Equal((unsigned int)key, (unsigned int)item->m_key))
        {
            this->UnlinkEntry(item);
            this->FillEntry(item, (unsigned int)key, data);
            return;
        }
        item = item->m_pkNext;
    }
    item = (BSMapEntry<void*, PointerMapValue*>*)this->AllocateEntry();
    this->FillEntry(item, (unsigned int)key, data);
    item->m_pkNext = ((BSMapEntry<void*, PointerMapValue*>**)this->m_ppkHashTable)[index];
    ((BSMapEntry<void*, PointerMapValue*>**)this->m_ppkHashTable)[index] = item;
    ++this->m_uiCount;
}

template <>
// @fnv 0x006f9a80
void BSMapBase<unsigned int, BGSDistantTreeBlock::InstanceData*>::SetAt(
    unsigned int key, BGSDistantTreeBlock::InstanceData* data)
{
    unsigned int index = this->Hash(key);
    BSMapEntry<unsigned int, BGSDistantTreeBlock::InstanceData*>* item =
        ((BSMapEntry<unsigned int, BGSDistantTreeBlock::InstanceData*>**)this->m_ppkHashTable)[index];
    unsigned int count = 0;
    while (item)
    {
        ++count;
        if (this->Equal(key, item->m_key))
        {
            this->UnlinkEntry(item);
            this->FillEntry(item, key, data);
            return;
        }
        item = item->m_pkNext;
    }
    item = (BSMapEntry<unsigned int, BGSDistantTreeBlock::InstanceData*>*)this->AllocateEntry();
    this->FillEntry(item, key, data);
    item->m_pkNext =
        ((BSMapEntry<unsigned int, BGSDistantTreeBlock::InstanceData*>**)this->m_ppkHashTable)[index];
    ((BSMapEntry<unsigned int, BGSDistantTreeBlock::InstanceData*>**)this->m_ppkHashTable)[index] = item;
    ++this->m_uiCount;
}

template <>
// @fnv 0x0048b460
BSMapBase<int, DistantTreeTextureInfo*>::~BSMapBase()
{
    this->RemoveAll();
}
