// fallout_shared/tesobjectrefr_decls.h: declares TESObjectREFR, DurationData
#ifndef FNV_TESOBJECTREFR_DECLS_H
#define FNV_TESOBJECTREFR_DECLS_H

// Private declarations for fallout_shared/tesobjectrefr.cpp (unit army-glm-5257).
// Signatures follow the canonical bindings from IDENTITIES.md / lookup sym;
// layouts here are minimal and private to this translation unit.

union SETTING_VALUE
{
    float f;
};

class GameSettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> DAT_011f6da8;
extern SettingT<GameSettingCollection> DAT_011f6db4;

class GlobalObject_00559cc0
{
  public:
    bool RemoveAt(unsigned int);
};
extern GlobalObject_00559cc0 g_011ca304;

class GlobalObject_00593240
{
  public:
    char storage[4];
};
extern GlobalObject_00593240 g_011ca8b4;

class GlobalObject_00878030
{
  public:
    char storage[4];
};
extern GlobalObject_00878030 g_011deffc;

class GarbageCollectorUpdateState;

class BGSEncounterZone;
extern BGSEncounterZone* DAT_011c9520;
extern unsigned char DAT_011c7a58;
extern unsigned char DAT_011dd435;

class TESObjectREFR
{
  public:
    virtual ~TESObjectREFR();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    unsigned char pad[0x38];
    float m_fObjectScale;  // +0x3C
    static BGSEncounterZone* FindEncounterZone();
    float GetScale();
};

class DurationData
{
  public:
    char month;  // +0x0
    int FUN_00678ca0();
};

#endif
