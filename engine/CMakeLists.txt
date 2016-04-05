
include_directories(${PROJECT_SOURCE_DIR}/base)
link_directories(${PROJECT_BINARY_DIR}/lib)

set(LIB_SRC 
	Game.cpp
	FPoint2D.cpp
	GameObject.cpp
	PicLoader.cpp
	PixelPoint.cpp
	Point2D.cpp
	)

add_library(libengine ${LIB_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libengine PROPERTIES OUTPUT_NAME "engine")

message(STATUS ${PROJECT_SOURCE_DIR})


