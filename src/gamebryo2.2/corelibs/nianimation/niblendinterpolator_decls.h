// gamebryo2.2/corelibs/nianimation/niblendinterpolator_decls.h: declares NiObject, NiInterpolator, NiBlendInterpolator, InterpArrayItem, CloningProcess
#ifndef FNV_NIBLENDINTERPOLATOR_UNIT_DECLS_H
#define FNV_NIBLENDINTERPOLATOR_UNIT_DECLS_H


class CloningProcess;
class ShaderBufferRecord;
extern "C" const float fnvNegMax;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);

template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char* key, T& value);
};
template <> class NiTStringPointerMap<ShaderBufferRecord*>
{
  public:
    bool GetAt(const char* key, ShaderBufferRecord*& value);
};
typedef NiTStringPointerMap<ShaderBufferRecord*> NiShaderBufferPointerMap;

class NiObject
{
  public:
    virtual void Slot00()
    {}
    virtual void Slot01()
    {}
    virtual void Slot02()
    {}
    virtual void Slot03()
    {}
    virtual void Slot04()
    {}
    virtual void Slot05()
    {}
    virtual void Slot06()
    {}
    virtual void Slot07()
    {}
    virtual void Slot08()
    {}
    virtual void Slot09()
    {}
    virtual void Slot10()
    {}
    virtual void Slot11()
    {}
    virtual void Slot12()
    {}
    virtual void Slot13()
    {}
    virtual void Slot14()
    {}
    virtual void Slot15()
    {}
    virtual void Slot16()
    {}
    virtual void Slot17()
    {}
    virtual void Slot18()
    {}
    virtual void Slot19()
    {}
    virtual void Slot20()
    {}
    virtual void Slot21()
    {}
    virtual void Slot22()
    {}
    virtual void Slot23()
    {}
    virtual void Slot24()
    {}
    virtual void Slot25()
    {}
    virtual void ProcessClone(CloningProcess& process);

  private:
    unsigned int m_uiRefCount;
};

class NiInterpolator : public NiObject
{
  public:
    float m_fLastTime;
};

class NiBlendInterpolator;
class NiBlendInterpolator : public NiInterpolator
{
  public:
    class InterpArrayItem
    {
      public:
        NiInterpolator* m_spControllerInterpolator;
        float m_fWeight;
        float m_fNormalizedWeight;
        char m_cPriority;
        unsigned char padding[3];
        float m_fEaseSpinner;
        float m_fLastEvaluationTime;
    };

    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    char m_cHighPriority;
    char m_cNextHighPriority;
    unsigned char padding[2];
    InterpArrayItem* m_pInterpArray;
    NiInterpolator* m_pSingleInterpolator;
    float m_fWeightThreshold;
    float m_fSingleInterpolatorTime;
    float m_fHighSumOfWeights;
    float m_fNextHighSumOfWeights;
    float m_fTrailingValue;

    unsigned char AddInterpolatorItem(NiInterpolator* interpolator, float weight, char priority, float updateTime);
    void RemoveInterpolatorAt(unsigned char index);
    virtual void ProcessClone(CloningProcess& process);
};
typedef NiBlendInterpolator::InterpArrayItem NiBlendInterpolator_InterpArrayItem;

class CloningProcess
{
  public:
    NiTStringPointerMap<ShaderBufferRecord*>* m_pCloneMap;
};

#endif
