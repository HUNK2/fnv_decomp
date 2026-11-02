// bsshader/speedtreeshaderproperty_decls.h: declares TESPackage, BSTreeNode
#ifndef SPEEDTREESHADERPROPERTY_DECLS_H
#define SPEEDTREESHADERPROPERTY_DECLS_H

class TESPackage
{
    unsigned char padding[0x7c];
    unsigned int m_uiRefCount;

  public:
    unsigned int GetRefCount();
};
class NiNode;
class BSTreeModel;
template <class T> class NiPointer
{
    T* pointer;

  public:
    T* operator->() const;
};
class BSTreeNode
{
    unsigned char padding[0xe4];
    NiPointer<NiNode> model;

  public:
    BSTreeModel* GetModelFilePath();
};
#endif
