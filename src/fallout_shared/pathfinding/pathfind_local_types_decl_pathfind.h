// fallout_shared/pathfinding/pathfind_local_types_decl_pathfind.h: declares PathingLocation
#ifndef PATHFIND_LOCAL_TYPES_H
#define PATHFIND_LOCAL_TYPES_H

// Unit-local supersets of canonical types (same layout; see pathfind_decls.h). Needs the canonical NiPoint3 and the
// layout_support.h forward declarations (included first by pathfind_decls.h).
#pragma pack(push, 4)
class NavMeshPtr;
template <class T> class NiPointer
{
  public:
    T* m_pObject;  // +0x0
    NiPointer(T* object = 0);
    NiPointer(const NiPointer&);
    ~NiPointer();
    NiPointer& operator=(T*);
    NiPointer& operator=(const NiPointer&);
    operator T*() const;
    T* operator->() const;
    T* Get();
};
class PathingLocation
{
  public:
    PathingLocation(TESObjectREFR* ref);     // declared for the original code (decl_variants.py) public:
    void** m_ppVirtualMethodTable;                         // +0x0
    NiPoint3 Location;                       // +0x4
    const NavMeshInfo* m_pLocationNavMesh;   // +0x10
    const void* pNavMeshInfoArray;           // +0x14 (BSSimpleArray<const NavMeshInfo*,1024>*)
    TESObjectCELL* pCell;                    // +0x18
    TESWorldSpace* m_pContainingWorldspace;  // +0x1C
    unsigned int m_uiPathingFlags;           // +0x20
    unsigned short m_usTriangleID;           // +0x24
    unsigned char uiFlags;                   // +0x26
    unsigned char layoutPadding27;  // scalar, not [1]: a char array member makes /GS protect PathingLocation locals
    PathingLocation();
    PathingLocation(const NiPoint3&, TESObjectCELL*, TESWorldSpace*);
    ~PathingLocation();
    bool HasValidTriangle();
    bool IsPathingLocationValid();
    bool FindNavMeshTriangle(NavMeshPtr&, unsigned short&);
    void ResetLocation();
    PathingLocation(const PathingLocation&);                   // 0x006dcc40 (called out of line by unmatched code)
    PathingLocation(const NiPoint3&, const PathingLocation&);  // 0x006dd0d0
    PathingLocation& operator=(const PathingLocation&);        // out of line in the original (no rep movsd)
    NiPoint3 GetLocation() const;                              // 0x005c3420
};
#pragma pack(pop)
#endif
