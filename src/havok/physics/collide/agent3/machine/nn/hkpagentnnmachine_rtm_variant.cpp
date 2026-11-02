// src/havok/physics/collide/agent3/machine/nn/hkpagentnnmachine_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent3/machine/nn/hkpagentnnmachine.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent3/machine/nn/hkpagentnnmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/nn/hkpagentnnmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct LinkEntry
{
    void* m_pIntegerData;
    void* m_pKey;
};
struct LinkNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    LinkEntry* m_pEntries;
    int m_iArrayLength;
};
void* __cdecl FindEntryValue(LinkNode* apFirst, LinkNode* apSecond);
// Stand-in for the game's record descriptor:
//   +0x00  base address used for the last record
//   +0x04  array of 4-byte record pointers
//   +0x08  number of records
struct unk_00cfddc0
{
    int unk00;
    int* unk04;
    int unk08;
};
void FUN_00cfddc0(unk_00cfddc0* pArg);
// GetNodePairValue (0x00cfdf60, 184 bytes)
//
// Two "grid" objects are looked up in a 32-column byte table that is held by a
// context object:
//
//   * ppA / ppB point at objects whose +0x0c member is a row/column index,
//   * pCtx->unk00 is the base of the table, pCtx->unk14 selects one of two
//     parallel tables (offset 0x12b0 when it is set, 0xeb0 when it is clear),
//   * pOutVal receives the table byte of the (transposed) second lookup,
//   * pOutFlag receives 1 when the table entry describes a usable value.
struct FnvNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct FnvCtx
{
    unsigned char* unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
void GetNodePairValue(FnvNode** ppA, FnvNode** ppB, FnvCtx* pCtx, int* pOutVal, int* pOutFlag);
struct CFE820Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct CFE820MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CFE820Allocator* m_pStreamAllocator;

    CFE820Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" CFE820MemoryRouter& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);
struct CFE820BlockArray
{
    char** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    static void construct(char** p, int n, char* const& e)
    {
        for (int i = 0; i < n; i++)
            p[i] = e;
    }

