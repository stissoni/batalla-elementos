cmake_minimum_required(VERSION 3.17)
project(TP3)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp casillero.h DIccionario.cpp Diccionario.h juego.h lago.cpp Lago.h
        main.cpp menu.cpp menu_juego.h montania.cpp montania.h Nodo.cpp Nodo.h personaje.cpp personaje.h
        personaje_de_agua.cpp personaje_de_agua.h personaje_de_aire.cpp personaje_de_aire.h personaje_de_fuego.cpp personaje_de_fuego.h
        personaje_de_tierra.cpp personaje_de_tierra.h precipicio.cpp precipicio.h vacio.cpp camino.h camino.cpp vacio.h)