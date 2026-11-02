// gamebryo2.2/corelibs/nianimation/niextradatacontroller_decls.h: declares NiFixedString, NiStream, NiSingleInterpController, NiPSysModifierCtlr
#ifndef NIEXTRADATACONTROLLER_DECLS_H
#define NIEXTRADATACONTROLLER_DECLS_H

class NiFixedString
{
  public:
    const char* data;
};
class NiStream
{
  public:
    char padding[0xd8];
    unsigned int version;
    void ReadFixedString(NiFixedString&);
    void ReadStringTableEntry(NiFixedString&);
};
class NiSingleInterpController
{
  public:
    virtual void Reserved();
    char padding[0x34];
    void LoadBinary(NiStream&);
};
class NiPSysModifierCtlr : public NiSingleInterpController
{
  public:
    NiFixedString m_kTargetModifierName;
    void* m_pkTargetModifier;
    virtual void LoadBinary(NiStream&);
};
#endif
