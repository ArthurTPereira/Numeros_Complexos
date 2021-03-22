#ifndef COMPLEXO_DOUBLE_H
#define COMPLEXO_DOUBLE_H

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE double
#define TYPED(COISA) D_ ## COISA
#define TIPO "lf"

#include "Complexo.h"

#undef TYPE
#undef TYPED
#undef TIPO

#endif