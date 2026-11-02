// include/BGSEntryPointFunction.h: declares BGSEntryPointFunction, EntryPointFunctionInfo
#ifndef FNV_BGSENTRYPOINTFUNCTION_H
#define FNV_BGSENTRYPOINTFUNCTION_H
#include "layout_support.h"
#pragma pack(push, 4)
class BGSEntryPointFunction
{
  public:
    enum ENTRY_POINT_FUNCTION
    {
        NONE = 0,
        SET_VALUE = 1,
        ADD_VALUE = 2,
        MULTIPLY_VALUE = 3,
        ADD_RANGE_TO_VALUE = 4,
        ADD_ACTOR_VALUE_MULT = 5,
        ABSOLUTE_VALUE = 6,
        NEGATIVE_ABSOLUTE_VALUE = 7,
        ADD_LEVELED_LIST_TO_TARGET = 8,
        ADD_ACTIVATE_CHOICE = 9,
        ENTRY_POINT_FUNCTION_COUNT = 10
    };
    enum ENTRY_POINT_FUNCTION_TYPE
    {
        VALUE_FUNCTION = 0,
        LEVELED_LIST_FUNCTION = 1,
        ACTIVATE_FUNCTION = 2,
        SPECIAL_FUNCTION = 3,
        ENTRY_POINT_FUNCTION_TYPE_COUNT = 4
    };
    struct EntryPointFunctionInfo
    {
        char* pFunctionName;
        ENTRY_POINT_FUNCTION_TYPE m_eFunctionType;
        void(__cdecl* pFunction)(TESObjectREFR*, ENTRY_POINT_FUNCTION_TYPE, unsigned char, void**, void*);
    };
    static unsigned char GetArgumentCount(ENTRY_POINT_FUNCTION_TYPE type);
    static void ApplyFunction(ENTRY_POINT_FUNCTION function, TESObjectREFR* reference, ENTRY_POINT_FUNCTION_TYPE type,
                              unsigned char argumentCount, void** arguments, void* data);
    static EntryPointFunctionInfo ms_kEntryPointFunctionTable[];
    static unsigned int ms_auiArgumentCountsByType[];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSEntryPointFunction::EntryPointFunctionInfo) == 12);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointFunction::EntryPointFunctionInfo, pFunctionName) == 0);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointFunction::EntryPointFunctionInfo, m_eFunctionType) == 4);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointFunction::EntryPointFunctionInfo, pFunction) == 8);
#endif
