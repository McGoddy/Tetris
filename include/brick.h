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

#ifndef TETRIS_BRICK_H
#define TETRIS_BRICK_H

#include <SFML/Graphics.hpp>
using namespace sf;

namespace tetris
{

////////////////////////////////////////////////////////////
/// \brief The Brick class is designed to initialize and render brick sprites.
///
/// This class represents the brick objects represented on the screen.
/// Bricks come in different shapes:
///    + I_SHAPE
///    + Z_SHAPE
///    + S_SHAPE
///    + T_SHAPE
///    + L_SHAPE
///    + J_SHAPE
///    + O_SHAPE.
///
/// Brick class provides the following services
///     + rotate     -- rotates the brick at 90°
///     + move      -- moves the brick along a 2D geometrical vector
///     + render    -- renders the brick on the Window provided.
///
////////////////////////////////////////////////////////////
class Brick
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Default constructor.
    ///
    /// This constructor creates the brick object
    /// \param offset  This is the default location of the Brick on the stage
    ///
    ////////////////////////////////////////////////////////////
    Brick(const Vector2f &offset);
    ////////////////////////////////////////////////////////////
    /// \brief Parameterized constructor.
    ///
    /// This constructor creates the brick object that correspond to the shape provided as parameter.
    ///
    /// \param shape   name of one of the shapes bricks can take in the game.
    ///
    ////////////////////////////////////////////////////////////
    //Brick(String shape);
    ////////////////////////////////////////////////////////////
    /// \brief rotates the brick counterclockwise.
    ///
    /// Use this function as a handler of one of the key events in the game.
    /// the shape is rotated at at 90°.
    ///
    ////////////////////////////////////////////////////////////
    void rotate();
    ////////////////////////////////////////////////////////////
    /// \brief moves the brick along a geometrical vector.
    ///
    /// Use this function to move the bricks  up, down, left, right.
    /// Vector2f Vector2u are classes provided by SFML framework for 2D transformation.
    /// The moves of the brick are limited by the boundaries of the area provided.
    ///
    /// \param offset   SFML Vector specifying the directions of the move.
    /// \param area       SFML Vector specifying the boundaries of the move.
    ///
    ////////////////////////////////////////////////////////////
    void move(const Vector2f &offset);
    ////////////////////////////////////////////////////////////
    /// \brief renders the brick as a sprite using the OpenGL drawing services of SFML.
    ///
    /// Use this function to draw bricks with simple graphics without textures.
    ///
    /// \param window   address of the SFML window where the brick will render its sprite.
    ///
    ////////////////////////////////////////////////////////////
    void render(RenderWindow *window);
    ////////////////////////////////////////////////////////////
    /// \brief determines if the brick position is inside a particular area which dimensions are given.
    ///
    /// Use this function to limit the moves of a brick inside the boundaries of a particular area of the Game's window.
    ///
    /// \param area   area where the brick position will be verified if it sits in between
    /// \return TRUE if the brick position is inside the boudaries of the area and FALSE if it's not
    ///
    ////////////////////////////////////////////////////////////
    bool inbound(Vector2u area);

public:
    static const String I_SHAPE;      ///< I-shape brick --String constant
    static const String Z_SHAPE;    ///< Z-shape brick --String constant
    static const String S_SHAPE;    ///< S-shape brick --String constant
    static const String T_SHAPE;    ///< T-shape brick --String constant
    static const String L_SHAPE;    ///< L-shape brick --String constant
    static const String J_SHAPE;    ///< J-shape brick --String constant
    static const String O_SHAPE;   ///< O-shape brick --String constant

    static const unsigned int block_size = 30;   ///< Default block size for bricks in pixels
    static const unsigned int wall_size = 15;   ///< Default block size for bricks in pixels

private:
    ////////////////////////////////////////////////////////////
    /// \brief compute an SFML Color constant based on the integer provided 
    ///
    /// Use compute random colors for the bricks
    ///
    /// \param n   random integer value that represents an SFML Color constant 
    ///
    ////////////////////////////////////////////////////////////
    sf::Color getFillColor(int);
    void logPosition();

private:
    RectangleShape block[4];   /// the 04 square blocks of each brick
    ////////////////////////////////////////
    /// default shapes configuration
    ////////////////////////////////////////
    unsigned short shape[7][4] = 
        {
            1,3,5,7,     // I - shape
            2,4,5,7,  // Z - shape
            3,5,4,6,  // S - shape
            3,5,4,7,  // T - shape
            2,3,5,7,  // L - shape
            3,5,7,6,  // J - shape
            2,3,4,5,  // 0 - shape
        };
public:
struct Position{short x,y;} p[4];  ///< position of each of the square blocks of the brick
////////////////////////////////////////////////////////////
/// \brief returns the brick's current position
///
/// This functions returns the brick position on the stage.
///
/// \param position  a structure holding the positions of all the blocks that are part of the brick
///
////////////////////////////////////////////////////////////
    void getPosition(Position*);
};

}// namespace tetris

#endif // TETRIS_BRICK_H