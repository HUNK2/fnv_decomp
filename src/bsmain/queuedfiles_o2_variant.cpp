
// src/bsmain/queuedfiles_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsmain/queuedfiles.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "queuedfiles.h"

struct FUN_0063fa10
{
    virtual ~FUN_0063fa10();
    void FUN_00c3cee0(char const*);
    void LookupFileEntryByArchive(int);
};

struct QBase : FUN_0063fa10
{
    QBase(int);
};

struct _NiStreamCtorAlias
{
    _NiStreamCtorAlias();
    virtual ~_NiStreamCtorAlias();
};

struct BSStream : _NiStreamCtorAlias
{
    char pad[0x5c0];
    int m_5c4;
    int m_5c8;
    BSStream()
    {
        m_5c8 = 0;
        m_5c4 = 0;
    }
    virtual ~BSStream();
};

struct FUN_00b60640 : QBase
{
    char pad[0x2c];
    BSStream m_stream;
    FUN_00b60640(char const* filename);
    virtual ~FUN_00b60640();
};

// @fnv 0x00b60640
FUN_00b60640::FUN_00b60640(char const* filename) : QBase(2)
{
    FUN_00c3cee0(filename);
    LookupFileEntryByArchive(0);
}
