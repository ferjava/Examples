cmake_minimum_required(VERSION 3.14)

project(Fjengine LANGUAGES CXX)


FILE(GLOB_RECURSE ENGINE_SOURCES "src/*.cpp")

ADD_LIBRARY(${PROJECT_NAME} ${ENGINE_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}include/)
