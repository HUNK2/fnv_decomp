// bssystem/bstmessagequeue_decls.h: declares QueuedMessage
#ifndef BSTMESSAGEQUEUE_DECLS_H
#define BSTMESSAGEQUEUE_DECLS_H

class QueuedMessage
{
  public:
    QueuedMessage& operator=(const QueuedMessage&);
};
class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
};
template <class T> class BSTFreeListElement
{
  public:
    unsigned char raw[8];
    BSTFreeListElement* pNext;
};
template <class T> class BSTFreeList
{
  public:
    void Elem(BSTFreeListElement<T>*&);
    bool FUN_00905aa0(BSTFreeListElement<T>*&, const T&);
};
template <class T> class BSTCommonLLMessageQueue
{
  public:
    void* vtable;
    unsigned int lock;
    BSTFreeList<T>* pSizeClassFreeList;
    BSTFreeListElement<T>* pHead;
    BSTFreeListElement<T>** m_ppTailLink;
    bool RemoveMessage(T&);
    bool EnqueueMessage(const T&);
};
#endif
