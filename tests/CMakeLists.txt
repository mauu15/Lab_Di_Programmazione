enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runUnitTests test_note.cpp
        test_note_manager.cpp
        test_collections.cpp
        ../src/Collection.cpp
)

target_link_libraries(runUnitTests gtest gtest_main pthread Note)
