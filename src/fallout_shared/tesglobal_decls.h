// fallout_shared/tesglobal_decls.h: declares TESGlobal
#ifndef TESGLOBAL_DECLS_H
#define TESGLOBAL_DECLS_H
#include "TESForm.h"
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
