// #include <Planner/Dijkstra/dijkstra.h>
// #include <Planner/BFS/bfs.h>
#include <utils/map.h>
#include <utils/matplotlibcpp.h>
#include <include/loadmapdata.h>

// #include <Func/loadmapdata.cpp>

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

namespace plt = matplotlibcpp;

int main() {
    std::string file_path = "/Users/seodonghwan/personal/Data-structure-Algorithm/globalmap/map-index.txt";

    Map map = Map(file_path);


    // Only for drawing
    std::cout << "Draw Map" << std::endl;
    std::vector<std::vector<Point>> draw_grid_map = map.get_map();
    std::vector<int> draw_map_info = map.get_map_info();
    int map_width = draw_map_info[0];
    int map_height = draw_map_info[1];

    std::vector<float> image_data(map_width * map_height);
    for(int x=0; x<map_width; ++x) {
        for(int y=0; y<map_height; ++y) {
            int structure = draw_grid_map[x][y].structure;
            int index = y * map_width + x;
            image_data[index] = (structure == 7) ? 0.0 : 1.0; // 7이면 검은색(0.0), 아니면 흰색(1.0)
        }
    }

    // imshow로 시각화
    plt::imshow(&image_data[0], map_height, map_width, 1); // 여기서 1은 그레이스케일 이미지를 나타냄
    plt::show();

    return 0;

}