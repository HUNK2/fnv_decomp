// bgsencounterzone_TESFile.h: declares TESFile
#ifndef FNV_LOCAL_TESFILE_H
#define FNV_LOCAL_TESFILE_H
#include "bgsencounterzone_layout_support.h"
class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData();
    bool NextChunk();
};
#endif
