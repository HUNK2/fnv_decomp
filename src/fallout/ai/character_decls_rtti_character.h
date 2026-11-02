// fallout/ai/character_decls_rtti_character.h: declares BGSLoadFormBuffer, Character, PlayerCharacter, AudioMarkerDataCalls, CharacterActorCalls
#ifndef FNV_CHARACTER_DECLS_H
#define FNV_CHARACTER_DECLS_H

#define PlayerCharacter PlayerCharacter_ActorHeader
#include "actor_rtti_character.h"
#undef PlayerCharacter

class BGSLoadFormBuffer
{
  public:
    virtual unsigned char GetVersion();
    void ReadTypedData(void* destination, unsigned int size);
};

class Character : public Actor
{
  public:
    BipedAnim* pBiped;
    float m_fFirstResetValue;
    float m_fSecondValue;
    bool m_bTrespassing;
    bool m_bActorGuard;
    unsigned char layoutPadding1C2[2];
    float m_fThirdValue;
    virtual void Unk_137(void);
    virtual void Unk_138(void);

    MagicTarget* GetMagicTarget();
    void InitLoadGame(BGSLoadFormBuffer* buffer);
    void ApplyLoadBuffer(BGSLoadFormBuffer* buffer);
    void Revert(BGSLoadFormBuffer* buffer);
    void LoadGame(BGSLoadFormBuffer* buffer);
    void* GetCurrentMusicMarker();
};

class MusicMarkerReference;
class PlayerCharacter
{
  public:
    MusicMarkerReference* GetMusicMarkerReference();
};

class AudioMarkerDataCalls
{
  public:
    void* GetData();
};

class CharacterActorCalls
{
  public:
    void InitLoadGame(BGSLoadFormBuffer* buffer);
    void ApplyLoadBuffer(BGSLoadFormBuffer* buffer);
    void Revert(BGSLoadFormBuffer* buffer);
    void LoadGame(BGSLoadFormBuffer* buffer);
};
#endif
