// bgsimpactdataset_TESFile.h: declares TESFile
#ifndef FNV_LOCAL_TESFILE_H
#define FNV_LOCAL_TESFILE_H
#include "layout_support.h"
class TESFile
{
  public:
    ENUM_FORM_ID GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData();
    bool NextChunk();
};
#endif
