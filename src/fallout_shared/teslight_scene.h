// fallout_shared/teslight_scene.h: declares NiMemObject, NiAVObject, NiNode, NiLight, NiSortAdjustNode
#ifndef FNV_TESLIGHT_SCENE_H
#define FNV_TESLIGHT_SCENE_H


class NiAVObject;
class NiNode;
class NiRTTI;
class TESObjectREFR;

class NiMemObject
{
  public:
    static void* __cdecl operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
};

class NiAVObject : public NiMemObject
{
  public:
    virtual ~NiAVObject();
    virtual void DeleteThis();
    virtual const void* GetRTTI() const;
    virtual NiNode* IsSceneNode();
    unsigned char layoutPadding[0x98];
};

class NiNode : public NiAVObject
{
  public:
    unsigned char layoutPadding[0x10];
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int index);
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void vfn_00d0();
    virtual void vfn_00d4();
    virtual void vfn_00d8();
    virtual void vfn_00dc(NiAVObject* object, bool arg1);
};

class NiLight : public NiAVObject
{
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* object);
    ~NiPointer();
    operator T*() const;
};

class NiSortAdjustNode : public NiNode
{
  public:
    NiSortAdjustNode(int arg1);
};

template <class T> unsigned int __cdecl BSStringLength(const T* string);
bool __cdecl NiObject_IsKindOf(const NiRTTI* type, NiAVObject* object);
extern NiRTTI DAT_011f4a28;

#endif
