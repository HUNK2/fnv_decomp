
// src/havok/physics/collide/dispatch/hkpagentregisterutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/dispatch/hkpagentregisterutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FlagCBFD
{
    bool m_bValue;
    FlagCBFD(bool bValue) : m_bValue(bValue)
    {}
    FlagCBFD(const FlagCBFD& kOther) : m_bValue(kOther.m_bValue)
    {}
};

class WorldCBFD
{
  public:
    void FUN_00cfb1e0(FlagCBFD kFlag);
};

void __cdecl FUN_00d46410(WorldCBFD* pkWorld);
void __cdecl ConfigureVtblHandlers(WorldCBFD* pkWorld);
void __cdecl RegisterTwoTables(WorldCBFD* pkWorld);
void __cdecl RegisterAll(WorldCBFD* pkWorld);
void __cdecl FUN_00d44310(WorldCBFD* pkWorld);
void __cdecl FUN_00cbfc60(WorldCBFD* pkWorld);
void __cdecl RegisterCallbacks(WorldCBFD* pkWorld);
void __cdecl FUN_00d42960(WorldCBFD* pkWorld);
void __cdecl FUN_00cbfcb0(WorldCBFD* pkWorld);

// Calls a sequence of registration and configuration functions on pkWorld, toggling a flag between two of them.
// @fnv 0x00cbfd20
void __cdecl InitializeWorld(WorldCBFD* pkWorld)
{
    FUN_00d46410(pkWorld);
    ConfigureVtblHandlers(pkWorld);
    RegisterTwoTables(pkWorld);
    RegisterAll(pkWorld);
    pkWorld->FUN_00cfb1e0(FlagCBFD(false));
    FUN_00d44310(pkWorld);
    pkWorld->FUN_00cfb1e0(FlagCBFD(true));
    FUN_00cbfc60(pkWorld);
    RegisterCallbacks(pkWorld);
    FUN_00d42960(pkWorld);
    FUN_00cbfcb0(pkWorld);
}