    void AddBack(char* const& e)
    {
        CFE820Allocator& alloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(char*));
        construct(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};
struct CFE820Pool
{
    unsigned int m_uiBufferCapacity;
    CFE820BlockArray m_kBlocks;
};
static char* AllocatePoolChunk(CFE820Pool* pool);
char* CFE820Allocate(CFE820Pool* pool);
// FUN_00cfeba0 - pick a per-shape handler out of a table and run it.
//
// The shape object carries a type byte and an index byte.  Depending on the
// type the function either jumps straight to a per-index callback or first
// evaluates two transform chains (FUN_00cfe1d0) and then re-dispatches with a
// masked type byte.
typedef void(__cdecl* FUN_00cfeba0_Fn)(void*, void*, void*, void*, void*, void*, void*);
struct FUN_00cfeba0_Obj
{
    unsigned char m_type;         // +0x00 shape type
    unsigned char m_uiEdgeIndex;  // +0x01 handler index
    int unk04;
    int unk08;  // +0x08
    int unk0c;
    void* m_p10;  // +0x10
    void* m_p14;  // +0x14
    int unk18;
    int unk1c;
    int unk20;  // +0x20
    int unk24;
    int unk28;
    int unk2c;
    int unk30;  // +0x30
};
struct FUN_00cfeba0_Result
{
    void* unk00;
    int unk04;
    void* unk08;
    void* unk0c;
};
struct __declspec(align(16)) FUN_00cfeba0_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
};
void* __cdecl FUN_00cfe1d0(void* h, void* a, void* b, unsigned int n, void* c);
void __cdecl FUN_00cfeba0(FUN_00cfeba0_Obj* self, void** apCallbackTable, void* a3);
struct ItemStack
{
    int m_base;
    int* m_pItems;
    int m_uiItemCount;
};
void __cdecl FUN_00cfea30(ItemStack* s, int value, int a, int b);
void __cdecl FUN_00cfed90(ItemStack* s, int a, int b);
extern const float DAT_01012054;
struct FUN_00cfdc90_Obj
{
    unsigned char type;
    unsigned char slot;
    short unk02;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
};
typedef void(__cdecl* FUN_00cfdc90_Fn)(FUN_00cfdc90_Obj* self, void* p, float a, float b, void* ctx);
void __cdecl DispatchSlotCallback(FUN_00cfdc90_Obj* obj, float x, float y, void* ctx);
struct hkpLinkedCollidableCFEA;
struct hkpAgentNnEntryCFEA;
typedef void(__cdecl* hkAgent3DestroyFuncCFEA)(hkpAgentNnEntryCFEA* entry, void* agentData, void* contactMgr,
                                               void* constraintOwner, void* dispatcher);
struct hkpAgent3FuncsCFEA
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
};
struct hkpCollisionDispatcherCFEA
{
    int unk0000, unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c;
    int unk0020, unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c;
    int unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    int unk0060, unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c;
    int unk0080, unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c;
    int unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc;
    int unk00c0, unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc;
    int unk00e0, unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc;
    int unk0100, unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c;
    int unk0120, unk0124, unk0128, unk012c, unk0130, unk0134, unk0138, unk013c;
    int unk0140, unk0144, unk0148, unk014c, unk0150, unk0154, unk0158, unk015c;
    int unk0160, unk0164, unk0168, unk016c, unk0170, unk0174, unk0178, unk017c;
    int unk0180, unk0184, unk0188, unk018c, unk0190, unk0194, unk0198, unk019c;
    int unk01a0, unk01a4, unk01a8, unk01ac, unk01b0, unk01b4, unk01b8, unk01bc;
    int unk01c0, unk01c4, unk01c8, unk01cc, unk01d0, unk01d4, unk01d8, unk01dc;
    int unk01e0, unk01e4, unk01e8, unk01ec, unk01f0, unk01f4, unk01f8, unk01fc;
    int unk0200, unk0204, unk0208, unk020c, unk0210, unk0214, unk0218, unk021c;
    int unk0220, unk0224, unk0228, unk022c, unk0230, unk0234, unk0238, unk023c;
    int unk0240, unk0244, unk0248, unk024c, unk0250, unk0254, unk0258, unk025c;
    int unk0260, unk0264, unk0268, unk026c, unk0270, unk0274, unk0278, unk027c;
    int unk0280, unk0284, unk0288, unk028c, unk0290, unk0294, unk0298, unk029c;
    int unk02a0, unk02a4, unk02a8, unk02ac, unk02b0, unk02b4, unk02b8, unk02bc;
    int unk02c0, unk02c4, unk02c8, unk02cc, unk02d0, unk02d4, unk02d8, unk02dc;
    int unk02e0, unk02e4, unk02e8, unk02ec, unk02f0, unk02f4, unk02f8, unk02fc;
    int unk0300, unk0304, unk0308, unk030c, unk0310, unk0314, unk0318, unk031c;
    int unk0320, unk0324, unk0328, unk032c, unk0330, unk0334, unk0338, unk033c;
    int unk0340, unk0344, unk0348, unk034c, unk0350, unk0354, unk0358, unk035c;
    int unk0360, unk0364, unk0368, unk036c, unk0370, unk0374, unk0378, unk037c;
    int unk0380, unk0384, unk0388, unk038c, unk0390, unk0394, unk0398, unk039c;
    int unk03a0, unk03a4, unk03a8, unk03ac, unk03b0, unk03b4, unk03b8, unk03bc;
    int unk03c0, unk03c4, unk03c8, unk03cc, unk03d0, unk03d4, unk03d8, unk03dc;
    int unk03e0, unk03e4, unk03e8, unk03ec, unk03f0, unk03f4, unk03f8, unk03fc;
    int unk0400, unk0404, unk0408, unk040c, unk0410, unk0414, unk0418, unk041c;
    int unk0420, unk0424, unk0428, unk042c, unk0430, unk0434, unk0438, unk043c;
    int unk0440, unk0444, unk0448, unk044c, unk0450, unk0454, unk0458, unk045c;
    int unk0460, unk0464, unk0468, unk046c, unk0470, unk0474, unk0478, unk047c;
    int unk0480, unk0484, unk0488, unk048c, unk0490, unk0494, unk0498, unk049c;
    int unk04a0, unk04a4, unk04a8, unk04ac, unk04b0, unk04b4, unk04b8, unk04bc;
    int unk04c0, unk04c4, unk04c8, unk04cc, unk04d0, unk04d4, unk04d8, unk04dc;
    int unk04e0, unk04e4, unk04e8, unk04ec, unk04f0, unk04f4, unk04f8, unk04fc;
    int unk0500, unk0504, unk0508, unk050c, unk0510, unk0514, unk0518, unk051c;
    int unk0520, unk0524, unk0528, unk052c, unk0530, unk0534, unk0538, unk053c;
    int unk0540, unk0544, unk0548, unk054c, unk0550, unk0554, unk0558, unk055c;
    int unk0560, unk0564, unk0568, unk056c, unk0570, unk0574, unk0578, unk057c;
    int unk0580, unk0584, unk0588, unk058c, unk0590, unk0594, unk0598, unk059c;
    int unk05a0, unk05a4, unk05a8, unk05ac, unk05b0, unk05b4, unk05b8, unk05bc;
    int unk05c0, unk05c4, unk05c8, unk05cc, unk05d0, unk05d4, unk05d8, unk05dc;
    int unk05e0, unk05e4, unk05e8, unk05ec, unk05f0, unk05f4, unk05f8, unk05fc;
    int unk0600, unk0604, unk0608, unk060c, unk0610, unk0614, unk0618, unk061c;
    int unk0620, unk0624, unk0628, unk062c, unk0630, unk0634, unk0638, unk063c;
    int unk0640, unk0644, unk0648, unk064c, unk0650, unk0654, unk0658, unk065c;
    int unk0660, unk0664, unk0668, unk066c, unk0670, unk0674, unk0678, unk067c;
    int unk0680, unk0684, unk0688, unk068c, unk0690, unk0694, unk0698, unk069c;
    int unk06a0, unk06a4, unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc;
    int unk06c0, unk06c4, unk06c8, unk06cc, unk06d0, unk06d4, unk06d8, unk06dc;
    int unk06e0, unk06e4, unk06e8, unk06ec, unk06f0, unk06f4, unk06f8, unk06fc;
    int unk0700, unk0704, unk0708, unk070c, unk0710, unk0714, unk0718, unk071c;
    int unk0720, unk0724, unk0728, unk072c, unk0730, unk0734, unk0738, unk073c;
    int unk0740, unk0744, unk0748, unk074c, unk0750, unk0754, unk0758, unk075c;
    int unk0760, unk0764, unk0768, unk076c, unk0770, unk0774, unk0778, unk077c;
    int unk0780, unk0784, unk0788, unk078c, unk0790, unk0794, unk0798, unk079c;
    int unk07a0, unk07a4, unk07a8, unk07ac, unk07b0, unk07b4, unk07b8, unk07bc;
    int unk07c0, unk07c4, unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc;
    int unk07e0, unk07e4, unk07e8, unk07ec, unk07f0, unk07f4, unk07f8, unk07fc;
    int unk0800, unk0804, unk0808, unk080c, unk0810, unk0814, unk0818, unk081c;
    int unk0820, unk0824, unk0828, unk082c, unk0830, unk0834, unk0838, unk083c;
    int unk0840, unk0844, unk0848, unk084c, unk0850, unk0854, unk0858, unk085c;
    int unk0860, unk0864, unk0868, unk086c, unk0870, unk0874, unk0878, unk087c;
    int unk0880, unk0884, unk0888, unk088c, unk0890, unk0894, unk0898, unk089c;
    int unk08a0, unk08a4, unk08a8, unk08ac, unk08b0, unk08b4, unk08b8, unk08bc;
    int unk08c0, unk08c4, unk08c8, unk08cc, unk08d0, unk08d4, unk08d8, unk08dc;
    int unk08e0, unk08e4, unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc;
    int unk0900, unk0904, unk0908, unk090c, unk0910, unk0914, unk0918, unk091c;
    int unk0920, unk0924, unk0928, unk092c, unk0930, unk0934, unk0938, unk093c;
    int unk0940, unk0944, unk0948, unk094c, unk0950, unk0954, unk0958, unk095c;
    int unk0960, unk0964, unk0968, unk096c, unk0970, unk0974, unk0978, unk097c;
    int unk0980, unk0984, unk0988, unk098c, unk0990, unk0994, unk0998, unk099c;
    int unk09a0, unk09a4, unk09a8, unk09ac, unk09b0, unk09b4, unk09b8, unk09bc;
    int unk09c0, unk09c4, unk09c8, unk09cc, unk09d0, unk09d4, unk09d8, unk09dc;
    int unk09e0, unk09e4, unk09e8, unk09ec, unk09f0, unk09f4, unk09f8, unk09fc;
    int unk0a00, unk0a04, unk0a08, unk0a0c, unk0a10, unk0a14, unk0a18, unk0a1c;
    int unk0a20, unk0a24, unk0a28, unk0a2c, unk0a30, unk0a34, unk0a38, unk0a3c;
    int unk0a40, unk0a44, unk0a48, unk0a4c, unk0a50, unk0a54, unk0a58, unk0a5c;
    int unk0a60, unk0a64, unk0a68, unk0a6c, unk0a70, unk0a74, unk0a78, unk0a7c;
    int unk0a80, unk0a84, unk0a88, unk0a8c, unk0a90, unk0a94, unk0a98, unk0a9c;
    int unk0aa0, unk0aa4, unk0aa8, unk0aac, unk0ab0, unk0ab4, unk0ab8, unk0abc;
    int unk0ac0, unk0ac4, unk0ac8, unk0acc, unk0ad0, unk0ad4, unk0ad8, unk0adc;
    int unk0ae0, unk0ae4, unk0ae8, unk0aec, unk0af0, unk0af4, unk0af8, unk0afc;
    int unk0b00, unk0b04, unk0b08, unk0b0c, unk0b10, unk0b14, unk0b18, unk0b1c;
    int unk0b20, unk0b24, unk0b28, unk0b2c, unk0b30, unk0b34, unk0b38, unk0b3c;
    int unk0b40, unk0b44, unk0b48, unk0b4c, unk0b50, unk0b54, unk0b58, unk0b5c;
    int unk0b60, unk0b64, unk0b68, unk0b6c, unk0b70, unk0b74, unk0b78, unk0b7c;
    int unk0b80, unk0b84, unk0b88, unk0b8c, unk0b90, unk0b94, unk0b98, unk0b9c;
    int unk0ba0, unk0ba4, unk0ba8, unk0bac, unk0bb0, unk0bb4, unk0bb8, unk0bbc;
    int unk0bc0, unk0bc4, unk0bc8, unk0bcc, unk0bd0, unk0bd4, unk0bd8, unk0bdc;
    int unk0be0, unk0be4, unk0be8, unk0bec, unk0bf0, unk0bf4, unk0bf8, unk0bfc;
    int unk0c00, unk0c04, unk0c08, unk0c0c, unk0c10, unk0c14, unk0c18, unk0c1c;
    int unk0c20, unk0c24, unk0c28, unk0c2c, unk0c30, unk0c34, unk0c38, unk0c3c;
    int unk0c40, unk0c44, unk0c48, unk0c4c, unk0c50, unk0c54, unk0c58, unk0c5c;
    int unk0c60, unk0c64, unk0c68, unk0c6c, unk0c70, unk0c74, unk0c78, unk0c7c;
    int unk0c80, unk0c84, unk0c88, unk0c8c, unk0c90, unk0c94, unk0c98, unk0c9c;
    int unk0ca0, unk0ca4, unk0ca8, unk0cac, unk0cb0, unk0cb4, unk0cb8, unk0cbc;
    int unk0cc0, unk0cc4, unk0cc8, unk0ccc, unk0cd0, unk0cd4, unk0cd8, unk0cdc;
    int unk0ce0, unk0ce4, unk0ce8, unk0cec, unk0cf0, unk0cf4, unk0cf8, unk0cfc;
    int unk0d00, unk0d04, unk0d08, unk0d0c, unk0d10, unk0d14, unk0d18, unk0d1c;
    int unk0d20, unk0d24, unk0d28, unk0d2c, unk0d30, unk0d34, unk0d38, unk0d3c;
    int unk0d40, unk0d44, unk0d48, unk0d4c, unk0d50, unk0d54, unk0d58, unk0d5c;
    int unk0d60, unk0d64, unk0d68, unk0d6c, unk0d70, unk0d74, unk0d78, unk0d7c;
    int unk0d80, unk0d84, unk0d88, unk0d8c, unk0d90, unk0d94, unk0d98, unk0d9c;
    int unk0da0, unk0da4, unk0da8, unk0dac, unk0db0, unk0db4, unk0db8, unk0dbc;
    int unk0dc0, unk0dc4, unk0dc8, unk0dcc, unk0dd0, unk0dd4, unk0dd8, unk0ddc;
    int unk0de0, unk0de4, unk0de8, unk0dec, unk0df0, unk0df4, unk0df8, unk0dfc;
    int unk0e00, unk0e04, unk0e08, unk0e0c, unk0e10, unk0e14, unk0e18, unk0e1c;
    int unk0e20, unk0e24, unk0e28, unk0e2c, unk0e30, unk0e34, unk0e38, unk0e3c;
    int unk0e40, unk0e44, unk0e48, unk0e4c, unk0e50, unk0e54, unk0e58, unk0e5c;
    int unk0e60, unk0e64, unk0e68, unk0e6c, unk0e70, unk0e74, unk0e78, unk0e7c;
    int unk0e80, unk0e84, unk0e88, unk0e8c, unk0e90, unk0e94, unk0e98, unk0e9c;
    int unk0ea0, unk0ea4, unk0ea8, unk0eac, unk0eb0, unk0eb4, unk0eb8, unk0ebc;
    int unk0ec0, unk0ec4, unk0ec8, unk0ecc, unk0ed0, unk0ed4, unk0ed8, unk0edc;
    int unk0ee0, unk0ee4, unk0ee8, unk0eec, unk0ef0, unk0ef4, unk0ef8, unk0efc;
    int unk0f00, unk0f04, unk0f08, unk0f0c, unk0f10, unk0f14, unk0f18, unk0f1c;
    int unk0f20, unk0f24, unk0f28, unk0f2c, unk0f30, unk0f34, unk0f38, unk0f3c;
    int unk0f40, unk0f44, unk0f48, unk0f4c, unk0f50, unk0f54, unk0f58, unk0f5c;
    int unk0f60, unk0f64, unk0f68, unk0f6c, unk0f70, unk0f74, unk0f78, unk0f7c;
    int unk0f80, unk0f84, unk0f88, unk0f8c, unk0f90, unk0f94, unk0f98, unk0f9c;
    int unk0fa0, unk0fa4, unk0fa8, unk0fac, unk0fb0, unk0fb4, unk0fb8, unk0fbc;
    int unk0fc0, unk0fc4, unk0fc8, unk0fcc, unk0fd0, unk0fd4, unk0fd8, unk0fdc;
    int unk0fe0, unk0fe4, unk0fe8, unk0fec, unk0ff0, unk0ff4, unk0ff8, unk0ffc;
    int unk1000, unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c;
    int unk1020, unk1024, unk1028, unk102c, unk1030, unk1034, unk1038, unk103c;
    int unk1040, unk1044, unk1048, unk104c, unk1050, unk1054, unk1058, unk105c;
    int unk1060, unk1064, unk1068, unk106c, unk1070, unk1074, unk1078, unk107c;
    int unk1080, unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c;
    int unk10a0, unk10a4, unk10a8, unk10ac, unk10b0, unk10b4, unk10b8, unk10bc;
    int unk10c0, unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc;
    int unk10e0, unk10e4, unk10e8, unk10ec, unk10f0, unk10f4, unk10f8, unk10fc;
    int unk1100, unk1104, unk1108, unk110c, unk1110, unk1114, unk1118, unk111c;
    int unk1120, unk1124, unk1128, unk112c, unk1130, unk1134, unk1138, unk113c;
    int unk1140, unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c;
    int unk1160, unk1164, unk1168, unk116c, unk1170, unk1174, unk1178, unk117c;
    int unk1180, unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c;
    int unk11a0, unk11a4, unk11a8, unk11ac, unk11b0, unk11b4, unk11b8, unk11bc;
    int unk11c0, unk11c4, unk11c8, unk11cc, unk11d0, unk11d4, unk11d8, unk11dc;
    int unk11e0, unk11e4, unk11e8, unk11ec, unk11f0, unk11f4, unk11f8, unk11fc;
    int unk1200, unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c;
    int unk1220, unk1224, unk1228, unk122c, unk1230, unk1234, unk1238, unk123c;
    int unk1240, unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c;
    int unk1260, unk1264, unk1268, unk126c, unk1270, unk1274, unk1278, unk127c;
    int unk1280, unk1284, unk1288, unk128c, unk1290, unk1294, unk1298, unk129c;
    int unk12a0, unk12a4, unk12a8, unk12ac, unk12b0, unk12b4, unk12b8, unk12bc;
    int unk12c0, unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc;
    int unk12e0, unk12e4, unk12e8, unk12ec, unk12f0, unk12f4, unk12f8, unk12fc;
    int unk1300, unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c;
    int unk1320, unk1324, unk1328, unk132c, unk1330, unk1334, unk1338, unk133c;
    int unk1340, unk1344, unk1348, unk134c, unk1350, unk1354, unk1358, unk135c;
    int unk1360, unk1364, unk1368, unk136c, unk1370, unk1374, unk1378, unk137c;
    int unk1380, unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c;
    int unk13a0, unk13a4, unk13a8, unk13ac, unk13b0, unk13b4, unk13b8, unk13bc;
    int unk13c0, unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc;
    int unk13e0, unk13e4, unk13e8, unk13ec, unk13f0, unk13f4, unk13f8, unk13fc;
    int unk1400, unk1404, unk1408, unk140c, unk1410, unk1414, unk1418, unk141c;
    int unk1420, unk1424, unk1428, unk142c, unk1430, unk1434, unk1438, unk143c;
    int unk1440, unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c;
    int unk1460, unk1464, unk1468, unk146c, unk1470, unk1474, unk1478, unk147c;
    int unk1480, unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c;
    int unk14a0, unk14a4, unk14a8, unk14ac, unk14b0, unk14b4, unk14b8, unk14bc;
    int unk14c0, unk14c4, unk14c8, unk14cc, unk14d0, unk14d4, unk14d8, unk14dc;
    int unk14e0, unk14e4, unk14e8, unk14ec, unk14f0, unk14f4, unk14f8, unk14fc;
    int unk1500, unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c;
    int unk1520, unk1524, unk1528, unk152c, unk1530, unk1534, unk1538, unk153c;
    int unk1540, unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c;
    int unk1560, unk1564, unk1568, unk156c, unk1570, unk1574, unk1578, unk157c;
    int unk1580, unk1584, unk1588, unk158c, unk1590, unk1594, unk1598, unk159c;
    int unk15a0, unk15a4, unk15a8, unk15ac, unk15b0, unk15b4, unk15b8, unk15bc;
    int unk15c0, unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc;
    int unk15e0, unk15e4, unk15e8, unk15ec, unk15f0, unk15f4, unk15f8, unk15fc;
    int unk1600, unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c;
    int unk1620, unk1624, unk1628, unk162c, unk1630, unk1634, unk1638, unk163c;
    int unk1640, unk1644, unk1648, unk164c, unk1650, unk1654, unk1658, unk165c;
    int unk1660, unk1664, unk1668, unk166c, unk1670, unk1674, unk1678, unk167c;
    int unk1680, unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c;
    int unk16a0, unk16a4, unk16a8, unk16ac, unk16b0;
    hkAgent3DestroyFuncCFEA m_pAgent3DestroyFuncs;
    // the rest of the agent3 function table follows, 0x50 bytes per agent type
    hkAgent3DestroyFuncCFEA getAgent3DestroyFunc(int agentType)
    {
        return *(hkAgent3DestroyFuncCFEA*)((char*)&m_pAgent3DestroyFuncs + agentType * sizeof(hkpAgent3FuncsCFEA));
    }
};
struct hkpAgentNnEntryCFEA
{
    unsigned char m_ucAgentType;
    unsigned char m_ucNnTrackType;
    unsigned short unk02;
    unsigned short m_ausAgentData[2];
    void* m_pContactManager;
    int unk0c;
    hkpLinkedCollidableCFEA* m_kCollidable[2];
    int unk18, unk1c;
};
struct hkpCollisionEntryCFEA
{
    hkpAgentNnEntryCFEA* m_pAgentEntry;
    hkpLinkedCollidableCFEA* m_pCollidable;
};
template <int N> static __forceinline void memCpyOneAlignedCFEA(void* dst, const void* src)
{
    int i = 0;
    do
    {
        ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i];
    } while (++i < N / 4);
}
static __forceinline int hkNextPowerOf2CFEA(unsigned int in)
{
    in -= 1;
    in |= in >> 16;
    in |= in >> 8;
    in |= in >> 4;
    in |= in >> 2;
    in |= in >> 1;
    return in + 1;
}
void __cdecl FUN_00c909d0(void* alloc, void* array, int sizeElem, void* pad, int newCapacity);
struct hkCollisionEntryArrayCFEA
{
    hkpCollisionEntryCFEA* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
        {
            memCpyOneAlignedCFEA<sizeof(hkpCollisionEntryCFEA)>(m_data + index, m_data + m_iElementCount);
        }
    }

    void OptimizeCapacity(CFE820Allocator& alloc, int numFreeElemsLeft)
    {
        int totalSize = hkNextPowerOf2CFEA(m_iElementCount + numFreeElemsLeft);
        if (totalSize < getCapacity())
        {
            FUN_00c909d0(&alloc, this, sizeof(hkpCollisionEntryCFEA), 0, totalSize);
        }
    }
};
struct hkpLinkedCollidableCFEA
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    hkCollisionEntryArrayCFEA m_kCollisionEntries;
};
void __cdecl FUN_00cfe020(void* track, hkpAgentNnEntryCFEA* entry);
void __cdecl FUN_00cfea30(void* track, hkpAgentNnEntryCFEA* entry, hkpCollisionDispatcherCFEA* dispatch,
                          void* constraintOwner);
