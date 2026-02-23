cmake_minimum_required(VERSION 3.16)
project(LightningMD)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(LightningMD
    src/main.cpp
    src/Reader.cpp
    src/Engine.cpp
    src/RollingVWAP.cpp
    src/RollingVolatility.cpp
)
