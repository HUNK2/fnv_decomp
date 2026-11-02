// bssystem/console/bsfile_console.cpp: BSFile (6 functions)

#include "bsfile_console_decls.h"
// Constructs a NiTPointerMap<unsigned int, TESFile*> by forwarding count to FUN_00474560.
// Constructs a NiTPointerMap of unsigned int to TESFile* pairs, delegating to the base constructor with the given count.
// @fnv 0x004744a0
template <> NiTPointerMap<unsigned int, TESFile*>::NiTPointerMap(unsigned int count) : FUN_00474560(count)
{}
// Seeks the file to a position computed from the offset and mode (set/current/end), updating position when it changes.
// @fnv 0x00b00590
void BSFile::Seek(int offset, int mode)
{
    int target;
    if (mode == DAT_010a2480)
    {
        target = offset;
        if (buffered == 0)
        {
            mode = DAT_010a2484;
            offset -= position;
        }
    }
    else if (mode == DAT_010a2484)
    {
        target = position + offset;
    }
    else if (mode == DAT_010a2488)
    {
        target = vfn_28() - offset;
    }
    else
    {
        target = position;
    }
    if (target != position)
    {
        NiFile::Seek(offset, mode);
        position = target;
    }
}

struct FUN_00aff950_shell
{
    unsigned int FUN_00aa1810(void*, unsigned int);
    unsigned int FUN_00aff950(void*, unsigned int);
};
// @fnv 0x00aff950
unsigned int FUN_00aff950_shell::FUN_00aff950(void* buffer, unsigned int size)
{
    unsigned int term = this->FUN_00aa1810(buffer, size);
    *(unsigned int*)((char*)this + 0x150) += term;
    return term;
}

struct S_00aff7c0_Pad
{
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
};

struct S_00aff7c0_Out
{
    int unk00;
    void FUN_00404820(const char* s);
    void FUN_004037f0(const char* s, int n);
};

struct S_00aff7c0_File
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20(int a, int b);
    int unk04;
    int(__cdecl* unk08)(S_00aff7c0_File*, char*, int, int*, int);
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    unsigned int FUN_00aff7c0(S_00aff7c0_Out* out, unsigned int maxLen);
};

// @fnv 0x00aff7c0
unsigned int S_00aff7c0_File::FUN_00aff7c0(S_00aff7c0_Out* out, unsigned int maxLen)
{
    if (!(bool)(unk24 != 0 ? 1 : 0))
        vfn_20(0, 0);
    unsigned int idx3 = 0;
    unsigned int outLen7 = 0;
    unsigned int kTotal = 0;
    char ch_;
    char buf2[0x104];
    for (;;)
    {
        int want = 1;
        int got = unk08(this, &ch_, 1, &want, 1);
        unk04 += got;
        int a2 = got;
        int b2 = a2;
        kTotal += b2;
        if (b2 != 1)
            ch_ = 0;
        if (kTotal > maxLen)
            ch_ = 0;
        buf2[idx3] = ch_;
        idx3++;
        if (idx3 == 0x103 || ch_ == 0)
        {
            buf2[idx3] = 0;
            if (outLen7)
                out->FUN_00404820(buf2);
            else
                out->FUN_004037f0(buf2, 0);
            outLen7 += idx3;
            if (!ch_)
                break;
            idx3 = 0;
        }
    }
    {
        S_00aff7c0_Pad pad;
    }
    return kTotal;
}

#include <string.h>
void __cdecl FUN_00ec65a6(char* dest, unsigned int size, const char* src);

struct S_00b00260_Base
{
    virtual void vfn_00();
    ~S_00b00260_Base();
    S_00b00260_Base();
};

struct FUN_00b00260 : S_00b00260_Base
{
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
    char unk2C;
    char unk2D;
    char unk2E;
    char unk2F;
    char unk30;
    char unk31;
    char unk32;
    char unk33;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    char path[260];
    int unk148;
    int unk14C;
    int unk150;
    int unk154;

    void FUN_00aff990(bool);
    bool FUN_00aff300(bool, bool);
    bool FUN_00affc60();

    FUN_00b00260(const char* pPath, int mode, unsigned int bufferSize, bool arg4);
};

// Initializes fields, copies pPath when its length is below 260, and calls helper functions depending on mode.
// @fnv 0x00b00260
FUN_00b00260::FUN_00b00260(const char* pPath, int mode, unsigned int bufferSize, bool abFlag)
{
    FUN_00aff990(false);
    unk28 = mode;
    unk10 = bufferSize;
    unk14 = 0;
    unk18 = 0;
    unk20 = 0;
    unk24 = 0;
    unk150 = 0;
    unk14C = 0;
    unk148 = 0;
    unk154 = 0;
    unk30 = 0;
    unk34 = 0;
    unk38 = 0xffffffff;
    unk3C = 0;
    unk40 = 0;

    if (strlen(pPath) >= 0x104)
    {
        path[0] = 0;
    }
    else
    {
        strcpy_s(path, 0x104, pPath);
        if (mode == 1)
        {
            FUN_00aff300(false, abFlag);
        }
    }
    if (mode == 0)
    {
        unk2C = FUN_00affc60();
    }
}

#include <windows.h>
void* fnv_zlib_memset(void* dst, int c, int n);

class B003C0File
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual const char* GetFileName();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    void* m_handle;

    SYSTEMTIME GetLastWriteTime();
};

// Returns the last write time of the file as local time, or zeroed SYSTEMTIME if m_handle is null.
// @fnv 0x00b003c0
SYSTEMTIME B003C0File::GetLastWriteTime()
{
    SYSTEMTIME localTime2;
    if (!(bool)(int)(m_handle != 0))
    {
        fnv_zlib_memset(&localTime2, 0, sizeof(localTime2));
        return localTime2;
    }
    WIN32_FIND_DATAA findData;
    FILETIME writeTime;
    SYSTEMTIME utcTime4;
    HANDLE find9 = FindFirstFileA(GetFileName(), &findData);
    if (find9 != INVALID_HANDLE_VALUE)
        writeTime = findData.ftLastWriteTime;
    FindClose(find9);
    FileTimeToSystemTime(&writeTime, &utcTime4);
    SystemTimeToTzSpecificLocalTime(0, &utcTime4, &localTime2);
    return localTime2;
}
