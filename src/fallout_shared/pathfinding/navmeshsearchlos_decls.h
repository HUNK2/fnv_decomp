// fallout_shared/pathfinding/navmeshsearchlos_decls.h: declares NavMeshSearchLOSArray
#ifndef NAVMESHSEARCHLOS_DECLS_H
#define NAVMESHSEARCHLOS_DECLS_H
class NavMeshSearchLOSArray
{
  public:
    unsigned int allocator;
    void* data;
    unsigned int size;
    unsigned int capacity;
    void Clear(bool freeStorage);
    void FUN_006ac070(void* entries, unsigned int count);
    void FUN_006a8500();
};
#endif
