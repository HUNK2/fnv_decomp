// fallout/ai/spectatorpackage_decls.h: declares SpectatorPackage
#ifndef SPECTATORPACKAGE_DECLS_H
#define SPECTATORPACKAGE_DECLS_H
class SpectatorPackage
{
  public:
    int IsComplete(const SpectatorPackage& other);
};
void __stdcall FUN_009f9c20(SpectatorPackage*);
int __stdcall FUN_009f9bb0(SpectatorPackage*, const SpectatorPackage*);
#endif
