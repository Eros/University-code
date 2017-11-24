cmake_minimum_required(VERSION 3.8)
project(UniversityStuff)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES StringsAndStuff.c MySkeleton.c 16/16.1.c 16/FileHandler.c)
add_executable(UniversityStuff ${SOURCE_FILES} MySkeleton.c)