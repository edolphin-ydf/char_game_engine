include_directories(${PROJECT_SOURCE_DIR}/base)
include_directories(${PROJECT_SOURCE_DIR}/etest)

link_directories(${PROJECT_BINARY_DIR}/lib)

set(SOURCE_SRC
	Main.cpp
	GetterSetterTest.cpp
	ArcObjectTest.cpp
	)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(test_base ${SOURCE_SRC})
target_link_libraries(test_base libbase)
target_link_libraries(test_base libetest)
#set_target_properties(test_base PROPERTIES COMPILE_FLAGS ALL_EXECUTEABLE_BIN_COMPILE_FLAGS)
set_target_properties(test_base PROPERTIES COMPILE_FLAGS "-Wall -pedantic -g")

#GET_TARGET_PROPERTY(CF test_game COMPILE_FLAGS)
#message(STATUS "--------------------------------------")
#message(STATUS ${CF})
#message(STATUS "--------------------------------------")



