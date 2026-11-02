// Source layout: _WIN32_FIND_DATAA. PC corrections are in generate_headers.py.
#ifndef FNV_UNIT_TESFORM__WIN32_FIND_DATAA_H
#define FNV_UNIT_TESFORM__WIN32_FIND_DATAA_H
#include "tesform_layout_support.h"
#include "tesform__FILETIME.h"
class _WIN32_FIND_DATAA
{
  public:
    unsigned long dwFileAttributes;  // +0x0
    _FILETIME ftCreationTime;        // +0x4
    _FILETIME ftLastAccessTime;      // +0xC
    _FILETIME ftLastWriteTime;       // +0x14
    unsigned long nFileSizeHigh;     // +0x1C
    unsigned long nFileSizeLow;      // +0x20
    unsigned long dwReserved0;       // +0x24
    unsigned long dwReserved1;       // +0x28
    char cFileName[260];             // +0x2C
    char cAlternateFileName[14];     // +0x130
    unsigned char layoutPadding13E[2];
};
FNV_STATIC_ASSERT(sizeof(_WIN32_FIND_DATAA) == 0x140);
FNV_STATIC_ASSERT(offsetof(_WIN32_FIND_DATAA, dwFileAttributes) == 0x0);
FNV_STATIC_ASSERT(offsetof(_WIN32_FIND_DATAA, ftCreationTime) == 0x4);
FNV_STATIC_ASSERT(offsetof(_WIN32_FIND_DATAA, ftLastAccessTime) == 0xC);
FNV_STATIC_ASSERT(offsetof(_WIN32_FIND_DATAA, ftLastWriteTime) == 0x14);
FNV_STATIC_ASSERT(offsetof(_WIN32_FIND_DATAA, nFileSizeHigh) == 0x1C);
FNV_STATIC_ASSERT(offsetof(_WIN32_FIND_DATAA, nFileSizeLow) == 0x20);
FNV_STATIC_ASSERT(offsetof(_WIN32_FIND_DATAA, dwReserved0) == 0x24);
FNV_STATIC_ASSERT(offsetof(_WIN32_FIND_DATAA, dwReserved1) == 0x28);
FNV_STATIC_ASSERT(offsetof(_WIN32_FIND_DATAA, cFileName) == 0x2C);
FNV_STATIC_ASSERT(offsetof(_WIN32_FIND_DATAA, cAlternateFileName) == 0x130);
#endif
