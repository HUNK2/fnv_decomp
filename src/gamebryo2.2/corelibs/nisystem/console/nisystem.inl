#include "nisystem_decls.h"

// @fnv 0x00a305b0
int __cdecl NiSprintf(char* buffer, unsigned int size, const char* format, ...)
{
    if (!size)
        return 1;
    char* args = (char*)(&format + 1);
    int result = vsprintf_s(buffer, size, format, args);
    buffer[size - 1] = 0;
    return result;
}
