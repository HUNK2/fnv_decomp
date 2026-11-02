// gamebryo2.2/corelibs/nimain/nitexture_match.h: declares NiObjectNET, NiExtraData, NiTexture
#ifndef NITEXTURE_MATCH_H
#define NITEXTURE_MATCH_H


class NiExtraData;

class NiObjectNET
{
  public:
    unsigned char m_akPrefix[16];
    NiExtraData** m_ppExtraData;
    unsigned short m_usExtraDataCount;
    unsigned short m_usMaxSize;

    void LoadBinary(class NiStream&);
    void DeleteExtraData(unsigned short index);
};

class NiExtraData
{
  public:
    virtual void Slot0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};

extern "C" void(__stdcall* fnv_EnterCriticalSection)(void*);
extern "C" void(__stdcall* fnv_LeaveCriticalSection)(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern unsigned char DAT_011f4380;

class NiTexture : public NiObjectNET
{
  public:
    void LoadBinary(NiStream&);
};
#endif
