/*
 * File: gobjects.cpp
 * ------------------
 * This file implements the gobjects.h interface.
 */

#include <string>
#include "gwindow.h" // In Stanford libraries, not in my repo
#include "gobjects.h"
using namespace std;
/*
 * Implementation notes: GObject class
 * -----------------------------------
 * The constructor for the superclass sets the default color (BLACK).
 */

GObject::GObject() {
    setColor("BLACK");
}

void GObject::setLocation(double x, double y) {
    this->x = x;
    this->y = y;
}

void GObject::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void GObject::setColor(string color) {
    this->color = color;
}

/*
 * Implementation notes: GLine class
 * ---------------------------------
 * The constructor for the GLine class has to change the specification
 * of the line from the endpoints passed to the constructor to the
 * representation that uses a starting point along with dx/dy values.
 */

GLine::GLine(double x1, double y1, double x2, double y2) {
    this->x = x1;
    this->y = y1;
    this->dx = x2 - x1;
    this->dy = y2 - y1;
}

void GLine::draw(GWindow & gw) {
    gw.setColor(color);
    gw.drawLine(x, y, x + dx, y + dy);
}

/*
 * Implementation notes: GRect and GOval classes
 * ---------------------------------------------
 * The constructors for these classes store their arguments in the
 * corresponding instance variables. The draw method forwards the
 * appropriate request to the GWindow class.
 */

GRect::GRect(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    filled = false;
}

void GRect::setFilled(bool flag) {
    filled = flag;
}

void GRect::draw(GWindow & gw) {
    gw.setColor(color);
    if (filled) {
        gw.fillRect(x, y, width, height);
    } else {
        gw.drawRect(x, y, width, height);
    }
}

GOval::GOval(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    filled = false;
}

void GOval::setFilled(bool flag) {
    filled = flag;
}

void GOval::draw(GWindow & gw) {
    gw.setColor(color);
    if (filled) {
        gw.fillOval(x, y, width, height);
    } else {
        gw.drawOval(x, y, width, height);
    }
}