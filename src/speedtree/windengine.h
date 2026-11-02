// speedtree/windengine.h: declares WindEngine
#ifndef FNV_WINDENGINE_H
#define FNV_WINDENGINE_H


#include "windengine_decls.h"

class WindEngine
{
  public:
    unsigned short m_usMatrixCount;
    Matrix4f* m_pMatrices;

    void Resize(unsigned short numMatrices);
};

FNV_STATIC_ASSERT(sizeof(WindEngine) == 8);
FNV_STATIC_ASSERT(offsetof(WindEngine, m_pMatrices) == 4);

// @fnv 0x00b07f20
void WindEngine::Resize(unsigned short numMatrices)
{
    if (m_usMatrixCount != numMatrices)
    {
        delete[] m_pMatrices;
        m_usMatrixCount = numMatrices;
        m_pMatrices = new Matrix4f[numMatrices];
    }

    for (int i = 0; i < numMatrices; ++i)
        m_pMatrices[i].InitializeIdentity();
}

#endif
