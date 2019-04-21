#ifndef jacobi_h
#define jacobi_h

#include <gmp.h>
#include <stdbool.h>

void mpz_pgcd(mpz_t res, const mpz_t a, const mpz_t b);

int jacobi(mpz_t a, const mpz_t n);

#endif //jacobi_h
