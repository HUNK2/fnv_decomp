// bssystem/console/bssystemdir_console_decls.h: declares DirectoryFindData, DirectoryIterator
#ifndef BSSYSTEMDIR_CONSOLE_DECLS_H
#define BSSYSTEMDIR_CONSOLE_DECLS_H

enum BSSystemFile__ErrorCode
{
    EC_NONE = 0,
    EC_FAILED = 4
};
struct DirectoryFindData
{
    char data[320];
};
extern void*(__stdcall* DAT_00fdf070)(const char*, DirectoryFindData*);
extern int(__stdcall* DAT_00fdf068)(void*, DirectoryFindData*);
class DirectoryIterator
{
  public:
    void* m_pFindHandle;
    DirectoryFindData m_kFindData;
    char m_acSearchPath[260];
    BSSystemFile__ErrorCode m_eErrorCode;
    BSSystemFile__ErrorCode NextEntry(bool& finished);
};
#endif
