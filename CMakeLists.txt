# Run 
# C:\tmp\CMakeSubTest\build>"c:\Program Files\CMake\bin\cmake" ..\
# C:\tmp\CMakeSubTest\build>"c:\Program Files\CMake\bin\cmake" --build %CD%

cmake_minimum_required(VERSION 3.0.0)
cmake_minimum_required(VERSION 3.10)
project(EModLib VERSION 0.2 DESCRIPTION "Library for modeling emotions")

# target_sources 
set( SOURCES src/stimulus.cpp src/Affect.cpp src/Mood.cpp src/Personality.cpp src/Rock.cpp src/Gusher.cpp src/Empath.cpp src/Intellectual.cpp src/PeopleFactory.cpp src/EmotionsModelLib.cpp )
set( HEADERS include/IAffect.h include/IPerson.h include/stimulus.h include/Affect.h include/Mood.h include/Personality.h include/Rock.h include/Gusher.h include/Empath.h include/Intellectual.h include/PeopleFactory.h include/EmotionsModelLib.h )

#You declared MyProjectLib as a shared library, so unless you exported all or part of the symbols of the library, you will only have a .dll designed to be loaded at runtime, 
#and no .lib to link against at compile time as you're trying to do.
#A quick solution may be to declare MyProjectLib as a static library:
#add_library(MyProjectLib STATIC ...)
#Another option could be to use "new" cmake features to export all symbols (see this article):
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(libEModLib SHARED ${SOURCES} ${HEADERS} )

# If you work with subdirectories, it is not very convenient to include relative path like "../include/mylib.h". So, pass top directory in included directories:
target_include_directories(libEModLib PRIVATE include)
