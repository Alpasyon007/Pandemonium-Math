# CMake Bulid File
#
# CMake Version
# cmake_minimum_required(VERSION 3.10)

# # Compiler Settings
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Set Variables
# set(SOURCE_DIR src)
# set(MATRIX_SOURCE_DIR Pandemonium-Mat/src)
# set(VECTOR_SOURCE_DIR Pandemonium-Vec/src)
# set(COMMON_SOURCE_DIR Common)

# # Set the project name
# project(PandemoniumMath)

# # Add the executable
# add_executable(
# 	PandemoniumMath
# 	${SOURCE_DIR}/main.cpp
# 	${SOURCE_DIR}/math.h
# 	${COMMON_SOURCE_DIR}/math_consts.h
# 	${VECTOR_SOURCE_DIR}/vector2.h
# 	${VECTOR_SOURCE_DIR}/vector3.h
# 	${MATRIX_SOURCE_DIR}/matrix4x4.h
# 	${MATRIX_SOURCE_DIR}/matrix3x3.h
# 	${VECTOR_SOURCE_DIR}/vector2.cpp
# 	${VECTOR_SOURCE_DIR}/vector3.cpp
# 	${MATRIX_SOURCE_DIR}/matrix4x4.cpp
# 	${MATRIX_SOURCE_DIR}/matrix3x3.cpp
# )

# target_include_directories(
# 	PandemoniumMath PRIVATE 
# 	${MATRIX_SOURCE_DIR}
# 	${VECTOR_SOURCE_DIR}
# 	${COMMON_SOURCE_DIR}
# )

# Include target directories
# target_include_directories(
# 	PandemoniumVec
# 	PRIVATE
# )

# add_library(PandemoniumVec)
# add_library(PandemoniumMat)

# add_subdirectory(Pandemonium-Vec)
# add_subdirectory(Pandemonium-Mat)

set_target_properties(PandemoniumMath PROPERTIES LINKER_LANGUAGE CXX)

# message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(
	PandemoniumMath
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/Include/PandemoniumMath.h
	${CMAKE_CURRENT_SOURCE_DIR}/Common/headers/math_consts.h
	${CMAKE_CURRENT_SOURCE_DIR}/Pandemonium-Vec/headers/vector.h
	${CMAKE_CURRENT_SOURCE_DIR}/Pandemonium-Mat/headers/matrix.h
	${CMAKE_CURRENT_SOURCE_DIR}/Pandemonium-Mat/headers/matrix3x3.h
	${CMAKE_CURRENT_SOURCE_DIR}/Pandemonium-Mat/headers/matrix4x4.h
	${CMAKE_CURRENT_SOURCE_DIR}/Pandemonium-Vec/headers/vector2.h
	${CMAKE_CURRENT_SOURCE_DIR}/Pandemonium-Vec/headers/vector3.h
	${CMAKE_CURRENT_SOURCE_DIR}/Pandemonium-Mat/src/matrix3x3.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Pandemonium-Mat/src/matrix4x4.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Pandemonium-Vec/src/vector2.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Pandemonium-Vec/src/vector3.cpp
)

target_include_directories(
	PandemoniumMath 
	PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/Common/headers
	${CMAKE_CURRENT_SOURCE_DIR}/Pandemonium-Vec/headers
	${CMAKE_CURRENT_SOURCE_DIR}/Pandemonium-Mat/headers
)

# target_link_libraries(
# 	PandemoniumVec
# 	PandemoniumMat
# )