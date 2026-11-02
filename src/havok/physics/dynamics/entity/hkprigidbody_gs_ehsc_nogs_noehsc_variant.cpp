
// src/havok/physics/dynamics/entity/hkprigidbody_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/entity/hkprigidbody.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/entity/hkprigidbody.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/entity/hkprigidbody.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00ca86c0_class
{
    unsigned int __thiscall FUN_00ca86c0();
};
struct FUN_00ca88c0_Class
{
    void FUN_00ca88c0(float f);
};
struct FUN_00ca80c0_Class
{
    int __fastcall FUN_00ca80c0();
};
struct FUN_00ca8900_Class
{
    void FUN_00ca8900(float f, int i);
};
struct FUN_00ca8910_class
{
    void FUN_00ca8910(float v);
};
struct FUN_00ca80b0_cls
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
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int m_iValueAtF0;

    int* FUN_00ca80b0();
};
extern float DAT_01016248;
struct Vector3
{
    float x, y, z;
};
struct Output
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48;
    float value;
};
inline float lowerPair(float left, float right)
{
    return left < right ? left : right;
}
inline float lowerPairReversed(float left, float right)
{
    return left > right ? right : left;
}
void __fastcall ComputeScaledMinimum(const Vector3* values, Output* result);
struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};
struct Subobject
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void update(unsigned int value);
};
struct Owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    Subobject subobjectE0;
    void FUN_00ca8150(unsigned int value, Vec4* result);
    void FUN_00ca85f0(unsigned int value);
};
struct CA86E0Object
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char unkE8;
    unsigned char unkE9;
    unsigned char unkEA;
    unsigned char unkEB;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    void* unk1F8;

    void* FUN_00ca86e0();
};
struct AudioInterface;
struct AudioInterfaceVTable
{
    void* slot00;
    void* slot04;
    void* slot08;
    void* slot0C;
    void* slot10;
    void* slot14;
    void* slot18;
    void* slot1C;
    void* slot20;
    void* slot24;
    void* slot28;
    void* slot2C;
    void(__thiscall* dispatch)(AudioInterface*, int);
};
struct AudioInterface
{
    AudioInterfaceVTable* vtbl;
};
struct FUN_00ca8800_Class
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    AudioInterface interfaceE0;
    void FUN_00ca8800(int value);
};
extern "C" void __cdecl FUN_00ca8700(FUN_00ca8800_Class* self);
struct CA8830Member
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void setValue(int value);
};
struct CA8830Object;
void __cdecl FUN_00ca8700(CA8830Object* obj);
struct CA8830Object
{
    char unk000[0xe0];
    CA8830Member m_kMemberDescriptor;

    void FUN_00ca8830(int value);
};
struct SubObject;
typedef void(__thiscall* SubDoFn)(SubObject* apThis, int aiFirst, int aiSecond);
struct SubObjectVtbl
{
    void* fn00;
    void* fn04;
    void* fn08;
    void* fn0c;
    void* fn10;
    void* fn14;
    void* fn18;
    void* fn1c;
    void* fn20;
    void* fn24;
    void* fn28;
    void* fn2c;
    void* fn30;
    void* fn34;
    SubDoFn Do;
};
struct SubObject
{
    SubObjectVtbl* m_pVtbl;
};
void __cdecl FUN_00ca8700(void* apOwner);
struct FUN_00ca8860_cls
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
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    SubObject m_sub;
    void FUN_00ca8860(int aiFirst, int aiSecond);
};
struct CA8B80Point3
{
    float x;
    float y;
    float z;
};
struct CA8B80Command
{
    unsigned char m_type;
    void* m_pOwnerObject;
    float x;
    float y;
    float z;
};
struct CA8B80Queue
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    void* m_bSlotEnabled;

    void Push(CA8B80Command* pkCommand);
};
struct CA8B80Handler
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void SetPosition(const CA8B80Point3& kPos);
};
struct CA8B80Object
{
    int unk00;
    int unk04;
    CA8B80Queue* m_queue;
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    CA8B80Handler m_handler;

    void Update();
    void FUN_00ca8b80(const CA8B80Point3& kPos);
};
struct FUN_00ca9240_Base
{
    int unk04;
    unsigned char type;
    FUN_00ca9240_Base(int a, int b, int c);
    virtual void unk00();
};
struct FUN_00ca9240 : FUN_00ca9240_Base
{
    FUN_00ca9240(int a, int b);
    virtual void unk04();
};
struct BaseRecord
{
    virtual void v00();

    int m_i04;
    char m_c08;

