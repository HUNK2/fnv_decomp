
// src/unmapped/debugtextactor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/debug/debugtextpages/debugtextactor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_009aae70_Entry
{
    unsigned char flag;
    int unk04;
};
extern S_009aae70_Entry DAT_011a55b4[];

const char* __cdecl CombatWorldState_GetStateValueText(int type, unsigned int value);
const char* __cdecl CombatWorldState_GetStateName(int type);
int __cdecl FUN_00406d00(char* buf, int size, const char* fmt, ...);
unsigned int __cdecl FUN_0044a670(const char* s);
int __cdecl FUN_00406d50(char* dst, unsigned int size, const char* src);

struct S_009aae70
{
    unsigned int FUN_005bd5c0(int type);
    void FormatFlagsString(char* buf, unsigned int size, int type);
};

// @fnv 0x009aae70
void S_009aae70::FormatFlagsString(char* pBuffer, unsigned int size, int type)
{
    unsigned int mask = FUN_005bd5c0(type);
    if (DAT_011a55b4[type].flag)
    {
        bool any = false;
        for (unsigned int uiBit = 0; uiBit < 32; uiBit++)
        {
            if (mask & (1 << uiBit))
            {
                if (!any)
                {
                    FUN_00406d00(pBuffer, size, "%s: %s", CombatWorldState_GetStateName(type), CombatWorldState_GetStateValueText(type, uiBit));
                }
                else
                {
                    char acTemp[260];
                    FUN_00406d00(acTemp, 0x104, ", %s", CombatWorldState_GetStateValueText(type, uiBit));
                    FUN_00406d50(pBuffer, size - FUN_0044a670(pBuffer), acTemp);
                }
                any = true;
            }
        }
        if (!any)
            FUN_00406d00(pBuffer, size, "%s: None", CombatWorldState_GetStateName(type));
    }
    else
    {
        FUN_00406d00(pBuffer, size, "%s: %s", CombatWorldState_GetStateName(type), CombatWorldState_GetStateValueText(type, mask));
    }
}
