cmake_minimum_required(VERSION 3.5)

project(PathPlanning VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 17)

# Find Python 3 and NumPy
find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)

include_directories(
    ${Python3_INCLUDE_DIRS}
    ${Python3_NumPy_INCLUDE_DIRS}
    .)

add_executable(${PROJECT_NAME} 
    main.cpp)

target_link_libraries(${PROJECT_NAME}
    ${Python3_LIBRARIES})
