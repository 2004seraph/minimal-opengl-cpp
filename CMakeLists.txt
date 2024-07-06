# CMakeList.txt : CMake project for CyanArgParser, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8)

IF(DEFINED ENV{VCPKG_ROOT})
    message(STATUS "vcpkg seems to be installed correctly: $ENV{VCPKG_ROOT}")
ELSE()
  message( FATAL_ERROR "vcpkg is not installed, or envar VCPKG_ROOT is not set!" )
ENDIF()

set(
    CMAKE_CXX_STANDARD 20
)

include(CMakePackageConfigHelpers)

project(
    "test"
    VERSION 1.0.0
    DESCRIPTION "test"
)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(
#        OpenGL REQUIRED
        glew CONFIG REQUIRED
        glfw3 CONFIG REQUIRED
)

SET(
        APP_EXE basicApp
)

ADD_EXECUTABLE(
        ${APP_EXE}
        app/main.cpp
)

include_directories(
        ${PROJECT_NAME}
        "../../include/"
        ${GLEW_INCLUDE_DIRS}
        ${GLFW_INCLUDE_DIRS}
)

target_include_directories(
        ${APP_EXE}
        PRIVATE
        ${SOURCE_SUBDIR}/include
)

TARGET_LINK_LIBRARIES(
        ${APP_EXE}
        GLEW::GLEW
        glfw
)