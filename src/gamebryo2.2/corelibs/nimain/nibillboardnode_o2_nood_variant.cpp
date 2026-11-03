
// src/gamebryo2.2/corelibs/nimain/nibillboardnode_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nimain/nibillboardnode.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

class NiRTTI;
class NiBillboardNode
{
  public:
    static const NiRTTI ms_kRTTI;
    virtual const NiRTTI* GetRTTI() const;
};

void* __cdecl FUN_00aa13e0(unsigned int);
class FUN_00a5ecb0
{
  public:
    virtual const NiRTTI* GetRTTI() const;
    FUN_00a5ecb0(unsigned int flags);
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
};
class BillboardNode : public FUN_00a5ecb0
{
  public:
    unsigned short mode;
    unsigned short unknownAE;
    float angle;
    virtual const NiRTTI* GetRTTI() const;
    BillboardNode() throw() : FUN_00a5ecb0(0), angle(0.0f)
    {
        mode = 9;
    }
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
// @fnv 0x00a7e770
BillboardNode* NiBillboardNode_CreateObject()
{
    return new BillboardNode;
}
