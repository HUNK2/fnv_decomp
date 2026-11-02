// bsshader/tallgrassshaderproperty_decls.h: declares Entry, MemoryManager, TallGrassShaderProperty, TallGrassCacheData, TallGrassRefObject and more
#ifndef TALLGRASS_PRIVATE_H
#define TALLGRASS_PRIVATE_H

extern unsigned long DAT_011c9f6c;
extern unsigned int DAT_011f9ef4, DAT_011f9ef8;
class NiShader;
template <class A, class K, class V> class NiTMapBase;
class TallGrassShaderProperty;
template <class T> class NiTPointerAllocator
{
};
template <class A, class K, class V> class NiTMapBase
{
  public:
    struct Entry
    {
        Entry* next;
        K key;
        V value;
    };
    void* vtable;
    unsigned int hashSize;
    Entry** buckets;
    unsigned int count;
    void RemoveAll();
    unsigned int GetCount() const
    {
        return count;
    }
    __declspec(noalias) void GetNext(void*&, K&, V&);
    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < hashSize; ++i)
            if (buckets[i])
                return buckets[i];
        return 0;
    }
};
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiShader*> GrassMap;
class MemoryManager
{
  public:
    static MemoryManager& Instance();
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
inline MemoryManager& MemoryManager::Instance()
{
    return g_memoryManager;
}
inline void TallGrassFree(void* data)
{
    MemoryManager::Instance().Deallocate(data);
}
class TallGrassShaderProperty
{
  public:
    class TallGrassCacheData
    {
      public:
        unsigned char data[64];
        ~TallGrassCacheData();
        static void operator delete(void* p)
        {
            MemoryManager::Instance().Deallocate(p);
        }
    };
    static unsigned long GetCacheIdentifier();
    __declspec(noalias) static NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned long,
                                          TallGrassCacheData*>* GetCacheDataMap();
    static void ClearCacheData();
    class GeometryCacheEntry;
    __declspec(noalias) static NiTMapBase<NiTPointerAllocator<unsigned int>, const char*,
                                          class NiPointerCachedGeometry>* GetGeometryCacheMap();
    static void ClearCaches();
};
template <class T> inline void DestroyGrass(T* pointer)
{
    if (pointer)
    {
        pointer->~T();
        MemoryManager::Instance().Deallocate(pointer);
    }
}
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class TallGrassRefObject
{
  public:
    virtual void vfn_00();
    virtual void DeleteThis();
    volatile long refs;
    void DecRef()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
template <class T> class NiPointer
{
  public:
    T* pointer;
    NiPointer() : pointer(0)
    {}
    ~NiPointer()
    {
        if (pointer)
            pointer->DecRef();
    }
    T* operator->() const
    {
        return pointer;
    }
    operator T*() const
    {
        return pointer;
    }
    void Reset()
    {
        if (pointer)
        {
            pointer->DecRef();
            pointer = 0;
        }
    }
};
class TallGrassShaderProperty::GeometryCacheEntry : public TallGrassRefObject
{
  public:
    NiPointer<TallGrassRefObject> geometry;
    void* data;
    unsigned int field10;
    NiPointer<TallGrassRefObject> field14;
    NiPointer<TallGrassRefObject> field18;
    NiPointer<TallGrassRefObject> field1c;
    NiPointer<TallGrassRefObject> field20;
    unsigned char padding[14];
    bool owned;
};
class NiPointerCachedGeometry : public NiPointer<TallGrassShaderProperty::GeometryCacheEntry>
{
};
#endif
