
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
