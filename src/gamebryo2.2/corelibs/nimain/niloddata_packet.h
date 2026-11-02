// gamebryo2.2/corelibs/nimain/niloddata_packet.h: declares NiLODData
#ifndef NILODDATA_PACKET_H
#define NILODDATA_PACKET_H
// PC layout inferred from the covered stream-write routine.
class NiLODData
{
  public:
    unsigned int Write(const void* buffer, unsigned int count);

  private:
    unsigned char prefix[0x1c];
    unsigned int position;
    unsigned int reserved;
    void* stream;
};
unsigned int __cdecl _access_s(const void*, unsigned int, unsigned int, void*);
#endif
