#pragma once

#include "colors.h"

/**
 * Represents a point of the output
 * */

struct Point {
    int x, y; // it's not cartesian, but the indexes in a matrix
    int color;
};

// returns true if the points are equal with relation with the coordinates
bool isEqual(Point pointA, Point pointB);

Point moveDown(Point point);
Point moveLeft(Point point);
Point moveRight(Point point);

// return the rotation of point 90 degrees clockwise in relation to center
Point rotateClockwise(Point center, Point point);

// return the rotation of point 90 degrees anticlockwise in relation to center
Point rotateAnticlockwise(Point center, Point point);