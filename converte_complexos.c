#include <stdlib.h>
#include <math.h>
#include "complexo_racional.h"
#include "converte_complexos.h"
#include "racional.h"

struct R_complexo_st {
    tRacional* real;
    tRacional* img;
};

struct racional {
    long int num;
    long int den;
};

LI_complexo_t* DoubleParaLI(D_complexo_t* complexo) {
    LI_complexo_t* inteiro = (LI_complexo_t*) malloc(sizeof(LI_complexo_t));
    inteiro->real = round(complexo->real);
    inteiro->img = round(complexo->img);
    return inteiro;
}

D_complexo_t* LIparaDouble(LI_complexo_t* complexo) {
    D_complexo_t* var = (D_complexo_t*) malloc(sizeof(D_complexo_t));
    var->real = (double)complexo->real;
    var->img = (double)complexo->img;

    return var;
}

R_complexo_t* DoubleParaR(D_complexo_t* complexo) {
    
    R_complexo_t* racional = (R_complexo_t*) malloc(sizeof(R_complexo_t));
    racional->real = doubleParaRacional(complexo->real);
    racional->img = doubleParaRacional(complexo->img);

    return racional;
}

D_complexo_t* RparaDouble(R_complexo_t* complexo) {
    D_complexo_t* var = (D_complexo_t*) malloc(sizeof(D_complexo_t));
    var->real = complexo->real->num / complexo->real->den;
    var->img = complexo->img->num / complexo->img->den;
    
    return var;
}

LI_complexo_t* RparaLI(R_complexo_t* complexo) {
    LI_complexo_t* inteiro = (LI_complexo_t*) malloc(sizeof(LI_complexo_t));
    inteiro->real = round(complexo->real->num / complexo->real->den);
    inteiro->img = round(complexo->img->num / complexo->img->den);
    return inteiro;
}

R_complexo_t* LIparaR(LI_complexo_t* complexo) {
    R_complexo_t* racional = (R_complexo_t*) malloc(sizeof(R_complexo_t));
    racional->real->num = complexo->real;
    racional->real->den = 1;
    
    racional->img->num = complexo->img;
    racional->img->den = 1;

    return racional;
}