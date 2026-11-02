// fallout_shared/packagelocation_package.h: declares TESPackage, BGSMessageInitAccess
#ifndef FNV_PACKAGELOCATION_PACKAGE_H
#define FNV_PACKAGELOCATION_PACKAGE_H


#include "TESForm.h"
#include "TESFullName.h"
#include "TESDescription.h"

// These small functions are linker-folded package/message accessors. The
enum PACKAGE_PROCEDURE_TYPE
{
    PACKAGE_PROCEDURE_NONE = -1
};
class TESPackageData;

class TESPackage : public TESForm
{
  public:
    int eProcedureType;  // +0x18
    struct Data
    {
        unsigned int uiPackageFlags;
        signed char eType;
        unsigned short usFOBehaviorFlags;
        unsigned short usPackageSpecificFlags;
    } kData;                               // +0x1c
    TESPackageData* m_pEscortPackageData;  // +0x28
    LocationDescriptor* pPackageLocation;  // +0x2c

    void SetMustReachLocation(bool enabled);
    void SetMustComplete(bool enabled);
    void SetProcedureType(PACKAGE_PROCEDURE_TYPE procedure);
};

FNV_STATIC_ASSERT(offsetof(TESPackage, eProcedureType) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESPackage, kData) == 0x1c);
FNV_STATIC_ASSERT(offsetof(TESPackage, pPackageLocation) == 0x2c);

// Canonical named access view for the message icon's serialized form ID.
struct BGSMessageInitAccess : public TESForm
{
    TESFullName fullName;
    TESDescription description;
    unsigned int iconFormID;

    unsigned int GetIconFormID();
};

FNV_STATIC_ASSERT(offsetof(BGSMessageInitAccess, iconFormID) == 0x2c);

#endif
