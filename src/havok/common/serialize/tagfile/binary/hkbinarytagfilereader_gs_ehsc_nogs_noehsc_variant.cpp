
// src/havok/common/serialize/tagfile/binary/hkbinarytagfilereader_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/serialize/tagfile/binary/hkbinarytagfilereader.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/tagfile/binary/hkbinarytagfilereader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/tagfile/binary/hkbinarytagfilereader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void* DAT_010d6ce8;
struct FUN_00dc5d30
{
    void* m_p;
    short m_usTrailingValue;
    short m_f;
    FUN_00dc5d30();
};
struct hkBinaryTagFileReaderVirtualObject
{
    virtual void FreeAllBlocks(int);
};
struct hkMemoryRouterContext
{
    virtual void FUN_00d00000();
    virtual void FUN_00d00004();
    virtual void FUN_00d00008();
    virtual void FUN_00d0000c();
    virtual void Free(void*, unsigned int);
};
struct NineIntegerRecord
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0c;
    hkMemoryRouterContext* m_p10;
};
NineIntegerRecord* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c856c0(void*, void*);
struct hkLargeBlockAllocator
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0c;
    void* m_p10;
    hkBinaryTagFileReaderVirtualObject* m_p14;
    void* m_p18;
    unsigned int m_n1c;
    unsigned int m_flags20;
    void** m_p24;
    int m_n28;
    unsigned int m_flags2c;
    void* m_p30;
    unsigned int m_n34;
    unsigned int m_flags38;

    void FreeAllBlocks();
    void FUN_00dd91f0();
};
class hkMemoryAllocatorDC5D;
struct hkMemoryRouterDC5D
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC5D* m_pStreamAllocator;
    hkMemoryAllocatorDC5D& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDC5D& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);
template <class T> __forceinline void constructWithCopyDC5D(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <class T> class hkArrayDC5D
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorDC5D& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyDC5D(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};
char* __cdecl AllocateWithHeader(hkMemoryAllocatorDC5D* pkAlloc, int iNumBytes) throw();
class hkBinaryReaderDC5D
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    hkArrayDC5D<char*> m_pStringFunctions;

    int FUN_00dc5bd0() throw();
    void FUN_00dd90d0(void* pvBuf, int iNumBytes) throw();
    char* ReadString();
};
extern "C" char* __fastcall ReadString(void* p);
extern "C" int __fastcall FUN_00dc5bd0(void* p);
void __cdecl FUN_00c908c0(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
struct VirtualObject
{
    virtual void dummy0();
    virtual void dummy1();
    virtual void* vtable_8();
};
struct Struct3;
struct Field10Class
{
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void* vtable_0c(Struct3* s);
    virtual void dummy4();
    virtual void dummy5();
    virtual int* vtable_18(void* outVal);
    virtual void dummy7();
    virtual void dummy8();
    virtual void vtable_24(char* name);
};
struct Item
{
    char* m_name;
    int m_type;
    int m_extra;
    char* m_altName;
};
static __forceinline void __fastcall callFree(hkMemoryRouterContext* ctx, void* p, unsigned int size)
{
    ctx->Free(p, size);
}
struct ItemArray
{
    Item* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease()
    {
        NineIntegerRecord* r = _D1A0E0GetMemoryRouter();
        hkMemoryRouterContext* ctx = r->m_p10;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            callFree(ctx, m_data, (cap & 0x3fffffff) * 16);
        }
    }
};
struct Struct3
{
    char* m_str;
    int m_type;
    void* m_obj;
    ItemArray m_items;
};
template <class T> inline void constructWithCopy(T* destination, const T* source, int count)
{
    for (int i = 0; i < count; ++i)
        destination[i] = source[i];
}
template <class T> struct ObjectArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int index)
    {
        return m_data[index];
    }
};
struct TagFileReader
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Field10Class* m_p10;
    hkBinaryTagFileReaderVirtualObject* m_p14;
    ObjectArray<VirtualObject*> m_kTrackedObjects;
    ObjectArray<void*> m_objects24;
    ObjectArray<void*> m_objects30;
    Field10Class* getP10()
    {
        return m_p10;
    }
    int ReadTagFileEntry();
};
struct Locals
{
    void* outVal;
    Struct3 s;
};
struct ReaderDC5BD0
{
    int FUN_00dd8fe0(void* pvBuffer, int iSize, int iCount);
    int FUN_00dc5bd0();
};
__forceinline void ReadVarIntDC5BD0(ReaderDC5BD0& kReader, __int64& kValue)
{
    unsigned char ucByte;
    kReader.FUN_00dd8fe0(&ucByte, 1, 1);
    unsigned __int64 uiByte = (int)ucByte;
    unsigned __int64 uiValue = (uiByte & ~0x81) >> 1;
    int bNegative = (int)(uiByte & 1);
    int iShift = 6;
    while (uiByte & 0x80)
    {
        kReader.FUN_00dd8fe0(&ucByte, 1, 1);
        uiByte = (int)ucByte;
        uiValue |= (uiByte & ~0x80) << iShift;
        iShift += 7;
    }
    if (bNegative)
    {
        kValue = -(__int64)uiValue;
        return;
    }
    kValue = uiValue;
}
struct ReaderDC5C80
{
    int FUN_00dd8fe0(void* pvBuffer, int iSize, int iCount);
    __int64 ReadVarInt();
};
struct FUN_00dc5d50_Local
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;

    void FUN_00dc5f30(unsigned int, unsigned int);
    void FUN_00dc6e50(unsigned int);
    void FreeAllBlocks();
};
unsigned int __stdcall hkBinaryTagfileReader_load(unsigned int a, unsigned int b, unsigned int c);

