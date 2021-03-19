#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef TYPE
#ifdef TYPED


TYPED(complexo_t)* TYPED(criaComplexo)() {
    TYPED(complexo_t)* complexo = (TYPED(complexo_t)*) malloc(sizeof(TYPED(complexo_t)));
    return complexo;
}

void TYPED(destroiComplexo)(TYPED(complexo_t)* complexo) {
    free(complexo);
}

TYPED(complexo_t)* TYPED(atribuiComplexo)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2) {
    complexo1->a = complexo2->a;
    complexo1->b = complexo2->b;
    return complexo1;
}




#endif
#endif