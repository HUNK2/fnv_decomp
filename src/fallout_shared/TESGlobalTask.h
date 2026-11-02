// fallout_shared/TESGlobalTask.h: declares TESFile, TESGlobal
#ifndef FNV_LUNA_TESGLOBAL_TASK_H
#define FNV_LUNA_TESGLOBAL_TASK_H

#include "TESForm.h"

class TESFile
{
  public:
    unsigned int GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void* data, unsigned int size);
    bool GetChunkData(unsigned int* value);
    bool NextChunk();
};

class TESGlobal : public TESForm
{
  public:
    BSStringT<char> cGlobalEditorID;
    char cType;
    unsigned char layoutPadding21[3];
    float fValue;
    virtual bool Load(TESFile* file);
};

#endif
