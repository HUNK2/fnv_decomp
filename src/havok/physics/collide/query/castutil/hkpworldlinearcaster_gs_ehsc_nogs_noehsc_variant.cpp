
// src/havok/physics/collide/query/castutil/hkpworldlinearcaster_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/query/castutil/hkpworldlinearcaster.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/query/castutil/hkpworldlinearcaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/castutil/hkpworldlinearcaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FloatHolder
{
    int unk00;
    float m_04;
};
struct SlotRecord
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    signed char m_05;
};
struct SlotTarget
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
};
struct FuncEntry
{
    void* pfn;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
typedef int(__cdecl* SlotFn)(int, int, int, int, int);
struct NodeMatcher
{
    virtual void v00();
    virtual unsigned char* Match(SlotRecord** ppRecord, int aKey, int aSlot);
};
struct FUN_00cfae50_cls
{
    int unk00;
    int unk04;
    NodeMatcher* m_08;
    FloatHolder* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int unk1c;
    unsigned char* m_20;

    float InvokeSlotHandler(SlotRecord* a1, int a2);
};
