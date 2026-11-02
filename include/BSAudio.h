// Source layout: BSAudio. PC corrections are in generate_headers.py.
#ifndef FNV_BSAUDIO_H
#define FNV_BSAUDIO_H

#include "layout_support.h"
#include "BSAudioSyncTimer.h"
#pragma pack(push, 4)
class BSAudio
{
  public:
    void** m_ppVirtualMethodTable;             // +0x0
    bool m_bAudioEnabled;        // +0x4
    bool bInitialized;           // +0x5
    bool m_bUseMultipleThreads;  // +0x6
    unsigned char layoutPadding7;
    unsigned int m_uiAudioFlags;  // +0x8
    bool m_bAudioOutputPaused;    // +0xC
    unsigned char layoutPaddingD;
    unsigned short layoutPaddingE;
    BSAudioListener* m_pAudioListener;                                                      // +0x10
    BSAudioSyncTimer m_kAudioBackendData;                                                  // +0x14
    bool___cdecl__unsigned_int__char___unsigned_int___void___* m_pfnReadAudioData;          // +0x20
    bool___cdecl__const_char___char___unsigned_int___void___* m_pfnReadAudioFile;           // +0x24
    bool___cdecl__char__* m_pfnIsAudioFileAvailable;                                        // +0x28
    unsigned_int___cdecl__BSSoundHandle___void___unsigned_int__* m_pfnGetSoundHandleValue;  // +0x2C
    void___cdecl___* m_pfnInitializeAudio;                                                  // +0x30
    void___cdecl___* m_pfnShutdownAudio;                                                    // +0x34
    void SetAudioState(unsigned int);
    static BSAudio* GetSingleton();
    SoundPlaybackHandle GetSoundHandleByFormID(unsigned int formID, unsigned int flags);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSAudio) == 0x38);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_bAudioEnabled) == 0x4);
FNV_STATIC_ASSERT(offsetof(BSAudio, bInitialized) == 0x5);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_bUseMultipleThreads) == 0x6);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_uiAudioFlags) == 0x8);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_bAudioOutputPaused) == 0xC);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_pAudioListener) == 0x10);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_kAudioBackendData) == 0x14);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_pfnReadAudioData) == 0x20);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_pfnReadAudioFile) == 0x24);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_pfnIsAudioFileAvailable) == 0x28);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_pfnGetSoundHandleValue) == 0x2C);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_pfnInitializeAudio) == 0x30);
FNV_STATIC_ASSERT(offsetof(BSAudio, m_pfnShutdownAudio) == 0x34);
#endif
