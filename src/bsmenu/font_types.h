// bsmenu/font_types.h: declares NiRect_float_, ButtonIcon, Font, FontManager
#ifndef FNV_FONT_PRIVATE_TYPES_H
#define FNV_FONT_PRIVATE_TYPES_H

#include <stddef.h>
#define FONT_JOIN_(a, b) a##b
#define FONT_JOIN(a, b) FONT_JOIN_(a, b)
#define FONT_ASSERT(e) typedef char FONT_JOIN(font_assert_, __LINE__)[(e) ? 1 : -1]
FONT_ASSERT(sizeof(void*) == 4);
class FontData;
class NiTexturingProperty;
class NiTriShape;
class NiPoint3;
class RgbaColor;
class FontCharacterInfo;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
};
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
};
template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
};
class NiRect_float_
{
  public:
    float m_fMinimumU;
    float m_fMaximumU;
    float m_fMinimumV;
    float m_fMaximumV;
};
class ButtonIcon
{
  public:
    float m_fGlyphWidthInPixels;
    float m_fHorizontalOffset;
    float m_fGlyphVerticalOffset;
    float m_fHorizontalSpacing;
    NiRect_float_ m_kTextureCoordinates;
};
class Font
{
  public:
    unsigned short BackgroundTask;
    char* m_pFile;
    int m_iFontNumber;
    NiPointer<NiTexturingProperty> m_kTextureSlots[8];
    float m_fLineHeight;
    float m_fDrop;
    int m_iOverlap;
    FontData* m_pFontData;
    BSStringT<char> m_kIconTexturePath;
    BSSimpleArray<ButtonIcon, 1024> m_kButtonIcons;
    static void MapCharacter(unsigned char& character);
    void AddCharacterToShape(FontCharacterInfo* letter, int index, NiTriShape* shape, NiPoint3& position,
                             const RgbaColor* color);
};
class FontManager
{
  public:
    Font* pFont[8];
    bool m_bUseNewFonts;
    static FontManager* pInstance;
    static FontManager* Instance();
    float GetFontPadding(int font);
};
FONT_ASSERT(sizeof(NiPointer<NiTexturingProperty>) == 4);
FONT_ASSERT(sizeof(BSStringT<char>) == 8);
FONT_ASSERT(offsetof(BSStringT<char>, sLen) == 4);
FONT_ASSERT(offsetof(BSStringT<char>, sMaxLen) == 6);
FONT_ASSERT(sizeof(NiRect_float_) == 16);
FONT_ASSERT(sizeof(ButtonIcon) == 32);
FONT_ASSERT(offsetof(ButtonIcon, m_kTextureCoordinates) == 16);
typedef BSSimpleArray<ButtonIcon, 1024> FontButtonIconArray;
FONT_ASSERT(sizeof(FontButtonIconArray) == 16);
FONT_ASSERT(offsetof(FontButtonIconArray, pBuffer) == 4);
FONT_ASSERT(offsetof(FontButtonIconArray, iSize) == 8);
FONT_ASSERT(offsetof(FontButtonIconArray, SimpleArrayStorage) == 12);
FONT_ASSERT(sizeof(Font) == 84);
FONT_ASSERT(offsetof(Font, BackgroundTask) == 0);
FONT_ASSERT(offsetof(Font, m_pFile) == 4);
FONT_ASSERT(offsetof(Font, m_iFontNumber) == 8);
FONT_ASSERT(offsetof(Font, m_kTextureSlots) == 12);
FONT_ASSERT(offsetof(Font, m_fLineHeight) == 44);
FONT_ASSERT(offsetof(Font, m_fDrop) == 48);
FONT_ASSERT(offsetof(Font, m_iOverlap) == 52);
FONT_ASSERT(offsetof(Font, m_pFontData) == 56);
FONT_ASSERT(offsetof(Font, m_kIconTexturePath) == 60);
FONT_ASSERT(offsetof(Font, m_kButtonIcons) == 68);
FONT_ASSERT(sizeof(FontManager) == 36);
FONT_ASSERT(offsetof(FontManager, pFont) == 0);
FONT_ASSERT(offsetof(FontManager, m_bUseNewFonts) == 32);
#endif
