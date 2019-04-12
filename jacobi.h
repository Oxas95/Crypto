#ifndef jacobi_h
#define jacobi_h

#include <gmp.h>
#include <stdbool.h>

typedef struct {
	mpz_t a;
	mpz_t n;
} symbole;

bool carreParfait(const mpz_t valeur);

int jacobi(symbole j);

#endif //jacobi_h
