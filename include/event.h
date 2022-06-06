////////////////////////////////////////////////////////////
//
// Copyright (c) 2022
// Daniel Moune Computer Systems, Inc.
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee,
// provided that the above copyright notice appear in all copies and
// that both that copyright notice and this permission notice appear
// in supporting documentation.  Engr Daniel Moune makes no
// representations about the suitability of this software for any
// purpose.  It is provided "as is" without express or implied warranty.
//
////////////////////////////////////////////////////////////

#ifndef TETRIS_EVENT_H
#define TETRIS_EVENT_H

#include "brick.h"
#include <ostream>

namespace tetris
{

////////////////////////////////////////////////////////////
/// \brief The Event class is designed to create and throw game events
///
/// This class represents the Event that may happen while the game is being played
///    + NEW_BRICK_DROP             -- this event is thrown every time a new brick is dropped on the stage
///    + BRICK_MOVED                   -- this event is thrown every time the brick moves on the stage
///    + BRICK_ROTATE                -- this event is thrown every time the brick rotates on the stage 
///    + BRICK_HIT_WALL               -- this event is thrown every time the brick hits the wall or the bottom of the stage
///    + BRICK_OUT_OF_BOUNDS  -- this event is thrown every time the brick position accidently appears to be out of bound
///    + ROW_COMPLETED            -- this event is thrown every time a completed row is detected by the game engine
///    + NO_SPACE_AVAILABLE     -- this event is thrown every time there's no more area on the stage available for a new brick drop
///    + GAME_OVER                      -- this event is thrown when the game engines stops because there's no more space available
///
////////////////////////////////////////////////////////////
class Event
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Enumeration of the different types of events
    ///
    ////////////////////////////////////////////////////////////
    enum EventType
    {
        RENDER,                                     ///< this event is thrown when it is time for SFML to render the frame on the Window
        NEW_BRICK_DROP,                     ///< this event is thrown every time a new brick is dropped on the stage
        BRICK_MOVING_UP,                    ///< this event is thrown every time the brick moves up on the stage
        BRICK_STOP_MOVING_UP,         ///< this event is thrown every time the brick stops moving up on the stage
        BRICK_MOVING_DOWN,              ///< this event is thrown every time the brick moves down on the stage
        BRICK_STOP_MOVING_DOWN,   ///< this event is thrown every time the brick stops moving down on the stage
        BRICK_MOVING_LEFT,               ///< this event is thrown every time the brick moves left on the stage
        BRICK_STOP_MOVING_LEFT,    ///< this event is thrown every time the brick stops moving left on the stage
        BRICK_MOVING_RIGHT,              ///< this event is thrown every time the brick moves right on the stage
        BRICK_STOP_MOVING_RIGHT,   ///< this event is thrown every time the brick stops moving right on the stage
        BRICK_ROTATE,                         ///< this event is thrown every time the brick rotates on the stage
        BRICK_STOP_ROTATE,              ///< this event is thrown every time the brick stops rotating on the stage
        BRICK_HIT_WALL,                 ///< this event is thrown every time the brick hits the wall or the bottom of the stage
        BRICK_OUT_OF_BOUNDS,   ///< this event is thrown every time the brick position accidently appears to be out of bound
        ROW_COMPLETED,             ///< this event is thrown every time a completed row is detected by the game engine
        NO_SPACE_AVAILABLE,      ///< this event is thrown every time there's no more area on the stage available for a new brick drop
        GAME_STARTED,                ///< this event is thrown every time the game engine is started
        GAME_OVER,                       ///< this event is thrown when the game engines stops because there's no more space available
        GAME_QUIT,                       ///< this event is thrown when the game is stopped and the window is closed by the player
        UNDEFINED                           ///< this is the default value when an event object is just created but undefined
    };

    EventType type; ///< Type of the event
    Time time; ///< Time at which the event was reported
    struct Location{short x,y;} brick_loc[4];  ///< position of each of the square blocks of the brick at the time of the event initialization

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor.
    ///
    /// This constructor creates the event object. the eventType property is set to UNDEFINED.
    ///
    ////////////////////////////////////////////////////////////
    Event();
    ////////////////////////////////////////////////////////////
    /// \brief Parameterized constructor which logs the position of the brick
    ///
    /// This constructor creates the event object. the eventType property is set to UNDEFINED.
    /// The position of the Brick at the time of the creation of the event is copied into the event.
    ///
    /// \param brick  The brick that is manipulated in the game.
    /// \param t         The time at which the event is reported
    ///
    ////////////////////////////////////////////////////////////
    Event(Brick brick, Time t);
    ////////////////////////////////////////////////////////////
    /// \brief Parameterized constructor which logs the position of the brick
    ///
    /// This constructor creates the event object. the eventType property is set to UNDEFINED.
    /// The position of the Brick at the time of the creation of the event is copied into the event.
    ///
    /// \param brick  The brick that is manipulated in the game.
    /// \param eType  The type of event that is reported.
    /// \param t           The time at which the event is reported.
    ///
    ////////////////////////////////////////////////////////////
    Event(Brick brick, EventType eType, Time t);

    friend std::ostream& operator <<(std::ostream& outputStream, const Event& e);
};

}// namespace tetris

#endif // TETRIS_EVENT_H