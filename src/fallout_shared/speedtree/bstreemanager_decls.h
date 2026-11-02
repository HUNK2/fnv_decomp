// fallout_shared/speedtree/bstreemanager_decls.h: declares AutoMemContext, MemoryManager
#ifndef BSTREEMANAGER_DECLS_H
#define BSTREEMANAGER_DECLS_H

#include "layout_support.h"
#include <new>
class NiAVObject;
class NiNode;
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    operator NiAVObject*() const;
};
template <> class NiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    NiPointer<NiNode>& operator=(NiNode* object);
};
#include "bstreemanager_types_BSTreeManager.h"
#include "bstreemanager_types_TES.h"
extern BSTreeManager* DAT_011d5c48;
extern TES* g_TES;
class AutoMemContext
{
  public:
    MEM_CONTEXT m_eMemoryContext;
    AutoMemContext(MEM_CONTEXT context, bool track, const char* file, int line);
    ~AutoMemContext();
};
class MemoryManager
{
  public:
    static void* Allocate(unsigned int size);
};
void FUN_00664940();
void* FUN_00664840(bool);
void SetGlobalValue(bool);
void SetGlobalFloatFromUInt(unsigned int);
void ClampAndStoreValue(float);
extern float DAT_011fd890;
extern float DAT_011adce0;
#endif
