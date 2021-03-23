#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "racional.h"

struct racional {
    long int num;
    long int den;
};

long int algoritmoEuclideano(long int x, long int y) {
    if (x == 0) return y;
    if (y == 0) return x;

    if (x > y) {
        return algoritmoEuclideano((x % y), y);
    } else {
        return algoritmoEuclideano(x, (y % x));
    }
}

tRacional* alocaRacional() {
    tRacional* racional = (tRacional*) malloc(sizeof(tRacional));
    if (racional == NULL) {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    return racional;
}

tRacional* criaRacional(long int num, long int den) {
    tRacional* racional = alocaRacional();
    racional->num = num;
    racional->den = den;
    return racional;
}

void destroiRacional(tRacional* racional) {
    free(racional);
}

tRacional* copiaRacional(tRacional* racional) {
    tRacional* novoRacional = criaRacional(racional->num, racional->den);
    return novoRacional;
}

int comparaRacional(tRacional* racional1, tRacional* racional2) {

    long double value1 = racional1->num * racional2->den;
    long double value2 = racional2->num * racional1->den;

    if (value1 < value2) return -1;
    if (value1 == value2) return 0;
    else return 1;
}

int verificaEquivalencia(tRacional* racional1, tRacional* racional2) {
    tRacional *temp1;
    tRacional *temp2;

    temp1 = reduzRacional(racional1);
    temp2 = reduzRacional(racional2);

    if (temp1->num == temp2->num && temp1->den == temp2->den) {
        return 1;
    } else return 0;
}

int verificaDenominador(tRacional* racional) {
    if (racional->den == 0) {
        return 1;
    } else return 0;
}

int verificaNumerador(tRacional* racional) {
    if (racional->num == 0) {
        return 1;
    } else return 0;
}

int verificaAmbos(tRacional* racional) {
    if (verificaDenominador(racional) == 1 && verificaNumerador(racional) == 1) {
        return 1;
    } else return 0;
}


tRacional* somaRacional(tRacional* racional1, tRacional* racional2) {
    tRacional* soma = alocaRacional();
    soma->den = racional1->den * racional2->den;
    soma->num = (racional2->den * racional1->num) + (racional1->den * racional2->num);
    return soma;
}

tRacional* acumulaSoma(tRacional* racional1, tRacional* racional2) {
    racional1 = somaRacional(racional1,racional2);
    return racional1;
}

tRacional* subtraiRacional(tRacional* racional1, tRacional* racional2) {
    tRacional* diferenca = alocaRacional();
    diferenca->den = racional1->den * racional2->den;
    diferenca->num = (racional2->den * racional1->num) - (racional1->den * racional2->num);
    return diferenca;
}

tRacional* multiplicaRacional(tRacional* racional1, tRacional* racional2) {
    tRacional* produto = alocaRacional();
    produto->num = racional1->num * racional2->num;
    produto->den = racional1->den * racional2->den;
    return produto;
}

tRacional* acumulaProduto(tRacional* racional1, tRacional* racional2) {
    racional1->num = racional1->num * racional2->num;
    racional1->den = racional1->den * racional2->den;
    return racional1;
}

tRacional* divideRacional(tRacional* racional1, tRacional* racional2) {
    tRacional* divisao = alocaRacional();
    divisao->num = racional1->num * racional2->den;
    divisao->den = racional1->den * racional2->num;
    return divisao;
}

tRacional* quadradoRacional(tRacional* racional1) {
    tRacional* quadrado = alocaRacional();
    quadrado->num = racional1->num * racional1->num;
    quadrado->den = racional1->den * racional1->den;
    return quadrado;
}

tRacional* raizRacional(tRacional* racional, int precisao) {
    double decimal = sqrt((double)racional->num / (double)racional->den);

    long int den = 1;
    int i=0;
    for (i = 0; i < precisao; i++) {
        den *= 10;
    }

    long int num = decimal * den + 0.5;
    long int mdc = algoritmoEuclideano(num, den);

    tRacional* raiz = alocaRacional();
    raiz->num = num / mdc;
    raiz->den = den / mdc;

    return raiz;
}

tRacional* reduzRacional(tRacional* racional) {
    long int mdc = algoritmoEuclideano(racional->num,racional->den);
    racional->num = racional->num / mdc;
    racional->den = racional->den / mdc;
    return racional;
}

void imprimeRacional(tRacional* racional) {
    printf("%ld/%ld\n",racional->num, racional->den);
}

double converteRacional(tRacional* racional) {
    double value = (double)racional->num / (double)racional->den;
    return value;
}

void imprimeCSV(tRacional* racional) {
    char arquivo[] = "racional.csv";
    FILE* r = fopen(arquivo,"a+");

    fprintf(r,"%ld,%ld\n",racional->num,racional->den);
    fclose(r);
}
