
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

// Searches the smaller node's entry list for an entry whose key equals the other node and returns its value, else 0.
// @fnv 0x00cfdd70
void* __cdecl FindEntryValue(LinkNode* apFirst, LinkNode* apSecond)
{
    LinkNode* pSmaller;
    LinkNode* pOther;

    if (apFirst->m_iArrayLength <= apSecond->m_iArrayLength)
    {
        pSmaller = apFirst;
        pOther = apSecond;
    }
    else
    {
        pSmaller = apSecond;
        pOther = apFirst;
    }

    int iEntryCount = pSmaller->m_iArrayLength;
    for (int i = 0; i < iEntryCount; i++)
    {
        if (pSmaller->m_pEntries[i].m_pKey == pOther)
            return pSmaller->m_pEntries[i].m_pIntegerData;
    }
    return 0;
}

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

// @fnv 0x00cfddc0
void FUN_00cfddc0(unk_00cfddc0* pArg)
{
    int i = 0;
    if (pArg->unk08 > i)
    {
        int* aRecords = pArg->unk04;
        volatile int* pCount = &pArg->unk08;  // re-read the record count
        int iCount = *pCount;
        do
        {
            unsigned char* pPos = (unsigned char*)*aRecords++;
            i++;
            unsigned char* pLimit;
            if (i == iCount)
                pLimit = (unsigned char*)(pArg->unk00 + (int)pPos);
            else
                pLimit = pPos + 0x200;
            while (pPos < pLimit)
                pPos += pPos[3];
        } while (i < iCount);
    }
}

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

// @fnv 0x00cfdf60
void GetNodePairValue(FnvNode** ppA, FnvNode** ppB, FnvCtx* pCtx, int* pOutVal, int* pOutFlag)
{
    FnvNode* pNodeA = *ppA;
    FnvNode* pNodeB = *ppB;
    FnvCtx* pCtxLocal = pCtx;
    unsigned char* pucBase = pCtxLocal->unk00;
    int iIndexA = pNodeA->unk0c;
    int iIndexB = pNodeB->unk0c;

    int iIndex = iIndexA * 32 + iIndexB;
    int iValue = pCtx->unk14 ? (int)pucBase[0x12b0 + iIndex] : (int)pucBase[0xeb0 + iIndex];

    int bOk = (*(int*)(pucBase + 0x16f0 + iValue * 80) == 2);
    if (iValue == 1)
    {
        int nQ = pucBase[(iIndexA + 13) * 32 + iIndexB];
        int nR = nQ + 0x7c;
        nR *= 5;
        bOk = (*(volatile unsigned char*)&pucBase[nR * 4] != 0);
    }

    int iResult = iValue;
    *pOutFlag = bOk;
    if (bOk)
    {
        int iIndexSwapped = iIndexB * 32 + iIndexA;
        iResult = pCtx->unk14 ? (int)pucBase[0x12b0 + iIndexSwapped] : (int)pucBase[0xeb0 + iIndexSwapped];
    }
    *pOutVal = iResult;
}

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

// Returns a pointer into the pool's current block at the pool offset, advancing it by 0x80, or allocates a new 0x200-byte block when the offset reaches 0x200.
// @fnv 0x00cfe820
static __declspec(noinline) char* AllocatePoolChunk(CFE820Pool* pool)
{
    if (pool->m_uiBufferCapacity < 0x200)
    {
        char* p = pool->m_kBlocks.m_data[pool->m_kBlocks.m_iElementCount - 1] + pool->m_uiBufferCapacity;
        pool->m_uiBufferCapacity += 0x80;
        return p;
    }
    char* block = static_cast<char*>(FUN_00c85750().heap().AllocateMemoryBlock(0x200));
    pool->m_kBlocks.AddBack(block);
    pool->m_uiBufferCapacity = 0x80;
    return block;
}

// Caller so the file-static helper is emitted with its register calling convention.
char* CFE820Allocate(CFE820Pool* pool)
{
    char* a = AllocatePoolChunk(pool);
    char* b = AllocatePoolChunk(pool);
    return a < b ? a : b;
}

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

