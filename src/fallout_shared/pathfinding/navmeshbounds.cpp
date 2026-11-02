
// src/fallout_shared/pathfinding/navmeshbounds.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshbounds.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

int __cdecl FUN_00ec3bad(int);
// Replaces the integer pointed to by p with the result of calling FUN_00ec3bad on its current value.
// @fnv 0x00401080
void FUN_00401080(int* piValue)
{
    int* q = piValue;
    *q = FUN_00ec3bad(*q);
}

struct Vec3i
{
    int x;
    int y;
    int z;
};
struct Elem12
{
    int x;
    int y;
    int z;
    Elem12();
};
struct Elem6
{
    short x;
    short y;
    short z;
};
struct Arr12
{
    int f0;
    Elem12* m_data;
    unsigned int m_uiItemCount;
    int f12;
    unsigned int FUN_0044ddc0();
    bool FUN_0076b610();
    Elem12* FUN_006a1440(unsigned int);
};
struct Arr6
{
    int f0;
    Elem6* m_data;
    unsigned int m_uiItemCount;
    int f12;
    unsigned int FUN_0044ddc0();
    Elem6* FUN_0069ccf0(unsigned int);
};
struct ByteArg
{
    unsigned char c;
};
bool FUN_00401500();
void FUN_00401080(int* p, ByteArg b);
void FUN_00407a90(short* p, ByteArg b);
void* memcpy(void* dst, const void* src, unsigned int n);

struct Owner69c4c0
{
    Vec3i m_kPointA;
    Vec3i m_kPointB;
    Arr6 m_arr6;
    Arr12 m_arr12;
    void WriteToBuffer(char* p);
};

// @fnv 0x0069c4c0
void Owner69c4c0::WriteToBuffer(char* apBuffer)
{
    unsigned short w;
    Vec3i v;
    unsigned int count2;
    Elem12* arr;
    unsigned int bytes5;
    Elem6* arr2_2;
    unsigned int i3;
    unsigned int i4;
    int j;

    v = m_kPointA;
    if (FUN_00401500())
    {
        FUN_00401080(&v.x, ByteArg());
        FUN_00401080(&v.y, ByteArg());
        FUN_00401080(&v.z, ByteArg());
    }
    memcpy(apBuffer, &v, 12);
    apBuffer += 12;
    v = m_kPointB;
    if (FUN_00401500())
    {
        FUN_00401080(&v.x, ByteArg());
        FUN_00401080(&v.y, ByteArg());
        FUN_00401080(&v.z, ByteArg());
    }
    memcpy(apBuffer, &v, 12);
    apBuffer += 12;
    w = (unsigned short)m_arr12.FUN_0044ddc0();
    if (FUN_00401500())
    {
        FUN_00407a90((short*)&w, ByteArg());
    }
    memcpy(apBuffer, &w, 2);
    apBuffer += 2;
    w = (unsigned short)m_arr6.FUN_0044ddc0();
    if (FUN_00401500())
    {
        FUN_00407a90((short*)&w, ByteArg());
    }
    memcpy(apBuffer, &w, 2);
    apBuffer += 2;
    if (!m_arr12.FUN_0076b610())
    {
        count2 = m_arr12.FUN_0044ddc0();
        bytes5 = count2 * 12;
        arr = new Elem12[count2];
        memcpy(arr, m_arr12.FUN_006a1440(0), bytes5);
        if (FUN_00401500())
        {
            for (i3 = 0; i3 < count2; i3++)
            {
                FUN_00401080(&arr[i3].x, ByteArg());
                FUN_00401080(&arr[i3].y, ByteArg());
                FUN_00401080(&arr[i3].z, ByteArg());
            }
        }
        memcpy(apBuffer, arr, bytes5);
        apBuffer += bytes5;
        delete[] arr;
        arr = 0;
        count2 = m_arr6.FUN_0044ddc0();
        bytes5 = count2 * 6;
        arr2_2 = new Elem6[count2];
        memcpy(arr2_2, m_arr6.FUN_0069ccf0(0), bytes5);
        if (FUN_00401500())
        {
            for (i4 = 0; i4 < count2; i4++)
            {
                for (j = 0; j < 3; j++)
                {
                    FUN_00407a90(&arr2_2[i4].x + j, ByteArg());
                }
            }
        }
        memcpy(apBuffer, arr2_2, bytes5);
        apBuffer += bytes5;
        delete[] arr2_2;
        arr2_2 = 0;
    }
}
