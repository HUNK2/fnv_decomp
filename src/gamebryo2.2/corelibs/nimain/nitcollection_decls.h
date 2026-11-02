// gamebryo2.2/corelibs/nimain/nitcollection_decls.h: declares MemoryManager
#ifndef FNV_NITCOLLECTION_DECLS_H
#define FNV_NITCOLLECTION_DECLS_H
class MemoryManager
{
  public:
    void* Allocate(unsigned int size);
};
extern MemoryManager g_memoryManager;
class NiGeometry;
class NiTexture;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer();
    ~NiPointer()
    {}
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
};
template <class T> class NiTNewInterface
{
  public:
    static T* Allocate(unsigned int count);
};
#endif
