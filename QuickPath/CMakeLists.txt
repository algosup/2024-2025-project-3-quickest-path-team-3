cmake_minimum_required(VERSION 3.30)
project(QuickPath)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_executable(QuickPath main.cpp
        DataIntegrityVerification/DataIntegrity.cpp
        src/Graph.cpp
        src/PathFinder.cpp
        src/RestApi.cpp
)
