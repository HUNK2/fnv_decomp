// fallout/interface/interface_rebase_BSFadeNode.h: declares _LODMultType, BSFadeNode
#ifndef FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_BSFADENODE_DECLARATION_H
#define FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_BSFADENODE_DECLARATION_H
#include "interface_rebase_PC_NiNode.h"
class TESObjectREFR;
class FadingSceneNode;
class BSMultiBoundRoom;
class BSPortal;
struct _LODMultType
{
    enum Type
    {
        NONE = 0,
        OBJECTS = 1,
        ITEMS = 2,
        ACTORS = 3,
        TREES = 4,
        LANDSCAPE = 5,
        DISTANT_LOD = 6,
        ACTOR_BODY_PART = 7,
        RENDERED_MENU = 8,
        INVISIBLE = 9,
        IMPOSTER = 10,
        COUNT = 11
    };
};
typedef _LODMultType::Type LOD_MULT_TYPE;
class BSFadeNode : public NiNode
{
  public:
    BSFadeNode();
    ~BSFadeNode();
    float fNearDistSqr;
    float fFarDistSqr;
    float fLastFadePct;
    float fCurrentFade;
    float m_fFadeDelta;
    float fTimeSinceUpdate;
    LOD_MULT_TYPE eLODMultType;
    int iFrameCounter;
    TESObjectREFR* m_pWorldReferenceInfo;
    FadingSceneNode* m_pFadingSceneNode;
    BSSimpleList<BSMultiBoundRoom*> kParentRooms;
    BSSimpleList<BSPortal*> kParentPortals;
    LOD_MULT_TYPE GetLODMultType() const;
};
FNV_STATIC_ASSERT(sizeof(LOD_MULT_TYPE) == 4);
FNV_STATIC_ASSERT(sizeof(BSFadeNode) == 0xE4);
FNV_STATIC_ASSERT(offsetof(BSFadeNode, fNearDistSqr) == 0xAC);
FNV_STATIC_ASSERT(offsetof(BSFadeNode, fFarDistSqr) == 0xB0);
FNV_STATIC_ASSERT(offsetof(BSFadeNode, fLastFadePct) == 0xB4);
FNV_STATIC_ASSERT(offsetof(BSFadeNode, fCurrentFade) == 0xB8);
FNV_STATIC_ASSERT(offsetof(BSFadeNode, m_fFadeDelta) == 0xBC);
FNV_STATIC_ASSERT(offsetof(BSFadeNode, fTimeSinceUpdate) == 0xC0);
FNV_STATIC_ASSERT(offsetof(BSFadeNode, eLODMultType) == 0xC4);
FNV_STATIC_ASSERT(offsetof(BSFadeNode, iFrameCounter) == 0xC8);
FNV_STATIC_ASSERT(offsetof(BSFadeNode, m_pWorldReferenceInfo) == 0xCC);
FNV_STATIC_ASSERT(offsetof(BSFadeNode, m_pFadingSceneNode) == 0xD0);
FNV_STATIC_ASSERT(offsetof(BSFadeNode, kParentRooms) == 0xD4);
FNV_STATIC_ASSERT(offsetof(BSFadeNode, kParentPortals) == 0xDC);
#endif
