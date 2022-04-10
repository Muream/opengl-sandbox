cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME OpenglSandbox)

project(${PROJECT_NAME} CXX)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(vendor/GLFW)

include_directories(
    vendor
    vendor/GLFW/include
    vendor/glad/include
    vendor/glm
)

file(GLOB_RECURSE PROJECT_HEADERS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)
file(GLOB_RECURSE PROJECT_SOURCES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.c??)
file(GLOB VENDORS_SOURCES vendor/glad/src/glad.c)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("Vendors" FILES ${VENDORS_SOURCES})

add_executable(
    ${PROJECT_NAME} 
    ${PROJECT_SOURCES} 
    ${PROJECT_HEADERS}
    ${VENDORS_SOURCES}
)

target_link_libraries(${PROJECT_NAME} glfw)