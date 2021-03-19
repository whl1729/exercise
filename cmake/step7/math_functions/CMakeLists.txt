add_executable(make_table make_table.cpp)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/table.h
    COMMAND make_table ${CMAKE_CURRENT_BINARY_DIR}/table.h
    DEPEMDS make_table
    )

add_library(math_functions
            mysqrt.cpp
            ${CMAKE_CURRENT_BINARY_DIR}/table.h
            )

target_include_directories(math_functions
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
        )

install(TARGETS math_functions DESTINATION lib)
install(FILES math_functions.h DESTINATION include)
