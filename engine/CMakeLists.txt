
include_directories(${PROJECT_SOURCE_DIR}/base)
link_directories(${PROJECT_BINARY_DIR}/lib)

set(LIB_SRC 
	Game.cpp
	FPoint2D.cpp
	GameObject.cpp
	PicLoader.cpp
	Point2D.cpp
	Color.cpp
	Line.cpp
	Scene.cpp
	PainterCursor.cpp
	)

add_library(libengine ${LIB_SRC})
target_link_libraries(libengine curses)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libengine PROPERTIES OUTPUT_NAME "engine")

message(STATUS ${PROJECT_SOURCE_DIR})


add_subdirectory(test)
