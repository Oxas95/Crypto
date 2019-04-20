#include "jacobi.h"
#include "SS_SM.h"
#include <stdio.h>
#include <stdlib.h>

int propriete5(symbole j, int pow);

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
	//mpz_t perfect;
	//mpz_init(perfect);
	int cmp = (int)mpz_cmp_si(res, 1);
	/*int ret;
	mpz_mod(res,j.a,j.n);
	if(cmp != 1) ret = 0;
	else {
		mpz_sqrtrem(res, perfect, res);
		if(mpz_cmp_si(perfect, 0) == 0)
			ret = 1;
		else ret = -1;
	}
	mpz_clear(perfect);*/
	mpz_clear(res);
	//return ret;
	return cmp == 0;
}

void propriete3(symbole j){
	int pow = 0;
	mpz_t mod;
	mpz_init(mod);
	
	mpz_mod_ui(mod, j.a, 2);
	while(mod == 0){
		mpz_div_ui(j.a, j.a, 2);
		pow++;
		mpz_mod_ui(mod, j.a, 2);
	}
	
	if(pow > 0) j.signe *= propriete5(j,pow);
	
	mpz_clear(mod);
}

int propriete4(symbole j){
	return mpz_cmp_ui(j.a, 1) == 0;
}

int propriete5(symbole j, int pow){
	mpz_t mod;
	mpz_init(mod);
	
	int ret;
	mpz_mod_ui(mod,j.n,8);
	
	if(mpz_cmp_ui(mod,1) == 0) ret = 1;
	if(mpz_cmp_ui(mod,7) == 0) ret = 1;
	if(mpz_cmp_ui(mod,3) == 0) ret = -1;
	if(mpz_cmp_ui(mod,5) == 0) ret = -1;
	
	for (int i = 0; i < pow; i++) ret *= ret;
	
	mpz_clear(mod);
	
	return ret;
}

void inverse(symbole j){
	mpz_t inverser;
	mpz_init_set(inverser, j.a);
	
	mpz_set(j.a, j.n);
	mpz_set(j.n, inverser);
	
	mpz_clear(inverser);
}

void propriete6(symbole j){
	mpz_t m;
	mpz_t m2;
	mpz_init(m);
	mpz_init(m2);
	
	inverse(j);
	
	mpz_mod_ui(m,j.n,4);
	mpz_mod_ui(m2,j.a,4);
	
	if(mpz_cmp_ui(m,1) == 0 || mpz_cmp_ui(m2,1)) j.signe *= 1;
	
	else if(mpz_cmp_ui(m,3) == 0 && mpz_cmp_ui(m2,3)) j.signe *= -1;
	
	else printf("erreur propriete 6\n");
	
	mpz_clear(m);
	mpz_clear(m2);
	
}

int jacobi(symbole j){
	int ret;
	while(1){
		if(mpz_cmp(j.a,j.n) == 1) propriete6(j);
		propriete1(j);
		propriete3(j);
		if(propriete4(j)) return j.signe;
		else if (propriete2(j) == 0) return 0;
	}
}
