// fallout_shared/bgsentrypoint.cpp: EntryPointFunctionDispatcher (1 function)

#include "EntryPointFunctionDispatcher.h"
#include "BGSEntryPointFunction.h"
#include "Actor.h"
#include "BGSPerkEntry.h"
#include "PlayerCharacter.h"
#include "original_entrypoint.h"
#include "original_script.h"
#include <stdarg.h>

namespace {
enum
{
    kMaximumEntryPointArguments = 10
};
}

// @fnv 0x005e58f0
void EntryPointFunctionDispatcher::ExecuteEntryPoint(ENTRY_POINT entryPoint, Actor* actor, ...)
{
    if (!actor || entryPoint >= ENTRY_POINT_COUNT)
        return;

    bool teammate = false;
    Actor* originalActor = actor;
    if (actor != g_thePlayer && actor->IsPlayerTeammate())
    {
        teammate = true;
        actor = g_thePlayer;
    }
    BSSimpleList<BGSPerkEntry*>* entries =
        actor->GetPerkEntriesForEntryPoint(static_cast<unsigned char>(entryPoint), teammate);
    if (entries && entries->GetItem())
    {
        actor = originalActor;
        TESForm* filters[kMaximumEntryPointArguments];
        void* functionArguments[kMaximumEntryPointArguments];
        unsigned char filterCount = ms_kEntryPointTable[entryPoint].m_kParameters.cCount;
        BGSEntryPointFunction::ENTRY_POINT_FUNCTION_TYPE functionType =
            static_cast<BGSEntryPointFunction::ENTRY_POINT_FUNCTION_TYPE>(
                ms_kEntryPointTable[entryPoint].m_ucFunctionType);
        unsigned char argumentCount = BGSEntryPointFunction::GetArgumentCount(functionType);
        filters[0] = actor;
        va_list arguments;
        va_start(arguments, actor);
        bool filtersValid = true;
        for (unsigned int i = 1; i < filterCount; ++i)
        {
            filters[i] = va_arg(arguments, TESForm*);
            if (!filters[i])
                filtersValid = false;
        }
        bool argumentsValid = true;
        for (unsigned int i = 0; i < argumentCount; ++i)
        {
            functionArguments[i] = va_arg(arguments, void*);
            if (!functionArguments[i])
                argumentsValid = false;
        }
        va_end(arguments);
        if (filtersValid && argumentsValid)
        {
            while (entries)
            {
                BGSPerkEntry* entry = entries->GetItem();
                if (entry && entry->CheckConditionFilters(filterCount, filters))
                {
                    BGSEntryPointFunction::ApplyFunction(
                        static_cast<BGSEntryPointFunction::ENTRY_POINT_FUNCTION>(entry->GetFunction()), actor,
                        functionType, argumentCount, functionArguments, entry->GetFunctionData());
                }
                entries = entries->GetNext();
            }
        }
        else
        {
            Warning(g_entryPointArgumentErrorFormat,
                    filtersValid ? g_entryPointFunctionArgumentName : g_entryPointFilterParameterName,
                    ms_kEntryPointTable[entryPoint].m_pName, filtersValid ? argumentCount : filterCount);
        }
    }
}
