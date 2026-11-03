// tesclimate.cpp: TESClimate, ClimateCopy (12 functions)

#include "tesclimate_types.h"
#include <string.h>
#include <new>

// @fnv 0x0052aaa0
TESClimate::TESClimate()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x36));
    ResetFormData();
}

// @fnv 0x0052ac20
void TESClimate::ResetFormData()
{
    memset(m_ucTimeSettings, 0, sizeof(m_ucTimeSettings));
    SetMoonPhaseDays(3);
}

// @fnv 0x0052b0f0
void TESClimate::MakeDefault()
{
    m_kSunTextures[0].AssignTextureName("Sky\\Sun.dds");
    m_kSunTextures[1].AssignTextureName("Sky\\SunGlare.dds");
    m_kStarsModel.SetModelFilePath("Sky\\Stars.nif");
    m_ucTimeSettings[0] = 36;
    m_ucTimeSettings[1] = 42;
    m_ucTimeSettings[2] = 108;
    m_ucTimeSettings[3] = 114;
    m_ucTimeSettings[4] = 0;
    SetUsesMasser(true);
    SetUsesSecunda(true);
    SetMoonPhaseDays(3);
    weatherList.RemoveAll();
    WeatherEntry* weather = new WeatherEntry;
    weather->m_pWeatherObject = dynamic_cast<TESWeather*>(TESForm::GetFormByID(0x15e));
    weather->m_uiWeatherChance = 100;
    if (weather->m_pWeatherObject)
        weatherList.AddHead(weather);
    else
    {
        delete weather;
        Warning("DEFAULT: Unable to add default weather to default climate.  ( TESClimate::MakeDefault() )");
    }
}

#include <malloc.h>
// @fnv 0x0052ac90
bool TESClimate::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x36)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x54534c57: {
            int warnings = Warning();
            SetWarningState(true);
            TESWeatherList::LoadWeatherEntries(&weatherList, file, this);
            SetWarningState(false);
            if (Warning() > warnings)
                Warning("MASTERFILE: Warnings were encountered while loading weather list chunk from climate %s",
                        GetName());
        }
        break;
        case 0x4d414e46:
        case 0x4d414e47:
        case 0x4d414e48:
        case 0x4d414e49:
        case 0x4d414e4a:
        case 0x4d414e4b:
        case 0x4d414e4c:
        case 0x4d414e4d:
        case 0x4d414e4e:
        case 0x4d414e4f:
        case 0x4d414e50:
            if (chunk - 0x4d414e46 < 2)
                TESTexture::ReadTextureData(&m_kSunTextures[chunk - 0x4d414e46], file);
            break;
        case 0x4c444f4d:
            TESModel::LoadModelData(&m_kStarsModel, file);
            break;
        case 0x4d414e54:
            file->GetChunkData(m_ucTimeSettings, 6);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_0052b260_shell : public TESClimate
{
    void TESClimate_SetUsesMasser(bool);
};

// Sets or clears bit 0x80 of the byte at offset 0x55 on this TESClimate based on abUses.
// @fnv 0x0052b260
void FUN_0052b260_shell::TESClimate_SetUsesMasser(bool abUses)
{
    abUses ? *(unsigned char*)((char*)this + 0x55) |= 0x80 : *(unsigned char*)((char*)this + 0x55) &= ~0x80;
}

struct FUN_0052b2c0_shell : public TESClimate
{
    void TESClimate_SetUsesSecunda(bool);
};

// Sets or clears bit 0x40 in the byte at offset 0x55 of this TESClimate based on abUses.
// @fnv 0x0052b2c0
void FUN_0052b2c0_shell::TESClimate_SetUsesSecunda(bool abUses)
{
    abUses ? *(unsigned char*)((char*)this + 0x55) |= 0x40 : *(unsigned char*)((char*)this + 0x55) &= ~0x40;
}

