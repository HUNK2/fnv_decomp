// fallout_shared/music_local.h: declares TESSoundFile, BGSMusicType, MusicTrack
#ifndef FNV_MUSIC_LOCAL_H
#define FNV_MUSIC_LOCAL_H

#include "TESForm.h"
#include "TESFile.h"
class TESSoundFile : public BaseFormComponent
{
  public:
    BSStringT<char> m_kSoundFile;
    virtual void SetSoundFile(const char* name);
    unsigned int GetSoundFileLength() const;
    const char* GetSoundFile() const;
};
class BGSMusicType : public TESForm, public TESSoundFile
{
  public:
    class MusicTrack
    {
      public:
        char m_acTrackName[260];
        MusicTrack(const char* name);
    };
    float fVolumeScale;
    BSSimpleList<MusicTrack*> m_kMusicFiles;
    unsigned int m_uiSelectedSoundIndex;
    virtual bool Load(TESFile* file);
    virtual void InitItem();
    void UpdateLoadingStatusCallback();
};
FNV_STATIC_ASSERT(sizeof(TESSoundFile) == 12);
FNV_STATIC_ASSERT(sizeof(BGSMusicType) == 52);
FNV_STATIC_ASSERT(offsetof(BGSMusicType, fVolumeScale) == 36);
FNV_STATIC_ASSERT(offsetof(BGSMusicType, m_kMusicFiles) == 40);
FNV_STATIC_ASSERT(offsetof(BGSMusicType, m_uiSelectedSoundIndex) == 48);
#endif
