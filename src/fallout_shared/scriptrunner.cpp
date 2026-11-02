// fallout_shared/scriptrunner.cpp: ScriptRunner (2 functions)

#include "ScriptRunner.h"
#include "Script.h"
#include "ScriptReferencedObject.h"
#include "ScriptFunctionInfo.h"
#include "TESObjectREFR.h"
#include "original_script.h"
#include "game_constants.h"
#include "ScriptHeaderData.h"
#include "ScriptLocals.h"
#include "ExpressionEvaluator.h"
#include "TESQuest.h"
#include "TESGlobal.h"
extern ScriptFunctionInfo g_scriptBlocks[kScriptBlockCount];
extern const char* g_expressionErrorStrings[];
extern void DebugLog(const char* format, ...);
extern bool IsScriptDebuggingEnabled();
extern const char* PrepareScriptMessage(const char* message, bool localized);

// @fnv 0x005e13a0
bool ScriptRunner::ParseOutput(Script* script, SCRIPT_OUTPUT& output, unsigned int& offset, int& lineSize,
                               TESObjectREFR** reference, bool skipReference)
{
    lineSize = 0;
    output = static_cast<SCRIPT_OUTPUT>(*reinterpret_cast<short*>(script->GetData() + offset));
    offset += 2;
    if (output == SCRIPT_OUTPUT_FLOW_REFERENCE_FUNCTION)
    {
        bool isVariable = false;
        unsigned int referenceID = *reinterpret_cast<short*>(script->GetData() + offset);
        offset += 2;
        if (!skipReference)
        {
            ScriptReferencedObject* object = script->GetReferencedForm(referenceID, m_pScriptLocals);
            if (object)
            {
                isVariable = object->m_uiFormID > 0;
                if (object->pForm)
                {
                    *reference = dynamic_cast<TESObjectREFR*>(object->pForm);
                }
            }
        }
        output = static_cast<SCRIPT_OUTPUT>(*reinterpret_cast<short*>(script->GetData() + offset));
        offset += 2;
        if (!skipReference && !*reference && !isVariable)
        {
            ScriptFunctionInfo* function = GetFunctionByOpcode(output);
            if (function)
            {
                SetErrorMessage(script,
                                "Unknown reference object for function '%s'.  Execution of script '%s' stopped.",
                                function->pFunctionName, script->GetName());
            }
            else
            {
                SetErrorMessage(script, "Unknown reference object.  Execution of script '%s' stopped.",
                                script->GetName());
            }
            return false;
        }
    }
    else
    {
        *reference = 0;
    }
    lineSize = *reinterpret_cast<short*>(script->GetData() + offset);
    offset += 2;
    return true;
}

