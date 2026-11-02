// gamebryo2.2/corelibs/nimain/bstexturepalette.cpp: TextureFileEntrySetter, TexMap (6 functions)

#include "bstexturepalette_decls.h"

#pragma optimize("", off)

// Builds an archive key from the texture's path and hashes, then looks up the matching BSFileEntry in the textures archive.
// @fnv 0x00c5d560
BSFileEntry* __cdecl TextureFileEntrySetter::FindEntryForTexture(const NiTexture* texture)
{
    struct ArchiveKey
    {
        FileNameHash directoryHash;
        const char* texturePath;
        FileNameHash fileHash;
    } archiveKey;
    char path[260];
    {
        struct TextureEntryResolution
        {
            const NiFixedString* name;
            const char* handle;
            BSFileEntry* entry;
        } lookupResult;
        lookupResult.name = &texture->GetPath();
        lookupResult.handle = lookupResult.name->m_kHandle;
        archiveKey.texturePath = lookupResult.handle;
        CleanPath(archiveKey.texturePath, path, sizeof(path));
        FileNameHash::CreateDirectoryAndFileHashes(path, archiveKey.directoryHash, archiveKey.fileHash);
        lookupResult.entry =
            ArchiveManager::FindFileEntry(ARCHIVE_TYPE_TEXTURES, archiveKey.directoryHash, archiveKey.fileHash, path);
        return lookupResult.entry;
    }
}

#pragma optimize("", on)

// Locks the spin lock, looks up the texture's priority bucket, stores the priority on the item and registers the file entry if the item has none.
// @fnv 0x00a61c50
void __cdecl TextureFileEntrySetter::SetTexture(NiTexture* texture, const BSFileEntry* entry)
{
    if (DAT_011f4468)
    {
        g_spinLock.Lock(0);
        unsigned int priority = GetTextureSizeLevel(texture);
        TextureCacheNode* item = DAT_011f4464[priority].FindOrInsertTexture(texture);
        item->m_usTextureSizeLevel = (unsigned short)priority;
        if (!item->m_pFileEntry)
        {
            if (!entry)
                entry = FindEntryForTexture(texture);
            if (entry)
                DAT_011f4468->SetAt(entry, item);
        }
        if (--g_spinLock.m_uiRecursionCount == 0)
            g_spinLock.m_uiOwningThreadID = 0;
    }
}

struct FUN_00a61e60_ent
{
    unsigned int pad0;
    void* pad4;
    unsigned char pad8[4];
    unsigned short w;
};
struct FUN_00a61670_stub
{
    void RemoveByKey(void* p);
};
struct FUN_00a61890_stub
{
    void RemoveNode(void* p);
};
void* __cdecl FindNodeByObject(const void* p);
extern int DAT_011f4484;
// @fnv 0x00a61f30
bool FUN_00a61f30(const void* apTexture)
{
    bool bres = false;
    if (DAT_011f4468)
    {
        g_spinLock.Lock(0);
        FUN_00a61e60_ent* pitem = (FUN_00a61e60_ent*)FindNodeByObject(apTexture);
        if (pitem)
        {
            if (pitem->pad4)
                ((FUN_00a61670_stub*)DAT_011f4468)->RemoveByKey(pitem->pad4);
            ((FUN_00a61890_stub*)((char*)DAT_011f4464 + pitem->w * 0xb28))->RemoveNode(pitem);
            bres = true;
        }
        if (--DAT_011f4484 == 0)
            g_spinLock.m_uiOwningThreadID = 0;
    }
    return bres;
}

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;

unsigned int __cdecl GetPathHash(const char*, bool);
unsigned int __cdecl FUN_00a61530(const char*);
bool __cdecl FUN_00a614d0(const char*, const char*);

struct NiTexture_VF
{
    virtual void _v01();
    virtual void _v02();
    virtual void _v03();
    virtual void _v04();
    virtual void _v05();
    virtual void _v06();
    virtual void _v07();
    virtual void _v08();
    virtual void _v09();
    virtual void _v0a();
    virtual void _v0b();
    virtual void _v0c();
    virtual void _v0d();
    virtual void _v0e();
    virtual void _v0f();
    virtual void _v10();
    virtual void _v11();
    virtual void _v12();
    virtual void _v13();
    virtual void _v14();
    virtual void _v15();
    virtual void _v16();
    virtual void _v17();
    virtual void _v18();
    virtual void _v19();
    virtual void _v1a();
    virtual void _v1b();
    virtual void _v1c();
    virtual void _v1d();
    virtual void _v1e();
    virtual void _v1f();
    virtual void _v20();
    virtual void _v21();
    virtual void _v22();
    virtual void _v23();
    virtual void _v24();
    virtual void _v25();
    virtual void _v26();
    virtual void _v27();
    virtual const char** GetTextureResourceName();
};

