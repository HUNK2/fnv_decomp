
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct B6B610Node;
struct B6B610Geometry;

extern B6B610Node* g_B6B610Root;

B6B610Geometry* __cdecl FUN_00a7fc00(void* a, void* b, void* c, B6B610Node* root, void* d, void* e, void* h, void* i);

class B6B610Wrapper
{
  public:
    static void* operator new(unsigned int size);
    static void operator delete(void* p);

    B6B610Wrapper(B6B610Geometry* geometry, void* f, void* g);

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
};

// Builds a geometry via FUN_00a7fc00 and, if it succeeds, allocates and returns a B6B610Wrapper for it; otherwise returns 0.
// @fnv 0x00b6b610
B6B610Wrapper* __cdecl CreateWrapperFromGeometry(void* apArg1, void* apArg2, void* apArg3, void* apArg4, void* apArg5,
                                                 void* apArg6, void* apArg7, void* apArg8, void* apArg9)
{
    B6B610Geometry* geometry = FUN_00a7fc00(apArg1, apArg2, apArg3, g_B6B610Root, apArg4, apArg5, apArg8, apArg9);
    if (geometry)
        return new B6B610Wrapper(geometry, apArg6, apArg7);
    return 0;
}
