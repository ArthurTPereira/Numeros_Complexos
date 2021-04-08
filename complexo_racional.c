#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include"complexo_racional.h"

struct racional {
    long int num;
    long int den;
};

typedef struct R_complexo_st {
    tRacional* real;
    tRacional* img;
} R_complexo_t;

R_complexo_t* R_criaComplexo(tRacional* real, tRacional* img) {
    R_complexo_t* complexo = (R_complexo_t*) malloc(sizeof(R_complexo_t));
    complexo->real = real;
    complexo->img = img;
    return complexo;
}

void R_imprimeComplexo(R_complexo_t* complexo) { //Funcao temporaria

    printf("%ld/%ld + %ld/%ld i ",complexo->real->num,complexo->real->den,complexo->img->num,complexo->img->den);
}

void R_destroiComplexo(R_complexo_t* complexo) {
    free(complexo);
}

void R_atribuiComplexo(R_complexo_t* complexo1, R_complexo_t* complexo2) {
    complexo1->real = complexo2->real;
    complexo1->img = complexo2->img;
}

R_complexo_t* R_copiaComplexo(R_complexo_t* complexo) {
    R_complexo_t* copia = (R_complexo_t*) malloc(sizeof(R_complexo_t));
    copia->real = complexo->real;
    copia->img = complexo->img;
    return copia;
}

tRacional* R_retornaReal(R_complexo_t* complexo) {
    return complexo->real;
}

tRacional* R_retornaImaginaria(R_complexo_t* complexo) {
    return complexo->img;
}

tRacional* R_retornaMagnitude(R_complexo_t* complexo) {
    tRacional* var1 = quadradoRacional(complexo->real);
    tRacional* var2 = quadradoRacional(complexo->img);
    var1 = somaRacional(var1,var2);
    printf("%ld/%ld\n\n",var1->num,var1->den);
    var1 = raizRacional(var1,6); // Precisao
    return var1;
}

double R_retornaFase(R_complexo_t* complexo) {
    tRacional* divisao = divideRacional(complexo->img,complexo->real);
    double value = converteRacional(divisao);
    return atan(value);
}

void R_mudaReal(R_complexo_t* complexo,tRacional* real) {
    complexo->real = real;
}

void R_mudaImaginaria(R_complexo_t* complexo,tRacional* imaginaria) {
    complexo->img = imaginaria;
}

R_complexo_t* R_calculaConjugado(R_complexo_t* complexo) {
    R_complexo_t* conjugado = (R_complexo_t*) malloc(sizeof(R_complexo_t));
    conjugado->real = complexo->real;
    conjugado->img->num = -complexo->img->num;
    conjugado->img->den = complexo->img->den;
    return conjugado;
}

R_complexo_t* R_somaComplexos(R_complexo_t* complexo1, R_complexo_t* complexo2) {
    R_complexo_t* soma = (R_complexo_t*) malloc(sizeof(R_complexo_t));
    tRacional* somareal = somaRacional(complexo1->real, complexo2->real);
    tRacional* somaimg = somaRacional(complexo1->img, complexo2->img);
    
    soma->real = somareal;
    soma->img = somaimg;

    return soma;
}

void R_acumulaSoma(R_complexo_t* complexo1, R_complexo_t* complexo2) {
    R_complexo_t* temp = R_somaComplexos(complexo1,complexo2);
    complexo1 = temp;
    free(temp);
}

R_complexo_t* R_subtraiComplexos(R_complexo_t* complexo1, R_complexo_t* complexo2) {
    R_complexo_t* subtracao = (R_complexo_t*) malloc(sizeof(R_complexo_t));
    tRacional *subreal = subtraiRacional(complexo1->real, complexo2->real);
    tRacional *subimg = subtraiRacional(complexo1->img, complexo2->img);
    
    subtracao->real = subreal;
    subtracao->img = subimg;

    return subtracao;
}

R_complexo_t* R_produtoComplexos(R_complexo_t* complexo1, R_complexo_t* complexo2) {
    R_complexo_t* produto = (R_complexo_t*) malloc(sizeof(R_complexo_t));

    tRacional* produtoreal = subtraiRacional(multiplicaRacional(complexo1->real,complexo2->real),multiplicaRacional(complexo1->img,complexo2->img));
    tRacional* produtoimg = somaRacional(multiplicaRacional(complexo1->real,complexo2->img),multiplicaRacional(complexo1->img,complexo2->real));

    produto->real = produtoreal;
    produto->img = produtoimg;

    return produto;
}

