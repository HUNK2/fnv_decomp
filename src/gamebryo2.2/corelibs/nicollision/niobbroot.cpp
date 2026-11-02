
// src/gamebryo2.2/corelibs/nicollision/niobbroot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/niobbroot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct MM
{
    void _DeallocateAlias(void*);
};
extern MM g_memoryManager;
extern int DAT_010f1b44;
struct DelBase
{
    virtual ~DelBase();
};
struct NiOBBRoot
{
    void* vf;
    int f4;
    DelBase* p8;
    void* Destroy(unsigned int);
};
// Sets vf to DAT_010f1b44, deletes p8, and if bit 0 of f is set deallocates this via g_memoryManager, then returns this.
// @fnv 0x00eb5fc0
void* NiOBBRoot::Destroy(unsigned int auiFlags)
{
    DelBase* t = p8;
    vf = (void*)&DAT_010f1b44;
    delete t;
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

struct S_00eb6030_Bound
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Test(S_00eb6030_Bound* other, int a2, int a3, int a4, int a5, int a6, int a7, int mine, int theirs,
                     int a8);
};
struct S_00eb6030
{
    void* vf;
    int unk4;
    S_00eb6030_Bound* unk8;
    int unkC;
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
    int TestAgainst(S_00eb6030* other, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};
// Returns 0 if this equals other, otherwise forwards both objects' unk8 and unk50 values to the bound Test method.
// @fnv 0x00eb6030
int S_00eb6030::TestAgainst(S_00eb6030* other, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    if (this == other)
        return 0;
    S_00eb6030_Bound* mine = unk8;
    int iMine = unk50;
    int t = other->unk50;
    return mine->Test(other->unk8, a2, a3, a4, a5, a6, a7, iMine, t, a8);
}

// Forwarder: this->m_08->virtual_slot_0x10(a) tail-jumped.
struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void Forward(int a);
};

struct FUN_00dbd750_cls
{
    int unk00;
    int unk04;
    Target* m_08;
    void FUN_00dbd750(int a);
};

// @fnv 0x00dbd750
void FUN_00dbd750_cls::FUN_00dbd750(int a)
{
    m_08->Forward(a);
}

struct FUN_00eb5ff0_view
{
    virtual void w0();
    virtual void w1();
    virtual int w2(FUN_00eb5ff0_view* first, int a2, int a3, int a4, int a5, int mine, int theirs);
};

struct FUN_00eb5ff0_cls
{
    void* vf;
    int unk4;
    S_00eb6030_Bound* unk8;
    int unkC;
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
    unsigned char CompareBounds(FUN_00eb5ff0_cls* other, int a2, int a3, int a4, int a5);
};

// If this differs from other, calls w2 on this->unk8 with other->unk8 and both objects' unk50 values, returning its result.
// @fnv 0x00eb5ff0
unsigned char FUN_00eb5ff0_cls::CompareBounds(FUN_00eb5ff0_cls* other, int a2, int a3, int a4, int a5)
{
    if (this == other)
    {
        return 0;
    }
    FUN_00eb5ff0_view* bound = reinterpret_cast<FUN_00eb5ff0_view*>(this->unk8);
    int theirs = other->unk50;
    int mine = this->unk50;
    return (unsigned char)bound->w2(reinterpret_cast<FUN_00eb5ff0_view*>(other->unk8), a2, a3, a4, a5, mine, theirs);
}
