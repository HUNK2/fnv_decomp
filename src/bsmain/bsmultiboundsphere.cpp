// bsmain/bsmultiboundsphere.cpp: BSMultiBoundSphere (1 function)

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

// @fnv 0x004a7bd0
float BSMultiBoundSphere::GetRadius() const
{
    return m_fSphereRadius;
}
