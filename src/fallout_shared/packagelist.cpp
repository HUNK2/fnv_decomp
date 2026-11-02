// fallout_shared/packagelist.cpp: PackageList, TESAIForm (10 functions)

#include "packagelist_decls.h"
template <class T> class BSSimpleList
{
  public:
    void RemoveAll();
    void AddHead(T&);
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    void SetItem(T const& item);
    void Remove(T const& item);
    void RemoveHead();
    bool IsInList(T& item);
    void AddTail(T const& item);
    unsigned int ItemsInList();
};

class PackageList
{
  public:
    BSSimpleList<TESPackage*>* GetListOfPackages();
    void Copy(const PackageList* src);
    void ClearPackageList();
    TESPackage* GetPackageForActor(Actor* actor);
    void CollectEligiblePackages(Actor*, BSSimpleList<TESPackage*>*, float, float);
    void InitItem(TESForm*);
    void AddPackage(TESPackage*);
    BSSimpleList<TESPackage*>* GetListOfPackages() const;
};

class TESAIForm
{
  public:
    PackageList* GetPackageList();
    const PackageList* GetPackageList() const;
    void CopyAIPackageList(const TESAIForm* src);
};

// @fnv 0x0067e400
void PackageList::ClearPackageList()
{
    GetListOfPackages()->RemoveAll();
}

// Copies the package list from src into this form's package list.
// @fnv 0x0047f2d0
void TESAIForm::CopyAIPackageList(const TESAIForm* src)
{
    GetPackageList()->Copy(src->GetPackageList());
}

// Scans the package list for a package whose conditions and schedule match the actor, logs the pick, updates extra data and process state, and returns it.
// @fnv 0x0067e780
TESPackage* PackageList::GetPackageForActor(Actor* actor)
{
    struct PackageSelection
    {
        TESPackage* package;
        DurationData* schedule;
        TESPackage* current;
        BSSimpleList<TESPackage*>* list;
    } selection;
    char message[300];
    selection.list = GetListOfPackages();
    selection.current = 0;
    if (actor)
        selection.current = actor->GetCurrentPackage();
    if (!selection.list->IsEmpty())
    {
        selection.package = 0;
        selection.schedule = 0;
        while (selection.list && (selection.package = selection.list->GetItem()))
        {
            if ((selection.package->vfn_138(actor) && !selection.package->IsFlag10000Set() &&
                 !selection.package->IsMustReachLocation()) ||
                (selection.package->IsMustReachLocation() &&
                 !actor->GetExtraData()->CanReachPackageLocation(selection.package)))
            {
                selection.schedule = selection.package->FUN_0041d8a0();
                if (selection.schedule)
                {
                    bool bCalendarMonth;
                    bool bDayOfMonth;
                    bool bDayOfWeek;
                    bDayOfWeek = false;
                    bDayOfMonth = false;
                    bCalendarMonth = false;
                    if (selection.schedule->FUN_0086a460() + selection.schedule->FUN_00726070() > 24)
                    {
                        bDayOfWeek = selection.package->IsScheduledForDay(true);
                        int yesterday = g_calendar.GetGameHour() - 1;
                        if (yesterday < 0)
                            yesterday = 30;
                        if (selection.schedule->FUN_00678ce0() == yesterday)
                            bDayOfMonth = true;
                        int lastMonth = g_calendar.GetCurrentMonth() - 1;
                        if (lastMonth < 0)
                            lastMonth = 12;
                        if (selection.schedule->FUN_00678ca0() == lastMonth)
                            bCalendarMonth = true;
                    }
                    if ((selection.schedule->FUN_00678ca0() == -1 ||
                         selection.schedule->FUN_00678ca0() == g_calendar.GetCurrentMonth() || bCalendarMonth) &&
                        (selection.schedule->FUN_00678ce0() == 0 ||
                         selection.schedule->FUN_00678ce0() == g_calendar.GetGameHour() || bDayOfMonth) &&
                        (selection.schedule->GetSecondByte() == -1 || selection.package->IsScheduledForDay(false) ||
                         bDayOfWeek) &&
                        (selection.schedule->FUN_0086a460() == -1 ||
                         IsHourInRange(selection.schedule->FUN_0086a460(), selection.schedule->FUN_00726070(),
                                       g_calendar.GetGameTime())))
                    {
                        struct PackageTargetState
                        {
                            PackageTargetRecord* packageTarget;
                            TESObjectREFR* reference;
                        } targetState;
                        targetState.reference = 0;
                        targetState.packageTarget = selection.package->GetTarget();
                        if (targetState.packageTarget)
                            targetState.reference = targetState.packageTarget->GetReferenceTarget();
                        if (selection.package->GetConditions()->ContainsTrait(actor, targetState.reference))
                        {
                            if (FUN_00703180() == actor)
                            {
                                sprintf(
                                    message, "%s Picked Package %s (%s)", actor->GetFullName(),
                                    PrepareScriptMessage(g_packageTypeNames[selection.package->GetPackType()], false),
                                    PrepareScriptMessage(selection.package->GetName(), false));
                                DebugLog(message);
                            }
                            if (selection.package->GetProcedureType() == -1)
                                selection.package->SetTargetFromReference(actor->GetLinkedRef());
                            if (selection.current && selection.current != selection.package &&
                                selection.current->GetPackType() == 1)
                            {
                                Actor* leader = dynamic_cast<Actor*>(actor->GetProcess()->GetLowProcess40());
                                if (leader)
                                    leader->GetExtraData()->AddFollowerActor(actor);
                            }
                            if (selection.current && selection.current != selection.package)
                            {
                                Script::GetLocalData(selection.current, actor->GetExtraData(), 0x800);
                                actor->GetProcess()->HandleOnPackageChange(actor, selection.current);
                                actor->GetProcess()->vfn_5a8(0);
                            }
                            if (selection.package && selection.package != selection.current)
                                Script::GetLocalData(selection.package, actor->GetExtraData(), 0x200);
                            return selection.package;
                        }
                    }
                }
            }
            selection.list = selection.list->GetNext();
        }
    }
    return selection.current;
}

