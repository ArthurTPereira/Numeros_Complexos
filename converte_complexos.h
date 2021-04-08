#ifndef CONVERTE_COMPLEXOS_H_
#define CONVERTE_COMPLEXOS_H_

#include "complexo_double.h"
#include "complexo_long_int.h"
#include "complexo_racional.h"
#include "racional.h"

LI_complexo_t* DoubleParaLI(D_complexo_t* complexo);

D_complexo_t* LIparaDouble(LI_complexo_t* complexo);

R_complexo_t* DoubleParaR(D_complexo_t* complexo);

D_complexo_t* RparaDouble(R_complexo_t* complexo);

LI_complexo_t* RparaLI(R_complexo_t* complexo);

R_complexo_t* LIparaR(LI_complexo_t* complexo);

#endif