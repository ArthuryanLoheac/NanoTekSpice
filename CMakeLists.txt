# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(nanotekspice LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

# Include the headers directories
include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB_RECURSE HEADER_FILES "include/**/*.hpp")
foreach(HEADER_FILE ${HEADER_FILES})
    get_filename_component(HEADER_DIR ${HEADER_FILE} DIRECTORY)
    include_directories(${HEADER_DIR})
endforeach()

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
    COMMAND rm ${PROJECT_NAME}
    COMMAND rm unit_tests
)

# Set re target
add_custom_target(re
    COMMAND make fclean
    COMMAND make
)

# Set tests_run target
add_custom_target(tests_run
    COMMAND ./unit_tests
    COMMAND gcovr -r ${CMAKE_SOURCE_DIR} --exclude tests/ --exclude CMakeFiles/
    DEPENDS unit_tests
)
