
class EffectItem
{
  public:
    int m_iMagnitude;
    int m_iArea;
    int m_iPayloadInteger;
    int m_eRange;
    int m_eAssociatedActorValue;

    bool EffectItem_IsActorValueUsed();
    int GetAffectedActorValue();
};

int EffectItem::GetAffectedActorValue()
{
    return EffectItem_IsActorValueUsed() ? m_eAssociatedActorValue : -1;
}
