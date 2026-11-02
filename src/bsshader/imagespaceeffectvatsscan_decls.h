// bsshader/imagespaceeffectvatsscan_decls.h: declares NonActorMagicCaster
#ifndef FNV_IMAGESPACEEFFECTVATSSCAN_DECLS_H
#define FNV_IMAGESPACEEFFECTVATSSCAN_DECLS_H


#include "MemoryManager.h"
extern MemoryManager g_memoryManager;
class ImageSpaceTexture;
class ImageSpaceEffectParam;
template <> class NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> >
{
  public:
    virtual ~NiTArray();
    ImageSpaceTexture** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, ImageSpaceTexture* const& value);
};
template <> class NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> >
{
  public:
    virtual ~NiTArray();
    ImageSpaceEffectParam** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetAt(unsigned int index, ImageSpaceEffectParam* const& value);
};

#include "imagespaceeffectvatsscan_types_ImageSpaceTexture.h"
#include "imagespaceeffectvatsscan_types_BSShaderManager.h"
#include "imagespaceeffectvatsscan_types_ImageSpaceEffectVATSScan.h"
#include "imagespaceeffectvatsscan_types_ImageSpaceShaderParam.h"

extern float DAT_011ae614;
extern float DAT_011ae618;
extern float DAT_01201f2c;
extern float DAT_01201f30;
extern float DAT_01201f34;
extern float DAT_01201f38;
extern float DAT_01201f3c;
extern NiPointer<NiTexture> DAT_01201f40;
extern NiPointer<NiTexture> DAT_01201f48;
extern void* DAT_010ba350;

class NonActorMagicCaster
{
  public:
    void SetSelectedMagicItem(MagicItem* spell);
};

#endif
