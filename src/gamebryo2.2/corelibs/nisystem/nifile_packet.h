// gamebryo2.2/corelibs/nisystem/nifile_packet.h: declares NiFile, NiFileAccessRequest
#ifndef NIFILE_PACKET_H
#define NIFILE_PACKET_H

class NiFile
{
  public:
    enum OpenMode
    {
        READ_ONLY,
        WRITE_ONLY,
        APPEND_ONLY
    };
    static NiFile* GetFile(const char*, OpenMode, unsigned int);
    static unsigned int RequestFileAccess(const char*, unsigned int, unsigned int);
};
extern NiFile*(__cdecl* DAT_011ac224)(const char*, NiFile::OpenMode, unsigned int);
struct NiFileAccessRequest
{
    const char* name;
    unsigned int operation;
    unsigned int bufferSize;
    unsigned int reserved0;
    unsigned int mode;
    unsigned int reserved1;
    unsigned int result;
};
void __cdecl CompleteJob(NiFileAccessRequest*);
#endif
