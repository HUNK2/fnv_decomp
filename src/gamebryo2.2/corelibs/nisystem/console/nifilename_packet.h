// gamebryo2.2/corelibs/nisystem/console/nifilename_packet.h: declares FileNameComponents
#ifndef NIFILENAME_PACKET_H
#define NIFILENAME_PACKET_H

extern "C" int __cdecl _splitpath_s(const char*, char*, unsigned int, char*, unsigned int, char*, unsigned int, char*,
                                    unsigned int);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" int __cdecl strcat_s(char*, unsigned int, const char*);
extern const char DAT_010a47b0[];  // "\\*" search suffix
class FileNameComponents
{
  public:
    char m_acFolderPath[256];
    char m_acDriveLetter[3];
    char m_acExtension[256];
    char m_acBaseName[256];
    char m_acDirectoryComponent[256];
    FileNameComponents(const char*);
    int SetFullPath(const char*);
};
#endif
