cmake_minimum_required(VERSION 3.10)

project(01.statistics
)

add_executable(statistics
    main.cpp
    Min.cpp
    Max.cpp
    Mean.cpp
    Std.cpp
    Pct.cpp
    IStatistics.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(statistics PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(statistics PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

set_target_properties(statistics
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)