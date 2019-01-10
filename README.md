# Emotions Model Library - EModLib

This is a C++11 library that models human emotions.

## Introduction: Why EModLib?

If we want to make technology for humans, it needs to have human-like features, so it is easier for humans to understand. Emotions are one such feature.

## Nomenclature

**Affect** is the core of human emotions and it consists of *arousal and valence dimensions*. Humans percieve theis emotions based on their *duration*: **short-term affect, long-term mood and life-long personality**. Each human fits into a different **personality type**. Human emotional state is changed through **stimulus**.

## Basic Concepts

Affective calculation is based on multi spring system physical modeling. Stimulus presents a temporary attachment of the spring system to a fixed wall, after which the spring is released and the system converges to a stable state, towards defined personality.
 
|0|-//k0//-|Personality (xp)|-//kp//-|Mood (xm)|-//km//-|Affect (xa)|-//ka//-||Stimulus (xs)||

*if stimulus is not available, ka becomes 0*

## Features

- Create a number of Persons with differnt presonality types
- Retrieve current emotional state

## Build

Enter the desired build folder for your OS and use > cmake ../
Alternatively, you can use already built makefiles in the build OS folder to compile the code.

## Applications

* Console Application
* GUI Application
* Unity3d plug-in

## Specifications

**Technology:** C++11

**Platforms:** Windows, Linux, OSX

**Tooling:** CMake, Make, Qt5, Unity3D, GTest and Git (obviously)

## Requirements

- A C++11-standard-compliant compiler

## Known Limitations

- Limited to 10 000 persons
