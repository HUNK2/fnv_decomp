// gamebryo2.2/corelibs/nimain/nipoint2.cpp: NiPoint2 (2 functions)

#include "nipoint2_decls.h"
// Reads two floats from the stream into the point's x and y coordinates.
// @fnv 0x00a68c80
void NiPoint2::LoadBinary(NiStream& stream)
{
    stream.m_pUnderlyingStream->ReadFloat(x);
    stream.m_pUnderlyingStream->ReadFloat(y);
}

struct OS_00a68ce0
{
    int f0;
    int f4;
    int f8;
    int(__cdecl* fC)(OS_00a68ce0*, void*, int, int*, int);
    void WriteFloat(float& f)
    {
        int tmp = 4;
        f4 += fC(this, &f, 4, &tmp, 1);
    }
};
struct ST_00a68ce0
{
    char _0[0x250];
    OS_00a68ce0* m_pBackingStream;
};
struct THIS_00a68ce0
{
    float x;
    float y;
    void WriteCoords(ST_00a68ce0&);
};
// @fnv 0x00a68ce0
void THIS_00a68ce0::WriteCoords(ST_00a68ce0& aStream)
{
    aStream.m_pBackingStream->WriteFloat(x);
    aStream.m_pBackingStream->WriteFloat(y);
}
