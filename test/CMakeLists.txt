# Structure C:\tmp\CMakeTest [code]\build [CMakeLists.txt]
# C:\tmp\CMakeTest\build>"..\..\Program Files\CMake\bin\cmake" ../
# C:\tmp\CMakeTest\build>"..\..\..\Program Files\CMake\bin\cmake" --build %CD%
# C:\tmp\CMakeTest\build>"..\..\..\Program Files\CMake\bin\ctest" -j4 (paralel jobs) --output-on-failure (details on failure) --gtest_output="xml:report.xml" --gtest_repeat=2 --gtest_filter=SquareRootTest.*-SquareRootTest.Zero* --gtest_break_on_failure
cmake_minimum_required(VERSION 2.8.12)

# Third-party library
include(ExternalProject)
ExternalProject_Add(googletest
    PREFIX "${CMAKE_BINARY_DIR}/lib"
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "master"
    CMAKE_ARGS 	-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/lib/installed
				-Dgtest_force_shared_crt=ON
	
	# Disable install step
#	INSTALL_COMMAND ""
)

# Prevent build on all targets build
set_target_properties(googletest PROPERTIES EXCLUDE_FROM_ALL TRUE)

# Define ${CMAKE_INSTALL_...} variables
include(GNUInstallDirs)

# Specify where third-party libraries are located
link_directories(${CMAKE_BINARY_DIR}/lib/installed/${CMAKE_INSTALL_LIBDIR})
include_directories(${CMAKE_BINARY_DIR}/lib/installed/${CMAKE_INSTALL_INCLUDEDIR})

# This is required for googletest
find_package(Threads REQUIRED)

# target_sources 
# target_sources(cmake-sample2-main PUBLIC "../src/main.c")
set( SOURCES_TEST test.cpp )
#set( HEADERS_TEST include/MyClass.h )

# Test
add_executable(EModLibTest ${SOURCES_TEST})
# Define the libraries this project depends upon
target_link_libraries(EModLibTest libEModLib gtest Threads::Threads)
# Make sure third-party is built before executable
add_dependencies(EModLibTest googletest)
#set_target_properties(EModLibTest PROPERTIES EXCLUDE_FROM_ALL TRUE)

# has target scope—it adds x/y to the include path for target t.
# You want the former one if all of your targets use the include directories in question. You want the latter one if the path is specific to a target, or if you want finer control of the path's visibility. The latter comes from the fact that target_include_directories() supports the PRIVATE, PUBLIC, and INTERFACE qualifiers.
target_include_directories(EModLibTest PRIVATE ${CMAKE_SOURCE_DIR}/include)
#include_directories(${CMAKE_BINARY_DIR}/include)

#possibly add to main after subdirectory
add_test(MyEmotionsModelLibraryTest EModLibTest)

# and your CMake target to which the command applies is MyTest, then you could add the following to your CMakeLists.txt:
IF (WIN32)
add_custom_command(TARGET EModLibTest POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${CMAKE_BINARY_DIR}/Debug/libEModLib.dll"      # <--this is in-file
        $<TARGET_FILE_DIR:EModLibTest>)                 # <--this is out-file path
ELSE()
  # set stuff for other systems
ENDIF()