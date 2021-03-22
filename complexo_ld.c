#include "complexo_long_int.h"

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE long int
#define TYPED(COISA) LI_ ## COISA
#define TIPO "ld"

#include "Complexo.c"

#undef TYPE
#undef TYPED
#undef TIPO