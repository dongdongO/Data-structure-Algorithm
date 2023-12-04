cmake_minimum_required(VERSION 3.5)

project(PathPlanning VERSION 1.0 LANGUAGES CXX)

find_package(PythonLibs REQUIRED)

include_directories(
    ${PYTHON_INCLUDE_DIRS}
    .)

add_executable(${PROJECT_NAME} 
    main.cpp)
target_link_libraries(${PROJECT_NAME}
    ${PYTHON_LIBRARIES})
