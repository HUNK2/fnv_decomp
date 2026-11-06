
#include "nitmap_decls.h"
template<>
// @fnv 0x00844a70
NiTMapItem<unsigned int, BGSReconstructCellSubBlocksMap*>*
NiTMap<unsigned int, BGSReconstructCellSubBlocksMap*>::NewItem() {
    return static_cast<NiTMapItem<unsigned int, BGSReconstructCellSubBlocksMap*>*>(m_kItemCount.Allocate());
}
// @fnv 0x00975cf0
// src: COMMUNITY 0x00975cf0
void BSTempEffect_RemoveAllDecals() {
    g_011d6a30.FUN_004ee920();
    DAT_011d6a20 = 0;
}
// @fnv 0x0048eff0
void ModelLoader::FUN_0048eff0(unsigned int key) {
    FUN_00445370(key, true);
}