    BaseRecord(void* apFirst, void* apSecond, int aiFlag);
};
struct FUN_00ca9270 : BaseRecord
{
    FUN_00ca9270(void* apFirst, void* apSecond);
};
struct FUN_00ca80a0_base
{
    virtual ~FUN_00ca80a0_base();
};
struct FUN_00ca80a0_cls : FUN_00ca80a0_base
{
    virtual ~FUN_00ca80a0_cls();
};
struct S_00ca8630_Owner
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned char unk300;
    unsigned char unk301;
    unsigned char unk302;
    unsigned char unk303;
    unsigned char unk304;
    unsigned char unk305;
    unsigned char unk306;
    unsigned char unk307;
};
struct S_00ca8630_Sub
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned short unk0a;
    unsigned short unk0c;
    void SetFlagBits(int a, int b, int c);
    __forceinline void Set(unsigned char v, int a, int b, int c)
    {
        unk09 = v;
        SetFlagBits(a, b, c);
    }
};
struct S_00ca8630_Class
{
    unsigned int unk00;
    unsigned int unk04;
    S_00ca8630_Owner* unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned char unkd4;
    unsigned char unkd5;
    unsigned char unkd6;
    unsigned char unkd7;
    unsigned int unkd8;
    unsigned int unkdc;
    S_00ca8630_Sub unke0;
    void FUN_00ca8630(bool f);
};
struct CA8890Member
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void setValue(int value);
};
struct CA8890Object;
void __cdecl FUN_00ca8700(CA8890Object* obj);
struct CA8890Object
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    CA8890Member m_kMemberDescriptor;

    void FUN_00ca8890(int value);
};
struct SpawnedSub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(float f);
};
struct FUN_00ca88e0_cls
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    SpawnedSub m_sub;

    void FUN_00ca88e0(float f);
};
struct CA92A0Allocator;
struct CA92A0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CA92A0Allocator* m_pStreamAllocator;

    CA92A0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" CA92A0MemoryRouter& __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(CA92A0Allocator* alloc, void* array, int numElements, int sizeElem);
struct CA92A0Element
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
};
struct CA92A0Array
{
    CA92A0Element* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void reserve(CA92A0Allocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(CA92A0Element));
        }
    }

    __forceinline CA92A0Array& operator=(const CA92A0Array& a)
    {
        CA92A0Allocator& alloc = FUN_00c85750().heap();
        const int oldSize = m_iElementCount;
        const int newSize = a.m_iElementCount;
        const int copiedSize = newSize > oldSize ? oldSize : newSize;
        reserve(alloc, newSize);
        {
            const CA92A0Element* src = a.m_data;
            CA92A0Element* dst = m_data;
            for (int i = 0; i < copiedSize; i++)
                dst[i] = src[i];
        }
        {
            const CA92A0Element* src = a.m_data + copiedSize;
            CA92A0Element* dst = m_data + copiedSize;
            for (int i = 0; i < newSize - copiedSize; i++)
                new (dst + i) CA92A0Element(src[i]);
        }
        m_iElementCount = newSize;
        return *this;
    }
};
struct CA92A0Object
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
    int unk6C;
    int unk70;
    int unk74;
    CA92A0Array m_entries;

    void CopyEntriesFrom(const CA92A0Object* other);
};
struct CA92A0Allocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int auiSize);
};
extern int DAT_010c6c64;
static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    do
    {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d += 4;
        s += 4;
    } while (--numQuads > 0);
}
__declspec(align(16)) struct FnvScratch
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    void FUN_00cf5ea0();
};
struct FnvSubObj
{
    void FUN_00cb0c10(unsigned int auiFlags);
};
struct FnvThing
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* v0C(void* pOwner);
};
struct FUN_00ca90c0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    FUN_00ca90c0_cls* Clone();
    void WriteToInfo(FnvScratch* pScratch);
    FUN_00ca90c0_cls* FUN_00ca8c90(FnvScratch* pScratch);
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual int v10();
    void CopyEntriesFrom(FUN_00ca90c0_cls* pSrc);
};
class hkBoolCA8B
{
  public:
    hkBoolCA8B(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};
class hkpShapeContainerCA8B
{
  public:
    virtual ~hkpShapeContainerCA8B();
    virtual int GetNumChildShapes() const;
};
class hkpShapeCA8B
{
  public:
    virtual ~hkpShapeCA8B();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual const hkpShapeContainerCA8B* GetShapeContainer() const;
    int unk04;
    int unk08;
    int m_type;
};
class hkpShapeCollectionCA8B : public hkpShapeCA8B, public hkpShapeContainerCA8B
{
};
class HostCA8B
{
  public:
    int unk00, unk04, unk08, unk0C;
    const hkpShapeCA8B* m_pCollisionShape;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC;
    int unkD0, unkD4, unkD8, unkDC, unkE0, unkE4;
    unsigned char m_bFlag;

