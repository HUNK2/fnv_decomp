// fallout_shared/miscstats_decls.h: declares MiscStatManager, MiscStatEntry, ChallengeManager, Menu, Tile and more
#ifndef MISCSTATS_DECLS_H
#define MISCSTATS_DECLS_H

class MiscStatManager
{
  public:
    enum MiscStat
    {
        MS_COUNT = 43
    };
    static void AddMiscStat(MiscStat id, int delta);
};
struct MiscStatEntry
{
    const char* name;
    int value;
};
extern "C" MiscStatEntry* DAT_011c6d50[43];
int FUN_004d5e00();
int Warning(const char*, ...);
class TESForm;
enum CHALLENGE_TYPE
{
    CHALLENGE_MISCSTAT = 11
};
class ChallengeManager
{
  public:
    static bool UpdateChallengeProgress(CHALLENGE_TYPE, int, TESForm*, TESForm*, unsigned short, unsigned short,
                                        unsigned short);
};
class Menu
{
};
class Tile
{
  public:
    static Tile* FindMenuById(int);
    Menu* GetMenu();
};
class StatsMenu : public Menu
{
  public:
    void RefreshMiscStat(MiscStatManager::MiscStat);
};
#endif
