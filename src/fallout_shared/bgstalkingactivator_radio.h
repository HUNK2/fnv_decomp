// fallout_shared/bgstalkingactivator_radio.h: declares NiPoint3, TESObjectREFR, ParentSpaceNode, TeleportLink, PathingPath and more
#ifndef FNV_BGSTALKINGACTIVATOR_RADIO_H
#define FNV_BGSTALKINGACTIVATOR_RADIO_H

#include "bgstalkingactivator.h"
#include <float.h>
class TESWorldSpace;
class TESObjectCELL;
class NavMeshInfo;
class PathingActorData;
class NiPoint3
{
  public:
    float x, y, z;
};
enum RADIO_RANGE_TYPE
{
    RADIO_RADIUS,
    RADIO_EVERYWHERE,
    RADIO_WORLDSPACE,
    RADIO_INTERIORS,
    RADIO_CELL
};
class TESObjectREFR : public TESForm
{
  public:
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void Unk_74();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual NiPoint3* GetPos() const;
    TESBoundObject* GetObjectReference();
    TESObjectCELL* GetParentCell();
    TESWorldSpace* GetParentWorldSpace();
    TESObjectREFR* GetExteriorRadioReference();
    float GetRadioStationRange();
    RADIO_RANGE_TYPE GetRadioRangeType();
    float GetLightLevelAtPoint(const NiPoint3&);
};
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    void* m_ppVirtualMethodTable;
    T* pData;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    unsigned int GetSize();
    T& GetAt(int);
};
class ParentSpaceNode
{
  public:
    bool m_bIsWorldspace;
    TESWorldSpace* m_pContainingWorldspace;
    TESObjectCELL* m_pReferenceCell;
};
class TeleportLink
{
  public:
    TESObjectREFR* pPathNodeDoor;
    NiPoint3 m_kDestinationPosition;
};
class PathingPath
{
  public:
    BSSimpleArray<ParentSpaceNode, 1024> Spaces;
    BSSimpleArray<TeleportLink, 1024> Doors;
    NiPoint3 Start;
    NiPoint3 End;
    PathingPath();
    ~PathingPath();
};
class PathingLocation
{
  public:
    void* m_ppVirtualMethodTable;
    NiPoint3 Location;
    const NavMeshInfo* m_pLocationNavMesh;
    const BSSimpleArray<const NavMeshInfo*, 1024>* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    PathingLocation(TESObjectREFR*);
    ~PathingLocation();
};
class Pathing
{
  public:
    enum TELEPORT_DOOR_PATH_RESTRICTION
    {
        ANY_SPACE,
        ONE_WORLDSPACE,
        INTERIOR_ONLY
    };
    enum DOOR_LOCK_DISPOSITION
    {
        DEFAULT_LOCKS,
        IGNORE_LOCKS,
        LOCKS_UNUSED,
        RADIO_LOCKS
    };
    static bool FindRouteBetweenLocations(const PathingLocation&, const PathingLocation&, PathingPath*,
                                          TELEPORT_DOOR_PATH_RESTRICTION, float, PathingActorData*,
                                          DOOR_LOCK_DISPOSITION);
    static float FindPathDistance(const PathingLocation&, const PathingLocation&, float, PathingActorData*,
                                  DOOR_LOCK_DISPOSITION);
};
FNV_STATIC_ASSERT(sizeof(PathingLocation) == 40);
FNV_STATIC_ASSERT(sizeof(PathingPath) == 56);
FNV_STATIC_ASSERT(sizeof(ParentSpaceNode) == 12);
#endif
