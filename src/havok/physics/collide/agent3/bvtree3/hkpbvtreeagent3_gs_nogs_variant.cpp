// src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3_gs_nogs_variant.cpp - flag-variant unit created 2026-11-01 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void* __cdecl InitAndReturnTail(void*, void*, void*);
void __fastcall FUN_00d2d890(void* self, int, void*, int);
void __fastcall CallWithValueSource(void* self, int, int, int);
void __fastcall FUN_00d2d430(void* self, int, int, int);
void __fastcall FUN_00d2d480(void* self, int, int, int);
void FUN_00d2d9d0(void* pObject);
extern "C" void __cdecl FUN_00da35f0(void*, float, float, int);
void __cdecl FUN_00d2d480(void*, void* target, float first, float second, int flags);
struct Interface
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
void FUN_00d2d4b0(Interface** a);
struct LessU32
{
    int pad;
    bool operator()(unsigned a, unsigned b) const
    {
        return a < b;
    }
};
// Partitions pArr[d..h] around a middle pivot using cmpLess, swapping out-of-order elements, then recurses on the left part and loops on the right.
// @fnv 0x00d2da70
extern "C" void __cdecl QuickSortRange(unsigned* auiArray, int aiLow, int aiHigh, LessU32 aComparator)
{
setpoint:
    int iRight = aiHigh;
    int iLeft = aiLow;
    __declspec(align(16)) unsigned pivot = auiArray[(aiLow + aiHigh) >> 1];
    do
    {
        while (aComparator(auiArray[iLeft], pivot))
            iLeft++;
        while (aComparator(pivot, auiArray[iRight]))
            iRight--;
        if (iRight >= iLeft)
        {
            if (iRight != iLeft)
            {
                unsigned t = auiArray[iRight];
                auiArray[iRight] = auiArray[iLeft];
                auiArray[iLeft] = t;
            }
            iRight--;
            iLeft++;
        }
    } while (iLeft <= iRight);
    if (aiLow < iRight)
        QuickSortRange(auiArray, aiLow, iRight, aComparator);
    if (iLeft < aiHigh)
    {
        aiLow = iLeft;
        goto setpoint;
    }
}
struct ValueSource
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4();
};
struct CallBuf
{
    int unk00;
    ValueSource** unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
void __cdecl FUN_00da48e0(void* a, void* b);
void __cdecl CallWithValueSource(void* apUnused, void* p2, int aiArg0, ValueSource** apValueSource, int aiArg1,
                                 int aiArg2, int aiArg3);
struct SpawnedObject
{
    int unk00;
    int unk04;
    int unk08;
    int m_kind;            // 0x0c
    unsigned char m_flag;  // 0x10
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    void* m_ptr18;  // 0x18
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void* m_ptr34;  // 0x34
};
void* __cdecl GetSpawnedObjectPointer(void** holder);
struct Agent
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(const char* typeName);
    virtual void f7();
};
extern "C" void __cdecl FUN_00d97250(int, int, void*);
extern "C" void __cdecl FUN_00da3510(int, int);
void __cdecl FUN_00d2d430(int a1, int a2, int a3, Agent* p);
void __cdecl FUN_00d2d460(int a, int b, int c)
{
    FUN_00da3510(b, c);
}
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" const char str_010ce7ec[];
extern "C" const char str_010ce7e0[];
extern "C" const char str_010ce7d4[];
extern "C" const char str_01076f38[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
struct S00d2d890_Rec
{
    const char* name;
    unsigned int stamp;
    unsigned int unk08;
    const char* tag;
};
struct S00d2d890_Buf
{
    int unk00;
    char* cur;
    int unk08;
    char* end;
};
struct __declspec(align(16)) S00d2d890_Local
{
    int b00;
    int b01;
    int b02;
    int b03;
    int b04;
    int b05;
    int b06;
    int b07;
    int b08;
    int b09;
    int b0a;
    int b0b;
    int b0c;
    int b0d;
    int b0e;
    int b0f;
    S00d2d890_Local()
    {}
    void FUN_00cb21e0(void* a);
};
struct S00d2d890_Hits
{
    int q000;
    int q001;
    int q002;
    int q003;
    int q004;
    int q005;
    int q006;
    int q007;
    int q008;
    int q009;
    int q00a;
    int q00b;
    int q00c;
    int q00d;
    int q00e;
    int q00f;
    int q010;
    int q011;
    int q012;
    int q013;
    int q014;
    int q015;
    int q016;
    int q017;
    int q018;
    int q019;
    int q01a;
    int q01b;
    int q01c;
    int q01d;
    int q01e;
    int q01f;
    int q020;
    int q021;
    int q022;
    int q023;
    int q024;
    int q025;
    int q026;
    int q027;
    int q028;
    int q029;
    int q02a;
    int q02b;
    int q02c;
    int q02d;
    int q02e;
    int q02f;
    int q030;
    int q031;
    int q032;
    int q033;
    int q034;
    int q035;
    int q036;
    int q037;
    int q038;
    int q039;
    int q03a;
    int q03b;
    int q03c;
    int q03d;
    int q03e;
    int q03f;
    int q040;
    int q041;
    int q042;
    int q043;
    int q044;
    int q045;
    int q046;
    int q047;
    int q048;
    int q049;
    int q04a;
    int q04b;
    int q04c;
    int q04d;
    int q04e;
    int q04f;
    int q050;
    int q051;
    int q052;
    int q053;
    int q054;
    int q055;
    int q056;
    int q057;
    int q058;
    int q059;
    int q05a;
    int q05b;
    int q05c;
    int q05d;
    int q05e;
    int q05f;
    int q060;
    int q061;
    int q062;
    int q063;
    int q064;
    int q065;
    int q066;
    int q067;
    int q068;
    int q069;
    int q06a;
    int q06b;
    int q06c;
    int q06d;
    int q06e;
    int q06f;
    int q070;
    int q071;
    int q072;
    int q073;
    int q074;
    int q075;
    int q076;
    int q077;
    int q078;
    int q079;
    int q07a;
    int q07b;
    int q07c;
    int q07d;
    int q07e;
    int q07f;
};
struct S00d2d890_Rec3
{
    const char* name;
    unsigned int stamp;
    unsigned int unk08;
};
struct S00d2d890_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
char** FUN_00c85750();
int FUN_00d2d4f0(int a, int b, S00d2d890_Local* l, void* c, int d, int e, char* f, int g);
int FUN_00d2d4b0(int a, S00d2d890_Hits* h);
int FUN_00da4aa0(int a, void* b, int c, char* d, int e);
char* __cdecl FUN_00d2d890(char* self, int a1, char* child, int a3, int a4);
struct FUN_00cfbd60_Obj
{
    void AddEntry(void* a1, int a2, int a3);
};
__declspec(noinline) void FUN_00d2d9d0(void* pObject);
struct __declspec(align(16)) S_00d2da20_AgentFuncs
{
    void* m_pCreateFunc;
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
    void* unk2C;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
    bool unk32;
    S_00d2da20_AgentFuncs()
    {
        m_bIsFlipped = false;
        m_bIsPredictive = false;
        unk32 = false;
        unk18 = 0;
        unk1C = 0;
        unk20 = 0;
        unk24 = 0;
        unk28 = 0;
    }
};
void FUN_00d2da20(FUN_00cfbd60_Obj* target);
