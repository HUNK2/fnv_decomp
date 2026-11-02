// gamebryo2.2/corelibs/nimain/nitristripsdata_forwarders.h: declares NiLinesData, NiPSysData
#ifndef FNV_NITRISTRIPSDATA_FORWARDERS_H
#define FNV_NITRISTRIPSDATA_FORWARDERS_H
class NiStream;
class NiLinesData
{
  public:
    bool RegisterStreamables(NiStream&);
    void LinkObject(NiStream&);
};
class NiPSysData
{
  public:
    bool RegisterStreamables(NiStream&);
    void LinkObject(NiStream&);
};
#endif
