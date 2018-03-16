cmake_minimum_required(VERSION 3.10)
project(DiepPlusPlus)

set(CMAKE_CXX_STANDARD 17)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

# Set version information in a config.h file
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)
include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "Diep")
add_executable(${EXECUTABLE_NAME} src/main.cpp src/Window/WindowHandler.cpp src/Window/WindowHandler.hh src/ECS/Systems/MoveSystem.cpp src/ECS/Systems/MoveSystem.hh src/ECS/Components/PositionComponent.hh src/ECS/Components/MoveComponent.hh src/ECS/Systems/EventSystem.hh src/ECS/Components/DrawableComponent.hh src/ECS/Systems/DrawableSystem.cpp src/ECS/Systems/DrawableSystem.hh)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# ECS
include_directories("${CMAKE_MODULE_PATH}/ECS")

# Detect and add SFML
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
include(CPack)
