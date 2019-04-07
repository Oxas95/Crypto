#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(){
	mpz_t var;
	mpz_init_set_str(var, "1234567890", 0);
	
	mpz_clear(var);
}
