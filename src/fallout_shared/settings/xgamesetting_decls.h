// fallout_shared/settings/xgamesetting_decls.h: declares Setting, GameSettingCollection
#ifndef FNV_XGAMESETTING_DECLS_H
#define FNV_XGAMESETTING_DECLS_H


#include "TESFile.h"
#include "SETTING_VALUE.h"

// The canonical Setting layout, with declarations for the two unresolved
// helpers used by the game-setting reader. No shared header is modified.
#pragma pack(push, 4)
class Setting
{
  public:
    SETTING_VALUE uValue;
    const char* pKey;
    Setting(const char* key, float value);
    Setting(const char* key, int value);
    Setting(const char* key, char* value);
    virtual ~Setting();
    virtual bool IsPrefSetting();
    unsigned int FUN_004f8940();
    Setting& FUN_00c33170(const char* value);
};

template <class T> class SettingCollectionMap
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual bool ReadSetting(T& setting);
    virtual bool Open(bool create);
    virtual bool Close();
    virtual void vfn_20();
    virtual void vfn_24();
    char szFileName[260];
    TESFile* pFile;
};

class GameSettingCollection : public SettingCollectionMap<Setting>
{
  public:
    virtual bool ReadSetting(Setting& setting);
    virtual bool Open(bool create);
    virtual bool Close();
    virtual bool ReadSetting(TESFile* file, const char* key);

    // Actor::IsFleeing(bool) candidate is incompatible with this call site.
    TESFile* FUN_004f8960();
    Setting* FUN_004f8a30(const char* key);
    void SetField108(TESFile* file);
};
#pragma pack(pop)

FNV_STATIC_ASSERT(sizeof(Setting) == 0xC);
FNV_STATIC_ASSERT(offsetof(Setting, uValue) == 0x4);
FNV_STATIC_ASSERT(offsetof(Setting, pKey) == 0x8);
FNV_STATIC_ASSERT(offsetof(GameSettingCollection, pFile) == 0x108);

extern "C" void* __cdecl _alloca(unsigned int size);
const char* PrepareScriptMessage(const char* text, bool alternate);

#endif
