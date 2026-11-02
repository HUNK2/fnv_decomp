
// src/havok/common/scenedata/mesh/hkxvertexdescription.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxvertexdescription.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkxVertexDescription.h"

struct hkEntryE3DE
{
    int m_iOwnerObjectOffset;
    unsigned short m_kPointA;
    unsigned short m_kPointB;
    int m_uiFilterValue;

    bool operator==(const hkEntryE3DE& o) const
    {
        return m_kPointA == o.m_kPointA && m_kPointB == o.m_kPointB && m_iOwnerObjectOffset == o.m_iOwnerObjectOffset &&
               m_uiFilterValue == o.m_uiFilterValue;
    }
};

class hkListE3DE
{
  public:
    hkEntryE3DE* m_data;
    int m_iElementCount;

    bool Equals(const hkListE3DE& o) const;
};

// Compares two lists: returns false if their counts differ or any corresponding entry differs, otherwise true.
// @fnv 0x00e3dee0
bool hkListE3DE::Equals(const hkListE3DE& aOther) const
{
    if (m_iElementCount == aOther.m_iElementCount)
    {
        for (int iIndex = 0; iIndex < m_iElementCount; iIndex++)
        {
            if (!(m_data[iIndex] == aOther.m_data[iIndex]))
                return false;
        }
        return true;
    }
    return false;
}
