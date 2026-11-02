
// src/gamebryo2.2/corelibs/nicollision/nibox.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nibox.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct StreamBuffer;
struct NiStream;
struct NiColor
{
    float red;
    float green;
    float blue;
    void SaveBinary(NiStream& stream);
};
typedef int(__cdecl* StreamWrite)(StreamBuffer*, const void*, unsigned int, unsigned int*, int);
struct StreamBuffer
{
    int unk00;
    unsigned int position;
    int unk08;
    StreamWrite write;
};
struct NiStream
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    StreamBuffer* buffer;
};
struct ColorContainer
{
    NiColor firstColor;
    NiColor secondColor;
    NiColor thirdColor;
    NiColor fourthColor;
    struct
    {
        float x;
        float y;
        float z;
    } extraVector;
    void FUN_00eae630(NiStream* stream);
};
// Saves the four colors and the extra vector to the stream, writing the vector as 12 bytes through the buffer's write function.
// @fnv 0x00eae630
void ColorContainer::FUN_00eae630(NiStream* stream)
{
    firstColor.SaveBinary(*stream);
    NiColor* color = &secondColor;
    int remaining = 3;
    do
    {
        color->SaveBinary(*stream);
        ++color;
        --remaining;
    } while (remaining != 0);
    StreamBuffer* writer = stream->buffer;
    {
        int stream = 4;
        writer->position += writer->write(writer, &extraVector, 12, (unsigned int*)&stream, 1);
    }
}

// WriteToStream - ColorContainer::SaveBinary(NiStream&)
//
// Two things differ from the pack's unit file and have to be compensated for:
//
//  * The buffer pointer lives at this+0x24c in the stream this unit uses, but the
//    unit's NiStream declares `StreamBuffer *buffer` at +0x250 (and `int unk24C`
//    at +0x24c).  The buffer object itself is {int, unsigned position, fnptr}
//    here, not the unit's StreamBuffer, whose write pointer sits at +0xc.
//  * The per-colour writer is the function at 0x00a59be0.  The checker's symbol
//    database binds `?SaveBinary@NiColor@@QAEXAAUNiStream@@@Z` to 0x00a69780,
//    so the unit's NiColor::SaveBinary cannot be used for the call; a name that
//    is not in the database lets the checker bind the relocation from the
//    original bytes instead.

struct Buf
{
    int unk00;
    unsigned int position;
    StreamWrite write;
};

// the per-colour writer used by this unit (its stream layout differs from NiStream's)
struct NiColorWriter
{
    float red;
    float green;
    float blue;
    void WriteColor(NiStream& stream);
};

struct FUN_00eae5d0_cls : ColorContainer
{
    void WriteToStream(NiStream* stream);
};

// @fnv 0x00eae5d0
void FUN_00eae5d0_cls::WriteToStream(NiStream* stream)
{
    ((NiColorWriter*)&firstColor)->WriteColor(*stream);
    NiColorWriter* p = (NiColorWriter*)&secondColor;
    int n = 3;
    do
    {
        p->WriteColor(*stream);
        p++;
    } while (--n != 0);
    Buf* buffer = *(Buf**)&stream->unk24C;
    {
        // `count` is address taken and the stream argument is dead by now, so
        // MSVC puts it in the incoming argument slot - exactly like the original
        // (lea eax,[esp+0x18] / mov [esp+0x28],4).
        unsigned int count = 4;
        int written = buffer->write((StreamBuffer*)buffer, &extraVector, 0xc, &count, 1);
        buffer->position += written;
    }
}
