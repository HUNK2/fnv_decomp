// bscore/bsscraparray_decls.h: declares MemoryManager
#ifndef BSSCRAPARRAY_DECLS_H
#define BSSCRAPARRAY_DECLS_H

class NiAVObject;
class Animation;
class NavMeshInfo;
template <class T> class NiPointer;
class ScrapHeapBuffer;
class MemoryManager
{
  public:
    ScrapHeapBuffer* GetGeneralAllocator();
};
MemoryManager* MemoryManager_Instance();
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    BSSimpleArray();
    ~BSSimpleArray();
    void* vtable;
    T* pBuffer;
    unsigned int iSize, SimpleArrayStorage;
    void FUN_00822860(unsigned int, bool);
    void FUN_006b3eb0(unsigned int, bool);
};
extern unsigned int DAT_01084074;
extern unsigned int DAT_0108c228;
template <class T, unsigned int N> class BSScrapArray : public BSSimpleArray<T, N>
{
  public:
    BSScrapArray();
    ScrapHeapBuffer* m_pAllocator;
};
#endif
