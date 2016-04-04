
set(LIB_SRC 
	ArcObject.cpp
	ArcObject.cpp
	AutoReleasePool.cpp
	)

add_library(libedpbase ${LIB_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libedpbase PROPERTIES OUTPUT_NAME "edpbase")



