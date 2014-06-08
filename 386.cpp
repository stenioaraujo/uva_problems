//////////////////////////////////
// Algoritimo Avancado
// Lista 3 basico
// P4 - 386 - Perfect Cubes
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////

#include <stdio.h>

int main(void) {	
	for (int a = 2; a <= 200; a++)
		for (int b = 2; b <= a; b++)
			for (int c = 2; c <= a; c++)
				for (int d = 2; d <= a; d++)
					if (a*a*a == b*b*b + c*c*c + d*d*d)
						if ( b <= c && c <= d)
							printf("Cube = %d, Triple = (%d,%d,%d)\n", a,b,c,d);
	
	return 0;
}