struct hkpAgentNnSectorCFF2;
struct hkpAgentNnEntryCFF2;
static __forceinline int hkNextPowerOf2CFF2(unsigned int in)
{
    in -= 1;
    in |= in >> 16;
    in |= in >> 8;
    in |= in >> 4;
    in |= in >> 2;
    in |= in >> 1;
    return in + 1;
}
void __cdecl FUN_00c909d0(void* alloc, void* array, int sizeElem, void* storage, int newCapacity);
struct hkMemoryAllocatorCFF2
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct hkMemoryRouterCFF2
{
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocatorCFF2* m_pStreamAllocator;

    hkMemoryAllocatorCFF2& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterCFF2 {
extern "C" hkMemoryRouterCFF2& __cdecl FUN_00c85750();
}
struct hkSectorArrayCFF2
{
    hkpAgentNnSectorCFF2** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkpAgentNnSectorCFF2* m_kStorage[1];

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    hkpAgentNnSectorCFF2*& back()
    {
        return m_data[m_iElementCount - 1];
    }
    void popBack()
    {
        m_iElementCount--;
    }

    void Search(hkMemoryAllocatorCFF2& alloc, int index, hkpAgentNnSectorCFF2* const* p, int numToInsert);

    __forceinline void OptimizeCapacity(int numFreeElemsLeft)
    {
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            int newCapacity = hkNextPowerOf2CFF2(m_iElementCount + numFreeElemsLeft);
            if (newCapacity < 1)
            {
                FUN_00c909d0(&hkRouterCFF2::FUN_00c85750().heap(), this, sizeof(hkpAgentNnSectorCFF2*), m_kStorage, 1);
            }
            else if (newCapacity < getCapacity())
            {
                FUN_00c909d0(&hkRouterCFF2::FUN_00c85750().heap(), this, sizeof(hkpAgentNnSectorCFF2*), 0, newCapacity);
            }
        }
    }
};
struct hkpAgentNnTrackCFF2
{
    int m_iBytesUsedInLastSector;
    hkSectorArrayCFF2 m_kSectors;
};
void __cdecl CloneRecord(hkpAgentNnTrackCFF2* track, hkpAgentNnEntryCFF2* entry);
void __cdecl FUN_00cff290(hkpAgentNnTrackCFF2* track, hkpAgentNnTrackCFF2* appendee);
extern "C" void _ReadWriteBarrier(void);
struct S_cfe020_Entry;
struct S_cfe020_Slot
{
    S_cfe020_Entry* entry;
    int unk04;
};
struct S_cfe020_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    S_cfe020_Slot* slots;
};
struct S_cfe020_Entry
{
    int unk00;
    union
    {
        int unk04;
        struct
        {
            unsigned short idxA;
            unsigned short idxB;
        };
    };
    int unk08;
    int unk0c;
    S_cfe020_Owner* ownerA;
    S_cfe020_Owner* ownerB;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    volatile int unk7c;
    __forceinline S_cfe020_Entry& operator=(const S_cfe020_Entry& o)
    {
        unk00 = o.unk00;
        unk04 = o.unk04;
        unk08 = o.unk08;
        unk0c = o.unk0c;
        ownerA = o.ownerA;
        ownerB = o.ownerB;
        unk18 = o.unk18;
        unk1c = o.unk1c;
        unk20 = o.unk20;
        unk24 = o.unk24;
        unk28 = o.unk28;
        unk2c = o.unk2c;
        unk30 = o.unk30;
        unk34 = o.unk34;
        unk38 = o.unk38;
        unk3c = o.unk3c;
        unk40 = o.unk40;
        unk44 = o.unk44;
        unk48 = o.unk48;
        unk4c = o.unk4c;
        unk50 = o.unk50;
        unk54 = o.unk54;
        unk58 = o.unk58;
        unk5c = o.unk5c;
        unk60 = o.unk60;
        unk64 = o.unk64;
        unk68 = o.unk68;
        unk6c = o.unk6c;
        unk70 = o.unk70;
        unk74 = o.unk74;
        unk78 = o.unk78;
        unk7c = o.unk7c;
        return *this;
    }
};
struct S_cfe020_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void ReleaseBlock(void* p, int size);
};
void __cdecl FUN_00c909d0(S_cfe020_Heap* heap, void* arr, int elemSize, void* mem, int n);
struct S_cfe020_Blocks
{
    char** data;
    int size;
    int cap;
    int local;
    __forceinline char* back()
    {
        return data[size - 1];
    }
    __forceinline void popBack()
    {
        size--;
    }
    __forceinline void optimize()
    {
        if ((cap & 0x80000000) == 0)
        {
            unsigned int n = size + 3;
            n |= n >> 16;
            n |= n >> 8;
            n |= n >> 4;
            n |= n >> 2;
            n |= n >> 1;
            int newCap = n + 1;
            if (newCap < 1)
            {
                FUN_00c909d0((S_cfe020_Heap*)&FUN_00c85750().heap(), &data, 4, &local, 1);
            }
            else if (newCap < (cap & 0x3fffffff))
            {
                FUN_00c909d0((S_cfe020_Heap*)&FUN_00c85750().heap(), &data, 4, 0, newCap);
            }
        }
    }
};
struct S_cfe020_Pool
{
    int used;
    S_cfe020_Blocks blocks;
};
void FUN_00cfe020(S_cfe020_Pool* pool, S_cfe020_Entry* dest);
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);
struct LinkArray
{
    LinkEntry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    LinkEntry* AddBack()
    {
        CFE820Allocator& alloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(LinkEntry));
        LinkEntry* ret = &m_data[m_iElementCount];
        m_iElementCount++;
        return ret;
    }
};
struct CollidableNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    short unk18;
    char m_type;
    char unk1b;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    LinkArray m_ppLinks;
};
struct Transform;
struct CollidableBody
{
    int unk00;
    int unk04;
    const Transform* m_kMotionTransform;
};
struct __declspec(align(16)) Transform
{
    __m128 column0, column1, column2, translation;
    void __thiscall FUN_00cb22f0(const Transform& t1, const Transform& t2);
};
struct CollisionAgentEntry;
template <typename T> class ValueWrapper
{
  public:
    __forceinline ValueWrapper()
    {}
    __forceinline ValueWrapper(T t) : m_kStorage(t)
    {}
    __forceinline void operator=(T t)
    {
        m_kStorage = t;
    }
    __forceinline operator T() const
    {
        return m_kStorage;
    }
    __forceinline T operator->() const
    {
        return m_kStorage;
    }

  private:
    T m_kStorage;
};
struct AgentInput
{
    ValueWrapper<const CollidableBody*> m_pBodyA;
    ValueWrapper<const CollidableBody*> m_pBodyB;
    ValueWrapper<const CollidableBody*> m_pAdditionalCollidableBody;
    ValueWrapper<void*> m_pRayCastInput;
    ValueWrapper<void*> m_pContactManager;
    Transform m_kTransform;
    AgentInput() : m_pAdditionalCollidableBody(0)
    {}
};
typedef void(__cdecl* AgentCreateFunc)(AgentInput* input, CollisionAgentEntry* entry, void* subEntry);
struct QualityEntry
{
    AgentCreateFunc m_pCreateFunc;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int m_flag28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};
struct Dispatcher
{
    char* m_tableBase;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    void* m_currentAgentEntry;
};
struct CollisionAgentEntry
{
    unsigned char m_flags;
    unsigned char m_iAutoRemoveLevel;
    unsigned char unk02;
    unsigned char m_iElementCount;
    unsigned short m_agentIndexA;
    unsigned short m_agentIndexB;
    void* m_pCurrentSimulationIsland;
    char m_ucNnTrackType;
    char unk0d;
    char unk0e;
    char unk0f;
    CollidableNode* m_nodeA;
    CollidableNode* m_nodeB;
    float m_fTimeOfImpact;
    int unk1c;
    __m128 m_vSeparatingNormal;
};
CollisionAgentEntry* __cdecl FUN_00cfe8a0(CFE820Pool* pool, CollidableNode* nodeA, CollidableBody* bodyA,
                                          CollidableNode* nodeB, CollidableBody* bodyB, unsigned char flags,
                                          int qualityType, Dispatcher* dispatcher, void* island);
__inline __m128 quadZero()
{
    return _mm_setzero_ps();
}
__inline __m128 quadInit()
{
    return quadZero();
}
struct SweptPose
{
    __m128 center0, center1, rotation0, rotation1, localCenter;
};
struct MotionPose
{
    Transform pose;
    SweptPose swept;
    __m128 angle;
    float radius, linearDamping, angularDamping, timeFactor;
    const SweptPose& getSweptTransform() const
    {
        return swept;
    }
};
class PairBody
{
  public:
    const void* shape;
    unsigned key;
    const void* motion;
    const PairBody* parent;
    PairBody()
    {}
    PairBody(const PairBody* p, const Transform* t)
    {
        parent = p;
        motion = t;
    }
    static void* operator new(unsigned, void* p)
    {
        return p;
    }
    static void operator delete(void*, void*)
    {}
    const MotionPose* GetMotionState() const
    {
        return static_cast<const MotionPose*>(motion);
    }
    const void* getShape() const
    {
        return shape;
    }
    unsigned getShapeKey() const
    {
        return key;
    }
    void SetCollisionShapeAndKey(const void* s, unsigned k)
    {
        shape = s;
        key = k;
    }
};
struct StepTimes
{
    ValueWrapper<float> start, end, delta, invDelta;
};
struct PairContext
{
    void* dispatcher;
    int weld;
    float tolerance;
    int unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    StepTimes step;
};
struct PairInput
{
    ValueWrapper<const PairBody*> bodyA, bodyB, overrideA;
    ValueWrapper<const PairContext*> context;
    ValueWrapper<void*> manager;
    Transform relative;
};
struct PairTemporary
{
    PairBody a, b;
    Transform ta, tb;
};
void __cdecl FUN_00cf1510(const SweptPose&, float, Transform&);
static void FUN_00cfde10(PairInput& out, PairInput& in, PairTemporary& temp);
PairInput* volatile pairIn;
PairTemporary* volatile pairTemp;
PairInput* volatile pairOut;
void pairCaller();

extern "C"
{
    __m128 _mm_load_ps(const float*);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_set_ps1(float);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_load_ps1(const float*);

    float _mm_cvtss_f32(__m128);
    void _mm_store_ss(float*, __m128);
    void _ReadBarrier();
    void _ReadWriteBarrier();
    void _WriteBarrier();
    void _ReadWriteBarrier();
    __m128 _mm_move_ss(__m128, __m128);
}

typedef float hkReal;
typedef unsigned char hkUchar;
typedef __m128 hkQuadReal;

class hkSimdRealCFE3
{
  public:
    hkSimdRealCFE3(hkReal x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    hkSimdRealCFE3(const hkQuadReal& x) : m_vValue(x)
    {}
    operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }

  private:
    hkQuadReal m_vValue;
};
typedef const hkSimdRealCFE3& hkSimdRealParameterCFE3;

class hkVector4CFE3
{
  public:
    hkQuadReal m_vComponents;

    inline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    inline void setSub4(const hkVector4CFE3& v0, const hkVector4CFE3& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void setMul4(hkSimdRealParameterCFE3 r, const hkVector4CFE3& v1)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
    }
    inline void addMul4(hkSimdRealParameterCFE3 r, const hkVector4CFE3& v1)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
    }
    inline hkSimdRealCFE3 dot4xyz1(const hkVector4CFE3& a) const
    {
        hkQuadReal linear = _mm_load_ps(reinterpret_cast<const float*>(&m_vComponents));
        hkQuadReal sep = a.m_vComponents;
        hkQuadReal x2 = _mm_mul_ps(linear, sep);
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 85), x2);
        hkQuadReal zwSum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 170), _mm_shuffle_ps(linear, linear, 255));
        return _mm_add_ps(xySum, zwSum);
    }
    inline hkReal& operator()(int a)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[a];
    }
    inline const hkReal& operator()(int a) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
    }
};

class hkTransformCFE3
{
  public:
    hkVector4CFE3 m_kColumn0, m_kColumn1, m_kColumn2, m_vTranslation;
    void FUN_00cb22f0(const hkTransformCFE3& a, const hkTransformCFE3& b);
};

class hkSweptTransformCFE3
{
  public:
    hkVector4CFE3 m_vCenterOfMass0;
    hkVector4CFE3 m_vCenterOfMass1;
    hkVector4CFE3 m_qRotation0;
    hkVector4CFE3 m_qRotation1;
    hkVector4CFE3 m_vCenterOfMassLocal;
    inline hkReal getInvDeltaTime() const
    {
        return m_vCenterOfMass1(3);
    }
};

class hkMotionStateCFE3
{
  public:
    hkTransformCFE3 m_kMotionTransform;
    hkSweptTransformCFE3 m_kSweptTransform;
    hkVector4CFE3 m_kDeltaAngle;
    hkReal m_fObjectRadius;
    hkReal m_fLinearDamping;
    hkReal m_fAngularDamping;
    hkReal m_timeFactor;

