cmake_minimum_required(VERSION 3.15)

# set peoject
project(tstd
	VERSION 1.0.0
	DESCRIPTION "my standard library for C/C++"
	LANGUAGES C CXX
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
	include/environment/environment.h
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

# macro definition
add_compile_definitions(UNICODE _UNICODE)

# MSVC
if(MSVC)
    # UTF-8
    add_compile_options(/utf-8)

    add_compile_definitions(_SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING)
endif()

# make a static lib
add_library(${PROJECT_NAME}_static STATIC
	${SOURCES}
)

# make a shared lib
add_library(${PROJECT_NAME}_shared SHARED
	${SOURCES}
)

# add options of library
set_target_properties(${PROJECT_NAME}_shared PROPERTIES
	VERSION ${PROJECT_VERSION}
	SOVERSION ${PROJECT_VERSION_MAJOR}
	OUTPUT_NAME ${PROJECT_NAME}
)

# set include directory
target_include_directories(${PROJECT_NAME}_static PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)
target_include_directories(${PROJECT_NAME}_shared PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

# install option
install(TARGETS ${PROJECT_NAME}_static ${PROJECT_NAME}_shared
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)

# make a test.exe
#add_executable(test
#	test/test_tstd.cpp
#)

# link
#target_link_libraries(test PRIVATE ${PROJECT_NAME}_static)
