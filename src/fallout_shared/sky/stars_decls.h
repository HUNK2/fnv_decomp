// fallout_shared/sky/stars_decls.h: declares SkyObject, Stars
#ifndef FNV_STARS_DECLS_H
#define FNV_STARS_DECLS_H
class NiNode;
class SkyObject
{
  public:
    void Initialize(NiNode*);
};
class Stars : public SkyObject
{
  public:
    void Initialize(NiNode*);
};
#endif
