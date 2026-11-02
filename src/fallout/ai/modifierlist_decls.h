// fallout/ai/modifierlist_decls.h: declares Modifier
#ifndef FNV_MODIFIERLIST_DECLS_H
#define FNV_MODIFIERLIST_DECLS_H


#include "layout_support.h"

#pragma pack(push, 4)
class Modifier
{
  public:
    char cKey;
    unsigned char padding[3];
    float fValue;

    Modifier(Modifier* other);
    Modifier(char key, float value);
    void SetValue(float value);
    char GetKey();
    float GetValue();
};

class ModifierPointerList
{
  public:
    Modifier** m_ppModifiers;
    ModifierPointerList();
    ModifierPointerList(ModifierPointerList* other);
    void RemoveModifier(int key);
    ~ModifierPointerList();
};

class ActorValueModifierList : public BSSimpleList<Modifier*>
{
  public:
    bool m_bAllowZeroValueModifiers;
    unsigned char padding[3];
    ModifierPointerList* m_ppModifiedActorValues;

    Modifier* GetModifierItem(char key);
    float GetActorValueModifierAmount(char key, bool& found);
    float GetActorValueModifierAmount(char key);
    enum ClampStyle
    {
        ClampNone = 0
    };
    void ModifyModifier(char key, float delta, ClampStyle clamp);
    static float ModifyAndClamp(float value, float delta, ClampStyle clamp);
    void EraseModifier(Modifier* modifier);
    void CopyModifierListFrom(ActorValueModifierList* other);
    void AppendModifier(Modifier* modifier);
    void RemoveAllModifiers();
    void AddFastModifier(char key, Modifier* modifier);
};
#pragma pack(pop)

void __cdecl operator delete(void* memory);

FNV_STATIC_ASSERT(sizeof(Modifier) == 8);
FNV_STATIC_ASSERT(sizeof(ActorValueModifierList) == 0x10);

#endif
