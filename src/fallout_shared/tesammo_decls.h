// fallout_shared/tesammo_decls.h: declares BGSProjectile, TESAmmoEffect, MiddleLowProcess, TESAmmoInitCalls
#ifndef TESAMMO_DECLS_H
#define TESAMMO_DECLS_H

class Script;
#include "tesammo_types.h"

class BGSProjectile : public TESForm
{
};
class TESAmmoEffect : public TESForm
{
};

class MiddleLowProcess
{
  public:
    int GetProcessInteger();
    void SetProcessInteger(int);
};

class TESAmmoInitCalls
{
  public:
    unsigned int GetFieldBC();
    void* FUN_00923000();
    void FUN_00502cb0(void*);
};

extern "C"
{
    extern const char DAT_01026288[];
    extern const char DAT_01026238[];
    extern const char DAT_010261e8[];
}

int Warning(const char*, ...);

#endif
