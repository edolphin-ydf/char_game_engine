include_directories(${PROJECT_SOURCE_DIR}/base)
include_directories(${PROJECT_SOURCE_DIR}/engine)

link_directories(${PROJECT_BINARY_DIR}/lib)

set(SOURCE_SRC
	Main.cpp
	ETest.cpp
	ETestClass.cpp
	TestCaseManager.cpp
	)

set(EXCUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(test ${SOURCE_SRC})
target_link_libraries(test libbase)
target_link_libraries(test libengine)
set_target_properties(test PROPERTIES COMPILE_FLAGS "-Wall -pedantic -g")

#GET_TARGET_PROPERTY(CF test_game COMPILE_FLAGS)
#message(STATUS "--------------------------------------")
#message(STATUS ${CF})
#message(STATUS "--------------------------------------")



