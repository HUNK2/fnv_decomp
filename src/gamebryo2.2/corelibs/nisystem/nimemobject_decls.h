// gamebryo2.2/corelibs/nisystem/nimemobject_decls.h: declares NiPoint2, SNAEntry, NiObject, NiFixedString, NiProperty
class Flag512Receiver
{
  public:
    void FUN_00633ba0(bool enabled, unsigned int mask);
    void SetFlag512(bool enabled);
};
class NiPoint2
{
  public:
    float x, y;
    NiPoint2(float a, float b);
};
class SNAEntry
{
  public:
    static void* operator new[](unsigned int size);
};
extern void* DAT_011f6080;

// Declarations for the constructor/getter span.
class NiObject
{
  public:
    unsigned int words[2];
    NiObject();
};
class NiFixedString
{
  public:
    const char* value;
};
extern NiFixedString EmptyFS;
extern unsigned char DAT_0109b244[];
extern unsigned char DAT_011f4304[];
class NiProperty : public NiObject
{
  public:
    NiFixedString name;
    void* controller;
    void* extraData;
    unsigned short extraDataSize, extraDataCapacity;
    NiProperty();
};
