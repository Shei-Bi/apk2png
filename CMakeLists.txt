# Project: 
cmake_minimum_required(VERSION 3.22)
project(apk2png)

# C++ headers and source files
file(GLOB_RECURSE HEADERS src/*.h)
file(GLOB_RECURSE SOURCES src/*.c src/*.cpp src/*.hpp)

set(CLI_TARGET apk2png)

add_executable(${CLI_TARGET} ${HEADERS} ${SOURCES})

# set_target_properties(${CLI_TARGET} PROPERTIES
#     FOLDER SupercellSDK/tools
# )
target_include_directories(${CLI_TARGET} PUBLIC include src)
# target_link_directories(${CLI_TARGET} PUBLIC lib/)
# target_link_libraries(${CLI_TARGET} PRIVATE supercell::flash glfw3)
