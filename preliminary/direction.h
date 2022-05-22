/*
 * File: direction.h
 * -----------------
 * This interface exports an enumerated type called Direction whose
 * elements are the four compass points: NORTH, EAST, SOUTH, and WEST.
 */

#ifndef _direction_h
#define _direction_h

#include <string>

/*
 * Type: Direction
 * ---------------
 * This enumerated type is used to represent the four compass directions.
 */

enum Direction { NORTH, EAST, SOUTH, WEST };

/*
 * Function: leftFrom
 * Usage: Direction newdir = leftFrom(dir)
 * ---------------------------------------
 * Returns the direction that is to the left of the argument.
 * For example, leftFrom(NORTH) retuns WEST.
 */

Direction leftFrom(Direction dir);

/*
 * Function: rightFrom
 * Usage: Direction newdir = leftFrom(dir)
 * ---------------------------------------
 * Returns the direction that is to the right of the argument.
 * For example, rightFrom(NORTH) retuns EAST.
 */

Direction rightFrom(Direction dir);

std::string directionToString(Direction dir);

#endif