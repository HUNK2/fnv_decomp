// bscore/bssimplearray_packet_decls.h: declares BSSimpleArrayPacketEffect, BSSimpleArrayPacketDebug, NiNode, PacketNodeRecord, PathingGraphNode and more
#ifndef BSSIMPLEARRAY_PACKET_DECLS_H
#define BSSIMPLEARRAY_PACKET_DECLS_H


typedef int(__cdecl* BSSimpleArrayCompare)(const void*, const void*);
extern "C" void* __cdecl bsearch(const void*, const void*, unsigned int, unsigned int, BSSimpleArrayCompare);

template <class T, unsigned int N> class BSSimpleArray
{
  public:
    virtual ~BSSimpleArray() = 0;

    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    void FUN_006b3eb0(unsigned int, bool);
    void ReleaseElements(T* items, unsigned int count);
    void InitializeItems(T* items, unsigned int count);
    unsigned int BinarySearch(T& value, BSSimpleArrayCompare compare);
    unsigned int ReserveIndex();
    unsigned int Add(T& value);
};

extern unsigned int DAT_0106c264;
extern unsigned int DAT_0106f798;
extern unsigned int DAT_01073e50;
class BSSimpleArrayPacketEffect
{
  public:
    void FUN_007883b0(unsigned int, bool);
};
extern unsigned int DAT_0109504c;
class BSSimpleArrayPacketDebug
{
  public:
    void InitArray(unsigned int, bool);
};

class NiAVObject;
class TESObjectREFR;
class NiNode;
template <class T> class NiTNewInterface;
template <class T, class Allocator> class NiTArray
{
  public:
    T& GetAt(unsigned int);
};
template <class T> class NiPointer
{
  public:
    T* operator->() const;
};
class NiNode
{
    char prefix[0x9c];
    NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> > children;

  public:
    NiAVObject* GetAt(unsigned int);
};

class PacketNodeRecord
{
    char storage[0x30];
};
class PathingGraphNode
{
    char storage[0x3c];
};
class BSSimpleArrayPacketNode
{
  public:
    void FUN_006d0510(unsigned int);
};
class BSSimpleArrayPacketReserve
{
  public:
    unsigned int FUN_00761540();
};

#endif
