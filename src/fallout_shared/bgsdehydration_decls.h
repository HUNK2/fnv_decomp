// fallout_shared/bgsdehydration_decls.h: declares BGSTerrainManager, WaitableObject

class BGSTerrainManager
{
  public:
    unsigned int GetMaxLevel();
};
double FUN_00ec6054(double value);
float ConvertDoubleResult(float value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long* value);
unsigned long WaitForSingleObjectEx(long* value);
class WaitableObject
{
  public:
    virtual void vfn_0000();
    virtual void vfn_0004();
    long references;
    void FUN_00401970();
};
