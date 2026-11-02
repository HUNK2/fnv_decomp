// gamebryo2.2/corelibs/nisystem/console/nithread_console.cpp: free functions (1 function)

extern "C" __declspec(dllimport) void __stdcall RaiseException(unsigned long, unsigned long, unsigned long,
                                                               const unsigned long*);

struct THREADNAME_INFO
{
    unsigned long dwType;
    const char* szName;
    unsigned long dwThreadID;
    unsigned long dwFlags;
};

// @fnv 0x00aa2740
void __cdecl SetDebuggerThreadName(unsigned long dwThreadID, const char* szThreadName)
{
    THREADNAME_INFO info;
    info.dwType = 0x1000;
    info.szName = szThreadName;
    info.dwThreadID = dwThreadID;
    info.dwFlags = 0;
    __try
    {
        RaiseException(0x406D1388, 0, sizeof(info) / sizeof(unsigned long), (const unsigned long*)&info);
    }
    __except (-1)
    {}
}
