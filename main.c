#include <stdio.h>
#include <stdlib.h>

int main() {

    #include "Complexo.h"
    //#include "complexo_double.h"
    #include "complexo_long_int.h"

    complexo_t_LI* var = criaComplexo_LI();
    destroiComplexo_LI(var);

    return 0;
}
