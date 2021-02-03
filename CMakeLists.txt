cmake_minimum_required(VERSION 3.17)
project(batalla_elementos)

set(CMAKE_CXX_STANDARD 14)

add_executable(batalla_elementos main.cpp camino.h camino.cpp casillero.h casillero.cpp DIccionario.cpp Diccionario.h
        juego.h lago.cpp lago.h menu.cpp menu.h montania.h montania.cpp Nodo.cpp Nodo.h personaje.cpp personaje.h
        personaje_de_tierra.h personaje_de_tierra.cpp personaje_de_fuego.h personaje_de_fuego.cpp personaje_de_aire.h
        personaje_de_aire.cpp personaje_de_agua.h personaje_de_agua.cpp precipicio.cpp precipicio.h vacio.cpp vacio.h
        volcan.h volcan.cpp arista.cpp arista.h vertice.cpp vertice.h)