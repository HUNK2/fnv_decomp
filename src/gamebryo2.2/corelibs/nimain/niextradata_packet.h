// gamebryo2.2/corelibs/nimain/niextradata_packet.h: declares NiObject, NiFixedString, NiAccumulator, NiExtraData, NiBinaryStream and more

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long* value);
class NiStream;
class NiObject
{
  public:
    NiObject();
    virtual void vfn_00();
    virtual void vfn_04();
    virtual const void* GetRTTI();
    unsigned int refs;
    virtual void LoadBinary(NiStream&);
};
class NiFixedString;
extern NiFixedString EmptyFS;
extern void* kVtbl_NiExtraData[];
class NiFixedString
{
  public:
    void* handle;
    NiFixedString& operator=(const NiFixedString& rhs)
    {
        if (rhs.handle != EmptyFS.handle)
            InterlockedIncrement((long*)((char*)rhs.handle - 8));
        if (handle != EmptyFS.handle)
            InterlockedDecrement((long*)((char*)handle - 8));
        handle = rhs.handle;
        return *this;
    }
};
class NiAccumulator
{
  public:
    void* vtable;
    unsigned int refs;
    void* camera;
    void ClearCamera();
};
class __declspec(novtable) NiExtraData : public NiObject
{
  public:
    NiFixedString name;
    void LinkObject(NiStream&);
    void LoadBinary(NiStream&);
    NiExtraData(const NiFixedString&);
};
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int ReadRaw(void* out, unsigned int n, unsigned int* size)
    {
        return read(this, out, n, size, 1);
    }
    void Read(void* out, unsigned int n)
    {
        unsigned int size = 4;
        position += ReadRaw(out, n, &size);
    }
};
class NiStream
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
    virtual void RegisterObject(NiObject*);
    char pad[0xd4];
    unsigned int version;
    char pad2[0x170];
    NiBinaryStream* input;
    NiObject* GetLoadedObject();
    void ResetStreamState();
    void ReadStringTableEntry(NiFixedString&);
    void ReadFixedString(NiFixedString&);
};
void* _NiMalloc(unsigned int);
template <class T> void ReadBinaryValue(NiStream&, T*, unsigned int);
extern const char g_011c7820_arg1[];

inline bool IsExactKindOf(const void* type, NiObject* object)
{
    if (object)
        return object->GetRTTI() == type;
    return false;
}

inline void ReadCount(NiStream& stream, unsigned int& count)
{
    stream.input->Read(&count, 4);
}

class NiMemObject
{
  public:
    static void* operator new(unsigned int) throw();
};
class NiBinaryExtraData : public NiExtraData, public NiMemObject
{
  public:
    unsigned int count;
    unsigned char* data;
    NiBinaryExtraData(unsigned int, unsigned char*) throw();
};
