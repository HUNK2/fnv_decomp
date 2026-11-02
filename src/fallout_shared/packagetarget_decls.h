// fallout_shared/packagetarget_decls.h: declares BGSCameraPath
#ifndef FNV_PACKAGETARGET_DECLS_H
#define FNV_PACKAGETARGET_DECLS_H

enum PACK_LOC_TYPE
{
    PACK_LOC_TYPE_INVALID = -1
};
class TESForm;
class BGSCameraPath
{
  public:
    int HasNameForWarning();
};
TESForm* GetFormByID(unsigned int);
int Warning(const char*, ...);
#endif
