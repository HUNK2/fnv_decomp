// gamebryo2.2/corelibs/nisystem/console/nifilename.cpp: FileNameComponents (2 functions)

#include "nifilename_packet.h"
// Initialises the object and splits path into drive, directory, filename and extension buffers via _splitpath_s.
// @fnv 0x00aa27d0
FileNameComponents::FileNameComponents(const char* path)
{
    m_acDirectoryComponent[0] = 0;
    _splitpath_s(path, m_acDriveLetter, 3, m_acFolderPath, 256, m_acBaseName, 256, m_acExtension, 256);
}

#pragma optimize("", off)
// Copies path into the buffer at offset 0x144, appends DAT_010a47b0, zeroes the fields at offsets 0 and 0x248, and returns the latter.
// @fnv 0x00b006b0
int FileNameComponents::SetFullPath(const char* path)
{
    if (!path)
        return 2;
    strcpy_s(reinterpret_cast<char*>(this) + 0x144, 260, path);
    strcat_s(reinterpret_cast<char*>(this) + 0x144, 260, DAT_010a47b0);
    *reinterpret_cast<unsigned int*>(this) = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x248) = 0;
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x248);
}
