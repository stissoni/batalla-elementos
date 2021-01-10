cmake_minimum_required(VERSION 3.17)
project(TP3_diccionario)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TP3_diccionario
        Diccionario.cpp
        Diccionario.h
        Nodo.cpp
        Nodo.h main.cpp
        Agua.cpp Agua.h
        Tierra.cpp Tierra.h
        Fuego.cpp Fuego.h
        Aire.cpp Aire.h
        Personaje.cpp Personaje.h)
