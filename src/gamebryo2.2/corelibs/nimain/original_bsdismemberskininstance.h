// gamebryo2.2/corelibs/nimain/original_bsdismemberskininstance.h: declares NiRTTI, NiSkinInstance, BSDismemberSkinInstance
#ifndef FNV_ORIGINAL_BSDISMEMBERSKININSTANCE_H
#define FNV_ORIGINAL_BSDISMEMBERSKININSTANCE_H


// Authored declarations for the BSDismemberSkinInstance unit
// (gamebryo2.2/corelibs/nimain/bsdismemberskininstance.h). The canonical
// generated headers do not yet carry the NiRTTI layout or the NiSkinInstance
// declaration, so this header keeps the translation unit self-contained.
// Canonical additions requested from the operator:
//   - NiRTTI.h: the real NiRTTI declaration (name/base members and
//     constructor) and the NiSkinInstance/BSDismemberSkinInstance layouts.
// (BSDismemberSkinInstance derives from NiSkinInstance, exposes ms_kRTTI and
// the virtual GetRTTI override).

class NiRTTI
{
  public:
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

class NiSkinInstance
{
  public:
    virtual ~NiSkinInstance();
    virtual const NiRTTI* GetRTTI() const;
    static const NiRTTI ms_kRTTI;
};

class BSDismemberSkinInstance : public NiSkinInstance
{
  public:
    static const NiRTTI ms_kRTTI;
    virtual const NiRTTI* GetRTTI() const;
};

#endif
