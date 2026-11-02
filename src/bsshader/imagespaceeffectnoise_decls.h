// bsshader/imagespaceeffectnoise_decls.h: declares MemoryManager, ImageSpaceShaderParam, ImageSpaceManager, Effects

class MemoryManager
{
  public:
    void* Allocate(unsigned int);
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
class ImageSpaceEffectParam
{
    char storage[36];
};
class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
    char storage[100];

  public:
    ImageSpaceShaderParam();
    void AllocateShaderConstants(int, int);
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
template <class T> class NiTMallocInterface
{
};
template <class T, class A> class NiTArray
{
    char storage[16];

  public:
    void SetSize(unsigned int);
    void SetAt(unsigned int, const T&);
};
class ImageSpaceTexture;
class ImageSpaceEffect
{
  public:
    char prefix[24];
    NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> > params;
    NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> > textures;
    void SetTextureArrayCount(int);
    void SetEffectParamAt(int, int, int);
    void SetEffectAt(int, ImageSpaceEffect*, ImageSpaceEffectParam*, int);
};
class ImageSpaceManager
{
  public:
    char prefix[8];
    struct Effects
    {
        char prefix[200];
        ImageSpaceEffect* noise;
    }* effects;
};
class NoiseImageSpaceEffect : public ImageSpaceEffect
{
  public:
    void Setup(ImageSpaceManager*, ImageSpaceEffectParam*);
};
