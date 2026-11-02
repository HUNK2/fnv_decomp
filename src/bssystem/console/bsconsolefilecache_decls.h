// bssystem/console/bsconsolefilecache_decls.h: declares NiTPrimitiveArray_unsigned_int_, FaceGenData, BSFileCache
#ifndef FNV_BSCONSOLEFILECACHE_DECLS_H
#define FNV_BSCONSOLEFILECACHE_DECLS_H


class TESHair;
class TESEyes;
class TESModel;
class TESTexture;
class NiTexture;
class BGSHeadPart;
enum SEX
{
    SEX_MALE,
    SEX_FEMALE
};
enum BS_FACEGEN_LOD
{
    BS_FACEGEN_LOD_NONE = -1
};

namespace oldstd {
template <class T> struct vector
{
    unsigned int unk00;
    void* unk04;
    unsigned int unk08;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
};
}

template <class T> struct FaceGenMatrix
{
    FaceGenMatrix();
    ~FaceGenMatrix();
    oldstd::vector<T> kData;
    unsigned int uiRowCount;
    unsigned int uiColCount;
};

template <class T> class NiTPrimitiveArray
{
  public:
    NiTPrimitiveArray(unsigned int initialSize = 0, unsigned int growBy = 1);
    virtual ~NiTPrimitiveArray();
    T* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
};

template <class T> class NiTObjectArray
{
  public:
    NiTObjectArray(unsigned int initialSize = 0, unsigned int growBy = 1);
    virtual ~NiTObjectArray();
    T* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
};

template <class T> class BSSimpleList
{
  public:
    BSSimpleList();
    ~BSSimpleList();
    T m_item;
    BSSimpleList<T>* m_pkNext;
};

// The canonical source binds the folded pointer-array RemoveAll to this name.
class NiTPrimitiveArray_unsigned_int_
{
  public:
    void RemoveAll();
    void** m_ppVirtualMethodTable;
    unsigned int* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
};

class FaceGenData
{
  public:
    FaceGenData();
    ~FaceGenData();
    FaceGenMatrix<float> m_kFaceGenCoordinates[2][2];
    TESHair* m_pHair;
    int iHairColor;
    float m_fHairLength;
    TESEyes* pEyes;
    SEX m_eSex;
    NiTPrimitiveArray<TESModel*> m_kModelObjectsItem;
    NiTPrimitiveArray<TESTexture*> pTexture;
    NiTPrimitiveArray<const char*> m_kTexturePaths;
    NiTObjectArray<NiPointer<NiTexture> > m_kFaceGenTextures;
    bool bFaceGenTexturing;
    bool m_bFaceGenDataValid;
    TESModel* m_pHeadModel;
    TESModel* m_pFaceGenModel;
    BS_FACEGEN_LOD m_eFaceGenLOD;
    BSSimpleList<BGSHeadPart*> Accessories;
};

class FileCache;
enum DVD_LAYER
{
    DVD_LAYER_FRONT,
    DVD_LAYER_BACK
};
enum FILE_CACHE_STATE
{
    FILE_CACHING_DISABLED,
    FILE_CACHING_IN_PROGRESS,
    FILE_CACHING_PAUSED,
    FILE_CACHING_FORCE_PAUSED,
    FILE_CACHING_FINISHED
};

// Same PC interface prefix as canonical bssystem/bsfilecache.h.
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

class BSWin32FileCache : public BSFileCache
{
  public:
    BSWin32FileCache();
    virtual ~BSWin32FileCache();
};

#endif
