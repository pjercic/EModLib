# Structure C:\tmp\CMakeTest [code]\build [CMakeLists.txt]
# C:\tmp\CMakeTest\build>"..\..\Program Files\CMake\bin\cmake" %CD%
# C:\tmp\CMakeTest\build>"..\..\..\Program Files\CMake\bin\cmake" --build %CD%
cmake_minimum_required(VERSION 2.8.12)

# target_sources 
# target_sources(cmake-sample2-main PUBLIC "../src/main.c")
set( SOURCES_APP src/ConsoleApp.cpp )
set( HEADERS_APP include/ConsoleApp.h )

ADD_EXECUTABLE( EModLibConsoleApp ${SOURCES_APP} ${HEADERS_APP} )

# has target scope—it adds x/y to the include path for target t.
# You want the former one if all of your targets use the include directories in question. You want the latter one if the path is specific to a target, or if you want finer control of the path's visibility. The latter comes from the fact that target_include_directories() supports the PRIVATE, PUBLIC, and INTERFACE qualifiers.
target_include_directories(EModLibConsoleApp PRIVATE include)
target_include_directories(EModLibConsoleApp PRIVATE ${CMAKE_SOURCE_DIR}/include)
#include_directories(${CMAKE_BINARY_DIR}/include)

# Define the libraries this project depends upon
# if importing external libraries, use find_package(Foo 2.0 REQUIRED)
target_link_libraries(EModLibConsoleApp libEModLib)




# I'd use add_custom_command to achieve this along with cmake -E copy_if_different.... For full info run

# cmake --help-command add_custom_command
# cmake -E


# So in your case, if you have the following directory structure:

# /CMakeLists.txt
# /src
# /libs/test.dll

# and your CMake target to which the command applies is MyTest, then you could add the following to your CMakeLists.txt:
IF (WIN32)
add_custom_command(TARGET EModLibConsoleApp POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${CMAKE_BINARY_DIR}/Debug/libEModLib.dll"      # <--this is in-file
        $<TARGET_FILE_DIR:EModLibConsoleApp>)                 # <--this is out-file path
ELSE()
  # set stuff for other systems
ENDIF()

# If you just want the entire contents of the /libs/ directory copied, use cmake -E copy_directory:

# add_custom_command(TARGET MyTest POST_BUILD
    # COMMAND ${CMAKE_COMMAND} -E copy_directory
        # "${PROJECT_SOURCE_DIR}/libs"
        # $<TARGET_FILE_DIR:MyTest>)


# If you need to copy different dlls depending upon the configuration (Release, Debug, eg) then you could have these in subdirectories named with the corresponding configuration: /libs/Release, and /libs/Debug. You then need to inject the configuration type into the path to the dll in the add_custom_command call, like this:

# add_custom_command(TARGET MyTest POST_BUILD
    # COMMAND ${CMAKE_COMMAND} -E copy_directory
        # "${PROJECT_SOURCE_DIR}/libs/$<CONFIGURATION>"
        # $<TARGET_FILE_DIR:MyTest>)

