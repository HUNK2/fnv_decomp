
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_0043c610_shell
{
    void __thiscall RunVirtualMethod28();
};

struct FUN_0043daa0_shell
{
    void __thiscall FUN_0043daa0();
};

// @fnv 0x0043daa0
void __thiscall FUN_0043daa0_shell::FUN_0043daa0()
{
    ((FUN_0043c610_shell*)this)->RunVirtualMethod28();
}

extern int DAT_01016a18;
struct QueuedFile
{
    void* vtbl;
    int m_field;
    int m_auiShapeKeys[8];
    QueuedFile(int a);
};
struct FUN_0043db30 : QueuedFile
{
    void* m_magicItem;
    void* m_effect;
    FUN_0043db30(void* aMagicItem, void* aEffect, int aPriority);
};
// @fnv 0x0043db30
FUN_0043db30::FUN_0043db30(void* aMagicItem, void* aEffect, int aPriority) : QueuedFile(aPriority)
{
    vtbl = &DAT_01016a18;
    m_magicItem = aMagicItem;
    m_effect = aEffect;
}

struct QHeadLocal
{
    int vtbl;
    int data;
};
struct QHeadPtr
{
    QHeadLocal* pHead;
    QHeadPtr(QHeadLocal* pHead);
    ~QHeadPtr();
};
struct IOTask
{
    unsigned char GetPriority();
};
struct C_00449210
{
    void FUN_00449210(int, QHeadPtr*);
};
struct FUN_0043d6b0_shell
{
    void __thiscall FUN_0043d6b0(QHeadLocal* aHead);
};
// Wraps aHead in a QHeadPtr and passes its priority and the wrapper to the object at this+0x64 via FUN_00449210.
// @fnv 0x0043d6b0
void FUN_0043d6b0_shell::FUN_0043d6b0(QHeadLocal* aHead)
{
    QHeadPtr head(aHead);
    (*(C_00449210**)((char*)this + 0x64))->FUN_00449210(((IOTask*)aHead)->GetPriority(), &head);
}
