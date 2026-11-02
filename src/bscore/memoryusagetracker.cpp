// bscore/memoryusagetracker.cpp: AutoMemContext (1 function)
class AutoMemContext
{
  public:
    void Leave();
    ~AutoMemContext();
};

// @fnv 0x00404ee0
AutoMemContext::~AutoMemContext()
{
    Leave();
}
