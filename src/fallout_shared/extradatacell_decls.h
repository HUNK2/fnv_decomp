// fallout_shared/extradatacell_decls.h: declares BSExtraData, ExtraNorthRotation
#ifndef EXTRADATACELL_DECLS_H
#define EXTRADATACELL_DECLS_H

class BSExtraData
{
  public:
    BSExtraData(unsigned char type);
    void** m_ppVirtualMethodTable;
    unsigned char m_ucExtraDataType;
    unsigned char padding[3];
    BSExtraData* pNext;
};
extern void* ExtraNorthRotation_vtable[];
class ExtraNorthRotation : public BSExtraData
{
  public:
    ExtraNorthRotation();
    float m_fNorthRotation;
};
#endif
