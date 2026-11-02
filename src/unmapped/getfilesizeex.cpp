
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C"
{
    __declspec(dllimport) int __stdcall GO(unsigned int id, void* out);
}

struct FUN_00aff000_tbl
{
    char pad[0x10];
    unsigned int m10;
    unsigned int GetValue(unsigned int* param);
};

// Calls GO with m10; on success stores the returned 64-bit value through param and returns 0, otherwise stores 0 and returns 4.
// @fnv 0x00aff000
unsigned int FUN_00aff000_tbl::GetValue(unsigned int* param)
{
    unsigned int res;
    unsigned __int64 local;

    if (GO(this->m10, &local))
    {
        *(unsigned __int64*)param = local;
        res = 0;
    }
    else
    {
        *(unsigned __int64*)param = 0;
        res = 4;
    }
    return res;
}
