// include/havok/hkxScene.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xB0.
#ifndef FNV_HAVOK_HKXSCENE_H
#define FNV_HAVOK_HKXSCENE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkxCamera;
class hkxLight;
class hkxMaterial;
class hkxMesh;
class hkxNode;
class hkxNodeSelectionSet;
class hkxSkinBinding;
class hkxTextureFile;
class hkxTextureInplace;
#pragma pack(push, 1)
class hkxScene : public hkReferencedObject
{
  public:
    hkStringPtr m_kSceneName;                        // +0x8
    hkStringPtr m_kSceneFileName;                    // +0xC
    hkReal m_fNumFrames;                             // +0x10
    hkxNode* m_pAabbRootNode;                        // +0x14
    hkArray<hkxNodeSelectionSet*> m_kSelectionSets;  // +0x18
    hkArray<hkxCamera*> m_kCameras;                  // +0x24
    hkArray<hkxLight*> m_ppLights;                   // +0x30
    hkArray<hkxMesh*> m_kMeshList;                   // +0x3C
    hkArray<hkxMaterial*> m_kMaterials;              // +0x48
    hkArray<hkxTextureInplace*> m_kInplaceTextures;  // +0x54
    hkArray<hkxTextureFile*> m_kExternalTextures;    // +0x60
    hkArray<hkxSkinBinding*> m_kSkinBindings;        // +0x6C
    char pad78[0x8];
    hkMatrix3 m_kAppliedTransform;  // +0x80
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxScene[(sizeof(hkxScene) == 0xB0) ? 1 : -1];
#endif
