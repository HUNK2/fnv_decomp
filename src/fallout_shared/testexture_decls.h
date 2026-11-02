// fallout_shared/testexture_decls.h: declares BaseFormComponent, TESFullName, TaskQueueInterface, TESTexture
#ifndef FNV_TESTEXTURE_PRIVATE_DECLS_H
#define FNV_TESTEXTURE_PRIVATE_DECLS_H


#include "layout_support.h"

#pragma pack(push, 4)
class BaseFormComponent
{
  public:
    BaseFormComponent();
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};

class TESFullName
{
  public:
    void SetFullName(const char* name);
};

class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char* destination, unsigned int size, const char* source);
};

class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> FullNameComponent;
    TESTexture();
    void InitializeComponent();
    static void ReadTextureData(TESTexture* texture, TESFile* file);
    static const char* NormalizeTextureFilePath(BSStringT<char>& result, const char* path);
    static void ConvertTexturePath(const char* path, char* output);
};
#pragma pack(pop)

char* __cdecl FUN_0040ab30(char* string, int character);

#endif