// @fnv 0x00cfeba0
void __cdecl FUN_00cfeba0(FUN_00cfeba0_Obj* self, void** apCallbackTable, void* a3)
{
    unsigned char flag;
    void* p = 0;
    FUN_00cfeba0_Result results[8];
    FUN_00cfeba0_Node elems[8];
    int type = self->m_type;
    void* h1 = self->m_p10;
    void* h2 = self->m_p14;

    for (;;)
    {
        switch (type - 2)
        {
        case 0:
        case 4:
            p = (char*)self + 0x20;
            break;
        case 2:
            p = (char*)self + 0x30;
            break;
        case 8:
        case 10:
        case 12:
            h1 = FUN_00cfe1d0(h1, &results[0], &elems[0], 4, &flag);
            h2 = FUN_00cfe1d0(h2, &results[4], &elems[4], 4, &flag);
            type = (unsigned int)((unsigned char)type) & (unsigned int)0xf7;
            continue;
        default:
            return;
        }

        {
            FUN_00cfeba0_Fn fn = *(FUN_00cfeba0_Fn*)((char*)(*apCallbackTable) + 0x16c8 + self->m_uiEdgeIndex * 80);
            if (fn)
            {
                fn(self, p, h1, h2, apCallbackTable, (void*)self->unk08, a3);
            }
        }
        return;
    }
}

namespace fnv_00cfeca0 {
extern "C" void _ReadWriteBarrier();
struct Record
{
    unsigned word00;
    unsigned word04;
    unsigned word08;
    unsigned word0c;
    unsigned word10;
    unsigned word14;
    unsigned word18;
    unsigned word1c;
    unsigned word20;
    unsigned word24;
    unsigned word28;
    unsigned word2c;
    unsigned word30;
    unsigned word34;
    unsigned word38;
    unsigned word3c;
    unsigned word40;
    unsigned word44;
    unsigned word48;
    unsigned word4c;
    unsigned word50;
    unsigned word54;
    unsigned word58;
    unsigned word5c;
    unsigned word60;
    unsigned word64;
    unsigned word68;
    unsigned word6c;
    unsigned word70;
    unsigned word74;
    unsigned word78;
    unsigned word7c;
};
struct DataBufferInfo
{
    Record* record;
    unsigned other;
};
struct Allocator
{
    virtual void Slot0();
    virtual void* Allocate(unsigned bytes);
};
struct BSAudio
{
    unsigned unk00, unk04, unk08, unk0c;
    Allocator* allocator;
};
BSAudio* FUN_00c85750();
void ResizeAudioStream(void*, void*, int);
struct SlabArray
{
    char** data;
    int count;
    unsigned capacityFlags;
    void Append(char* block)
    {
        BSAudio* audio = FUN_00c85750();
        if (count == (capacityFlags & 0x3fffffffu))
            ResizeAudioStream(audio->allocator, this, 4);
        data[count] = block;
        ++count;
    }
};
struct State
{
    unsigned used;
    SlabArray slabs;
};
__declspec(noinline) static Record* AllocatePoolChunk(State* state)
{
    if (state->used < 512u)
    {
        char* result = state->slabs.data[state->slabs.count - 1] + state->used;
        state->used += 128;
        return reinterpret_cast<Record*>(result);
    }
    BSAudio* audio = FUN_00c85750();
    Allocator* allocator = audio->allocator;
    char* block = static_cast<char*>(allocator->Allocate(512));
    state->slabs.Append(block);
    state->used = 128;
    return reinterpret_cast<Record*>(block);
}
// Allocates a Record from state, copies all 32 words from source, then registers the new record in two tables indexed by the halves of word04.
// @fnv 0x00cfeca0
Record* CloneRecord(State* state, const Record* source)
{
    Record* record = AllocatePoolChunk(state);
    record->word00 = source->word00;
    record->word04 = source->word04;
    record->word08 = source->word08;
    record->word0c = source->word0c;
    record->word10 = source->word10;
    record->word14 = source->word14;
    record->word18 = source->word18;
    record->word1c = source->word1c;
    record->word20 = source->word20;
    record->word24 = source->word24;
    record->word28 = source->word28;
    record->word2c = source->word2c;
    record->word30 = source->word30;
    record->word34 = source->word34;
    record->word38 = source->word38;
    record->word3c = source->word3c;
    record->word40 = source->word40;
    record->word44 = source->word44;
    record->word48 = source->word48;
    record->word4c = source->word4c;
    record->word50 = source->word50;
    record->word54 = source->word54;
    record->word58 = source->word58;
    record->word5c = source->word5c;
    record->word60 = source->word60;
    record->word64 = source->word64;
    record->word68 = source->word68;
    record->word6c = source->word6c;
    record->word70 = source->word70;
    record->word74 = source->word74;
    record->word78 = source->word78;
    record->word7c = source->word7c;
    _ReadWriteBarrier();
    unsigned short indexA = static_cast<unsigned short>(record->word04);
    unsigned short indexB = static_cast<unsigned short>(record->word04 >> 16);
    DataBufferInfo* tableA = *reinterpret_cast<DataBufferInfo**>(record->word10 + 0x50);
    tableA[indexA].record = record;
    DataBufferInfo* tableB = *reinterpret_cast<DataBufferInfo**>(record->word14 + 0x50);
    tableB[indexB].record = record;
    return record;
}
}  // namespace fnv_00cfeca0

