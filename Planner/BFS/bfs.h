#pragma once

#include <utils/map.h>

#include <deque>
#include <utility>

class BFS {
public:
    BFS(Map& map, double start_x, double start_y, double end_x, double end_y);
    ~BFS();
    bool path_planning(int max_iter);
    std::vector<std::vector<double>> get_route();

private:
    Map& map;
    std::deque<std::vector<int>> visit_deque;

    int start_x;
    int start_y;
    int end_x;
    int end_y;

    // double width;
    // double height;
    double resolution;

    std::vector<double> route_x;
    std::vector<double> route_y;
};

BFS::BFS(Map& map, double start_x, double start_y, double end_x, double end_y):map(map) {
    // this->map = map;
    std::vector<int> map_info = map.get_map_info();
    // this->resolution = map_info[2];

    this->start_x = round(start_x/resolution);
    this->start_y = round(start_y/resolution);
    this->end_x = round(end_x/resolution);
    this->end_y = round(end_y/resolution);
    this->map.set_start(this->start_x, this->start_y);
    this->map.set_end(this->end_x, this->end_y);
    std::cout<<"start_x : "<<this->start_x<<'\t'<<"start_y : "<<this->start_y<<std::endl;
    std::cout<<"end_x : "<<this->end_x<<'\t'<<"end_y : "<<this->end_y<<std::endl;
}

BFS::~BFS() {
    std::cout<<"Default BFS destructor"<<std::endl;
}

bool BFS::path_planning(int max_iter) {
    if (map.is_blocked(start_x, start_y)) {return false;}
    else if (map.is_blocked(end_x, end_y)) {return false;}

    int count = 0;

    visit_deque.push_back({start_x, start_y});
    map.set_visited(start_x, start_y);

    int old_x = 0;
    int old_y = 0;
    int new_x = 0;
    int new_y = 0;
    // std::cout<<start_x<<'\t'<<start_y<<std::endl;
    while (!visit_deque.empty()) {
        old_x = visit_deque.front()[0];
        old_y = visit_deque.front()[1];
        int new_xs[4] = {old_x+1, old_x, old_x-1, old_x};
        int new_ys[4] = {old_y, old_y+1, old_y, old_y-1};
        for (int i=0; i<=3; i++) {
            new_x = new_xs[i];
            new_y = new_ys[i];
            // std::cout<<"new_x : "<<new_x<<'\t'<<"new_y : "<<new_y<<std::endl;
            if (!map.is_blocked_or_visited(new_x, new_y)) {
                visit_deque.push_back({new_x, new_y});
                map.set_visited(new_x, new_y);
                map.set_prev_point(old_x, old_y, new_x, new_y);
                if (map.is_end(new_x, new_y)) {
                    return true;
                }
            }
        }
        visit_deque.pop_front();

        // if (count++<max_iter) {
        //     std::cout<<"Maximum Iteration : "<<count<<std::endl;
        //     return false;
        // }
    }
    return true;
}

std::vector<std::vector<double>> BFS::get_route() {
    std::cout<<"get_route"<<std::endl;
    int now_x = end_x;
    int now_y = end_y;
    while (!map.is_start(now_x, now_y)) {
        std::vector<int> next_xy = map.get_prev_point(now_x, now_y);
        route_x.push_back(next_xy[0]*resolution);
        route_y.push_back(next_xy[1]*resolution);
        now_x = next_xy[0];
        now_y = next_xy[1];
        std::cout<<"new_x : "<<now_x<<'\t'<<"new_y : "<<now_y<<std::endl;
    }
    std::vector<std::vector<double>> route = std::vector<std::vector<double>>({route_x, route_y});
    return route;
}
