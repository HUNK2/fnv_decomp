// gamebryo2.2/corelibs/nimain/niintegersextradata_decls.h: declares NiExtraData, NiIntegerStreamEntry, NiIntegerStreamArray, NiIntegersExtraData
#ifndef NIINTEGERSEXTRADATA_DECLS_H
#define NIINTEGERSEXTRADATA_DECLS_H

class NiStream;
template <class T> void ReadBinaryValue(NiStream&, T&);
class NiExtraData
{
  public:
    unsigned int baseData[3];
    void LoadBinary(NiStream&);
};
struct NiIntegerStreamEntry
{
    unsigned int fields[3];
    void FUN_00c545d0(NiStream&);
};
struct NiIntegerStreamArray
{
    void FUN_00c54850(unsigned int);
    void FUN_00c54b70(NiIntegerStreamEntry&);
};
class NiIntegersExtraData : public NiExtraData
{
  public:
    NiIntegerStreamArray entries;
    void LoadBinary(NiStream&);
};
#endif
