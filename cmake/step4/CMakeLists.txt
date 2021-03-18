cmake_minimum_required(VERSION 3.5)

project(step4 VERSION 4.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file(step4_config.h.in step4_config.h)

if (USE_MYMATH)
    add_subdirectory(math_functions)
    list(APPEND EXTRA_LIBS math_functions)
endif()

add_executable(step4 main.cpp)

target_link_libraries(step4 PUBLIC ${EXTRA_LIBS})

target_include_directories(step4 PUBLIC "${PROJECT_BINARY_DIR}")

install(TARGETS step4 DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/step4_config.h" DESTINATION include)
