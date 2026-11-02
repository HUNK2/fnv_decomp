#ifndef BSTFREELIST_DECLS_H
#define BSTFREELIST_DECLS_H

class QueuedMessage;
template <class T> class BSTFreeListElement
{
  public:
    unsigned char raw[8];
    BSTFreeListElement* pNext;
    void FUN_00905ae0();
};
template <class T> class BSTFreeList
{
  public:
    void Elem(BSTFreeListElement<T>*& element);
    void PushFront(BSTFreeListElement<T>*& element);
};
#endif
