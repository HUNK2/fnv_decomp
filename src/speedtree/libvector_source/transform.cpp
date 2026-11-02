// speedtree/libvector_source/transform.cpp: Matrix4f (2 functions)

#include "transform_decls.h"

// @fnv 0x00b3ccb0
Matrix4f::Matrix4f()
{
    InitializeIdentity();
}

// Fills the 4x4 matrix with the identity values (1.0 on the diagonal, 0.0 elsewhere).
// @fnv 0x00b3ccd0
void Matrix4f::InitializeIdentity()
{
    m_fComponents[0][0] = 1.0f;
    m_fComponents[0][1] = 0.0f;
    m_fComponents[0][2] = 0.0f;
    m_fComponents[0][3] = 0.0f;
    m_fComponents[1][0] = 0.0f;
    m_fComponents[1][1] = 1.0f;
    m_fComponents[1][2] = 0.0f;
    m_fComponents[1][3] = 0.0f;
    m_fComponents[2][0] = 0.0f;
    m_fComponents[2][1] = 0.0f;
    m_fComponents[2][2] = 1.0f;
    m_fComponents[2][3] = 0.0f;
    m_fComponents[3][0] = 0.0f;
    m_fComponents[3][1] = 0.0f;
    m_fComponents[3][2] = 0.0f;
    m_fComponents[3][3] = 1.0f;
}
