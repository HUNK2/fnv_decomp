// bssystem/filefinder_filefinder_decls.h: declares NiFile, FileFinder, MemoryManager, BSFile, ArchiveManager
#ifndef FNV_FILEFINDER_FILEFINDER_DECLS_H
#define FNV_FILEFINDER_FILEFINDER_DECLS_H

class NiFile
{
  public:
    enum OpenMode
    {
        READ_ONLY,
        WRITE_ONLY,
        APPEND_ONLY
    };
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual bool Open(bool, bool);
};

class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        NOTFOUND = 0,
        HARDDRIVE = 1,
        ARCHIVE = 2,
        CACHE = 3,
        PC = 4,
        DVD = 5,
        DVDTOHD = 6
    };
    static NiFile* GetFile(const char*, NiFile::OpenMode, unsigned int, unsigned int);
    static FILE_LOCATION __cdecl Exist(const char*, char*, unsigned int, unsigned int);
    FILE_LOCATION GetFileLocation(char*, char*, unsigned int, unsigned int);
    unsigned int FUN_00afe220(char*, unsigned int, unsigned int);
};
extern "C" FileFinder* g_fileFinder;
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);

class MemoryManager
{
  public:
    void* Allocate(unsigned int);
};
extern MemoryManager g_memoryManager;
class BSFile : public NiFile
{
  public:
    char storage[340];
    BSFile(const char*, int, unsigned int, bool);
    static __forceinline void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void*);
};
class ArchiveManager
{
  public:
    static NiFile* GetFile(const char*, unsigned int, unsigned int);
};

#endif
