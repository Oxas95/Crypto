#include "SS_SM.h"
#include <stdio.h>
#include <stdlib.h>

//gmp_printf %Zd -> mpz_t type

//algorithme d'exponentiation rapide (square and multiply)

//ajoute "value" au début du tableau "tab" et ajoute 1 à sa variable taille "size" associé
int* add_value_tab(int* tab, int* size, int value){
	*size += 1;
	int* copie = malloc((*size) * sizeof(int));
	copie[0] = value;
	for (int i = 0; i < *size - 1; i++){
		copie[i + 1] = tab[i];
	}
	if(tab) free(tab);
	return copie;
}


//convertis un mpz_t en binaire dans un tableau d'entiers
int* binary(const mpz_t value, int* sizeofBinary){
	int* tab = NULL; 									//tableau contenant la conversion en binaire
	sizeofBinary = 0;
	mpz_t mpz_reste; 									//reste de type mpz_t
	int reste;       									//reste de type int
	mpz_t quotient;
	mpz_init_set(quotient, value);
	mpz_init(mpz_reste);
	do{
		mpz_mod_ui(mpz_reste, quotient, 2); 			//mpz_reste = quotient % 2
		reste = (int)mpz_get_si(mpz_reste); 			//conversion mpz_t -> int
		add_value_tab(tab, sizeofBinary, reste); 	//ajout du reste dans le tableau
		mpz_div_ui(quotient, quotient, 2);				//on divise le quotient par 2
	}while(mpz_cmp_ui(quotient, 0) != 0); 				//si quotient est different de 0, on continu a diviser par 2 pour recupérer le reste
	return tab;
}

void exponentiation(mpz_t r, mpz_t a, mpz_t n, mpz_t H){
	int t;
	int* h = binary(H, &t);
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
	return true;
}

