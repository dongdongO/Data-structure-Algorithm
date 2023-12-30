#pragma once

#include <vector>

class Point
{
public:
    uint8_t structure;
    bool blocked;

    Point();
    ~Point();  
};

Point::Point() {
    blocked = false;
}

Point::~Point() {
}