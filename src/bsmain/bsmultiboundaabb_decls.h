// bsmain/bsmultiboundaabb_decls.h: declares bhkLiquidAction, BSMultiBoundShape, BSMultiBoundAABB
#ifndef FNV_BSMULTIBOUNDAABB_DECLS_H
#define FNV_BSMULTIBOUNDAABB_DECLS_H

#include "NiObject.h"
#include "NiPoint3.h"
class bhkLiquidAction
{
  public:
    unsigned int GetInstanceSize();
};
class BSMultiBoundShape : public NiObject
{
  public:
    unsigned int m_uiShapeType;
};
class BSMultiBoundAABB : public BSMultiBoundShape
{
  public:
    NiPoint3 Center;
    NiPoint3 m_kOffset;
    void SetGridPosition(const NiPoint3& center);
};
#endif
