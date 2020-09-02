cmake_minimum_required(VERSION 3.17)
project(cpp_only_threads)
set(CMAKE_CXX)
# These are where the include files should be
include_directories(/usr/local/include)

# add extra lib directories
link_directories(/usr/local/lib)

add_executable(cpp_audio_thread audio2.cpp)

# specify the dependency on an extra library
target_link_libraries(cpp_audio_thread allegro allegro_main allegro_acodec allegro_audio)


