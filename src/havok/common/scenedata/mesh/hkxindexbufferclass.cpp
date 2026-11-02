
// src/havok/common/scenedata/mesh/hkxindexbufferclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxindexbufferclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct AudioAllocator
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Release(void*, unsigned int);
};
struct BSAudio
{
    unsigned int unk00, unk04, unk08, unk0C;
    AudioAllocator* allocator;
    void Release(void* p, unsigned int size)
    {
        allocator->Release(p, size);
    }
};
BSAudio* FUN_00c85750();
struct AudioObject
{
    unsigned int unk00;
    unsigned short allocationSize;
    void FUN_00e023c0();
    static void operator delete(void* p)
    {
        BSAudio* audio = FUN_00c85750();
        AudioObject* object = static_cast<AudioObject*>(p);
        audio->allocator->Release(p, object->allocationSize);
    }
    void* ReleaseIfFlagged(unsigned int flags);
};
// Calls FUN_00e023c0, then deletes this via operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00e02430
void* AudioObject::ReleaseIfFlagged(unsigned int flags)
{
    FUN_00e023c0();
    if (flags & 1)
        operator delete(this);
    return this;
}
