#pragma once

#include "colors.h"

/**
 * Represents a point of the output
 * */

struct Point {
    int x, y; // it's not cartesian, but the indexes in a matrix
    int color;
};

Point moveDown(Point point);
Point moveLeft(Point point);
Point moveRight(Point point);

// return the rotation of point 90 degrees clockwise in relation to center
Point rotateClockwise(Point center, Point point);

// return the rotation of point 90 degrees anticlockwise in relation to center
Point rotateAnticlockwise(Point center, Point point);