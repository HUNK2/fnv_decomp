// fallout/misc/saveload/bgschangeflags_decls.h: declares FormChangeMask, FormChangeRecord, BGSChangeFlagsState

class GlobalObject_008c71b0
{
  public:
    int value;
    GlobalObject_008c71b0(int value);
};
class FormChangeMask
{
  public:
    unsigned int flags;
    unsigned int FUN_00559450();
    static FormChangeMask HasFormChanged(FormChangeMask changes, FormChangeMask forced, int type, bool enabled);
};
class FormChangeRecord
{
  public:
    unsigned int flags;
    bool FUN_00562210(unsigned int mask);
};
class BGSChangeFlagsState
{
  public:
    unsigned char padding[0x28];
    unsigned int flags;
    void CombineFlags(bool enabled);
};
