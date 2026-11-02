// FNV decompilation source: fallout_shared/pathfinding/astarsearch.h
//
// A* pathfinding search template used by the NavMesh and CombatPlan planners.
// PC layout corrections are derived from the PC disassembly: the node map
// lives at +0x14 (buckets only, no vtable slot), the search queue at +0x1FF4,
// m_pFirstNode at +0x2048, m_pCurrentNode at +0x204C, m_pLastCreatedNode at
// +0x2050 and m_bUseBestNode at +0x2054. AStarNode stores its link data
// by value, so the key/bucket offsets depend on the instantiation.
#ifndef FNV_ASTARSEARCH_DECLS_H
#define FNV_ASTARSEARCH_DECLS_H


#include "layout_support.h"

enum CREATE_ASTARNODE_RESULT
{
    CREATE_ASTARNODE_RESULT_ASTAR_CREATED_NEW_NODE = 0,
    CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA = 1,
    CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER = 2
};

class NavMesh;
class NavMeshTriangleReference;
#pragma pack(push, 4)
class NavMeshTriangleReference
{
  public:
    NavMesh* m_pLocationNavMesh;            // +0x0, 4 bytes
    unsigned short m_usTriangleIdentifier;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    float GetCenterX;  // +0x8, 4 bytes
    float m_fCenterY;  // +0xC, 4 bytes
    float m_fCenterZ;  // +0x10, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshTriangleReference) == 20);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleReference, m_pLocationNavMesh) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleReference, m_usTriangleIdentifier) == 4);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleReference, GetCenterX) == 8);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleReference, m_fCenterY) == 12);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleReference, m_fCenterZ) == 16);

class NavMeshTriangleEdgeReference;
#pragma pack(push, 4)
class NavMeshTriangleEdgeReference
{
  public:
    NavMesh* m_pLocationNavMesh;            // +0x0, 4 bytes
    unsigned short m_usTriangleIdentifier;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    int m_iEdgeIndex;  // +0x8, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshTriangleEdgeReference) == 12);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleEdgeReference, m_pLocationNavMesh) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleEdgeReference, m_usTriangleIdentifier) == 4);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleEdgeReference, m_iEdgeIndex) == 8);

class AStarNodeData;
class AStarNodeLink;

template <class BoundingVolumeNode, class TLink> class AStarNode
{
  public:
    float m_fPathingCostCur;                        // +0x0
    float m_fCost;                      // +0x4
    BoundingVolumeNode ObjectResolver;  // +0x8
    TLink m_kOpenListLink;              // +0x8 + sizeof(BoundingVolumeNode)
    AStarNode* m_pParentNode;
    AStarNode* m_ppPreviousNodeLink;
    AStarNode* pListNode;
    unsigned int iKey;
    AStarNode* m_pNextHashNode;

    double GetFitness();
};

template <class BoundingVolumeNode, class TLink> class AStarNodeAllocator
{
  public:
    unsigned char m_ScrapHeap[16];
    AStarNode<BoundingVolumeNode, TLink>* CreateNode();
    AStarNode<BoundingVolumeNode, TLink>* FUN_006b9420();
};

template <class BoundingVolumeNode, class TLink> class AStarNodeHashTable
{
  public:
    AStarNode<BoundingVolumeNode, TLink>* m_ppNodes[2039];  // +0x0
    unsigned int iCount;                                    // +0x1FDC
    unsigned int FUN_00996840(unsigned int uiKey);
};

template <class BoundingVolumeNode, class TLink> class AStarOpenList
{
  public:
    float m_fValue;                                       // +0x0
    AStarNode<BoundingVolumeNode, TLink>* m_ppNodes[20];  // +0x4
    void InsertSortedNode(AStarNode<BoundingVolumeNode, TLink>* pNode);
    void UnlinkNode(AStarNode<BoundingVolumeNode, TLink>* pNode);
    void UnlinkFromNeighbors(AStarNode<BoundingVolumeNode, TLink>* pNode);
    AStarNode<BoundingVolumeNode, TLink>* Pop();
};

// PC-only dynamic connection array (20 bytes on PC: no inline buffer).
// The original container type is unrecovered; size and methods are fixed by
// the ComputePath disassembly (ctor writes +0x10, Clear touches +0x4/+0x8/+0xC).
template <class BoundingVolumeNode, class TLink> class AStarConnectionArray
{
  public:
    AStarConnectionArray();
    ~AStarConnectionArray();
    void Clear(bool bFreeData);
    unsigned int GetSize();
    AStarNode<BoundingVolumeNode, TLink>*& operator[](unsigned int uiIndex);

  private:
    // Named words (not an array) so /GS sees no local buffer here.
    unsigned int m_uiData0;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned int m_uiData3;
    unsigned int m_uiData4;
};

template <class BoundingVolumeNode, class TLink> class AStarSearch
{
  public:
    virtual ~AStarSearch();
    AStarNodeAllocator<BoundingVolumeNode, TLink> m_kNodeAllocator;  // +0x4
    AStarNodeHashTable<BoundingVolumeNode, TLink> m_kNodeHashTable;  // +0x14
    AStarOpenList<BoundingVolumeNode, TLink> AStarBucketQueue;       // +0x1FF4
    AStarNode<BoundingVolumeNode, TLink>* m_pFirstNode;              // +0x2048
    AStarNode<BoundingVolumeNode, TLink>* m_pCurrentNode;            // +0x204C
    AStarNode<BoundingVolumeNode, TLink>* m_pLastCreatedNode;        // +0x2050
    bool m_bUseBestNode;                                             // +0x2054
    unsigned char m_Padding2055[3];

    virtual void CollectConnections(AStarNode<BoundingVolumeNode, TLink>* pNode,
                                    AStarConnectionArray<BoundingVolumeNode, TLink>* pConnectionArray);
    virtual bool HasReachedGoal(AStarNode<BoundingVolumeNode, TLink>* pNode);

    CREATE_ASTARNODE_RESULT CreateOrUpdateNode(unsigned int uiKey, float m_fPathingCostCur,
                                               AStarNode<BoundingVolumeNode, TLink>*& pNodeOut);
    AStarNode<BoundingVolumeNode, TLink>* FindOrCreateSearchNode(unsigned int uiKey,
                                                                 const BoundingVolumeNode& ObjectResolver,
                                                                 float m_fCost);
    AStarNode<BoundingVolumeNode, TLink>* ComputePath();
    bool FUN_006a8290(AStarNode<BoundingVolumeNode, TLink>* pNode, unsigned int uiParam1, unsigned int uiParam2);
    bool Search(unsigned int uiParam1, unsigned int uiParam2, bool bUseBestNode);
};

typedef AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference> NavMeshAStarNode;
typedef AStarNode<AStarNodeData*, AStarNodeLink*> CombatPlanAStarNode;
typedef AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference> NavMeshAStarSearch;
FNV_STATIC_ASSERT(sizeof(NavMeshAStarNode) == 0x3C);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarNode, iKey) == 0x34);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarNode, m_pNextHashNode) == 0x38);
FNV_STATIC_ASSERT(sizeof(CombatPlanAStarNode) == 0x24);
FNV_STATIC_ASSERT(offsetof(CombatPlanAStarNode, iKey) == 0x1C);
FNV_STATIC_ASSERT(offsetof(CombatPlanAStarNode, m_pNextHashNode) == 0x20);
FNV_STATIC_ASSERT(sizeof(NavMeshAStarSearch) == 0x2058);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarSearch, m_kNodeHashTable) == 0x14);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarSearch, AStarBucketQueue) == 0x1FF4);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarSearch, m_pFirstNode) == 0x2048);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarSearch, m_pLastCreatedNode) == 0x2050);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarSearch, m_bUseBestNode) == 0x2054);

// Tasklet manager behind GetTaskletManager. Slots 0-2 are unrecovered
// (never called by the matched functions); slot 3 takes the
// a tasklet. Exact extent unrecovered; size is not observable here.
class BSWin32TaskletManager
{
  public:
    BSWin32TaskletManager(unsigned int uiThreadCount);
    ~BSWin32TaskletManager();
    virtual void LockTasklets();
    virtual void UnlockTasklets();
    virtual void WaitForTasklets();
    virtual bool TryRunAsTasklet(unsigned int uiThreadId);

  private:
    unsigned char m_Data[64];
};

unsigned int gm_GetCurrentThreadId();

class NavMeshSearch
{
  public:
    int CreateOrUpdateNode(unsigned int, float, NavMeshAStarNode*&);
};

void FUN_0040fca0(unsigned long);
#endif
