//////////////////////////////////
// Algoritimo Avancado
// Lista 3 basico
// P6 - 725 - Division
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>

int dif(char *conc) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (conc[i] == conc[j] && i != j) {
               return 0;
            }
		}
	}
	return 1;
}

int main() {
	long int a, b, N, nSol, i = 0;
	char buffer[15];
	
	while (1) {
		scanf("%ld", &N);
		if (N==0) break;
		
		if (i++ > 0) printf("\n");
		
		nSol = 1;
		for (b = 1; b <= 99999; b++) {
			a = N*b;
			if (a > 99999) break;
			
			sprintf(buffer, "%05ld", a);
			sprintf(buffer+5, "%05ld", b);
			
			if (dif(buffer)) {
				printf("%05ld / %05ld = %ld\n", a, b, N);
				nSol = 0;
			}
		}
		
		if (nSol) printf("There are no solutions for %ld.\n", N);
	}
		
	return 0;
}