    inline const hkTransformCFE3& getTransform() const
    {
        return m_kMotionTransform;
    }
    inline const hkSweptTransformCFE3& getSweptTransform() const
    {
        return m_kSweptTransform;
    }
};

void __cdecl FUN_00cf1510(const hkSweptTransformCFE3& st, hkReal t, hkTransformCFE3& out);

class hkpShapeCFE3;

class hkpCdBodyCFE3
{
  public:
    const hkpShapeCFE3* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyCFE3* m_parent;

    hkpCdBodyCFE3()
    {}
    hkpCdBodyCFE3(const hkpCdBodyCFE3* parent, const hkTransformCFE3* t)
    {
        m_parent = parent;
        m_pMotionState = t;
    }
    inline void* operator new(unsigned int, void* p)
    {
        return p;
    }
    inline void operator delete(void*, void*)
    {}
    inline const hkMotionStateCFE3* GetMotionState() const
    {
        return reinterpret_cast<const hkMotionStateCFE3*>(m_pMotionState);
    }
    inline const hkpShapeCFE3* getShape() const
    {
        return m_pCollisionShape;
    }
    inline unsigned int getShapeKey() const
    {
        return m_uiCollisionShapeKey;
    }
    inline void SetCollisionShapeAndKey(const hkpShapeCFE3* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
};

struct hkpProcessCollisionInputCFE3;
struct hkpProcessCollisionOutputCFE3;
struct hkpAgentNnEntryCFE3;
class hkpContactMgrCFE3;
class hkpConstraintOwnerCFE3;

class hkpCollisionAgentCFE3
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void ProcessAgent(const hkpCdBodyCFE3& bodyA, const hkpCdBodyCFE3& bodyB,
                                  const hkpProcessCollisionInputCFE3& input, hkpProcessCollisionOutputCFE3& result);
};

struct hkpAgent3InputCFE3
{
    hkpAgent3InputCFE3() : m_pAdditionalCollidableBody(0)
    {}
    ValueWrapper<const hkpCdBodyCFE3*> m_pBodyA;
    ValueWrapper<const hkpCdBodyCFE3*> m_pBodyB;
    ValueWrapper<const hkpCdBodyCFE3*> m_pAdditionalCollidableBody;
    ValueWrapper<const hkpProcessCollisionInputCFE3*> m_pRayCastInput;
    ValueWrapper<hkpContactMgrCFE3*> m_pContactManager;
    hkTransformCFE3 m_kTransform;
};

struct hkpAgent3ProcessInputCFE3 : public hkpAgent3InputCFE3
{
    ValueWrapper<hkReal> m_fSubtypeValue;
    hkVector4CFE3 m_vSubtypePosition;
};

typedef void*(__cdecl* hkAgent3CleanupFuncCFE3)(hkpAgentNnEntryCFE3* entry, void* agentData, hkpContactMgrCFE3* mgr,
                                                hkpConstraintOwnerCFE3& owner);
typedef void(__cdecl* hkAgent3SepNormalFuncCFE3)(const hkpAgent3InputCFE3& input, hkpAgentNnEntryCFE3* entry,
                                                 void* agentData, hkVector4CFE3& sepNormalOut);
typedef void*(__cdecl* hkAgent3ProcessFuncCFE3)(const hkpAgent3ProcessInputCFE3& input, hkpAgentNnEntryCFE3* entry,
                                                void* agentData, hkVector4CFE3* separatingNormalOut,
                                                hkpProcessCollisionOutputCFE3& result);

struct hkpAgentFuncsCFE3
{
    void* m_pCreateFunc;
    void* m_pQueryPenetrationsFunc;
    void* m_pGetPenetrationsFunc;
    void* m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

struct __declspec(align(16)) hkpAgent3FuncsInternCFE3
{
    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    hkAgent3CleanupFuncCFE3 m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_pCreateZombieFunc;
    void* m_pUpdateFilterFunc;
    void* m_pCalcStats;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    hkAgent3SepNormalFuncCFE3 m_pAgentFunction7;
    hkAgent3ProcessFuncCFE3 m_pAgentFunction8;
    void* unk30;
    void* unk34;
    void* unk38;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
    int m_eSymmetric;
};

class hkpCollisionDispatcherCFE3
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pAgentRegister;
    void* m_apContactMgrFactoriesByResponsePair[8][8];
    __declspec(align(16)) unsigned int m_auiAlternateTypeFlags[32];
    int m_iEntryCount;
    __declspec(align(16)) hkUchar m_agent2TypeMap[32][32];
    hkUchar m_agent3TypeMap[32][32];
    hkpAgentFuncsCFE3 m_agent2Funcs[64];
    int m_iAgent2FunctionCount;
    __declspec(align(16)) hkUchar m_ucAgent2TypeTable[32][32];
    __declspec(align(16)) hkUchar m_ucAgent3TypeTable[32][32];
    hkpAgent3FuncsInternCFE3 m_kAgent3FunctionTable[16];

    __forceinline hkAgent3CleanupFuncCFE3 getAgent3CleanupFunc(int type)
    {
        return m_kAgent3FunctionTable[type].m_pAgentFunction3;
    }
    __forceinline hkAgent3ProcessFuncCFE3 getAgent3ProcessFunc(int type)
    {
        return m_kAgent3FunctionTable[type].m_pAgentFunction8;
    }
    __forceinline hkAgent3SepNormalFuncCFE3 getAgent3SepNormalFunc(int type)
    {
        return m_kAgent3FunctionTable[type].m_pAgentFunction7;
    }
};

struct hkpCollisionQualityInfoCFE3
{
    int m_fMinimumCollisionSeparation;
    int m_fMinimumExtraSeparation;
    int m_createNormalContact;
    int m_fTimeOfImpactSeparation;
    ValueWrapper<int> m_iQualityInfoValue10;
};

struct hkpStepInfoCFE3
{
    ValueWrapper<hkReal> m_uiStartTime;
    ValueWrapper<hkReal> m_fEndTime;
    ValueWrapper<hkReal> m_fTimeStep;
    ValueWrapper<hkReal> m_fInverseDeltaTime;
};

struct hkpProcessCollisionInputCFE3
{
    ValueWrapper<hkpCollisionDispatcherCFE3*> m_pCollisionDispatcher;
    ValueWrapper<int> m_collisionQuality;
    ValueWrapper<hkReal> m_fScalar;
    int unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    hkpStepInfoCFE3 m_pStepInfo;
    ValueWrapper<hkpCollisionQualityInfoCFE3*> m_pCollisionQualityInfo;

    inline hkReal getTolerance() const
    {
        return m_fScalar;
    }
};

struct hkpProcessCollisionOutputCFE3
{
    int unk00;
    hkpConstraintOwnerCFE3* m_pConstraintOwner;
};

struct hkpAgentNnEntryCFE3
{
    hkUchar m_ucAgentType;
    hkUchar m_ucNnTrackType;
    hkUchar m_usNumContactPoints;
    hkUchar m_iElementCount;
    unsigned short m_ausAgentData[2];
    hkpContactMgrCFE3* m_pContactManager;
    hkUchar m_cAgentType;
    hkUchar m_uiForceCollideOntoPpu;
    hkUchar m_ucHeaderByte;
    hkUchar m_usHeaderWord;
    hkpCdBodyCFE3* m_kCollidable[2];

    inline hkpCdBodyCFE3* getCollidableA()
    {
        return m_kCollidable[0];
    }
    inline hkpCdBodyCFE3* getCollidableB()
    {
        return m_kCollidable[1];
    }
};

struct hkpAgentNnMachinePaddedEntryCFE3 : public hkpAgentNnEntryCFE3
{
    int m_uiRollingFrictionData;
    int m_padding3;
};

struct hkpAgentNnMachineTimEntryCFE3 : public hkpAgentNnEntryCFE3
{
    hkReal m_fFloatValue;
    int unk1c;
    hkVector4CFE3 m_vSeparatingNormal;
};

struct hkAgentNnMachineBodyTempCFE3
{
    hkpCdBodyCFE3 m_pBodyA;
    hkpCdBodyCFE3 m_pBodyB;
    hkTransformCFE3 m_kTransformA;
    hkTransformCFE3 m_kTransformB;
};

void* __cdecl FUN_00cfe1d0(void* h, void* a, void* b, unsigned int n, void* c);

enum
{
    STREAM_CALL_CFE3 = 2,
    STREAM_CALL_WITH_TIM_CFE3 = 4,
    STREAM_CALL_AGENT_CFE3 = 6,
    TRANSFORM_FLAG_CFE3 = 8,
    STREAM_CALL_WITH_TRANSFORM_CFE3 = 10,
    STREAM_CALL_WITH_TIM_WITH_TRANSFORM_CFE3 = 12,
    STREAM_CALL_AGENT_WITH_TRANSFORM_CFE3 = 14
};

static __forceinline void calcTimInfoCFE3(const hkMotionStateCFE3& ms0, const hkMotionStateCFE3& ms1, hkReal deltaTime,
                                          hkVector4CFE3& timOut)
{
    const hkSweptTransformCFE3& st0 = ms0.getSweptTransform();
    const hkSweptTransformCFE3& st1 = ms1.getSweptTransform();

    hkVector4CFE3 diff0;
    diff0.setSub4(st0.m_vCenterOfMass0, st0.m_vCenterOfMass1);
    hkVector4CFE3 diff1;
    diff1.setSub4(st1.m_vCenterOfMass1, st1.m_vCenterOfMass0);

    hkReal f0 = deltaTime * st0.getInvDeltaTime();
    hkReal f1 = deltaTime * st1.getInvDeltaTime();

    timOut.setMul4(f0, diff0);
    timOut.addMul4(f1, diff1);
    timOut(3) = f0 * ms0.m_kDeltaAngle(3) * ms0.m_fObjectRadius + f1 * ms1.m_kDeltaAngle(3) * ms1.m_fObjectRadius;
}

static __forceinline void initInputAtTimeCFE3(hkpAgent3InputCFE3& in, hkAgentNnMachineBodyTempCFE3& bodyTemp,
                                              hkpAgent3InputCFE3& out)
{
    FUN_00cf1510(in.m_pBodyA->GetMotionState()->getSweptTransform(), in.m_pRayCastInput->m_pStepInfo.m_uiStartTime,
                 bodyTemp.m_kTransformA);
    FUN_00cf1510(in.m_pBodyB->GetMotionState()->getSweptTransform(), in.m_pRayCastInput->m_pStepInfo.m_uiStartTime,
                 bodyTemp.m_kTransformB);

    out.m_pBodyA = &bodyTemp.m_pBodyA;
    out.m_pBodyB = &bodyTemp.m_pBodyB;
    out.m_pContactManager = in.m_pContactManager;
    out.m_pRayCastInput = in.m_pRayCastInput;

    bodyTemp.m_pBodyA.SetCollisionShapeAndKey(in.m_pBodyA->getShape(), in.m_pBodyA->getShapeKey());
    bodyTemp.m_pBodyB.SetCollisionShapeAndKey(in.m_pBodyB->getShape(), in.m_pBodyB->getShapeKey());
    new (&bodyTemp.m_pBodyA) hkpCdBodyCFE3(in.m_pBodyA, &bodyTemp.m_kTransformA);
    new (&bodyTemp.m_pBodyB) hkpCdBodyCFE3(in.m_pBodyB, &bodyTemp.m_kTransformB);

    out.m_kTransform.FUN_00cb22f0(bodyTemp.m_kTransformA, bodyTemp.m_kTransformB);
}

