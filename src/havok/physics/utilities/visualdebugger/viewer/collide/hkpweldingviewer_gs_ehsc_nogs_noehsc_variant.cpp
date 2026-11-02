// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00dd9380_class
{
    void* FUN_00dd9380(const char* name, void* factory);
};
extern int DAT_01269cd0;
extern int DAT_01268fbc;
void* __cdecl FUN_00d62e20();
void __cdecl RegisterWeldingViewer();
struct S_00d62650_B1
{
    virtual void vfn1();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct S_00d62650_B3
{
    virtual void vfn3();
};
struct S_00d62650_Arg
{
    void __thiscall FUN_00c93920(S_00d62650_B3* p);
};
struct S_00d62650_B2
{
    virtual void DispatchToArg(S_00d62650_Arg* arg);
    int unk04;
};
struct S_00d62650_D : S_00d62650_B1, S_00d62650_B2, S_00d62650_B3
{
    virtual void DispatchToArg(S_00d62650_Arg* arg);
};
// hkpWeldingViewer - virtual slot 2 of the base subobject at +0x20.
// Removes the entity pointer held by this subobject from the world's list.
//   this  -> the base subobject (complete object + 0x20)
//   -0x20 -> the complete object
//   +0x08 -> the pointer that is handed to the list (complete object + 0x28)
struct HKWorldList
{
    void IsEntityAdded(void* entity);
};
struct HKConstraint
{
    int unk00;
    int unk04;
    void* unk08;
    void FUN_00d62680(HKWorldList* list);
};
struct S_00d626b0_Item
{
    void FUN_00c93920(void* apSub);
};
struct S_00d626b0_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    S_00d626b0_Item** m_6c;
    int m_70;
};
struct S_00d626b0_A
{
    virtual void a0();
    int unk04;
};
struct S_00d626b0_B
{
    virtual void b0();
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct S_00d626b0_C
{
    virtual void c0();
    S_00d626b0_Owner* m_24;
};
struct S_00d626b0_R : S_00d626b0_A, S_00d626b0_B, S_00d626b0_C
{
    S_00d626b0_R(int a) throw();
};
struct S_00d626b0_S
{
    virtual void s0();
    S_00d626b0_S() throw()
    {}
};
struct FUN_00d626b0 : S_00d626b0_R, S_00d626b0_S
{
    FUN_00d626b0(int a) throw();
    virtual void a0();
    virtual void b0();
    virtual void c0();
    virtual void s0();
};
class D62720Listener
{
  public:
    virtual ~D62720Listener() throw()
    {}
};
class D62720Island
{
  public:
    void removeListener(D62720Listener* listener);
};
struct D62720World
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    D62720Island** m_islands;
    int m_iIslandCount;
};
class D62720BaseA
{
  public:
    virtual ~D62720BaseA();

    int unk04;
};
class D62720BaseB
{
  public:
    virtual void unk00();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class D62720BaseC
{
  public:
    virtual void unk00();
};
class D62720Base : public D62720BaseA, public D62720BaseB, public D62720BaseC
{
  public:
    virtual ~D62720Base();

    D62720World* m_pOwningWorld;
};
class FUN_00d62720 : public D62720Base, public D62720Listener
{
  public:
    virtual ~FUN_00d62720() throw();
};
// The factory that creates one hkpWeldingViewer-like record for the physics
// world: it asks the world manager's pool for a 0x2c byte block, stamps the
// block size into the record header and then runs the record's constructor.
struct Viewer;
struct Pool
{
    virtual void dummy0();
    virtual Viewer* alloc0x2c(int n);
};
struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Pool* unk10;
};
struct Viewer
{
    int unk00;
    unsigned short unk04;
    void* ctor0d626b0(void* arg);
};
extern "C" void* __cdecl FUN_00c85750();
void* __cdecl FUN_00d62e20_impl(void* arg);
extern int g_D62E80Value;
int __cdecl FUN_00d62e80();
// FUN_00d62e90 : MSVC this-adjusting thunk  (sub ecx, 0x20 ; jmp <impl>)
struct A1_00d62e90
{
    A1_00d62e90();
    virtual void FUN_00d62e90();
    char pad[0x1c];
};
struct A2_00d62e90
{
    A2_00d62e90();
    virtual void FUN_00d62e90();
};
struct Own_00d62e90 : A1_00d62e90, A2_00d62e90
{
    Own_00d62e90();
    virtual void key_fn();
// @fnv 0x00d62e90
    void FUN_00d62e90();
};
Own_00d62e90::Own_00d62e90()
{}
void Own_00d62e90::key_fn()
{}
Own_00d62e90* make_00d62e90()
{
    static Own_00d62e90 o;
    return &o;
}
struct D62EA0Primary
{
    virtual void vfunc00();
    virtual void FUN_00d62ea0();

    int unk04;
};
struct D62EA0Secondary
{
    virtual void FUN_00d62ea0();
};
struct D62EA0Object : D62EA0Primary, D62EA0Secondary
{
    D62EA0Object();

// @fnv 0x00d62ea0
    virtual void FUN_00d62ea0();
};
D62EA0Object::D62EA0Object()
{}
// FUN_00d62eb0 : MSVC this-adjusting thunk  (sub ecx, 0x28 ; jmp <impl>)
struct A1_00d62eb0
{
    A1_00d62eb0();
    virtual void FUN_00d62eb0();
    char pad[0x24];
};
struct A2_00d62eb0
{
    A2_00d62eb0();
    virtual void FUN_00d62eb0();
};
struct Own_00d62eb0 : A1_00d62eb0, A2_00d62eb0
{
    Own_00d62eb0();
    virtual void key_fn();
// @fnv 0x00d62eb0
    void FUN_00d62eb0();
};
Own_00d62eb0::Own_00d62eb0()
{}
void Own_00d62eb0::key_fn()
{}
Own_00d62eb0* make_00d62eb0()
{
    static Own_00d62eb0 o;
    return &o;
}
