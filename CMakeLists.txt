cmake_minimum_required(VERSION 3.17)
project(hi)

set(CMAKE_CXX_STANDARD 14)
# These are where the include files should be
include_directories(/usr/local/include)

# add extra lib directories
link_directories(/usr/local/lib)

add_executable(hi audio2.cpp)

# specify the dependency on an extra library
target_link_libraries(hi allegro allegro_main allegro_acodec allegro_audio)


