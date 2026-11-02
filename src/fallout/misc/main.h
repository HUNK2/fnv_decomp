// fallout/misc/main.h: declares NiMemObject, SceneGraph, Main
#ifndef FNV_MAIN_H
#define FNV_MAIN_H

// Shared classes come from the canonical include/ headers (PlayerCharacter/Character/Actor/MobileObject/
// TESObjectREFR/TESForm, NiRefObject). Two leaf types stay unit-local supersets of the canonical ones because
// matched functions use members the canonical headers do not declare:
//   NiPointer: default constructor and out-of-line operator= on incomplete T (Main::spMenuSceneGraph, 0x0066b0d0).
//   NiMemObject: static operator new (??2NiMemObject@@SAPAXI@Z, 0x00aa13e0); canonical NiMemObject is empty.
#define NiPointer FNV_NiPointer_Dummy
#define NiMemObject FNV_NiMemObject_Canonical
#include "layout_support.h"
#include "NiMemObject.h"
#undef NiMemObject
#undef NiPointer

class NiCamera;
class SceneGraph;

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    NiPointer<T>& operator=(T* object);
};

class NiMemObject
{
  public:
    static void* operator new(size_t size);
    static void operator delete(void*, unsigned int);
};
FNV_STATIC_ASSERT(sizeof(NiMemObject) == sizeof(FNV_NiMemObject_Canonical));

#include "NiRefObject.h"
#include "PlayerCharacter.h"

extern PlayerCharacter* g_thePlayer;

class SceneGraph : public NiMemObject
{
  public:
    char pad[0xC0];
    SceneGraph(const char* name, bool menuSceneGraph, NiCamera* camera);
};

class Main
{
  public:
    static NiPointer<SceneGraph> spMenuSceneGraph;

    static void CreateMenuSceneGraph();
};

// @fnv 0x004dc650
void Main::CreateMenuSceneGraph()
{
    spMenuSceneGraph = new SceneGraph("3DMenu", false, 0);
}

#endif
