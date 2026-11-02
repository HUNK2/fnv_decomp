// fallout/interface/menus/loadingmenu_packet.h: declares BSThread, NiAVObject, NiNode, RgbaColor, NiGeometryData and more

class BSThread
{
  public:
    enum StackSize
    {
        StackSizeDefault = 0x4000
    };
    virtual ~BSThread();
    unsigned char _threadStorage[0x2c];
    BSThread();
    bool FUN_008905f0();
    void SetName(const char*);
    void Initialize(StackSize, const char*, bool);
    void SetSchedulingPriority(unsigned int);
    void SetThreadPriority(int);
};

class InterfaceManager;
class NiAVObject
{
};
class NiNode
{
  public:
    NiAVObject* FUN_0045bc00(unsigned int);
};
class RgbaColor
{
  public:
    NiNode* FUN_0056c7f0();
};
class NiGeometryData
{
  public:
    RgbaColor* GetColors();
};
class NiProperty
{
  public:
    void FUN_0068c9f0(float);
};
class NiGeometry
{
  public:
    NiProperty* GetProperty(int);
};
InterfaceManager* FUN_004b7210();
unsigned int FUN_004af350();

class GlobalObject_0044f440
{
  public:
    float FUN_00450410();
};
extern GlobalObject_0044f440 g_011da158, g_011da190, g_011da1a0;
extern bool DAT_011a0294;
bool FUN_0070edf0();
unsigned int gm_GetTickCount();

enum ENUM_FORM_ID
{
    FormLoadScreen = 0x4b
};
class TESForm
{
  public:
    virtual void vfn_0();
    static TESForm* GetFormByID(unsigned int);
    ENUM_FORM_ID GetFormType() const;
};
class TESFullName
{
  public:
    const char* GetFullName();
};
class TESLoadScreen : public TESForm
{
  public:
    unsigned char pad[0x14];
    TESFullName fullName;
    bool IsRefFlag400Set();
    bool MatchesFormLocation(TESForm*);
    bool IsDefaultLoadScreen();
    int GetLoadScreenTypeDataType();
};
class BGSPerkEntry
{
  public:
    unsigned char pad[0x18];
    TESFullName fullName;
};
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    T& GetItem();
    BSSimpleList* GetNext();
    unsigned int ItemsInList();
    void AddTail(T const&);
};
int FUN_00408b20(const char*, const char*);

class Tile
{
  public:
    void Set(int, int);
    void Set(int, float, bool);
    void Set(int, const char*, bool);
    void GetFloat(int, int);
    bool FUN_0078a1f0();
};
class BGSSaveLoadGame
{
  public:
    bool FUN_0042ce10();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
class BGSQuestObjective
{
  public:
    const char* GetDisplayText();
};
class GlobalObject_0078d900
{
  public:
    BGSQuestObjective* objective;
};
extern GlobalObject_0078d900 g_011da168;
extern float DAT_011da16c;
extern int DAT_011da170;
class SettingT_GameSettingCollection_
{
  public:
    const char* String();
    union SETTING_VALUE* Int();
};
class GlobalObject_0040c150
{
  public:
    char storage[12];
};
extern GlobalObject_0040c150 g_011d1f8c, g_011d40f0, g_011d2358;
void FUN_0078d670();

class GlobalObject2_0045cfe0
{
  public:
    char storage[12];
};
extern GlobalObject2_0045cfe0 g_011ded5c;
void FUN_0040fca0(unsigned long);

union SETTING_VALUE
{
    unsigned int u;
    int i;
    float f;
};
class GlobalObject_0045cfe0
{
  public:
    char storage[12];
};
extern GlobalObject_0045cfe0 g_011da108, g_011da124, g_011da138;
class ParentSpaceNode;
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    unsigned int GetSize();
    void UpdateEntryValue(unsigned int, unsigned int);
    void Clear(bool);
    unsigned int Add(T&);
};
class NiFormArray
{
  public:
    TESForm*& FUN_00877a30(unsigned int);
};
class BGSMusicType
{
  public:
    class MusicTrack;
};
class ScriptVariableInfo;
unsigned int FUN_0042f5a0(unsigned int, unsigned int);
unsigned int FUN_005a00a0(unsigned int);
class TESLoadScreenFlags
{
  public:
    static bool GetUseLocationSpecificScreensOnly();
    static void SetUseLocationSpecificScreensOnly(bool);
};

class TESQuest : public TESForm
{
  public:
    BGSQuestObjective* GetObjective(unsigned int);
};
class BGSLoadGameBuffer
{
  public:
    unsigned int ReadFormIdentifier();
    void ReadDataBlock(void*, unsigned int);
};
class GlobalObject2_0040c150
{
  public:
    char storage[12];
};
extern GlobalObject2_0040c150 g_011d0c60;
void FUN_004581c0(bool);

class TESDataHandler
{
  public:
    BSSimpleList<TESLoadScreen*>* GetTESLoadScreenList();
};
extern TESDataHandler* g_dataHandler;
class OSGlobals;
extern OSGlobals* g_osGlobals;
class DurationData
{
  public:
    char FUN_00678ce0();
};
extern bool DAT_011d8907;
class NavMeshInfo;
class LoadingMenu
{
  public:
    enum TileIndex
    {
        Tile0 = 0
    };
    unsigned char _padToTiles[0x28];
    Tile* m_pTiles[38];
    char _padToCandidates_padc0[16];
    char m_kFirstTileList[12];
    char m_kSecondTileList[12];
    char m_kThirdTileList[12];
    char m_kFourthTileList[12];
    char m_kFifthTileList[12];
    char m_aeMiscStatIdentifiers[172];
    char m_kLoadingScreenTip[8];
    char m_kLoadingScreenColor[16];
    BSSimpleList<BGSPerkEntry*> candidates;
    BSSimpleList<BGSPerkEntry*>* currentCandidate;
    unsigned char _padToTime[4];
    unsigned int nextTipTime;
    unsigned char _padToExtra[4];
    unsigned int extraCandidates;
    char _padToUsFlags_pad1ec[4];
    void* m_pAlternateTileShaderState;
    char m_kFirstDate[12];
    char m_kSecondDate[12];
    char m_kLoadScreenTextures[16];
    unsigned int m_uiLoadingScreenNumber;
    unsigned short m_usAdditionalFlags;
    unsigned short usFlags;

    void SetTileVisible(TileIndex, bool);
    static void HideTile();
    static void UpdateLoadingScreenThread();
    static void SetLoadingScreenVisible(int);
    void UpdateLoadingScreenTip();
    bool IsLoadScreenValid(TESLoadScreen*);
    void RefreshLoadingScreen();
    bool GetFloat(int);
    void SelectLoadScreens(BSSimpleArray<TESLoadScreen*, 1024>&);
    void CollectLoadScreens(BSSimpleArray<TESLoadScreen*, 1024>&);
    void Update();
    static void UpdateLoadingMenuState();
    static void LoadGame(BGSLoadGameBuffer*);
    void UpdateLoadScreen(TESLoadScreen*, float, int);
    void FUN_0078b100(float, int);
    void UpdateTiles(float, int);
    void FadeSlideTiles(float, int);
    void UpdateLoadingTiles(float, int);
    void SetFloatFlag(int, bool);
    char m_kTileLayouts[912];
    unsigned int m_uiFirstStateValue;
    unsigned int m_uiSecondStateValue;
    int m_iStateFlags;
};

class BGSCameraPath
{
  public:
    BGSCameraPath* GetPrevPath();
};
