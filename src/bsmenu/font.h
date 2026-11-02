// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/bsmenu/font.h
//
// Covered function (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x007593e0  Font::TextMeasurement::~TextMeasurement  (101 bytes)
//
// the five int layout fields, char m_cTextState at +0x1C and
// BSSimpleList<int> m_kLineWidths at +0x20; class size 0x28. The destructor
// body clears m_kLineWidths and the compiler appends member destruction for
// BSSimpleList<int> and BSStringT<char> in reverse declaration order.
#ifndef FNV_FONT_H
#define FNV_FONT_H


#include "layout_support.h"

class Font
{
  public:
    class TextMeasurement
    {
      public:
        BSStringT<char> m_kText;
        int iWidth;
        int iHeight;
        int m_iFirstTextMetric;
        int m_iSecondTextMetric;
        int m_iThirdTextMetric;
        char m_cTextState;
        BSSimpleList<int> m_kLineWidths;

        TextMeasurement();

// @fnv 0x007593e0
        ~TextMeasurement()
        {
            m_kLineWidths.RemoveAll();
        }

        BSStringT<char>* GetNewText();
        int GetWidth();
        int GetHeight();
        int GetNumLines();
        int GetCharCount();
        int GetLineWidth(int iLine);
    };
};

#endif
