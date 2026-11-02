// fallout_shared/sky/sun_decls.h: declares SkyObject, BSShaderManager, BSShaderAccumulator, Sun
#ifndef SUN_DECLS_H
#define SUN_DECLS_H

class NiAVObject;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* object = 0);
    ~NiPointer();
    NiPointer& operator=(T* object);
};
class SkyObject
{
  public:
    SkyObject();
    virtual ~SkyObject();
    NiPointer<NiAVObject> m_pRootNode;
};
class BSShaderManager
{
  public:
    enum BATCHRENDERER_CREATION_MODE
    {
        SunMode = 100
    };
};
class BSShaderAccumulator
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    BSShaderAccumulator(BSShaderManager::BATCHRENDERER_CREATION_MODE, unsigned int, unsigned int);
    char data[0x280];
};
class Sun : public SkyObject
{
  public:
    Sun();
    virtual ~Sun();
    NiPointer<NiAVObject> m_pFirstSceneObject, m_pSecondSceneObject, m_pThirdSceneObject, m_pFourthSceneObject;
    void* m_pSunGlarePick;
    NiPointer<NiAVObject> m_pMenuLight;
    float m_fSunGlareIntensity;
    bool bDoOcclusionTests;
    NiPointer<NiAVObject> m_pSunShaderAccumulator;
};
#endif
