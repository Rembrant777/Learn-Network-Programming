cmake_minimum_required(VERSION 3.10)
project(m1_proj)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Boost
find_package(Boost REQUIRED COMPONENTS system filesystem)

# Include Boost directories
include_directories(${Boost_INCLUDE_DIRS})


if(Boost_FOUND)
    message(STATUS "Found Boost ${Boost_VERSION}")
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
else()
    message(FATAL_ERROR "Boost not found")
endif()

# Find Google Test
find_package(GTest REQUIRED)


# Include GTest directories
include_directories(${GTEST_INCLUDE_DIRS})

# Manually specify gmock library paths
set(GMOCK_LIB "/usr/lib/aarch64-linux-gnu/libgmock.a")
set(GMOCK_MAIN_LIB "/usr/lib/aarch64-linux-gnu/libgmock_main.a")

########### add executable files here ###########
# Create executable for Boost example
add_executable(boost_example src/test_boost.cpp)
target_link_libraries(boost_example PRIVATE ${Boost_LIBRARIES})

# Create executable for GTest example
add_executable(gtest_example src/test_gtest.cpp)
target_link_libraries(gtest_example PRIVATE GTest::GTest GTest::Main ${GMOCK_LIB} ${GMOCK_MAIN_LIB} pthread)