extern "C"
{
// @fnv 0x00cfe370
    static __declspec(noinline) void __cdecl FUN_00cfe370(hkpAgentNnEntryCFE3* entry,
                                                          const hkpProcessCollisionInputCFE3& input, int& numTim,
                                                          hkpProcessCollisionOutputCFE3& output, hkpContactMgrCFE3* mgr)
    {
        const hkpCdBodyCFE3* cdBodyA = entry->getCollidableA();
        const hkpCdBodyCFE3* cdBodyB = entry->getCollidableB();

        hkMotionStateCFE3 motionStatesA[4];
        hkMotionStateCFE3 motionStatesB[4];
        hkpCdBodyCFE3 cdBodiesA[4];
        hkpCdBodyCFE3 cdBodiesB[4];

        int command = entry->m_ucAgentType;
    commandSwitch:
        switch (command)
        {
        case STREAM_CALL_WITH_TRANSFORM_CFE3:
        case STREAM_CALL_WITH_TIM_WITH_TRANSFORM_CFE3:
        case STREAM_CALL_AGENT_WITH_TRANSFORM_CFE3: {
            hkUchar dummy;
            cdBodyA = (const hkpCdBodyCFE3*)FUN_00cfe1d0((void*)cdBodyA, cdBodiesA, motionStatesA, 4, &dummy);
            cdBodyB = (const hkpCdBodyCFE3*)FUN_00cfe1d0((void*)cdBodyB, cdBodiesB, motionStatesB, 4, &dummy);
            command = hkUchar(command) & hkUchar(~TRANSFORM_FLAG_CFE3);
            goto commandSwitch;
        }

        case STREAM_CALL_AGENT_CFE3: {
            hkpCollisionAgentCFE3* agent =
                *reinterpret_cast<hkpCollisionAgentCFE3**>(static_cast<hkpAgentNnMachinePaddedEntryCFE3*>(entry) + 1);
            agent->ProcessAgent(*cdBodyA, *cdBodyB, input, output);
            break;
        }

        case STREAM_CALL_CFE3: {
            hkpAgentNnMachinePaddedEntryCFE3* e = static_cast<hkpAgentNnMachinePaddedEntryCFE3*>(entry);
            hkpAgent3ProcessInputCFE3 in3;
            in3.m_pBodyA = cdBodyA;
            in3.m_pBodyB = cdBodyB;
            in3.m_pContactManager = entry->m_pContactManager;
            in3.m_pRayCastInput = &input;

            const hkMotionStateCFE3* msA = in3.m_pBodyA->GetMotionState();
            const hkMotionStateCFE3* msB = in3.m_pBodyB->GetMotionState();
            calcTimInfoCFE3(*msA, *msB, in3.m_pRayCastInput->m_pStepInfo.m_fTimeStep, in3.m_vSubtypePosition);
            in3.m_kTransform.FUN_00cb22f0(msA->getTransform(), msB->getTransform());

            void* agentData = e + 1;
            input.m_pCollisionDispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)(in3, entry, agentData, 0,
                                                                                       output);
            break;
        }

        case STREAM_CALL_WITH_TIM_CFE3: {
            hkpAgentNnMachineTimEntryCFE3* e = static_cast<hkpAgentNnMachineTimEntryCFE3*>(entry);
            hkpAgent3ProcessInputCFE3 in3;
            in3.m_pBodyA = cdBodyA;
            in3.m_pBodyB = cdBodyB;
            in3.m_pContactManager = entry->m_pContactManager;
            in3.m_pRayCastInput = &input;

            const hkMotionStateCFE3* msA = in3.m_pBodyA->GetMotionState();
            const hkMotionStateCFE3* msB = in3.m_pBodyB->GetMotionState();
            calcTimInfoCFE3(*msA, *msB, in3.m_pRayCastInput->m_pStepInfo.m_fTimeStep, in3.m_vSubtypePosition);

            void* agentData = e + 1;
            hkReal dist;
            if (e->m_fFloatValue != input.m_pStepInfo.m_uiStartTime)
            {
                if (!input.m_pCollisionQualityInfo->m_iQualityInfoValue10)
                {
                    e->m_fFloatValue = input.m_pStepInfo.m_fEndTime;
                    dist = -3.40282e+38f;
                    e->m_vSeparatingNormal.setZero4();
                    e->m_vSeparatingNormal(3) = dist;
                    goto PROCESS_AT_T1;
                }
                hkAgentNnMachineBodyTempCFE3 bodyTemp;
                hkpAgent3InputCFE3 in3b;
                initInputAtTimeCFE3(in3, bodyTemp, in3b);
                input.m_pCollisionDispatcher->getAgent3SepNormalFunc(entry->m_ucNnTrackType)(in3b, entry, agentData,
                                                                                             e->m_vSeparatingNormal);
            }

            hkVector4CFE3& vSeparatingNormal = e->m_vSeparatingNormal;
            const hkReal worst = in3.m_vSubtypePosition.dot4xyz1(vSeparatingNormal);
            e->m_fFloatValue = input.m_pStepInfo.m_fEndTime;
            dist = vSeparatingNormal(3) - worst;
            if (dist >= input.getTolerance())
            {
                e->m_vSeparatingNormal(3) = dist;
                if (entry->m_usNumContactPoints)
                {
                    input.m_pCollisionDispatcher->getAgent3CleanupFunc(entry->m_ucNnTrackType)(
                        entry, agentData, in3.m_pContactManager, *output.m_pConstraintOwner);
                }
                numTim++;
                break;
            }
        PROCESS_AT_T1:
            in3.m_fSubtypeValue = dist;
            in3.m_kTransform.FUN_00cb22f0(msA->getTransform(), msB->getTransform());
            input.m_pCollisionDispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)(in3, entry, agentData,
                                                                                       &e->m_vSeparatingNormal, output);
            break;
        }

        default:
            break;
        }
    }
}
void hkAgentNnMachine_ProcessAgentCFE3(hkpAgentNnEntryCFE3* entry, const hkpProcessCollisionInputCFE3& input,
                                       hkpProcessCollisionOutputCFE3& output, hkpContactMgrCFE3* mgr)
{
    int numTim = 0;
    FUN_00cfe370(entry, input, numTim, output, mgr);
}

extern float DAT_0104da48;

extern "C"
{
    void _mm_prefetch(const char*, int);
    __m128 _mm_load_ps(const float*);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_set_ps1(float);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_load_ps1(const float*);

    float _mm_cvtss_f32(__m128);
    void _mm_store_ss(float*, __m128);
    void _ReadBarrier();
    void _ReadWriteBarrier();
    void _WriteBarrier();
    void _ReadWriteBarrier();
    __m128 _mm_move_ss(__m128, __m128);
}

typedef float hkReal;
typedef unsigned char hkUchar;
typedef __m128 hkQuadReal;

class hkSimdRealCFT
{
  public:
    hkSimdRealCFT(hkReal x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    hkSimdRealCFT(const hkQuadReal& x) : m_vValue(x)
    {}
    operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }

  private:
    hkQuadReal m_vValue;
};
typedef const hkSimdRealCFT& hkSimdRealParameterCFT;

class hkVector4CFT
{
  public:
    hkQuadReal m_vComponents;
    __forceinline const hkQuadReal& getQuad() const
    {
        return m_vComponents;
    }

    inline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    inline void setSub4(const hkVector4CFT& v0, const hkVector4CFT& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void setMul4(hkSimdRealParameterCFT r, const hkVector4CFT& v1)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
    }
    inline void addMul4(hkSimdRealParameterCFT r, const hkVector4CFT& v1)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
    }
    inline hkSimdRealCFT dot4xyz1(const hkVector4CFT& a) const
    {
        hkQuadReal linear = _mm_load_ps(reinterpret_cast<const float*>(&m_vComponents));
        hkQuadReal sep = a.m_vComponents;
        hkQuadReal x2 = _mm_mul_ps(linear, sep);
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 85), x2);
        hkQuadReal zwSum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 170), _mm_shuffle_ps(linear, linear, 255));
        return _mm_add_ps(xySum, zwSum);
    }
    inline hkReal& operator()(int a)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[a];
    }
    inline const hkReal& operator()(int a) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
    }
};

class hkTransformCFT
{
  public:
    hkVector4CFT m_kColumn0, m_kColumn1, m_kColumn2, m_vTranslation;
    void FUN_00cb22f0(const hkTransformCFT& a, const hkTransformCFT& b);
    void SetMulInverse(const hkTransformCFT& a, const hkTransformCFT& b)
    {
        FUN_00cb22f0(a, b);
    }
};

class hkSweptTransformCFT
{
  public:
    hkVector4CFT m_vCenterOfMass0;
    hkVector4CFT m_vCenterOfMass1;
    hkVector4CFT m_qRotation0;
    hkVector4CFT m_qRotation1;
    hkVector4CFT m_vCenterOfMassLocal;
    inline hkReal getInvDeltaTime() const
    {
        return m_vCenterOfMass1(3);
    }
};

class hkMotionStateCFT
{
  public:
    hkTransformCFT m_kMotionTransform;
    hkSweptTransformCFT m_kSweptTransform;
    hkVector4CFT m_kDeltaAngle;
    hkReal m_fObjectRadius;
    hkReal m_fLinearDamping;
    hkReal m_fAngularDamping;
    hkReal m_timeFactor;

    inline const hkTransformCFT& getTransform() const
    {
        return m_kMotionTransform;
    }
    inline const hkSweptTransformCFT& getSweptTransform() const
    {
        return m_kSweptTransform;
    }
};

void __cdecl FUN_00cf1510(const hkSweptTransformCFT& st, hkReal t, hkTransformCFT& out);

class hkpShapeCFT;

class hkpCdBodyCFT
{
  public:
    const hkpShapeCFT* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyCFT* m_parent;

    hkpCdBodyCFT()
    {}
    hkpCdBodyCFT(const hkpCdBodyCFT* parent, const hkTransformCFT* t)
    {
        m_parent = parent;
        m_pMotionState = t;
    }
    inline void* operator new(unsigned int, void* p)
    {
        return p;
    }
    inline void operator delete(void*, void*)
    {}
    inline const hkMotionStateCFT* GetMotionState() const
    {
        return reinterpret_cast<const hkMotionStateCFT*>(m_pMotionState);
    }
    inline const hkpShapeCFT* getShape() const
    {
        return m_pCollisionShape;
    }
    inline unsigned int getShapeKey() const
    {
        return m_uiCollisionShapeKey;
    }
    inline void SetCollisionShapeAndKey(const hkpShapeCFT* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
};

struct hkpProcessCollisionInputCFT;
struct hkpProcessCollisionOutputCFT;
struct hkpAgentNnEntryCFT;
class hkpContactMgrCFT;
class hkpConstraintOwnerCFT;

class hkpCollisionAgentCFT
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void ProcessAgent(const hkpCdBodyCFT& bodyA, const hkpCdBodyCFT& bodyB,
                                  const hkpProcessCollisionInputCFT& input, hkpProcessCollisionOutputCFT& result);
};

struct hkpAgent3InputCFT
{
    hkpAgent3InputCFT() : m_pAdditionalCollidableBody(0)
    {}
    ValueWrapper<const hkpCdBodyCFT*> m_pBodyA;
    ValueWrapper<const hkpCdBodyCFT*> m_pBodyB;
    ValueWrapper<const hkpCdBodyCFT*> m_pAdditionalCollidableBody;
    ValueWrapper<const hkpProcessCollisionInputCFT*> m_pRayCastInput;
    ValueWrapper<hkpContactMgrCFT*> m_pContactManager;
    hkTransformCFT m_kTransform;
};

struct hkpAgent3ProcessInputCFT : public hkpAgent3InputCFT
{
    ValueWrapper<hkReal> m_fSubtypeValue;
    hkVector4CFT m_vSubtypePosition;
};

typedef void*(__cdecl* hkAgent3CleanupFuncCFT)(hkpAgentNnEntryCFT* entry, void* agentData, hkpContactMgrCFT* mgr,
                                               hkpConstraintOwnerCFT& owner);
typedef void(__cdecl* hkAgent3SepNormalFuncCFT)(const hkpAgent3InputCFT& input, hkpAgentNnEntryCFT* entry,
                                                void* agentData, hkVector4CFT& sepNormalOut);
typedef void*(__cdecl* hkAgent3ProcessFuncCFT)(const hkpAgent3ProcessInputCFT& input, hkpAgentNnEntryCFT* entry,
                                               void* agentData, hkVector4CFT* separatingNormalOut,
                                               hkpProcessCollisionOutputCFT& result);

struct hkpAgentFuncsCFT
{
    void* m_pCreateFunc;
    void* m_pQueryPenetrationsFunc;
    void* m_pGetPenetrationsFunc;
    void* m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

struct __declspec(align(16)) hkpAgent3FuncsInternCFT
{
    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    hkAgent3CleanupFuncCFT m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_pCreateZombieFunc;
    void* m_pUpdateFilterFunc;
    void* m_pCalcStats;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    hkAgent3SepNormalFuncCFT m_pAgentFunction7;
    hkAgent3ProcessFuncCFT m_pAgentFunction8;
    void* unk30;
    void* unk34;
    void* unk38;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
    int m_eSymmetric;
};

class hkpCollisionDispatcherCFT
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pAgentRegister;
    void* m_apContactMgrFactoriesByResponsePair[8][8];
    __declspec(align(16)) unsigned int m_auiAlternateTypeFlags[32];
    int m_iEntryCount;
    __declspec(align(16)) hkUchar m_agent2TypeMap[32][32];
    hkUchar m_agent3TypeMap[32][32];
    hkpAgentFuncsCFT m_agent2Funcs[64];
    int m_iAgent2FunctionCount;
    __declspec(align(16)) hkUchar m_ucAgent2TypeTable[32][32];
    __declspec(align(16)) hkUchar m_ucAgent3TypeTable[32][32];
    hkpAgent3FuncsInternCFT m_kAgent3FunctionTable[16];

    __forceinline hkAgent3CleanupFuncCFT getAgent3CleanupFunc(int type)
    {
        return m_kAgent3FunctionTable[type].m_pAgentFunction3;
    }
    __forceinline hkAgent3ProcessFuncCFT getAgent3ProcessFunc(int type)
    {
        return m_kAgent3FunctionTable[type].m_pAgentFunction8;
    }
    __forceinline hkAgent3SepNormalFuncCFT getAgent3SepNormalFunc(int type)
    {
        return m_kAgent3FunctionTable[type].m_pAgentFunction7;
    }
};

struct hkpCollisionQualityInfoCFT
{
    int m_fMinimumCollisionSeparation;
    int m_fMinimumExtraSeparation;
    int m_createNormalContact;
    int m_fTimeOfImpactSeparation;
    ValueWrapper<int> m_iQualityInfoValue10;
};

