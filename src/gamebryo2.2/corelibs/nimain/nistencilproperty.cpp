// gamebryo2.2/corelibs/nimain/nistencilproperty.cpp: NiStencilProperty (1 function)

class NiRTTI;

class NiStencilProperty
{
  public:
    static const NiRTTI ms_kRTTI;
    virtual const NiRTTI* GetRTTI() const;
};

// @fnv 0x0049ed30
const NiRTTI* NiStencilProperty::GetRTTI() const
{
    return &ms_kRTTI;
}
