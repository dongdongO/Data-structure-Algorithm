#pragma once

#include <util/point.h>

#include <vector>
#include <cmath>
#include <iostream>

class Map {
public:
    Map(int width, int height, const std::vector<std::vector<int>>& map_data);
    // Map();
    ~Map();

    std::vector<std::vector<Point>> get_map();
    std::vector<int> get_map_info();

    // Helper
    void set_prev_point(int old_x, int old_y, int new_x, int new_y);
    std::vector<int> get_prev_point(int x, int y);
    std::vector<std::vector<int>> get_visited();

    void set_start(int x, int y);
    void set_end(int x, int y);

    void set_blocked(int x, int y);
    void set_visited(int x, int y);

    bool is_start(int x, int y);
    bool is_end(int x, int y);

    bool is_blocked(int x, int y);
    bool is_visited(int x, int y);
    bool is_blocked_or_visited(int x, int y);
    bool is_outside(int x, int y);

    int get_structure(int x, int y);

private:
    int width;
    int height;
    int x_size;
    int y_size;

    std::vector<std::vector<Point>> grid_map;
    std::vector<std::vector<double>> obstacle_list;
};

Map::Map(int width, int height, const std::vector<std::vector<int>>& map_data) {
    this->width = width;
    this->height = height;

    grid_map.resize(width, std::vector<Point>(height, Point()));

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            int map_value = map_data[y][x];
            switch (map_value) {
                case 0:
                    grid_map[x][y].set_solidline();
                    break;
                case 1:
                    grid_map[x][y].set_stopline();
                    break;
                case 2:
                    grid_map[x][y].set_crosswalk();
                    break;
                case 3:
                    grid_map[x][y].set_dottedline();
                    break;
                case 4:
                    grid_map[x][y].set_parkinglot();
                    break;
                case 5:
                    grid_map[x][y].set_roundabout();
                    break;
                case 6:
                    grid_map[x][y].set_startline();
                    break;
                case 7:
                    grid_map[x][y].set_floor();
                    break;                                                        
                case 8:
                    grid_map[x][y].set_busline();
                    break;
                case 9:
                    grid_map[x][y].set_sidewalk();
                    break;
            }
        }
    }
    std::cout << "Map Size: " << grid_map.size() << " x " << grid_map[0].size() << std::endl;    
}

// Map::Map() {
//     std::cout<<"Default Map constructor"<<std::endl;
// }

Map::~Map() {
    std::cout<<"Default Map destructor"<<std::endl;
}

std::vector<std::vector<Point>> Map::get_map() {
    return grid_map;
}

std::vector<int> Map::get_map_info() {
    std::vector<int> map_info = {width, height};
    return map_info;
}

void Map::set_prev_point(int old_x, int old_y, int new_x, int new_y) {
    grid_map[new_x][new_y].set_prev_point(old_x, old_y);
}

std::vector<int> Map::get_prev_point(int x, int y) {
    std::vector<int> prev_point = grid_map[x][y].get_prev_point();
    return prev_point;
}

void Map::set_start(int x, int y) {
    grid_map[x][y].set_start_point();
}

void Map::set_end(int x, int y) {
    grid_map[x][y].set_end_point();
}

void Map::set_blocked(int x, int y) {
    grid_map[x][y].set_blocked();
}

void Map::set_visited(int x, int y) {
    grid_map[x][y].set_visited();
}

bool Map::is_outside(int x, int y) {
    if (x<0 || x_size<=x) {return true;}
    else if (y<0 || y_size<=y) {return true;}
    else {return false;}
}

bool Map::is_start(int x, int y) {
    if (is_outside(x, y)) {return false;}

    if (grid_map[x][y].is_start_point()) {return true;}
    else {return false;}
}

bool Map::is_end(int x, int y) {
    if (is_outside(x, y)) {return false;}

    if (grid_map[x][y].is_end_point()) {return true;}
    else {return false;}
}

bool Map::is_blocked(int x, int y) {
    if (is_outside(x, y)) {return true;}

    if (grid_map[x][y].is_blocked()) {return true;}
    else {return false;}
}

bool Map::is_visited(int x, int y) {
    if (is_outside(x, y)) {return true;}

    if (grid_map[x][y].is_visited()) {return true;}
    else {return false;}
}

bool Map::is_blocked_or_visited(int x, int y) {
    if (is_outside(x, y)) {return true;}

    if (grid_map[x][y].is_blocked() || grid_map[x][y].is_visited()) {return true;}
    return false;
}

std::vector<std::vector<int>> Map::get_visited() {
    std::vector<std::vector<int>> visited_points;
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            if (grid_map[x][y].is_visited()) {
                visited_points.push_back({x, y});
            }
        }
    }
    return visited_points;
}

int Map::get_structure(int x, int y) {
    return grid_map[x][y].get_structure();
}