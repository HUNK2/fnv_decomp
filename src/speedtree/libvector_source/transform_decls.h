// speedtree/libvector_source/transform_decls.h: declares Matrix4f
#ifndef FNV_TRANSFORM_DECLS_H
#define FNV_TRANSFORM_DECLS_H

class Matrix4f
{
  public:
    Matrix4f();
    void InitializeIdentity();
    float m_fComponents[4][4];
};
#endif
