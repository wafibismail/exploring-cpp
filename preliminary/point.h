/*
 * File: point.h
 * -------------
 * This interface exports the Point class, which represents a point on
 * a two-dimensional integer grid.
 */

#ifndef _point_h
#define _point_h

#include <string>
#include <iostream>

class Point {

public:

/*
 * Constructor: Point
 * Usage: Point origin;
 *        Point pt(xc, xy);
 * ------------------------
 * Creates a Point object. The default constructor sets the coordinates
 * to 0; the second form sets the coordinates to xc and yc.
 */

    Point();
    Point(int xc, int yc);

/*
 * Methods: getX, getY
 * Usage: int x = pt.getX();
 *        int y = pt.getY();
 * -------------------------
 * Return the x and y coordinates of the point, respectively.
 */

    int getX();
    int getY();

/*
 * Method: toString
 * Usage: string str = pt.toString();
 * ----------------------------------
 * Returns a string representation of the Point in the form "(x, y)"
 */

    std::string toString();

private:

/* Friend declaration */

    friend bool operator==(Point pt1, Point pt2);

/* Instance variables */

    int x;                  /* The x coordinate */
    int y;                  /* The y coordinate */
};

/*
 * Operator: <<
 * Usage: cout << pt;
 * ------------------
 * Overloads the << operator so that it is able to display Point values
 */

std::ostream & operator<<(std::ostream & os, Point pt);

/*
 * Operator: ==
 * Usage: pt1 == pt2
 * -----------------
 * Implements the == operator for points.
 */

bool operator==(Point pt1, Point pt2);

/*
 * Operator: !=
 * Usage: pt1 != pt2
 * -----------------
 * Implements the != operator for points. It is good practice to 
 * overload this operator whenever you overload == to ensure that
 * clients can perform ether test.
 */

bool operator!=(Point pt1, Point pt2);

#endif