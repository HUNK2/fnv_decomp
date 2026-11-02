// gamebryo2.2/corelibs/nimain/nibillboardnode.cpp: NiBillboardNode (1 function)

class NiRTTI;

class NiBillboardNode
{
  public:
    static const NiRTTI ms_kRTTI;
    virtual const NiRTTI* GetRTTI() const;
};

// @fnv 0x0051cf90
const NiRTTI* NiBillboardNode::GetRTTI() const
{
    return &ms_kRTTI;
}
