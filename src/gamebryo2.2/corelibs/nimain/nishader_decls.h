// gamebryo2.2/corelibs/nimain/nishader_decls.h: declares NiShader, WaitableObject
#ifndef FNV_NISHADER_PRIVATE_DECLS_H
#define FNV_NISHADER_PRIVATE_DECLS_H

#include "NiRefObject.h"
#include "NiFixedString.h"
class NiShader : public NiRefObject
{
  public:
    NiFixedString m_kName;
    unsigned int m_uiShaderIdentifier;
    bool m_bShaderEnabled;
    bool Initialize();
};
class WaitableObject
{
  public:
    void FUN_00401970();
    void FUN_0040f6e0();
};
class NiAVObject;
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    NiPointer<NiAVObject>& operator=(NiAVObject* object);
};
#endif
