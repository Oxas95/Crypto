#include "SS_SM.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//gmp_printf %Zd -> mpz_t type

//algorithme d'exponentiation rapide (square and multiply)

//ajoute "value" au début du tableau "tab" et ajoute 1 à sa variable taille "size" associé
int* add_value_tab(int* tab, int* size, int value){
	*size += 1;
	int* copie = malloc((*size) * sizeof(int)), i;
	for (i = 0; i < *size - 1; i++){
		copie[i] = tab[i];
	}
	copie[i] = value;
	if(tab) free(tab);
	return copie;
}


//convertis un mpz_t en binaire dans un tableau d'entiers
int* binary(const mpz_t value, int* sizeofBinary){
	int* tab = NULL; 									//tableau contenant la conversion en binaire
	*sizeofBinary = 0;
	mpz_t mpz_reste; 									//reste de type mpz_t
	int reste;       									//reste de type int
	mpz_t quotient;
	mpz_init_set(quotient, value);
	mpz_init(mpz_reste);
	do{
		mpz_mod_ui(mpz_reste, quotient, 2); 			//mpz_reste = quotient % 2
		reste = (int)mpz_get_si(mpz_reste); 			//conversion mpz_t -> int
		tab = add_value_tab(tab, sizeofBinary, reste); 		//ajout du reste dans le tableau
		mpz_sub(quotient, quotient, mpz_reste);
		mpz_div_ui(quotient, quotient, 2);				
	}while(mpz_cmp_ui(quotient, 0) != 0); 				//si quotient est different de 0, on continu a diviser par 2 pour recupérer le reste
	
	mpz_clear(mpz_reste);
	mpz_clear(quotient);
	return tab;
}

void exponentiation(mpz_t r, const mpz_t a, const mpz_t n, const mpz_t H){
	int t;
	int* h = binary(H, &t);
	for (int i = 0; i < t; i++)
		printf("%d",h[i]);
	printf("\n");
	
	mpz_set(r, a);
	for (int i = t - 1; i >= 0 ; i--){
		mpz_mul(r, r, r);
		mpz_mod(r, r, n);
		if(h[i]){
			mpz_mul(r, r, a);
			mpz_mod(r, r, n);
		}
	}
	
	free(h); //mémoire du tableau pour le nombre binaire vidé
}


//test de primalité de Solovay-Strassen

bool Solovay_Strassen(mpz_t n, mpz_t k){
	mpz_t a;
	mpz_init(a);
	mpz_t n1;
	mpz_init_set(n1,n);
	mpz_sub_ui(n1,n1,3);
	mpz_t expo;
	mpz_init_set(expo,n);
	mpz_sub_ui(expo,expo,1);
	mpz_div_ui(expo,expo,2);
	mpz_t res;
	mpz_init(res);
	mpz_t i;
	mpz_init_set_ui(i,0);
	int r;
	symbole j;
	mpz_init(j.a);
	mpz_init_set(j.n, n);
	
	gmp_randstate_t alea;
	gmp_randinit_mt(alea);
	gmp_randseed_ui(alea, time(NULL));
	
	
	for (; mpz_cmp(i,k) < 0; mpz_add_ui(i,i,1)){
		mpz_urandomm(a,alea,n1);
		
		mpz_add_ui(a,a,2);
		mpz_set(j.a, a);
		
		r = jacobi(j);
		
		exponentiation(res,a,n,expo);
		if(r == 0 || mpz_cmp_ui(res,r) != 0) return false;
		gmp_printf("%Zd\r",i);
	}
	
	mpz_clear(a);
	mpz_clear(n1);
	mpz_clear(expo);
	mpz_clear(j.a);
	mpz_clear(j.n);
	mpz_clear(res);
	mpz_clear(i);
	
	return true;
}

