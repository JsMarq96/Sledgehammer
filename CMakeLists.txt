cmake_minimum_required(VERSION 3.21)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(sledgehammer)

file(GLOB H_SOURCES "sledgehammer/*.h")
file(GLOB C_SOURCES "sledgehammer/*.c")
file(GLOB SUBFOLDER_H_SOURCES "sledgehammer/*/*.h")
file(GLOB SUBFOLDER_C_SOURCES "sledgehammer/*/*.c")

add_library(sledgehammer ${C_SOURCES} ${H_SOURCES} ${SUBFOLDER_H_SOURCES} ${SUBFOLDER_C_SOURCES})

set_target_properties(sledgehammer PROPERTIES C_STANDARD 23 LINKER_LANGUAGE C)

add_subdirectory(libraries/cglm)
target_link_libraries(sledgehammer PUBLIC m cglm)
target_include_directories(sledgehammer PUBLIC ".")