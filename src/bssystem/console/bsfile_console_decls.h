// bssystem/console/bsfile_console_decls.h: declares NiFile, BSFile
class TESFile;
class FUN_00474560
{
  public:
    FUN_00474560(unsigned int);
    virtual void vfn_00();
};
template <class K, class V> class NiTPointerMap : public FUN_00474560
{
  public:
    NiTPointerMap(unsigned int);
    virtual void vfn_00();
};
extern int DAT_010a2480;
extern int DAT_010a2484;
extern int DAT_010a2488;
class NiFile
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual int vfn_28();
    void Seek(int, int);
    char pad04[0x24];
    int buffered;
    char pad2c[0x124];
    int position;
};
class BSFile : public NiFile
{
  public:
    void Seek(int, int);
};
