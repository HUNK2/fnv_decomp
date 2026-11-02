// fallout/misc/saveload/bgsloadformbuffer.cpp: BGSLoadFormBuffer (16 functions)

#include "bgsloadformbuffer_decls.h"

// @fnv 0x008a81c0
unsigned char BGSLoadFormBuffer::GetVersion()
{
    return Header.cVersion;
}

// Initializes the load form buffer by zeroing iFormID, iSize, pForm and iFlags.
// @fnv 0x008643b0
BGSLoadFormBuffer::BGSLoadFormBuffer() : iFormID(0), iSize(0), pForm(0), iFlags(0)
{}

// @fnv 0x00864610
TESObjectREFR* BGSLoadFormBuffer::GetReference()
{
    TESForm* form = GetForm();
    if (form && form->GetIsReference())
        return reinterpret_cast<TESObjectREFR*>(form);
    return 0;
}

// @fnv 0x00864660
Actor* BGSLoadFormBuffer::GetActor()
{
    TESForm* form = reinterpret_cast<TESForm*>(GetReference());
    if (form && form->IsActor())
        return reinterpret_cast<Actor*>(form);
    return 0;
}

// @fnv 0x008645b0
TESForm* BGSLoadFormBuffer::GetForm()
{
    if (!pForm && IsFlag2Set())
        pForm = GetFormByID(iFormID);
    return pForm;
}

// @fnv 0x00864580
void BGSLoadFormBuffer::SkipData(SaveLoadFile* file, unsigned int size)
{
    unsigned int remaining;
    if (remaining = iSize - size)
        file->AdvancePosition(iSize - size);
}

struct Dummy84eaf0
{
    void ClearNumericIDIndex();
};

struct Dummy864490
{
    void FUN_00864490();
};

// @fnv 0x00864450
FormLoadContext* __fastcall FUN_00864450(FormLoadContext* apObject)
{
    reinterpret_cast<Dummy84eaf0*>(apObject)->ClearNumericIDIndex();
    reinterpret_cast<FormChangeMask*>(reinterpret_cast<char*>(apObject) + 3)->FormChangeMask::FormChangeMask();
    reinterpret_cast<Dummy864490*>(reinterpret_cast<char*>(apObject) + 7)->FUN_00864490();
    *(reinterpret_cast<unsigned char*>(apObject) + 8) = 0;
    return apObject;
}

// @fnv 0x00864490
char* __fastcall FUN_00864490(char* p)
{
    *p = 0;
    return p;
}

struct FUN_008644b0_shell : public BGSLoadFormBuffer
{
    int FUN_008644b0(SaveLoadFile*);
};

enum SIZE_TYPE
{
};
unsigned int __cdecl ReadSizedUnsignedInt(SaveLoadFile*, unsigned int&, SIZE_TYPE);
unsigned int __fastcall FUN_00853500(void*);
SIZE_TYPE __fastcall FUN_00864520(void*);

struct BGSSaveLoadFile_Read_shell : public SaveLoadFile
{
    unsigned int Read(void*, unsigned int);
};

// @fnv 0x008644b0
int FUN_008644b0_shell::FUN_008644b0(SaveLoadFile* apFile)
{
    SIZE_TYPE esizeType;
    unsigned int iLoadedSize;

    ((BGSSaveLoadFile_Read_shell*)apFile)->Read((char*)this + 0x14, 9);
    *(unsigned int*)((char*)this + 0x10) = FUN_00853500((char*)this + 0x14);
    esizeType = FUN_00864520((char*)this + 0x1b);
    iLoadedSize = ReadSizedUnsignedInt(apFile, *(unsigned int*)((char*)this + 0x20), esizeType);
    if (iLoadedSize != *(unsigned int*)((char*)this + 0x20))
        return -1;
    return iLoadedSize;
}

struct FUN_00864520_shell : public BGSSaveLoadFormInfo
{
    int FUN_00864520();
};

// @fnv 0x00864520
int FUN_00864520_shell::FUN_00864520()
{
    return *(unsigned char*)this >> 6;
}

struct S_00864540
{
    int pad[8];
    int f20;
    int ReadFromFile(int, int);
    int CheckValueMatchesField(int);
};
// Calls ReadFromFile with a and f20; returns -1 if the result differs from f20, otherwise returns the result.
// @fnv 0x00864540
int S_00864540::CheckValueMatchesField(int a)
{
    int r = ReadFromFile(a, f20);
    if (r != f20)
        return -1;
    return r;
}

struct FUN_00864580_shell : public BGSLoadFormBuffer
{
    void FUN_00864580(SaveLoadFile*, unsigned int);
};

// @fnv 0x00864580
void FUN_00864580_shell::FUN_00864580(SaveLoadFile* apFile, unsigned int aiAlreadyLoadedAmount)
{
    unsigned int uiRemaining;
    if ((uiRemaining =
             *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x20) - aiAlreadyLoadedAmount) != 0)
    {
        apFile->AdvancePosition(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x20) -
                                aiAlreadyLoadedAmount);
    }
}

struct FUN_008645b0_shell : public BGSLoadFormBuffer
{
    TESForm* FUN_008645b0();
};

// @fnv 0x008645b0
TESForm* FUN_008645b0_shell::FUN_008645b0()
{
    if (pForm == 0 && IsFlag2Set())
    {
        pForm = GetFormByID(iFormID);
    }
    return pForm;
}

struct FUN_008645f0_shell : public BGSLoadFormBuffer
{
    bool IsFlag2Set();
};

// @fnv 0x008645f0
bool FUN_008645f0_shell::IsFlag2Set()
{
    return (iFlags & 2) ? true : false;
}

struct TESObjectREFR;
struct FUN_00864610_shell : public BGSLoadFormBuffer
{
    TESObjectREFR* FUN_00864610();
};

namespace {
struct VTable4
{
    virtual void v0();
    virtual void* v1();
};
struct VTableF0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual bool vf0();
};
}

// Returns the form pointer from v1() as a TESObjectREFR if it is non-null and its vf0() is non-zero, otherwise returns 0.
// @fnv 0x00864610
TESObjectREFR* FUN_00864610_shell::FUN_00864610()
{
    VTableF0* pform = reinterpret_cast<VTableF0*>(reinterpret_cast<VTable4*>(this)->v1());
    if (pform && pform->vf0())
        return reinterpret_cast<TESObjectREFR*>(pform);
    return 0;
}

struct Actor;
struct ActorCause;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BipedAnim;
struct CellMopp;
struct GameFormRecord;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct BooleanIntegerAccessor;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESGlobal;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkNiCollisionObject;
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];
struct FUN_00864660_shell : public BGSLoadFormBuffer
{
    Actor* GetReferenceAsActor();
};

struct _REFR_VtblHelper
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
};

// Returns the buffer's reference cast to Actor if it is an actor, otherwise null.
// @fnv 0x00864660
Actor* FUN_00864660_shell::GetReferenceAsActor()
{
    TESObjectREFR* pref = GetReference();
    if (pref && reinterpret_cast<_REFR_VtblHelper*>(pref)->IsActor())
        return reinterpret_cast<Actor*>(pref);
    return 0;
}
