/*
 * File: IterateDirections.cpp
 * ---------------------------
 * Demonstrates overloading ++ operators on the class Direction
 */

#include "direction.h"
#include <iostream>
using namespace std;

/* Main program */

int main() {
    cout << "for-loop" << endl;
    for(Direction dir = NORTH; dir <= WEST; dir++) {
        cout << dir << endl;
    }
    Direction dir;
    cout << endl;
    cout << "while (dir != WEST) cout << dir++;" << endl
         << "Start: " << (dir = NORTH) << endl;
    while (dir != WEST) cout << dir++ << endl;
    cout << "End: " << dir << endl << endl;
    cout << "while (dir != WEST) cout << ++dir;" << endl
         << "Start: " << (dir = NORTH) << endl;
    while (dir != WEST) cout << ++dir << endl;
    cout << "End: " << dir << endl;
}