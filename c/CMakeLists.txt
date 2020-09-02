cmake_minimum_required(VERSION 3.17)
project(hi)

set(CMAKE_C)
# These are where the include files should be
include_directories(/usr/local/include)

# add extra lib directories
link_directories(/usr/local/lib)

add_executable(hi c_thread.c)
add_executable(hi2 c_audio_thread.c)

# specify the dependency on an extra library
target_link_libraries(hi2 allegro allegro_main allegro_acodec allegro_audio)


