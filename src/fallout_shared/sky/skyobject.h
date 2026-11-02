// Authored declarations for the SkyObject unit
// (fallout_shared/sky/skyobject.cpp). The canonical generated headers do not
// carry this class yet, so the translation unit stays self-contained; member
// names, the protected m_pRootNode member and the introducing virtuals come from
#ifndef FNV_SKYOBJECT_H
#define FNV_SKYOBJECT_H


class NiNode;

// Shared engine pointer template. Construction, destruction, conversion and
// assignment stay out of line; the PC engine bodies are separate functions
// rather than inlined template code.
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* pObject = 0);
    ~NiPointer();
    operator T*() const;
    NiPointer& operator=(T* pObject);
};

class Sky;

class SkyObject
{
  public:
    SkyObject();
    virtual ~SkyObject();

    // @fnv 0x0063f830 declares the SkyObject constructor; the remaining
    virtual NiNode* GetRoot();
    virtual void Initialize(NiNode* pRoot);
    virtual void Update(Sky* pWeatherSky, float fSeconds);

    void SetDisplayObject(bool bDisplay);

  protected:
    NiPointer<NiNode> m_pRootNode;  // +0x4
};

#endif