    hkBoolCA8B FUN_00ca8bf0() const;
};

#include <xmmintrin.h>
#include <math.h>
extern "C" int DAT_01268370;
extern "C" double __cdecl sqrt(double);
static inline float CA8Sqrtf(float x)
{
    return ((float)sqrt((double)x));
}
static inline float CA8Sqrt(float r)
{
    return CA8Sqrtf(r);
}
static inline float CA8Max2(float a, float b)
{
    return (a > b) ? a : b;
}

__declspec(align(16)) struct CA8Vec4
{
    float x;
    float y;
    float z;
    float w;
};

__declspec(align(16)) struct CA8Aabb
{
    CA8Vec4 m_kMinimumCorner;
    CA8Vec4 m_kMaximumCorner;
};

struct CA8Shape
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void getAabb(void* t, float tol, CA8Aabb* out);
};

struct CA8Owner
{
    unsigned int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    unsigned int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    unsigned int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    unsigned int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    unsigned int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    unsigned int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    unsigned int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    unsigned int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    unsigned int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    unsigned int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    unsigned int unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    unsigned int unk160, unk164, unk168, unk16C;
    CA8Vec4 m_170;
    unsigned int unk180, unk184, unk188, unk18C;
    float m_190;

    void FUN_00ca8150(CA8Shape* seg, CA8Vec4* dst);
};

// @fnv 0x00ca8150
void CA8Owner::FUN_00ca8150(CA8Shape* seg, CA8Vec4* dst)
{
    CA8Aabb pair;
    seg->getAabb(&DAT_01268370, 0.0f, &pair);
    __m128 a = *(const __m128*)&pair.m_kMinimumCorner;
    __m128 b = *(const __m128*)&pair.m_kMaximumCorner;
    _mm_store_ps(&dst->x, _mm_sub_ps(b, a));

    CA8Vec4& p = pair.m_kMinimumCorner;
    p = m_170;
    __m128 pv = _mm_load_ps(&p.x);
    __m128 d0 = _mm_sub_ps(b, pv);
    __m128 d1 = _mm_sub_ps(a, pv);
    __m128 x0 = _mm_mul_ps(d0, d0);
    float db;
    _mm_store_ss(&db, _mm_add_ss(_mm_shuffle_ps(x0, x0, 0xaa), _mm_add_ss(_mm_shuffle_ps(x0, x0, 0x55), x0)));
    __m128 x1 = _mm_mul_ps(d1, d1);
    float da;
    _mm_store_ss(&da, _mm_add_ss(_mm_shuffle_ps(x1, x1, 0xaa), _mm_add_ss(_mm_shuffle_ps(x1, x1, 0x55), x1)));

    m_190 = CA8Sqrt(CA8Max2(db, da));
}

struct __declspec(align(16)) V181
{
    float x, y, z, w;
};
struct Matrix181
{
    V181 x, y, z;
};
struct Transform181
{
    V181 x, y, z, t;
};
struct Ref181
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};
struct UFloat181
{
    unsigned char value;
    void FUN_00ca9360(const float* value) throw();
};
struct Motion181
{
    int unk00, unk04;
    unsigned char type, unk09;
    unsigned short unk0a;
    int unk0c;
    Transform181 transform;
    int unk50;
    int unk54;
    int unk58;
    float penetrationDepth;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    float linearDamping, angularDamping;
    UFloat181 maxLinear, maxAngular;
    unsigned short unkbe;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    unsigned short unk11c, solverDeactivation;
    int unk120, unk124, unk128, unk12c;
    void FUN_00c86420(int) throw();
};
struct FixedMotion181 : Motion181
{
    FixedMotion181(const V181*, const V181*) throw();
};
inline void* operator new(unsigned int, void* memory) throw()
{
    return memory;
}
struct CInfo181
{
    unsigned int userData;
    void* shape;
    Ref181* localFrame;
    unsigned char response, unk0d;
    unsigned short responseCount;
    V181 position, rotation, linearVelocity, angularVelocity;
    Matrix181 inertia;
    V181 centerOfMass;
    float mass, linearDamping, angularDamping;
    unsigned short unk9c, solverDeactivation;
    float friction, restitution, maxLinear, maxAngular, penetrationDepth;
    signed char motionType;
    unsigned char enableDeactivation;
    signed char deactivationClass, quality;
    unsigned char removalLevel, responseModifier;
    signed char shapeKeys;
    unsigned char forceCollide;
};
struct Root181
{
    virtual void slot0();
    int unk04, unk08, unk0c;
};
struct Entity181 : Root181
{
    void* shape;
    int unk14;
    Transform181* transform;
    int unk1c;
    unsigned char unk20, flags, unk22, unk23;
    int unk24;
    unsigned short unk28;
    unsigned char quality, unk2b;
    unsigned int userData;
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
    float penetrationDepth;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    unsigned char response, unk8d;
    unsigned short unk8e;
    float friction, restitution;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    unsigned short unka8, responseCount;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    unsigned char removalLevel, shapeKeys, responseModifier, unkd3;
    int unkd4, unkd8, unkdc;
    Motion181 motion;
    Ref181* localFrame;
    void FUN_00c9cce0(void* shape) throw();
};
void __cdecl FUN_00ca8240(int type, const V181* position, const V181* rotation, float mass, const Matrix181* inertia,
                          const V181* center, float maxLinear, float maxAngular, Motion181* motion) throw();
