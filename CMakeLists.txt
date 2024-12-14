cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SnakeGame)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
# Add the executable
add_executable(SnakeGame 
    main.cpp 
    environment.cpp 
    console_handle.cpp 
    snake.cpp 
    food.cpp
    assorted.cpp
)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Link libraries
target_link_libraries(SnakeGame ncurses)