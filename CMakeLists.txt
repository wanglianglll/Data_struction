cmake_minimum_required(VERSION 3.26)
project(Data_struction)

set(CMAKE_CXX_STANDARD 17)

add_executable(Data_struction src/main.cpp
        src/workspace/Workspace.cpp
        src/workspace/Workspace.h
        src/workspace/ui_stream_thread/ui_thread.cpp)

find_package(Threads REQUIRED)
target_link_libraries(Data_struction Threads::Threads)