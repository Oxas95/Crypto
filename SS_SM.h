#ifndef SS_SM_h
#define SS_SM_h

#include <stdbool.h>
#include <gmp.h>
#include "jacobi.h"

//conversion mpz_t dans un tableau de booleen, bit de poids faible en 0
bool* binary(const mpz_t value, int* sizeofBinary);

//algorithme square and multiply

void exponentiation(mpz_t r, const mpz_t a, const mpz_t n, const mpz_t H);

//test de primalité de Solovay-Strassen

bool Solovay_Strassen(const mpz_t n, const mpz_t k);

#endif //SS_SM_h
