// bsaudio/bsaudiolistener.cpp: BSAudioListener (2 functions)

#include "BSAudioListener.h"

// @fnv 0x00aeab50
void BSAudioListener::SetListenerID(unsigned int argument0)
{
    m_uiListenerFlags = argument0;
}
// @fnv 0x00aeab70
unsigned int BSAudioListener::GetListenerID()
{
    return m_uiListenerFlags;
}
