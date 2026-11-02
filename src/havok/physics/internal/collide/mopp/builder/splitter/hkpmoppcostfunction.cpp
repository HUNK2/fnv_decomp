
// src/havok/physics/internal/collide/mopp/builder/splitter/hkpmoppcostfunction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/splitter/hkpmoppcostfunction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CountProvider
{
    virtual void Destroy();
    virtual void Initialize();
    virtual void Reset();
    virtual void Update();
    virtual int GetCount();
};
struct BufferRequirements
{
    int unk00;
    int unk04;
    int unk08;
    int additionalCount;
    int unk10;
    int unk14;
    int unk18;
    bool fixedCapacity;
    int ComputeRequiredSize(CountProvider* provider);
};
// Computes a byte size from the provider's count plus additionalCount, using a fixed capacity of 4096 when fixedCapacity is set.
// @fnv 0x00dd4b80
int BufferRequirements::ComputeRequiredSize(CountProvider* provider)
{
    int count = provider->GetCount() + additionalCount;
    int capacity = fixedCapacity ? 4096 : count;
    return capacity * 224 + count * 20;
}
