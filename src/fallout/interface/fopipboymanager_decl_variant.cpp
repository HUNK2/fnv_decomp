
// src/fallout/interface/fopipboymanager_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x007f8720: the skeleton of src/fallout/interface/fopipboymanager.cpp
// with declarations corrected to what the original code does (fopipboymanager_decls.h: FOPipboyManager += bool FUN_007f8720(bool press, bool release, float& x, float& y, int& button); NiAVObject* FUN_007fa950();; fopipboymanager_decls.h: class NiPoint3 { public: float x,y,z; NiPoint3(flo -> class NiPoint3 { public: float x,y,z; NiPoint3(flo; fopipboymanager_de). Move the function to its real unit once
// that unit declares it this way.

#include "fopipboymanager_decls_decl_fopipboymanager.h"

class NiPoint2
{
  public:
    float x, y;
};
class NiPick
{
  public:
    class Record
    {
      public:
        NiPointer<NiAVObject> object;
        NiPointer<NiNode> proxy;
        NiPoint3 intersect;
        float distance;
        unsigned short triangle, vertices[3];
        float texture[2];
        NiPoint3 normal;
        float color[4];
        NiAVObject* FUN_00458b50();
        const NiPoint2* FUN_00891170();
    };
    class Results
    {
      public:
        virtual ~Results();
        Record** data;
        unsigned short capacity, size, effective, grow;
        unsigned int valid;
        Record* FUN_00968670(unsigned int);
    };
    int pickType, sortType, intersectType, coordinateType;
    bool frontOnly, observeCull;
    NiPointer<NiAVObject> root;
    Results results;
    Record* last;
    bool returnTexture, returnNormal, smoothNormal, returnColor;
    NiPick(int, int);
    ~NiPick();
    void SetByteAtOffset17(bool);
    void FUN_00705fc0(NiAVObject*);
    void FUN_006ecd40(int);
    void SetByteAtOffset30(bool);
    bool FUN_00e98e20(const NiPoint3&, const NiPoint3&, bool);
    Results* FUN_00500940();
};
class NiCamera
{
  public:
    void MapScreenToRay(int, int, NiPoint3&, NiPoint3&, bool);
};
class SceneGraph
{
  public:
    NiCamera* FUN_006629f0();
};
SceneGraph* FUN_0045c670();
bool FUN_007178a0();
bool FUN_00717920();
double FUN_00706e20();
extern int DAT_011a0ba0;
// @fnv 0x007f8720
bool FOPipboyManager::FUN_007f8720(bool press, bool release, float& x, float& y, int& button)
{
    bool result = false;
    Interface* ui = Interface::InterfaceManager_Instance();
    if (!FUN_007fa950() || !(NiAVObject*)m_cPipBoyButtonAvailability[0] ||
        !(NiAVObject*)m_cPipBoyButtonAvailability[1] || !(NiAVObject*)m_cPipBoyButtonAvailability[2])
        return false;
    if (FUN_007178a0() && FUN_00717920() && (NiNode*)m_pPipBoyObject0)
    {
        NiPoint3 origin;
        NiPoint3 c;
        NiPick b(0, 8);
        b.SetByteAtOffset17(true);
        b.FUN_00705fc0(FUN_007fa950());
        b.FUN_006ecd40(0);
        b.SetByteAtOffset30(true);
        NiCamera* a = FUN_0045c670()->FUN_006629f0();
        a->MapScreenToRay((int)ui->FUN_009a9350(), (int)ui->FUN_00792760(), origin, c, false);
        if (b.FUN_00e98e20(origin, c, false))
        {
            unsigned int firstIndex = 0;
            NiPick::Record* hit = b.FUN_00500940()->FUN_00968670(firstIndex);
            if (hit && hit->FUN_00458b50() == FUN_007fa950())
            {
                NiPoint2 horizontal = *hit->FUN_00891170();
                float scale = FUN_00706e20();
                float uv = scale * (double)1.333333f;
                x = horizontal.x * uv;
                y = horizontal.y * scale;
                result = true;
            }
        }
        if (press || release)
        {
            int selected = -1;
            b.FUN_006ecd40(0);
            b.SetByteAtOffset30(false);
            for (int i = 0; i < 3; i++)
            {
                b.FUN_00705fc0(m_cPipBoyButtonAvailability[i]);
                FUN_0045c670()->FUN_006629f0()->MapScreenToRay((int)ui->FUN_009a9350(), (int)ui->FUN_00792760(), origin,
                                                               c, false);
                if (b.FUN_00e98e20(origin, c, false))
                {
                    unsigned int hit = 0;
                    NiPick::Record* hitIndex = b.FUN_00500940()->FUN_00968670(hit);
                    if (hitIndex)
                    {
                        if (press)
                            DAT_011a0ba0 = i;
                        else
                            selected = i;
                    }
                }
            }
            if (release && selected == DAT_011a0ba0)
            {
                button = selected + 1;
                DAT_011a0ba0 = -1;
            }
        }
    }
    return result;
}
