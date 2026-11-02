// fallout_shared/animation_local_types.h: declares NiPoint3, NiFixedString
#ifndef ANIMATION_LOCAL_TYPES_H
#define ANIMATION_LOCAL_TYPES_H
// Unit-local supersets of canonical leaf types (same layout; see animation_decls.h). Included before the canonical
// headers, which animation_decls.h then includes with these names renamed away.
#pragma pack(push, 4)
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer();
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
    NiPointer& operator=(const NiPointer&);
};
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    static const NiPoint3 ZERO;
};
class NiFixedString
{
  public:
    char* m_kHandle;
    operator const char*() const;
};
#pragma pack(pop)
#endif
