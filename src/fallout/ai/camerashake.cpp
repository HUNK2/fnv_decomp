// fallout/ai/camerashake.cpp: FileFinder, Interface (4 functions)

#include "camerashake_decls.h"
// Clears DAT_011dfecc, builds the CameraShake.nif path, and if it exists loads it via g_modelLoader and sets its name.
// @fnv 0x008d1820
void InitializeCameraShake()
{
    char path[260];
    DAT_011dfecc = 0;
    sprintf_s(path, 260, "%s\\Characters\\CameraShake.nif", "Meshes");
    if (FileFinder::Exist(path, 0, 0, -1))
    {
        DAT_011dfecc = g_modelLoader->LoadFile(path, 0, true, false, false, false);
        DAT_011dfecc->SetName(NiFixedString(path));
    }
}

struct NiFixedStr
{
    operator const char*() const;
};
struct SeqObj
{
    NiFixedStr& GetName();
};
struct ModelLoader_target
{
    void FUN_0045a5e0(const char*);
};
// If DAT_011dfecc is set, passes its GetName() string to g_modelLoader's FUN_0045a5e0 and clears DAT_011dfecc.
// @fnv 0x008d1920
void FUN_008d1920()
{
    if (DAT_011dfecc)
    {
        ((ModelLoader_target*)g_modelLoader)->FUN_0045a5e0((const char*)((SeqObj*)DAT_011dfecc)->GetName());
        DAT_011dfecc = 0;
    }
}

class NiPoint3
{
  public:
    float x;
    float y;
    float z;
    NiPoint3 operator-(const NiPoint3& arPoint) const;
    float Length() const;
};

class SettingFloat
{
  public:
    float* Float();
};

struct Controls
{
    void FUN_00a255b0(float afLeft, float afRight, int aiDuration, int aiArg3, int aiArg4, int aiArg5, int aiArg6);
};

struct OSGlobals
{
    Controls* FUN_00877720();
};

struct Interface
{
    static bool IsSaveLoadActive();
};

struct FUN_0043c490_shell
{
    NiPoint3& FUN_0043c490();
};

struct FUN_00558310_node;
FUN_00558310_node* FUN_0045c670();
FUN_0043c490_shell* __fastcall FUN_00558310(FUN_00558310_node* apNode);

extern SettingFloat originalRuntimeFloatSetting1063;
extern SettingFloat originalRuntimeFloatSetting1065;
extern SettingFloat originalRuntimeFloatSetting1066;
extern SettingFloat originalRuntimeFloatSetting1067;
extern SettingFloat g_011d064c;
extern SettingFloat g_011d09dc;
extern SettingFloat g_011d0b3c;
extern OSGlobals* g_osGlobals;
extern float DAT_011dfed4;
extern float DAT_011dfed8;

// @fnv 0x008d1960
void UpdateDistanceFade(float afMult, const NiPoint3& arPos)
{
    float fdelta;
    float fFadeDelta;
    float fFadeStart;
    NiPoint3 cameraPos;

    if (DAT_011dfecc && afMult > 0.0)
    {
        cameraPos = FUN_00558310(FUN_0045c670())->FUN_0043c490();
        fdelta = (cameraPos - arPos).Length();
        fFadeStart = *originalRuntimeFloatSetting1066.Float() * afMult;
        fFadeDelta = *originalRuntimeFloatSetting1067.Float() * afMult;
        if (fFadeStart < *originalRuntimeFloatSetting1065.Float())
            fFadeStart = *originalRuntimeFloatSetting1065.Float();
        if (fFadeStart + fFadeDelta > fdelta)
        {
            if (fdelta > fFadeStart)
                afMult = (1.0f - (fdelta - fFadeStart) / fFadeDelta) * afMult;
            if (afMult > 1.0)
                afMult = 1.0f;
            else if (afMult < *g_011d09dc.Float())
                afMult = *g_011d09dc.Float();
            DAT_011dfed4 = afMult;
            DAT_011dfed8 = *originalRuntimeFloatSetting1063.Float();
            if (!Interface::IsSaveLoadActive())
            {
                Controls* pcontrols = g_osGlobals->FUN_00877720();
                pcontrols->FUN_00a255b0(DAT_011dfed4 * *g_011d0b3c.Float(), DAT_011dfed4 * *g_011d0b3c.Float(),
                                        (int)(DAT_011dfed8 * 1000.0 * *g_011d064c.Float()), 0, 0, 0, 0);
            }
        }
    }
}

struct NiUpdateData
{
    float time;
    bool update;
    bool flags;
    int unk08;
    NiUpdateData(float, bool, bool);
};
struct MatrixView
{
    float entries[9];
    MatrixView FUN_004b45b0() const;
    MatrixView FUN_0043f8d0(const MatrixView&) const;
};
struct ControllerView
{
    float FUN_0047c860();
};
struct CameraView
{
    ControllerView* FUN_0043b230();
    void FUN_00a59c60(NiUpdateData&);
    MatrixView& FUN_006a9540();
};
struct TimeView
{
    float FUN_0084d030();
};
extern TimeView DAT_011f6394;
extern SettingFloat g_011d08b0;
// Advances a camera shake timer, samples the camera controller matrix into output, and returns the current shake amount.
// @fnv 0x008d1b30
float UpdateCameraShake(float time, MatrixView* output)
{
    if (DAT_011dfecc && DAT_011dfed4 != 0.0 && DAT_011dfed8 != 0.0)
    {
        ControllerView* second = ((CameraView*)DAT_011dfecc)->FUN_0043b230();
        float position = second->FUN_0047c860();
        NiUpdateData first(position, true, false);
        ((CameraView*)DAT_011dfecc)->FUN_00a59c60(first);
        MatrixView controller = ((CameraView*)DAT_011dfecc)->FUN_006a9540();
        NiUpdateData old(time, true, false);
        ((CameraView*)DAT_011dfecc)->FUN_00a59c60(old);
        *output = controller.FUN_004b45b0().FUN_0043f8d0(((CameraView*)DAT_011dfecc)->FUN_006a9540());
        DAT_011dfed8 -= DAT_011f6394.FUN_0084d030();
        if (DAT_011dfed8 < 0.0)
        {
            DAT_011dfed8 = 0.0f;
            DAT_011dfed4 = 0.0f;
        }
        else if (DAT_011dfed8 < *g_011d08b0.Float())
            return DAT_011dfed4 * DAT_011dfed8 / *g_011d08b0.Float();
    }
    else if (DAT_011dfed8 != 0.0 || DAT_011dfed4 != 0.0)
    {
        DAT_011dfed8 = 0.0f;
        DAT_011dfed4 = 0.0f;
    }
    return DAT_011dfed4;
}
