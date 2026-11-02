// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshobstaclemanager.h
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x006c3920  NavMeshObstacleManager::GetProcessedTaskCount   (66 bytes)
//   0x006c3970  NavMeshObstacleManager::GetBackgroundTaskCount  (66 bytes)
#ifndef FNV_NAVMESHOBSTACLEMANAGER_H
#define FNV_NAVMESHOBSTACLEMANAGER_H


#include "layout_support.h"

class ObstacleTaskData;

// Lock entry points stay out of line: the original counts call them.
class RecursiveSpinLock
{
  public:
    volatile unsigned int m_uiOwningThreadID;  // +0x0
    unsigned int m_uiRecursionCount;              // +0x4
    void Lock(const char* name);
    void Unlock();
};

class NavMeshObstacleManager
{
  public:
    // State ahead of the background task bookkeeping is not reconstructed yet.
    unsigned char layoutPadding0[0x13C];
    BSSimpleArray<ObstacleTaskData*, 1024> m_kProcessedTasks;   // +0x13C
    BSSimpleArray<ObstacleTaskData*, 1024> m_kBackgroundTasks;  // +0x14C
    FNV_ALIGN(32) RecursiveSpinLock m_kTaskLock;                       // +0x160
    unsigned int GetProcessedTaskCount();
    unsigned int GetBackgroundTaskCount();
};

const char kGetProcessedTaskCountLabel[] = "NavMeshObstacleManager::GetProcessedTaskCount()";
const char kGetBackgroundTaskCountLabel[] = "NavMeshObstacleManager::GetBackgroundTaskCount()";

// @fnv 0x006c3920
unsigned int NavMeshObstacleManager::GetProcessedTaskCount()
{
    m_kTaskLock.Lock(kGetProcessedTaskCountLabel);
    unsigned int ItemUpdateArray = m_kBackgroundTasks.GetSize();
    m_kTaskLock.Unlock();
    return ItemUpdateArray;
}

// @fnv 0x006c3970
unsigned int NavMeshObstacleManager::GetBackgroundTaskCount()
{
    m_kTaskLock.Lock(kGetBackgroundTaskCountLabel);
    unsigned int ItemUpdateArray = m_kProcessedTasks.GetSize();
    m_kTaskLock.Unlock();
    return ItemUpdateArray;
}

#endif
