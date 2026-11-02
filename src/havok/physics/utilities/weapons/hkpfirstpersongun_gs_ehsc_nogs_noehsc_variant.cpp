
// src/havok/physics/utilities/weapons/hkpfirstpersongun_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/weapons/hkpfirstpersongun.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/weapons/hkpfirstpersongun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpfirstpersongun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpFirstPersonGun.h"
struct FUN_00e463b0_cls
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_0C;

    unsigned int FUN_00e463b0();
};
struct FUN_00e463c0_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Tail(int a);
    void FUN_00e463c0(int a);
};
struct FUN_00cb0b80
{
    char* m_kStringBuffer;
    FUN_00cb0b80(const char* s) throw();
};
template <typename T> struct hkArrayE466
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayE466() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
class hkRefObjE466
{
  public:
    virtual ~hkRefObjE466();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjE466()
    {
        m_sReferenceCount = 1;
    }
};
class FUN_00e46660 : public hkRefObjE466
{
  public:
    volatile unsigned char m_type;
    char unk09, unk0A, unk0B;
    FUN_00cb0b80 m_name;
    unsigned char m_uiKeyboardKey;
    char unk11, unk12, unk13;
    hkArrayE466<void*> m_kListeners;
    FUN_00e46660();
    virtual ~FUN_00e46660();
};
struct FUN_00e466e0_Obj
{
    void FUN_00e466e0();
};
class FUN_00e46750_Obj;
struct VirtualObj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(FUN_00e46750_Obj* a, int b);
};
struct FUN_00c85750_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    VirtualObj* unk10;
};
FUN_00c85750_Obj* __cdecl FUN_00c85750();
class FUN_00e46750_Obj : public hkpFirstPersonGun
{
  public:
    void FUN_00e466e0();
    int FUN_00e46750(unsigned char flag);
};
