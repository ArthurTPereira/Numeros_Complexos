#ifndef COMPLEXO_LONG_INT_H
#define COMPLEXO_LONG_INT_H

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE long int
#define TYPED(COISA) LI_ ## COISA
#define TIPO "ld"

#include "Complexo.h"

#undef TYPE
#undef TYPED
#undef TIPO


#endif