#ifndef RACIONAL_H
#define RACIONAL_H

typedef struct racional tRacional;
long int algoritmoEuclideano(long int x, long int y);
tRacional* alocaRacional();
tRacional* criaRacional(long int num, long int den);
void destroiRacional(tRacional* racional);
tRacional* copiaRacional(tRacional* racional);
int comparaRacional(tRacional* racional1, tRacional* racional2);
int verificaEquivalencia(tRacional* racional1, tRacional* racional2);
int verificaNumerador(tRacional* racional);
int verificaDenominador(tRacional* racional);
int verificaAmbos(tRacional* racional);
tRacional* somaRacional(tRacional* racional1, tRacional* racional2);
tRacional* acumulaSoma(tRacional* racional1, tRacional* racional2);
tRacional* subtraiRacional(tRacional* racional1, tRacional* racional2);
tRacional* multiplicaRacional(tRacional* racional1, tRacional* racional2);
tRacional* acumulaProduto(tRacional* racional1, tRacional* racional2);
tRacional* divideRacional(tRacional* racional1, tRacional* racional2);
tRacional* quadradoRacional(tRacional* racional1);
tRacional* raizRacional(tRacional* racional, int precisao);
tRacional* reduzRacional(tRacional* racional);
void imprimeRacional(tRacional* racional);
double converteRacional(tRacional* racional);
void imprimeCSV(tRacional* racional);

#endif