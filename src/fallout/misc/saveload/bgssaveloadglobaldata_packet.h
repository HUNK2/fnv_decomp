// fallout/misc/saveload/bgssaveloadglobaldata_packet.h: declares TES, ScreenSplatter, ScreenCustomSplatter, BSPortal, ImageSpaceModifierInstanceDOF and more
#ifndef BGSSAVELOADGLOBALDATA_PACKET_H
#define BGSSAVELOADGLOBALDATA_PACKET_H


class BGSLoadGameBuffer;
class ImageSpaceModifierInstance;
class NiAVObject;
class NiTexture;
class NiNode;
class BGSPerkEntry;
template <class T> class NiPointer
{
  public:
    T* pointer;
    NiPointer(T*);
    ~NiPointer();
    T* operator->() const;
};
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList* GetNext();
    void Remove(const NiPointer<NiAVObject>&);
};
class TES
{
  public:
    void LoadGame(BGSLoadGameBuffer*);
    void FUN_00459840(BGSLoadGameBuffer*);
    void ProcessItems(BGSLoadGameBuffer*);
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* FUN_0043b5d0();
};
extern TES* g_TES;
class ScreenSplatter
{
  public:
    static void Clear();
};
class ScreenCustomSplatter
{
  public:
    static void Clear();
};
class BSPortal
{
  public:
    ~BSPortal();
};
BSPortal* FUN_0045a190();
class ImageSpaceModifierInstanceDOF
{
  public:
    void FUN_0063f790(float);
};
class ImageSpaceModifierInstance
{
  public:
    bool IsFlagSet();
};
class CombatManager
{
  public:
    void LoadGame(BGSLoadGameBuffer*);
    void FUN_00993800(BGSLoadGameBuffer*);
    void ApplyLoadBuffer(BGSLoadGameBuffer*);
};
class Interface
{
  public:
    static void ApplyLoadBuffer(BGSLoadGameBuffer*);
    static void Revert(BGSLoadGameBuffer*);
    static void LoadGame(BGSLoadGameBuffer*);
    static void PrintDebugMessage(BGSLoadGameBuffer*);
};

class BGSLoadGameBuffer
{
  public:
    virtual unsigned char GetVersion();
    int ReadElementCount();
    void ReadDataBlock(void*, unsigned int);
    unsigned int ReadFormIdentifier();
};
class TESForm
{
  public:
    virtual void vfn_0();
    static TESForm* GetFormByID(unsigned int);
};
class TESImageSpaceModifier : public TESForm
{
};
class NiAVObject
{
};
class ImageSpaceModifierInstanceForm
{
  public:
    static ImageSpaceModifierInstanceForm* Trigger(TESImageSpaceModifier*, float, NiAVObject*);
    void SetPad5(float);
};
extern float DAT_011c3c08;

class GlobalObject_0096d020
{
};
extern GlobalObject_0096d020 g_011e0e80;
void FUN_004d60c0(BGSLoadGameBuffer*);
void ResetRadioGlobals(BGSLoadGameBuffer*);
class MagicItem;
class MagicCaster
{
  public:
    virtual void SetSelectedMagicItem(MagicItem*);
};

void FUN_0084cd40(BGSLoadGameBuffer*);
void ReadSavedSettings(BGSLoadGameBuffer*);
void FUN_008368b0(BGSLoadGameBuffer*);
class Sky
{
  public:
    static Sky* GetInstance();
    void LoadGame(BGSLoadGameBuffer*);
};
class SoundPlaybackManager
{
  public:
    static void LoadGame(BGSLoadGameBuffer*);
};

#endif
