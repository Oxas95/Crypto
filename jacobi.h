#ifndef jacobi_h
#define jacobi_h

#include <gmp.h>
#include <stdbool.h>

typedef struct {
	int signe;
	mpz_t a;
	mpz_t n;
} symbole;

void inverse(symbole j);

int jacobi(symbole j);

#endif //jacobi_h