unsigned char __cdecl GetSubtreeDepth(void* shape) throw();
extern float DAT_0104da48;
struct Error181
{
    virtual void unknown0();
    virtual void unknown4();
    virtual void unknown8();
    virtual void Report(int severity, unsigned int id, const char* text, const char* file, int line) throw();
};
extern Error181* DAT_01268360;
struct ErrorStream181
{
    void* vptr;
    char* buffer;
    int length, capacity;
    ErrorStream181(char* buffer, int capacity) throw();
    void FUN_00cc01c0(const char* text) throw();
    void FUN_00cc00e0() throw();
};
static __declspec(noinline) void ComputeScaledMinimum(Output* coll, const V181& he)
{
    float lo = lowerPair(he.x, lowerPair(he.y, he.z));
    float hi = he.x > he.y ? he.x : he.y;
    if (he.z > hi)
        hi = he.z;
    coll->value = lowerPairReversed(hi * DAT_01016248, lo);
    coll->unk48 = coll->unk44;
}
struct S00ca8c90_Body : Entity181
{
    virtual void slot0();
    S00ca8c90_Body* FUN_00ca8c90(const CInfo181& info);
    void OnTrigger(const V181*) throw();
    void FUN_00561800(const V181*) throw();
    void FUN_00ca8630(bool enabled) throw();
    void FUN_00ca8150(void* shape, V181* result) throw();
};
extern void* DAT_010c7888;
// @fnv 0x00ca8c90
S00ca8c90_Body* S00ca8c90_Body::FUN_00ca8c90(const CInfo181& info)
{
    FUN_00c9cce0(info.shape);
    *(void**)this = &DAT_010c7888;
    response = info.response;
    responseCount = info.responseCount;
    userData = info.userData;
    Ref181* frame = info.localFrame;
    if (frame)
    {
        frame->FUN_00c90510();
        if (localFrame)
            localFrame->removeReference();
        localFrame = frame;
        frame->FUN_00c90510();
    }
    if (info.motionType == 5)
    {
        FixedMotion181* fixed = new (&motion) FixedMotion181(&info.position, &info.rotation);
        fixed->maxLinear.FUN_00ca9360(&info.maxLinear);
        fixed->maxAngular.FUN_00ca9360(&info.maxAngular);
        fixed->FUN_00c86420(1);
        transform = &motion.transform;
        if (info.penetrationDepth <= 0.0f)
            penetrationDepth = DAT_0104da48;
        else
            penetrationDepth = info.penetrationDepth;
    }
    else
    {
        FUN_00ca8240(info.motionType, &info.position, &info.rotation, info.mass, &info.inertia, &info.centerOfMass,
                     info.maxLinear, info.maxAngular, &motion);
        motion.FUN_00c86420(info.deactivationClass);
        OnTrigger(&info.linearVelocity);
        FUN_00561800(&info.angularVelocity);
        transform = &motion.transform;
        penetrationDepth = info.penetrationDepth;
    }
    FUN_00ca8630(info.enableDeactivation != 0);
    motion.linearDamping = info.linearDamping;
    motion.angularDamping = info.angularDamping;
    if (shape)
    {
        V181 halfExtents;
        FUN_00ca8150(shape, &halfExtents);
        if (penetrationDepth <= 0.0f)
            ComputeScaledMinimum(reinterpret_cast<Output*>(&shape), halfExtents);
    }
    if (info.quality != -1)
        quality = info.quality;
    else if (motion.type == 5)
        quality = 0;
    else
        quality = (info.motionType == 4) ? 1 : 2;
    removalLevel = info.removalLevel;
    if (info.forceCollide)
        flags |= 1;
    friction = info.friction;
    restitution = info.restitution;
    motion.solverDeactivation = info.solverDeactivation;
    if (info.shapeKeys >= 0)
    {
        shapeKeys = info.shapeKeys;
        if (shapeKeys > 0 && shapeKeys < GetSubtreeDepth(info.shape))
        {
            char buffer[512];
            ErrorStream181 stream(buffer, 512);
            stream.FUN_00cc01c0(
                "Shape key storage insufficient to store all possible branches. This may cause truncation of the shape key information.");
            DAT_01268360->Report(1, 0x458a1bb2, buffer, ".\\Entity\\hkpRigidBody.cpp", 329);
            stream.FUN_00cc00e0();
        }
    }
    else
        shapeKeys = GetSubtreeDepth(info.shape);
    responseModifier = info.responseModifier;
    return this;
}
