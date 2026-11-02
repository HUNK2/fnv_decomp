// src/fallout/ai/gunwobble.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/gunwobble.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_008d6a80_Obj
{
    void* FUN_006838b0();
};
struct S_008d6a80_Holder
{
    void FUN_004f0110(void* data);
};
extern void* DAT_011e00e0[];
extern char DAT_012681cc;
extern char DAT_011a9448;
S_008d6a80_Obj* FUN_004aae30(void* root, void* name);
void* FUN_00653270(void* rtti, void* obj);

// Looks up the object named by DAT_011e00e0[idx] under root, resolves its holder via FUN_00653270 and passes DAT_011a9448 to FUN_004f0110.
// @fnv 0x008d6a80
void FUN_008d6a80(int iIndex, void* root)
{
    if (DAT_011e00e0[iIndex])
    {
        S_008d6a80_Obj* obj = FUN_004aae30(root, DAT_011e00e0[iIndex]);
        if (obj)
        {
            S_008d6a80_Holder* holder = (S_008d6a80_Holder*)FUN_00653270(&DAT_012681cc, obj->FUN_006838b0());
            if (holder)
                holder->FUN_004f0110(&DAT_011a9448);
        }
    }
}
