// gamebryo2.2/corelibs/nianimation/bsmultitargettreadtransfcontroller_decls.h: declares TreadEntry, BSMultiTargetTreadTransfController
class NiInterpolator;
struct TreadEntry
{
    char data[0x34];
};
class BSMultiTargetTreadTransfController
{
    char padding[0x34];
    TreadEntry* entries;

  public:
    NiInterpolator* GetInterpolator(unsigned short index);
};
extern unsigned int DAT_011f36a0;
extern char DAT_00a2d8a0;
extern char DAT_00a2de70;
void __cdecl FUN_00aa2080(void*, void*);
class GlobalObject_00a2e180
{
  public:
    GlobalObject_00a2e180();
};
