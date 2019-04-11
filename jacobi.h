#ifndef jacobi_h
#define jacobi_h

#include <gmp.h>

typedef struct {
	mpz_t a;
	mpz_t n;
} symbole;

int jacobi(symbole j);

#endif //jacobi_h
