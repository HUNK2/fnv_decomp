// gamebryo2.2/corelibs/nimain/niobject_packet_decls.h: declares BSFaceGenMorphData
#ifndef FNV_NIOBJECT_PACKET_DECLS_H
#define FNV_NIOBJECT_PACKET_DECLS_H
class GlobalObject_00869db0
{
  public:
    unsigned int GetSize();
};
// The PC body uses a member at +0x1ec and has no stack arguments.
class BSFaceGenMorphData
{
  public:
    unsigned int DynamicCast();

  private:
    char unknown_000[0x1ec];
    GlobalObject_00869db0 array_1ec;
};
#endif