struct ItemStack
{
    int m_base;
    int* m_pItems;
    int m_uiItemCount;
};

void __cdecl FUN_00cfea30(ItemStack* s, int value, int a, int b);

// @fnv 0x00cfed90
void __cdecl FUN_00cfed90(ItemStack* s, int a, int b)
{
    if (s->m_uiItemCount != 0)
    {
        do
        {
            int iIndex = *(volatile int*)&s->m_uiItemCount;
            int iItemValue = s->m_pItems[iIndex - 1];
            FUN_00cfea30(s, iItemValue + s->m_base - 0x80, a, b);
        } while (s->m_uiItemCount != 0);
    }
}

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

// Looks up a per-slot callback from ctx and invokes it with obj, a payload pointer, x and y; for types 4 and 12 it also updates obj->unk18 from x/y.
// @fnv 0x00cfdc90
void __cdecl DispatchSlotCallback(FUN_00cfdc90_Obj* obj, float x, float y, void* ctx)
{
    switch (obj->type - 2)
    {
    case 0:
    case 4:
    case 8:
    case 12: {
        FUN_00cfdc90_Fn fn = *(FUN_00cfdc90_Fn*)(*(char**)ctx + obj->slot * 80 + 0x16d4);
        if (fn != 0)
        {
            fn(obj, &obj->unk20, x, y, ctx);
        }
    }
    break;
    case 2:
    case 10: {
        void* p = &obj->unk30;
        float prev = obj->unk18;
        if (prev == x)
        {
            obj->unk18 = y;
        }
        else
        {
            obj->unk18 = DAT_01012054;
        }
        FUN_00cfdc90_Fn fn = *(FUN_00cfdc90_Fn*)(*(char**)ctx + obj->slot * 80 + 0x16d4);
        if (fn != 0)
        {
            fn(obj, p, x, y, ctx);
        }
    }
    break;
    }
}

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

