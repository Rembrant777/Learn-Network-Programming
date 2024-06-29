cmake_minimum_required(VERSION 3.10)
project(m1_proj)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adjust gtest paths 
set(GTEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../submodules/gtest_installed)
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

# Create GTest example executable 
add_executable(gtest_example src/test_gtest.cpp)
target_include_directories(gtest_example PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(gtest_example PRIVATE ${GTEST_LIB} ${GTEST_MAIN_LIB} ${GMOCK_LIB} ${GMOCK_MAIN_LIB} pthread)

# Create Thread Test executable 
add_executable(gtest_thread src/MutexLock.h src/ch01_01_thread_safety.cpp)
target_include_directories(gtest_thread PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(gtest_thread PRIVATE ${GTEST_LIB} ${GTEST_MAIN_LIB} ${GMOCK_LIB} ${GMOCK_MAIN_LIB} pthread)