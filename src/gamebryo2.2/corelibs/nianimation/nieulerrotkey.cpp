
// src/gamebryo2.2/corelibs/nianimation/nieulerrotkey.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nieulerrotkey.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern unsigned char DAT_011f3758[];
class ChannelState
{
  public:
    __declspec(noinline) void ClearFloatKeys();
    int unk00, unk04, unk08, unk0c, unk10;
    // Three presence/count values, followed by the three channel type codes.
    // A single property block keeps every cursor access within its array.
    int channelProperties[6];

    unsigned char encoded[3];
    void* values[3];
    int unk3c, unk40, unk44;
    void SetChannelValues(void* value0, int present0, unsigned type0, void* value1, int present1, unsigned type1,
                          void* value2, int present2, unsigned type2);
};
extern void(__cdecl* DAT_011f38a0[])(void*);
void ChannelState::ClearFloatKeys()
{
    for (int i = 0; i < 3; ++i)
    {
        if (values[i])
            DAT_011f38a0[channelProperties[i + 3]](values[i]);
        values[i] = 0;
        channelProperties[i] = 0;
        channelProperties[i + 3] = 0;
    }
}
// Clears the three channel slots, stores each value with its presence flag and type, resets unk3c/unk40/unk44, and encodes the type bytes into encoded.
// @fnv 0x00a3d540
void ChannelState::SetChannelValues(void* value0, int present0, unsigned type0, void* value1, int present1,
                                    unsigned type1, void* value2, int present2, unsigned type2)
{
    ClearFloatKeys();
    channelProperties[0] = present0;
    values[0] = value0;
    channelProperties[3] = type0;
    channelProperties[1] = present1;
    values[1] = value1;
    channelProperties[4] = type1;
    channelProperties[2] = present2;
    values[2] = value2;
    channelProperties[5] = type2;
    unk3c = 0;
    unk40 = 0;
    unk44 = 0;
    int* piChannelProp = channelProperties + 3;
    unsigned char* pucEncoded = encoded;
    for (int remaining = 3; remaining; --remaining)
    {
        if (piChannelProp[-3])
            *pucEncoded = DAT_011f3758[*piChannelProp];
        else
            *pucEncoded = 0;
        ++piChannelProp;
        ++pucEncoded;
    }
}
