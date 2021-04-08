cmake_minimum_required(VERSION 3.10)
project(Numeros_Complexos C)

set(CMAKE_C_STANDARD 99)

add_executable(Numeros_Complexos
        Complexo.c
        Complexo.h
        complexo_lf.c
        complexo_double.h
        complexo_long_int.h
        complexo_ld.c
        complexo_racional.h
        complexo_racional.c
        converte_complexos.c
        converte_complexos.h
        main.c)

target_link_libraries(Numeros_Complexos m)