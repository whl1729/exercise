cmake_minimum_required(VERSION 3.5)

project(step3 VERSION 3.3)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file(step3_config.h.in step3_config.h)

if (USE_MYMATH)
    add_subdirectory(math_functions)
    list(APPEND EXTRA_LIBS math_functions)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(step3 main.cpp)

target_link_libraries(step3 PUBLIC "${EXTRA_LIBS}")
target_include_directories(step3 PUBLIC "${PROJECT_BINARY_DIR}")
