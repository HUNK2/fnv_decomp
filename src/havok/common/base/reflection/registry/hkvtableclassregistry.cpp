
// src/havok/common/base/reflection/registry/hkvtableclassregistry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/registry/hkvtableclassregistry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BoolResult
{
    char value;
    BoolResult()
    {}
};
struct IntResult
{
    int value;
    IntResult()
    {}
};
struct Object
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual BoolResult vf0c();
};
struct Buffer
{
    int value;
    void FUN_00cb0a60();
    void FUN_00cb0c00();
    int Equals(int);
};
struct Manager
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual int vf10(int*);
};
extern Manager* DAT_01269b74;
extern int DAT_011b7b88;
IntResult FUN_00dcca60(Object*);
void FUN_00d48af0(Object*, int*);
int hkString_memCmp(void*, const void*, int);
int FUN_00dc0fb0();
struct ParseState
{
    int status;
    Buffer buffer;
    int bits;
};
// Checks the object and parse state, returning 1 when the buffer comparison or manager check succeeds.
// @fnv 0x00d49240
int FUN_00d49240(Object* object)
{
    if (!object || !object->vf0c().value)
        return 0;
    if (FUN_00dcca60(object).value > 1)
        return 1;
    ParseState parseState;
    parseState.buffer.FUN_00cb0a60();
    FUN_00d48af0(object, &parseState.status);
    if (parseState.status == 2)
    {
        if (hkString_memCmp(&parseState.bits, &DAT_011b7b88, 4) != 0)
            goto check3;
        if (parseState.buffer.Equals(FUN_00dc0fb0()) != 0)
        {
            parseState.buffer.FUN_00cb0c00();
            return 1;
        }
        goto manager;
    }
check3:
    if (parseState.status != 3)
        goto failure;
manager:
    if (DAT_01269b74->vf10(&parseState.status))
    {
        parseState.buffer.FUN_00cb0c00();
        return 1;
    }
failure:
    parseState.buffer.FUN_00cb0c00();
    return 0;
}
