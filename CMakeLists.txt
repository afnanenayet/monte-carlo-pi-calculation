# CMakeLists.txt for monte_carlo_pi.cpp
# Generates a binary and compilation database for monte_carlo_pi.cpp

cmake_minimum_required(VERSION 3.10)
project(monte_carlo_pi)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Necessary for clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Versioning
set(monte_carlo_pi_VERSION_MAJOR 0)
set(monte_carlo_pi_VERSION_MINOR 1)

add_executable(monte_carlo_pi monte_carlo_pi.cpp)
