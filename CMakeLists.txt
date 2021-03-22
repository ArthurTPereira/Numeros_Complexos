cmake_minimum_required(VERSION 3.10)
project(Numeros_Complexos C)

set(CMAKE_C_STANDARD 99)

add_executable(Numeros_Complexos
        Complexo.c
        Complexo.h
        complexo_double.h
        complexo_ld.c
        complexo_long_int.h
        complexo_racional.h
        complexo_lf.c
        main.c)