include_directories(${PROJECT_SOURCE_DIR}/edolphin_cge)
include_directories(${PROJECT_SOURCE_DIR}/edolphin_base)
link_directories(${PROJECT_BINARY_DIR}/lib)

set(SOURCE_SRC
	Main.cpp
	)

set(EXCUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(test_game ${SOURCE_SRC})
target_link_libraries(test_game libedpbase)
target_link_libraries(test_game libedpcge)
set_target_properties(test_game PROPERTIES COMPILE_FLAGS "-Wall -pedantic -g")

#GET_TARGET_PROPERTY(CF test_game COMPILE_FLAGS)
#message(STATUS "--------------------------------------")
#message(STATUS ${CF})
#message(STATUS "--------------------------------------")



