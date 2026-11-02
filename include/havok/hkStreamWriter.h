// include/havok/hkStreamWriter.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKSTREAMWRITER_H
#define FNV_HAVOK_HKSTREAMWRITER_H
#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkStreamWriter : public hkReferencedObject
{
  public:
    enum SeekWhence
    {
        STREAM_SET = 0,
        STREAM_CUR = 1,
        STREAM_END = 2
    };
};
#pragma pack(pop)
typedef char fnv_hk_size_hkStreamWriter[(sizeof(hkStreamWriter) == 0x8) ? 1 : -1];
#endif