// Scans packages over the coming days/hours, adds those whose schedule matches and are not current or already missed, then sorts the missed list by schedule.
// @fnv 0x0067ec40
void PackageList::CollectEligiblePackages(Actor* actor, BSSimpleList<TESPackage*>* pMissedList, float elapsed,
                                          float startHour)
{
    struct CalendarScan
    {
        float hour;
        int day;
        int currentMonth;
        int month;
        int year;
    } scan;
    struct MissedPackageContext
    {
        int today;
        TESPackage* current;
        BSSimpleList<TESPackage*>* cursor;
    } sortCtx;
    sortCtx.current = 0;
    scan.day = actor->GetProcess()->vfn_30();
    scan.month = actor->GetProcess()->vfn_34();
    scan.year = actor->GetProcess()->vfn_38();
    scan.hour = startHour;
    sortCtx.today = g_calendar.GetGameHour();
    scan.currentMonth = g_calendar.GetCurrentMonth();
    while (scan.day)
    {
        BSSimpleList<TESPackage*>* pList = GetListOfPackages();
        if (actor)
            sortCtx.current = actor->GetCurrentPackage();
        if (!pList->IsEmpty())
        {
            TESPackage* pPackage = 0;
            DurationData* pSchedule = 0;
            while (pList && (pPackage = pList->GetItem()))
            {
                if (pPackage->FUN_0067efd0() && pPackage->FUN_00677760(actor))
                {
                    pSchedule = pPackage->FUN_0041d8a0();
                    if (pSchedule && (pSchedule->FUN_00678ca0() == -1 || pSchedule->FUN_00678ca0() <= scan.month) &&
                        (pSchedule->FUN_00678ce0() == 0 || pSchedule->FUN_00678ce0() <= scan.day) &&
                        (pSchedule->GetSecondByte() == -1 ||
                         pSchedule->GetSecondByte() <= g_calendar.GetGameDayOfWeek()) &&
                        (pSchedule->FUN_0086a460() == -1 || pSchedule->FUN_0086a460() < scan.hour) &&
                        pPackage != sortCtx.current && !pMissedList->IsInList(pPackage))
                    {
                        if (pPackage->GetProcedureType() == -1)
                            pPackage->SetTargetFromReference(actor->GetLinkedRef());
                        pMissedList->AddTail(pPackage);
                    }
                }
                pList = pList->GetNext();
            }
            scan.hour += 1.0;
            if (scan.hour > 23.0)
            {
                ++scan.day;
                scan.hour = 0;
                unsigned short usDaysInMonth = GetShortFromTable((signed char)scan.month);
                if (scan.day > usDaysInMonth)
                {
                    scan.day -= usDaysInMonth;
                    ++scan.month;
                    if (scan.month >= 12)
                    {
                        scan.month -= 12;
                        ++scan.year;
                    }
                }
            }
            if (scan.day == sortCtx.today && scan.month == scan.currentMonth &&
                (int)scan.hour >= (int)g_calendar.GetGameTime())
                scan.day = 0;
        }
        else
            scan.day = 0;
    }
    sortCtx.cursor = pMissedList;
    BSSimpleList<TESPackage*>* pNext = 0;
    if (sortCtx.cursor)
    {
        unsigned int iCount = sortCtx.cursor->ItemsInList();
        bool bSwapped = true;
        while (iCount && bSwapped)
        {
            bSwapped = false;
            pNext = sortCtx.cursor;
            while (pNext)
            {
                TESPackage* pPackage1 = sortCtx.cursor->GetItem();
                TESPackage* pPackage2 = pNext->GetItem();
                if (pPackage1->CompareTo(pPackage2->FUN_0041d8a0()) == 1)
                {
                    sortCtx.cursor->SetItem(pPackage2);
                    pNext->SetItem(pPackage1);
                    bSwapped = true;
                }
                pNext = pNext->GetNext();
            }
            sortCtx.cursor = sortCtx.cursor->GetNext();
            --iCount;
        }
    }
}