struct hkpStepInfoCFT
{
    ValueWrapper<hkReal> m_uiStartTime;
    ValueWrapper<hkReal> m_fEndTime;
    ValueWrapper<hkReal> m_fTimeStep;
    ValueWrapper<hkReal> m_fInverseDeltaTime;
};

struct hkpProcessCollisionInputCFT
{
    ValueWrapper<hkpCollisionDispatcherCFT*> m_pCollisionDispatcher;
    ValueWrapper<int> m_collisionQuality;
    ValueWrapper<hkReal> m_fScalar;
    int unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    hkpStepInfoCFT m_pStepInfo;
    ValueWrapper<hkpCollisionQualityInfoCFT*> m_pCollisionQualityInfo;

    inline hkReal getTolerance() const
    {
        return m_fScalar;
    }
};

struct TrackContact
{
    hkVector4CFT position, normal;
    int id, unk24, unk28, unk2c;
};
struct TrackProperties
{
    float appliedImpulse, internalSolver;
    int material, internalData;
    unsigned int extendedData[7];
    int unk2c;
    TrackProperties() : appliedImpulse(0.0f), internalSolver(0.0f)
    {}
};
struct TrackToi
{
    hkVector4CFT position, normal;
    ValueWrapper<float> time;
    float separationVelocity;
    int unk28, unk2c;
    int cache0, cache1, cache2, cache3;
    TrackProperties properties;
    TrackToi() : time(DAT_0104da48)
    {}
};
struct hkpProcessCollisionOutputCFT
{
    ValueWrapper<TrackContact*> m_pAlignedPairData;
    ValueWrapper<hkpConstraintOwnerCFT*> m_pConstraintOwner;
    int unk08, unk0c;
    TrackContact m_akContactPoints[256];
    TrackToi m_fTimeOfImpact;
    ValueWrapper<void*> m_akContactRecords;
    int unk3074, unk3078, unk307c;
    hkpProcessCollisionOutputCFT(hkpConstraintOwnerCFT* owner)
    {
        m_pConstraintOwner = owner;
    }
    __forceinline void reset()
    {
        m_pAlignedPairData = &m_akContactPoints[0];
        m_fTimeOfImpact.time = DAT_0104da48;
        m_akContactRecords = 0;
    }
    __forceinline bool isEmpty() const
    {
        return (TrackContact*)m_pAlignedPairData == &m_akContactPoints[0];
    }
};

class TrackCollidable : public hkpCdBodyCFT
{
};
struct hkpAgentNnEntryCFT
{
    hkUchar m_ucAgentType;
    hkUchar m_ucNnTrackType;
    hkUchar m_usNumContactPoints;
    hkUchar m_iElementCount;
    unsigned short m_ausAgentData[2];
    hkpContactMgrCFT* m_pContactManager;
    hkUchar m_cAgentType;
    hkUchar m_uiForceCollideOntoPpu;
    hkUchar m_ucHeaderByte;
    hkUchar m_usHeaderWord;
    hkpCdBodyCFT* m_kCollidable[2];

    inline TrackCollidable* getCollidableA()
    {
        return reinterpret_cast<TrackCollidable*>(m_kCollidable[0]);
    }
    inline TrackCollidable* getCollidableB()
    {
        return reinterpret_cast<TrackCollidable*>(m_kCollidable[1]);
    }
};

struct hkpAgentNnMachinePaddedEntryCFT : public hkpAgentNnEntryCFT
{
    int m_uiRollingFrictionData;
    int m_padding3;
};

struct hkpAgentNnMachineTimEntryCFT : public hkpAgentNnEntryCFT
{
    hkReal m_fFloatValue;
    int unk1c;
    hkVector4CFT m_vSeparatingNormal;
};

struct hkAgentNnMachineBodyTempCFT
{
    hkpCdBodyCFT m_pBodyA;
    hkpCdBodyCFT m_pBodyB;
    hkTransformCFT m_kTransformA;
    hkTransformCFT m_kTransformB;
};

void* __cdecl FUN_00cfe1d0(void* h, void* a, void* b, unsigned int n, void* c);

enum
{
    STREAM_CALL_CFT = 2,
    STREAM_CALL_WITH_TIM_CFT = 4,
    STREAM_CALL_AGENT_CFT = 6,
    TRANSFORM_FLAG_CFT = 8,
    STREAM_CALL_WITH_TRANSFORM_CFT = 10,
    STREAM_CALL_WITH_TIM_WITH_TRANSFORM_CFT = 12,
    STREAM_CALL_AGENT_WITH_TRANSFORM_CFT = 14
};

class hkpContactMgrCFT
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void processContact(const hkpCdBodyCFT&, const hkpCdBodyCFT&, const hkpProcessCollisionInputCFT&,
                                hkpProcessCollisionOutputCFT&);
};
struct TrackSector
{
    unsigned char data[512];
    hkpAgentNnEntryCFT* getBegin()
    {
        return reinterpret_cast<hkpAgentNnEntryCFT*>(&data[0]);
    }
    hkpAgentNnEntryCFT* GetStreamEnd()
    {
        return reinterpret_cast<hkpAgentNnEntryCFT*>(&data[512]);
    }
};
struct TrackSectorArray
{
    TrackSector** data;
    int count;
    int capacity;
    TrackSector* local;
    __forceinline int GetLogicalSize() const
    {
        return count;
    }
    __forceinline TrackSector*& operator[](int n)
    {
        return data[n];
    }
};
struct TrackSectors
{
    unsigned int bytesUsed;
    TrackSectorArray sectors;
};
struct TrackMonitor
{
    char* start;
    char* end;
    char* capacity;
    char* limit;
};
extern unsigned int DAT_0126835c;
extern unsigned int DAT_01269200;
extern const float DAT_0104e148 = -3.40282e+38f;
extern const char DAT_010cc9d0[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int);
struct PreviousBodies
{
    hkpCdBodyCFT a, b;
    hkTransformCFT ta, tb;
};
static __forceinline void fillPrevious(const hkpAgent3InputCFT& current, PreviousBodies& b, hkpAgent3InputCFT& previous)
{
    FUN_00cf1510(current.m_pBodyA->GetMotionState()->getSweptTransform(),
                 current.m_pRayCastInput->m_pStepInfo.m_uiStartTime, b.ta);
    FUN_00cf1510(current.m_pBodyB->GetMotionState()->getSweptTransform(),
                 current.m_pRayCastInput->m_pStepInfo.m_uiStartTime, b.tb);
    previous.m_pBodyA = &b.a;
    previous.m_pBodyB = &b.b;
    previous.m_pContactManager = current.m_pContactManager;
    previous.m_pRayCastInput = current.m_pRayCastInput;
    b.a.SetCollisionShapeAndKey(current.m_pBodyA->getShape(), current.m_pBodyA->getShapeKey());
    b.b.SetCollisionShapeAndKey(current.m_pBodyB->getShape(), current.m_pBodyB->getShapeKey());
    new (&b.a) hkpCdBodyCFT(current.m_pBodyA, &b.ta);
    new (&b.b) hkpCdBodyCFT(current.m_pBodyB, &b.tb);
    previous.m_kTransform.SetMulInverse(b.ta, b.tb);
}
static __forceinline void motionDelta(const hkMotionStateCFT& a, const hkMotionStateCFT& b, hkReal dt,
                                      hkVector4CFT& out)
{
    hkVector4CFT da, db;
    da.setSub4(a.getSweptTransform().m_vCenterOfMass0, a.getSweptTransform().m_vCenterOfMass1);
    db.setSub4(b.getSweptTransform().m_vCenterOfMass1, b.getSweptTransform().m_vCenterOfMass0);
    hkReal fa = dt * a.getSweptTransform().getInvDeltaTime();
    hkReal fb = dt * b.getSweptTransform().getInvDeltaTime();
    out.setMul4(fa, da);
    out.addMul4(fb, db);
    out(3) = fa * a.m_kDeltaAngle(3) * a.m_fObjectRadius + fb * b.m_kDeltaAngle(3) * b.m_fObjectRadius;
}
static __forceinline void processEntry(hkpAgentNnEntryCFT* e, const hkpProcessCollisionInputCFT& context, int& skipped,
                                       hkpProcessCollisionOutputCFT& out)
{
    const hkpCdBodyCFT* a = e->getCollidableA();
    const hkpCdBodyCFT* b = e->getCollidableB();
    hkMotionStateCFT ma[4], mb[4];
    hkpCdBodyCFT ba[4], bb[4];
    int cmd = e->m_ucAgentType;
again:
    switch (cmd)
    {
    case 10:
    case 12:
    case 14: {
        ValueWrapper<hkUchar> transformed;
        a = (const hkpCdBodyCFT*)FUN_00cfe1d0((void*)a, ba, ma, 4, &transformed);
        b = (const hkpCdBodyCFT*)FUN_00cfe1d0((void*)b, bb, mb, 4, &transformed);
        cmd = hkUchar(cmd) & hkUchar(~8);
        goto again;
    }
    case 6: {
        hkpCollisionAgentCFT* agent =
            *reinterpret_cast<hkpCollisionAgentCFT**>(static_cast<hkpAgentNnMachinePaddedEntryCFT*>(e) + 1);
        agent->ProcessAgent(*a, *b, context, out);
        break;
    }
    case 2: {
        hkpAgent3ProcessInputCFT query;
        query.m_pBodyA = a;
        query.m_pBodyB = b;
        query.m_pContactManager = e->m_pContactManager;
        query.m_pRayCastInput = &context;
        const hkMotionStateCFT* am = query.m_pBodyA->GetMotionState();
        const hkMotionStateCFT* bm = query.m_pBodyB->GetMotionState();
        motionDelta(*am, *bm, query.m_pRayCastInput->m_pStepInfo.m_fTimeStep, query.m_vSubtypePosition);
        query.m_kTransform.SetMulInverse(am->getTransform(), bm->getTransform());
        context.m_pCollisionDispatcher->getAgent3ProcessFunc(e->m_ucNnTrackType)(
            query, e, static_cast<hkpAgentNnMachinePaddedEntryCFT*>(e) + 1, 0, out);
        break;
    }
    case 4: {
        hkpAgentNnMachineTimEntryCFT* timed = static_cast<hkpAgentNnMachineTimEntryCFT*>(e);
        hkpAgent3ProcessInputCFT query;
        query.m_pBodyA = a;
        query.m_pBodyB = b;
        query.m_pContactManager = e->m_pContactManager;
        query.m_pRayCastInput = &context;
        const hkMotionStateCFT* am = query.m_pBodyA->GetMotionState();
        const hkMotionStateCFT* bm = query.m_pBodyB->GetMotionState();
        motionDelta(*am, *bm, query.m_pRayCastInput->m_pStepInfo.m_fTimeStep, query.m_vSubtypePosition);
        void* data = timed + 1;
        hkReal distance;
        if (timed->m_fFloatValue != context.m_pStepInfo.m_uiStartTime)
        {
            if (!context.m_pCollisionQualityInfo->m_iQualityInfoValue10)
            {
                timed->m_fFloatValue = context.m_pStepInfo.m_fEndTime;
                distance = -3.40282e+38f;
                timed->m_vSeparatingNormal.setZero4();
                timed->m_vSeparatingNormal(3) = distance;
                goto collide;
            }
            PreviousBodies bodies;
            hkpAgent3InputCFT previous;
            fillPrevious(query, bodies, previous);
            context.m_pCollisionDispatcher->getAgent3SepNormalFunc(e->m_ucNnTrackType)(previous, e, data,
                                                                                       timed->m_vSeparatingNormal);
        }
        {
            hkVector4CFT& normal = timed->m_vSeparatingNormal;
            __m128 velocity = _mm_load_ps(&query.m_vSubtypePosition(0));
            __m128 product = _mm_mul_ps(normal.getQuad(), velocity);
            __m128 z = _mm_shuffle_ps(product, product, 170);
            __m128 w = _mm_shuffle_ps(velocity, velocity, 255);
            __m128 y = _mm_shuffle_ps(product, product, 85);
            __m128 zw = _mm_add_ss(z, w);
            __m128 xy = _mm_add_ss(y, product);
            __m128 total = _mm_add_ps(zw, xy);
            hkReal movement;
            _mm_store_ss(&movement, total);
            timed->m_fFloatValue = context.m_pStepInfo.m_fEndTime;
            distance = normal(3) - movement;
            if (distance >= context.getTolerance())
            {
                timed->m_vSeparatingNormal(3) = distance;
                if (e->m_usNumContactPoints)
                    context.m_pCollisionDispatcher->getAgent3CleanupFunc(e->m_ucNnTrackType)(
                        e, data, query.m_pContactManager, *out.m_pConstraintOwner);
                ++skipped;
                break;
            }
        }
    collide:
        query.m_fSubtypeValue = distance;
        query.m_kTransform.SetMulInverse(am->getTransform(), bm->getTransform());
        context.m_pCollisionDispatcher->getAgent3ProcessFunc(e->m_ucNnTrackType)(query, e, data,
                                                                                 &timed->m_vSeparatingNormal, out);
        break;
    }
    }
}
// @fnv 0x00cff3c0
void __cdecl FUN_00cff3c0(hkpConstraintOwnerCFT* owner, TrackSectors& track, const hkpProcessCollisionInputCFT& context)
{
    int skipped = 0;
    hkpProcessCollisionOutputCFT result(owner);
    for (int index = 0; index < track.sectors.GetLogicalSize();)
    {
        TrackSector* sector = track.sectors[index];
        hkpAgentNnEntryCFT* entry = sector->getBegin();
        ++index;
        hkpAgentNnEntryCFT* end = (index == track.sectors.GetLogicalSize())
                                      ? (hkpAgentNnEntryCFT*)((char*)entry + track.bytesUsed)
                                      : sector->GetStreamEnd();
        for (; entry < end; entry = (hkpAgentNnEntryCFT*)((char*)entry + entry->m_iElementCount))
        {
            TrackCollidable* a = entry->getCollidableA();
            TrackCollidable* b = entry->getCollidableB();
            result.reset();
            _mm_prefetch((const char*)entry + 128, 0);
            _mm_prefetch((const char*)entry->m_pContactManager, 0);
            processEntry(entry, context, skipped, result);
            if (DAT_01269200 == 1)
                return;
            if (!result.isEmpty())
                entry->m_pContactManager->processContact(*a, *b, context, result);
        }
    }
    TrackMonitor& stream = *(TrackMonitor*)TlsGetValue(DAT_0126835c);
    char* cur = stream.end;
    if (cur < stream.limit)
    {
        *(const char**)cur = DAT_010cc9d0;
        *(float*)(cur + 4) = float(skipped);
        stream.end = cur + 8;
    }
}

