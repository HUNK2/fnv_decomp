// gamebryo2.2/corelibs/niconsolerenderer/nidynamicgeometrygroup_decls.h: declares NiGeometryGroup, NiDynamicGeometryGroup
#ifndef NIDYNAMICGEOMETRYGROUP_DECLS_H
#define NIDYNAMICGEOMETRYGROUP_DECLS_H

void* __cdecl _NiMalloc(unsigned int);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
class NiGeometryGroup
{
  public:
    NiGeometryGroup();
    virtual void Purge();
    unsigned int m_uiRefCount;
    void* m_pD3DDevice;
};
class NiVBDynamicSet;
class NiVBChip;
template <class T> class DynamicMapBase
{
  public:
    virtual void Slot();
    unsigned int size;
    void* table;
    unsigned int count;
    DynamicMapBase() : size(37), count(0)
    {
        table = _NiMalloc(37 * 4);
        fnv_zlib_memset(table, 0, size * 4);
    }
};
template <class T> class DynamicMap : public DynamicMapBase<T>
{
  public:
    virtual void Slot();
    DynamicMap()
    {}
};
template <class T> class DynamicArrayBase
{
  public:
    virtual void Slot();
    void* data;
    unsigned short capacity, size, firstFree, grow;
    DynamicArrayBase(unsigned short maxSize = 0, unsigned short growBy = 1)
    {
        capacity = 0;
        grow = 1;
        size = 0;
        firstFree = 0;
        data = 0;
    }
};
template <class T> class DynamicArray : public DynamicArrayBase<T>
{
  public:
    virtual void Slot();
    DynamicArray()
    {}
};
class NiDynamicGeometryGroup : public NiGeometryGroup
{
  public:
    NiDynamicGeometryGroup();
    virtual void Purge();
    DynamicMap<NiVBDynamicSet> sets;
    DynamicMap<NiVBChip> chips;
    DynamicArray<NiVBDynamicSet> streamSets;
    DynamicArray<NiVBChip> streamChips;
    unsigned int nextIndex;
};
#endif
