// gamebryo2.2/corelibs/nimain/bstexturepalette_decls.h: declares NiFixedString, NiTexture, FileNameHash, ArchiveManager, TextureFileEntrySetter and more
#ifndef FNV_BSTEXTUREPALETTE_DECLS_H
#define FNV_BSTEXTUREPALETTE_DECLS_H

#include "layout_support.h"

class NiFixedString
{
  public:
    char* m_kHandle;
};

class BSFileEntry;
class NiTexture
{
  public:
    virtual ~NiTexture();
    virtual void DeleteThis();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual unsigned int GetRenderedWidth();
    virtual unsigned int GetRenderedHeight();
    virtual const NiFixedString& GetPath() const;
};

class FileNameHash
{
  public:
    unsigned char cLast, cSecondToLast, cLength, cFirst;
    unsigned int uiCRC;
    static void __cdecl CreateDirectoryAndFileHashes(const char*, FileNameHash&, FileNameHash&);
};
FNV_STATIC_ASSERT(sizeof(FileNameHash) == 8);

// Archive type one is the texture archive group.
enum ArchiveType
{
    ARCHIVE_TYPE_TEXTURES = 1
};
class ArchiveManager
{
  public:
    static BSFileEntry* __cdecl FindFileEntry(ArchiveType, FileNameHash&, FileNameHash&, const char*);
};

class TextureFileEntrySetter
{
  public:
    static BSFileEntry* __cdecl FindEntryForTexture(const NiTexture*);
    static void __cdecl SetTexture(NiTexture*, const BSFileEntry*);
};
bool __cdecl CleanPath(const char*, char*, unsigned int);

class TextureCacheNode
{
  public:
    NiTexture* spTexture;
    BSFileEntry* m_pFileEntry;
    TextureCacheNode* pNext;
    unsigned short m_usTextureSizeLevel;
    short m_sTextureCacheValue;
};
FNV_STATIC_ASSERT(sizeof(TextureCacheNode) == 16);
class TextureCacheMap
{
  public:
    TextureCacheNode* pElement[713];
    unsigned int iCount;
    TextureCacheNode* FindOrInsertTexture(NiTexture*);
};
FNV_STATIC_ASSERT(sizeof(TextureCacheMap) == 0xb28);
class BSFileEntryMap
{
  public:
    void SetAt(const BSFileEntry*, TextureCacheNode*);
};
class RecursiveSpinLock
{
  public:
    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
    void Lock(const char*);
};
extern RecursiveSpinLock g_spinLock;
extern TextureCacheMap* DAT_011f4464;
extern BSFileEntryMap* DAT_011f4468;
unsigned int __cdecl GetTextureSizeLevel(NiTexture*);
#endif
