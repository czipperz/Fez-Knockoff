find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

include_directories(${FEZ_KNOCKOFF_SOURCE_DIR})

include_directories(${FEZ_KNOCKOFF_SOURCE_DIR}/src)
link_directories(${FEZ_KNOCKOFF_SOURCE_DIR}/src)

file(GLOB files "*.hh" "*.cc")
add_executable(fez_knockoff ${files})

target_link_libraries(fez_knockoff ${SDL2_LIBRARY})
target_link_libraries(fez_knockoff ${SDL2_IMAGE_LIBRARY})

# force c++11
target_compile_features(fez_knockoff PRIVATE cxx_auto_type)
