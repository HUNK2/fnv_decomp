
// src/havok/physics/collide/util/shapedepth/hkpshapedepthutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/shapedepth/hkpshapedepthutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

__declspec(align(16)) struct ScratchVector
{
    float x;
    float y;
    float z;
    float w;
};

struct ScratchMatrix
{
    ScratchVector row0;
    ScratchVector row1;
    ScratchVector row2;
    ScratchVector row3;
};

struct ChildScratch
{
    ScratchMatrix m0;
    ScratchMatrix m1;
    ScratchMatrix m2;
    ScratchMatrix m3;
    ScratchMatrix m4;
    ScratchMatrix m5;
    ScratchMatrix m6;
    ScratchMatrix m7;
};

struct FUN_00d21960_Node;

struct FUN_00d21960_Children
{
    virtual void unk00();
    virtual void unk04();
    virtual int First();
    virtual int Next(int index);
    virtual void unk10();
    virtual FUN_00d21960_Node* GetChild(int index, ChildScratch* scratch);
};

struct FUN_00d21960_Node
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual FUN_00d21960_Children* GetChildren();
};

// Recursively computes the depth of a node's child subtree, returning 0 for nodes without children and max child depth plus one otherwise.
// @fnv 0x00d21960
unsigned char __cdecl GetSubtreeDepth(FUN_00d21960_Node* node)
{
    FUN_00d21960_Children* children = node->GetChildren();
    if (children)
    {
        unsigned char maxDepth = 0;
        ChildScratch scratch;
        for (int iIndex = children->First(); iIndex != -1; iIndex = children->Next(iIndex))
        {
            unsigned char depth = GetSubtreeDepth(children->GetChild(iIndex, &scratch));
            if (depth > maxDepth)
                maxDepth = depth;
        }
        return maxDepth + 1;
    }
    return 0;
}
