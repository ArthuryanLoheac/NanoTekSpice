# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(nanotekspice LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

# Include the headers directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set the sources files
set(MAIN Main.cpp)
file(GLOB_RECURSE SRC "src/**.cpp")
file(GLOB_RECURSE TEST_SRC "tests/**.cpp")

# Create the executables
add_executable(${PROJECT_NAME} ${MAIN} ${SRC})
add_executable(unit_tests ${SRC} ${TEST_SRC})

# Set the coverage compile options
target_compile_options(unit_tests PRIVATE --coverage)

# Link the criterion library
target_link_libraries(unit_tests criterion gcov)

# Set fclean target
add_custom_target(fclean
    COMMAND rm -rf ${PROJECT_NAME} unit_tests
)

# Set re target
add_custom_target(re
    COMMAND fclean
    COMMAND make
)

# Set tests_run target
add_custom_target(tests_run
    COMMAND ./unit_tests
    COMMAND gcovr -r ${CMAKE_SOURCE_DIR} --exclude tests/ --exclude CMakeFiles/
    DEPENDS unit_tests
)
