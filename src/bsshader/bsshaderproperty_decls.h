// bsshader/bsshaderproperty_decls.h: declares BSShaderPropertyLightSlot, BSShaderProperty
#ifndef FNV_BSSHADERPROPERTY_DECLS_H
#define FNV_BSSHADERPROPERTY_DECLS_H

#include "MemoryManager.h"

extern MemoryManager g_memoryManager;
void __cdecl operator delete(void*);
class NiGeometry;
class ShadowSceneLight;

// Trivial pointer slots let the shader's private allocator own the light array.
// The storage contains only the light pointer, with no per-array lifetime cookie.
struct BSShaderPropertyLightSlot
{
    ShadowSceneLight* light;
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
};
FNV_STATIC_ASSERT(sizeof(BSShaderPropertyLightSlot) == sizeof(ShadowSceneLight*));

class BSShaderProperty
{
  public:
    class ShaderPassEntry;
    class ShaderPassList;
};

class BSShaderProperty::ShaderPassEntry
{
  public:
    NiGeometry* m_pShaderGeometry;
    unsigned short m_usShaderPassType;
    unsigned char m_ucLightIndex;
    bool m_bIsBest;
    bool m_bRendered;
    unsigned char m_ucLightCount;
    unsigned char m_ucLightCapacity;
    unsigned char m_ucPassIndex;
    ShadowSceneLight** m_ppShadowSceneLights;

    ShaderPassEntry(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ...);
    void __cdecl FUN_00ba8c50(unsigned char, ShadowSceneLight*, ...);
    void SetPassEnum(unsigned short value)
    {
        m_usShaderPassType = value;
    }
    void SetFirstPass(bool value)
    {
        m_bIsBest = value;
    }
    void SetGeometry(NiGeometry* value)
    {
        m_pShaderGeometry = value;
    }
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
};

template <> class NiTArray<BSShaderProperty::ShaderPassEntry*, NiTNewInterface<BSShaderProperty::ShaderPassEntry*> >
{
  public:
    virtual ~NiTArray();
    BSShaderProperty::ShaderPassEntry** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00ba8d30(unsigned int);
    void SetAt(unsigned int, BSShaderProperty::ShaderPassEntry*&);
    unsigned int Add(BSShaderProperty::ShaderPassEntry* item)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_00ba8d30(index + m_usGrowBy);
        SetAt(index, item);
        return index;
    }
};

class BSShaderProperty::ShaderPassList
{
  public:
    NiTObjectArray<ShaderPassEntry*> m_kRenderPasses;
    unsigned int iSize;
    void Add(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*,
             ShadowSceneLight*);
};
FNV_STATIC_ASSERT(sizeof(BSShaderProperty::ShaderPassEntry) == 16);
FNV_STATIC_ASSERT(sizeof(BSShaderProperty::ShaderPassList) == 20);
#endif
