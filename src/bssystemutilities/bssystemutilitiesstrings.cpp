// bssystemutilities/bssystemutilitiesstrings.cpp: BSSystemUtilitiesStrings (4 functions)

#include "bssystemutilitiesstrings.h"

// Frees each of the 8 stored string pointers via g_memoryManager.Deallocate and clears the slots.
// @fnv 0x00af3680
void BSSystemUtilitiesStrings::Destroy()
{
    for (unsigned int i = 0; i < 8; ++i)
    {
        if (m_pStringFunctions[i])
        {
            void* ptr = m_pStringFunctions[i];
            g_memoryManager.Deallocate(ptr);
            m_pStringFunctions[i] = 0;
        }
    }
}

struct FUN_00af3660_shell : public BSSystemUtilitiesStrings
{
    void CallVTableMethod();
};

struct VTableHelper_00af3660
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

// @fnv 0x00af3660
void FUN_00af3660_shell::CallVTableMethod()
{
    reinterpret_cast<VTableHelper_00af3660*>(this)->v2();
}

struct FUN_00af37a0_Owner
{
    void FUN_00af35c0();
    void* DestroyIfFlagged(unsigned int flags);
};
// @fnv 0x00af37a0
void* FUN_00af37a0_Owner::DestroyIfFlagged(unsigned int flags)
{
    FUN_00af35c0();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct P03MM : public MemoryManager
{
    void* Allocate(unsigned int);
};
extern P03MM _g_memoryManager;

unsigned int _strlen(const char*);
void* _fnv_zlib_memset(void*, int, unsigned int);
int _strcpy_s(char*, unsigned int, const char*);

struct FUN_00af36e0_shell
{
    char pad[4];
    char* m_pStringFunctions[1];

    void SetStringAt(unsigned int index, const char* str);
};

// Frees the string stored at the given index, then allocates and copies a new copy of str into that slot if str is non-null.
// @fnv 0x00af36e0
void FUN_00af36e0_shell::SetStringAt(unsigned int index, const char* pcStr)
{
    unsigned int len;
    if (m_pStringFunctions[index])
    {
        void* pOldString = m_pStringFunctions[index];
        _g_memoryManager.Deallocate(pOldString);
        m_pStringFunctions[index] = 0;
    }
    if (pcStr)
    {
        len = _strlen(pcStr) + 1;
        void* pAllocated = _g_memoryManager.Allocate(len);
        m_pStringFunctions[index] = (char*)pAllocated;
        void* pZeroed = m_pStringFunctions[index];
        _fnv_zlib_memset(pZeroed, 0, len);
        void* pNewString = m_pStringFunctions[index];
        _strcpy_s((char*)pNewString, len, pcStr);
    }
}
