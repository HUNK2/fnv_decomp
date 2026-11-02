
// src/bsshader/bsshaderutil_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00b6bee0: the skeleton of src/bsshader/bsshaderutil.cpp
// with declarations corrected to what the original code does (bsshaderutil_decls.h: virtual void vfn_48() = 0; -> virtual void vfn_48(void* a, void* b, int c) =; bsshaderutil_decls.h: virtual void Unk_2A() = 0; virtual void Un -> virtual void Unk_2A() = 0; virtual void Un). Move the function to its real unit once
// that unit declares it this way.

#include "bsshaderutil_decls_decl_bsshaderutil.h"
#pragma optimize("", off)
#pragma optimize("", on)
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
extern NiPointer<NiRefObject> g_spCurrentAccumulator;
void FUN_00b54b10(BSShaderAccumulator* accumulator);

extern __declspec(thread) int DAT_012722bc;
struct AccumulatorContext
{
    int unk00, unk04;
    NiRefObject* object;
    void FUN_004dc540(NiRefObject*);
};
extern AccumulatorContext* DAT_011f4748;
struct NiNodeHolder
{
    NiRefObject* value;
    NiNodeHolder(NiRefObject* p) : value(p)
    {
        if (value)
            value->IncRefCount();
    }
    ~NiNodeHolder();
};
void FUN_00b54ac0(NiRefObject*);
// @fnv 0x00b6bee0
void FUN_00b6bee0(void* first, void* second, BSShaderAccumulator* accumulator)
{
    if (DAT_011f4748 && first && second)
    {
        if (!DAT_012722bc)
        {
            NiNodeHolder guard(DAT_011f4748->object);
            DAT_011f4748->FUN_004dc540(accumulator->texture);
        }
        FUN_00b54ac0(accumulator->texture);
        accumulator->vfn_48(first, second, 0);
    }
}
