cmake_minimum_required(VERSION 3.22)

project(example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ConceptualExample ${CMAKE_CURRENT_SOURCE_DIR}/ConceptualExample.cpp)

add_executable(example ${CMAKE_CURRENT_SOURCE_DIR}/Program.cpp)

target_link_libraries(example ConceptualExample)

install(TARGETS example
    RUNTIME DESTINATION bin
)

set(CPACK_PACKAGE_VERSION 1.0.0)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third-party/gtest)
    add_executable(check tests/test.cpp)
    target_link_libraries(check
        gtest_main
    )
    add_test(NAME check COMMAND check)
endif()

include(CPack.cmake)
