#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

int main() {

    #include "complexo_double.h"
    #include "complexo_long_int.h"
    #include "complexo_racional.h"

    LI_complexo_t* inteiro = LI_criaComplexo(1,2);
    printf("Exemplo de número complexo long int:");
    LI_imprimeComplexo(inteiro);
    
    LI_destroiComplexo(inteiro);

    return 0;
}
