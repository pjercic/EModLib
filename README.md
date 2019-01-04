# Emotions Model Library - EModLib

This is a C++11 library that models human emotions.

Affective calculation is based on multi spring system physical modeling. Stimulus presents a temporary attachment of the spring system to a fixed wall, after which the spring is released and the system converges to a stable state, towards defined personality.

 0  k0        xp       kp    xm    km     xa     ka |Stimulus|
||-\/\/-|Personality|-\/\/-|Mood|-\/\/-|Affect|-\/\/-||

*if stimulus is not available, ka becomes 0*

##Applications
* Console Application
* GUI Application
* Unity3d plug-in

##Specifications
**Technology:** C++11
**OS:** Windows, Linux, OSX
**Tooling:** CMake, Make, Qt5, Unity3D
