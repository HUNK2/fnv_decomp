#ifndef NAVMESHOBSTACLEMANAGER_LOCAL_TYPES_H
#define NAVMESHOBSTACLEMANAGER_LOCAL_TYPES_H
// Unit-local container/smart-pointer templates (see navmeshobstaclemanager_decls.h). Included before the canonical
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    unsigned int Add(T&);
    unsigned int GetSize();
    void Clear(bool);
    void Remove(unsigned int, bool);
    template <class U> unsigned int Find(U&, unsigned int, bool (*)(U&, U&));
};
template <class T, class A> class NiTArray
{
  public:
    T& GetAt(unsigned int);
};
template <class K, class V> class NiTPointerMap
{
  public:
    void RemoveAll();
};
template <class T> class NiPointer
{
  public:
    T* p[1];
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    NiPointer(const NiPointer&);
};
template <class T> class BSSimpleList
{
  public:
    bool IsEmpty();
    T& GetItem();
    BSSimpleList* GetNext();
    void RemoveAll();
    void Remove(const T&);
    bool IsInList(T&);
    void AddTail(const T&);
    void AddHead(T&);
};
#endif
