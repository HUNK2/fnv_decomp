// bssystemutilities/bsdiscbootsystemutility.cpp: BSDiscBootSystemUtility (3 functions)

#include "bsdiscbootsystemutility_local.h"

typedef void(__thiscall* DestroyFn)(BSDiscBootSystemUtility*);

extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);

// @fnv 0x00af3ae0
void BSDiscBootSystemUtility::Destroy()
{}

// @fnv 0x00af3aa0
void BSDiscBootSystemUtility::Initialize(const char* titleID, unsigned int parentalLevel)
{
    ((DestroyFn)m_ppVirtualMethodTable[2])(this);
    if (titleID)
    {
        strcpy_s(m_acTitleID, 0x40, titleID);
    }
    m_uiParentalLevel = parentalLevel;
}

struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct FUN_00af3af0_Class
{
    void InitPointer();
    void* FUN_00af3af0(unsigned int);
};
// @fnv 0x00af3af0
void* FUN_00af3af0_Class::FUN_00af3af0(unsigned int flags)
{
    InitPointer();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
