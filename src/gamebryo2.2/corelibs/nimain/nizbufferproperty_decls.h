// gamebryo2.2/corelibs/nimain/nizbufferproperty_decls.h: declares NiAlphaAccumulator, NiAlphaProperty
class NiAlphaAccumulator
{
  public:
    NiAlphaAccumulator();
    unsigned char storage[0x30];
};
extern unsigned int kVtbl_NiAlphaAccumulator;
class NiAlphaProperty : public NiAlphaAccumulator
{
  public:
    NiAlphaProperty();
    unsigned char enabled, flag1, flag2;
};
