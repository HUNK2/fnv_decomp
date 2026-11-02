// bscore/bsrandom_precipitation.h: declares NiMemObject, BSShaderAccumulator, Precipitation
#ifndef BSRANDOM_PRECIPITATION_H
#define BSRANDOM_PRECIPITATION_H
class NiAVObject;
template <class T> class NiPointer
{
  public:
    NiPointer(T*);
    ~NiPointer();
    NiPointer& operator=(T*);
    T* ptr;
};
class GlobalObject_0048f200
{
  public:
    GlobalObject_0048f200();
    ~GlobalObject_0048f200();
    float xyz[3];
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
namespace BSShaderManager {
enum BATCHRENDERER_CREATION_MODE
{
    Mode99 = 99
};
}
class BSShaderAccumulator : public NiMemObject
{
  public:
    BSShaderAccumulator(BSShaderManager::BATCHRENDERER_CREATION_MODE, unsigned int, unsigned int);
    char storage[0x280];
};
class FUN_00a712f0 : public NiMemObject
{
  public:
    FUN_00a712f0();
    char storage[0x114];
};
class GlobalObject_0048f200_d0049fe00 : public GlobalObject_0048f200
{
  public:
    GlobalObject_0048f200_d0049fe00()
    {}
    ~GlobalObject_0048f200_d0049fe00();
};
class Precipitation
{
  public:
    Precipitation();
    NiPointer<NiAVObject> node;
    int unused;
    GlobalObject_0048f200_d0049fe00 a;
    GlobalObject_0048f200 b;
    NiPointer<NiAVObject> accumulator, object;
};
#endif
