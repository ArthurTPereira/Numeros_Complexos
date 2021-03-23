#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifdef TYPE
#ifdef TYPED

TYPED(complexo_t)* TYPED(criaComplexo)(TYPE a, TYPE b) { // funcionou
    TYPED(complexo_t)* complexo = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    complexo->a = a;
    complexo->b = b;
    return complexo;
}

void TYPED(destroiComplexo)(TYPED(complexo_t)* complexo) { //funcionou
    free(complexo);
}

void TYPED(atribuiComplexo)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) { //antes deu erro mas agora foi
    complexo1->a = complexo2->a;
    complexo1->b = complexo2->b;
}

void TYPED(imprimeComplexo)(TYPED(complexo_t)* complexo) { //funcionou
    char parametros[50];
    strcpy(parametros,"");
    strcat(parametros," %");
    strcat(parametros,TIPO);
    if(complexo->b >=0) {
        strcat(parametros," +");
    }
    strcat(parametros," %");
    strcat(parametros,TIPO);
    strcat(parametros,"i");

    printf(parametros,complexo->a,complexo->b);
    printf("\n");
}

TYPE TYPED(retornaReal)(TYPED(complexo_t)* complexo) { //funcionou
    return complexo->a;
}

TYPE TYPED(retornaImaginaria)(TYPED(complexo_t)* complexo) { //funcionou
    return complexo->b;
}

double TYPED(retornaMagnitude)(TYPED(complexo_t)* complexo) { //funcionou mas nao sei se ta certo o valor
    return (double)sqrt(complexo->a * complexo->a + complexo->b * complexo->b);
}

double TYPED(retornaFase)(TYPED(complexo_t)* complexo) { //funcionou mas nao sei se ta certo o valor tambem
    return atan(complexo->b / complexo->a);
}

void TYPED(mudaReal)(TYPED(complexo_t)* complexo,TYPE real) { //funcionou
    complexo->a = real;
}

void TYPED(mudaImaginaria)(TYPED(complexo_t)* complexo,TYPE imaginaria) { //funcionou
    complexo->b = imaginaria;
}

TYPED(complexo_t)* TYPED(calculaConjugado)(TYPED(complexo_t)* complexo) { //funcionou
    TYPED(complexo_t)* conjugado = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    conjugado->a = complexo->a;
    conjugado->b = -complexo->b;
    return conjugado;
}

TYPED(complexo_t)* TYPED(somaComplexos)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    TYPED(complexo_t)* soma = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    soma->a = complexo1->a + complexo2->a;
    soma->b = complexo1->b + complexo2->b;
    return soma;
}

TYPED(complexo_t)* TYPED(acumulaSoma)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    TYPED(complexo_t)* acumulado = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    acumulado->a = complexo1->a + complexo2->a;
    acumulado->b = complexo1->b + complexo2->b;
    return acumulado;
}

TYPED(complexo_t)* TYPED(subtraiComplexos)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    TYPED(complexo_t)* subtracao = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    subtracao->a = complexo1->a - complexo2->a;
    subtracao->b = complexo1->b - complexo2->b;
    return subtracao;
}

TYPED(complexo_t)* TYPED(produtoComplexos)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    TYPED(complexo_t)* produto = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    produto->a = complexo1->a * complexo2->a - complexo1->b * complexo2->b;
    produto->b = complexo1->a * complexo2->b + complexo1->b * complexo2->a;
    return produto;
}

TYPED(complexo_t)* TYPED(acumulaProduto)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    TYPED(complexo_t)* acumulado = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));;
    acumulado->a = complexo1->a * complexo2->a - complexo1->b * complexo2->b;
    acumulado->b = complexo1->a * complexo2->b + complexo1->b * complexo2->a;
    return acumulado;
}

TYPED(complexo_t)* TYPED(divideComplexos)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    TYPED(complexo_t)* divisao = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    TYPE div1 = ((complexo2->a * complexo2->a) + (complexo2->b * complexo2->b));
    TYPE div2 = ((complexo2->a * complexo2->a) + (complexo2->b * complexo2->b));
    if (div1 == 0 || div2 == 0) {
        printf("Nao e possivel dividir por zero.\n");
        free(divisao);
        return NULL;
    }
    divisao->a = (((complexo1->a * complexo2->a) + (complexo1->b * complexo2->b)) / div1);
    divisao->b = (((-complexo1->a * complexo2->b) + (complexo1->b * complexo2->a)) / div2);
    return divisao;
}

TYPED(complexo_t)* TYPED(operacaoComplexo)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2, char* operador) {
    TYPED(complexo_t)* resultado = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));

    if (strcmp(operador,"+") == 0) {
        resultado = TYPED(somaComplexos)(complexo1,complexo2);
    } else if(strcmp(operador, "-") == 0) {
        resultado = TYPED(subtraiComplexos)(complexo1, complexo2);
    } else if(strcmp(operador,"*")== 0) {
        resultado = TYPED(produtoComplexos)(complexo1, complexo2);
    } else if (strcmp(operador,"/") == 0) {
        resultado = TYPED(divideComplexos)(complexo1,complexo2);
    } else if (strcmp(operador,"+=") == 0) {
        resultado = TYPED(acumulaSoma)(complexo1,complexo2);
    } else if (strcmp(operador,"*=") == 0) {
        resultado = TYPED(acumulaProduto)(complexo1,complexo2);
    }

    return resultado;
}

int TYPED(verificaModulo)(TYPED(complexo_t)* complexo) {
    double modulo = (double)TYPED(retornaMagnitude)(complexo);
    if (modulo >= -0.00001 && modulo <= 0.00001) {
        return 1;
    } else {
        return 0;
    }
}

int TYPED(verificaReal)(TYPED(complexo_t)* complexo) {
    if (complexo->b >= -0.00001 && complexo->b <= 0.00001) {
        return 1;
    } else {
        return 0;
    }
}

int TYPED(verificaImaginario)(TYPED(complexo_t)* complexo) {
    if (complexo->a >= -0.00001 && complexo->a <= 0.00001) {
        return 1;
    } else {
        return 0;
    }
}

int TYPED(comparaModulos)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    double modulo1 = TYPED(retornaMagnitude)(complexo1);
    double modulo2 = TYPED(retornaMagnitude)(complexo2);

    if (fabs(modulo1 - modulo2) <= 0.0001) {
        return 0;
    } else if (modulo1 > modulo2) {
        return 1;
    } else {
        return -1;
    }
}

int TYPED(comparaFase)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    double fase1 = TYPED(retornaFase)(complexo1);
    double fase2 = TYPED(retornaFase)(complexo2);

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

#endif
#endif