// FNV decompilation source: fallout_shared/pathfinding/pathmanager.h
//
// Pathing message types used by the actor pathing manager.
#ifndef FNV_PATHMANAGER_H
#define FNV_PATHMANAGER_H


class cancellation_token_source
{
  public:
    ~cancellation_token_source();
};

class QueuedMessage
{
  public:
    unsigned int m_eMessageType;
    cancellation_token_source m_pPathingSolution;

    ~QueuedMessage();
};

// @fnv 0x00800190
QueuedMessage::~QueuedMessage()
{}

#endif  // FNV_PATHMANAGER_H
