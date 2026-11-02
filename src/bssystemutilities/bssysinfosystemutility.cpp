// bssystemutilities/bssysinfosystemutility.cpp: BSSysInfoSystemUtility (3 functions)

#include "BSSysInfoSystemUtility.h"

// @fnv 0x00af3b70
void BSSysInfoSystemUtility::Initialize()
{}

// @fnv 0x00af3b80
void BSSysInfoSystemUtility::Destroy()
{
    m_eLanguage = BSSysInfoSystemUtility__LANGUAGE_LANGUAGE_UNKNOWN;
}

struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
MemoryManager g_memoryManager;

struct FUN_00af3b50_holder
{
    void __thiscall SetVTable();
};

struct FUN_00af3ba0_shell
{
    void* __thiscall FUN_00af3ba0(unsigned int flags);
};

// @fnv 0x00af3ba0
void* FUN_00af3ba0_shell::FUN_00af3ba0(unsigned int flags)
{
    ((FUN_00af3b50_holder*)this)->SetVTable();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
