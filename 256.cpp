//////////////////////////////////
// Algoritimo Avancado
// Lista 3 basico
// P3 - 256 - Quirksome Squares
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>

int main() {
    char *possibilidades[] =
	{
	"0",
	"1",
	"00\n01\n81\n",
	"3",
	"0000\n0001\n2025\n3025\n9801\n",
	"5",
	"000000\n000001\n088209\n494209\n998001\n",
	"7",
	"00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n",
	};
	int d;
    
	while(scanf("%d", &d) != EOF) {
		printf("%s", possibilidades[d]);
	}
	
	return 0;
}

/* SOLUÇÃO GERADA APARITR DE

#include <stdio.h>

long int pow(long int base, long int expo) {
    long int retorno = base;
    while (--expo) {
        retorno *= base;
    }
	
    return retorno;
}

int main() {
    long int i, j, k, P, P2, igual;
    int d2, d;
    char format[50];
    char num[50];
    char num2[50];
    
    while (scanf("%d", &d) != EOF) {
	    P = pow(10,d/2);
	    d2 = d/2;
	    for (i = 0; i < P; i++) {
	    	P2 = P - i;
	    	for (j = 0; j <= P2; j++) {
	    		sprintf(format, "%%0%dd%%0%dd", d2,d2);
	    		sprintf(num, format, i,j);
	    		sprintf(format, "%%0%dd", d);
	    		sprintf(num2, format, (i+j)*(i+j));
	    		
	    		igual = 1;
	    		for (k = 0; k < d; k++) {
	    			if (num[k] != num2[k]) {
	    				igual = 0;
	    				break;
	    			}
	    		}
	    		
	    		if(igual) {
	    			printf("%s\\n", num);
	    		}
	    	}
	    }
        printf("\n");
    }
	return 0;
}
*/
