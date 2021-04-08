#ifndef COMPLEXO_RACIONAL_H_
#define COMPLEXO_RACIONAL_H_

#include "racional.h"

typedef struct R_complexo_st R_complexo_t;

R_complexo_t* R_criaComplexo(tRacional* real, tRacional* img);

void R_imprimeComplexo(R_complexo_t* complexo);

void R_destroiComplexo(R_complexo_t* complexo);

void R_atribuiComplexo(R_complexo_t* complexo1, R_complexo_t* complexo2);

R_complexo_t* R_copiaComplexo(R_complexo_t* complexo);

tRacional* R_retornaReal(R_complexo_t* complexo);

tRacional* R_retornaImaginaria(R_complexo_t* complexo);

tRacional* R_retornaMagnitude(R_complexo_t* complexo);

double R_retornaFase(R_complexo_t* complexo);

void R_mudaReal(R_complexo_t* complexo,tRacional* real);

void R_mudaImaginaria(R_complexo_t* complexo,tRacional* imaginaria);

R_complexo_t* R_calculaConjugado(R_complexo_t* complexo);

R_complexo_t* R_somaComplexos(R_complexo_t* complexo1, R_complexo_t* complexo2);

void R_acumulaSoma(R_complexo_t* complexo1, R_complexo_t* complexo2);

R_complexo_t* R_subtraiComplexos(R_complexo_t* complexo1, R_complexo_t* complexo2);

R_complexo_t* R_produtoComplexos(R_complexo_t* complexo1, R_complexo_t* complexo2);

void R_acumulaProduto(R_complexo_t* complexo1, R_complexo_t* complexo2);

R_complexo_t* R_divideComplexos(R_complexo_t* complexo1, R_complexo_t* complexo2);

R_complexo_t* R_operacaoComplexo(R_complexo_t* complexo1, R_complexo_t* complexo2, char* operador);

int R_verificaModulo(R_complexo_t* complexo);

int R_verificaReal(R_complexo_t* complexo);

int R_verificaImaginario(R_complexo_t* complexo);

int R_comparaModulos(R_complexo_t* complexo1, R_complexo_t* complexo2);

int R_comparaFase(R_complexo_t* complexo1, R_complexo_t* complexo2);

R_complexo_t* R_alteraMagnitude(R_complexo_t* complexo, int escalar);

R_complexo_t* R_alteraFase(R_complexo_t* complexo);

#endif