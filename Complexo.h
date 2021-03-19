#ifdef TYPE
#ifdef TYPED

typedef struct TYPED(complexo) {
    TYPE a;
    TYPE b;
} TYPED(complexo_t);

TYPED(complexo_t)* TYPED(criaComplexo)();

void TYPED(destroiComplexo)(TYPED(complexo_t)* complexo);

TYPED(complexo_t)* TYPED(atribuiComplexo)(TYPED(complexo_t)* complexo1, TYPED(complexo_t)* complexo2);

#endif
#endif