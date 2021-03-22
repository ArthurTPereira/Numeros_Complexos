#include "complexo_double.h"

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE double
#define TYPED(COISA) COISA ## _D
#define TIPO "lf"

#include "Complexo.c"

#undef TYPE
#undef TYPED
#undef TIPO