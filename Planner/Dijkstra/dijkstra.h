#pragma once

#include <Utils/map.h>

class Dijkstra {
public:
    Dijkstra(Map map, double start_point_x, double start_point_y, double end_point_x, double end_point_y);
    ~Dijkstra();
    bool path_planning();
private:
    Map map;
    double start_point_x;
    double start_point_y;
    double end_point_x;
    double end_point_y;
};

Dijkstra::Dijkstra(Map map, double start_point_x, double start_point_y, double end_point_x, double end_point_y) {
    this->map = map;
    this->start_point_x = start_point_x;
    this->start_point_y = start_point_y;
    this->end_point_x = end_point_x;
    this->end_point_y = end_point_y;
}

Dijkstra::~Dijkstra() {
}

// bool Dijkstra::path_planning() {
//     if map.is_collision(start_point_x, start_point_y) {return false;}
//     else if map.is_collision(end_point_x, end_point_y) {return false;}

//     while () {
        
//     }
// }