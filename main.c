#include <stdio.h>
#include <stdlib.h>
#include "converte_complexos.h"

int main() {

    #include "complexo_racional.h"
    #include "complexo_double.h"
    #include "complexo_long_int.h"

    tRacional* rac1 = criaRacional(8,2);
    tRacional* rac2 = criaRacional(15,4);
    R_complexo_t* var = R_criaComplexo(rac1,rac2);
    LI_complexo_t* inteiro = RparaLI(var);
    LI_imprimeComplexo(inteiro);
    
    destroiRacional(rac1);
    destroiRacional(rac2);
    R_destroiComplexo(var);
    LI_destroiComplexo(inteiro);

    return 0;
}
