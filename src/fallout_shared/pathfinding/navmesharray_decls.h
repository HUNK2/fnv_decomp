#ifndef NAVMESHARRAY_DECLS_H
#define NAVMESHARRAY_DECLS_H

class NavMesh;
template <class T> class NiPointer
{
  public:
    T* ptr;
    NiPointer(const NiPointer&);
    ~NiPointer();
};
typedef NiPointer<NavMesh> NavMeshPtr;
class GlobalObject_00869f00
{
  public:
    unsigned int GetSize();
    NavMesh*& GetAt(unsigned int);
};
NavMeshPtr MakeNavMeshPointer(NavMesh*);
#endif
