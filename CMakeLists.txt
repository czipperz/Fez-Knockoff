cmake_minimum_required(VERSION 2.6)
project(FEZ_KNOCKOFF)

# allow loading of packages based on scripts in `cmake` directory
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      ${FEZ_KNOCKOFF_SOURCE_DIR}/cmake)

add_subdirectory(src)
