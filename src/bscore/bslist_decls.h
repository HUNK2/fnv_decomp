#ifndef BSLIST_DECLS_H
#define BSLIST_DECLS_H

namespace OEI {
namespace IO {
class IORequest;
}
}
template <class T> struct BSListNode
{
    BSListNode* next;
    BSListNode* previous;
    T data;
};
template <class T> class BSPointerListBase
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08(BSListNode<T>*);
    BSListNode<T>* m_pkHead;
    BSListNode<T>* m_pkTail;
    unsigned int m_uiCount;
    T RemoveHead();
};
#endif