// Resolves each package form ID in the package list to a TESPackage, warning and removing entries that cannot be found.
// @fnv 0x0067e560
void PackageList::InitItem(TESForm* form)
{
    struct PackageResolutionCursor
    {
        BSSimpleList<TESPackage*>* list;
        BSSimpleList<TESPackage*>* previous;
        TESFile* file;
    } cursor;
    cursor.list = GetListOfPackages();
    cursor.previous = 0;
    cursor.file = form ? form->GetFile(-1) : 0;
    while (cursor.list && !cursor.list->IsEmpty())
    {
        struct PackageResolution
        {
            unsigned int formID;
            TESPackage* package;
        } packageEntry;
        packageEntry.formID = reinterpret_cast<unsigned int>(cursor.list->GetItem());
        if (form)
            TESForm::RemapFormIDForFile(packageEntry.formID, cursor.file);
        packageEntry.package = dynamic_cast<TESPackage*>(TESForm::GetFormByID(packageEntry.formID));
        if (!packageEntry.package)
        {
            BSStringT<char> debugName;
            if (form)
                form->GetDebugName(&debugName);
            else
                debugName.Set("UNKNOWN form", 0);
            Warning("MASTERFILE: Could not find Package (%08X) for %s.", packageEntry.formID, debugName.String());
            if (cursor.previous)
            {
                TESPackage* pMissingPackage = reinterpret_cast<TESPackage*>(packageEntry.formID);
                cursor.previous->Remove(pMissingPackage);
                cursor.list = cursor.previous->GetNext();
            }
            else
                cursor.list->RemoveHead();
        }
        else
        {
            cursor.list->SetItem(packageEntry.package);
            cursor.previous = cursor.list;
            cursor.list = cursor.list->GetNext();
        }
    }
}

// Checks whether the integer hour falls within the range from start to start+duration, handling wrap-around past 23.
// @fnv 0x0067e700
bool IsHourInRange(int start, int duration, float hour)
{
    struct TimeRange
    {
        int current;
        int wrapped;
        int end;
    } timeRange;
    timeRange.current = static_cast<int>(hour);
    timeRange.end = start + duration;
    timeRange.wrapped = 0;
    if (timeRange.current == start)
        return true;
    if (timeRange.end > 23)
    {
        timeRange.wrapped = timeRange.end - 24;
        if ((timeRange.current > start || timeRange.current < timeRange.wrapped) && timeRange.current < timeRange.end)
            return true;
    }
    else if (timeRange.current > start && timeRange.current < timeRange.end)
        return true;
    return false;
}

// @fnv 0x0067e440
void PackageList::Copy(const PackageList* src)
{
    struct CopyCursor
    {
        TESPackage* package;
        BSSimpleList<TESPackage*>* list;
    } cursor;
    ClearPackageList();
    cursor.list = src->GetListOfPackages();
    if (!cursor.list->IsEmpty())
    {
        while (cursor.list)
        {
            cursor.package = cursor.list->GetItem();
            AddPackage(cursor.package);
            cursor.list = cursor.list->GetNext();
        }
    }
}

// Appends the given TESPackage to the list returned by GetListOfPackages().
// @fnv 0x0067e420
void PackageList::AddPackage(TESPackage* package)
{
    GetListOfPackages()->AddTail(package);
}

struct FUN_0067efd0_shell : public TESPackage
{
    bool FUN_0067efd0();
};

// @fnv 0x0067efd0
bool FUN_0067efd0_shell::FUN_0067efd0()
{
    return (*(unsigned int*)((char*)this + 0x1c) & 4) ? true : false;
}

class FUN_0067e4a0_cls
{
  public:
    unsigned int* FUN_006815c0();
    bool FUN_008256d0();
    bool FUN_0067e4a0(FUN_0067e4a0_cls* other);
};

// Compares two lists element by element via FUN_006815c0 and FUN_00726070, returning true if they differ or one is exhausted first.
// @fnv 0x0067e4a0
bool FUN_0067e4a0_cls::FUN_0067e4a0(FUN_0067e4a0_cls* other)
{
    unsigned int q;
    unsigned int r;
    FUN_0067e4a0_cls* p;
    FUN_0067e4a0_cls* s;

    s = (FUN_0067e4a0_cls*)FUN_006815c0();
    p = (FUN_0067e4a0_cls*)other->FUN_006815c0();
    if (!s->FUN_008256d0())
    {
        while (s != 0 && *s->FUN_006815c0() != 0 && p != 0 && *p->FUN_006815c0() != 0)
        {
            r = *s->FUN_006815c0();
            q = *p->FUN_006815c0();
            if (r != q)
            {
                return true;
            }
            s = (FUN_0067e4a0_cls*)((DurationData*)s)->FUN_00726070();
            p = (FUN_0067e4a0_cls*)((DurationData*)p)->FUN_00726070();
        }
        if (s != 0 || p != 0)
        {
            return true;
        }
    }
    else
    {
        if (!p->FUN_008256d0())
        {
            return true;
        }
    }
    return false;
}
