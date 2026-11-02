template <class T> class NiTPointerList;
template <> class NiTPointerList<TESForm*>
{
  public:
    void* Find(TESForm* const&, void*);
};
template <>
class NiTPointerListBase<NiTPointerAllocator<unsigned int>, Script*>
    : public NiTListBase<NiTPointerAllocator<unsigned int>, Script*>
{
  public:
    Script* Remove(Script*&);
    Script* RemoveHead();
    Script* RemoveTail();
    Script* RemovePos(void*&);
    void DeleteItem(NiTListItem<Script*>*);
};
class BSMultiBound;
template <>
class NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<BSMultiBound> >
    : public NiTListBase<NiTPointerAllocator<unsigned int>, NiPointer<BSMultiBound> >
{
  public:
    void AddTail(const NiPointer<BSMultiBound>&);
};
