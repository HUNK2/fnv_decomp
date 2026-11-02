
// src/havok/physics/dynamics/world/util/broadphase/hkpbroadphaseborderlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/broadphase/hkpbroadphaseborderlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00cf6f10_Node
{
    int unk00;
    unsigned char type;
    signed char off;
    unsigned short unk06;
    int unk08;
    int unk0C;
    signed char off10;
};

struct S_00cf6f10_Rec
{
    S_00cf6f10_Node* first;
    S_00cf6f10_Node* second;
};

struct S_00cf6f10_Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual int v24(void* p);
};

// @fnv 0x00cf6f10
int __stdcall FUN_00cf6f10(S_00cf6f10_Rec* pRec)
{
    S_00cf6f10_Node* a = pRec->first;
    if (a->type == 3 && pRec->second->type == 3)
    {
    }
    else
    {
        if (a->type == 3)
        {
            S_00cf6f10_Node* pFirstBase = (S_00cf6f10_Node*)((char*)a + a->off);
            S_00cf6f10_Node* pSecond = pRec->second;
            void* pSecondBase = (char*)pSecond + pSecond->off;
            S_00cf6f10_Obj* y = (S_00cf6f10_Obj*)((char*)pFirstBase + pFirstBase->off10);
            y->v24(pSecondBase);
        }
        S_00cf6f10_Node* b = pRec->second;
        if (b->type == 3)
        {
            S_00cf6f10_Node* pSecondBase2 = (S_00cf6f10_Node*)((char*)b + b->off);
            S_00cf6f10_Obj* y = (S_00cf6f10_Obj*)((char*)pSecondBase2 + pSecondBase2->off10);
            S_00cf6f10_Node* pFirst2 = pRec->first;
            return y->v24((char*)pFirst2 + pFirst2->off);
        }
    }
}

namespace f6 {
struct Disp
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(void* other);
};
struct Sh
{
    void* vt;
    char type;
    signed char off;
};
struct Pair
{
    Sh* a;
    Sh* b;
};
static inline char* Base(Sh* s)
{
    return (char*)s + s->off;
}
static inline Disp* GetDisp(Sh* s)
{
    char* p = Base(s);
    return (Disp*)(p + p[0x10]);
}
// @fnv 0x00cf6ea0
void __stdcall DispatchPairByType(Pair* p)
{
    if (p->a->type == 3 && p->b->type == 3)
        return;
    if (p->a->type == 3)
    {
        char* ob = Base(p->b);
        GetDisp(p->a)->v7(ob);
    }
    if (p->b->type == 3)
    {
        Disp* d = GetDisp(p->b);
        d->v7(Base(p->a));
    }
}
}
