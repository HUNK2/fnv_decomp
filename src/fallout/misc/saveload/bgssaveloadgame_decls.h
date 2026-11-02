// fallout/misc/saveload/bgssaveloadgame_decls.h: declares FormChangeMask, Actor, TESDataHandlerSaveLoad, FormChangeRecord, BGSSaveLoadChangesMap and more
#ifndef BGSSAVELOADGAME_DECLS_H
#define BGSSAVELOADGAME_DECLS_H

// TESForm (all PC virtuals) comes from the canonical TESForm.h; TESDataHandler, TESObjectCELL and the NiTPointerMap
// template come from the canonical layout_support.h.
#include "layout_support.h"
#include "TESForm.h"
class BaseProcess;
class TESFile;
class BGSReconstructFormsInFileMap;
class TESObjectREFR;
class FormChangeMask
{
  public:
    unsigned int flags;
    unsigned int FUN_00559450();
};
class Actor
{
  public:
    BaseProcess* GetProcess();
    void UpdateActorMovementState(bool);
};
// TESDataHandler members the canonical (API-only) layout_support.h class does not declare yet; called through a cast
// of g_dataHandler (same address).
class TESDataHandlerSaveLoad
{
  public:
    bool FormIDExists(unsigned int);
    unsigned int GetNextID();
    TESFile* GetCompiledFileByIndex(int);
    unsigned char GetCompiledFileCount();
};
extern TESDataHandler* g_dataHandler;
class FormChangeRecord
{
  public:
    FormChangeMask flags;
    FormChangeMask savedFlags;
};
class BGSSaveLoadChangesMap
{
  public:
    bool ContainsChangeFlags(unsigned int, FormChangeMask);
    void AddFormChangeFlags(unsigned int, FormChangeMask);
    bool ClearChangeFlags(unsigned int, FormChangeMask);
    bool HasFormChanges(unsigned int);
    FormChangeRecord* FUN_009a4250(unsigned int);
};
// The canonical NiTPointerMap template has no RemoveAll; the <unsigned int, unsigned int> instance used here declares it.
template <> class NiTPointerMap<unsigned int, unsigned int>
{
  public:
    void RemoveAll();
};
class BGSReconstructFormsInAllFilesMap
{
  public:
    BGSReconstructFormsInAllFilesMap();
    virtual ~BGSReconstructFormsInAllFilesMap();
    unsigned int data[12];
    void BuildMap();
    void* GetFirstPos();
    void GetNext(void*&, TESFile*&, BGSReconstructFormsInFileMap*&);
    unsigned int FUN_00849c80();
    TESForm* FUN_00849ca0(unsigned int);
};
class BGSSaveLoadReferencesMap
{
  public:
    void LoadCellReferences(TESObjectCELL*, BGSReconstructFormsInAllFilesMap*);
};
class BGSSaveLoadGame
{
  public:
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    unsigned int unused[3];
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    unsigned char pad14[0x248 - 0x14];
    unsigned char m_ucSaveLoadState;
    unsigned char GetLoadState();
    bool ContainsReference(unsigned int);
    bool HasFormChangeFlags(TESForm*, FormChangeMask);
    bool GetAllowChanges();
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, FormChangeMask);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, FormChangeMask, bool);
    void HasFormChanges(TESForm*);
    void ClearFormChanges();
    bool FUN_0042ce10();
    void LoadForm(TESForm*);
    void FUN_00849c00(bool);
    void FormReconstructionMap(TESObjectCELL*);
    void DeleteForm(TESForm*);
};
#endif
