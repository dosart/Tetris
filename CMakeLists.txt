###################################################################################################
##
##      Information about project
##
###################################################################################################

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Tetris)
project(${PROJECT_NAME} VERSION 0.0.1
        DESCRIPTION "Tetris game"
        LANGUAGES CXX
        )

###################################################################################################
##
##      Project options
##
###################################################################################################

option(USE_DOC "Turn on documentation" ON)
option(USE_TEST "Turn on testing" ON)

###################################################################################################
##
##      Compilation options
##
###################################################################################################

add_compile_options(
        -Werror

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wctor-dtor-privacy
        -Wenum-compare
        -Wfloat-equal
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-conversion
        -Wsign-promo
)

###################################################################################################
##
##      Source files
##
###################################################################################################

add_executable(${PROJECT_NAME})
set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_sources(
        ${PROJECT_NAME}
        PRIVATE
        include/tetris.h
        include/render.h
        include/controller.h
        include/tetromino.h

        src/main.cpp
        src/render.cpp
        src/controller.cpp
        src/tetramino.cpp
        src/tetris.cpp
)

set(PROJECT_INCLUDE_DIR include)
target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${PROJECT_INCLUDE_DIR}
)

###################################################################################################
##
##      SFML link
##
###################################################################################################

find_package(SFML 2.5 COMPONENTS audio graphics)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

###################################################################################################
##
##      ResourcesLoader link
##
###################################################################################################

add_subdirectory(external/ResourcesLoader)
target_link_libraries(${PROJECT_NAME} ResourcesLoader::library)


###################################################################################################
##
##      Documentation
##
###################################################################################################

if (NOT USE_DOC)
    message(STATUS "Autodocumentation is disabled")
else ()
    add_subdirectory(doc)
endif ()

###################################################################################################
##
##      Tests
##
###################################################################################################

if (NOT USE_TEST)
    message(STATUS "Tests is disabled")
else ()
    add_subdirectory(test)
endif ()