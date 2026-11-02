// gamebryo2.2/corelibs/nimain/nitristrips_decls.h: declares NiParticles, NiTriStrips
class NiParticles
{
  public:
    NiParticles();
    unsigned int* vtable;
};
class NiTriStrips : public NiParticles
{
  public:
    NiTriStrips();
};
extern unsigned int DAT_0109ed94;
