// Source layout: OSGlobals. PC corrections are in generate_headers.py.
#ifndef FNV_OSGLOBALS_H
#define FNV_OSGLOBALS_H

#include "layout_support.h"
// Partial PC prefix through sound; sizeof checks this prefix, not the entire runtime allocation.
#pragma pack(push, 4)
class OSGlobals
{
  public:
    unsigned char oneMore;         // +0x0
    unsigned char quitGame;        // +0x1
    unsigned char exitToMainMenu;  // +0x2
    unsigned char layoutPadding3;
    unsigned short layoutPadding4;
    bool isFlycam;  // +0x6
    unsigned char layoutPadding7;
    void* window;               // +0x8
    void* procInstance;         // +0xC
    unsigned int mainThreadID;  // +0x10
    void* mainThreadHandle;     // +0x14
    void* scrapHeapBuffer;      // +0x18
    unsigned int layoutPadding1C;
    OSInputGlobals* input;  // +0x20
    OSSoundGlobals* sound;  // +0x24
    unsigned int GetUptimeMilliseconds();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(OSGlobals) == 0x28);
FNV_STATIC_ASSERT(offsetof(OSGlobals, oneMore) == 0x0);
FNV_STATIC_ASSERT(offsetof(OSGlobals, quitGame) == 0x1);
FNV_STATIC_ASSERT(offsetof(OSGlobals, exitToMainMenu) == 0x2);
FNV_STATIC_ASSERT(offsetof(OSGlobals, isFlycam) == 0x6);
FNV_STATIC_ASSERT(offsetof(OSGlobals, window) == 0x8);
FNV_STATIC_ASSERT(offsetof(OSGlobals, procInstance) == 0xC);
FNV_STATIC_ASSERT(offsetof(OSGlobals, mainThreadID) == 0x10);
FNV_STATIC_ASSERT(offsetof(OSGlobals, mainThreadHandle) == 0x14);
FNV_STATIC_ASSERT(offsetof(OSGlobals, scrapHeapBuffer) == 0x18);
FNV_STATIC_ASSERT(offsetof(OSGlobals, input) == 0x20);
FNV_STATIC_ASSERT(offsetof(OSGlobals, sound) == 0x24);
#endif
