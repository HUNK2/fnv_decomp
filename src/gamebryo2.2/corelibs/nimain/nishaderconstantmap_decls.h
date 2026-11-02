// gamebryo2.2/corelibs/nimain/nishaderconstantmap_decls.h: declares NiGlobalStringTable, NiFixedString, NiShaderConstantMap, ShaderConstantMapEntry
#ifndef NISHADERCONSTANTMAP_DECLS_H
#define NISHADERCONSTANTMAP_DECLS_H

class IMemoryHeap;
#include "MemoryManager.h"
extern MemoryManager g_memoryManager;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
    static void IncRefCount(char*& handle);
    static void DecRefCount(char*& handle);
    static char* GetRealBufferStart(char*& handle)
    {
        return (char*)((unsigned int*)handle - 2);
    }
};
class NiFixedString;
extern NiFixedString EmptyFS;
class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString()
    {
        m_kHandle = EmptyFS.m_kHandle;
    }
    NiFixedString(const char* text)
    {
        if (text == 0)
            m_kHandle = EmptyFS.m_kHandle;
        else
            m_kHandle = NiGlobalStringTable::AddString(text);
    }
    ~NiFixedString()
    {
        NiGlobalStringTable::DecRefCount(m_kHandle);
    }
    NiFixedString& operator=(const NiFixedString& text)
    {
        char* handle = text.m_kHandle;
        if (m_kHandle != handle)
        {
            NiGlobalStringTable::IncRefCount(handle);
            NiGlobalStringTable::DecRefCount(m_kHandle);
            m_kHandle = handle;
        }
        return *this;
    }
    NiFixedString& operator=(const char* text)
    {
        if (m_kHandle != text)
        {
            char* old = m_kHandle;
            m_kHandle = NiGlobalStringTable::AddString(text);
            NiGlobalStringTable::DecRefCount(old);
        }
        return *this;
    }
    operator const char*() const
    {
        return m_kHandle;
    }
};
inline unsigned int NiAtomicIncrement(unsigned int& value)
{
    return InterlockedIncrement((long*)&value);
}
inline unsigned int NiAtomicSubtract(unsigned int& value)
{
    return InterlockedDecrement((long*)&value);
}
inline void NiGlobalStringTable::IncRefCount(char*& handle)
{
    if (handle != EmptyFS.m_kHandle)
    {
        char* buffer = GetRealBufferStart(handle);
        unsigned int* count = (unsigned int*)buffer;
        NiAtomicIncrement(*count);
    }
}
inline void NiGlobalStringTable::DecRefCount(char*& handle)
{
    if (handle != EmptyFS.m_kHandle)
    {
        char* buffer = GetRealBufferStart(handle);
        unsigned int* count = (unsigned int*)buffer;
        NiAtomicSubtract(*count);
    }
}
class NiShaderConstantMap
{
  public:
    class ShaderConstantMapEntry
    {
      public:
        unsigned int m_uiConstantID;
        NiFixedString m_kConstantName;
        ShaderConstantMapEntry()
        {
            m_uiConstantID = 0;
            m_kConstantName = (const char*)0;
        }
        ShaderConstantMapEntry(unsigned int id, const NiFixedString& name)
        {
            m_uiConstantID = id;
            m_kConstantName = name;
        }
        ~ShaderConstantMapEntry()
        {}
        ShaderConstantMapEntry& operator=(const ShaderConstantMapEntry& other)
        {
            m_uiConstantID = other.m_uiConstantID;
            m_kConstantName = other.m_kConstantName;
            return *this;
        }
        static void* operator new[](unsigned int size) throw()
        {
            return g_memoryManager.Allocate(size);
        }
    };
    static void InitializePoint3();
    static bool ParseConstantName(const char*, char*, unsigned int, unsigned int&);
    static bool FindConstantMapping(const char*, unsigned int&, unsigned int&);
    static ShaderConstantMapEntry* ms_pkShaderConstantMap;
    static unsigned int ms_uiShaderConstantMapEntryCount;
    static ShaderConstantMapEntry* ms_pkConstantMap;
    static unsigned int ms_uiConstantMapEntryCount;
};
extern "C" int strcpy_s(char*, unsigned int, const char*);
// The mutable-source C++ overload is distinct from the CRT entry point.
int strcpy_s(char*, unsigned int, char*);
extern "C" char* strchr(char*, int);
extern "C" int isdigit(int);
extern "C" char* strtok_s(char*, const char*, char**);
long FUN_00eca6d3(const char*);
int NiStricmp(const char*, const char*);

#endif
