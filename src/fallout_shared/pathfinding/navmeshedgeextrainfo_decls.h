// fallout_shared/pathfinding/navmeshedgeextrainfo_decls.h: declares EdgeExtraInfo
#ifndef NAVMESHEDGEEXTRAINFO_DECLS_H
#define NAVMESHEDGEEXTRAINFO_DECLS_H


class NavMeshInfo;
class TESFile;

template <class T, int N> class BSSimpleArray
{
  public:
    unsigned int Add(const T&);
};

template <> class BSSimpleArray<NavMeshInfo*, 1024>
{
  public:
    void* vtable;
    void FUN_006b3eb0(unsigned int, bool);
};

extern unsigned int DAT_0106b0dc;

class EdgeExtraInfo
{
  public:
    void* vtable;
    EdgeExtraInfo* DeserializeFromFile();
};

#endif
