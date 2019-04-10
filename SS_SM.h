#ifndef SS_SM_h
#define SS_SM_h

#include <stdbool.h>
#include <gmp.h>
#include "jacobi.h"

//algorithme d'exponentiation rapide (square and multiply)

void exponentiation(mpz_t r, mpz_t a, mpz_t n, mpz_t H);

//test de primalité de Solovay-Strassen

bool Solovay_Strassen(mpz_t n, mpz_t k);

#endif //SS_SM_h
