#ifndef FNV_EXPRESSIONOPERAND_H
#define FNV_EXPRESSIONOPERAND_H

#include "layout_support.h"
#pragma pack(push, 4)
class ExpressionValue
{
  public:
    char Type;  // +0x0
    unsigned char layoutPadding1;
    unsigned short layoutPadding2;
    unsigned int layoutPadding4;
    union
    {
        long m_lIntegerValue;
        double m_dFloatingPointValue;
    };  // +0x8
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExpressionValue) == 0x10);
FNV_STATIC_ASSERT(offsetof(ExpressionValue, Type) == 0x0);
FNV_STATIC_ASSERT(offsetof(ExpressionValue, m_lIntegerValue) == 0x8);
FNV_STATIC_ASSERT(offsetof(ExpressionValue, m_dFloatingPointValue) == 0x8);
#endif
