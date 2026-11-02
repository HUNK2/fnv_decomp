// speedtree/librandom_source/idvrandom_decls.h: declares RandomNumberGenerator, Random

class RandomNumberGenerator
{
  public:
    RandomNumberGenerator();
    void SeedRandomGenerator(long seed);
    float GenerateRandomFloat(float low, float high);
};
class Random
{
  public:
    static void Set(double seed);
    static void SetLong(long seed);
};
extern bool DAT_011f8eb8;
extern "C" __int64 __cdecl _time64(__int64*);
