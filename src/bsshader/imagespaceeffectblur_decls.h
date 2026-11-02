// bsshader/imagespaceeffectblur_decls.h: declares MemoryManager, ImageSpaceManager, NiTexturingProperty, ImageSpaceShaderParam
#ifndef IMAGESPACEEFFECTBLUR_DECLS_H
#define IMAGESPACEEFFECTBLUR_DECLS_H

class MemoryManager
{
  public:
    void* Allocate(unsigned int);
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern float DAT_011ae6c8, DAT_011ae6cc;
class ImageSpaceEffectParam
{
};
class ImageSpaceEffect;
class ImageSpaceManager
{
  public:
    char pad[8];
    ImageSpaceEffect** effects;
    __forceinline ImageSpaceEffect* GetEffect(unsigned int index)
    {
        return effects[index];
    }
};
class ImageSpaceTexture;
class NiTexturingProperty
{
  public:
    enum FilterMode
    {
        FILTER_NEAREST,
        FILTER_BILERP
    };
};
template <class T> class NiTMallocInterface
{
};
template <class T, class A> class NiTArray
{
  public:
    void* vtable;
    T* data;
    unsigned short capacity, size, effective, grow;
    void SetSize(unsigned int);
    // SetAt changes the array storage without retaining the argument reference.
    __declspec(noalias) void SetAt(unsigned int, T const&);
};
class ImageSpaceEffect
{
  public:
    char prefix[24];
    NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> > pEffectParamList;
    NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> > pTextures;
    void SetTextureArrayCount(int);
    void SetEffectParamAt(int, int, int);
    void SetEffectAt(int, ImageSpaceEffect*, ImageSpaceEffectParam*, int);
    void SetTextureArrayAt(int, int, int, NiTexturingProperty::FilterMode, NiTexturingProperty::FilterMode);
};
class ImageSpaceEffectFourTexturePass : public ImageSpaceEffect
{
  public:
    void Setup(ImageSpaceManager*, ImageSpaceEffectParam*);
};
class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
  public:
    char data[0x88];
    ImageSpaceShaderParam();
    static __forceinline void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
    static __forceinline void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
    void AllocateShaderConstants(int, int);
    void SetShaderConstantVector4(int, float, float, float, float);
};
#endif
