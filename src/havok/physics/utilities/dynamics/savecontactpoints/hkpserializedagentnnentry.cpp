
// src/havok/physics/utilities/dynamics/savecontactpoints/hkpserializedagentnnentry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/savecontactpoints/hkpserializedagentnnentry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpSerializedAgentNnEntry.h"

struct Hk_e05c20_alloc
{
    virtual void slot0();
    virtual void slot1();
    virtual void deleteObj(void* p, int flags);
    virtual void slot3();
    virtual void ReturnMemory(void* p, int size);
};

struct Hk_e05c20_router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Hk_e05c20_alloc* m_alloc;
    Hk_e05c20_alloc& heap()
    {
        return *m_alloc;
    }
};

Hk_e05c20_router* FUN_00c85750();

struct Hk_e05c20_track
{
    hkArray<hkpAgent1nSector*> m_kSectors;
    hkArray<hkpSerializedSubTrack1nInfo*> m_kSubTracks;
    void FUN_00e05c20();
};

// Frees all hkpAgent1nSector and hkpSerializedSubTrack1nInfo entries, then returns the underlying array memory to the heap and resets both arrays.
// @fnv 0x00e05c20
void Hk_e05c20_track::FUN_00e05c20()
{
    if ((m_kSectors.m_iCapacityState & 0x80000000) == 0)
    {
        for (int i = 0; i < m_kSectors.m_iElementCount; ++i)
        {
            hkpAgent1nSector* p = m_kSectors.m_data[i];
            if (p)
            {
                FUN_00c85750()->heap().deleteObj(p, 0x200);
            }
        }
    }
    if ((m_kSubTracks.m_iCapacityState & 0x80000000) == 0)
    {
        for (int i = 0; i < m_kSubTracks.m_iElementCount; ++i)
        {
            hkpSerializedSubTrack1nInfo* p = m_kSubTracks.m_data[i];
            if (p)
            {
                reinterpret_cast<Hk_e05c20_track*>(p)->FUN_00e05c20();
                FUN_00c85750()->heap().deleteObj(p, 0x20);
            }
        }
    }
    Hk_e05c20_alloc& a = FUN_00c85750()->heap();
    m_kSubTracks.m_iElementCount = 0;
    if ((m_kSubTracks.m_iCapacityState & 0x80000000) == 0)
    {
        a.ReturnMemory(m_kSubTracks.m_data, (m_kSubTracks.m_iCapacityState & 0x3fffffff) * 4);
    }
    m_kSubTracks.m_data = 0;
    m_kSubTracks.m_iCapacityState = 0x80000000;

    Hk_e05c20_alloc& b = FUN_00c85750()->heap();
    m_kSectors.m_iElementCount = 0;
    if ((m_kSectors.m_iCapacityState & 0x80000000) == 0)
    {
        b.ReturnMemory(m_kSectors.m_data, (m_kSectors.m_iCapacityState & 0x3fffffff) * 4);
    }
    m_kSectors.m_iCapacityState = 0x80000000;
    m_kSectors.m_data = 0;
}
