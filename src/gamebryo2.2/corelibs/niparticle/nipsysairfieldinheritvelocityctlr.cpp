
// src/gamebryo2.2/corelibs/niparticle/nipsysairfieldinheritvelocityctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysairfieldinheritvelocityctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_012027b0;

// @fnv 0x00c30630
void* __cdecl FUN_00c30630()
{
    return &g_012027b0;
}

struct NiPSysModifierFloatCtlr
{
    float m_fValue;
};

struct NiPSysAirFieldInheritVelocityCtlr : NiPSysModifierFloatCtlr
{
    void FUN_00c30640(float& fValue);
};

// @fnv 0x00c30640
void __thiscall NiPSysAirFieldInheritVelocityCtlr::FUN_00c30640(float& fValue)
{
    float* p = *(float**)((char*)this + 0x3c);
    fValue = p[0x5c / 4];
}

struct S_00c30650_Mod
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    float m_fNormalizedValue;
    void Set(float f)
    {
        if (0.0 > f)
            f = 0.0f;
        if (1.0 < f)
            f = 1.0f;
        m_fNormalizedValue = f;
    }
};
struct S_00c30650
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
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
    S_00c30650_Mod* m_pkTargetModifier;
    void SetModValue(float fValue);
};
// Clamps fValue to [0,1] via the modifier's Set and stores it.
// @fnv 0x00c30650
void S_00c30650::SetModValue(float fValue)
{
    m_pkTargetModifier->Set(fValue);
}

extern "C" char DAT_010c05e4;
extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedCtlr
{
    void FUN_00c32d80();
    virtual void v00();
};

struct SpawnedHost
{
    void FUN_00c32de0(SpawnedCtlr* obj, void* a1);
    SpawnedCtlr* CreateSpawnedCtlr(void* a1);
};

// Allocates a 0x40-byte SpawnedCtlr, initialises it, passes it to FUN_00c32de0 with a1, and returns it.
// @fnv 0x00c306a0
SpawnedCtlr* SpawnedHost::CreateSpawnedCtlr(void* a1)
{
    SpawnedCtlr* obj = (SpawnedCtlr*)FUN_00aa13e0(0x40);
    if (obj != 0)
    {
        obj->FUN_00c32d80();
        *(void* volatile*)obj = &DAT_010c05e4;
    }
    else
    {
        obj = 0;
    }
    this->FUN_00c32de0(obj, a1);
    return obj;
}

struct StrArr
{
    void* unk00;
    char** data;
    unsigned short capacity;
    unsigned short index;
    unsigned short count;
    unsigned short growBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
char* __cdecl FUN_00a7d330(char*);
void __stdcall FUN_00c32f60(StrArr*);
// Grows the array if its index has reached capacity, then stores the string returned by FUN_00a7d330 at that index.
// @fnv 0x00c30740
void __stdcall FUN_00c30740(StrArr* array)
{
    FUN_00c32f60(array);
    char* value = FUN_00a7d330(static_cast<char*>(g_012027b0));
    unsigned int index = array->index;
    unsigned int capacity = array->capacity;
    if (index >= capacity)
        array->SetSize(index + array->growBy);
    array->SetAt(index, value);
}
