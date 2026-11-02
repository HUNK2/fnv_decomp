
// src/havok/physics/utilities/weapons/hkpgravitygun_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/weapons/hkpgravitygun.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/weapons/hkpgravitygun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpgravitygun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpGravityGun.h"
struct FUN_00e45fb0_class
{
    void FUN_00e45e60(int);
    void FUN_00e45fb0(int, int, int);
};
struct DDCC60World
{
    void removeReference();
};
struct FUN_00e45fc0_class
{
    unsigned char m_unknown[0x20];
    DDCC60World** m_kExternalLinks;
    int m_sReferenceCount;

    void RemoveAllReferences(int);
};
struct hkFinishLoadedObjectFlagE463
{
    int m_bFinishing;
};
template <class T> class hkArrayE463
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE463() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
class FUN_00e466a0
{
  public:
    FUN_00e466a0(hkFinishLoadedObjectFlagE463 flag);
    virtual ~FUN_00e466a0();

    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    hkUint8 m_type;
    const char* m_name;
    hkUint8 m_uiKeyboardKey;
    hkArrayE463<void*> m_kListeners;
};
class hkpRigidBodyE463;
class FUN_00e46300 : public FUN_00e466a0
{
  public:
    hkArrayE463<hkpRigidBodyE463*> m_kPickedBodies;

    FUN_00e46300(hkFinishLoadedObjectFlagE463 flag);
    virtual ~FUN_00e46300();
};

#include <xmmintrin.h>
extern double DAT_01016408;

struct Body_e45e
{
    int unk[0x1a0 / 4];
    __m128 m_kInertiaAndMassInv;
    void FUN_00ca88e0(float mass);
    void FUN_00c905b0();
    float getMassInv() const
    {
        float w;
        _mm_store_ss(&w, _mm_shuffle_ps(m_kInertiaAndMassInv, m_kInertiaAndMassInv, 0xff));
        return w;
    }
};

struct World_e45e
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    Body_e45e** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    Body_e45e* FUN_00e45e60(int index);
};
// @fnv 0x00e45e60
Body_e45e* World_e45e::FUN_00e45e60(int index)
{
    Body_e45e** volatile* pdata = (Body_e45e * * volatile*)&m_data;
    Body_e45e* body = (*pdata)[index];
    m_iElementCount--;
    int n = (m_iElementCount - index) * 4;
    Body_e45e** data = *pdata;
    char* dst = (char*)&data[index];
    const char* src = (const char*)&data[index + 1];
    for (int i = 0; i < n; i += 4)
        *(unsigned int*)(dst + i) = *(const unsigned int*)(src + i);
    body->FUN_00ca88e0((float)(body->getMassInv() * DAT_01016408));
    body->FUN_00c905b0();
    return body;
}
