// fallout_shared/bgsmusictype.cpp: BGSMusicType, MusicTypeDeletion, MusicTypeWriter, MusicTypeCopyEntry and more (8 functions)

#define BSSimpleList BSSimpleListWithoutItemsInList
#include "music_local.h"
#undef BSSimpleList
#include <malloc.h>

template <class T> struct BSSimpleList
{
    bool IsEmpty();
    unsigned int ItemsInList();
};

// Loads a music type record: reads the header, then handles EDID, OBND, FNAM and ANAM chunks until no more chunks remain, returning true.
// @fnv 0x00591550
bool BGSMusicType::Load(TESFile* file)
{
    int iChunkID;
    unsigned int size = 0;
    LoadRecordHeader(file);
    SetInitializationState(false);
    while (iChunkID = file->GetChunkID())
    {
        switch (iChunkID)
        {
        case 0x44494445: {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4d414e46: {
            char* soundFile = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(soundFile, 0);
            SetSoundFile(soundFile);
            break;
        }
        case 0x4d414e41: {
            float attenuation = 0.0f;
            file->GetChunkData(reinterpret_cast<unsigned int*>(&attenuation));
            fVolumeScale = attenuation;
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

extern "C" int __cdecl sprintf_s(char* buffer, unsigned int size, const char* format, ...);
unsigned int __cdecl GetRandomNumberInRange(int minimum, int maximum);

// Prefixes the sound file with Data\\Music unless it ends in a backslash, then selects a random track index when tracks exist.
// @fnv 0x00591410
void BGSMusicType::InitItem()
{
    if (IsFormInitialized())
        return;
    struct SoundFileNames
    {
        const char* name;
        const char* soundFile;
    } soundFileNames;
    if (GetSoundFileLength() > 2)
    {
        soundFileNames.soundFile = GetSoundFile();
        if (soundFileNames.soundFile[GetSoundFileLength() - 1] == '\\')
        {
            UpdateLoadingStatusCallback();
        }
        else
        {
            soundFileNames.name = GetSoundFile();
            char fullPath[260];
            sprintf_s(fullPath, 260, "%s\\%s", "Data\\Music", soundFileNames.name);
            SetSoundFile(fullPath);
        }
    }
    m_uiSelectedSoundIndex =
        reinterpret_cast<BSSimpleList<MusicTrack*>&>(m_kMusicFiles).IsEmpty()
            ? 0
            : GetRandomNumberInRange(0, reinterpret_cast<BSSimpleList<MusicTrack*>&>(m_kMusicFiles).ItemsInList() - 1);
    SetInitializationState(true);
}

struct MusicTypeDeletion : public BGSMusicType
{
    void* FUN_005912a0(unsigned int flags);
};

// Calls the BGSMusicType destructor and frees the object with operator delete when the low bit of flags is set.
// @fnv 0x005912a0
void* MusicTypeDeletion::FUN_005912a0(unsigned int flags)
{
    this->BGSMusicType::~BGSMusicType();
    if (flags & 1)
        ::operator delete(this);
    return this;
}

class MusicType_00591320 : public TESForm, public TESSoundFile
{
  public:
    float fVolumeScale;
    BSSimpleListWithoutItemsInList<BGSMusicType::MusicTrack*> m_kMusicFiles;
    unsigned int m_uiSelectedSoundIndex;
    void BGSMusicType_ClearData();
    virtual ~MusicType_00591320();
};

// Destructor for MusicType_00591320 that calls BGSMusicType_ClearData to perform cleanup.
// @fnv 0x00591320
MusicType_00591320::~MusicType_00591320()
{
    BGSMusicType_ClearData();
}

struct MusicTypeFileList_005913b0 : BGSMusicType
{
    void BGSMusicType_ClearData();
};
// Removes and frees every entry in m_kMusicFiles until the list is empty.
// @fnv 0x005913b0
void MusicTypeFileList_005913b0::BGSMusicType_ClearData()
{
    void* pEntry = 0;
    while (!m_kMusicFiles.IsEmpty())
    {
        pEntry = m_kMusicFiles.GetItem();
        m_kMusicFiles.RemoveHead();
        void* p = pEntry;
        operator delete(p);
        pEntry = 0;
    }
}

struct MusicSoundWriter : TESSoundFile
{
    void TESSoundFile_Save();
};

struct MusicSaveComponents
{
    TESForm form;
    MusicSoundWriter soundFile;
};

void FUN_00485910(int chunk, float value);

struct MusicTypeWriter : BGSMusicType
{
    void TESForm_StartForm();
    void TESForm_CloseForm();
    void BGSMusicType_SaveForm();
};

// Writes the music type save components by calling TESForm_StartForm, the sound file writer, and FUN_00485910 with the MANA chunk and fVolumeScale.
// @fnv 0x005916b0
void MusicTypeWriter::BGSMusicType_SaveForm()
{
    TESForm_StartForm();
    reinterpret_cast<MusicSaveComponents*>(this)->soundFile.TESSoundFile_Save();
    FUN_00485910(0x4d414e41, fVolumeScale);
    TESForm_CloseForm();
}

class MusicTypeCopyEntry : public BGSMusicType
{
  public:
    void TESForm_CopyAllComponents(TESForm* source);
    void BGSMusicType_CopyFrom(TESForm* source);
};

// Copies fVolumeScale from a BGSMusicType source and delegates the remaining copy to TESForm_CopyAllComponents.
// @fnv 0x005916f0
void MusicTypeCopyEntry::BGSMusicType_CopyFrom(TESForm* source)
{
    BGSMusicType* music = dynamic_cast<BGSMusicType*>(source);
    if (!music)
        return;
    fVolumeScale = music->fVolumeScale;
    TESForm_CopyAllComponents(music);
}

struct MusicFormComponentCompareView
{
    bool TESForm_CompareAllComponents(::TESForm* form);
};

struct MusicTypeCompareEntry : ::BGSMusicType
{
    bool BGSMusicType_Compare(::TESForm* form);
};

// Returns true if the given form is not a BGSMusicType, or if its fVolumeScale or form component differs from this entry.
// @fnv 0x00591740
bool MusicTypeCompareEntry::BGSMusicType_Compare(::TESForm* form)
{
    ::BGSMusicType* other = dynamic_cast< ::BGSMusicType*>(form);
    if (!other)
        return true;
    if (fVolumeScale != other->fVolumeScale)
        return true;
    if (reinterpret_cast<MusicFormComponentCompareView*>(this)->TESForm_CompareAllComponents(other))
        return true;
    return false;
}
