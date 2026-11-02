// gamebryo2.2/corelibs/nianimation/nicontrollermanager.h: declares NiMemObject, NiRefObject, NiObject, NiUpdateData, NiTimeController and more
#ifndef FNV_ASTRA_CONTROLLER_MANAGER_H
#define FNV_ASTRA_CONTROLLER_MANAGER_H

#include <stddef.h>
#define FNV_JOIN_INNER(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_INNER(a, b)
#define FNV_STATIC_ASSERT(x) typedef char FNV_JOIN(fnv_assert_, __LINE__)[(x) ? 1 : -1]
// NiRefObject's first two virtual slots are the destructor and DeleteThis.
// Other unused virtual interfaces are deliberately not synthesized. No object
// of these polymorphic types is constructed here and no other slot is called.
class NiMemObject
{
  public:
    virtual ~NiMemObject();
};
class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;
    virtual ~NiRefObject();
    virtual void DeleteThis();
};
class NiObject : public NiRefObject
{
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
};
template <class T> class NiTNewInterface
{
};
template <class T> class NiTMallocInterface
{
};
template <class T, class Allocator> class NiTArray
{
  public:
    virtual ~NiTArray();
    T* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, const T&);
    unsigned int AddFirstEmpty(const T&);
};
template <class T> class NiTObjectArray : public NiTArray<T, NiTNewInterface<T> >
{
};
template <class T, class Allocator> class NiTSet
{
  public:
    T* m_pBase;
    unsigned int m_uiElementCount, m_uiAllocatedCapacity;
};
template <class T> class NiTPrimitiveSet : public NiTSet<T, NiTMallocInterface<T> >
{
};
template <class T> class NewInterfaceSet : public NiTSet<T, NiTNewInterface<T> >
{
};
template <class K, class V> class NiTMapItem;
template <class T> class NiTStringPointerMap
{
  public:
    virtual ~NiTStringPointerMap();
    unsigned int m_uiHashSize;
    NiTMapItem<const char*, T>** m_ppkHashTable;
    struct MapEntryCount
    {
        unsigned int m_uiCount;
    } m_kItemCount;
    // Unused string-map tail; its field identity is not recovered here.
    unsigned char layoutPadding10[4];
};
class NiUpdateData
{
  public:
    float fTime;
    bool m_bUpdateEnabled, m_bRender, m_bInterpolate;
    bool m_bTimeToDie, m_bVisible;
};
class NiObjectNET;
class NiControllerManager;
class NiTimeController : public NiObject
{
  public:
    enum CycleType
    {
        LOOP,
        REVERSE,
        CLAMP,
        MAX_CYCLE_TYPES
    };
    unsigned short m_uiObjectFlags;
    float m_fFrequency, m_fPhase, m_fLoKeyTime, m_fHiKeyTime;
    float m_fStartTime, m_fLastTime, m_fWeightAdjustedLastTime, m_fControllerTime;
    NiObjectNET* m_pkTarget;
    NiPointer<NiTimeController> m_spNextController;
    virtual void Update(NiUpdateData&);
};
class NiFixedString
{
  public:
    const char* m_pString;
};
class NiAVObject;
class NiStringPalette;
class NiTextKeyExtraData;
class BSAnimNote;
class NiControllerSequence : public NiObject
{
  public:
    class InterpArrayItem;
    class IDTag;
    enum AnimState
    {
        INACTIVE,
        ANIMATING,
        EASEIN,
        EASEOUT,
        TRANSSOURCE,
        TRANSDEST,
        MORPHSOURCE
    };
    NiFixedString m_kName;
    unsigned int m_uiNumControlledBlocks, m_uiNumIDTags;
    InterpArrayItem* m_pInterpArray;
    IDTag* m_pkIDTags;
    float m_fWeight;
    NiPointer<NiTextKeyExtraData> m_spTextKeyData;
    NiTimeController::CycleType m_eAnimationCycleType;
    float m_fFrequency, m_fFirstKeyTime, m_fLastKeyTime, m_fLastTime;
    float m_fWeightAdjustedLastTime, m_fScaledLastTime;
    NiControllerManager* m_pkOwnerManager;
    AnimState m_eAnimationState;
    float m_fSequenceOffset, m_fStartTime, m_fEndTime, m_fDestinationFrame;
    NiControllerSequence* m_pkTimeSyncSequence;
    NiFixedString m_kAccumulationRootName;
    NiAVObject* m_pkAccumulationRoot;
    NiPointer<NiStringPalette> m_spStringPalette;
    short m_sAnimNotesExtraDataIndex;
    NiPointer<BSAnimNote>* m_pkAnimNotes;
    unsigned short m_usNumAnimNotes;
    bool m_bHasAnimNotes;
    void Update(float, bool);
};
class NiAVObjectPalette;
class BSAnimNoteListener;
class NiControllerManager : public NiTimeController
{
  public:
    NiTObjectArray<NiPointer<NiControllerSequence> > m_kSequences;
    NiTPrimitiveSet<NiControllerSequence*> m_kPlayingSequences;
    NiTStringPointerMap<NiControllerSequence*> m_kObjectMap;
    BSAnimNoteListener* m_pAudioListener;
    bool m_bUseCumulativeAnimation;
    NewInterfaceSet<NiPointer<NiControllerSequence> > m_kSequenceSet;
    NiPointer<NiAVObjectPalette> m_spControllerManager;
    virtual void Update(NiUpdateData&);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
FNV_STATIC_ASSERT(sizeof(NiRefObject) == 8);
FNV_STATIC_ASSERT(sizeof(NiPointer<NiControllerSequence>) == 4);
FNV_STATIC_ASSERT(sizeof(NiTObjectArray<NiPointer<NiControllerSequence> >) == 16);
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveSet<NiControllerSequence*>) == 12);
FNV_STATIC_ASSERT(sizeof(NiTStringPointerMap<NiControllerSequence*>) == 20);
FNV_STATIC_ASSERT(sizeof(NiUpdateData) == 12);
FNV_STATIC_ASSERT(sizeof(NiTimeController) == 0x34);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_uiObjectFlags) == 8);
FNV_STATIC_ASSERT(sizeof(NiControllerSequence) == 0x74);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_eAnimationState) == 0x44);
FNV_STATIC_ASSERT(sizeof(NiControllerManager) == 0x7c);
FNV_STATIC_ASSERT(offsetof(NiControllerManager, m_kPlayingSequences) == 0x44);
FNV_STATIC_ASSERT(offsetof(NiControllerManager, m_kSequenceSet) == 0x6c);
FNV_STATIC_ASSERT(offsetof(NiControllerManager, m_spControllerManager) == 0x78);
#endif
