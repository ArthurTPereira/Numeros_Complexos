#include "complexo_racional.h"

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE long int
#define TYPED(COISA) R_ ## COISA
#define TIPO "ld"

#include "Complexo.c"

#undef TYPE
#undef TYPED
#undef TIPO