struct BSTexMapItem_StandIn
{
    NiTexture* spTexture;
    void* field_4;
    TextureCacheNode* pNext;
    short field_c;
    short offset;

    void* operator new(size_t size)
    {
        return g_memoryManager.Allocate(size);
    }

    BSTexMapItem_StandIn(NiTexture* tex, TextureCacheNode* next)
    {
        spTexture = tex;
        InterlockedIncrement((volatile long*)((char*)tex + 4));
        field_4 = 0;
        pNext = next;
        field_c = 0;
        offset = 0;
    }
};

struct FUN_00a617c0_shell : public TextureFileEntrySetter
{
    TextureCacheNode* FindOrInsertTexture(NiTexture* apTex);
};

// Looks up a texture by its path in a hash bucket, returning the matching item or inserting a new one and incrementing the count.
// @fnv 0x00a617c0
TextureCacheNode* FUN_00a617c0_shell::FindOrInsertTexture(NiTexture* apTex)
{
    const char* path = *reinterpret_cast<NiTexture_VF*>(apTex)->GetTextureResourceName();
    unsigned int offset = GetPathHash(path, true);
    path += offset;
    unsigned int hash = FUN_00a61530(path);

    for (TextureCacheNode* item = reinterpret_cast<TextureCacheNode**>(this)[hash]; item; item = item->pNext)
    {
        const char* otherPath = *reinterpret_cast<NiTexture_VF*>(item->spTexture)->GetTextureResourceName() +
                                *reinterpret_cast<short*>((char*)item + 0xe);
        if (FUN_00a614d0(path, otherPath))
            return item;
    }

    BSTexMapItem_StandIn* pitem = new BSTexMapItem_StandIn(apTex, reinterpret_cast<TextureCacheNode**>(this)[hash]);
    pitem->offset = (short)offset;
    reinterpret_cast<TextureCacheNode**>(this)[hash] = reinterpret_cast<TextureCacheNode*>(pitem);
    (*reinterpret_cast<int*>((char*)this + 0xb24))++;
    return reinterpret_cast<TextureCacheNode*>(pitem);
}

struct S_00a61b90_Map : TextureCacheMap
{
    bool FindShaderByHash(unsigned int hash, const char* path, NiTexture** ppTex);
};

// Locks the spin lock, hashes the path suffix, releases any existing texture in ppTex, and probes up to 7 map slots for a matching texture.
// @fnv 0x00a61b90
bool __cdecl FindTextureByPath(const char* path, NiTexture** ppTex)
{
    bool found = false;
    if (DAT_011f4468 != 0)
    {
        g_spinLock.Lock(0);
        unsigned int offset = GetPathHash(path, true);
        const char* name = path + offset;
        unsigned int hash = FUN_00a61530(path + offset);
        NiTexture* pOldTexture = *ppTex;
        if (pOldTexture)
        {
            if (InterlockedDecrement((volatile long*)((char*)pOldTexture + 4)) == 0)
                pOldTexture->DeleteThis();
            *ppTex = 0;
        }
        int iSlot = 7;
        do
        {
            if (iSlot-- == 0)
                break;
            found = static_cast<S_00a61b90_Map*>(DAT_011f4464 + iSlot)->FindShaderByHash(hash, name, ppTex);
        } while (!found);
        if (--g_spinLock.m_uiRecursionCount == 0)
            g_spinLock.m_uiOwningThreadID = 0;
    }
    return found;
}

