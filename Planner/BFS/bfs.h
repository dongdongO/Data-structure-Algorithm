#pragma once

#include <utils/map.h>
#include <utils/point.h>

#include <deque>
#include <utility>

class BFS {
public:
    BFS(Map& map, double start_x, double start_y, double end_x, double end_y);
    ~BFS();
    bool path_planning();
    std::vector<std::vector<int>> get_route();

private:
    Map& map;
    std::deque<std::vector<int>> visit_deque;

    int start_x;
    int start_y;
    int end_x;
    int end_y;

    std::vector<std::vector<Point>> map_index;

    std::vector<int> route_x;
    std::vector<int> route_y;
};

BFS::BFS(Map& map, double start_x, double start_y, double end_x, double end_y):map(map) {
    map_index = map.get_map();
    this->start_x = start_x;
    this->start_y = start_y;
    this->end_x = end_x;
    this->end_y = end_y;
    std::cout<<"start_x : "<<this->start_x<<'\t'<<"start_y : "<<this->start_y<<std::endl;
    std::cout<<"end_x : "<<this->end_x<<'\t'<<"end_y : "<<this->end_y<<std::endl;
}

BFS::~BFS() {
    std::cout<<"Default BFS destructor"<<std::endl;
}

bool BFS::path_planning() {
    if (map_index[start_x][start_y].blocked) {return false;}
    else if (map_index[start_x][start_y].blocked) {return false;}

    int count = 0;

    visit_deque.push_back({start_x, start_y});
    map.set_visited(start_x, start_y);

    int old_x = 0;
    int old_y = 0;
    int new_x = 0;
    int new_y = 0;
    // std::cout<<start_x<<'\t'<<start_y<<std::endl;
    while (!visit_deque.empty()) {
        count += 1;
        old_x = visit_deque.front()[0];
        old_y = visit_deque.front()[1];
        int new_xs[4] = {old_x+1, old_x, old_x-1, old_x};
        int new_ys[4] = {old_y, old_y+1, old_y, old_y-1};
        // std::cout<<"new_x : "<<new_x<<'\t'<<"new_y : "<<new_y<<std::endl;
        // std::cout<<"Loop :" <<count<<std::endl;
        for (int i=0; i<=3; i++) {
            new_x = new_xs[i];
            new_y = new_ys[i];
            if (!map.is_blocked_or_visited(new_x, new_y)) {
                visit_deque.push_back({new_x, new_y});
                map.set_visited(new_x, new_y);
                map.set_prev_point(old_x, old_y, new_x, new_y);
                // std::cout<<"new_x : "<<new_x<<'\t'<<"new_y : "<<new_y<<std::endl;
                if (new_x == end_x && new_y == end_y) {
                    std::cout << "The End : " << new_x << ", " << new_y << std::endl;
                    return true;
                }
            }
        }
        visit_deque.pop_front();
    }
    return true;
}

std::vector<std::vector<int>> BFS::get_route() {
    std::cout<<"get_route"<<std::endl;
    int now_x = end_x;
    int now_y = end_y;
    while (now_x != start_x || now_y != start_y) {
        std::vector<int> next_xy = map.get_prev_point(now_x, now_y);
        route_x.push_back(next_xy[0]);
        route_y.push_back(next_xy[1]);
        now_x = next_xy[0];
        now_y = next_xy[1];
        std::cout<<"new_x : "<<now_x<<'\t'<<"new_y : "<<now_y<<std::endl;
    }
    std::vector<std::vector<int>> route = std::vector<std::vector<int>>({route_x, route_y});
    return route;
}
