
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct MemoryPool;

extern MemoryPool* ms_pPoolAddressMap[];
extern MemoryPool* DAT_011f67b8[];

// @fnv 0x00aa6840
void ClearMemoryPoolTables()
{
    unsigned int uiIndex;
    for (uiIndex = 0; uiIndex < 0x100; ++uiIndex)
        DAT_011f67b8[uiIndex] = 0;
    unsigned int uiIndex2;
    for (uiIndex2 = 0; uiIndex2 < 0x100; ++uiIndex2)
        ms_pPoolAddressMap[uiIndex2] = 0;
}
