// ActorPathHandler declarations for the magic effect-item-list unit
// line 79), returning ActorPathHandler::PATH_HANDLER_RESULT_DONE; the
// CodeView PATH_HANDLER_RESULT enumerators are reproduced verbatim.
#ifndef FNV_EFFECTITEMLIST_H
#define FNV_EFFECTITEMLIST_H


class ActorPathHandler
{
  public:
    enum PATH_HANDLER_RESULT
    {
        PATH_HANDLER_RESULT_NONE = -1,
        PATH_HANDLER_RESULT_OK = 0,
        PATH_HANDLER_RESULT_CANT_MOVE = 1,
        PATH_HANDLER_RESULT_CANT_REACH_Z = 2,
        PATH_HANDLER_RESULT_CANT_USE_DOOR = 3,
        PATH_HANDLER_RESULT_FELL_OFF_PATH = 4,
        PATH_HANDLER_RESULT_DONE = 5,
        PATH_HANDLER_RESULT_DONE_SLEEP_SPECIAL = 6
    };

// @fnv 0x009dfdf0
    PATH_HANDLER_RESULT CompleteNoPathUpdate(float fSeconds)
    {
        return PATH_HANDLER_RESULT_DONE;
    }
};

#endif
