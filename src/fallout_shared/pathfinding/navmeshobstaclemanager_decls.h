
// Shared classes come from the canonical include/ headers: TESForm/TESObjectREFR/MobileObject/Actor (PC virtual
// slots), SETTING_VALUE. Explicit ../../../include/ paths (src/fallout_shared shadows layout_support.h, TESForm.h...).
// Unit-local templates (navmeshobstaclemanager_local_types.h) keep the API matched code calls out of line and the
// canonical headers lack (BSSimpleArray Add/Clear/Remove/Find, BSSimpleList Remove/IsInList/AddTail(const T&),
// NiTPointerMap::RemoveAll, NiTArray::GetAt, NiPointer copy ctor); the canonical ones are renamed away.
#include "navmeshobstaclemanager_local_types.h"
#define NiPointer FNV_NiPointer_Canonical
#define BSSimpleList FNV_BSSimpleList_Canonical
#define BSSimpleArray FNV_BSSimpleArray_Canonical
#define NiTPointerMap FNV_NiTPointerMap_Canonical
#define NiTArray FNV_NiTArray_Canonical
#include "../../../include/layout_support.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/Actor.h"
#undef NiTArray
#undef NiTPointerMap
#undef BSSimpleArray
#undef BSSimpleList
#undef NiPointer
#include "../../../include/SETTING_VALUE.h"
class TESObjectREFR;
class AnimIdle;
class ObstacleData;
class ObstacleTaskData;
class NavMeshInfo;
class RecursiveSpinLock
{
  public:
    void Lock(const char*);
    void Unlock();
};
class NavMeshObstacleManager
{
  public:
    void AddProcessedTask(ObstacleTaskData*);
    bool ClearBackgroundTasks();
    void QueueObstacleTasks();
    void ClearObstacles();
    void RemoveObstaclesForReference(unsigned int);
    bool ProcessObstacleTask(ObstacleTaskData*);
};
class SandboxProcedureData;
class TESObjectREFR;
template <class T> class NiTNewInterface;
class ObstacleTaskData
{
  public:
    virtual ~ObstacleTaskData();
    virtual void vfn_04();
    virtual void Run();
};
class TESFile;
class BGSReconstructFormsInFileMap;
class BGSReconstructFormsInAllFilesMap
{
  public:
    void* GetFirstPos();
    void GetNext(void*&, TESFile*&, BGSReconstructFormsInFileMap*&);
};
class INISettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
class GlobalObject_0045cf30
{
};
extern GlobalObject_0045cf30 g_011d71a0;
class BGSPerkEntry;
class ActorCause;
class BGSCameraShot;
class bhkRigidBody;
class ObstacleData;
class AnimIdle;
template <class K, class V> class NiTMapItem;
template <class T> class DFALL;
template <class A, class K, class V> class NiTMapBase
{
  public:
    bool GetAt(K, V&) const;
    bool RemoveAt(K);
    void SetAt(K, V);
};
