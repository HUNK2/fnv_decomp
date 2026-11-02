// bshavok/bhkliquidaction.h: declares bhkLiquidAction
#ifndef BHKLIQUIDACTION_H
#define BHKLIQUIDACTION_H

#include "bhkliquidaction_decls.h"
class bhkLiquidAction : public FUN_0056d410
{
  public:
    bhkLiquidAction(const LiquidActionInfo& info);
    virtual ~bhkLiquidAction();
    void ConfigureBody(const LiquidActionInfo& info);
    GlobalObject_004ee810 member;
};
// @fnv 0x0056d380
bhkLiquidAction::bhkLiquidAction(const LiquidActionInfo& info)
{
    ConfigureBody(info);
    ++DAT_012681bc;
}
#endif
