cmake_minimum_required(VERSION 3.8)
project(Serializer VERSION 1.0.0 LANGUAGES CXX)

option(Serializer_BuildTests "Build the unit tests when BUILD_TESTING is enabled." ON)

set(SOURCES
	"include/BinaryDeserializer.hpp"
	"include/BinaryPacker.hpp"
	"include/BinarySerializer.hpp"
	"include/BinaryUnpacker.hpp"
	"include/TypeMap.hpp")

add_library(${PROJECT_NAME} INTERFACE ${SOURCES})
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include>
)

include(CTest)
if(BUILD_TESTING AND Serializer_BuildTests)
    add_subdirectory(Tests)
endif()