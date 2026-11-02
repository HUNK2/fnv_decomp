
#include "iomanager_decls.h"
// @fnv 0x0043d690
void IOManager::SubmitTask()
{
    DAT_01202d98->FUN_0043d6b0(this);
}
// @fnv 0x0043db70
void IOTask::GenerateKey()
{
    SetKey(3, InitScriptRunLockTask(), GetPriority(), FUN_0043dc10());
}
