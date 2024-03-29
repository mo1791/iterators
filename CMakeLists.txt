#
cmake_minimum_required(VERSION 3.5)

project(
    iterator_l
    VERSION 1.0.0
    DESCRIPTION "C++ Iterators Concepts Satisfaction"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(DEFAULT_BUILD_TYPE "Release")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)

    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

include(GNUInstallDirs)

set(SOURCE_FILES
    src/random_access_iterator.cxx
    src/bidirectional_iterator.cxx
    src/contiguous_iterator.cxx
    src/forward_iterator.cxx
    src/output_iterator.cxx
    src/intput_iterator.cxx
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1)

install(TARGETS ${PROJECT_NAME} EXPORT IteratorLConfig
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(EXPORT IteratorLConfig DESTINATION share/lib/cmake)

export(TARGETS ${PROJECT_NAME} FILE IteratorLConfig.cmake)

configure_file(iterator_l.pc.in iterator_l.in @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/iterator_l.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)