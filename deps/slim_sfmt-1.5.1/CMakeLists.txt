project(slim_sfmt LANGUAGES C)
include_directories(${CMAKE_CURRENT_LIST_DIR})

set(SLIM_SFMT_SOURCES ${CMAKE_CURRENT_LIST_DIR}/SFMT.c)
if(BUILD_SHARED_LIBS)
    add_library(slim_sfmt SHARED ${SLIM_SFMT_SOURCES})
else()
    add_library(slim_sfmt STATIC ${SLIM_SFMT_SOURCES})
endif()
target_compile_definitions( slim_sfmt PRIVATE "SFMT_MEXP=19937" )

install(TARGETS slim_sfmt)
