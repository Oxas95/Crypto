#ifndef SS_SM_h
#define SS_SM_h

#include <stdbool.h>
#include <gmp.h>
#include "jacobi.h"

int* binary(const mpz_t value, int* sizeofBinary);

//test de primalité de Solovay-Strassen

void exponentiation(mpz_t r, const mpz_t a, const mpz_t n, const mpz_t H);

bool Solovay_Strassen(const mpz_t n, const mpz_t k);

#endif //SS_SM_h
