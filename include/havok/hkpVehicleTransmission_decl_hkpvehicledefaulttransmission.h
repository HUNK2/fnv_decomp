// include/havok/hkpVehicleTransmission.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKPVEHICLETRANSMISSION_H
#define FNV_HAVOK_HKPVEHICLETRANSMISSION_H
#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkpVehicleTransmission : public hkReferencedObject
{
  public:
    virtual void T01();
    virtual void T02();
    virtual void T03();
    virtual void T04();
    virtual void T05();
    virtual void T06();
    virtual void T07();
    virtual hkReal getTransmissionRatio(const struct Vehicle* vehicle,
                                        const void* input) const;  // declared for the original code (decl_variants.py)

  public:
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleTransmission[(sizeof(hkpVehicleTransmission) == 0x8) ? 1 : -1];
#endif
