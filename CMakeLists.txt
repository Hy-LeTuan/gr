cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 17)

project("gr" VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CORE_SOURCES src/main.cpp;src/reader.cpp)

add_executable(${PROJECT_NAME} ${CORE_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

# include libm for linking
target_link_libraries(${PROJECT_NAME} m)
