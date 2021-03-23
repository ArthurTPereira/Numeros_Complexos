#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

int main() {

    #include "complexo_double.h"
    #include "complexo_long_int.h"
    #include "complexo_racional.h"

    R_complexo_t* variavel = R_criaComplexo(1,2);
    R_imprimeComplexo(variavel);
    R_destroiComplexo(variavel);


    return 0;
}
