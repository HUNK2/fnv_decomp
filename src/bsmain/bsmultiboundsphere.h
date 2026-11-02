// bsmain/bsmultiboundsphere.h: declares BSMultiBoundSphere
#ifndef FNV_BSMULTIBOUNDSHERE_H
#define FNV_BSMULTIBOUNDSHERE_H


#pragma pack(push, 4)

class BSMultiBoundSphere
{
  public:
    float GetRadius() const;

  private:
    unsigned char _pad[0x18];
    float m_fSphereRadius;
};

#pragma pack(pop)

#endif
