#include <stdio.h>
#include <math.h>

int is_prime(int n) {
	int a, i, flag;
 	
	a	= floor(sqrt(n)) + 1;

	for (i = 2; i < a; i++){
		if (n % i == 0){
            return 0;

		}
	}
    return 1;

}

int main(){
	int j, k, x, c, mod;

	k = 1000;
	mod = 12;

	for (j = 1; j < k; j++) {
		x = mod * j;
		c = x;
		while (is_prime(c) == 0) {
			c++;
		}
		printf("%d\n", (c-x));
	}
	return 0;
}
