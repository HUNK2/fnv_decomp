// gamebryo2.2/corelibs/nisystem/nifile.cpp: NiFile (2 functions)

#include "nifile_packet.h"
// @fnv 0x00aa1a20
NiFile* NiFile::GetFile(const char* name, OpenMode mode, unsigned int bufferSize)
{
    return DAT_011ac224(name, mode, bufferSize);
}
// The dispatch helper retains the original unoptimized request construction.
#pragma optimize("", off)
// Builds a NiFileAccessRequest with operation 1, the given name, buffer size and mode, submits it to CompleteJob and returns the result.
// @fnv 0x00aa85c0
unsigned int NiFile::RequestFileAccess(const char* name, unsigned int mode, unsigned int bufferSize)
{
    NiFileAccessRequest request;
    request.name = 0;
    request.operation = 0;
    request.reserved0 = 0;
    request.reserved1 = 0;
    request.operation = 1;
    request.name = name;
    request.bufferSize = bufferSize;
    request.mode = mode;
    CompleteJob(&request);
    return request.result;
}
