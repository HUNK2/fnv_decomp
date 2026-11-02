// fallout_shared/pathfinding/navmeshrender_decls.h: declares NavMeshPtr, ObstacleTask, NavMeshObstacleManager
#ifndef FNV_NAVMESHRENDER_DECLS_H
#define FNV_NAVMESHRENDER_DECLS_H


#include "layout_support.h"

class ObstacleData;
class bhkRigidBody;
class NavMesh;

class NavMeshPtr : public NiPointer<NavMesh>
{
  public:
    NavMeshPtr();
    ~NavMeshPtr();
    NavMeshPtr& operator=(const NavMeshPtr& other);
};

enum OBSTACLE_TASK_TYPE
{
    OBSTACLE_TASK_TYPE_ADD_OBSTACLE = 0x10,
    OBSTACLE_TASK_TYPE_REMOVE_OBSTACLE = 0x20,
    OBSTACLE_TASK_TYPE_ADD_OBSTACLE_FOR_UPDATE = 0x11,
    OBSTACLE_TASK_TYPE_REMOVE_OBSTACLE_FOR_UPDATE = 0x21,
    OBSTACLE_TASK_TYPE_ADD_DOOR = 0x30,
    OBSTACLE_TASK_TYPE_REMOVE_DOOR = 0x40
};

enum OBSTACLE_TASK_RESULT
{
    OBSTACLE_TASK_RESULT_SUCCESS,
    OBSTACLE_TASK_RESULT_FAILLURE
};

template <> class NiPointer<ObstacleData>
{
  public:
    ObstacleData* m_pObject;
    NiPointer(ObstacleData* object = 0);
    ~NiPointer();
    NiPointer& operator=(const NiPointer& other);
};

class ObstacleTask
{
  public:
    NiPointer<ObstacleData> m_spRegisteredObstacle;
    OBSTACLE_TASK_TYPE eType;
    OBSTACLE_TASK_RESULT m_kResult;
    NavMeshPtr apSearchNavMesh;
    ObstacleTask(const NiPointer<ObstacleData>& obstacle, OBSTACLE_TASK_TYPE type, const NavMeshPtr& navMesh);
};

FNV_STATIC_ASSERT(sizeof(ObstacleTask) == 0x10);
FNV_STATIC_ASSERT(offsetof(ObstacleTask, apSearchNavMesh) == 0x0c);

template <> class BSSimpleList<NiPointer<ObstacleData> >
{
  public:
    NiPointer<ObstacleData> m_item;
    BSSimpleList* m_pkNext;
    void AddHead(const NiPointer<ObstacleData>& item);
    bool Contains(const NiPointer<ObstacleData>& item);
};

template <class T> class LockFreeQueue
{
  public:
    virtual ~LockFreeQueue();
    virtual void* AllocateInterface(unsigned int thread);
    virtual void IncrementCount();
    virtual void DecrementCount();
    virtual unsigned int GetCount();
    // Includes the queue nodes, interface manager, count and the aligned lock.
    unsigned char layoutPadding4[0x3c];
    bool FUN_006c6030(T& item);
};

template <class T> class DFALL
{
};
template <class Allocator, class Key, class Value> class NiTMapBase
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    NiTMapItem<Key, Value>** m_ppkHashTable;
    unsigned int m_uiCount;
    bool GetAt(Key key, Value& result) const;
};

typedef NiTMapBase<DFALL<NiTMapItem<bhkRigidBody*, NiPointer<ObstacleData> > >, bhkRigidBody*, NiPointer<ObstacleData> >
    RigidBodyObstacleMap;

class NavMeshObstacleManager
{
  public:
    unsigned char layoutPadding0[0x3c];
    BSSimpleList<NiPointer<ObstacleData> > m_kActiveObstacles;
    unsigned char layoutPadding44[0x1c];
    LockFreeQueue<bhkRigidBody*> m_kActivatedRigidBodies;
    LockFreeQueue<bhkRigidBody*> m_kDeactivatedRigidBodies;
    RigidBodyObstacleMap RigidBodyObstacleLookup;
    void ProcessActivatedObstacles();
};

FNV_STATIC_ASSERT(sizeof(LockFreeQueue<bhkRigidBody*>) == 0x40);
FNV_STATIC_ASSERT(offsetof(NavMeshObstacleManager, m_kActiveObstacles) == 0x3c);
FNV_STATIC_ASSERT(offsetof(NavMeshObstacleManager, m_kActivatedRigidBodies) == 0x60);
FNV_STATIC_ASSERT(offsetof(NavMeshObstacleManager, RigidBodyObstacleLookup) == 0xe0);

#endif
