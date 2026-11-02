
// src/havok/common/base/reflection/hkclassenum_decl_variant_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/base/reflection/hkclassenum_decl_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/reflection/hkclassenum_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00db7600: the skeleton of src/havok/common/base/reflection/hkclassenum.cpp
// with declarations corrected to what the original code does (hkBase.h: typedef char hkBool; -> class hkBool { public: __forceinline hkBool() {} _; hkClassEnum.h: hkClassEnum += void FUN_00db7600(class hkStreamWriter* writer) const;). Move the function to its real unit once
// that unit declares it this way.
// src/havok/common/base/reflection/hkclassenum.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassenum.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkClassEnum_decl_hkclassenum.h"
extern "C" int __cdecl FUN_00d86980();
int __stdcall ReadSignedValueBySize(const void* p);
struct hkCustomAttributes
{
    void* __thiscall getAttribute(void* arg);
};
struct FUN_00db76a0_Class
{
    void* __thiscall GetAttribute(void* arg);
};
struct FUN_00db7860
{
    int m_00;
    int m_04;
    int m_08;
    ~FUN_00db7860() throw();
};
struct FUN_00db7870 : public FUN_00db7860
{
    FUN_00db7870(int n) throw();
};
struct hkObjDB76
{
    void FUN_00db7600(FUN_00db7860* p) throw();
    void FUN_00db76c0();
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short memSizeAndFlags;
    short referenceCount;
};
class hkStreamWriter;
class hkOArchive : public hkReferencedObject
{
  public:
    hkStreamWriter* writer;
    hkBool byteSwap;
    hkOArchive(hkStreamWriter*, hkBool);
    virtual ~hkOArchive();
    void FUN_00d607b0(const void*, int);
    void WriteInt(unsigned int);
};
class hkClassEnumItem
{
  public:
    int value;
    const char* name;
};
int __cdecl FUN_00cb10d0(const char*);
// @fnv 0x00db7600
void hkClassEnum::FUN_00db7600(hkStreamWriter* writer) const
{
    hkOArchive archive(writer, false);
    const char* name = m_name;
    archive.FUN_00d607b0(name, FUN_00cb10d0(name));
    int count = m_items.m_iElementCount;
    for (int i = 0; i < count; ++i)
    {
        const hkClassEnumItem& item = m_items.m_data[i];
        const char* itemName = item.name;
        archive.FUN_00d607b0(itemName, FUN_00cb10d0(itemName));
        archive.WriteInt(item.value);
    }
    archive.WriteInt(count);
}
