cmake_minimum_required(VERSION 3.15)

project(step9 VERSION 1.9)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

configure_file(step9_config.h.in step9_config.h)

add_subdirectory(math_functions)

add_executable(step9 main.cpp)

target_include_directories(step9 PUBLIC ${PROJECT_BINARY_DIR})
target_link_libraries(step9 PUBLIC math_functions)

install(TARGETS step9 DESTINATION bin)
install(FILES ${PROJECT_BINARY_DIR}/step9_config.h DESTINATION include)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(cpack_package_version_minor "${Tutorial_VERSION_MINOR}")
include(CPack)
