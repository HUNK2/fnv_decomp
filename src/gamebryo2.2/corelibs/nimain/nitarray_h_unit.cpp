
// Header unit for gamebryo2.2/corelibs/nimain/nitarray.inl.
// No @fnv markers here; the covered template members are defined and
// marked in the header. This translation unit only forces the covered
// COMDATs to be emitted so their bytes can be compared.
#include "nitarray.inl"

void NiTArray_UnitReference()
{
    NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> >* pGroups = 0;
    ActorCombatGroup* pGroup = 0;
    pGroups->SetAt(0, pGroup);
    pGroups->SetSize(0);
    pGroups->SetAtGrow(0, pGroup);
}

struct Arr
{
    unsigned int GetSize();
};
struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    unsigned int GetSize();
};
struct FUN_0096aca0_shell : Arr
{
    void ResizeAndClear(int b);
};
// @fnv 0x0096aca0
void FUN_0096aca0_shell::ResizeAndClear(int aiCount)
{
    unsigned int uiOldSize = GetSize();
    ((StrArr*)this)->SetSize(uiOldSize + aiCount);
    for (unsigned int uiIndex = uiOldSize; uiIndex < ((StrArr*)this)->GetSize(); ++uiIndex)
    {
        char* pElement = 0;
        ((StrArr*)this)->SetAt(uiIndex, pElement);
    }
}
