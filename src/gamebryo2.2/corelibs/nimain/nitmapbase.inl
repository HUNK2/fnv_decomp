
#include "nitmapbase_decls.h"

template<>
// @fnv 0x00a53c30
bool NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiShader*>::GetAt(
    const char* key, NiShader*& data)
{
    unsigned int index = Hash(key);
    NiTMapItem<const char*, NiShader*>* item = m_ppkHashTable[index];
    while (item)
    {
        if (Equal(key, item->m_key))
        {
            data = item->m_val;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

template<>
// @fnv 0x00b63170
bool NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, bool>::GetAt(
    NiObject* key, bool& data)
{
    unsigned int index = Hash(key);
    NiTMapItem<NiObject*, bool>* item = m_ppkHashTable[index];
    while (item)
    {
        if (Equal(key, item->m_key))
        {
            data = item->m_val;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

template<>
// @fnv 0x00a5d320
void NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, bool>::SetAt(
    NiObject* key, bool data)
{
    unsigned int index = Hash(key);
    NiTMapItem<NiObject*, bool>* item = m_ppkHashTable[index];
    while (item)
    {
        if (Equal(key, item->m_key))
        {
            item->m_val = data;
            return;
        }
        item = item->m_pkNext;
    }
    item = NewItem();
    FillEntry(item, key, data);
    item->m_pkNext = m_ppkHashTable[index];
    m_ppkHashTable[index] = item;
    m_kItemCount.m_uiCount++;
}

template<>
// @fnv 0x00e92760
bool NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiPointer<RefCountedNamedObject> >::GetAt(
    const char* key, NiPointer<RefCountedNamedObject>& data)
{
    unsigned int index = Hash(key);
    NiTMapItem<const char*, NiPointer<RefCountedNamedObject> >* item = m_ppkHashTable[index];
    while (item)
    {
        if (Equal(key, item->m_key))
        {
            data = item->m_val;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

template<>
// @fnv 0x00e91fd0
bool NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiShader*>::RemoveAt(
    const char* key)
{
    unsigned int index = Hash(key);
    NiTMapItem<const char*, NiShader*>* item = m_ppkHashTable[index];
    if (!item)
        return false;
    if (Equal(key, item->m_key))
    {
        m_ppkHashTable[index] = item->m_pkNext;
        Unk_004(item);
        Unk_006(item);
        m_kItemCount.m_uiCount--;
        return true;
    }

    NiTMapItem<const char*, NiShader*>* previous = item;
    item = item->m_pkNext;
    while (item)
    {
        if (Equal(key, item->m_key))
        {
            previous->m_pkNext = item->m_pkNext;
            Unk_004(item);
            Unk_006(item);
            m_kItemCount.m_uiCount--;
            return true;
        }
        previous = item;
        item = item->m_pkNext;
    }
    return false;
}


#pragma optimize("", off)

// @fnv 0x00404d30
bool NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord*> >, unsigned int, CombatThreatRecord*>::GetFirstPos()
{
    return count != 0;
}

// @fnv 0x00589000
NiTMapBase<NiTPointerAllocator<unsigned int>,int,TESObjectCELL*>::NiTMapBase(unsigned int size)
{
 InitArray(size);
 vtable = DAT_01031fec;
}

// @fnv 0x004701d0
NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned int,TESForm*>::NiTMapBase(unsigned int size, unsigned int flags)
{
 FUN_004705e0(size,flags);
 vtable = DAT_01019a3c;
}

// @fnv 0x00402d00
TESFullName::TESFullName() {}


// @fnv 0x00845690
NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord*> >, unsigned int, CombatThreatRecord*>*
NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord*> >, unsigned int, CombatThreatRecord*>::Destructor(unsigned int flags)
{
 FUN_008456c0();
 if (flags & 1) operator delete(this);
 return this;
}

// @fnv 0x006b7b30
unsigned int FUN_006b7b30(NavMeshInfo* info)
{
 TESObjectCELL* cell = info->GetInteriorCell();
 if (cell)
   return reinterpret_cast<unsigned int (__cdecl*)(TESObjectCELL*)>(PrepareScriptMessage)(cell);
 else
   return reinterpret_cast<unsigned int (__cdecl*)(TESObjectCELL*)>(PrepareScriptMessage)(info->cell);
}

// @fnv 0x00473210
void TESFile::SetCompileIndex(unsigned char index)
{
 flags = (static_cast<unsigned int>(index) << 24) | (flags & 0x00ffffff);
 compileIndex = index;
}

// @fnv 0x0043d410
NiUpdateData::NiUpdateData(float time,bool updateControllers,bool isMultiThreaded)
{
 this->time=time;
 this->updateControllers=updateControllers;
 this->isMultiThreaded=isMultiThreaded;
 flag6=false;
 flag7=false;
 flag8=false;
}

// @fnv 0x004b9ba0
void* BGSReconstructFormsInAllFilesMap::GetFirstPos()
{
 for (unsigned int i=0;i<hashSize;i++)
 {
  if(hashTable[i]) return hashTable[i];
 }
 return 0;
}

// @fnv 0x00843470
FormChangeMap::FormChangeMap() {}

