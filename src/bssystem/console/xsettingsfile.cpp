
//
// Partial S1 opening: the debug-settings accessor. The per-platform
// settings singleton (XSettingsFile) is lazily constructed and cached in a
// byte out of the cached instance.

#include "layout_support.h"

// The 0x44-byte settings singleton. The first three 0x14-byte members are
// the per-category setting collections; the remaining tail holds debug
// flags (byte at +0x3C) and a 4-byte state word at +0x40.
class XSettingsFile
{
  public:
    // Three 0x14-byte setting collections.
    char m_collections[3][0x14];
    // Debug flags packed in the tail, then a 4-byte state word.
    unsigned char m_debugFlags;        // +0x3C
    unsigned char m_uiStandInValue;    // +0x3D
    unsigned char m_iValueAfterStandIn;              // +0x3E
    unsigned char m_pAuxiliaryObject;  // +0x3F
    int m_uiContentCount;              // +0x40

    // Lazily constructs and caches the singleton, returning the cached
    // instance. Bound to the original accessor at 0x006FF580.
    static XSettingsFile* GetRandomGenerator();
};

// @fnv 0x006FF610
unsigned char GetDebugFlags()
{
    return XSettingsFile::GetRandomGenerator()->m_debugFlags;
}
