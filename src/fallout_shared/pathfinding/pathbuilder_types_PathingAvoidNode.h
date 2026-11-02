// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PATHINGAVOIDNODE_H
#define FNV_PATHINGAVOIDNODE_H

#include "layout_support.h"
#include "NiPoint3.h"
class PathingAvoidanceNode;
enum PathingAvoidNode__AVOID_NODE_TYPE
{
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_SPHERE = 0,
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_CYLINDER = 1,
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_SPHERE_ACTOR = 2
};
#pragma pack(push, 4)
class PathingAvoidanceNode
{
  public:
    NiPoint3 m_kLocation;                          // +0x0, 12 bytes
    NiPoint3 TwoComponentVector;              // +0xC, 12 bytes
    float fRadius;                            // +0x18, 4 bytes
    float m_fPathingCostCur;                              // +0x1C, 4 bytes
    PathingAvoidNode__AVOID_NODE_TYPE eType;  // +0x20, 4 bytes
    // PathingAvoidanceNode
    // float __cdecl PathingAvoidanceNode::*(NiPoint3&)
    // PathingAvoidanceNode::AVOID_NODE_TYPE __cdecl PathingAvoidanceNode::*()
    // const NiPoint3& __cdecl PathingAvoidanceNode::*()
    // const NiPoint3& __cdecl PathingAvoidanceNode::*()
    // float __cdecl PathingAvoidanceNode::*()
    // float __cdecl PathingAvoidanceNode::*()
    // void __cdecl PathingAvoidanceNode::*(BGSSaveFormBuffer*)
    // void __cdecl PathingAvoidanceNode::*(BGSLoadFormBuffer*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingAvoidanceNode) == 36);
FNV_STATIC_ASSERT(offsetof(PathingAvoidanceNode, m_kLocation) == 0);
FNV_STATIC_ASSERT(offsetof(PathingAvoidanceNode, TwoComponentVector) == 12);
FNV_STATIC_ASSERT(offsetof(PathingAvoidanceNode, fRadius) == 24);
FNV_STATIC_ASSERT(offsetof(PathingAvoidanceNode, m_fPathingCostCur) == 28);
FNV_STATIC_ASSERT(offsetof(PathingAvoidanceNode, eType) == 32);
#endif
