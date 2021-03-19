add_library(math_functions math_functions.cpp)

target_include_directories(math_functions
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
        )

option(USE_MYMATH "Use tutorial provided math implementation" ON)
if (USE_MYMATH)

    target_compile_definitions(math_functions PRIVATE "USE_MYMATH")

    add_executable(make_table make_table.cpp)

    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/table.h
        COMMAND make_table ${CMAKE_CURRENT_BINARY_DIR}/table.h
        DEPENDS make_table
        )

    add_library(mysqrt STATIC mysqrt.cpp ${CMAKE_CURRENT_BINARY_DIR}/table.h)

    target_include_directories(mysqrt PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

    set_target_properties(mysqrt PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS})

    target_link_libraries(math_functions PRIVATE mysqrt)
endif()

# define the symbol stating we are using the declspec(dllexport) when building on windows
target_compile_definitions(math_functions PRIVATE "EXPORTING_MYMATH")

set(installable_libs math_functions)
if (TARGET mysqrt)
    list(APPEND installable_libs mysqrt)
endif()

install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES math_functions.h DESTINATION include)
