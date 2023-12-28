cmake_minimum_required(VERSION 3.5)

project(PathPlanning VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Find Python 3 and NumPy
find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)

# Include directories for header files
include_directories(
    ${Python3_INCLUDE_DIRS}
    ${Python3_NumPy_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}
)

# Add executable with all relevant source files
add_executable(${PROJECT_NAME} 
    main.cpp
    src/loadmapdata.cpp
    ${PROJECT_SOURCES}
)

# Link with Python libraries
target_link_libraries(${PROJECT_NAME}
    ${Python3_LIBRARIES}
)
