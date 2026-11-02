
// src/havok/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct StateD72090
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
};
void FUN_00d72090(StateD72090* out);
#include <string.h>
struct Node
{
    unsigned short unk00;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short unk10;
    unsigned short unk12;
    Node* unk14;
};
struct __declspec(align(16)) Buffer
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
};
extern "C" void __cdecl FUN_00d72090(void*);
extern "C" void __cdecl FUN_00d72190(Node*, Buffer*, int, int*);
extern "C" void __cdecl FUN_00d6f460(Node*, unsigned short, Buffer*, int*);
extern "C" Buffer* __cdecl GetSharedBuffer();
static void __cdecl FUN_00d6c5a0(Node* self, int* counter, Buffer* source);
void __cdecl Caller(Node* self, int* counter);
