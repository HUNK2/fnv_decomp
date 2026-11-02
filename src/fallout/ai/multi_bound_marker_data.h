// MSVC9 SP1 layout check: PASS
// CodeView tag codeview-tag-layout:sha256:4cf82a8b301b2bb9471a1215e86b4b548543256616268942fb3426523721e82e; PC corrections inherited from generate_headers.py.
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_MULTIBOUNDMARKERDATA_H
#define FNV_MULTIBOUNDMARKERDATA_H
#include "layout_support.h"
#include "NiPoint3.h"
class Point3Offset;
#pragma pack(push, 4)
class Point3Offset
{
  public:
    NiPoint3 m_kOffset;  // +0x0, 12 bytes
    NiPoint3* ProjectileLaunched(NiPoint3* pDest, NiPoint3* pSource);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Point3Offset) == 12);
FNV_STATIC_ASSERT(offsetof(Point3Offset, m_kOffset) == 0);
#endif
