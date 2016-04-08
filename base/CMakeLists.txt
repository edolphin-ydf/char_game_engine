
set(LIB_SRC 
	ArcObject.cpp
	AutoReleasePool.cpp
	AutoReleasePoolManager.cpp
	)

add_library(libbase ${LIB_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libbase PROPERTIES OUTPUT_NAME "base")

add_subdirectory(test)


