
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* __cdecl operator new(unsigned);
void* __cdecl operator new[](unsigned);
void* __cdecl FUN_00403d30(void*, int, unsigned);
struct Heap
{
    virtual void method0();
};
struct Block
{
    unsigned offset;
    void* memory;
};
struct Bin
{
    int count;
    Block* first;
};
struct Critical
{
    void* debugInfo;
    int lockCount, recursionCount;
    void* owningThread;
    void* semaphore;
    unsigned spinCount;
};
struct FUN_00aa78a0 : Heap
{
    const char* name;
    int alignment, blockHeaderSize;
    unsigned pageSize, reserveSize, commitSize, currentCommit;
    int used, allocations, unk28, unk2C;
    void* base;
    int unk34, unk38, unk3C, unk40;
    Block blocks[1024];
    Block* freeBlock;
    int unk2048, unk204C, allocatedBlocks, freeBlocks;
    Bin bins[16];
    Critical lock;
    bool flag, initialized;
    unsigned short unk20F2;
    FUN_00aa78a0(unsigned, unsigned, const char*, bool);
};
struct FUN_00aa7400 : Heap
{
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    FUN_00aa7400(unsigned, const char*);
};
extern char DAT_010824fc, DAT_010824f0, DAT_010824e4;
struct MemoryManager
{
    unsigned short unk00, count, current, unk06;
    Heap** heaps;
    Heap* classes[66];
    void InitializeHeaps();
};
// Clears the classes array, allocates three heaps, assigns them to class slots, and resets current to 0.
// @fnv 0x00866e00
void MemoryManager::InitializeHeaps()
{
    FUN_00403d30(classes, 0, 0x108);
    count = 3;
    heaps = new Heap*[count];
    heaps[0] = new FUN_00aa78a0(0xc800000, 0x5500000, &DAT_010824fc, false);
    classes[65] = heaps[0];
    heaps[1] = new FUN_00aa7400(0x183800, &DAT_010824f0);
    classes[0] = heaps[1];
    classes[9] = heaps[1];
    classes[3] = heaps[1];
    heaps[2] = new FUN_00aa78a0(0x4000000, 0x200000, &DAT_010824e4, false);
    classes[23] = heaps[2];
    current = 0;
}
