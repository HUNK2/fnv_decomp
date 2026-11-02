
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl _delete(void* p, unsigned int flags);

struct FUN_00e7a1e0_shell
{
    void* FUN_00e78be0();
    void* DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_00e78be0, then deletes this with size 0x2c when flags has bit 0 set, and returns this.
// @fnv 0x00e7a1e0
void* FUN_00e7a1e0_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_00e78be0();
    if (flags & 1)
        _delete(this, 0x2c);
    return this;
}

struct DynamicArrayChip
{
    void* vftable;
    unsigned int* m_30;
    unsigned short unk34;
    unsigned short m_36;
    unsigned short m_38;
    unsigned short unk3A;

    void RemoveAll(unsigned int zero)
    {
        for (unsigned short i = 0; i < m_36; ++i)
            m_30[i] = zero;
        m_36 = 0;
        m_38 = 0;
    }
};

struct NiVBBlock
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    DynamicArrayChip m_chips;
    unsigned int m_3c;
    unsigned int m_40;

    void FUN_00e942d0();
};

// @fnv 0x00e942d0
void NiVBBlock::FUN_00e942d0()
{
    unsigned int zero = 0;
    m_00 = zero;
    m_08 = zero;
    m_0c = zero;
    m_10 = zero;
    m_14 = zero;
    m_04 = zero;
    m_18 = zero;
    m_1c = zero;
    m_20 = zero;
    m_24 = zero;
    m_28 = zero;

    m_chips.RemoveAll(zero);

    m_3c = zero;
    m_40 = zero;
}
