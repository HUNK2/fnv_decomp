// BGSTerrainNode unit-local declarations.
//
// The distant-terrain node/manager layouts below are copied verbatim from the
// NiPoint3/Setting/AutoMemContext extras follow the accepted
// gameplayformulas.cpp / actionpoints.cpp / bstempeffectsimpledecal precedents:
// canonical headers omit the vanilla accessors, so the TU-local declarations
// carry them.
#ifndef FNV_BGSTERRAINNODE_LOCAL_H
#define FNV_BGSTERRAINNODE_LOCAL_H


#include "layout_support.h"
#include <float.h>
#include <stddef.h>

class BGSTerrainManager;
class BGSTerrainNode;
class BGSTerrainChunk;
class BGSDistantObjectBlock;
class BGSDistantTreeBlock;

#pragma pack(push, 4)
class NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
    NiPoint3();
    NiPoint3(float xPos, float yPos, float zPos);
    NiPoint3 operator-(const NiPoint3& point) const;
    float ComputeMagnitude();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint3) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiPoint3, x) == 0x0);
FNV_STATIC_ASSERT(offsetof(NiPoint3, y) == 0x4);
FNV_STATIC_ASSERT(offsetof(NiPoint3, z) == 0x8);

class BGSTerrainManager
{
  public:
    unsigned int GetMaxLevel();
    unsigned int GetMinLevel();
};

#pragma pack(push, 4)
union SETTING_VALUE
{
  public:
    const char* str;  // +0x0
    int i;            // +0x0
    unsigned int u;   // +0x0
    float f;          // +0x0
    bool b;           // +0x0
    char c;           // +0x0
    unsigned char h;  // +0x0
};
#pragma pack(pop)

class GameSettingCollection
{
};

class SettingT_GameSettingCollection_
{
  public:
    SettingT_GameSettingCollection_();
    ~SettingT_GameSettingCollection_();
    SETTING_VALUE* Float();
    SETTING_VALUE* Bool();
};

extern SettingT_GameSettingCollection_ fSplitDistanceMult;
extern SettingT_GameSettingCollection_ fMorphStartDistanceMult;
extern SettingT_GameSettingCollection_ fMorphEndDistanceMult;
extern SettingT_GameSettingCollection_ bKeepLowDetailTerrain;

class AutoMemContext
{
  public:
    MEM_CONTEXT m_eMemoryContext;  // +0x0
    AutoMemContext(MEM_CONTEXT context, bool track, const char* file, int line);
    ~AutoMemContext();
};

int Warning(const char* aFormat, ...);

extern "C" void* memset(void* pDestination, int cValue, unsigned int uSize);

enum BGSTerrainNode__PARENT_POSITION
{
    BGSTerrainNode__PARENT_POSITION_PP_TOPLEVEL = 0,
    BGSTerrainNode__PARENT_POSITION_PP_UPPER_LEFT = 1,
    BGSTerrainNode__PARENT_POSITION_PP_UPPER_RIGHT = 2,
    BGSTerrainNode__PARENT_POSITION_PP_LOWER_LEFT = 3,
    BGSTerrainNode__PARENT_POSITION_PP_LOWER_RIGHT = 4
};

#pragma pack(push, 4)
class BGSTerrainNode
{
  public:
    BGSTerrainManager* pManager;  // +0x0, 4 bytes
    unsigned int iLevel;          // +0x4, 4 bytes
    short m_sX;                   // +0x8, 2 bytes
    short m_sY;                   // +0xA, 2 bytes
    bool m_bWithinMaximumLevel;   // +0xC, 1 bytes
    bool m_bNodeStateFlag;        // +0xD, 1 bytes
    unsigned char layoutPaddingE[2];
    BGSTerrainChunk* pChunk;           // +0x10, 4 bytes
    BGSDistantObjectBlock* pBlock;     // +0x14, 4 bytes
    BGSDistantTreeBlock* pTrees;       // +0x18, 4 bytes
    NiNode* m_pSceneNode;              // +0x1C, 4 bytes
    BGSTerrainNode* pChildren[4];      // +0x20, 16 bytes
    BGSTerrainNode* pParent;           // +0x30, 4 bytes
    NiPoint3 Center;                   // +0x34, 12 bytes
    float m_fNodeRadius;               // +0x40, 4 bytes
    float m_fSplitDistance;            // +0x44, 4 bytes
    float m_fMorphStartDistance;       // +0x48, 4 bytes
    float m_fMorphEndDistance;         // +0x4C, 4 bytes
    unsigned int TerrainNodeData;      // +0x50, 4 bytes
    bool m_bFlagBeforeParentPosition;  // +0x54, 1 bytes
    unsigned char layoutPadding55[3];
    BGSTerrainNode__PARENT_POSITION m_eParentPosition;  // +0x58, 4 bytes
    bool m_bPersistent;                                 // +0x5C, 1 bytes
    bool m_bNodeInitialized;                            // +0x5D, 1 bytes
    unsigned char layoutPadding5E[2];
    BGSTerrainNode(BGSTerrainManager* pManagerArg, BGSTerrainNode* pParentArg, short sX, short sY, unsigned int uiSize,
                   bool bPersistentArg);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSTerrainNode) == 96);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, pManager) == 0);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, iLevel) == 4);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_sX) == 8);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_sY) == 10);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_bWithinMaximumLevel) == 12);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_bNodeStateFlag) == 13);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, pChunk) == 16);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, pBlock) == 20);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, pTrees) == 24);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_pSceneNode) == 28);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, pChildren) == 32);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, pParent) == 48);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, Center) == 52);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_fNodeRadius) == 64);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_fSplitDistance) == 68);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_fMorphStartDistance) == 72);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_fMorphEndDistance) == 76);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, TerrainNodeData) == 80);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_bFlagBeforeParentPosition) == 84);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_eParentPosition) == 88);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_bPersistent) == 92);
FNV_STATIC_ASSERT(offsetof(BGSTerrainNode, m_bNodeInitialized) == 93);
#endif
