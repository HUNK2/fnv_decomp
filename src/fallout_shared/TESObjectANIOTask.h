// fallout_shared/TESObjectANIOTask.h: declares TESForm, TESModelTextureSwap, TESObjectANIO
#ifndef LUNA_TESOBJECTANIO_TASK_H
#define LUNA_TESOBJECTANIO_TASK_H

class TESFile;
class TESForm
{
  public:
    virtual ~TESForm();
    virtual void InitItem();
    char baseData[0x14];
    bool IsFormInitialized() const;
    void SetInitializationState(bool initialized);
    TESFile* GetFile(int fileIndex);
    static void RemapFormIDForFile(unsigned int& formID, TESFile* file);
    static TESForm* GetFormByID(unsigned int formID);
};
class TESModelTextureSwap
{
  public:
    void InitItem(TESForm* form);
};
class TESObjectANIO : public TESForm
{
  public:
    char modelTextureSwapData[0x20];
    TESObjectANIO* pObject;
    virtual void InitItem();
};
#endif