struct hkDataObjectImpl;

struct DataObjectImplReference
{
    hkDataObjectImpl* m_pClassImpl;
    DataObjectImplReference(hkDataObjectImpl* impl);
};

struct hkOstream
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    void* m_pStreamWriter;
    hkOstream(void* buf, int bufSize);
    ~hkOstream();
    hkOstream& operator<<(const char* s);
};

struct hkError
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual int message(int type, int id, const char* desc, const char* file, int line);
};

extern hkError* DAT_01268360;

struct hkBinaryTagfileReader
{
    void ReadByteArray(void* buf, int size, int count);
    int ReadTag();
    int readMetadata();
    DataObjectImplReference readObjectTopLevel(int tag);

    DataObjectImplReference FUN_00dc6e50();
};

// @fnv 0x00dc6e50
DataObjectImplReference hkBinaryTagfileReader::FUN_00dc6e50()
{
    char buf[512];
    int magic0;
    ReadByteArray(&magic0, 4, 1);
    int magic1;
    ReadByteArray(&magic1, 4, 1);
    if (magic0 == 0xcab00d1e && magic1 == 0xd011face)
    {
        for (int tag = ReadTag(); tag != -1; tag = ReadTag())
        {
            switch (tag)
            {
            case 1: {
                if (ReadTag() != 0)
                {
                    {
                        hkOstream ostr(buf, sizeof(buf));
                        ostr << "Unrecognised tagfile version.";
                        DAT_01268360->message(1, 0x2ab6036f, buf, ".\\Tagfile\\Binary\\hkBinaryTagfileReader.cpp",
                                              0x1d9);
                    }
                    return DataObjectImplReference(0);
                }
                break;
            }
            case 2: {
                if (readMetadata() == 1)
                {
                    return DataObjectImplReference(0);
                }
                break;
            }
            case 3:
            case 4:
            case 6: {
                return readObjectTopLevel(tag);
            }
            default: {
                return DataObjectImplReference(0);
            }
            }
        }
    }
    else
    {
        hkOstream ostr(buf, sizeof(buf));
        ostr << "This does not look like a binary tagfile (magic number mismatch)";
        DAT_01268360->message(1, 0x2ab6036f, buf, ".\\Tagfile\\Binary\\hkBinaryTagfileReader.cpp", 0x1c5);
    }
    return DataObjectImplReference(0);
}
