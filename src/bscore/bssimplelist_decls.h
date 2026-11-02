// bscore/bssimplelist_decls.h: declares TESDataHandler
#ifndef FNV_BSSIMPLELIST_DECLS_H
#define FNV_BSSIMPLELIST_DECLS_H

class InventoryStackRecord;
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    BSSimpleList(T& item);
    ~BSSimpleList();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    void AddTail(T& item);
    void AddHead(T& item);
    void RemoveHead();
    void RemoveAll();
};
class TESClass;
class TESDataHandler
{
  public:
    BSSimpleList<TESClass*>* GetTESClassList();
};
#endif
