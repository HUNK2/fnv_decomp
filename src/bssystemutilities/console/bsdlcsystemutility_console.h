// bssystemutilities/console/bsdlcsystemutility_console.h: declares DownloadableContentManager, BSSystemUtility
#ifndef FNV_ASTRA_DLC_H
#define FNV_ASTRA_DLC_H

#include <stddef.h>
class ContentMountRecord;
class DownloadableContentEntry;
class DownloadableContentInfo;
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
};
class DownloadableContentManager
{
  public:
    typedef void(__cdecl* MOUNT_CALLBACK)(unsigned int, unsigned int, bool, const ContentMountRecord*);
    unsigned int m_uiContentCount;
    DownloadableContentEntry* m_pFirstService;
    DownloadableContentInfo* m_pSecondService;
    BSSimpleList<ContentMountRecord*> m_kContentEntries;
    BSSimpleList<ContentMountRecord*> m_kMountedPackages;
    BSSimpleList<char*> m_kMountedPackageNames;
    static DownloadableContentManager& GetRandomGenerator();
    bool IsDLCAvailable();
    bool IsContentAvailable();
    void UnmountDLC();
    unsigned int MountDownloadableContent(unsigned int userIndex, MOUNT_CALLBACK callback);
};
class BSSystemUtility
{
  public:
    DownloadableContentManager& QDLCUtility();
};
typedef char check_DLC_size[sizeof(DownloadableContentManager) == 0x24 ? 1 : -1];
typedef char check_DLC_valid[offsetof(DownloadableContentManager, m_kContentEntries) == 0x0c ? 1 : -1];
#endif
