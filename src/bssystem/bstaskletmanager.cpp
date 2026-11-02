
// src/bssystem/bstaskletmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bssystem/bstaskletmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct MemoryManager
{
    void* __thiscall _DeallocateAlias(void*);
};

extern "C" void* __cdecl _DeallocateAlias(void*);
extern int DAT_010a47b8;
extern MemoryManager g_memoryManager;

struct BSTaskletManagerCallback
{
    int* vtable;
    void* __thiscall Destroy(unsigned int flags);
};

// Sets the vtable to DAT_010a47b8 and, when flags has bit 0 set, deallocates this through g_memoryManager, returning this.
// @fnv 0x00b00e90
void* __thiscall BSTaskletManagerCallback::Destroy(unsigned int flags)
{
    this->vtable = &DAT_010a47b8;
    if (flags & 1)
    {
        g_memoryManager._DeallocateAlias(this);
    }
    return this;
}
