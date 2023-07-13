project(video_codec_analyzer)

cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Werror -fno-omit-frame-pointer)

add_subdirectory(example)
add_subdirectory(tool)