// @fnv 0x00cfea30
void __cdecl FUN_00cfea30(void* track, hkpAgentNnEntryCFEA* entry, hkpCollisionDispatcherCFEA* dispatch,
                          void* constraintOwner)
{
    switch (entry->m_ucAgentType)
    {
    case 2:
    case 6:
    case 10:
    case 14: {
        hkAgent3DestroyFuncCFEA pDestroyFunc = dispatch->getAgent3DestroyFunc(entry->m_ucNnTrackType);
        pDestroyFunc(entry, (char*)entry + 0x20, entry->m_pContactManager, constraintOwner, dispatch);
        break;
    }
    case 4:
    case 12: {
        hkAgent3DestroyFuncCFEA pDestroyFunc = dispatch->getAgent3DestroyFunc(entry->m_ucNnTrackType);
        pDestroyFunc(entry, (char*)entry + 0x30, entry->m_pContactManager, constraintOwner, dispatch);
        break;
    }
    default:
        break;
    }

    for (int i = 0; i < 2; i++)
    {
        hkpLinkedCollidableCFEA* collidable = entry->m_kCollidable[i];
        int index = entry->m_ausAgentData[i];
        hkCollisionEntryArrayCFEA& entries = collidable->m_kCollisionEntries;
        entries.removeAt(index);
        if (index < collidable->m_kCollisionEntries.m_iElementCount)
        {
            hkpAgentNnEntryCFEA* pMovedEntry = entries.m_data[index].m_pAgentEntry;
            pMovedEntry->m_ausAgentData[pMovedEntry->m_kCollidable[0] != collidable] = (unsigned short)index;
        }
        entries.OptimizeCapacity(FUN_00c85750().heap(), 4);
    }

    FUN_00cfe020(track, entry);
}

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

// Clones records from the end of appendee into track while track's last sector is not full, then inserts appendee's remaining sectors into track's sector array.
// @fnv 0x00cff290
void __cdecl FUN_00cff290(hkpAgentNnTrackCFF2* track, hkpAgentNnTrackCFF2* appendee)
{
    while (track->m_iBytesUsedInLastSector != 0x200)
    {
        if (appendee->m_kSectors.GetLogicalSize() == 0)
        {
            break;
        }
        hkpAgentNnEntryCFF2* entry =
            (hkpAgentNnEntryCFF2*)((char*)appendee->m_kSectors.back() + appendee->m_iBytesUsedInLastSector - 0x80);
        CloneRecord(track, entry);
        appendee->m_iBytesUsedInLastSector = appendee->m_iBytesUsedInLastSector - 0x80;
        if (appendee->m_iBytesUsedInLastSector == 0)
        {
            hkpAgentNnSectorCFF2* sector = appendee->m_kSectors.back();
            appendee->m_kSectors.popBack();
            hkRouterCFF2::FUN_00c85750().heap().ReleaseBlock(sector, 0x200);
            appendee->m_iBytesUsedInLastSector = 0x200;
        }
        appendee->m_kSectors.OptimizeCapacity(4);
    }

    if (appendee->m_kSectors.GetLogicalSize())
    {
        hkpAgentNnSectorCFF2** sectors = appendee->m_kSectors.m_data;
        track->m_kSectors.Search(hkRouterCFF2::FUN_00c85750().heap(), track->m_kSectors.GetLogicalSize(), sectors,
                                 appendee->m_kSectors.GetLogicalSize());
        track->m_iBytesUsedInLastSector = appendee->m_iBytesUsedInLastSector;
        appendee->m_kSectors.m_iElementCount = 0;
        appendee->m_iBytesUsedInLastSector = 0x200;
    }
}

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

