
class EffectItem
{
  public:
    int m_iMagnitude;
    int m_iArea;
    int m_iPayloadInteger;
    int m_eRange;
    int m_eAssociatedActorValue;

    bool FUN_00403ee0();
    int GetAffectedActorValue();
};

int EffectItem::GetAffectedActorValue()
{
    return FUN_00403ee0() ? m_eAssociatedActorValue : -1;
}
