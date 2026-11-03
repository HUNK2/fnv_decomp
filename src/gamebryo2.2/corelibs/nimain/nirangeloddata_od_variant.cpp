
// src/gamebryo2.2/corelibs/nimain/nirangeloddata_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nirangeloddata.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/nimain/nirangeloddata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nirangeloddata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_011f5ef8;
GlobalObjectO2_00a7b610* __cdecl NiRangeLODData_GetRTTI();
struct NiPoint3
{
    float x, y, z;
};
struct NiLODData
{
    int m_base;
    int m_ucUnknownByte;
};
struct NiRangeLODData_Range
{
};
struct CloningProcess
{
};
struct NiRangeLODData
{
    NiLODData m_base;
    NiPoint3 m_kCenter;
    NiPoint3 m_kWorldCenter;
    unsigned int m_uiRangeCount;
    NiRangeLODData_Range* m_pRanges;
    void SetRangeCount(unsigned int uiNumRanges);
    void CopyTo(NiRangeLODData* pkDest, CloningProcess* kCloning);
};
extern "C" void* __cdecl _memmove(void* dst, const void* src, unsigned int size);
