cmake_minimum_required(VERSION 3.10)
project(BoostExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adjust Boost paths
set(BOOST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../boost/boost_dir)
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

# Create executable
add_executable(boost_example test_boost.cpp)
target_include_directories(boost_example PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(boost_example PRIVATE ${Boost_LIBRARIES})