void R_acumulaProduto(R_complexo_t* complexo1, R_complexo_t* complexo2) {
    R_complexo_t *temp = R_produtoComplexos(complexo1,complexo2);
    complexo1 = temp;
    free(temp);
}

R_complexo_t* R_divideComplexos(R_complexo_t* complexo1, R_complexo_t* complexo2) {
    R_complexo_t* divisao = (R_complexo_t*) malloc(sizeof(R_complexo_t));
    tRacional* dividendo = somaRacional(multiplicaRacional(complexo2->real,complexo2->real),multiplicaRacional(complexo2->img,complexo2->img));

    tRacional* divisaoreal1 = somaRacional(multiplicaRacional(complexo1->real,complexo2->real),multiplicaRacional(complexo1->img,complexo2->img));
    tRacional* divisaoreal = divideRacional(divisaoreal1,dividendo);
    
    tRacional* divisaoimg1 = somaRacional(multiplicaRacional(inverteRacional(complexo1->real),complexo2->img),multiplicaRacional(complexo1->img,complexo2->real));
    tRacional* divisaoimg = divideRacional(divisaoimg1,dividendo);

    divisao->real = divisaoreal;
    divisao->img = divisaoimg;

    return divisao;
}

R_complexo_t* R_operacaoComplexo(R_complexo_t* complexo1, R_complexo_t* complexo2, char* operador) {
    R_complexo_t* resultado = (R_complexo_t*) malloc(sizeof(R_complexo_t));

    if (strcmp(operador,"+") == 0) {
        resultado = R_somaComplexos(complexo1,complexo2);
    } else if(strcmp(operador, "-") == 0) {
        resultado = R_subtraiComplexos(complexo1, complexo2);
    } else if(strcmp(operador,"*")== 0) {
        resultado = R_produtoComplexos(complexo1, complexo2);
    } else if (strcmp(operador,"/") == 0) {
        resultado = R_divideComplexos(complexo1,complexo2);
    } else if (strcmp(operador,"+=") == 0) {
        R_acumulaSoma(complexo1,complexo2);
        return complexo1;
    } else if (strcmp(operador,"*=") == 0) {
        R_acumulaProduto(complexo1,complexo2);
        return complexo1;
    }

    return resultado;
}

int R_verificaModulo(R_complexo_t* complexo) {
    tRacional* magnitude = R_retornaMagnitude(complexo);
    double modulo = converteRacional(magnitude);
    if (modulo >= -0.00001 && modulo <= 0.00001) {
        return 1;
    } else {
        return 0;
    }
}
int R_verificaReal(R_complexo_t* complexo) {
    double real = converteRacional(complexo->real);
    if (real >= -0.00001 && real <= 0.00001) {
        return 1;
    } else {
        return 0;
    }
}

int R_verificaImaginario(R_complexo_t* complexo) {
    double imaginario = converteRacional(complexo->real);
    if (imaginario >= -0.00001 && imaginario <= 0.00001) {
        return 1;
    } else {
        return 0;
    }
}

int R_comparaModulos(R_complexo_t* complexo1, R_complexo_t* complexo2) {
    tRacional* mag1 = R_retornaMagnitude(complexo1);
    tRacional* mag2 = R_retornaMagnitude(complexo2);

    double convertido1 = converteRacional(mag1);
    double convertido2 = converteRacional(mag2);

    if (fabs(convertido1 - convertido2) <= 0.0001) {
        return 0;
    } else if (convertido1 > convertido2) {
        return 1;
    } else {
        return -1;
    }
}

int R_comparaFase(R_complexo_t* complexo1, R_complexo_t* complexo2) {
    double fase1 = R_retornaFase(complexo1);
    double fase2 = R_retornaFase(complexo2);

    if(fabs(fase1 - fase2) <= 0.0001) {
        return 0;
    }
    else if(fase1 > fase2) {
        return 1;
    }
    else {
        return -1;
    }
}

R_complexo_t* R_alteraMagnitude(R_complexo_t* complexo, int escalar) {
    R_complexo_t* escalonado = (R_complexo_t*) malloc(sizeof(R_complexo_t));
    escalonado->real = complexo->real;
    escalonado->img = complexo->img;
    
    escalonado->real->num = escalonado->real->num * escalar;
    escalonado->img->num = escalonado->img->num * escalar;

    return escalonado;
}

R_complexo_t* R_alteraFase(R_complexo_t* complexo) {
    R_complexo_t* transformado = (R_complexo_t*) malloc(sizeof(R_complexo_t));
    transformado->real = complexo->real;
    transformado->img = complexo->img;

    transformado->real->num = -transformado->real->num;
    transformado->img->num = -transformado->img->num;

    return transformado;
}
