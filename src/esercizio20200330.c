#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



unsigned long fibonacci (unsigned int n){
	if (n == 0) {return 0;}
	if (n == 1) {return 1;}

	int res = fibonacci(n-1) + fibonacci(n-2);
	return res;
}


unsigned long * fibonacci_array(unsigned int n){
	unsigned long * res;
	res = calloc(n, sizeof(unsigned long));

	if (res == NULL) {
			perror("calloc error");
			exit(EXIT_FAILURE);
		}

	for (unsigned int i = 0; i < n; i++){
		res[i] = fibonacci(i);
	}
	return res;

}

void swap(unsigned long *x, unsigned long *y) {
	unsigned long t = *x;
	*x = *y;
	*y = t;
}


int main(int argc, char *argv[]){

	//calcolo fibonacci_result
	unsigned long * fibonacci_result = fibonacci_array(39);

	//faccio una copia dell'array
	unsigned long * fibonacci_result_copy;

		fibonacci_result_copy = malloc(39 * sizeof(unsigned long));

		if (fibonacci_result_copy == NULL) {
					perror("malloc error");
					exit(EXIT_FAILURE);
				}

		memcpy(fibonacci_result_copy, fibonacci_result, 39* sizeof(unsigned long));

	//inverto l'array fibonacci_result_copy
	unsigned int i = 0;
	unsigned int j = 39;
		while (i < j) {
				j--;
				swap(&fibonacci_result_copy[i], &fibonacci_result_copy[j]);
				i++;
			}

	//calcolo bubble sort
	unsigned int newn;
	unsigned int n = 39;

		while (n > 1) {

			newn = 0;

			for (int i = 1; i < n; i++) {
				if (fibonacci_result_copy[i-1] > fibonacci_result_copy[i]) {
					swap(&fibonacci_result_copy[i-1], &fibonacci_result_copy[i]);
					newn = i;
				}
			}

				n = newn;
		}

	// verifico che i due array siano identici

	for(unsigned int i = 0; i < 39; i++){
		if (fibonacci_result_copy[i] != fibonacci_result[i]){
			printf("I due array sono diversi alla cella numero %u \n", i);
			return 1;
		}
	}

	printf("I due array sono uguali. \n");

	return 0;

}


