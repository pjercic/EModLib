# make sure the enviroment variable is set in windows
# http://doc.qt.io/qt-5/cmake-manual.html
# https://stackoverflow.com/questions/22215900/add-the-installation-prefix-of-qt5widgets-to-cmake-prefix-path
cmake_minimum_required(VERSION 3.8.2)

project(EModLibGuiApp)

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Turn on automatic invocation of the MOC
set(CMAKE_AUTOMOC ON)

# There may be a way to tell up front if Qt5 is going to be found, but I haven't found
# a foolproof way to do it yet, so settle for the default error message for now.
#if(NOT CMAKE_PREFIX_PATH AND NOT Qt5Widgets_DIR)
#    message(WARNING "CMAKE_PREFIX_PATH is not defined, so find_package may not work. Set the CMAKE_PREFIX_PATH "
#            "environment variable to the install prefix of Qt 5, either on the command line as "
#            "-DCMAKE_PREFIX_PATH=\"path/to/Qt5/lib/cmake\" or with set(CMAKE_PREFIX_PATH path/to/Qt5/lib/cmake)")
#endif(NOT CMAKE_PREFIX_PATH AND NOT Qt5Widgets_DIR)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Make this a GUI application on Windows
if(WIN32)
  set(CMAKE_WIN32_EXECUTABLE ON)
endif()

# Find the QtWidgets library
#find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

# - or -
find_package(Qt5 COMPONENTS Widgets Declarative)
 
# Generate code from ui files
#qt5_wrap_ui(UI_HEADERS mainwindow.ui)

# Generate rules for building source files from the resources
#qt5_add_resources(QRCS resources.qrc)

# Tell CMake to create the helloworld executable
#add_executable(helloworld main.cpp mainwindow.cpp ${UI_HEADERS} ${QRCS})
add_executable(EModLibGuiApp src/main.cpp src/mainwindow.cpp include/mainwindow.h)

target_include_directories(EModLibGuiApp PRIVATE include)
target_include_directories(EModLibGuiApp PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Add the Qt5 Widgets for linking
target_link_libraries(EModLibGuiApp Qt5::Widgets Qt5::WinMain libEModLib)

# and your CMake target to which the command applies is MyTest, then you could add the following to your CMakeLists.txt:
IF (WIN32)
add_custom_command(TARGET EModLibGuiApp POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${CMAKE_BINARY_DIR}/Debug/libEModLib.dll"      # <--this is in-file
        $<TARGET_FILE_DIR:EModLibGuiApp>)                 # <--this is out-file path
ELSE()
  # set stuff for other systems
ENDIF()