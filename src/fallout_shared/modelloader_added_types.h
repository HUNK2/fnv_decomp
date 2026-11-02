// fallout_shared/modelloader_added_types.h: declares BSXFlags, DFALL_NiTMapItem_unsigned_int_Actor_____, NiTMap_unsigned_int_Actor___, BGSSaveLoadGame
#ifndef FNV_MODELLOADER_ADDED_TYPES_H
#define FNV_MODELLOADER_ADDED_TYPES_H

#include <stddef.h>

// API-only declaration: no object construction, storage, casts or virtual calls.
// Public address/name evidence identifies both const members.
class BSXFlags
{
  public:
    unsigned int GetFlags(unsigned int flags) const;
    bool GetAddon() const;
};

// No container constructors, destructors or operations are defined or called.
class BGSSaveLoadChangesMap;
class FormIDConverter;
class BGSSaveLoadReferencesMap;
class LoadGameSubBufferQueue;
class SaveLoadChangeHistory;
class BGSReconstructFormsInAllFilesMap;
class BGSLoadFormBuffer;
class Actor;
class NiTMap_unsigned_int_unsigned_int_;

template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
};

template <class K, class V> class NiTMapItem
{
  public:
    NiTMapItem<K, V>* m_pkNext;
    K m_key;
    V m_val;
};

class DFALL_NiTMapItem_unsigned_int_Actor_____
{
};
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor_____AntiBloatAllocator
    : public DFALL_NiTMapItem_unsigned_int_Actor_____
{
  public:
    unsigned int m_uiCount;
};
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor___
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    NiTMapItem<unsigned int, Actor*>** m_ppkHashTable;
    NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor_____AntiBloatAllocator m_kItemCount;
};
class NiTMap_unsigned_int_Actor___ : public NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor___
{
};

class BGSSaveLoadGame
{
  public:
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    NiTMap_unsigned_int_unsigned_int_* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    BSSimpleArray<BGSLoadFormBuffer*, 1024> LoadFormBufferArray;
    NiTMap_unsigned_int_Actor___ m_acTextBuffer;
    unsigned char m_acFirstTextBuffer[255];
    unsigned char m_acSecondTextBuffer[255];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    bool GetInitingForms() const;
};
typedef char modelloader_check_map_size[(sizeof(NiTMap_unsigned_int_Actor___) == 16) ? 1 : -1];
typedef char modelloader_check_flags_offset[(offsetof(BGSSaveLoadGame, m_uiInitializationFlags) == 0x244) ? 1 : -1];
typedef char modelloader_check_saveload_size[(sizeof(BGSSaveLoadGame) == 0x24C) ? 1 : -1];
// Full supplied real-field/dependency assertions retained. Natural alignment replaces synthetic padding arrays.
typedef BSSimpleArray<BGSLoadFormBuffer*, 1024> ModelLoaderFormBufferArray;
typedef char modelloader_assert_00[(sizeof(DFALL_NiTMapItem_unsigned_int_Actor_____) == 1) ? 1 : -1];
typedef char modelloader_assert_01
    [(sizeof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor_____AntiBloatAllocator) == 4) ? 1
                                                                                                                  : -1];
typedef char modelloader_assert_02
    [(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor_____AntiBloatAllocator,
               m_uiCount) == 0)
         ? 1
         : -1];
typedef char modelloader_assert_03
    [(sizeof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor___) == 16) ? 1 : -1];
typedef char modelloader_assert_04
    [(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor___, m_ppVirtualMethodTable) == 0) ? 1 : -1];
typedef char modelloader_assert_05
    [(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor___, m_uiHashSize) == 4) ? 1 : -1];
typedef char modelloader_assert_06[(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor___,
                                             m_ppkHashTable) == 8)
                                       ? 1
                                       : -1];
typedef char modelloader_assert_07[(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor___,
                                             m_kItemCount) == 12)
                                       ? 1
                                       : -1];
typedef char modelloader_assert_08[(sizeof(NiTMap_unsigned_int_Actor___) == 16) ? 1 : -1];
typedef char modelloader_assert_09[(sizeof(BGSSaveLoadGame) == 588) ? 1 : -1];
typedef char modelloader_assert_10[(offsetof(BGSSaveLoadGame, m_pFormChangesMap) == 0) ? 1 : -1];
typedef char modelloader_assert_11[(offsetof(BGSSaveLoadGame, m_pSecondChangesMap) == 4) ? 1 : -1];
typedef char modelloader_assert_12[(offsetof(BGSSaveLoadGame, m_pSecondSaveLoadData) == 8) ? 1 : -1];
typedef char modelloader_assert_13[(offsetof(BGSSaveLoadGame, m_pSaveLoadData) == 12) ? 1 : -1];
typedef char modelloader_assert_14[(offsetof(BGSSaveLoadGame, m_pReferencesMap) == 16) ? 1 : -1];
typedef char modelloader_assert_15[(offsetof(BGSSaveLoadGame, m_pSaveLoadMap) == 20) ? 1 : -1];
typedef char modelloader_assert_16[(offsetof(BGSSaveLoadGame, m_pAuxiliaryData) == 24) ? 1 : -1];
typedef char modelloader_assert_17[(offsetof(BGSSaveLoadGame, m_pNoteHandler) == 28) ? 1 : -1];
typedef char modelloader_assert_18[(offsetof(BGSSaveLoadGame, m_pFormReconstructionMap) == 32) ? 1 : -1];
typedef char modelloader_assert_19[(offsetof(BGSSaveLoadGame, LoadFormBufferArray) == 36) ? 1 : -1];
typedef char modelloader_assert_20[(offsetof(BGSSaveLoadGame, m_acTextBuffer) == 52) ? 1 : -1];
typedef char modelloader_assert_21[(offsetof(BGSSaveLoadGame, m_acFirstTextBuffer) == 68) ? 1 : -1];
typedef char modelloader_assert_22[(offsetof(BGSSaveLoadGame, m_acSecondTextBuffer) == 323) ? 1 : -1];
typedef char modelloader_assert_23[(offsetof(BGSSaveLoadGame, m_uiInitializationFlags) == 580) ? 1 : -1];
typedef char modelloader_assert_24[(offsetof(BGSSaveLoadGame, m_ucSaveLoadState) == 584) ? 1 : -1];
typedef char modelloader_assert_25[(sizeof(ModelLoaderFormBufferArray) == 16) ? 1 : -1];
typedef char modelloader_assert_26[(offsetof(ModelLoaderFormBufferArray, m_ppVirtualMethodTable) == 0) ? 1 : -1];
typedef char modelloader_assert_27[(offsetof(ModelLoaderFormBufferArray, pBuffer) == 4) ? 1 : -1];
typedef char modelloader_assert_28[(offsetof(ModelLoaderFormBufferArray, iSize) == 8) ? 1 : -1];
typedef char modelloader_assert_29[(offsetof(ModelLoaderFormBufferArray, SimpleArrayStorage) == 12) ? 1 : -1];

#endif
