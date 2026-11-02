// src/gamebryo2.2/corelibs/nisystem/nimemobject_o2_variant_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/gamebryo2.2/corelibs/nisystem/nimemobject_o2_variant.cpp that match byte for byte only
// with VC9 SP1 and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/gamebryo2.2/corelibs/nisystem/nimemobject_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nisystem/nimemobject.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "nimemobject_decls.h"

struct FUN_00a5c200 : ::NiObject
{
    ::NiFixedString name;
    void* controller;
    void* extraData;
    unsigned short extraDataSize, extraDataCapacity;
    FUN_00a5c200();
};
// @fnv 0x00a5c200
FUN_00a5c200::FUN_00a5c200()
{
    words[0] = (unsigned int)::DAT_0109b244;
    name = ::EmptyFS;
    controller = 0;
    extraData = 0;
    extraDataSize = 0;
    extraDataCapacity = 0;
}

struct S_00aa1420_Object
{
    virtual void S_00aa1420_v0();
    virtual void S_00aa1420_v1(int* arg1, int* arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
};

inline void S_00aa1420_Object::S_00aa1420_v0()
{}

inline void S_00aa1420_Object::S_00aa1420_v1(int* arg1, int* arg2, int arg3, int arg4, int arg5, int arg6, int arg7)
{}

struct S_00aa1420_Holder
{
    S_00aa1420_Object* m_00;
};

// @fnv 0x00aa1420
void __cdecl FUN_00aa1420(int arg)
{
    int value;
    S_00aa1420_Object* obj;

    obj->S_00aa1420_v1(
        (*(volatile int*)& arg = 4, &value), &arg, 2, 0,
        (*(volatile int*)& value = arg ? arg : 1, obj = reinterpret_cast<S_00aa1420_Holder*>(DAT_011f6080)->m_00, 0),
        -1, 0);
}

namespace SizedDeleteDetail {
enum MemoryOperation
{
    ScalarDelete = 3
};

class Allocator
{
  public:
    virtual ~Allocator();
    virtual void* Allocate();
    virtual void Deallocate(void* memory, MemoryOperation operation, unsigned int size);
};

class Manager
{
    Allocator* allocator;

  public:
    static Manager& Current()
    {
        return *static_cast<Manager*>(::DAT_011f6080);
    }

    void Deallocate(void* memory, unsigned int size)
    {
        allocator->Deallocate(memory, ScalarDelete, size);
    }
};
}

// @fnv 0x00aa1460
void FUN_00aa1460(void* memory, unsigned int size)
{
    if (memory)
        SizedDeleteDetail::Manager::Current().Deallocate(memory, size);
}
