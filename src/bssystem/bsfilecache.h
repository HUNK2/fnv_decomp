// bssystem/bsfilecache.h: declares BSFileCache
#ifndef FNV_BSFILECACHE_H
#define FNV_BSFILECACHE_H


class FileCache;

enum DVD_LAYER
{
    DVD_LAYER_FRONT = 0,
    DVD_LAYER_BACK = 1
};

enum FILE_CACHE_STATE
{
    FILE_CACHING_DISABLED = 0,
    FILE_CACHING_IN_PROGRESS = 1,
    FILE_CACHING_PAUSED = 2,
    FILE_CACHING_FORCE_PAUSED = 3,
    FILE_CACHING_FINISHED = 4
};

#pragma pack(push, 4)
class BSFileCache
{
  public:
    BSFileCache();
    virtual ~BSFileCache();

    FileCache* m_pActiveFileCache;
    unsigned int m_uiCacheEntryCount;
    unsigned int m_uiCachedBytes;
    unsigned int m_uiCacheLimit;
    unsigned int m_uiCacheByteCount;
    unsigned int m_uiCacheCapacity;
    unsigned int m_uiCacheRequestCount;
    unsigned int m_uiCacheFlags;
    unsigned int m_uiCacheIndex;
    int m_iCacheEntryIndex;
    unsigned int m_uiReferenceCount;
    int m_iCacheCount;
    int m_iFileSize;
    int m_iFilePosition;
    int m_iCachePosition;
    DVD_LAYER m_eDVDLayer;
    bool m_bCacheEnabled;
    bool m_bCacheReadPending;
    bool m_bCacheWritePending;
    bool m_bCacheInitialized;
    unsigned int m_uiCacheOffset;
    unsigned int m_uiCacheBufferCount;
    void* m_pFileCacheArray;
    void* m_pfnCacheProgress;
    void* m_pfnCacheStatus;
    volatile FILE_CACHE_STATE m_eCacheState;
    void* m_pCacheSyncObject;
};
#pragma pack(pop)

#endif
