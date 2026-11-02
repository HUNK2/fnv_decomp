// fallout/ai/falloutcharacterprogression_decls.h: declares NiNodeBooleanState

class NiNode;
template <class T> class NiPointer
{
  public:
    T* pObject;
    T* operator->() const;
};

class NiNodeBooleanState
{
  public:
    NiPointer<NiNode> pData;
    bool GetBooleanValue();
};
