# CMake Bulid File
#
# CMake Version
cmake_minimum_required(VERSION 3.10)

# Compiler Settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set Variables
set(SOURCE_DIR src)

# Set the project name
project(PandemoniumMath)

# Add the executable
add_executable(
	PandemoniumMath
	${SOURCE_DIR}/main.cpp
	${SOURCE_DIR}/math.h
	# ${SOURCE_DIR}/math_consts.h
	Pandemonium-Vec/src/vector2.h
	Pandemonium-Vec/src/vector3.h
	Pandemonium-Mat/src/matrix4x4.h
	Pandemonium-Mat/src/matrix3x3.h
	Pandemonium-Vec/src/vector2.cpp
	Pandemonium-Vec/src/vector3.cpp
	Pandemonium-Mat/src/matrix4x4.cpp
	Pandemonium-Mat/src/matrix3x3.cpp
)

target_include_directories(PandemoniumMath PRIVATE Pandemonium-Mat/src)
target_include_directories(PandemoniumMath PRIVATE Pandemonium-Vec/src)

# Include target directories
# target_include_directories(
# 	PandemoniumVec
# 	PRIVATE
# )