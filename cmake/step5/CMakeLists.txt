cmake_minimum_required(VERSION 3.15)

project(step5 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial provided math functions" ON)

configure_file(step5_config.h.in step5_config.h)

if (USE_MYMATH)
    add_subdirectory(math_functions)
    list(APPEND EXTRA_LIBS math_functions)
endif()

add_executable(step5 main.cpp)

target_include_directories(step5 PUBLIC ${PROJECT_BINARY_DIR})
target_link_libraries(step5 PUBLIC ${EXTRA_LIBS})

install(TARGETS step5 DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/step5_config.h" DESTINATION include)
