// fallout/interface/menus/playernameentrymenu.cpp: PlayerNameEntryMenu (7 functions)

#include "playernameentrymenu_decls.h"

// If FUN_007ab810 reports completion, passes its result to Finish and then calls FUN_007ab7c0.
// @fnv 0x007ab7e0
void PlayerNameEntryMenu::UpdateDialog()
{
    if (FUN_007ab810())
    {
        Finish(FUN_007ab810());
        FUN_007ab7c0();
    }
}

struct Str6a70
{
    Str6a70& operator=(char const*);
};

extern Str6a70 g_011daed8;

// @fnv 0x007ab7c0
void __cdecl FUN_007ab7c0(void)
{
    g_011daed8 = 0;
}

namespace fnv_007ab810 {
extern const char* __cdecl FUN_007ab810();

struct Flt
{
    operator const char*() const;
};

extern Flt g_011daed8;

// @fnv 0x007ab810
const char* __cdecl FUN_007ab810()
{
    return g_011daed8;
}
}  // namespace fnv_007ab810

struct S_7ab770
{
    void FUN_007ab7a0();
    void* FUN_007ab770(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_007ab7a0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x007ab770
void* S_7ab770::FUN_007ab770(unsigned int flags)
{
    FUN_007ab7a0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FullNameEx
{
    void SetFullName(char const*);
};
struct Tile
{
    void Set(int, int);
};
void _FUN_007df4e0();
struct NPC007ab9a0
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void func48(int);
};
struct Holder007ab9a0
{
    int _00;
    Tile* _04;
    char _08[28];
    int _24;
    NPC007ab9a0* _28;
    void FUN_007ab9a0(char const* apName);
};
// If apName is set, applies it to the full name at _28+0xd0, calls func48(0x20) and _FUN_007df4e0; then sets tile _04 to (0x1772,1) and _24 to 2.
// @fnv 0x007ab9a0
void Holder007ab9a0::FUN_007ab9a0(char const* apName)
{
    if (apName)
    {
        ((FullNameEx*)((char*)_28 + 0xd0))->SetFullName(apName);
        _28->func48(0x20);
        _FUN_007df4e0();
    }
    _04->Set(0x1772, 1);
    _24 = 2;
}

class FUN_007ab7a0_base
{
  public:
    virtual void unk00();
    ~FUN_007ab7a0_base();
    int unk04;
};

class FUN_007ab7a0_cls : public FUN_007ab7a0_base
{
  public:
    virtual ~FUN_007ab7a0_cls();
};

// @fnv 0x007ab7a0
FUN_007ab7a0_cls::~FUN_007ab7a0_cls()
{}

void NormalizeSmartQuotes(unsigned char* apChar);

struct FontGlyph
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float m_fGlyphWidthInPixels;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
};

struct FontData
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
    FontGlyph glyphs[256];
};

struct Font
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    FontData* pData;
};

struct FontManager
{
    static FontManager* Instance();
    Font* GetFont(int aiID);
};

// True if every character is printable in fonts 0 and 6 and at least one is not a space.
// @fnv 0x007ab820
bool __cdecl IsTextRenderable(const char* apText)
{
    bool bHasNonSpace6 = false;
    bool bInvalid7 = false;
    unsigned char cChar2;
    Font* pFont;
    if (apText)
    {
        while (!bInvalid7 && *apText)
        {
            cChar2 = *apText;
            NormalizeSmartQuotes(&cChar2);
            bInvalid7 = (cChar2 == '\\' || cChar2 == '~');
            pFont = FontManager::Instance()->GetFont(0);
            if (pFont && pFont->pData)
            {
                if (pFont->pData->glyphs[cChar2].m_fGlyphWidthInPixels != 0.0)
                    bHasNonSpace6 = (bHasNonSpace6 || cChar2 != ' ');
                else
                    bInvalid7 = true;
            }
            pFont = FontManager::Instance()->GetFont(6);
            if (pFont && pFont->pData)
            {
                if (pFont->pData->glyphs[cChar2].m_fGlyphWidthInPixels != 0.0)
                    bHasNonSpace6 = (bHasNonSpace6 || cChar2 != ' ');
                else
                    bInvalid7 = true;
            }
            apText++;
        }
    }
    return bHasNonSpace6 && !bInvalid7;
}
