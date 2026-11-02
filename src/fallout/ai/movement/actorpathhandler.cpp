// src/fallout/ai/movement/actorpathhandler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/movement/actorpathhandler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Base_009e03e0
{
    virtual ~Base_009e03e0();
};

extern void _Deallocate(void*);

struct ActorPathHandler : Base_009e03e0
{
    void* FUN_009dfe10(unsigned int flags);
};

// Destructs the object and, when flags has bit 0 set, deallocates this; returns this.
// @fnv 0x009dfe10
void* ActorPathHandler::FUN_009dfe10(unsigned int flags)
{
    Base_009e03e0::~Base_009e03e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
