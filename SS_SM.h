#ifndef SS_SM_h
#define SS_SM_h

#include <stdbool.h>
#include <gmp.h>
#include "jacobi.h"

//test de primalité de Solovay-Strassen

bool Solovay_Strassen(mpz_t n, mpz_t k);

#endif //SS_SM_h
