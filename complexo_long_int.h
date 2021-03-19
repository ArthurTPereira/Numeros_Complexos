#ifndef COMPLEXO_LONG_INT_H
#define COMPLEXO_LONG_INT_H

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE long int
#define TYPED(COISA) COISA ## _LI
#define TIPO "ld"

#include "Complexo.h"

#undef TYPE
#undef TYPED
#undef TIPO


#endif