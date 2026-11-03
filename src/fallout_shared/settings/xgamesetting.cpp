// fallout_shared/settings/xgamesetting.cpp: GameSettingCollection, StrArr (9 functions)

#include "xgamesetting_decls.h"

// Reads a DATA chunk from the current TESFile and stores its payload into the setting according to the setting's type.
// @fnv 0x004f8860
bool GameSettingCollection::ReadSetting(Setting& setting)
{
    bool result = false;
    if (Actor_GetLifeState())
    {
        TESFile* file = Actor_GetLifeState();
        file->NextChunk();
        if (file->GetChunkID() == 0x41544144)
        {
            switch (setting.FUN_004f8940())
            {
            case 3:
                result = file->GetChunkData(&setting.uValue.u);
                break;
            case 5:
                result = file->GetChunkData(&setting.uValue.u);
                break;
            case 6:
                char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
                result = file->GetChunkData(buffer, 0);
                setting.FUN_00c33170(buffer);
                break;
            }
        }
    }
    return result;
}

// Reads a setting from the file by key, returning whether a matching setting was found and read, then closes the file.
// @fnv 0x004f89c0
bool GameSettingCollection::ReadSetting(TESFile* file, const char* key)
{
    bool result = false;
    SetField108(file);
    {
        Setting* setting = FUN_004f8a30(PrepareScriptMessage(key, false));
        if (setting)
            result = ReadSetting(*setting);
    }
    Close();
    return result;
}

// @fnv 0x004f89a0
bool GameSettingCollection::Close()
{
    pFile = 0;
    return true;
}

struct S_0060ba10
{
    char pad[0xa];
    unsigned short s;
    void FUN_0060bd90(unsigned short, int);
    void FUN_0096a610(int a);
};
// @fnv 0x0096a610
void S_0060ba10::FUN_0096a610(int a)
{
    FUN_0060bd90(s, a);
}

struct FUN_004f8980_shell
{
    virtual bool __thiscall GameSettingCollection_Open(bool);
};

// @fnv 0x004f8980
bool __thiscall FUN_004f8980_shell::GameSettingCollection_Open(bool)
{
    return *(int*)((char*)this + 0x108) != 0;
}

void __cdecl _Deallocate(void*);
struct S00404b40
{
    void FUN_00404b70();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00404b70, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00404b40
void* S00404b40::DestroyIfFlagged(unsigned int flags)
{
    FUN_00404b70();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct NiTPrimitiveArray_unsigned_int_
{
    unsigned int AddFirstEmpty(unsigned int const&);
};
char* _FUN_00a7d330(char const*);
char* __cdecl FUN_00a7d510(char const*, unsigned int);
struct Base00404fd0
{
    unsigned int FUN_00404fd0(NiTPrimitiveArray_unsigned_int_*);
};
struct Holder004f8800 : Base00404fd0
{
    unsigned int AddGameSettingsStrings(NiTPrimitiveArray_unsigned_int_*);
};
// Adds "GameSettings" and "Total GameSettings" strings to apStrings and returns the count from FUN_00404fd0.
// @fnv 0x004f8800
unsigned int Holder004f8800::AddGameSettingsStrings(NiTPrimitiveArray_unsigned_int_* apStrings)
{
    unsigned int I;
    apStrings->AddFirstEmpty((unsigned int)_FUN_00a7d330("GameSettings"));
    I = FUN_00404fd0(apStrings);
    apStrings->AddFirstEmpty((unsigned int)FUN_00a7d510("Total GameSettings", I));
    return I;
}

struct StrArr
{
    unsigned char _pad0[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _pad1;
    unsigned short m_usGrowBy;
    void SetAt(unsigned int, char*&);
    void FUN_00c4c920(unsigned int);
    unsigned int FUN_00c4c8d0(char*&);
};
struct Pad12
{
    int a;
    int b;
    int c;
};
// Appends element to the array, growing it by m_usGrowBy if full, and returns the index it was stored at.
// @fnv 0x00c4c8d0
unsigned int StrArr::FUN_00c4c8d0(char*& element)
{
    Pad12 pad;
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            FUN_00c4c920(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
}

char* __cdecl FUN_00ec7750(const char* key, const char* name);

// @fnv 0x00c4bd20
int __cdecl FUN_00c4bd20(Setting* setting)
{
    int res = 0;
    char* dst;
    const char* n = setting->pKey;
    const char* p = n;
    if (p)
    {
        dst = FUN_00ec7750(p, "_:");
        if (dst)
        {
            dst += 2;
        }
    }
    else
    {
        res = 0;
    }
    return res;
}
