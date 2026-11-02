#ifndef IMAGESPACEMANAGER_ARRAY_H
#define IMAGESPACEMANAGER_ARRAY_H
#include "NiMemObject.h"
#include "layout_support.h"
// yUI CommonLib/Gamebryo/NiTArray.hpp. Boolean receiver evidence: the
// DepthOfFieldTextures::kTextureStates field and covered caller at b8bc20.
template <> class NiTArray<bool, NiTMallocInterface<bool> > : public NiMemObject
{
  public:
    virtual ~NiTArray();
    bool* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int GetSize();
    bool& GetAt(unsigned int);
    bool RemoveAtAndFill(unsigned int);
    void SetAt(unsigned int, const bool&);
};
FNV_STATIC_ASSERT((sizeof(NiTArray<bool, NiTMallocInterface<bool> >) == 16));
#endif
