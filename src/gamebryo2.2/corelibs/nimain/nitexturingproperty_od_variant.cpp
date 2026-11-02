
// src/gamebryo2.2/corelibs/nimain/nitexturingproperty_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nitexturingproperty.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "nitexturingproperty_decls.h"

class ObjectBase
{
  public:
    virtual unsigned int Destroy(unsigned int flags);
};

class ObjectArray_b9713
{
  public:
    ObjectBase** GetAt(unsigned int i);
    void SetAt(unsigned int i, ObjectBase*& v);
};

class Owner_b9713
{
  public:
    unsigned int m_u00, m_u04, m_u08, m_u0c, m_u10, m_u14, m_u18;
    ObjectArray_b9713 m_ppData;
    void FUN_00533f40(ObjectBase* v);
};

// @fnv 0x00533f40
void Owner_b9713::FUN_00533f40(ObjectBase* v)
{
    ObjectBase* old = *m_ppData.GetAt(0);
    if (v != old)
    {
        ObjectBase* a = old;
        ObjectBase* b8 = a;
        b8 ? b8->Destroy(1) : 0;
        m_ppData.SetAt(0, v);
    }
}
