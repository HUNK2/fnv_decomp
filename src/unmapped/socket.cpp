
// src/unmapped/socket.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/remotelog/socket.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct MorphName
{
    char const* FUN_0044a560();
    char const* __thiscall GetMorphName();
};
// @fnv 0x0044a380
char const* __thiscall MorphName::GetMorphName()
{
    return reinterpret_cast<MorphName*>(reinterpret_cast<char*>(this) + 0xc)->FUN_0044a560();
}

struct FUN_00aca1e0
{
    void* __thiscall GetPointer();
};
// @fnv 0x00aca1e0
void* __thiscall FUN_00aca1e0::GetPointer()
{
    struct X
    {
        int a;
        int b;
        int c;
        int d;
        int e;
        int f;
        unsigned int g;
        int h;
    }* p = (X*)((char*)this + 0xc);
    return p->g >= 16 ? (void*)p->b : (void*)((char*)p + 4);
}
