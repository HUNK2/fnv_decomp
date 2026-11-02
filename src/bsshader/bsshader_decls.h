#ifndef BSSHADER_DECLS_H
#define BSSHADER_DECLS_H
#include "layout_support.h"
class NiD3DPass;
// Passes use the renderer pool reference count, not NiRefObject's atomic count.
template <> class NiPointer<NiD3DPass>
{
  public:
    NiD3DPass* m_pObject;
    NiPointer();
    ~NiPointer();
    NiPointer& operator=(NiD3DPass* object);
};
#include "bsshader_pass_layout.h"
#include "bsshader_shader_layout.h"
inline NiPointer<NiD3DPass>& NiPointer<NiD3DPass>::operator=(NiD3DPass* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            m_pObject->DecRefCount();
        m_pObject = object;
        if (object)
            ++object->m_uiRefCount;
    }
    return *this;
}
#endif
