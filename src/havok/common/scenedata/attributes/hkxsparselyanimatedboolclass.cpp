
// src/havok/common/scenedata/attributes/hkxsparselyanimatedboolclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/attributes/hkxsparselyanimatedboolclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
NineIntegerRecord* FUN_00c85750();

struct hkReferencedObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkReferencedObject() : m_usMemSizeAndFlags(0xffff), m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObject();

    void operator delete(void* p)
    {
        hkReferencedObject* b = static_cast<hkReferencedObject*>(p);
        FUN_00c85750()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

struct FUN_00e01ac0 : hkReferencedObject
{
    FUN_00e01ac0();
    virtual ~FUN_00e01ac0();
};

// Default constructor for the FUN_00e01ac0 class, which inherits from hkReferencedObject.
// @fnv 0x00e01ac0
FUN_00e01ac0::FUN_00e01ac0()
{}
