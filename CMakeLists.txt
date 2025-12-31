cmake_minimum_required(VERSION 3.10)
project(sysdoctor)

set(CMAKE_CXX_STANDARD 17)

add_executable(sysdoctor
    src/main.cpp
    src/system_metrics.cpp
    src/ai_engine.cpp
)


