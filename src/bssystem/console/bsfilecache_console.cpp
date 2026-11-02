
//
// builds the platform cache object once on first use behind the usual
// one-time flag, registers it for destruction, and hands back the shared
// BSFileCache reference the engine caches files through.
//
// Covered PC function: 0x00AFF100 (116 bytes).

#include "layout_support.h"

class FileCache;

// Int-sized enums from the original interface; only the names and widths
// are recovered, the enumerators are not needed by this unit.
typedef int DVD_LAYER;
typedef int FILE_CACHE_STATE;

// Common file-cache interface shared by every platform specialization.
class BSFileCache
{
  public:
    virtual ~BSFileCache();

    // Builds the platform cache object once and returns the shared one.
    static BSFileCache& GetRandomGenerator();

    static char* ms_pcCachePath;
    static const char* sEssentialFileCacheList;
    static const char* sUnessentialFileCacheList;

    FileCache* m_pActiveFileCache;                       // +0x04
    unsigned int m_uiCacheEntryCount;                    // +0x08
    unsigned int m_uiCachedBytes;                        // +0x0C
    unsigned int m_uiCacheLimit;                         // +0x10
    unsigned int m_uiCacheByteCount;                     // +0x14
    unsigned int m_uiCacheCapacity;                      // +0x18
    unsigned int m_uiCacheRequestCount;                  // +0x1C
    unsigned int m_uiCacheFlags;                         // +0x20
    unsigned int m_uiCacheIndex;                         // +0x24
    int m_iCacheEntryIndex;                              // +0x28
    unsigned int m_uiReferenceCount;                     // +0x2C
    int m_iCacheCount;                                   // +0x30
    int m_iFileSize;                                     // +0x34
    int m_iFilePosition;                                 // +0x38
    int m_iCachePosition;                                // +0x3C
    DVD_LAYER m_eDVDLayer;                               // +0x40
    bool m_bCacheEnabled;                                // +0x44
    bool m_bCacheReadPending;                            // +0x45
    bool m_bCacheWritePending;                           // +0x46
    bool m_bCacheInitialized;                            // +0x47
    unsigned int m_uiCacheOffset;                        // +0x48
    unsigned int m_uiCacheBufferCount;                   // +0x4C
    BSSimpleArray<FileCache*, 1024>* m_pFileCacheArray;  // +0x50
    void(__cdecl* m_pfnCacheProgress)(const char*);      // +0x54
    void(__cdecl* m_pfnCacheStatus)(bool);               // +0x58
    volatile FILE_CACHE_STATE m_eCacheState;             // +0x5C
    void* m_pCacheSyncObject;                            // +0x60
};
FNV_STATIC_ASSERT(sizeof(BSFileCache) == 0x64);

// PC specialization of the file cache; it overrides the interface and
// carries no extra state of its own.
class BSWin32FileCache : public BSFileCache
{
  public:
    BSWin32FileCache();
    virtual ~BSWin32FileCache();
};

// Returns a reference to the function-local static BSWin32FileCache instance.
// @fnv 0x00aff100
BSFileCache& BSFileCache::GetRandomGenerator()
{
    static BSWin32FileCache s_fileCache;
    return s_fileCache;
}
