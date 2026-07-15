cmake_minimum_required(VERSION 3.10)

# set peoject
project(tstd
	VERSION 1.0.0
	DESCRIPTION "my standard library for C/C++"
	LANGUAGES CXX
)

# project version
set(PROJECT_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(PROJECT_VERSION_PATCH ${PROJECT_VERSION_PATCH})

# compiler option
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# source
set(SOURCES
	src/base/base.c
	src/converter/converter.c
	src/environment/environment.c
	src/files/directorySuite.cpp
	src/files/fileSuite.cpp
	src/math/complex.cpp
	src/window/window.cpp
	src/window/windowProcedure.cpp
)

# header
set(HEADERS
	include/tstd.h
	include/tstd_definition.h
	include/base/base.h
	include/converter/converter.h
	include/debug/measure.hpp
	include/environment/environment.hpp
	include/files/directorySuite.hpp
	include/files/fileSuite.hpp
	include/math/complex.hpp
	include/math/vector.hpp
	include/memory/memoryHandler.hpp
	include/window/window.hpp
	include/window/windowProcedure.hpp
)

# include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# make file group for VS
source_group(
	TREE ${PROJECT_SOURCE_DIR}
	PREFIX "Source Files"
	FILES ${SOURCES}
)
source_group(
	TREE ${PROJECT_SOURCE_DIR}
	PREFIX "Header Files"
	FILES ${HEADERS}
)

# make a exe
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# make a static lib
add_library(${PROJECT_NAME}_lib STATIC
	${SOURCES}
)

# make a shared lib
add_library(${PROJECT_NAME}_shared SHARED
	${SOURCES}
)

add options of library
set_target_properties(${PROJECT_NAME}_shared PROPERTIES
	VERSION ${PROJECT_VERSION}
	SOVERSION ${PROJECT_VERSION_MAJOR}
)

# install option
install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
