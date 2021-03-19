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

enable_testing()

# does the application run?
add_test(NAME Runs COMMAND step4 25)

# does the usage message work?
add_test(NAME Usage COMMAND step4)
set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")

# define a function to simplify adding tests
function(do_test target arg result)
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endfunction(do_test)

#do a bunch of result based tests
do_test(step4 4 "4 is 2")
do_test(step4 9 "9 is 3")
do_test(step4 5 "5 is 2.236")
do_test(step4 7 "7 is 2.645")
do_test(step4 25 "25 is 5")
do_test(step4 -25 "-25 is [-nan|nan|0]")
do_test(step4 0.0001 "0.0001 is 0.01")
