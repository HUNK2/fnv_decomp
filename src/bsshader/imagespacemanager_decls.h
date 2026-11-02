// bsshader/imagespacemanager_decls.h: declares NiUpdateData, ImageSpaceManagerNameString, NiAVObject, NiScreenElements, ImageSpaceManagerScreenGeometry
#ifndef FNV_IMAGESPACEMANAGER_DECLS_H
#define FNV_IMAGESPACEMANAGER_DECLS_H

#include "NiFixedString.h"
class NiGlobalStringTable;
class NiScreenElementsData;
extern NiFixedString EmptyFS;
extern volatile unsigned int DAT_011f91ac;
extern float DAT_010162c0;
extern float DAT_0104a494;
extern const char DAT_010b04ac[];
void* Allocate(unsigned int size);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

class NiUpdateData
{
  public:
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
};

class ImageSpaceManagerNameString
{
  public:
    char* m_kHandle;
    explicit ImageSpaceManagerNameString(const char* value) : m_kHandle(NiGlobalStringTable::AddString(value))
    {}
    ~ImageSpaceManagerNameString()
    {
        if (m_kHandle != EmptyFS.m_kHandle)
            InterlockedDecrement((volatile long*)(m_kHandle - 8));
    }
};

class NiAVObject : public NiRefObject
{
  public:
    unsigned char padding[0xb0];
    void SetName(const NiFixedString& name);
    void UpdateSceneObject();
    void Update(NiUpdateData& data);
};

class NiScreenElements : public NiAVObject
{
  public:
    NiScreenElementsData* m_spGeometryData;
    unsigned char tail_padding[8];
};

class ImageSpaceManagerScreenGeometry
{
  public:
    unsigned char padding[0xb8];
    NiScreenElementsData* m_spGeometryData;
    unsigned char tail_padding[8];
    static void* __cdecl operator new(unsigned int size) throw();
    ImageSpaceManagerScreenGeometry(NiScreenElementsData* data)
    {
        FUN_00a87810(data);
    }
    ImageSpaceManagerScreenGeometry* FUN_00a87810(NiScreenElementsData* data);
};
#endif
