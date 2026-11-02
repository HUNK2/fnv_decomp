// gamebryo2.2/corelibs/nianimation/niactormanager_packet.h: declares ActorManagerPacket, NiGlobalStringTable, NiFixedString

class ActorManagerPacket
{
  public:
    static void InitializePoint3();
};
class NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
};
class NiFixedString
{
  public:
    char* m_kHandle;
};
extern NiFixedString EmptyFS;
extern char* DAT_011f3ec0;
extern char* DAT_011f3ec4;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
