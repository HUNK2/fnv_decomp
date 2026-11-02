// fallout_shared/tessound.cpp: TESSound (4 functions)

#include "tessound.h"
#include <malloc.h>

const char kTESSoundFileLabel[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSound.cpp";

// Source line of the default-objects context in the original PC file (0x559).
enum
{
    kGenerateDefaultObjectsSourceLine = 0x559
};

// @fnv 0x005e2ef0
void TESSound::ResetFormData()
{
    data.iFlags = 0;
    data.iMax = 0;
    data.iMin = 0;
    data.m_cPitchAdjustment = 0;
    data.m_uiFrequency = 0;
    data.m_ucUnused = 0;
    data.m_aucAttenuationBytes = 0;
    data.m_auiAttenuationCurve[0] = 100;
    data.m_auiAttenuationCurve[1] = 50;
    data.m_auiAttenuationCurve[2] = 20;
    data.m_auiAttenuationCurve[3] = 5;
    data.m_auiAttenuationCurve[4] = 0;
    data.m_uiReverbAttenuation = 80;
    data.m_uiTrailingValue1 = 0;
    data.m_uiTrailingValue2 = 0;
    data.iPriority = 128;
}

// @fnv 0x005e3600
void TESSound::InitializeMagicSystem()
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TES_DEFAULT_OBJECTS, true, kTESSoundFileLabel,
                           kGenerateDefaultObjectsSourceLine);
}

// @fnv 0x005e2b70
TESSound::TESSound()
{
    SetFormType(ENUM_FORM_ID_SOUN_ID);
    m_cSoundFlag = 0;
    ResetFormData();
}

// Loads a SOUN record: reads the header, then handles EDID, OBND, FNAM, RNAM, SNDD, SNDX, ANAM, GNAM and HNAM chunks, converting endianness where required.
// @fnv 0x005e3160
bool TESSound::Load(TESFile* file)
{
    if (static_cast<TESFileFormInt*>(file)->GetTESForm() != ENUM_FORM_ID_SOUN_ID)
        return false;
    LoadRecordHeader(file);
    int iChunkID;
    while ((iChunkID = file->GetChunkID()) != 0)
    {
        switch (iChunkID)
        {
        case 0x44494445:  // EDID
        {
            char* pChunkBuffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(pChunkBuffer, 0x200);
            SetEditorID_AtRuntime(pChunkBuffer);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4D414E46:  // FNAM
        {
            char* pChunkBuffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(pChunkBuffer, 0);
            SetSoundFile(pChunkBuffer);
            break;
        }
        case 0x4D414E52:  // RNAM
            ReadTypedData(file, &m_cSoundFlag, sizeof(m_cSoundFlag));
            break;
        case 0x44444E53:  // SNDD
            ReadTypedData(file, &data, sizeof(data));
            if (file->IsEndianConversionRequired())
                data.Endian();
            break;
        case 0x58444E53:  // SNDX
        {
            TESSound__SOUND_DATA2 oldSoundData;
            ReadTypedData(file, &oldSoundData, sizeof(oldSoundData));
            if (file->IsEndianConversionRequired())
                oldSoundData.Endian();
            data.iMin = oldSoundData.iMin;
            data.iMax = oldSoundData.iMax;
            data.m_cPitchAdjustment = oldSoundData.m_cPitchAdjustment;
            data.iFlags = oldSoundData.iFlags;
            data.m_uiFrequency = oldSoundData.m_uiFrequency;
            data.m_aucAttenuationBytes = oldSoundData.m_aucAttenuationBytes;
            break;
        }
        case 0x4D414E41:  // ANAM
            ReadTypedData(file, data.m_auiAttenuationCurve, sizeof(data.m_auiAttenuationCurve));
            if (file->IsEndianConversionRequired())
            {
                BSEndian(&data.m_auiAttenuationCurve[0], EndianSizeTag<2>());
                BSEndian(&data.m_auiAttenuationCurve[1], EndianSizeTag<2>());
                BSEndian(&data.m_auiAttenuationCurve[2], EndianSizeTag<2>());
                BSEndian(&data.m_auiAttenuationCurve[3], EndianSizeTag<2>());
                BSEndian(&data.m_auiAttenuationCurve[4], EndianSizeTag<2>());
            }
            if (data.m_auiAttenuationCurve[0] == 100 && data.m_auiAttenuationCurve[1] == 75 &&
                data.m_auiAttenuationCurve[2] == 50 && data.m_auiAttenuationCurve[3] == 25 &&
                data.m_auiAttenuationCurve[4] == 0)
            {
                data.m_auiAttenuationCurve[0] = 100;
                data.m_auiAttenuationCurve[1] = 50;
                data.m_auiAttenuationCurve[2] = 20;
                data.m_auiAttenuationCurve[3] = 5;
                data.m_auiAttenuationCurve[4] = 0;
            }
            break;
        case 0x4D414E47:  // GNAM
            ReadTypedData(file, &data.m_uiReverbAttenuation, sizeof(data.m_uiReverbAttenuation));
            break;
        case 0x4D414E48:  // HNAM
            ReadTypedData(file, &data.iPriority, sizeof(data.iPriority));
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}