void _Deallocate(void*);
struct FUN_0052ab50_shell
{
    void FUN_0052ab80();
    void* FUN_0052ab50(unsigned int flags);
};
// Calls FUN_0052ab80, then if bit 0 of flags is set calls _Deallocate on this, and returns this.
// @fnv 0x0052ab50
void* FUN_0052ab50_shell::FUN_0052ab50(unsigned int flags)
{
    FUN_0052ab80();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0052ac50_shell : public TESClimate
{
    void TESClimate_SetMoonPhaseDays(unsigned int);
};

int __cdecl MinInt(int, int);
// @fnv 0x0052ac50
void FUN_0052ac50_shell::TESClimate_SetMoonPhaseDays(unsigned int auiDays)
{
    *(unsigned char*)((char*)this + 0x55) =
        (*(unsigned char*)((char*)this + 0x55) & 0xC0) | MinInt(auiDays, 0xFFFFFF3F);
}

struct TESForm_StartForm
{
    void M();
};
struct TESForm_CloseForm
{
    void M();
};
struct FUN_0048e370_obj
{
    void TESTexture_Save(unsigned int);
};
struct FUN_004891d0_obj
{
    void WriteToBuffer(unsigned int, unsigned int);
};
void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);
void __cdecl WriteWeatherList(unsigned int);
struct FUN_0052ae80_shell
{
    void Init();
};
// @fnv 0x0052ae80
void FUN_0052ae80_shell::Init()
{
    ((TESForm_StartForm*)this)->M();
    ((void(__thiscall*)(void*, unsigned int))WriteWeatherList)((char*)this + 0x30, 0x54534c57);
    int i = 0;
    for (; i < 2; ++i)
        ((FUN_0048e370_obj*)((char*)this + 0x38 + i * 0xc))->TESTexture_Save(0x4d414e46 + i);
    ((FUN_004891d0_obj*)((char*)this + 0x18))->WriteToBuffer(0x4c444f4d, 0x54444f4d);
    TESForm_AddChunkArray(0x4d414e54, (char*)this + 0x50, 6);
    ((TESForm_CloseForm*)this)->M();
}

struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm* form);
    bool IsClimateDifferent(TESForm* form);
};

struct FUN_0052afe0_compare_t
{
    virtual void FUN_00000000();
    virtual void FUN_00000004();
    virtual bool FUN_00000008(void* other);
    virtual bool FUN_0000000c(void* other);
};

struct FUN_00582690_weather_t
{
    bool IsDifferentFrom(TESWeatherList* other);
};

// @fnv 0x0052afe0
bool FUN_005e79a0_t::IsClimateDifferent(TESForm* apCompare)
{
    int iIndex;
    TESClimate* i = dynamic_cast<TESClimate*>(apCompare);

    if (!i)
        return true;

    if (this->TESForm_CompareAllComponents(i))
        return true;

    for (iIndex = 0; iIndex < 2; ++iIndex)
    {
        if (((FUN_0052afe0_compare_t*)((unsigned char*)this + 0x38 + iIndex * 0xc))
                ->FUN_0000000c((void*)((unsigned char*)i + 0x38 + iIndex * 0xc)))
            return true;
    }

    if (((FUN_0052afe0_compare_t*)((unsigned char*)this + 0x18))->FUN_0000000c((void*)((unsigned char*)i + 0x18)))
        return true;

    if (((FUN_00582690_weather_t*)((unsigned char*)this + 0x30))
            ->IsDifferentFrom((TESWeatherList*)((unsigned char*)i + 0x30)))
        return true;

    if (memcmp((void*)((unsigned char*)this + 0x50), (void*)((unsigned char*)i + 0x50), 6) != 0)
        return true;

    return false;
}

struct FUN_0052ab80_base
{
    virtual ~FUN_0052ab80_base();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct FUN_0052ab80 : public FUN_0052ab80_base
{
    TESModel m_kStarsModel;
    TESWeatherList weatherList;
    TESTexture m_kSunTextures[2];

    void Reset();
    virtual ~FUN_0052ab80();
};

// @fnv 0x0052ab80
FUN_0052ab80::~FUN_0052ab80()
{
    Reset();
}

class ClimateCopy : public TESClimate
{
  public:
    void TESForm_CopyAllComponents(TESForm*);
    void TESClimate_CopyFrom(TESForm*);
};

class WeatherListCopy : public TESWeatherList
{
  public:
    void CopyWeatherList(const TESWeatherList*, bool);
};

// Copies climate data from a source TESForm into this ClimateCopy, including weather list, sun textures, stars model, and time settings.
// @fnv 0x0052af10
void ClimateCopy::TESClimate_CopyFrom(TESForm* source)
{
    TESClimate* climate;
    climate = dynamic_cast<TESClimate*>(source);
    if (!climate)
        return;

    TESForm_CopyAllComponents(climate);
    static_cast<WeatherListCopy&>(weatherList).CopyWeatherList(&climate->weatherList, false);

    {
        int i;
        for (i = 0; i < 2; ++i)
            m_kSunTextures[i].CopyFromBase(&climate->m_kSunTextures[i]);
    }

    m_kStarsModel.CopyFromBase(&climate->m_kStarsModel);
    memcpy(m_ucTimeSettings, climate->m_ucTimeSettings, 6);
}
