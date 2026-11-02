// Source layout: TopicInfoArray. PC corrections are in generate_headers.py.
#ifndef FNV_TOPICINFOARRAY_H
#define FNV_TOPICINFOARRAY_H
#include "layout_support.h"
#pragma pack(push, 4)
class TopicInfoArray : public NiTLargePrimitiveArray<TESTopicInfo*>
{
  public:
    TopicInfoArray();
    ~TopicInfoArray();
    void InsertInfoAt(unsigned int index, TESTopicInfo* info);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TopicInfoArray) == 0x18);
#endif
