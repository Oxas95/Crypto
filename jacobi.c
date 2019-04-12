#include "jacobi.h"
#include <stdio.h>
#include <stdlib.h>

void mpz_pgcd(mpz_t res, const mpz_t a, const mpz_t b){
	mpz_t reste;
	mpz_init(reste);
	mpz_t tmp_a;
	mpz_t tmp_b;
	mpz_init_set(tmp_a, a);
	mpz_init_set(tmp_b, b);
	do{
		mpz_mod(reste, tmp_a, tmp_b);
		mpz_set(tmp_a,tmp_b);
		mpz_set(tmp_b,reste);
	}while(tmp_b);
	mpz_set(res,tmp_a);
	mpz_clear(reste);
	mpz_clear(tmp_a);
	mpz_clear(tmp_b);
}

void propriete1(symbole j){
	mpz_mod(j.a,j.a,j.n);
}

int propriete2(symbole j){
	mpz_t res;
	mpz_init(res);
	mpz_pgcd(res,j.a,j.n);
	mpz_t perfect;
	mpz_init(perfect);
	int cmp = (int)mpz_cmp_si(res, 0);
	int ret;
	mpz_mod(res,j.a,j.n);
	if(cmp != 1) ret = 0;
	else {
		mpz_sqrtrem(res, perfect, res);
		if(mpz_cmp_si(perfect, 0) == 0)
			ret = 1;
		else ret = -1;
	}
	mpz_clear(res);
	mpz_clear(perfect);
	return ret;
}

void propriete3(symbole j){
	
}

void propriete4(symbole j){
	
}

void propriete5(symbole j){
	
}

void propriete6(symbole j){
	
}

int jacobi(symbole j){
	
}
