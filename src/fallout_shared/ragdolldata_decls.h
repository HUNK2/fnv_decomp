// fallout_shared/ragdolldata_decls.h: declares NiPoint3, NiUpdateData, bhkFilter, bhkWorldObject, bhkCollisionObject and more
#ifndef RAGDOLLDATA_DECLS_H
#define RAGDOLLDATA_DECLS_H

#include "ragdolldata_types_NiMatrix3.h"
class NiNode;
class NiPoint3
{
  public:
    float x, y, z;
};
class NiUpdateData
{
  public:
    float time;
    bool a, b, c, d;
    unsigned int flags;
    NiUpdateData(float, bool, bool);
};
class bhkFilter
{
  public:
    unsigned int value;
    int FUN_004d9da0();
};
class bhkWorldObject
{
  public:
    bhkFilter FUN_0043b4f0();
};
class bhkCollisionObject
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0(int, int, int);
    bhkWorldObject* FUN_006fa820();
    void FUN_004d9fa0(bool);
};
class NiAVObject
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual NiNode* IsSceneNode();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void UpdateWorldData(const NiUpdateData&);
    void FUN_00440460(const NiPoint3&);
};
class NiNode : public NiAVObject
{
  public:
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(int);
    void FUN_0043fa80(void*);
};
bhkCollisionObject* FUN_004a8b00(NiNode*);
struct TransformEntry
{
    signed char id;
    NiPoint3 translate;
    NiPoint3 rotate;
};
class RagDollData
{
  public:
    unsigned char count;
    TransformEntry* bones;
    bool FindBoneIndex(NiNode*, unsigned int&);
};
#endif
