// bsshader/imagespaceshaderparam_decls.h: declares ImageSpaceShaderParamFloat
#ifndef IMAGESPACESHADERPARAM_DECLS_H
#define IMAGESPACESHADERPARAM_DECLS_H

#include "layout_support.h"
#include "NiRefObject.h"
#include "MemoryManager.h"
extern "C" void* __cdecl fnv_zlib_memcpy(void*, const void*, unsigned int);
extern unsigned char DAT_011f9440;
class GraphicsRenderer;
class NiD3DShaderConstantMap;
extern GraphicsRenderer* g_pkRenderer;
extern MemoryManager g_memoryManager;

template <> class NiPointer<NiD3DShaderConstantMap>
{
  public:
    NiD3DShaderConstantMap* m_pObject;
    ~NiPointer();
    NiPointer& operator=(NiD3DShaderConstantMap* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                reinterpret_cast<NiRefObject*>(m_pObject)->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                reinterpret_cast<NiRefObject*>(m_pObject)->IncRefCount();
        }
        return *this;
    }
};

struct ImageSpaceShaderParamFloat
{
    float value;
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
};
#endif
