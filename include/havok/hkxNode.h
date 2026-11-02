// include/havok/hkxNode.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x48.
#ifndef FNV_HAVOK_HKXNODE_H
#define FNV_HAVOK_HKXNODE_H

#include "hkBase.h"
class hkReferencedObject;
class hkxNodeAnnotationData;
#pragma pack(push, 1)
class hkxNode
{
  public:
    char pad0[0x14];
    hkStringPtr m_name;                             // +0x14
    hkReferencedObject* m_object;                   // +0x18
    hkArray<hkMatrix4> m_kKeyFrames;                // +0x1C
    hkArray<hkxNode*> m_children;                   // +0x28
    hkArray<hkxNodeAnnotationData> m_kAnnotations;  // +0x34
    hkStringPtr m_kUserProperties;                  // +0x40
    hkBool m_bSelected;                             // +0x44
    char pad45[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxNode[(sizeof(hkxNode) == 0x48) ? 1 : -1];
#endif
