#include "jacobi.h"
#include "SS_SM.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int propriete5(mpz_t n, int pow);

void mpz_pgcd(mpz_t res, const mpz_t a, const mpz_t b){
	mpz_t reste;
	mpz_init(reste);
	mpz_t tmp_a;
	mpz_t tmp_b;
	if(mpz_cmp(a,b) > 0){
		mpz_init_set(tmp_a, a);
		mpz_init_set(tmp_b, b);
	}
	else {
		mpz_init_set(tmp_a, b);
		mpz_init_set(tmp_b, a);
	}
	do{
		
		mpz_mod(reste, tmp_a, tmp_b);
		mpz_set(tmp_a,tmp_b);
		mpz_set(tmp_b,reste);
		
	}while(mpz_cmp_ui(tmp_b,0) != 0);
	mpz_set(res,tmp_a);
	mpz_clear(reste);
	mpz_clear(tmp_a);
	mpz_clear(tmp_b);
}

void propriete1(mpz_t a, mpz_t n){
	mpz_mod(a,a,n);
}

int propriete2(mpz_t a, mpz_t n){
	mpz_t res;
	mpz_init(res);
	mpz_pgcd(res,a,n);
	int cmp = (int)mpz_cmp_si(res, 1);
	mpz_clear(res);
	return cmp == 0;
}

void propriete3(mpz_t a, mpz_t n, int *signe){
	int pow = 0;
	mpz_t mod;
	mpz_init(mod);
	
	mpz_mod_ui(mod, a, 2);
	while(mpz_cmp_ui(mod,0) == 0){
		mpz_div_ui(a, a, 2);
		pow++;
		mpz_mod_ui(mod, a, 2);
	}
	
	if(pow > 0) *signe *= propriete5(n,pow);
	
	mpz_clear(mod);
}

int propriete4(mpz_t a){
	return mpz_cmp_ui(a, 1) == 0;
}

int propriete5(mpz_t n, int pow){
	mpz_t mod;
	mpz_init(mod);
	
	int ret;
	mpz_mod_ui(mod,n,8);
	
	if(mpz_cmp_ui(mod,1) == 0) ret = 1;
	if(mpz_cmp_ui(mod,7) == 0) ret = 1;
	if(mpz_cmp_ui(mod,3) == 0) ret = -1;
	if(mpz_cmp_ui(mod,5) == 0) ret = -1;
	if(ret == -1) for (int i = 0; i < pow - 1; i++) ret *= -1;
	mpz_clear(mod);
	
	return ret;
}

void inverse(mpz_t a, mpz_t n){
	mpz_t inverser;
	mpz_init_set(inverser, a);
	
	mpz_set(a, n);
	mpz_set(n, inverser);
	
	mpz_clear(inverser);
}

void propriete6(mpz_t a, mpz_t n, int *signe){
	mpz_t m;
	mpz_t m2;
	mpz_init(m);
	mpz_init(m2);
	
	inverse(a,n);
	
	mpz_mod_ui(m,n,4);
	mpz_mod_ui(m2,a,4);
	
	if(mpz_cmp_ui(m,1) == 0 || mpz_cmp_ui(m2,1) == 0) *signe *= 1;
	
	else if(mpz_cmp_ui(m,3) == 0 && mpz_cmp_ui(m2,3) == 0) *signe *= -1;
	
	else printf("erreur propriete 6\n");
	
	mpz_clear(m);
	mpz_clear(m2);
	
}

int jacobi(mpz_t a, const mpz_t n){
	mpz_t tmp_n;
	mpz_init_set(tmp_n,n);
	printf("algo jacobi :\n");
	int signe = 1;
	while(1){
		//printf(".");
		gmp_printf("%Zd/%Zd, signe : %d\n",a,tmp_n,signe);
		if(mpz_cmp(a,tmp_n) < 0) propriete6(a,tmp_n,&signe);
		propriete1(a,tmp_n);
		propriete3(a,tmp_n,&signe);
		if(propriete4(a)) 				{mpz_clear(tmp_n); return signe;}
		if (propriete2(a,tmp_n) == 0) 	{mpz_clear(tmp_n); return 0;}
	}
}
