// fallout/interface/interfacemanager_packet.h: declares Interface, InterfaceManager, TESEnchantableForm, MiddleHighProcess, NiPoint2 and more

class NiNode;
class Interface
{
  public:
    NiNode* GetRoot();
    enum enumGamepadButtons
    {
        ButtonZero
    };
};
enum GAMEPAD_BUTTON
{
    GamepadZero
};
class Tile;
class InterfaceManager
{
  public:
    char padding[0x110];
    union
    {
        struct
        {
            int unusedStackSlot;
            int enterStack[10];
        };
        int previousStack[11];
    };
    int GetMenuStackEntry(int);
    int GetTopEnterStackEntry();
    void AddTileIfAbsent(Tile*);
    static float UpdateInterfaceState();
    static void SendGamepadButton(Interface::enumGamepadButtons);
    static GAMEPAD_BUTTON ConvertGamepadButton(Interface::enumGamepadButtons);
    static bool IsInterfaceMenuActive();
};
enum MagicSystem__CastingType
{
    CastingTypeZero
};
class TESEnchantableForm
{
  public:
    void SetCastingType(MagicSystem__CastingType);
};
class MiddleHighProcess
{
  public:
    char padding[0xe4];
    TESEnchantableForm enchantable;
    void SetRunOncePackageIndex(int);
};
class TESIdleForm;
template <class T, int N> class BSSimpleArray
{
  public:
    unsigned int Add(T&);
    bool FUN_009962f0(T&);
};
class GlobalObject_00719b80 : public BSSimpleArray<TESIdleForm*, 1024>
{
};
extern GlobalObject_00719b80 g_011d8b44;
class NiPoint2
{
  public:
    float x, y;
    NiPoint2 operator*(float) const;
};
class BGSPerkEntry;
class EffectSetting;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList* GetNext();
    unsigned int ItemsInList();
};

extern bool FUN_004b71d0();
extern InterfaceManager* FUN_004b7210();
class InputManager
{
  public:
    void FUN_00a25560(GAMEPAD_BUTTON);
};
class OSGlobals
{
  public:
    InputManager* FUN_00877720();
};
extern OSGlobals* g_osGlobals;
extern int FUN_004dc1f0();
extern int FUN_004dc200();
extern const double DAT_0106e7f8;
extern const float DAT_0106ec38;

template <class T> class BSStringT
{
  public:
    const char* String();
};
template <class T> class NiTPointerAllocator
{
};
template <class A, class T> class NiTPointerListBase
{
  public:
    T& GetNext(void*&);
};
class BSOcclusionPlane;
class SystemColorManager
{
  public:
    class SystemColor;
    SystemColor* Find(int);
};
class Tile
{
  public:
    static int GetTraitID(const char*);
};
class ConsoleManager
{
  public:
    static ConsoleManager* Instance(bool);
    bool IsConsoleActive();
};
