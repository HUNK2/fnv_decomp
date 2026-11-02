// fallout_shared/imagespacemodifierinstance_calls.h: declares NiMemObjectAllocation, TESSound, BSAudio, TES
#ifndef FNV_IMAGESPACEMODIFIERINSTANCE_CALLS_H
#define FNV_IMAGESPACEMODIFIERINSTANCE_CALLS_H

#include "NiObject.h"
#include "TESForm.h"
class ImageSpaceModifierInstance;
class NiMemObjectAllocation
{
  public:
    static void* operator new(unsigned int size);
    static void operator delete(void* pointer, unsigned int size);
};
template <> class NiPointer<ImageSpaceModifierInstance>
{
  public:
    ImageSpaceModifierInstance* m_pObject;
    NiPointer(ImageSpaceModifierInstance* object);
    ~NiPointer();
    operator ImageSpaceModifierInstance*() const;
};
template <> class BSSimpleList<NiPointer<ImageSpaceModifierInstance> >
{
  public:
    NiPointer<ImageSpaceModifierInstance> m_item;
    BSSimpleList* m_pkNext;
    NiPointer<ImageSpaceModifierInstance>& GetItem();
    BSSimpleList* GetNext();
    void Remove(const NiPointer<ImageSpaceModifierInstance>&);
    void AddTail(const NiPointer<ImageSpaceModifierInstance>& item);
};
class TESSound : public TESForm
{
};
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char padding[3];
    unsigned int eState;
    ~SoundPlaybackHandle();
    bool Play();
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    SoundPlaybackHandle GetSoundHandleByFormID(unsigned int formID, unsigned int flags, bool assumeSuccess);
};
class TES
{
  public:
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* FUN_0043b5d0();
};
extern TES* g_TES;
extern float DAT_0102d270;
extern float DAT_011c96fc;
#endif
