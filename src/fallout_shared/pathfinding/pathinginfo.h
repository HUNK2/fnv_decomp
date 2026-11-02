#ifndef FNV_PATHINGINFO_H
#define FNV_PATHINGINFO_H
#include "pathinginfo_decls.h"
class PathingInfo
{
  public:
    const unsigned char* vtable;
    unsigned int references;
    PathingInfo();
};
// @fnv 0x004968b0
PathingInfo::PathingInfo()
{
    vtable = &kVtbl_NiRefObject;
    references = 0;
    InitScriptRunLock((void*)&DAT_011f4400);
}
#endif
