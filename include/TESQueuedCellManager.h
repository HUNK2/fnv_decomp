#pragma once

class TESObjectCELL;

class TESQueuedCellManager
{
public:
    void FUN_00528540();
    void SubmitQueuedItems();
    void ExteriorCellLoader_QueueCellLoad(TESObjectCELL*);
    int CallVirtual17();
    void ProcessQueries();
    int ExteriorCellLoader_TryCancelTasks();
    void ExteriorCellLoader_WaitForTasks();
};
