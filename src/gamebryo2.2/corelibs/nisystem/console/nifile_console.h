// gamebryo2.2/corelibs/nisystem/console/nifile_console.h: declares NiBinaryStream, NiFile
#ifndef FNV_ASTRA_NIFILE_H
#define FNV_ASTRA_NIFILE_H

#include <stddef.h>
struct _iobuf;
typedef _iobuf FILE;
class NiBinaryStream
{
  public:
    typedef unsigned int(__cdecl* READFUNC)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    typedef unsigned int(__cdecl* WRITEFUNC)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    virtual ~NiBinaryStream();
    unsigned int m_uiStreamFlags;
    READFUNC m_pfnRead;
    WRITEFUNC m_pfnWrite;
    unsigned int GetLine(char* buffer, unsigned int maxChars);
};
class NiFile : public NiBinaryStream
{
  public:
    enum OpenMode
    {
        READ_ONLY = 0,
        WRITE_ONLY = 1,
        APPEND_ONLY = 2
    };
    unsigned int m_uiBufferAllocSize;
    unsigned int m_uiBufferReadSize;
    unsigned int m_uiPos;
    unsigned int m_uiTotalFileSize;
    char* m_pBuffer;
    FILE* m_pFile;
    OpenMode m_eMode;
    bool m_bGood;
    virtual ~NiFile();

  protected:
    bool Flush();
    static unsigned int __cdecl WriteBytesToFile(const void*, unsigned int, unsigned int, FILE*);
};
extern "C" int __cdecl fclose(FILE*);
void __cdecl NiFree(void*);
typedef char check_NiBinaryStream_size[sizeof(NiBinaryStream) == 0x10 ? 1 : -1];
typedef char check_NiFile_size[sizeof(NiFile) == 0x30 ? 1 : -1];
typedef char check_NiFile_buffer[offsetof(NiFile, m_pBuffer) == 0x20 ? 1 : -1];
typedef char check_NiFile_file[offsetof(NiFile, m_pFile) == 0x24 ? 1 : -1];
typedef char check_NiFile_mode[offsetof(NiFile, m_eMode) == 0x28 ? 1 : -1];
typedef char check_NiFile_good[offsetof(NiFile, m_bGood) == 0x2c ? 1 : -1];
#endif
