#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gmp.h>
#include "jacobi.h"

//gmp_printf %Zd -> mpz_t type

bool is_number(char* str){
	int i = 0;
	while (str[i] != '\0'){
		if(str[i] < '0' || str[i] > '9') return false;
		i++;
	}
	return true;
}

int main(int argc, char** argv){
	if(argc != 3){ 
		printf("./%s <n> <k>\n",argv[0]);
		printf("n : valeur pour faire le test primitif\n");
		printf("k : nombre d'itérations\n");
		exit(1);
	}
	if((is_number(argv[1]) && is_number(argv[2])) == false){
		printf("arguments incorrects\n");
	}
	
	mpz_t n, k;
	mpz_init_set_str(n, argv[1], 0);
	mpz_init_set_str(k, argv[2], 0);
	
	gmp_printf("%Zd, %Zd\n",n,k);
	
	if(carreParfait(n) == true) printf("vrai\n");
	else printf("faux\n");
	
	if(carreParfait(k) == true) printf("vrai\n");
	else printf("faux\n");
	
	mpz_clear(n);
	mpz_clear(k);
}
