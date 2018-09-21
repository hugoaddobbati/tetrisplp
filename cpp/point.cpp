#include "point.h"
#pragma once
bool isEqual(Point pointA, Point pointB){
    if(pointA.x != pointB.x || pointA.y != pointB.y) return false;
    return true;
}

Point moveDown(Point point){
    Point nextPoint;
    nextPoint.x = point.x;
    nextPoint.y = point.y + 1;
    nextPoint.color = point.color;
    return nextPoint;
}

Point moveLeft(Point point){
    Point nextPoint;
    nextPoint.x = point.x-1;
    nextPoint.y = point.y;
    nextPoint.color = point.color;
    return nextPoint;
}

Point moveRight(Point point){
    Point nextPoint;
    nextPoint.x = point.x+1;
    nextPoint.y = point.y;
    nextPoint.color = point.color;
    return nextPoint;
}

Point rotateClockwise(Point center, Point point){
    //x,y -> y,-x
    int newX = point.x - center.x;
    int newY = point.y - center.y;
    Point nextPoint;
    nextPoint.x = newY;
    nextPoint.y = -newX;
    nextPoint.x += center.x;
    nextPoint.y += center.y;
    nextPoint.color = point.color;
    return nextPoint;
}

Point rotateAnticlockwise(Point center, Point point){
    //x,y -> -y,x
    int newX = point.x - center.x;
    int newY = point.y - center.y;
    Point nextPoint;
    nextPoint.x = -newY;
    nextPoint.y = newX;
    nextPoint.x += center.x;
    nextPoint.y += center.y;
    nextPoint.color = point.color;


    return nextPoint;
}
