// gamebryo2.2/corelibs/nimain/niloddata.cpp: NiLODData (5 functions)
#include "niloddata_packet.h"
// Writes count bytes from buffer to the stream, advances position by the bytes written, and returns that count.
// @fnv 0x00aa1570
unsigned int NiLODData::Write(const void* buffer, unsigned int count)
{
    unsigned int written = _access_s(buffer, 1, count, stream);
    position += written;
    return written;
}

extern const char* const g_011f5ee8_arg1;

// @fnv 0x00aa09e0
const char* __cdecl NiLODData_GetRTTI()
{
    return (const char*)&g_011f5ee8_arg1;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern long volatile DAT_011f4400;
extern int DAT_0109b4f4;
struct NiRefObject
{
    virtual ~NiRefObject()
    {}
    unsigned int m_uiRefCount;
    NiRefObject() : m_uiRefCount(0)
    {
        InterlockedIncrement(&DAT_011f4400);
    }
};
struct FUN_00a5d3a0 : NiRefObject
{
    FUN_00a5d3a0();
};
// Initialises the object by storing the vtable pointer DAT_0109b4f4 into its first field.
// @fnv 0x00a5d3a0
FUN_00a5d3a0::FUN_00a5d3a0()
{
    *(void**)this = (void*)&DAT_0109b4f4;
}

namespace fnv_00aa09f0 {
extern int DAT_010a2254;
struct NiRefObject
{
    virtual ~NiRefObject();
};
struct NiObject : public NiRefObject
{
    virtual ~NiObject();
};
extern void __cdecl operator delete(void*, size_t);
struct NiLODData_shell : public NiObject
{
    void* __thiscall FUN_00aa09f0(int flags);
};
// @fnv 0x00aa09f0
void* NiLODData_shell::FUN_00aa09f0(int flags)
{
    *reinterpret_cast<void**>(this) = &DAT_010a2254;
    NiRefObject::~NiRefObject();
    if (flags & 1)
        operator delete(this, 8);
    return this;
}
}  // namespace fnv_00aa09f0

// @fnv 0x00aa09d0
char __stdcall FUN_00aa09d0(char)
{
    return 1;
}
