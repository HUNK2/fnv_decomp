// bsmain/setting_declarations.h: declares INISettingCollection, INIPrefSettingCollection
#ifndef FNV_SETTING_PRIVATE_DECLARATIONS_H
#define FNV_SETTING_PRIVATE_DECLARATIONS_H


#include "../../include/Setting.h"

// Private declarations: pack Setting layouts and clean public PC declarations.
// No executable dependency implementations are introduced here.
template <class T> class NiTPrimitiveArray;

template <class T> class SettingCollection
{
  public:
    SettingCollection();
    virtual ~SettingCollection();
    virtual void Add(T* setting);
    virtual void Remove(T* setting);
    virtual unsigned int GetViewerStrings(NiTPrimitiveArray<char*>* strings);
    virtual bool WriteSetting(T& setting);
    virtual bool ReadSetting(T& setting);
    virtual bool Open(bool write);
    virtual bool Close();
    virtual bool WriteAllSettings();
    virtual bool ReadAllSettings();

    char m_acPathBuffer[260];
    void* pHandle;
};

template <class T> class SettingCollectionList : public SettingCollection<T>
{
  public:
    SettingCollectionList();
    virtual ~SettingCollectionList();
    virtual void Add(T* setting);
    virtual void Remove(T* setting);
    virtual unsigned int GetViewerStrings(NiTPrimitiveArray<char*>* strings);
    virtual bool WriteAllSettings();
    virtual bool ReadAllSettings();
    bool Get(const char* key, T*& result);
    T* GetPtr(const char* key);
    BSSimpleList<T*>* Head();
    BSSimpleList<T*>* Next(BSSimpleList<T*>* position);

    BSSimpleList<T*> m_kSettingList;
};

class INISettingCollection : public SettingCollectionList<Setting>
{
  public:
    INISettingCollection();
    virtual ~INISettingCollection();
    virtual unsigned int GetViewerStrings(NiTPrimitiveArray<char*>* strings);
    virtual bool WriteSetting(Setting& setting);
    virtual bool ReadSetting(Setting& setting);
    virtual bool Open(bool write);
    virtual bool Close();
};

class INIPrefSettingCollection : public INISettingCollection
{
  public:
    INIPrefSettingCollection();
    virtual ~INIPrefSettingCollection();
};

template <class Collection> class SettingT : public Setting
{
  public:
    SettingT(const char* key, float value);
    SettingT(const char* key, int value);
    SettingT(const char* key, char* value);
    virtual ~SettingT();
    static Collection* GetCollection();

  protected:
    static Collection* ms_pCollection;
    static void EnsureCollection();
};

// These are declarations only. The pack identifies the real global allocator.
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* pointer);

FNV_STATIC_ASSERT(sizeof(SettingCollection<Setting>) == 0x10C);
FNV_STATIC_ASSERT(offsetof(SettingCollection<Setting>, m_acPathBuffer) == 4);
FNV_STATIC_ASSERT(offsetof(SettingCollection<Setting>, pHandle) == 0x108);
FNV_STATIC_ASSERT(sizeof(SettingCollectionList<Setting>) == 0x114);
FNV_STATIC_ASSERT(offsetof(SettingCollectionList<Setting>, m_kSettingList) == 0x10C);
FNV_STATIC_ASSERT(sizeof(INISettingCollection) == 0x114);
FNV_STATIC_ASSERT(sizeof(INIPrefSettingCollection) == 0x114);
FNV_STATIC_ASSERT(sizeof(SettingT<INISettingCollection>) == 0xC);
FNV_STATIC_ASSERT(sizeof(SettingT<INIPrefSettingCollection>) == 0xC);

#endif
