
// src/fallout_shared/tesobjectarma_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectarma.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesobjectarma_load.h"
class TESForm;
class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};
class TESForm
{
  public:
    virtual ~TESForm();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void readOBNDSubRecord(TESFile*);
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual const char* GetEditorID();
    virtual bool SetEditorID(const char*);
    void LoadRecordHeader(TESFile*);
    void SetFormType(ENUM_FORM_ID);
    void SetInitializationState(bool initialized);
};
class TESBipedModelForm
{
  public:
    unsigned char prefix[4];
    unsigned int bipedFlags;
    unsigned char m_ucBipedModelData;
    unsigned char padding[3];
    TESModelTextureSwap bipedModel[2];
    TESModelTextureSwap worldModel[2];
    TESTexture1024 m_kIcon[2];
    BGSMessageIcon messageIcon[2];
    TESModel m_kFaceGenModel;
    void InitItem(TESForm* form);
};
class BGSDestructibleObjectForm
{
  public:
    unsigned char bytes[8];
    static void LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
    void InitItem(TESForm* form);
};
class TESObjectARMA : public TESForm
{
  public:
    unsigned char padToBiped[0x6c];
    TESBipedModelForm biped;
    BGSDestructibleObjectForm destructible;
    BGSEquipType equipType;
    unsigned char padToData[0x1c];
    ArmorData data;
    bool Load(TESFile* file);
    void ResetFormData();
    void InitItem();
};
extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
extern int __cdecl Warning(const char* format, ...);
struct TESObjectARMO
{
    TESObjectARMO();
    ~TESObjectARMO();
};
struct SFTX
{
    void SetFormType(int);
};
extern int DAT_0102a214;
extern int DAT_0102a228;
extern int DAT_0102a23c;
extern int DAT_0102a250;
extern int DAT_0102a264;
extern int DAT_0102a278;
extern int DAT_0102a2a4;
extern int DAT_0102a2b8;
extern int DAT_0102a2d8;
extern int DAT_0102a2f0;
extern int DAT_0102a304;
extern int DAT_0102a31c;
struct FUN_00511e40
{
    TESObjectARMO armo;
    FUN_00511e40();
};
struct FUN_00484d60_holder
{
    void SaveIfChanged(unsigned int);
};
struct FUN_0048ea40_holder
{
    void FUN_0048ea40(unsigned int);
};
struct FUN_005144c0_shell
{
    void FUN_005144c0(unsigned int flags);
};
struct BGSLoadFormBuffer;
struct TESValueFormLoadGame
{
    void LoadGame(BGSLoadFormBuffer*);
};
struct TESFormBufferAccess
{
    void LoadGame(BGSLoadFormBuffer*);
};
struct FUN_005160a0_shell : TESObjectARMO
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

// MSVC adjustor thunk: the primary base occupies 0x58 bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_005129c0();
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
};

struct SecondaryBase
{
    virtual void FUN_005129c0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005129c0
    virtual void FUN_005129c0();
};

Derived::Derived()
{}

// FUN_005129d0 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x58 ; jmp <final overrider>
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot through two bases: the slot of the second base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, size of the
// primary base) and tail-jumps to the implementation.
//
// The subtracted offset is therefore the size of the primary base: a vtable
// pointer plus 21 int members (4 + 84 = 0x58 bytes). Both bases declare the
// same virtual function; the derived class redeclares it and defines only its
// constructor, which is what makes the compiler emit the vtables and the
// adjusting thunk.
struct ArmaPrimaryBase
{
    virtual void FUN_005129d0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
};

struct ArmaSecondaryBase
{
    virtual void FUN_005129d0();
};

struct ArmaDerived : ArmaPrimaryBase, ArmaSecondaryBase
{
    ArmaDerived();
// @fnv 0x005129d0
    virtual void FUN_005129d0();
};

ArmaDerived::ArmaDerived()
{}

namespace fnv_005129e0 {
// FUN_005129e0 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x58 ; jmp <final overrider>
//
// MSVC emits such a thunk in the vtable of a class that inherits the same
// virtual slot from two bases: the slot of the second base holds a small
// stub that moves `this` back onto the complete object (sub ecx, sizeof of
// the primary base)) and tail-jumps to the implementation.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 21 int members (4 + 84 = 0x58 bytes).
// Both bases declare the same virtual function; the derived class redeclares
// it and defines only its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct ArmaPrimaryBase
{
    virtual void FUN_005129e0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
};

struct ArmaSecondaryBase
{
    virtual void FUN_005129e0();
};

struct ArmaDerived : ArmaPrimaryBase, ArmaSecondaryBase
{
    ArmaDerived();
// @fnv 0x005129e0
    virtual void FUN_005129e0();
};

ArmaDerived::ArmaDerived()
{}
}  // namespace fnv_005129e0