namespace ProcessAgentCFEDD0 {

extern "C"
{
    ::__m128 _mm_load_ps(const float*);
    ::__m128 _mm_sub_ps(::__m128, ::__m128);
    ::__m128 _mm_mul_ps(::__m128, ::__m128);
    ::__m128 _mm_add_ps(::__m128, ::__m128);
    ::__m128 _mm_add_ss(::__m128, ::__m128);
    ::__m128 _mm_shuffle_ps(::__m128, ::__m128, int);
    ::__m128 _mm_load_ss(const float*);

    void _mm_store_ss(float*, ::__m128);
}

typedef float hkReal;
typedef unsigned char hkUchar;
typedef ::__m128 hkQuadReal;

class hkSimdRealProcessAgentCFEDD0
{
  public:
    hkSimdRealProcessAgentCFEDD0(hkReal x)
    {
        m_vValue = ProcessAgentCFEDD0::_mm_load_ss(&x);
    }
    hkSimdRealProcessAgentCFEDD0(const hkQuadReal& x) : m_vValue(x)
    {}
    operator hkReal() const
    {
        hkReal s;
        ProcessAgentCFEDD0::_mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline hkQuadReal broadcast() const
    {
        return ProcessAgentCFEDD0::_mm_shuffle_ps(m_vValue, m_vValue, 0);
    }

  private:
    hkQuadReal m_vValue;
};
typedef const hkSimdRealProcessAgentCFEDD0& hkSimdRealParameterProcessAgentCFEDD0;

class hkVector4ProcessAgentCFEDD0
{
  public:
    hkQuadReal m_vComponents;

    inline void setZero4()
    {
        m_vComponents = ::_mm_setzero_ps();
    }
    inline void setSub4(const hkVector4ProcessAgentCFEDD0& v0, const hkVector4ProcessAgentCFEDD0& v1)
    {
        m_vComponents = ProcessAgentCFEDD0::_mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void setMul4(hkSimdRealParameterProcessAgentCFEDD0 r, const hkVector4ProcessAgentCFEDD0& v1)
    {
        m_vComponents = ProcessAgentCFEDD0::_mm_mul_ps(r.broadcast(), v1.m_vComponents);
    }
    inline void addMul4(hkSimdRealParameterProcessAgentCFEDD0 r, const hkVector4ProcessAgentCFEDD0& v1)
    {
        m_vComponents = ProcessAgentCFEDD0::_mm_add_ps(m_vComponents,
                                                       ProcessAgentCFEDD0::_mm_mul_ps(r.broadcast(), v1.m_vComponents));
    }
    inline hkSimdRealProcessAgentCFEDD0 dot4xyz1(const hkVector4ProcessAgentCFEDD0& a) const
    {
        hkQuadReal linear = ProcessAgentCFEDD0::_mm_load_ps(reinterpret_cast<const float*>(&m_vComponents));
        hkQuadReal sep = a.m_vComponents;
        hkQuadReal x2 = ProcessAgentCFEDD0::_mm_mul_ps(linear, sep);
        hkQuadReal xySum = ProcessAgentCFEDD0::_mm_add_ss(ProcessAgentCFEDD0::_mm_shuffle_ps(x2, x2, 85), x2);
        hkQuadReal zwSum = ProcessAgentCFEDD0::_mm_add_ss(ProcessAgentCFEDD0::_mm_shuffle_ps(x2, x2, 170),
                                                          ProcessAgentCFEDD0::_mm_shuffle_ps(linear, linear, 255));
        return ProcessAgentCFEDD0::_mm_add_ps(xySum, zwSum);
    }
    inline hkReal& operator()(int a)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[a];
    }
    inline const hkReal& operator()(int a) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
    }
};

class hkTransformProcessAgentCFEDD0
{
  public:
    hkVector4ProcessAgentCFEDD0 m_kColumn0, m_kColumn1, m_kColumn2, m_vTranslation;
    void FUN_00cb22f0(const hkTransformProcessAgentCFEDD0& a, const hkTransformProcessAgentCFEDD0& b);
};

class hkSweptTransformProcessAgentCFEDD0
{
  public:
    hkVector4ProcessAgentCFEDD0 m_vCenterOfMass0;
    hkVector4ProcessAgentCFEDD0 m_vCenterOfMass1;
    hkVector4ProcessAgentCFEDD0 m_qRotation0;
    hkVector4ProcessAgentCFEDD0 m_qRotation1;
    hkVector4ProcessAgentCFEDD0 m_vCenterOfMassLocal;
    inline hkReal getInvDeltaTime() const
    {
        return m_vCenterOfMass1(3);
    }
};

class hkMotionStateProcessAgentCFEDD0
{
  public:
    hkTransformProcessAgentCFEDD0 m_kMotionTransform;
    hkSweptTransformProcessAgentCFEDD0 m_kSweptTransform;
    hkVector4ProcessAgentCFEDD0 m_kDeltaAngle;
    hkReal m_fObjectRadius;
    hkReal m_fLinearDamping;
    hkReal m_fAngularDamping;
    hkReal m_timeFactor;

    inline const hkTransformProcessAgentCFEDD0& getTransform() const
    {
        return m_kMotionTransform;
    }
    inline const hkSweptTransformProcessAgentCFEDD0& getSweptTransform() const
    {
        return m_kSweptTransform;
    }
};

void __cdecl FUN_00cf1510(const hkSweptTransformProcessAgentCFEDD0& st, hkReal t, hkTransformProcessAgentCFEDD0& out);

class hkpShapeProcessAgentCFEDD0;

class hkpCdBodyProcessAgentCFEDD0
{
  public:
    const hkpShapeProcessAgentCFEDD0* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyProcessAgentCFEDD0* m_parent;

    hkpCdBodyProcessAgentCFEDD0()
    {}
    hkpCdBodyProcessAgentCFEDD0(const hkpCdBodyProcessAgentCFEDD0* parent, const hkTransformProcessAgentCFEDD0* t)
    {
        m_parent = parent;
        m_pMotionState = t;
    }
    inline void* operator new(unsigned int, void* p)
    {
        return p;
    }
    inline void operator delete(void*, void*)
    {}
    inline const hkMotionStateProcessAgentCFEDD0* GetMotionState() const
    {
        return reinterpret_cast<const hkMotionStateProcessAgentCFEDD0*>(m_pMotionState);
    }
    inline const hkpShapeProcessAgentCFEDD0* getShape() const
    {
        return m_pCollisionShape;
    }
    inline unsigned int getShapeKey() const
    {
        return m_uiCollisionShapeKey;
    }
    inline void SetCollisionShapeAndKey(const hkpShapeProcessAgentCFEDD0* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
};

struct hkpProcessCollisionInputProcessAgentCFEDD0;
struct hkpProcessCollisionOutputProcessAgentCFEDD0;
struct hkpAgentNnEntryProcessAgentCFEDD0;
class hkpContactMgrProcessAgentCFEDD0;
class hkpConstraintOwnerProcessAgentCFEDD0;

class hkpCollisionAgentProcessAgentCFEDD0
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void ProcessAgent(const hkpCdBodyProcessAgentCFEDD0& bodyA, const hkpCdBodyProcessAgentCFEDD0& bodyB,
                                  const hkpProcessCollisionInputProcessAgentCFEDD0& input,
                                  hkpProcessCollisionOutputProcessAgentCFEDD0& result);
};

struct hkpAgent3InputProcessAgentCFEDD0
{
    hkpAgent3InputProcessAgentCFEDD0() : m_pAdditionalCollidableBody(0)
    {}
    ValueWrapper<const hkpCdBodyProcessAgentCFEDD0*> m_pBodyA;
    ValueWrapper<const hkpCdBodyProcessAgentCFEDD0*> m_pBodyB;
    ValueWrapper<const hkpCdBodyProcessAgentCFEDD0*> m_pAdditionalCollidableBody;
    ValueWrapper<const hkpProcessCollisionInputProcessAgentCFEDD0*> m_pRayCastInput;
    ValueWrapper<hkpContactMgrProcessAgentCFEDD0*> m_pContactManager;
    hkTransformProcessAgentCFEDD0 m_kTransform;
};

struct hkpAgent3ProcessInputProcessAgentCFEDD0 : public hkpAgent3InputProcessAgentCFEDD0
{
    ValueWrapper<hkReal> m_fSubtypeValue;
    hkVector4ProcessAgentCFEDD0 m_vSubtypePosition;
};

typedef void*(__cdecl* hkAgent3CleanupFuncProcessAgentCFEDD0)(hkpAgentNnEntryProcessAgentCFEDD0* entry, void* agentData,
                                                              hkpContactMgrProcessAgentCFEDD0* mgr,
                                                              hkpConstraintOwnerProcessAgentCFEDD0& owner);
typedef void(__cdecl* hkAgent3SepNormalFuncProcessAgentCFEDD0)(const hkpAgent3InputProcessAgentCFEDD0& input,
                                                               hkpAgentNnEntryProcessAgentCFEDD0* entry,
                                                               void* agentData,
                                                               hkVector4ProcessAgentCFEDD0& sepNormalOut);
typedef void*(__cdecl* hkAgent3ProcessFuncProcessAgentCFEDD0)(const hkpAgent3ProcessInputProcessAgentCFEDD0& input,
                                                              hkpAgentNnEntryProcessAgentCFEDD0* entry, void* agentData,
                                                              hkVector4ProcessAgentCFEDD0* separatingNormalOut,
                                                              hkpProcessCollisionOutputProcessAgentCFEDD0& result);

struct hkpAgentFuncsProcessAgentCFEDD0
{
    void* m_pCreateFunc;
    void* m_pQueryPenetrationsFunc;
    void* m_pGetPenetrationsFunc;
    void* m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

struct __declspec(align(16)) hkpAgent3FuncsInternProcessAgentCFEDD0
{
    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    hkAgent3CleanupFuncProcessAgentCFEDD0 m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_pCreateZombieFunc;
    void* m_pUpdateFilterFunc;
    void* m_pCalcStats;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    hkAgent3SepNormalFuncProcessAgentCFEDD0 m_pAgentFunction7;
    hkAgent3ProcessFuncProcessAgentCFEDD0 m_pAgentFunction8;
    void* unk30;
    void* unk34;
    void* unk38;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
    int m_eSymmetric;
};

class hkpCollisionDispatcherProcessAgentCFEDD0
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pAgentRegister;
    void* m_apContactMgrFactoriesByResponsePair[8][8];
    __declspec(align(16)) unsigned int m_auiAlternateTypeFlags[32];
    int m_iEntryCount;
    __declspec(align(16)) hkUchar m_agent2TypeMap[32][32];
    hkUchar m_agent3TypeMap[32][32];
    hkpAgentFuncsProcessAgentCFEDD0 m_agent2Funcs[64];
    int m_iAgent2FunctionCount;
    __declspec(align(16)) hkUchar m_ucAgent2TypeTable[32][32];
    __declspec(align(16)) hkUchar m_ucAgent3TypeTable[32][32];
    hkpAgent3FuncsInternProcessAgentCFEDD0 m_kAgent3FunctionTable[16];

