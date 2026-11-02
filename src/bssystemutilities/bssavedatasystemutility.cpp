// bssystemutilities/bssavedatasystemutility.cpp: BSSaveDataSystemUtility, TargetClass (4 functions)

#include "BSSaveDataSystemUtility.h"

// @fnv 0x00af2f60
void BSSaveDataSystemUtility::Destroy()
{
    m_pOperationContext = 0;
}

struct FUN_00af2f40_shell : public BSSaveDataSystemUtility
{
    void CallVTableMethod();
};

struct VTableHelper
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

// @fnv 0x00af2f40
void FUN_00af2f40_shell::CallVTableMethod()
{
    reinterpret_cast<VTableHelper*>(this)->v2();
}

class MemoryManager
{
  public:
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct TargetClass
{
    void FUN_00af2f20();
    void* FUN_00af2fc0(unsigned int flags);
};
// @fnv 0x00af2fc0
void* TargetClass::FUN_00af2fc0(unsigned int flags)
{
    FUN_00af2f20();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00af2ff0_Holder
{
    bool FUN_00af2ff0(const char* a, void* b);
};
// @fnv 0x00af2ff0
bool FUN_00af2ff0_Holder::FUN_00af2ff0(const char* a, void* b)
{
    return false;
}
