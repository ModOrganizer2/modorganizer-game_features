cmake_minimum_required(VERSION 3.16)

project(gamefeatures)
set(project_type lib)
set(enable_warnings OFF)

include(../cmake_common/project.cmake)
add_subdirectory(src)
