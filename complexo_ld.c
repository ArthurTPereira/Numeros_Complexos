#include "complexo_long_int.h"

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE long int
#define TYPED(COISA) COISA ## _LI
#define TIPO "ld"

#include "Complexo.c"

#undef TYPE
#undef TYPED
#undef TIPO