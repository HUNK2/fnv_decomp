// src/bscore/bscoremessage.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bscore/bscoremessage.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00aa4d30
int __cdecl FUN_00aa4d30()
{
    return 0;
}

struct BSCoreMessage;

class BSCoreMessage_shell
{
  public:
    BSCoreMessage* __thiscall FUN_00aa4d40(unsigned int auiTextID, unsigned int auiCaptionID, const char* apcText,
                                           const char* apcCaption, unsigned int aStyle);
};

// @fnv 0x00aa4d40
BSCoreMessage* BSCoreMessage_shell::FUN_00aa4d40(unsigned int auiTextID, unsigned int auiCaptionID, const char* apcText,
                                                 const char* apcCaption, unsigned int aStyle)
{
    return 0;
}

struct P03MM
{
    void _DeallocateAlias(void*);
};
extern P03MM g_memoryManager;
struct BSCoreMessage
{
    void FUN_00aa4c80();
    void* FUN_00aa4d00(unsigned int);
};
// Calls FUN_00aa4c80, then if bit 0 of flags is set deallocates this via g_memoryManager, and returns this.
// @fnv 0x00aa4d00
void* BSCoreMessage::FUN_00aa4d00(unsigned int flags)
{
    FUN_00aa4c80();
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}
