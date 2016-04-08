
set(LIB_SRC
	ETest.cpp
	ETestClass.cpp
	TestCaseManager.cpp
	Assert.cpp
	AssertException.cpp
	)

add_library(libetest ${LIB_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libetest PROPERTIES OUTPUT_NAME "etest")


