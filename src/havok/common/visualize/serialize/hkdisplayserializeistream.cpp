// src/havok/common/visualize/serialize/hkdisplayserializeistream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/serialize/hkdisplayserializeistream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct DdabeTag
{
    bool b;
    DdabeTag() : b(false)
    {}
    DdabeTag(const DdabeTag& o) : b(o.b)
    {}
};

struct DdabeBase
{
    DdabeBase(int a, DdabeTag t);
    virtual void unk00();
};

struct FUN_00ddabe0 : DdabeBase
{
    FUN_00ddabe0(int a);
    virtual void unk00();
};

// @fnv 0x00ddabe0
FUN_00ddabe0::FUN_00ddabe0(int a) : DdabeBase(a, DdabeTag())
{}

struct FUN_00ddac60_Obj
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
};

void __stdcall FUN_00dd8fe0(FUN_00ddac60_Obj* obj, int a, int b);

// @fnv 0x00ddac60
void __stdcall FUN_00ddac60(FUN_00ddac60_Obj* obj)
{
    FUN_00dd8fe0(obj, 4, 3);
    obj->unk0C = 0.0f;
}

struct ArrayRecord
{
    void* data;
    int size;
    int capacity;
};
struct ArrayPair
{
    ArrayRecord first;
    ArrayRecord second;
};
struct BSAudio
{
};
BSAudio* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(void*, void*, int, int);
struct FUN_00ddacd0_shell
{
    void __thiscall FUN_00dd8fe0(void* output, int elementSize, int count);
    void __thiscall FUN_00ddac60(void* output);
    void __thiscall FUN_00ddac00(void* output);
    void __thiscall FUN_00ddacd0(ArrayPair* arrays);
};
// @fnv 0x00ddacd0
void __thiscall FUN_00ddacd0_shell::FUN_00ddacd0(ArrayPair* arrays)
{
    {
        int firstCount;
        FUN_00dd8fe0(&firstCount, 4, 1);
        if (firstCount > 0)
        {
            for (int remaining = firstCount; remaining != 0; --remaining)
            {
                BSAudio* allocator = FUN_00c85750();
                void* growFunction = *(void**)((char*)allocator + 0x10);
                ArrayRecord* array = &arrays->first;
                int size = array->size;
                int needed = size + 1;
                int capacity = array->capacity & 0x3fffffff;
                if (capacity < needed)
                {
                    int grown = capacity * 2;
                    if (needed < grown)
                        needed = grown;
                    FUN_00c908c0(growFunction, array, needed, 16);
                }
                ++array->size;
                void* output = (char*)array->data + size * 16;
                FUN_00ddac60(output);
            }
        }
    }
    {
        int secondCount;
        FUN_00dd8fe0(&secondCount, 4, 1);
        if (secondCount > 0)
        {
            ArrayRecord* array = &arrays->second;
            for (int remaining = secondCount; remaining != 0; --remaining)
            {
                BSAudio* allocator = FUN_00c85750();
                void* growFunction = *(void**)((char*)allocator + 0x10);
                int size = array->size;
                int needed = size + 1;
                int capacity = array->capacity & 0x3fffffff;
                if (capacity < needed)
                {
                    int grown = capacity * 2;
                    if (needed < grown)
                        needed = grown;
                    FUN_00c908c0(growFunction, array, needed, 16);
                }
                ++array->size;
                void* output = (char*)array->data + size * 16;
                FUN_00ddac00(output);
            }
        }
    }
}

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

struct FUN_00dd9210_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00dd91f0();

    FUN_00dd9210_cls* FUN_00dd9210(unsigned char acFlags);
};

// Calls FUN_00dd91f0, then if acFlags bit 0 is set frees this via the allocator from FUN_00c85750 with m_uSize, and returns this.
// @fnv 0x00dd9210
FUN_00dd9210_cls* FUN_00dd9210_cls::FUN_00dd9210(unsigned char acFlags)
{
    FUN_00dd91f0();
    if (acFlags & 1)
    {
        AudioHolder* pHolder = reinterpret_cast<AudioHolder*>(FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}

#include <xmmintrin.h>
struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};
struct FUN_008cd6a0_Class
{
    void FUN_00cb2d90(void* value);
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
    __m128 unk30;
};
struct hkIArchive
{
    void FUN_00dd8fe0(void* destination, int componentSize, int components);
};
struct hkDisplaySerializeIStream : hkIArchive
{
    void FUN_00ddac80(FUN_008cd6a0_Class* target);
};
// Reads a 3-component vector (w set to 1.0f) into target->unk30 and a 4-component value that is passed to target->FUN_00cb2d90.
// @fnv 0x00ddac80
void hkDisplaySerializeIStream::FUN_00ddac80(FUN_008cd6a0_Class* target)
{
    Vec4 source;
    Vec4 destination;
    FUN_00dd8fe0(&source, 4, 3);
    source.w = 1.0f;
    FUN_00dd8fe0(&destination, 4, 4);
    target->unk30 = *(__m128*)&source;
    target->FUN_00cb2d90(&destination);
}

// Reads three 4-byte integers via FUN_00dd8fe0 and stores them sequentially into the output buffer.
// @fnv 0x00ddac00
__declspec(noinline) void __thiscall FUN_00ddacd0_shell::FUN_00ddac00(void* output)
{
    int* dst = (int*)output;
    {
        int val1;
        FUN_00dd8fe0(&val1, 4, 1);
        dst[0] = val1;
    }
    {
        int val2;
        FUN_00dd8fe0(&val2, 4, 1);
        dst[1] = val2;
    }
    {
        int val3;
        FUN_00dd8fe0(&val3, 4, 1);
        dst[2] = val3;
    }
}
