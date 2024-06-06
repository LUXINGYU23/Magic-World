cmake_minimum_required(VERSION 3.0.0)
project(magic VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(magic main.c display.c file.c exceptio.c graphics.c monsters.c scene.c solve.c genlib.c gcalloc.h strlib.c extgraph.h random.c)
target_link_libraries(magic winmm gdi32 Msimg32)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
