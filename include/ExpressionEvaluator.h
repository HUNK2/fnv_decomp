#ifndef FNV_CEXPRESSION_H
#define FNV_CEXPRESSION_H

#include "layout_support.h"
#include "ExpressionValue.h"
#pragma pack(push, 4)
class ExpressionEvaluator
{
  public:
    EXPRESSION_ERROR m_eExpressionError;               // +0x0
    char m_sExpression[512];                           // +0x4
    char m_sExpressionBuffer[512];                     // +0x204
    Stack<ExpressionOperator, 64> m_kOperatorStack;  // +0x404
    Stack<ExpressionValue, 32> m_kOperandStack;      // +0x508
    ExpressionEvaluator();
    ~ExpressionEvaluator();
    double Eval(const char* data, TESObjectREFR* reference, TESObjectREFR* container, Script* script,
                ScriptLocals* locals, int length, bool skip);
    EXPRESSION_ERROR ExpressionError();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExpressionEvaluator) == 0x70C);
FNV_STATIC_ASSERT(offsetof(ExpressionEvaluator, m_eExpressionError) == 0x0);
FNV_STATIC_ASSERT(offsetof(ExpressionEvaluator, m_sExpression) == 0x4);
FNV_STATIC_ASSERT(offsetof(ExpressionEvaluator, m_sExpressionBuffer) == 0x204);
FNV_STATIC_ASSERT(offsetof(ExpressionEvaluator, m_kOperatorStack) == 0x404);
FNV_STATIC_ASSERT(offsetof(ExpressionEvaluator, m_kOperandStack) == 0x508);
#endif
