// gamebryo2.2/corelibs/nianimation/nikeyframemanager_decls.h: declares NiGeomMorpherController
#ifndef NIKEYFRAMEMANAGER_DECLS_H
#define NIKEYFRAMEMANAGER_DECLS_H

class GlobalObject_00869f00
{
  public:
    unsigned int GetSize();
};
class NiNode;
template <class T> class NiPointer
{
  public:
    T* operator->() const;

  private:
    T* m_pObject;
};
class NiGeomMorpherController
{
  public:
    unsigned int GetNumTargets() const;

  private:
    unsigned char m_controllerData[0x38];
    NiPointer<NiNode> m_spMorphTargetData;
};
#endif
