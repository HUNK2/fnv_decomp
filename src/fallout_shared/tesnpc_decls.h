// fallout_shared/tesnpc_decls.h: declares TESNPC
#ifndef FNV_TESNPC_DECLS_H
#define FNV_TESNPC_DECLS_H

class NiAVObject;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer<T>& operator=(T* object);
    NiPointer<T>& operator=(const NiPointer<T>& other);
};
class TESNPC
{
  public:
    char prefix[0x1c4];
    NiPointer<NiAVObject> head;
    NiPointer<NiAVObject> headCopy;
    void ResetFaceGen();
};
#endif