    __forceinline hkAgent3CleanupFuncProcessAgentCFEDD0 getAgent3CleanupFunc(int type)
    {
        return m_kAgent3FunctionTable[type].m_pAgentFunction3;
    }
    __forceinline hkAgent3ProcessFuncProcessAgentCFEDD0 getAgent3ProcessFunc(int type)
    {
        return m_kAgent3FunctionTable[type].m_pAgentFunction8;
    }
    __forceinline hkAgent3SepNormalFuncProcessAgentCFEDD0 getAgent3SepNormalFunc(int type)
    {
        return m_kAgent3FunctionTable[type].m_pAgentFunction7;
    }
};

struct hkpCollisionQualityInfoProcessAgentCFEDD0
{
    int m_fMinimumCollisionSeparation;
    int m_fMinimumExtraSeparation;
    int m_createNormalContact;
    int m_fTimeOfImpactSeparation;
    ValueWrapper<int> m_iQualityInfoValue10;
};

struct hkpStepInfoProcessAgentCFEDD0
{
    ValueWrapper<hkReal> m_uiStartTime;
    ValueWrapper<hkReal> m_fEndTime;
    ValueWrapper<hkReal> m_fTimeStep;
    ValueWrapper<hkReal> m_fInverseDeltaTime;
};

struct hkpProcessCollisionInputProcessAgentCFEDD0
{
    ValueWrapper<hkpCollisionDispatcherProcessAgentCFEDD0*> m_pCollisionDispatcher;
    ValueWrapper<int> m_collisionQuality;
    ValueWrapper<hkReal> m_fScalar;
    int unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    hkpStepInfoProcessAgentCFEDD0 m_pStepInfo;
    ValueWrapper<hkpCollisionQualityInfoProcessAgentCFEDD0*> m_pCollisionQualityInfo;

    inline hkReal getTolerance() const
    {
        return m_fScalar;
    }
};

struct hkpProcessCollisionOutputProcessAgentCFEDD0
{
    int unk00;
    hkpConstraintOwnerProcessAgentCFEDD0* m_pConstraintOwner;
};

struct hkpAgentNnEntryProcessAgentCFEDD0
{
    hkUchar m_ucAgentType;
    hkUchar m_ucNnTrackType;
    hkUchar m_usNumContactPoints;
    hkUchar m_iElementCount;
    unsigned short m_ausAgentData[2];
    hkpContactMgrProcessAgentCFEDD0* m_pContactManager;
    hkUchar m_cAgentType;
    hkUchar m_uiForceCollideOntoPpu;
    hkUchar m_ucHeaderByte;
    hkUchar m_usHeaderWord;
    hkpCdBodyProcessAgentCFEDD0* m_kCollidable[2];

    inline hkpCdBodyProcessAgentCFEDD0* getCollidableA()
    {
        return m_kCollidable[0];
    }
    inline hkpCdBodyProcessAgentCFEDD0* getCollidableB()
    {
        return m_kCollidable[1];
    }
};

struct hkpAgentNnMachinePaddedEntryProcessAgentCFEDD0 : public hkpAgentNnEntryProcessAgentCFEDD0
{
    int m_uiRollingFrictionData;
    int m_padding3;
};

struct hkpAgentNnMachineTimEntryProcessAgentCFEDD0 : public hkpAgentNnEntryProcessAgentCFEDD0
{
    hkReal m_fFloatValue;
    int unk1c;
    hkVector4ProcessAgentCFEDD0 m_vSeparatingNormal;
};

struct hkAgentNnMachineBodyTempProcessAgentCFEDD0
{
    hkpCdBodyProcessAgentCFEDD0 m_pBodyA;
    hkpCdBodyProcessAgentCFEDD0 m_pBodyB;
    hkTransformProcessAgentCFEDD0 m_kTransformA;
    hkTransformProcessAgentCFEDD0 m_kTransformB;
};

void* __cdecl FUN_00cfe1d0(void* h, void* a, void* b, unsigned int n, void* c);

enum
{
    STREAM_CALL_ProcessAgentCFEDD0 = 2,
    STREAM_CALL_WITH_TIM_ProcessAgentCFEDD0 = 4,
    STREAM_CALL_AGENT_ProcessAgentCFEDD0 = 6,
    TRANSFORM_FLAG_ProcessAgentCFEDD0 = 8,
    STREAM_CALL_WITH_TRANSFORM_ProcessAgentCFEDD0 = 10,
    STREAM_CALL_WITH_TIM_WITH_TRANSFORM_ProcessAgentCFEDD0 = 12,
    STREAM_CALL_AGENT_WITH_TRANSFORM_ProcessAgentCFEDD0 = 14
};

static __forceinline void timedEstimateProcessAgentCFEDD0(const hkMotionStateProcessAgentCFEDD0& a,
                                                          const hkMotionStateProcessAgentCFEDD0& b, float dt,
                                                          hkVector4ProcessAgentCFEDD0& out, float& sb)
{
    hkVector4ProcessAgentCFEDD0 da, db;
    da.setSub4(a.m_kSweptTransform.m_vCenterOfMass0, a.m_kSweptTransform.m_vCenterOfMass1);
    db.setSub4(b.m_kSweptTransform.m_vCenterOfMass1, b.m_kSweptTransform.m_vCenterOfMass0);
    float sa = dt * a.m_kSweptTransform.getInvDeltaTime();
    sb = dt * b.m_kSweptTransform.getInvDeltaTime();
    out.setMul4(sa, da);
    out.addMul4(sb, db);
    out(3) = sa * a.m_kDeltaAngle(3) * a.m_fObjectRadius + sb * b.m_kDeltaAngle(3) * b.m_fObjectRadius;
}
static __forceinline void motionEstimateProcessAgentCFEDD0(const hkMotionStateProcessAgentCFEDD0& a,
                                                           const hkMotionStateProcessAgentCFEDD0& b, float dt,
                                                           hkVector4ProcessAgentCFEDD0& out)
{
    hkVector4ProcessAgentCFEDD0 da, db;
    da.setSub4(a.m_kSweptTransform.m_vCenterOfMass0, a.m_kSweptTransform.m_vCenterOfMass1);
    db.setSub4(b.m_kSweptTransform.m_vCenterOfMass1, b.m_kSweptTransform.m_vCenterOfMass0);
    float sa = dt * a.m_kSweptTransform.getInvDeltaTime();
    float sb = dt * b.m_kSweptTransform.getInvDeltaTime();
    out.setMul4(sa, da);
    out.addMul4(sb, db);
    out(3) = sa * a.m_kDeltaAngle(3) * a.m_fObjectRadius + sb * b.m_kDeltaAngle(3) * b.m_fObjectRadius;
}
static __forceinline void previousInputProcessAgentCFEDD0(hkpAgent3InputProcessAgentCFEDD0& current,
                                                          hkAgentNnMachineBodyTempProcessAgentCFEDD0& state,
                                                          hkpAgent3InputProcessAgentCFEDD0& previous)
{
    FUN_00cf1510(current.m_pBodyA->GetMotionState()->getSweptTransform(),
                 current.m_pRayCastInput->m_pStepInfo.m_uiStartTime, state.m_kTransformA);
    FUN_00cf1510(current.m_pBodyB->GetMotionState()->getSweptTransform(),
                 current.m_pRayCastInput->m_pStepInfo.m_uiStartTime, state.m_kTransformB);
    previous.m_pBodyA = &state.m_pBodyA;
    previous.m_pBodyB = &state.m_pBodyB;
    previous.m_pContactManager = current.m_pContactManager;
    previous.m_pRayCastInput = current.m_pRayCastInput;
    state.m_pBodyA.SetCollisionShapeAndKey(current.m_pBodyA->getShape(), current.m_pBodyA->getShapeKey());
    state.m_pBodyB.SetCollisionShapeAndKey(current.m_pBodyB->getShape(), current.m_pBodyB->getShapeKey());
    new (&state.m_pBodyA) hkpCdBodyProcessAgentCFEDD0(current.m_pBodyA, &state.m_kTransformA);
    new (&state.m_pBodyB) hkpCdBodyProcessAgentCFEDD0(current.m_pBodyB, &state.m_kTransformB);
    previous.m_kTransform.FUN_00cb22f0(state.m_kTransformA, state.m_kTransformB);
}
extern float DAT_0104e148;
// @fnv 0x00cfedd0
extern "C" void __cdecl FUN_00cfedd0(hkpAgentNnEntryProcessAgentCFEDD0* entry,
                                     const hkpProcessCollisionInputProcessAgentCFEDD0& input,
                                     hkpProcessCollisionOutputProcessAgentCFEDD0& output)
{
    const hkpCdBodyProcessAgentCFEDD0* a = entry->getCollidableA();
    const hkpCdBodyProcessAgentCFEDD0* b = entry->getCollidableB();
    hkMotionStateProcessAgentCFEDD0 motionsA[4], motionsB[4];
    hkpCdBodyProcessAgentCFEDD0 bodiesA[4], bodiesB[4];
    int command = entry->m_ucAgentType;
again:
    switch (command)
    {
    case 10:
    case 12:
    case 14: {
        hkUchar transformed;
        a = (const hkpCdBodyProcessAgentCFEDD0*)ProcessAgentCFEDD0::FUN_00cfe1d0((void*)a, bodiesA, motionsA, 4,
                                                                                 &transformed);
        b = (const hkpCdBodyProcessAgentCFEDD0*)ProcessAgentCFEDD0::FUN_00cfe1d0((void*)b, bodiesB, motionsB, 4,
                                                                                 &transformed);
        command = (hkUchar)command & 0xf7;
        goto again;
    }
    case 6: {
        hkpAgentNnMachinePaddedEntryProcessAgentCFEDD0* padded = (hkpAgentNnMachinePaddedEntryProcessAgentCFEDD0*)entry;
        hkpCollisionAgentProcessAgentCFEDD0* agent = *(hkpCollisionAgentProcessAgentCFEDD0**)(padded + 1);
        agent->ProcessAgent(*a, *b, input, output);
        break;
    }
    case 2: {
        hkpAgent3ProcessInputProcessAgentCFEDD0 process;
        process.m_pBodyA = a;
        process.m_pBodyB = b;
        process.m_pContactManager = entry->m_pContactManager;
        process.m_pRayCastInput = &input;
        const hkMotionStateProcessAgentCFEDD0* ma = process.m_pBodyA->GetMotionState();
        const hkMotionStateProcessAgentCFEDD0* mb = process.m_pBodyB->GetMotionState();
        motionEstimateProcessAgentCFEDD0(*ma, *mb, process.m_pRayCastInput->m_pStepInfo.m_fTimeStep,
                                         process.m_vSubtypePosition);
        process.m_kTransform.FUN_00cb22f0(ma->getTransform(), mb->getTransform());
        void* data = (hkpAgentNnMachinePaddedEntryProcessAgentCFEDD0*)entry + 1;
        input.m_pCollisionDispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)(process, entry, data, 0, output);
        break;
    }
    case 4: {
        hkpAgentNnMachineTimEntryProcessAgentCFEDD0* timed = (hkpAgentNnMachineTimEntryProcessAgentCFEDD0*)entry;
        hkpAgent3ProcessInputProcessAgentCFEDD0 process;
        process.m_pBodyA = a;
        process.m_pBodyB = b;
        process.m_pContactManager = entry->m_pContactManager;
        process.m_pRayCastInput = &input;
        const hkMotionStateProcessAgentCFEDD0* ma = process.m_pBodyA->GetMotionState();
        const hkMotionStateProcessAgentCFEDD0* mb = process.m_pBodyB->GetMotionState();
        float distance;
        timedEstimateProcessAgentCFEDD0(*ma, *mb, process.m_pRayCastInput->m_pStepInfo.m_fTimeStep,
                                        process.m_vSubtypePosition, distance);
        void* data = timed + 1;
        if (timed->m_fFloatValue != input.m_pStepInfo.m_uiStartTime)
        {
            if (!input.m_pCollisionQualityInfo->m_iQualityInfoValue10)
            {
                timed->m_fFloatValue = input.m_pStepInfo.m_fEndTime;
                distance = -3.40282e+38f;
                timed->m_vSeparatingNormal.setZero4();
                timed->m_vSeparatingNormal(3) = distance;
                goto processAtEnd;
            }
            hkAgentNnMachineBodyTempProcessAgentCFEDD0 state;
            hkpAgent3InputProcessAgentCFEDD0 previous;
            previousInputProcessAgentCFEDD0(process, state, previous);
            input.m_pCollisionDispatcher->getAgent3SepNormalFunc(entry->m_ucNnTrackType)(previous, entry, data,
                                                                                         timed->m_vSeparatingNormal);
        }
        {
            hkVector4ProcessAgentCFEDD0& plane = timed->m_vSeparatingNormal;
            float projected = process.m_vSubtypePosition.dot4xyz1(plane);
            timed->m_fFloatValue = input.m_pStepInfo.m_fEndTime;
            distance = plane(3) - projected;
            if (distance >= input.getTolerance())
            {
                timed->m_vSeparatingNormal(3) = distance;
                if (entry->m_usNumContactPoints)
                    input.m_pCollisionDispatcher->getAgent3CleanupFunc(entry->m_ucNnTrackType)(
                        entry, data, process.m_pContactManager, *output.m_pConstraintOwner);
                break;
            }
        }
    processAtEnd:
        process.m_fSubtypeValue = distance;
        process.m_kTransform.FUN_00cb22f0(ma->getTransform(), mb->getTransform());
        input.m_pCollisionDispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)(process, entry, data,
                                                                                   &timed->m_vSeparatingNormal, output);
        break;
    }
    default:
        break;
    }
}

}
