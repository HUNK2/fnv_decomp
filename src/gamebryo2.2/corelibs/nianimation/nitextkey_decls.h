// gamebryo2.2/corelibs/nianimation/nitextkey_decls.h: declares NiFixedString, NiBinaryStream, NiStream, TimedTextEntry

class NiFixedString
{
  public:
    const char* m_pcString;
};
class NiBinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiCurrentPos;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* buffer, unsigned int size)
    {
        m_uiCurrentPos += m_pfnRead(this, buffer, size, &size, 1);
    }
};
class NiStream
{
  public:
    char pad0[0xd8];
    unsigned int m_uiNifVersion;
    char padDC[0x24c - 0xdc];
    NiBinaryStream* m_pUnderlyingStream;
    void ReadStringTableEntry(NiFixedString&);
    void ReadFixedString(NiFixedString&);
};
class TimedTextEntry
{
  public:
    float m_fTime;
    NiFixedString m_kText;
    void LoadBinary(NiStream&);
};
