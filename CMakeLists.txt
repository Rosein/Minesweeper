cmake_minimum_required(VERSION 3.5)

project(Minesweeper)

add_definitions(
    -std=c++17
    -fno-elide-constructors
    -Wall
    -Wextra
    -pedantic
    -Werror
    -Wfatal-errors
    -Wno-unused-value
    -Wno-unused-parameter
    -Wno-unused-variable
    -lsfml-graphics 
    -lsfml-window 
    -lsfml-system
)

include_directories(include)
file(GLOB SOURCES src/*.cpp app/*.cpp)
add_executable(Minesweeper ${SOURCES})
FILE(COPY resources DESTINATION "${CMAKE_BINARY_DIR}")

set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" "/usr/share/SFML/cmake/Modules/FindSFML.cmake")
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)
target_link_libraries(Minesweeper ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

