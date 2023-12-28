#pragma once

#include <vector>

class Point
{
public:
    Point();
    ~Point();

    void set_solidline();
    void set_stopline();
    void set_crosswalk();
    void set_dottedline();
    void set_parkinglot();
    void set_roundabout();
    void set_startline();
    void set_floor();
    void set_busline();
    void set_sidewalk();

    void set_blocked();
    void set_visited();
    bool is_blocked();
    bool is_visited();

    void set_start_point();
    void set_end_point();
    bool is_start_point();
    bool is_end_point();
    void set_prev_point(int prev_x, int prev_y);
    std::vector<int> get_prev_point();

    int get_structure();
    
private:
    int structure;
    bool start_point;
    bool end_point;
    bool blocked;
    bool visited;
    int prev_x;
    int prev_y;
};

Point::Point() {
    start_point = false;
    end_point = false;
    blocked = false;
    visited = false;
}

Point::~Point() {
}

void Point::set_solidline() {blocked=true; structure=0;}
void Point::set_stopline() {blocked=false; structure=1;}
void Point::set_crosswalk() {blocked=false; structure=2;}
void Point::set_dottedline() {blocked=false; structure=3;}
void Point::set_parkinglot() {blocked=true; structure=4;}
void Point::set_roundabout() {blocked=true; structure=5;}
void Point::set_startline() {blocked=false; structure=6;}
void Point::set_floor() {blocked=false; structure=7;}
void Point::set_busline() {blocked=true; structure=8;}
void Point::set_sidewalk() {blocked=true; structure=9;}

void Point::set_blocked() {
    blocked = true;
}

void Point::set_visited() {
    visited = true;
}

bool Point::is_blocked() {
    return blocked;
}

bool Point::is_visited() {
    return visited;
}

void Point::set_start_point() {
    start_point = true;
}

void Point::set_end_point() {
    end_point = true;
}

bool Point::is_start_point() {
    return start_point;
}

bool Point::is_end_point() {
    return end_point;
}

void Point::set_prev_point(int prev_x, int prev_y) {
    this->prev_x = prev_x;
    this->prev_y = prev_y;
}

std::vector<int> Point::get_prev_point() {
    std::vector<int> prev_point_xy = std::vector<int>({prev_x, prev_y});
    return prev_point_xy;
}

int Point::get_structure() {
    return structure;
}