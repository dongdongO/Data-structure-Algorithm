// #include <Planner/Dijkstra/dijkstra.h>
#include <Planner/BFS/bfs.h>
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
    // std::string file_path = "../globalmap/map-index.txt";
    // std::vector<std::vector<int>> map_data = load_map_data(file_path);

    // // std::cout<<map_data.size()<<std::endl;
    // // std::cout<<map_data[0].size()<<std::endl;

    // int width = map_data.size();
    // int height = map_data[0].size();

    // // Map Setting
    // // double width = 10.2;
    // // double height = 10.3;
    // // double resolution = 0.1;
    // Map map = Map(width, height, map_data);

    // // map_data 메모리 해제
    // map_data.clear();
    // map_data.shrink_to_fit();

    // Map Setting

    // Obstacle Setting
    // map.set_obstacle(2.3, 2.3, 1.0, 1.0);
    // map.set_obstacle(6.5, 6.1, 1.0, 1.0);
    // map.set_obstacle(5.1, 2.0, 2.0, 2.0);
    // Obstacle Setting

    // Start & End point Setting
    // double start_x = 2.5;
    // double start_y = 1.5;
    // double end_x = 7.0;
    // double end_y = 8.7;
    // // Start & End point Setting

    // Path Planning
    // BFS
    // BFS bfs = BFS(map,
    //     start_x,
    //     start_y,
    //     end_x,
    //     end_y);
    // bfs.path_planning(1000);
    // std::vector<std::vector<double>> bfs_route = bfs.get_route();
    // BFS
    // Path Planning


    // Dijkstra
    // Dijkstra dijkstra = Dijkstra(map,
    //     start_x,
    //     start_y,
    //     end_x,
    //     end_y);
    // dijkstra.path_planning();

    // Matplotlib (Visualization)
    std::cout<<"Matplotlib"<<std::endl;
    // double draw_resolution = 0.1;

    // auto map_info = map.get_map();
    // auto obstacle_list = map.get_obstacle_list();

    // Obstacle
    // for (int l=0; l<obstacle_list.size(); l++) {
    //     double o_x1 = obstacle_list[l][0];
    //     double o_y1 = obstacle_list[l][1];
    //     double o_x2 = o_x1+obstacle_list[l][2];
    //     double o_y2 = o_y1+obstacle_list[l][3];
    //     plt::plot({o_x1,o_x1,o_x2,o_x2,o_x1}, {o_y1,o_y2,o_y2,o_y1,o_y1}, "k-");
    //     plt::plot({o_x1,o_x2}, {o_y1,o_y2}, "k-");
    //     plt::plot({o_x1,o_x2}, {o_y2,o_y1}, "k-");
    // }

    // // Map
    // plt::plot({0,0,width,width,0},{0,height,height,0,0},"k-");  
    // // Starting
    // plt::plot({start_x}, {start_y}, "ro");
    // // Ending
    // plt::plot({end_x}, {end_y}, "bo");

    // // Path Planning Node
    // // plt::plot
    // // Path Planning Line
    // plt::plot(bfs_route[0], bfs_route[1], "b-");
    
    // plt::show();

    std::string file_path = "../globalmap/map-index.txt";
    std::vector<std::vector<int>> map_data = load_map_data(file_path);
    int width = map_data[0].size();
    int height = map_data.size();

    Map map = Map(width, height, map_data);

    // 이미지 데이터를 1차원 배열로 변환 (그레이스케일)
    std::vector<float> image_data(width * height);
    for (int y = 0; y < height; y++) {
        // std::cout<<y<<std::endl;
        for (int x = 0; x < width; x++) {
            int structure = map.get_structure(x, y);
            // std::cout<<structure<<std::endl;
            int index = y * width + x;
            image_data[index] = (structure == 7) ? 0.0 : 1.0; // 7이면 검은색(0.0), 아니면 흰색(1.0)
            // std::cout<<x<<std::endl;
        }
        // std::cout<<y<<std::endl;
    }

    // imshow로 시각화
    plt::imshow(&image_data[0], height, width, 1); // 여기서 1은 그레이스케일 이미지를 나타냄
    plt::show();

    return 0;

}