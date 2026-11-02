
// src/staging/blk_00ce0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

#pragma optimize("gty", on)
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    } lanes;
};
extern "C" __m128 _mm_setzero_ps();
extern float DAT_01012054;

namespace InvalidateTimDetail {
struct Node;
struct Input;
typedef void(__cdecl* Invalidate)(Node*, void*, const Input&);
struct Method
{
    Invalidate invalidate;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
};
struct Input
{
    Method* methods;
};
struct __declspec(align(16)) Node
{
    unsigned char command;
    unsigned char agentType;
    unsigned short unk02;
    int unk04, unk08, unk0c, unk10, unk14;
    float time;
    int unk1c;
};
struct TimNode : Node
{
    __m128 normal;
};
}

// @fnv 0x00cfdbe0
void __cdecl FUN_00cfdbe0(InvalidateTimDetail::Node* node, const InvalidateTimDetail::Input& input)
{
    using namespace InvalidateTimDetail;
    switch (node->command)
    {
    case 2:
    case 6:
    case 10:
    case 14: {
        Invalidate action = input.methods[node->agentType + 0x49].invalidate;
        if (action)
            action(node, node + 1, input);
        break;
    }
    case 4:
    case 12: {
        TimNode* pTimNode = static_cast<TimNode*>(node);
        pTimNode->time = DAT_01012054;
        pTimNode->normal = _mm_setzero_ps();
        Invalidate action = input.methods[node->agentType + 0x49].invalidate;
        if (action)
            action(node, pTimNode + 1, input);
        break;
    }
    }
}
