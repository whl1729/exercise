cmake_minimum_required(VERSION 3.5)

project(step2 VERSION 4.0)

configure_file(step2_config.h.in step2_config.h)

option(USE_MYMATH "Use step2 provided math implementation" ON)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

if (USE_MYMATH)
    add_subdirectory(math_functions)
    list(APPEND EXTRA_LIBS "math_functions")
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/math_functions")
endif()

add_executable(step2 main.cpp)

target_link_libraries(step2 PUBLIC ${EXTRA_LIBS})

target_include_directories(step2 PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${EXTRA_INCLUDES}"
                           )