struct TexRefObject
{
    virtual ~TexRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
};
struct TexMapIter
{
    TextureCacheNode* pItem;
    unsigned int uiBucket;
    unsigned int uiMap;
};
struct TexPtr
{
    TexRefObject* m_pObject;
};
struct TexEntryMap
{
    void RemoveByKey(BSFileEntry* apEntry);
};
struct TexMap
{
    TextureCacheNode* pElement[713];
    unsigned int iCount;
    bool GetNext(TexMapIter& arIter, TexPtr& arTex);
    bool First(TexMapIter& it)
    {
        it.uiBucket = 0;
        it.pItem = 0;
        if (iCount)
        {
            for (unsigned int i = 0; i < 713; ++i)
            {
                if (pElement[i])
                {
                    it.uiBucket = i;
                    it.pItem = pElement[i];
                    it.uiMap = it.pItem->m_usTextureSizeLevel;
                    break;
                }
            }
        }
        return it.pItem != 0;
    }
    void RemoveNode(TextureCacheNode* apItem);
};
struct TexSpinLock
{
    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
    void Unlock()
    {
        if (--m_uiRecursionCount == 0)
            m_uiOwningThreadID = 0;
    }
};
extern unsigned char DAT_011f4461;
extern int DAT_011a95fc;
bool __cdecl FUN_00a616e0(TexMapIter& arIter);
__declspec(noinline) bool TexMap::GetNext(TexMapIter& it, TexPtr& tex)
{
    if (it.pItem)
    {
        TexRefObject* p = (TexRefObject*)it.pItem->spTexture;
        if (tex.m_pObject != p)
        {
            if (tex.m_pObject && !InterlockedDecrement(&tex.m_pObject->m_uiRefCount))
                tex.m_pObject->DeleteThis();
            tex.m_pObject = p;
            if (tex.m_pObject)
                InterlockedIncrement(&tex.m_pObject->m_uiRefCount);
        }
        it.pItem = it.pItem->pNext;
        if (!it.pItem)
        {
            while (++it.uiBucket < 713)
            {
                if (pElement[it.uiBucket])
                {
                    it.pItem = pElement[it.uiBucket];
                    break;
                }
            }
        }
    }
    return it.pItem != 0;
}

inline bool Next(TexMapIter& it, TexPtr& tex, bool cross = true)
{
    bool more = ((TexMap*)DAT_011f4464)[it.uiMap].GetNext(it, tex);
    if (!more && cross)
    {
        while (it.uiMap-- != 0)
        {
            more = ((TexMap*)DAT_011f4464)[it.uiMap].First(it);
            if (more)
                break;
        }
    }
    return more;
}
__declspec(noinline) bool __cdecl FUN_00a616e0(TexMapIter& it)
{
    unsigned int idx = 7;
    bool found;
    do
    {
        --idx;
        TexMap& m = ((TexMap*)DAT_011f4464)[idx];
        it.uiBucket = 0;
        it.pItem = 0;
        if (m.iCount)
        {
            for (unsigned int b = 0; b < 713; ++b)
            {
                if (m.pElement[b])
                {
                    it.uiBucket = b;
                    it.pItem = m.pElement[b];
                    it.uiMap = it.pItem->m_usTextureSizeLevel;
                    break;
                }
            }
        }
        found = it.pItem != 0;
    } while (!found && idx);
    return found;
}

// Iterates texture cache entries, removes entries whose object ref count is 2 up to a limit, then decrements the last object's ref count.
// @fnv 0x00a61cd0
void __cdecl FUN_00a61cd0()
{
    if (DAT_011f4468)
    {
        g_spinLock.Lock(0);
        int removed = 0;
        DAT_011f4461 = 0;
        TexMapIter it;
        if (FUN_00a616e0(it))
        {
            TexPtr tex = {0};
            bool more;
            TexRefObject* last;
            do
            {
                unsigned int oldmap = it.uiMap;
                TextureCacheNode* olditem = it.pItem;
                more = Next(it, tex);
                last = tex.m_pObject;
                if (last && last->m_uiRefCount == 2)
                {
                    if (olditem->m_pFileEntry)
                        ((TexEntryMap*)DAT_011f4468)->RemoveByKey(olditem->m_pFileEntry);
                    ((TexMap*)DAT_011f4464)[oldmap].RemoveNode(olditem);
                    ++removed;
                }
            } while (more && removed < DAT_011a95fc);
            if (last && InterlockedDecrement(&last->m_uiRefCount) == 0)
                last->DeleteThis();
        }
        ((TexSpinLock*)&g_spinLock)->Unlock();
    }
}
