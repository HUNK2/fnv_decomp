// This instantiation uses the canonical folded smart-pointer lifetime routines.
class ObstacleData;
template <> class NiPointer<ObstacleData>
{
  public:
    ObstacleData* m_pObject;
    NiPointer(const NiPointer&);
    ~NiPointer();
};
