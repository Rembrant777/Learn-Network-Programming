cmake_minimum_required(VERSION 3.10)
project(BoostExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adjust Boost paths
set(BOOST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/boost/)
set(BOOST_INCLUDE_DIRS ${BOOST_ROOT}/include)
set(BOOST_LIBRARY_DIRS ${BOOST_ROOT}/lib)

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

# Adjust gtest paths 
set(GTEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/gtest)
set(GTEST_INCLUDE_DIRS ${GTEST_ROOT}/include)
set(GTEST_LIBRARY_DIRS ${GTEST_ROOT}/lib)

# Include gtest paths 
include_directories(${GTEST_INCLUDE_DIRS})
link_directories(${GTEST_LIBRARY_DIRS})

# Find gtest and gmock libraries 
find_library(GTEST_LIB gtest HINTS ${GTEST_LIBRARY_DIRS})
find_library(GTEST_MAIN_LIB gtest_main HINTS ${GTEST_LIBRARY_DIRS})
find_library(GMOCK_LIB gmock HINTS ${GTEST_LIBRARY_DIRS})
find_library(GMOCK_MAIN_LIB gmock_main HINTS ${GTEST_LIBRARY_DIRS})


########### add executable files here ###########

# Create executable
add_executable(boost_example src/test_boost.cpp)
target_include_directories(boost_example PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(boost_example PRIVATE ${Boost_LIBRARIES})

# Create GTest example executable 
add_executable(gtest_example src/test_gtest.cpp)
target_include_directories(gtest_example PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(gtest_example PRIVATE ${GTEST_LIB} ${GTEST_MAIN_LIB} ${GMOCK_LIB} ${GMOCK_MAIN_LIB} pthread)
