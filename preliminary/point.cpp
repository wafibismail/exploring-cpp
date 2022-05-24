/*
 * File: point.cpp
 * ---------------
 * This file implements the point.h interface.
 */

#include <string>
#include <iostream>
#include <sstream>
#include "point.h"

using namespace std;

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * The constructors initialize the instance variables x and y. In the
 * second form of the constructor, the parameter names are xc and yc
 * to avoid the problem of shadowing the instance variables.
 */

Point::Point() {
    x = 0;
    y = 0;
}

Point:: Point(int xc, int yc) {
    x = xc;
    y = yc;
}

/*
 * Implementation notes: Getters
 * -----------------------------
 * The getters return the value of the corresponding instance variable.
 * No setters are provided to ensure that Point objects are immutable.
 */

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

/*
 * Implementation notes: toString
 * ------------------------------
 * The implementation of toString uses the integerToString function
 * from the strlib.h interface.
 */

string Point::toString() {
    stringstream ss;
    string str;
    ss << "(" << x << "," << y << ")";
    ss >> str;
    ss.clear();
    return str;
}

/*
 * The implementation of boolean operators' overloads
 */

bool operator==(Point pt1, Point pt2) {
    return pt1.x == pt2.x && pt1.y == pt2.y;
}

bool operator!=(Point pt1, Point pt2) {
    return !(pt2 == pt2);
}

ostream & operator<<(ostream & os, Point pt) {
    return os << pt.toString();
}