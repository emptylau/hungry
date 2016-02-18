cmake_minimum_required(VERSION 2.8)

project(testhello)

add_executable(testhello Hello.cpp)
target_link_libraries(testhello  "${LIBRARIES_FROM_REFERENCES}")
