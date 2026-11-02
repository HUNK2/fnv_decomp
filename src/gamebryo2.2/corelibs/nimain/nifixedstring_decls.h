// gamebryo2.2/corelibs/nimain/nifixedstring_decls.h: declares NiFixedString, NiGlobalStringTable
#ifndef FNV_NIFIXEDSTRING_DECLS_H
#define FNV_NIFIXEDSTRING_DECLS_H
class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString& operator=(const char* pcString);
};
class NiGlobalStringTable
{
  public:
    static char* AddString(const char* pcString);
};
extern NiFixedString EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
#endif
