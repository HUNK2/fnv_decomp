// fallout_shared/sky/sky_local_types.h: declares NiPoint3
#ifndef FNV_SKY_LOCAL_TYPES_H
#define FNV_SKY_LOCAL_TYPES_H
// Unit-local supersets of canonical leaf types (same layout; see sky_packet.h). Included before the canonical
// headers, which sky_packet.h then includes with these names renamed away.
#pragma pack(push, 4)
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    NiPointer& operator=(T*);
    operator T*() const;
    T* operator->() const;
    bool operator==(T*) const;
    bool operator!=(T*) const;
};
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3(float, float, float);
};
#pragma pack(pop)
#endif
