cmake_minimum_required(VERSION 3.15)

project(step6 VERSION 1.6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial provided math functions" ON)

configure_file(step6_config.h.in step6_config.h)

if(USE_MYMATH)
    add_subdirectory(math_functions)
    list(APPEND EXTRA_LIBS math_functions)
endif()

add_executable(step6 main.cpp)

target_include_directories(step6 PUBLIC ${PROJECT_BINARY_DIR})
target_link_libraries(step6 PUBLIC ${EXTRA_LIBS})

install(TARGETS step6 DESTINATION bin)
install(FILES ${PROJECT_BINARY_DIR}/step6_config.h DESTINATION include)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)