// Pops an S_cfe020_Entry from the pool's stack, copies it to dest, updates the owner slot pointers, and releases the block when the pool empties.
// @fnv 0x00cfe020
void FUN_00cfe020(S_cfe020_Pool* pool, S_cfe020_Entry* dest)
{
    S_cfe020_Entry* src = (S_cfe020_Entry*)(pool->blocks.back() + pool->used - 0x80);
    if (dest != src)
    {
        *dest = *src;
        _ReadWriteBarrier();
        unsigned short a = dest->idxA;
        unsigned short b = dest->idxB;
        dest->ownerA->slots[a].entry = dest;
        dest->ownerB->slots[b].entry = dest;
    }
    pool->used -= 0x80;
    if (pool->used == 0)
    {
        char* block = pool->blocks.back();
        pool->blocks.popBack();
        ((S_cfe020_Heap*)&FUN_00c85750().heap())->ReleaseBlock(block, 0x200);
        pool->used = 0x200;
    }
    pool->blocks.optimize();
}

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
// Allocates a CollisionAgentEntry from pool, links nodeA/nodeB, builds AgentInput, and calls the quality-level create function to initialize the agent.
// @fnv 0x00cfe8a0
CollisionAgentEntry* __cdecl FUN_00cfe8a0(CFE820Pool* pool, CollidableNode* nodeA, CollidableBody* bodyA,
                                          CollidableNode* nodeB, CollidableBody* bodyB, unsigned char flags,
                                          int qualityType, Dispatcher* dispatcher, void* island)
{

    char* initialTable = dispatcher->m_tableBase;
    char* pAlloc = AllocatePoolChunk(pool);
    CollisionAgentEntry* entry = (CollisionAgentEntry*)pAlloc;
    entry->m_nodeA = nodeA;
    entry->m_pCurrentSimulationIsland = island;
    entry->m_nodeB = nodeB;
    entry->m_agentIndexA = (unsigned short)nodeA->m_ppLinks.m_iElementCount;
    entry->m_agentIndexB = (unsigned short)nodeB->m_ppLinks.m_iElementCount;
    LinkEntry* linkA = nodeA->m_ppLinks.AddBack();
    LinkEntry* linkB = nodeB->m_ppLinks.AddBack();
    {
        AgentInput input;
        linkA->m_pIntegerData = entry;
        linkB->m_pIntegerData = entry;
        linkA->m_pKey = nodeB;
        linkB->m_pKey = nodeA;
        input.m_pBodyA = bodyA;
        input.m_pBodyB = bodyB;
        input.m_pContactManager = entry->m_pCurrentSimulationIsland;
        input.m_pRayCastInput = dispatcher;
        input.m_kTransform.FUN_00cb22f0(*bodyA->m_kMotionTransform, *bodyB->m_kMotionTransform);
        char* tableBase = dispatcher->m_tableBase;
        char agentType = tableBase[0x1bb0 + nodeA->m_type * 10 + nodeB->m_type];
        entry->m_ucNnTrackType = agentType;
        dispatcher->m_currentAgentEntry = dispatcher->m_tableBase + 0x1c20 + ((int)(signed char)agentType << 6);
        QualityEntry* quality = (QualityEntry*)(initialTable + 0x16b0 + qualityType * 80);
        entry->m_iAutoRemoveLevel = (unsigned char)qualityType;
        void* subEntry;
        if (quality->m_flag28 != 0)
        {
            entry->m_flags = flags | 4;
            entry->m_fTimeOfImpact = -1.0f;
            entry->m_vSeparatingNormal = _mm_setzero_ps();
            subEntry = (char*)entry + 0x30;
        }
        else
        {
            entry->m_flags = flags | 2;
            subEntry = (char*)entry + 0x20;
        }
        ((QualityEntry*)(initialTable + 0x16b0 + (unsigned char)qualityType * 80))
            ->m_pCreateFunc(&input, entry, subEntry);
    }
    entry->m_iElementCount = 0x80;
    return entry;
}

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

// Computes swept transforms for both bodies, copies shapes and keys into temp bodies, and sets out fields from in and temp.
// @fnv 0x00cfde10
static __declspec(noinline) void FUN_00cfde10(PairInput& out, PairInput& in, PairTemporary& temp)
{
    FUN_00cf1510(in.bodyA->GetMotionState()->getSweptTransform(), in.context->step.start, temp.ta);
    FUN_00cf1510(in.bodyB->GetMotionState()->getSweptTransform(), in.context->step.start, temp.tb);
    out.bodyA = &temp.a;
    out.bodyB = &temp.b;
    out.manager = in.manager;
    out.context = in.context;
    temp.a.SetCollisionShapeAndKey(in.bodyA->getShape(), in.bodyA->getShapeKey());
    temp.b.SetCollisionShapeAndKey(in.bodyB->getShape(), in.bodyB->getShapeKey());
    new (&temp.a) PairBody(in.bodyA, &temp.ta);
    new (&temp.b) PairBody(in.bodyB, &temp.tb);
    out.relative.FUN_00cb22f0(temp.ta, temp.tb);
}
PairInput* volatile pairIn;
PairTemporary* volatile pairTemp;
PairInput* volatile pairOut;
void pairCaller()
{
    FUN_00cfde10(*pairOut, *pairIn, *pairTemp);
}
