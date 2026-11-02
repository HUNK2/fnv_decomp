// Unit-private PC MobileObjectProcessArray layout. Names and signatures from the supplied
#ifndef FNV_PROCESSLISTS_PRIVATE_PROCESSARRAY_H
#define FNV_PROCESSLISTS_PRIVATE_PROCESSARRAY_H

#include "processlists_layout_support.h"

class MobileObject;

class MobileObjectProcessArray
{
  public:
    NiTPrimitiveArray<MobileObject*> m_kMobileObjectArray;
    unsigned int m_auiProcessHeadIndices[PROCESS_TYPE_PROCESS_TYPE_COUNT];
    unsigned int m_auiProcessTailIndices[PROCESS_TYPE_PROCESS_TYPE_COUNT];
    unsigned int m_auiNextUpdateIndices[PROCESS_TYPE_PROCESS_TYPE_COUNT];

    MobileObject* GetItem(unsigned int auiIndex) const;  // PC 00968670
    unsigned int GetHead(PROCESS_TYPE aeLevel) const;    // PC 005DE0F0
    unsigned int GetTail(PROCESS_TYPE aeLevel) const;    // PC 005BE5C0
    unsigned int GetSize() const;                        // PC 0055B980
    PROCESS_TYPE GetProcessLevelFromIndex(unsigned int auiIndex) const;
    unsigned int GetIndexFromObject(MobileObject* apObject, PROCESS_TYPE aeLevel) const;
};
FNV_STATIC_ASSERT(sizeof(PROCESS_TYPE) == 4);
FNV_STATIC_ASSERT(sizeof(MobileObjectProcessArray) == 0x40);
FNV_STATIC_ASSERT(offsetof(MobileObjectProcessArray, m_kMobileObjectArray) == 0);
FNV_STATIC_ASSERT(offsetof(MobileObjectProcessArray, m_auiProcessHeadIndices) == 0x10);
FNV_STATIC_ASSERT(offsetof(MobileObjectProcessArray, m_auiProcessTailIndices) == 0x20);
FNV_STATIC_ASSERT(offsetof(MobileObjectProcessArray, m_auiNextUpdateIndices) == 0x30);
#endif
