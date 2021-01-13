cmake_minimum_required(VERSION 3.17)
project(batalla_elementos)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(batalla_elementos
        Agua.cpp
        Agua.h
        Aire.cpp
        Aire.h
        Diccionario.cpp
        Diccionario.h
        Fuego.cpp
        Fuego.h
        funciones.cpp
        funciones.h
        jugador.cpp
        jugador.h
        main.cpp
        menu.cpp
        menu.h
        Nodo.cpp
        Nodo.h
        Personaje.cpp
        Personaje.h
        Tierra.cpp
        Tierra.h)