// @fnv 0x005e1550
bool ScriptRunner::ParseBlock(Script* script, const SCRIPT_OUTPUT output, TESObjectREFR* reference, int& blockSize,
                              const unsigned int inputOffset, unsigned int& lineOffset, const unsigned int lineNumber,
                              bool skip, bool skipBlock)
{
    unsigned int offset = inputOffset;
    const char* data = script->GetData();
    if (output == SCRIPT_OUTPUT_FLOW_BEGIN)
    {
        int blockID = *reinterpret_cast<const short*>(data + offset);
        offset += 2;
        if (blockID < 0 || blockID >= kScriptBlockCount)
        {
            Warning("Invalid script block for BEGIN on line %i of script '%s' (%08X).", lineNumber, script->GetName(),
                    script->GetFormID());
            return false;
        }
        int skipSize = *reinterpret_cast<const int*>(data + offset);
        offset += 4;
        const ScriptParameter* blockParams = g_scriptBlocks[blockID].pParameters;
        FNVScriptExecuteFunction blockExecute = g_scriptBlocks[blockID].m_pfnExecute;
        if (skip)
        {
            if (blockParams && blockSize)
                ExtractArgs(blockParams, data, &offset, reference, m_pReference, script, m_pScriptLocals);
        }
        else
        {
            if (g_scriptBlocks[blockID].m_bRequiresReference && !reference)
            {
                Warning("SCRIPTS: Script '%s', line %d: Null for a required ref pointer.", script->GetName(),
                        lineNumber);
                return false;
            }
            double result;
            if (!blockExecute ||
                !blockExecute(blockParams, data, reference, m_pReference, script, m_pScriptLocals, result, offset))
            {
                Warning("SCRIPTS: Script '%s', line %d: Error Executing line (Offset %d).", script->GetName(),
                        lineNumber, offset);
                return false;
            }
            if (!result || skipBlock)
                blockSize += skipSize;
        }
    }
    else if (!skipBlock)
    {
        const ScriptFunctionInfo* function;
        switch (output)
        {
        case SCRIPT_OUTPUT_FLOW_SCRIPTNAME:
            break;
        case SCRIPT_OUTPUT_FLOW_BEGIN:
            break;
        case SCRIPT_OUTPUT_FLOW_END:
            break;
        case SCRIPT_OUTPUT_FLOW_SET: {
            char varType = data[offset];
            offset++;
            short variableID = 0;
            ScriptLocals* currentPScriptVariables = m_pScriptLocals;
            ScriptReferencedObject* referencedObject = 0;
            switch (varType)
            {
            case kScriptGlobalVariable:
            case kScriptReferenceVariable: {
                short referenceID = *reinterpret_cast<const short*>(data + offset);
                offset += 2;
                if (varType == kScriptReferenceVariable)
                {
                    varType = data[offset];
                    offset++;
                }
                referencedObject = script->GetReferencedForm(referenceID, m_pScriptLocals);
                if (!skip)
                {
                    if (varType != kScriptReferenceVariable && referencedObject && referencedObject->pForm)
                    {
                        TESObjectREFR* object = dynamic_cast<TESObjectREFR*>(referencedObject->pForm);
                        if (object)
                            currentPScriptVariables = object->GetReferenceLocals();
                        else
                        {
                            TESQuest* quest = dynamic_cast<TESQuest*>(referencedObject->pForm);
                            if (quest)
                                currentPScriptVariables = quest->GetScriptLocalData();
                        }
                        if (!currentPScriptVariables)
                        {
                            Warning("Missing script variables on object for SET on line %i of script '%s' (%08X).",
                                    lineNumber, script->GetName(), script->GetFormID());
                            return false;
                        }
                    }
                    else
                    {
                        Warning("Missing ref object in SET on line %i of script '%s' (%08X).", lineNumber,
                                script->GetName(), script->GetFormID());
                        return false;
                    }
                }
            }
            break;
            }
            switch (varType)
            {
            case kScriptGlobalVariable:
                break;
            default: {
                variableID = *reinterpret_cast<const short*>(data + offset);
                offset += 2;
            }
            break;
            }
            short expressionSize = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            ExpressionEvaluator variableExpression;
            double expressionValue = variableExpression.Eval(data + offset, reference, m_pReference, script,
                                                             m_pScriptLocals, expressionSize, skip);
            offset += expressionSize;
            if (variableExpression.ExpressionError())
            {
                Warning("SCRIPTS: Script '%s', line %d: Set expression returned an error: %s.\r\n", script->GetName(),
                        lineNumber, g_expressionErrorStrings[variableExpression.ExpressionError()]);
                script->GetHeader()->dataSize = 0;
                return false;
            }
            if (!skip)
            {
                if (varType == kScriptGlobalVariable)
                {
                    if (referencedObject && referencedObject->pForm)
                    {
                        if (!skip)
                        {
                            static_cast<TESGlobal*>(referencedObject->pForm)
                                ->SetValue(static_cast<float>(expressionValue));
                            if (IsScriptDebuggingEnabled())
                                DebugLog("set global >> %0.2f", static_cast<float>(expressionValue));
                        }
                    }
                    else
                    {
                        Warning("Invalid variable type for SET on line %i of script '%s' (%08X).", lineNumber,
                                script->GetName(), script->GetFormID());
                        return false;
                    }
                }
                else
                {
                    if (currentPScriptVariables)
                    {
                        switch (varType)
                        {
                        case kScriptLongVariable:
                        case kScriptShortVariable:
                            currentPScriptVariables->SetVariable(variableID, static_cast<int>(expressionValue));
                            if (IsScriptDebuggingEnabled())
                                DebugLog("set %s >> %i",
                                         currentPScriptVariables->m_pOwnerScript->GetVariableName(variableID),
                                         static_cast<int>(expressionValue));
                            break;
                        case kScriptFloatVariable:
                            currentPScriptVariables->SetVariable(variableID, expressionValue);
                            if (IsScriptDebuggingEnabled())
                                DebugLog("set %s >> %.2f",
                                         currentPScriptVariables->m_pOwnerScript->GetVariableName(variableID),
                                         expressionValue);
                            break;
                        }
                        if ((referencedObject && referencedObject->pForm) || reference)
                        {
                            TESObjectREFR* changedReference = 0;
                            if (referencedObject)
                            {
                                if (referencedObject->pForm && referencedObject->pForm->GetIsReference())
                                    changedReference = static_cast<TESObjectREFR*>(referencedObject->pForm);
                            }
                            else
                                changedReference = reference;
                            if (changedReference && !changedReference->IsTemporary())
                            {
                                if (!changedReference->GetParentCell() ||
                                    !changedReference->GetParentCell()->IsOutdoorCell())
                                    changedReference->MarkAsModified(TESObjectREFR::CHANGE_SCRIPT_VARIABLES);
                            }
                        }
                    }
                    else
                    {
                        Warning("Missing scriptvariables for object in SET on line %i of script '%s' (%08X).",
                                lineNumber, script->GetName(), script->GetFormID());
                        return false;
                    }
                }
            }
            break;
        }
        case SCRIPT_OUTPUT_FLOW_IF:
            if (m_aiIfStack[m_iIfStackDepth])
                m_iIfStackDepth++;
            m_aiIfStack[m_iIfStackDepth] = kScriptIfActiveFlag;
        case SCRIPT_OUTPUT_FLOW_ELSEIF: {
            short skipCount = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            short conditionSize = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            ExpressionEvaluator condition;
            if (skip)
            {
                condition.Eval(data + offset, reference, m_pReference, script, m_pScriptLocals, conditionSize, skip);
                m_aiIfStack[m_iIfStackDepth] |= kScriptIfConditionPassedFlag;
            }
            else
            {
                if (!(m_aiIfStack[m_iIfStackDepth] & kScriptIfConditionPassedFlag) &&
                    condition.Eval(data + offset, reference, m_pReference, script, m_pScriptLocals, conditionSize,
                                   skip))
                    m_aiIfStack[m_iIfStackDepth] |= kScriptIfConditionPassedFlag;
                else
                    lineOffset += skipCount;
            }
            if (condition.ExpressionError())
            {
                SetError(script, SCRIPT_ERROR_ERROR_SCRIPT_EXPRESSION);
                Warning("SCRIPTS: Script '%s', line %d: failed to evaluate expression.", script->GetName(), lineNumber);
                script->GetHeader()->dataSize = 0;
                m_eExpressionError = condition.ExpressionError();
                return false;
            }
            offset += conditionSize;
            break;
        }
        case SCRIPT_OUTPUT_FLOW_ELSE: {
            short skipCount = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            if (!(m_aiIfStack[m_iIfStackDepth] & kScriptIfConditionPassedFlag))
                m_aiIfStack[m_iIfStackDepth] |= kScriptIfConditionPassedFlag;
            else if (!skip)
                lineOffset += skipCount;
            break;
        }
        case SCRIPT_OUTPUT_FLOW_ENDIF:
            m_aiIfStack[m_iIfStackDepth] = 0;
            if (m_iIfStackDepth)
                m_iIfStackDepth--;
            break;
        case SCRIPT_OUTPUT_FLOW_REFERENCE_FUNCTION:
            break;
        case SCRIPT_OUTPUT_FLOW_RETURN:
            if (skip)
                break;
        default: {
            function = GetFunctionByOpcode(output);
            if (!function)
            {
                BSStringT<char> message;
                message.PrintfString("SCRIPTS: Unable to find function definition for command %d in script '%s'.", output,
                                script->GetName());
                if (IsScriptDebuggingEnabled())
                    DebugLog(PrepareScriptMessage(message.String(), false));
                else
                    Warning(PrepareScriptMessage(message.String(), false));
                return false;
            }
            else
            {
                const ScriptParameter* blockParams = function->pParameters;
                if (function->m_bRequiresReference && !reference && !skip)
                {
                    BSStringT<char> message;
                    message.PrintfString("SCRIPTS: Script '%s', line %d: Function '%s' requires a reference.",
                                    script->GetName(), lineNumber, function->pFunctionName);
                    if (IsScriptDebuggingEnabled())
                        DebugLog(PrepareScriptMessage(message.String(), false));
                    else
                        Warning(PrepareScriptMessage(message.String(), false));
                    return false;
                }
                if (skip)
                {
                    if (blockParams && blockSize)
                    {
                        ExtractArgs(blockParams, data, &offset, reference, m_pReference, script, m_pScriptLocals);
                        switch (output)
                        {
                        case SCRIPT_OUTPUT_FUNCTION_MESSAGE: {
                            short valueCount = *reinterpret_cast<const short*>(data + offset);
                            offset += 2;
                            for (short valueIndex = 0; valueIndex < valueCount; valueIndex++)
                            {
                                double expressionValue;
                                Script::GetValue(expressionValue, data, offset, reference, m_pReference, script,
                                                 m_pScriptLocals, true);
                            }
                            offset += 4;
                            break;
                        }
                        }
                    }
                }
                else
                {
                    FNVScriptExecuteFunction blockExecute = function->m_pfnExecute;
                    if (function->m_bSetsExecutionFlag)
                        m_bExecutionFlagSet = true;
                    double result;
                    if (!blockExecute || !blockExecute(blockParams, data, reference, m_pReference, script,
                                                       m_pScriptLocals, result, offset))
                    {
                        Warning("Failed to execute function '%s' on line %i of script '%s' (%08X).",
                                function->pFunctionName, lineNumber, script->GetName(), script->GetFormID());
                        return false;
                    }
                }
            }
        }
        }
    }
    return true;
}
