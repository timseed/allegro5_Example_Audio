cmake_minimum_required(VERSION 3.17)
project(cpp_only_threads)
set(CMAKE_CXX)
# These are where the include files should be
include_directories(/usr/local/include)

# add extra lib directories
link_directories(/usr/local/lib)

add_executable(cpp_audio_thread audio2.cpp wav/arriving.wav wav/leaving.wav)

set(RESOURCE_FILES
  wav/arriving.wav,
  wav/leaving.wav
)

# specify the dependency on an extra library
target_link_libraries(cpp_audio_thread allegro allegro_main allegro_acodec allegro_audio)




# We have another project with its own CMakeList also ... so add that
add_subdirectory(c)

# 
# cmake -DCMAKE_INSTALL_PREFIX=$HOME/allegro
install(TARGETS cpp_audio_thread
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
install(FILES wav/leaving.wav DESTINATION share)
install(FILES wav/arriving.wav DESTINATION share)
