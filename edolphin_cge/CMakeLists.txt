
include_directories(${PROJECT_SOURCE_DIR}/edolphin_base)

set(LIB_SRC 
	Game.cpp
	)

add_library(libedpcge ${LIB_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libedpcge PROPERTIES OUTPUT_NAME "edpcge")



