
// bgsentrypointfunction_ctx2_variant.cpp: context variant of src/fallout_shared/bgsentrypointfunction.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "BGSEntryPointFunction.h"

struct ScriptLocals;
struct Script
{
    ScriptLocals* GetOrCreateScriptLocals();
};
struct BoundObj5e5f50
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual void b43();
    virtual void b44();
    virtual void b45();
    virtual void b46();
    virtual void b47();
    virtual void b48();
    virtual void b49();
    virtual void b50();
    virtual void b51();
    virtual void b52();
    virtual void b53();
    virtual void b54();
    virtual void b55();
    virtual void b56();
    virtual bool IsLeveledOrPlayable();
};
struct InventoryItemEntry
{
    int m_iCountDelta;
    BoundObj5e5f50* pObj;
};
struct Actor5e5f50
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void a48();
    virtual void a49();
    virtual void a50();
    virtual void a51();
    virtual void a52();
    virtual void a53();
    virtual void a54();
    virtual void a55();
    virtual void a56();
    virtual void a57();
    virtual void a58();
    virtual void a59();
    virtual void a60();
    virtual void a61();
    virtual void a62();
    virtual void a63();
    virtual void a64();
    virtual void a65();
    virtual void a66();
    virtual void a67();
    virtual void a68();
    virtual void a69();
    virtual void a70();
    virtual void a71();
    virtual void a72();
    virtual void a73();
    virtual void a74();
    virtual void a75();
    virtual void a76();
    virtual void a77();
    virtual void a78();
    virtual void a79();
    virtual void a80();
    virtual void a81();
    virtual void a82();
    virtual void a83();
    virtual void a84();
    virtual void a85();
    virtual void a86();
    virtual void a87();
    virtual void a88();
    virtual void a89();
    virtual void a90();
    virtual void a91();
    virtual void a92();
    virtual void a93();
    virtual void a94();
    virtual void a95();
    virtual void a96();
    virtual void a97();
    virtual void a98();
    virtual void a99();
    virtual void AddObjectToContainer(BoundObj5e5f50*, struct ExtraDataList*, int);
};
struct ListNode5e5f50
{
    bool FUN_008256d0();
    InventoryItemEntry** FUN_006815c0();
    ListNode5e5f50* FUN_00726070();
};
struct TESContainer
{
    TESContainer();
    virtual ~TESContainer();
    InventoryItemEntry* pFirstItem;
    ListNode5e5f50* pListNode;
    ListNode5e5f50* FUN_00717e50();
};
struct TESLeveledList
{
    void PopulateContainerFromReference(void*, TESContainer*);
};
struct LevForm5e5f50
{
    virtual void vfn00();
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    TESLeveledList list;
};
struct DataLeveledList5e5f50
{
    LevForm5e5f50* FUN_00726070();
};
struct InventoryChanges
{
    static InventoryChanges* __cdecl CreateForReference(void*);
};
struct ExtraDataList
{
    ExtraDataList();
    virtual ~ExtraDataList();
    void* m_data;
    unsigned char m_presenceBitfield[0x15];
    void FUN_00419ad0(unsigned short);
    void FUN_00419ed0(Script*);
    void FUN_00419f80(ScriptLocals*);
};
Script* __fastcall FUN_00418800(ExtraDataList*);
Script* __cdecl FUN_004826d0(BoundObj5e5f50*);
bool __cdecl FUN_005e5b80(int, int, void*, int, unsigned char, void**, void*);

// @fnv 0x005e5f50
void __cdecl FUN_005e5f50(void* apPerkOwner, int aeFunctionType, unsigned char acArgumentCount,
                          void** apFunctionArgument, void* apData)
{
    if (!FUN_005e5b80(1, 3, apPerkOwner, aeFunctionType, acArgumentCount, apFunctionArgument, apData))
        return;
    DataLeveledList5e5f50* pfunctionData = (DataLeveledList5e5f50*)apData;
    Actor5e5f50* ptarget = (Actor5e5f50*)*apFunctionArgument;
    TESContainer tempcont;
    pfunctionData->FUN_00726070()->list.PopulateContainerFromReference(apPerkOwner, &tempcont);
    InventoryChanges* pinventory = InventoryChanges::CreateForReference(ptarget);
    ListNode5e5f50* pCurrentElementNext = tempcont.FUN_00717e50();
    if (pinventory)
    {
        while (pCurrentElementNext && !pCurrentElementNext->FUN_008256d0() && *pCurrentElementNext->FUN_006815c0())
        {
            InventoryItemEntry* pdata = *pCurrentElementNext->FUN_006815c0();
            BoundObj5e5f50* pboundObject = 0;
            if (pdata->pObj && pdata->pObj->IsLeveledOrPlayable())
                pboundObject = pdata->pObj;
            if (pboundObject)
            {
                Script* pScript = FUN_004826d0(pdata->pObj);
                if (pScript)
                {
                    ExtraDataList* pExtra = 0;
                    for (int n = 0; n < pdata->m_iCountDelta; n++)
                    {
                        pExtra = new ExtraDataList;
                        pExtra->FUN_00419ad0(1);
                        if (pExtra && !FUN_00418800(pExtra))
                        {
                            pExtra->FUN_00419ed0(pScript);
                            pExtra->FUN_00419f80(FUN_00418800(pExtra)->GetOrCreateScriptLocals());
                        }
                    }
                    ptarget->AddObjectToContainer(pboundObject, pExtra, 1);
                }
                else
                    ptarget->AddObjectToContainer(pboundObject, 0, pdata->m_iCountDelta);
            }
            pCurrentElementNext = pCurrentElementNext->FUN_00726070();
        }
    }
}
