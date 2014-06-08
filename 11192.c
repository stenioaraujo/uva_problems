//////////////////////////////////
// Algoritimo Avancado
// Lista 2 basico
// P1 - 11192 - Group Reverse
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>

int main(void) {
    char c[105];
    short g, i, j, k, p, m; // g grupo i intervalo
    
    do {
        scanf("%hd", &g);
        if (g == 0) break;
        
        scanf(" %s", c);
        i = 0;
        for (j = 0; j < 104; j++) {
        	if (c[j] == '\0')
        		break;
        	i++;
        }
        i = i/g;
        
        p = 0;
        k = p + i-1;
        while(k < i*g) {
        	for (m = k; m >= p; m--) {
        		printf("%c", c[m]);
        	}
        	p += i;
        	k += i;
        }
        printf("\n");
        
    } while(1);
    
    return 0;
}
