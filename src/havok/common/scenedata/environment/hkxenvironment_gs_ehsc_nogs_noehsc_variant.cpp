
// src/havok/common/scenedata/environment/hkxenvironment_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/scenedata/environment/hkxenvironment.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/scenedata/environment/hkxenvironment.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/environment/hkxenvironment.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkxEnvironment.h"
struct HKXMemoryManager
{
    virtual void Unused1()
    {}
    virtual void Unused2()
    {}
    virtual void Free(void* p, unsigned short size) = 0;
};
struct HKXMemoryRouter
{
    char padding[0x10];
    HKXMemoryManager* manager;
};
struct HKXEnvironmentStandIn
{
    char padding[4];
    unsigned short size;
    void DestroyEnvironment();
    HKXEnvironmentStandIn* FUN_00e3f8a0(unsigned char flags);
};
HKXMemoryRouter* _D1A0E0GetMemoryRouter();
extern int DAT_010ebab8;
struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* FUN_00e3f510(unsigned int unusedArg);
};
struct HavokString
{
    char* text;
};
struct EnvironmentVariable
{
    HavokString name;
    HavokString value;
};
struct HavokAllocator
{
    virtual ~HavokAllocator();
    virtual void* AllocateMemoryBlock(int);
    virtual void ReleaseBlock(void*, int);
    virtual void* AllocateBufferWithSize(int&);
    virtual void ReturnMemory(void*, int);
};
HKXMemoryRouter* __cdecl FUN_00c85750();
void __fastcall FUN_00cb0c00(HavokString* string);
struct EnvironmentArray
{
    EnvironmentVariable* data;
    int size;
    int capacityAndFlags;

    __forceinline void release()
    {
        HavokAllocator* allocator = reinterpret_cast<HavokAllocator*>(FUN_00c85750()->manager);
        EnvironmentVariable* entry = data;
        if (size > 0)
        {
            int remaining = size;
            do
            {
                FUN_00cb0c00(&entry->value);
                FUN_00cb0c00(&entry->name);
                ++entry;
            } while (--remaining != 0);
        }
        size = 0;
        if ((static_cast<unsigned int>(capacityAndFlags) & 0x80000000u) == 0)
            allocator->ReturnMemory(data, (capacityAndFlags & 0x3fffffff) * sizeof(EnvironmentVariable));
        data = 0;
        capacityAndFlags = 0x80000000;
    }
};
struct EnvironmentLayout
{
    void** vtable;
    unsigned short memoryFlags;
    short referenceCount;
    EnvironmentArray variables;
};
hkBaseObject::~hkBaseObject()
{}

struct hkMemoryAllocator
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct hkMemoryRouterStandIn
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocator* m_pStreamAllocator;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

hkMemoryRouterStandIn* getMemoryRouter();

struct hkStringStandIn
{
    static int strLen(const char* str);
};

class InlineStorageString
{
  public:
    InlineStorageString();
    __forceinline ~InlineStorageString()
    {
        hkMemoryAllocator& a = getMemoryRouter()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            a.ReturnMemory(m_data, m_iCapacityState & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    InlineStorageString& operator=(const InlineStorageString& other);
    InlineStorageString& operator=(const char* s);
    InlineStorageString& operator+=(const char* s);
    const char* cString() const
    {
        return m_data;
    }

    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char m_kStorage[128];
};

class hkOstream
{
  public:
    hkOstream(void* buf, int bufSize);
    ~hkOstream();
    hkOstream& operator<<(const char* s);

    int unk00;
    int unk04;
    int unk08;
};

class hkError
{
  public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual int message(int type, int id, const char* description, const char* file, int line);

    static hkError* s_instance;
};

struct hkxEnvironmentTransition
{
    int m_uiContentCount;
    int m_pRayCastInput;
    int m_newState;
    int m_pAction;
};

extern const hkxEnvironmentTransition s_transitionTable[32];

struct hkxEnvironmentParser : public hkxEnvironment
{
    void AddVariable(const char* name, const char* value);
    int FUN_00e3f520(const char* str);
};

// @fnv 0x00e3f520
int hkxEnvironmentParser::FUN_00e3f520(const char* str)
{
    int state = 0;
    int pos = 0;
    InlineStorageString name;
    InlineStorageString value;
    const int length = hkStringStandIn::strLen(str);

    do
    {
        int input = 4;
        if (pos >= length)
        {
            input = 5;
        }
        else
        {
            const char c = str[pos];
            if (c <= ' ')
            {
                input = 0;
            }
            if (c == '"')
            {
                input = 1;
            }
            else if (c == '=')
            {
                input = 2;
            }
            else if (c == ';')
            {
                input = 3;
            }
        }

        int action = 6;
        int newState = 9;
        int i = 0;
        do
        {
            if (s_transitionTable[i].m_uiContentCount == state && s_transitionTable[i].m_pRayCastInput == input)
            {
                newState = s_transitionTable[i].m_newState;
                action = s_transitionTable[i].m_pAction;
            }
        } while (++i < 32);
        switch (action)
        {
        case 6: {
            char assertBuf[512];
            hkOstream ostr(assertBuf, sizeof(assertBuf));
            ostr << "Error parsing environment string: '" << str << "'";
            hkError::s_instance->message(1, 0xabba7881, assertBuf, ".\\Environment\\hkxEnvironment.cpp", 308);
            return 1;
        }
        case 0:
            pos++;
            break;
        case 1: {
            char tmp[2] = {str[pos], 0};
            name += tmp;
            pos++;
            break;
        }
        case 2: {
            char tmp[2] = {str[pos], 0};
            value += tmp;
            pos++;
            break;
        }
        case 3:
            AddVariable(name.cString(), value.cString());
            name = value = "";
            pos++;
            break;
        case 4:
            AddVariable(name.cString(), 0);
            name = value = "";
            pos++;
            break;
        case 5:
            break;
        default: {
            char assertBuf[512];
            hkOstream ostr(assertBuf, sizeof(assertBuf));
            ostr << "Internal Error: Unknown action parsing environment string: '" << str << "'";
            hkError::s_instance->message(1, 0xabba0032, assertBuf, ".\\Environment\\hkxEnvironment.cpp", 320);
            return 1;
        }
        }
        state = newState;
    } while (state != 8);
    return 0;
}
